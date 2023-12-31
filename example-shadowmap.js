/*
Umbra is the part fully in shadow
Penumbra is the part that is soft-- between shadowed and unshadowed

Shadow map is rendered from point of view of light source
Renders only depth, all colour pipeline is masked off
Also typically cull front faces rather than back faces

Can't blur shadow map texture directly because it represents depths not intensities
Essentially, depth map is a height field
But also, it's nonlinear, with more resolution closer to camera

Aliasing from shadowmap can be combatted by bilinar interp over nearest shadowmap texels: but need to interpolate the result of a depth test, not the depth itself. Best result by a 2D interp using the fractional texel position as interp factor.

Softer shadows using PCF, which just means performing depth test on a few different samples in the shadowmap and averaging the result. Results in multiple shadows (like from an LED array). 
Use irregular spacing (randomized/poisson) of sample points to get rid of banding (replaced by noise)

*/

const glfw = require("./glfw3.js")
const { vec2, vec3, vec4, quat, mat2, mat2d, mat3, mat4} = require("gl-matrix")
const gl = require('./gles3.js') 
const glutils = require('./glutils.js');

if (!glfw.init()) {
	console.log("Failed to initialize GLFW");
	process.exit(-1);
}
let version = glfw.getVersion();
console.log('glfw ' + version.major + '.' + version.minor + '.' + version.rev);
console.log('glfw version-string: ' + glfw.getVersionString());

// Open OpenGL window
glfw.defaultWindowHints();
glfw.windowHint(glfw.CONTEXT_VERSION_MAJOR, 3);
glfw.windowHint(glfw.CONTEXT_VERSION_MINOR, 3);
glfw.windowHint(glfw.OPENGL_FORWARD_COMPAT, 1);
glfw.windowHint(glfw.OPENGL_PROFILE, glfw.OPENGL_CORE_PROFILE);

let window = glfw.createWindow(720, 720, "Test");
if (!window) {
	console.log("Failed to open GLFW window");
	glfw.terminate();
	process.exit(-1);
}
glfw.makeContextCurrent(window);
console.log(gl.glewInit());
glfw.setWindowPos(window, 20, 20)

//can only be called after window creation!
console.log('GL ' + glfw.getWindowAttrib(window, glfw.CONTEXT_VERSION_MAJOR) + '.' + glfw.getWindowAttrib(window, glfw.CONTEXT_VERSION_MINOR) + '.' + glfw.getWindowAttrib(window, glfw.CONTEXT_REVISION) + " Profile: " + glfw.getWindowAttrib(window, glfw.OPENGL_PROFILE));

// Enable vertical sync (on cards that support it)
glfw.swapInterval(1); // 0 for vsync off



const depthTexture = gl.createTexture();
const depthTextureSize = 1024;
gl.bindTexture(gl.TEXTURE_2D, depthTexture);
gl.texImage2D(
    gl.TEXTURE_2D,      // target
    0,                  // mip level
    gl.DEPTH_COMPONENT32F, // internal format
    depthTextureSize,   // width
    depthTextureSize,   // height
    0,                  // border
    gl.DEPTH_COMPONENT, // format
    gl.FLOAT,           // type
    null);              // data
// gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST);
// gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST);
gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.LINEAR);
gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR);
// clamp shadowmap to a border value of 1.0 
// so that outside the map it assumes infinite depth (unshadowed)
gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.GL_CLAMP_TO_BORDER);
gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.GL_CLAMP_TO_BORDER);
gl.texParameterfv(gl.TEXTURE_2D, gl.TEXTURE_BORDER_COLOR, new Float32Array([1., 1., 1., 1.])); 
//gl.texParameterfv(gl.TEXTURE_2D, gl.TEXTURE_BORDER_COLOR, new Float32Array([0, 0, 0, 0]));  
// for using sampler2DShadow:
//gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_COMPARE_MODE, gl.COMPARE_REF_TO_TEXTURE);

const depthFramebuffer = gl.createFramebuffer();
gl.bindFramebuffer(gl.FRAMEBUFFER, depthFramebuffer);
gl.framebufferTexture2D(
    gl.FRAMEBUFFER,       // target
    gl.DEPTH_ATTACHMENT,  // attachment point
    gl.TEXTURE_2D,        // texture target
    depthTexture,         // texture
    0);                   // mip level
gl.bindTexture(gl.TEXTURE_2D, null);





let quadprogram = glutils.makeProgram(gl,
`#version 330
in vec4 a_position;
in vec2 a_texCoord;
out vec2 v_texCoord;
void main() {
    gl_Position = a_position;
    vec2 adj = vec2(1, -1);
    gl_Position.xy = (gl_Position.xy + adj) - adj;
	v_texCoord = a_texCoord;
}`,
`#version 330
precision mediump float;
uniform sampler2D u_tex;
in vec2 v_texCoord;
out vec4 outColor;

void main() {
	outColor = vec4(v_texCoord, 0., 1.);
	vec4 depth = vec4(texture(u_tex, v_texCoord).rrr, 1.);
	outColor = depth;
}
`);
let quad = glutils.createVao(gl, glutils.makeQuad(), quadprogram.id);

let cubeprogram = glutils.makeProgram(gl,
`#version 330
uniform mat4 u_modelmatrix;
uniform mat4 u_viewmatrix;
uniform mat4 u_projmatrix;
in vec3 a_position;
in vec3 a_normal;
in vec2 a_texCoord;
out vec4 v_color;

void main() {
	// Multiply the position by the matrix.
	vec3 vertex = a_position.xyz;
	gl_Position = u_projmatrix * u_viewmatrix * u_modelmatrix * vec4(vertex, 1);

	// in case rendering with gl.POINTS:
	gl_PointSize = 4.;

	v_color = vec4(a_normal*0.25+0.25, 1.);
	v_color += vec4(a_texCoord*0.5, 0., 1.);
}
`,
`#version 330
precision mediump float;

in vec4 v_color;
out vec4 outColor;

void main() {
	outColor = v_color;
}
`);
let cube = glutils.createVao(gl, glutils.makeCube({ min:[-0.2, -0.01, -0.3], max: [0.2, 0.01, 0.3] }), cubeprogram.id);

let shadowprogram = glutils.makeProgram(gl,
	`#version 330
	uniform mat4 u_modelmatrix;
	uniform mat4 u_viewmatrix;
	uniform mat4 u_projmatrix; 
	in vec3 a_position;
	
	void main() {
		// Multiply the position by the matrix.
		vec3 vertex = a_position.xyz;
		gl_Position = u_projmatrix * u_viewmatrix * u_modelmatrix * vec4(vertex, 1);
	}
	`,
	`#version 330
	precision mediump float;
	
	void main() {
		// gl_FragDepth = gl_FragCoord.z; 
	}
	`);

let floorprogram = glutils.makeProgram(gl,
`#version 330
uniform mat4 u_modelmatrix;
uniform mat4 u_viewmatrix;
uniform mat4 u_projmatrix;
uniform mat4 u_lightmatrix;
in vec3 a_position;
in vec3 a_normal;
in vec2 a_texCoord;

out vec2 v_texCoord;
out vec4 v_worldpos;
out vec4 v_shadowndc;
//out vec3 v_shadowprojcoords;

void main() {
	// Multiply the position by the matrix.
	vec3 vertex = a_position.xyz;
	v_worldpos = u_modelmatrix * vec4(vertex, 1);
	gl_Position = u_projmatrix * u_viewmatrix * v_worldpos;
	
	v_texCoord = a_texCoord;
	// convert world pos into lightspace
	// u_lightmatrix = lightprojmatrix * lightviewmatrix
	// perspective divide then map from -1,1 to 0,1:
	v_shadowndc = u_lightmatrix * v_worldpos;
	
}
`,
`#version 330
precision mediump float;

uniform mat4 u_lightmatrix;
uniform mat4 u_projmatrix_shadow_inverse;
uniform vec2 u_nearfar;
uniform vec2 u_shadowminmax;
uniform float u_time;
uniform sampler2D u_tex;
//uniform sampler2DShadow u_tex;

in vec2 v_texCoord;
in vec4 v_worldpos;
//in vec3 v_shadowprojcoords;
in vec4 v_shadowndc;
out vec4 outColor;

vec2 poissonDisk[16] = vec2[]( 
	vec2( -0.94201624, -0.39906216 ), 
	vec2( 0.94558609, -0.76890725 ), 
	vec2( -0.094184101, -0.92938870 ), 
	vec2( 0.34495938, 0.29387760 ), 
	vec2( -0.91588581, 0.45771432 ), 
	vec2( -0.81544232, -0.87912464 ), 
	vec2( -0.38277543, 0.27676845 ), 
	vec2( 0.97484398, 0.75648379 ), 
	vec2( 0.44323325, -0.97511554 ), 
	vec2( 0.53742981, -0.47373420 ), 
	vec2( -0.26496911, -0.41893023 ), 
	vec2( 0.79197514, 0.19090188 ), 
	vec2( -0.24188840, 0.99706507 ), 
	vec2( -0.81409955, 0.91437590 ), 
	vec2( 0.19984126, 0.78641367 ), 
	vec2( 0.14383161, -0.14100790 ) 
 );

float distanceFromDepth(float depth, float near, float far) {
	float ndc = depth * 2.0 - 1.0;
	return (2.0 * near * far) / (far + near - ndc * (far - near));	
}

float map(float value, float min1, float max1, float min2, float max2) {
	return min2 + (value - min1) * (max2 - min2) / (max1 - min1);
}

float random(in float x) {
	return fract(sin(x) * 43758.5453);
}

float random(in vec2 st) {
	return fract(sin(dot(st.xy, vec2(12.9898, 78.233))) * 43758.5453);
}

float random(in vec3 pos) {
	return fract(sin(dot(pos.xyz, vec3(70.9898, 78.233, 32.4355))) * 43758.5453123);
}

float random(in vec4 pos) {
	float dot_product = dot(pos, vec4(12.9898,78.233,45.164,94.673));
	return fract(sin(dot_product) * 43758.5453);
}

vec3 RANDOM_SCALE3 = vec3(.1031, .1030, .0973);
vec4 FANDOM_SCALE4 = vec4(1031, .1030, .0973, .1099);

vec2 random2(float p) {
    vec3 p3 = fract(vec3(p) * RANDOM_SCALE3);
    p3 += dot(p3, p3.yzx + 19.19);
    return fract((p3.xx+p3.yz)*p3.zy);
}

vec2 random2(in vec2 st) {
    const vec2 k = vec2(.3183099, .3678794);
    st = st * k + k.yx;
    return -1. + 2. * fract(16. * k * fract(st.x * st.y * (st.x + st.y)));
}

vec2 random2(vec3 p3) {
    p3 = fract(p3 * RANDOM_SCALE3);
    p3 += dot(p3, p3.yzx+19.19);
    return fract((p3.xx+p3.yz)*p3.zy);
}

vec3 random3(float p) {
    vec3 p3 = fract(vec3(p) * RANDOM_SCALE3);
    p3 += dot(p3, p3.yzx+19.19);
    return fract((p3.xxy+p3.yzz)*p3.zyx); 
}

vec3 random3(vec2 p) {
    vec3 p3 = fract(vec3(p.xyx) * RANDOM_SCALE3);
    p3 += dot(p3, p3.yxz+19.19);
    return fract((p3.xxy+p3.yzz)*p3.zyx);
}

vec3 random3(in vec3 p) {
    p = vec3( dot(p, vec3(127.1, 311.7, 74.7)),
            dot(p, vec3(269.5, 183.3, 246.1)),
            dot(p, vec3(113.5, 271.9, 124.6)));
    return -1. + 2. * fract(sin(p) * 43758.5453123);
}

vec4 random4(float p) {
    vec4 p4 = fract(vec4(p) * FANDOM_SCALE4);
    p4 += dot(p4, p4.wzxy+19.19);
    return fract((p4.xxyz+p4.yzzw)*p4.zywx);   
}

vec4 random4(vec2 p) {
    vec4 p4 = fract(vec4(p.xyxy) * FANDOM_SCALE4);
    p4 += dot(p4, p4.wzxy+19.19);
    return fract((p4.xxyz+p4.yzzw)*p4.zywx);
}

vec4 random4(vec3 p) {
    vec4 p4 = fract(vec4(p.xyzx)  * FANDOM_SCALE4);
    p4 += dot(p4, p4.wzxy+19.19);
    return fract((p4.xxyz+p4.yzzw)*p4.zywx);
}

vec4 random4(vec4 p4) {
    p4 = fract(p4  * FANDOM_SCALE4);
    p4 += dot(p4, p4.wzxy+19.19);
    return fract((p4.xxyz+p4.yzzw)*p4.zywx);
}

float shadowRaw(sampler2D shadowmap, vec2 tc, float biasedCurrentDepth, float spread) {
	return biasedCurrentDepth > texture(shadowmap, tc).r ? 1.0 : 0.0; 
}

float shadowBilinear(sampler2D shadowmap, vec2 tc, float biasedCurrentDepth, float spread) {
	vec2 texSize = textureSize(shadowmap, 0);
	vec2 texelSize = 1.0 / texSize;

	// bilinear interp four nearest samples in the shadowmap:
	float d00 = shadowRaw(shadowmap, tc + vec2(-0.5,-0.5)*texelSize, biasedCurrentDepth, spread);
	float d01 = shadowRaw(shadowmap, tc + vec2(-0.5, 0.5)*texelSize, biasedCurrentDepth, spread); 
	float d10 = shadowRaw(shadowmap, tc + vec2( 0.5,-0.5)*texelSize, biasedCurrentDepth, spread); 
	float d11 = shadowRaw(shadowmap, tc + vec2( 0.5, 0.5)*texelSize, biasedCurrentDepth, spread); 

	vec2 a = fract(tc*texSize);
	float avg = mix(mix(d00, d01, a.y), mix(d10, d11, a.y), a.x);
	return avg;
}

float shadow3x3(sampler2D shadowmap, vec2 tc, float biasedCurrentDepth, float spread) {
	vec2 texSize = textureSize(shadowmap, 0);
	vec2 texelSize = 1.0 / texSize;
	float shadow = 0.;
	for (int x = -1; x <= 1; ++x) {
		for (int y = -1; y <= 1; ++y) {
			shadow += shadowRaw(shadowmap, tc + vec2(x,y)*texelSize, biasedCurrentDepth, spread); 
		}    
	}
	return shadow / 9.0;
}

float shadowPCF(sampler2D shadowmap, vec2 tc, float biasedCurrentDepth, float spread) {
	// PCF: percentage-closer filtering
	float shadow = 0.0;
	vec2 texSize = textureSize(shadowmap, 0);
	vec2 texelSize = spread / texSize;
	const int halfkernelWidth = 3;
	for(int x = -halfkernelWidth; x <= halfkernelWidth; ++x) {
		for(int y = -halfkernelWidth; y <= halfkernelWidth; ++y) {
			shadow += shadowRaw(shadowmap, tc + vec2(x,y)*texelSize, biasedCurrentDepth, spread);
		}
	}
	return shadow / ((halfkernelWidth*2+1)*(halfkernelWidth*2+1));
}


float shadowDisk(sampler2D shadowmap, vec2 tc, float biasedCurrentDepth, float spread) {
	float shadow = 0.0;
	vec2 texSize = textureSize(shadowmap, 0);
	vec2 texelSize = spread / texSize;
	for (int i=0;i<16;i++) {
		// randomized index
		int index = int(16.0*random(vec4(gl_FragCoord.xy, i, u_time)))%16;
		shadow += shadowRaw(shadowmap, tc + poissonDisk[index]*texelSize, biasedCurrentDepth, spread);
	}
	return shadow / 16.0;
}

float shadowRandomBilinear(sampler2D shadowmap, vec2 tc, float biasedCurrentDepth, float spread) {
	float shadow = 0.0;
	vec2 texSize = textureSize(shadowmap, 0);
	vec2 texelSize = 1. / texSize;
	for (int i=0;i<16;i++) {
		// randomized index
		float x = random(vec2(gl_FragCoord.y, float(i) + u_time));
		float y = random(vec2(gl_FragCoord.x, float(i) - u_time));
		int index = int(16.0*random(vec4(gl_FragCoord.xy, i, u_time)))%16;
		// vec2 r = vec2(x, y);
		vec2 r = poissonDisk[index];
		shadow += shadowBilinear(shadowmap, tc + spread*r*texelSize, biasedCurrentDepth, 1.);
	}
	return shadow / 16.0;
}


float shadowESM(sampler2D shadowmap, vec2 tc, float z, float near, float far, float k) {
	float d = distanceFromDepth(texture(shadowmap, tc).r, near, far);
	float ddz = z-d;
	//return z-d > 0 ? 1.0 : 0.0;
	// Approximate step function (z-d > 0) by exp(k*(z-d)):
	//return ddz;
	return exp(k*-ddz);
}

float compute_pcss(sampler2D shadowmap, vec2 uv, float dc, float pcf_width, float u_kernel_size, float bias){
    float result = 0.;

    float step_count = u_kernel_size / 2.;
    float step_uv = pcf_width / step_count;
    for(float x=-step_count; x<=step_count; x++){
        for(float y=-step_count; y<=step_count; y++){
            vec2 offset = vec2(x, y) * step_uv;
            float depth = texture(shadowmap, uv.xy + offset).r + bias;
            if (depth > dc){
                result += 1.0;
            } else {
                result += 0.5;
            }
        }
    }
    return pow(result / (u_kernel_size * u_kernel_size), 2.2);
}

float compute_pcss_shadow(sampler2D shadowmap, vec2 uv, float dc, float zc, float near, float far) {
	float u_light_size = 0.2;
	float blocker_kernel_size = 25.;
	float pcf_kernel_size = 25.;

	// first get region width
	// proportional to light size, and to the distance from the light nearplane (cz)
    float search_region_width = u_light_size * (zc - near) / zc; 

	// now compute blockers:
	int blocker_count = 0;
    float blocker_depth_sum = 0;
    float step_count = blocker_kernel_size / 2.;
	float step_uv = search_region_width / step_count;
    for(float x=-step_count; x<=step_count; x++){
        for(float y=-step_count; y<=step_count; y++){
            vec2 offset = vec2(x, y) * step_uv;
			// shouldn't this be converted to Z?
			float d = texture(shadowmap, uv.xy + offset).r;
			//float dz = distanceFromDepth(d, near, far);
            //if (dz < z){
			if (d < dc) {
                blocker_count++;
                //blocker_depth_sum += dz; 
                blocker_depth_sum += d; 
            }
        }
    }
	if (blocker_count == 0) return 1.0;  // no blockers
	float average_blocker_depth = blocker_depth_sum / blocker_count;
    
	float blocker_distance = distanceFromDepth(average_blocker_depth, near, far);

    float penumbra_width =  u_light_size * (zc - blocker_distance) / blocker_distance; // / u_frustum_width;
	//float penumbra_width = abs(zc - blocker_distance) / blocker_distance;

	float pcf_width = penumbra_width * near / zc;

	float bias = 0.000001;
    float pcss = compute_pcss(shadowmap, uv, dc, pcf_width, pcf_kernel_size, bias);

	return pcss;
}


void main() {

	outColor = vec4(1.);

	vec3 shadowprojcoords = (v_shadowndc.xyz / v_shadowndc.w) * 0.5 + 0.5;

	// bias gets rid of shadow acne (depth buffer aliasing) 
	// but also creates a little peter-panning (shadow detached from object)
	// depends on angle of light, resolution of depth buffer, bit-depth of depth buffer, etc etc.
	float bias = 0.000001;  
	
	float near = u_nearfar.x;
	float far = u_nearfar.y;

	// clamp here in case the point is beyond the light's far plane:
	float currentDepth = clamp(shadowprojcoords.z, 0.0, 1.0);
	
	float zc = distanceFromDepth(currentDepth, near, far);	// world units (meters)

	// use uni-normalized coordinates in shadow's projection space to sample shadowmap:
	float rawDepth = texture(u_tex, shadowprojcoords.xy).r;  
	// for sampler2Dshadow:
	//float rawDepth = texture(u_tex, vec3(shadowprojcoords.xy, shadowprojcoords.z-bias));  


	// two ways to compute depth in meters:

	// first, using near, far values:
	float z = distanceFromDepth(rawDepth, near, far);	// world units (meters)

	// second, by the inverse lightshadow matrix:
	// first convert back to bipolar NDC coords, then unproject through lightspace:
	vec4 ndc = vec4(shadowprojcoords.xy, rawDepth, 1.0) * 2.0 - 1.0;
	vec4 lightpos = u_projmatrix_shadow_inverse * ndc;
	//lightpos.z; // world units (meters)

	// signed distance from surface:
	float dz = zc - z;

	float isUnshadowed = currentDepth - bias < rawDepth ? 1.0 : 0.0;  
	// cheating, for a case where 
	//float isUnshadowed = (rawDepth < 1. && rawDepth > 0.) ? 0. : 1.;

	
	// PCF: percentage-closer filtering
	float shadow = 0.;
	vec2 texSize = textureSize(u_tex, 0);
	vec2 texelSize = 1.0 / texSize;

	// shadow = shadowRaw(u_tex, shadowprojcoords.xy, currentDepth - bias, 1);
	// shadow = shadowBilinear(u_tex, shadowprojcoords.xy, currentDepth - bias, 1);
	// shadow = shadow3x3(u_tex, shadowprojcoords.xy, currentDepth - bias, 1.);
	// shadow = shadowPCF(u_tex, shadowprojcoords.xy, currentDepth - bias, 1.); 
	// shadow = shadowDisk(u_tex, shadowprojcoords.xy, currentDepth - bias, 5.);  
	// shadow = shadowRandomBilinear(u_tex, shadowprojcoords.xy, currentDepth - bias, 10.);  
	// shadow = shadowESM(u_tex, shadowprojcoords.xy, z, near, far, 1.0);
	shadow = compute_pcss_shadow(u_tex, shadowprojcoords.xy, currentDepth, z, near, far);
	
	isUnshadowed = 1. - shadow;
	float visibility = 1. - shadow;
	
	// outColor = vec4(shadowprojcoords, 1.); 
	// outColor = vec4(ndc );  
	// outColor = vec4(lightpos.xyz, 1.);
	//outColor = vec4(lightpos.z);
	//outColor = vec4(z);
	// outColor = vec4(v_texCoord, 0., 1.);
	//outColor = vec4(rawDepth);
	//outColor = vec4(isUnshadowed);
	//outColor = vec4(shadow);
	//outColor = vec4(a, 0., 1.);
	//outColor = vec4(dz);
	//outColor = vec4(visibility);
	// outColor = vec4(z);

	outColor = vec4(shadow);

}
`);
let w = 8
let floor = glutils.createVao(gl, glutils.makeCube({ min:[-w/2, -1, -w/2], max: [w/2, 0, w/2] }), floorprogram.id);

let t = glfw.getTime();
let fps = 60;

function animate() {
	if(glfw.windowShouldClose(window) || glfw.getKey(window, glfw.KEY_ESCAPE)) {
		shutdown();
	} else {
		setImmediate(animate)
	}

	let windim = glfw.getFramebufferSize(window)
	
	let t1 = glfw.getTime();
	let dt = t1-t;
	fps += 0.1*((1/dt)-fps);
	t = t1;
	glfw.setWindowTitle(window, `fps ${fps}`);
	// Get window size (may be different than the requested size)
	let dim = glfw.getFramebufferSize(window);
	//if(wsize) console.log("FB size: "+wsize.width+', '+wsize.height);

	// Compute the matrix
	let viewmatrix = mat4.create();
	let projmatrix = mat4.create();
	let modelmatrix = mat4.create();
	mat4.lookAt(viewmatrix, [0, 2, 3], [0, 1, 0], [0, 1, 0]);
	mat4.perspective(projmatrix, Math.PI/2, dim[0]/dim[1], 0.1, 10);

	let viewmatrix_shadow = mat4.create()
	let viewmatrix_shadow_inverse = mat4.create()
	let projmatrix_shadow = mat4.create()
	let projmatrix_shadow_inverse = mat4.create()
	let h = 3
	mat4.lookAt(viewmatrix_shadow, [0, h, 0], [0, 0, 0], [0, 0, 1]);
	mat4.invert(viewmatrix_shadow_inverse, viewmatrix_shadow)
	
	let far = h
	let near = 0.1
	let f = w/2 * near/far
	//mat4.perspective(projmatrix_shadow, 2*Math.atan2(w/2, h), 1/1, 1, h);
	mat4.frustum(projmatrix_shadow, -f, f, -f, f, near, far)
	mat4.invert(projmatrix_shadow_inverse, projmatrix_shadow)

	let lightmatrix = mat4.create()
	mat4.multiply(lightmatrix, projmatrix_shadow, viewmatrix_shadow);


	//mat4.identity(modelmatrix);
	mat4.translate(modelmatrix, modelmatrix, [0, h*0.5*(1 + Math.sin(t*2)), 0])
	mat4.rotate(modelmatrix, modelmatrix, t, [0, 1, 0])
	mat4.translate(modelmatrix, modelmatrix, [0, 0, 0.3])
	mat4.rotate(modelmatrix, modelmatrix, t, [0, 0, 1])
	mat4.rotate(modelmatrix, modelmatrix, t, [1, 0, 0])

	let modelmatrix2 = mat4.create()
	mat4.translate(modelmatrix2, modelmatrix2, [0, 1, 0])

	// first, the shadowpass:
	{
		// draw to the depth texture
		gl.bindFramebuffer(gl.FRAMEBUFFER, depthFramebuffer);
		gl.viewport(0, 0, depthTextureSize, depthTextureSize);
		// gl.clearDepthf(0.0)
		// gl.depthFunc(gl.GEQUAL);
		gl.colorMask(false, false, false, false)
		gl.clear(gl.DEPTH_BUFFER_BIT);
		gl.enable(gl.CULL_FACE)
		gl.cullFace(gl.FRONT)

		shadowprogram.begin()
			.uniform("u_viewmatrix", viewmatrix_shadow)
			.uniform("u_projmatrix", projmatrix_shadow)
			.uniform("u_modelmatrix", modelmatrix)
		cube.bind().draw().unbind();
		shadowprogram
			.uniform("u_modelmatrix", modelmatrix2)
		cube.bind().draw().unbind();
		shadowprogram.end();

		gl.cullFace(gl.BACK)
		gl.disable(gl.CULL_FACE)
		gl.colorMask(true, true, true, true)
		// gl.clearDepthf(1.0)
		// gl.depthFunc(gl.LEQUAL);
		gl.bindFramebuffer(gl.FRAMEBUFFER, null);
	}

	{
		gl.viewport(0, 0, windim[0], windim[1]);
		gl.enable(gl.DEPTH_TEST)
		gl.depthMask(true)
		gl.clearColor(0.2, 0.2, 0.2, 1);
		gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

		gl.bindTexture(gl.TEXTURE_2D, depthTexture);
		floorprogram.begin()
			.uniform("u_modelmatrix", mat4.create())
			.uniform("u_viewmatrix", viewmatrix)
			.uniform("u_projmatrix", projmatrix)
			.uniform("u_lightmatrix", lightmatrix)
			.uniform("u_projmatrix_shadow_inverse", projmatrix_shadow_inverse)
			.uniform("u_nearfar", near, far)
			.uniform("u_time", t)
			.uniform("u_shadowminmax", 0.4, 0.8)
			.uniform("u_tex", 0)
		//cube.bind().drawPoints().unbind();
		floor.bind().draw().unbind();
		floorprogram.end();

		cubeprogram.begin()
			.uniform("u_modelmatrix", modelmatrix)
			.uniform("u_viewmatrix", viewmatrix)
			.uniform("u_projmatrix", projmatrix)
		cube.bind().draw().unbind();
		cubeprogram
			.uniform("u_modelmatrix", modelmatrix2)
		cube.bind().draw().unbind();
		cubeprogram.end();
	}

	// Swap buffers
	glfw.swapBuffers(window);
	glfw.pollEvents();
}

function shutdown() {
	// Close OpenGL window and terminate GLFW
	glfw.destroyWindow(window);
	glfw.terminate();

	process.exit(0);
}

animate();