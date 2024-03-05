#version 330
#include "math.glsl"
#include "hash.glsl"
#include "hg_sdf.glsl"
precision mediump float;

uniform sampler3D u_volume_tex;

uniform sampler2D u_color_prev;
uniform sampler2D u_depth_prev;
uniform float test;

uniform mat4 u_viewmatrix;
uniform mat4 u_viewmatrix_prev;
uniform mat4 u_projmatrix_prev;
uniform float t;
uniform float u_N;

in vec2 v_uv;
in vec3 v_color;
in vec3 v_normal;
in vec3 v_warped;
in vec3 v_position;
in vec3 v_flow;
in float v_far;

in mat4 v_instmatrix;
in mat4 v_instmatrix_prev;

in vec4 v_clipspace0;
in vec4 v_clipspace1;


in vec3 v_raypos;
in vec3 v_raydir;

in vec3 v_world;
in vec3 v_world_dir;
in vec3 v_world_ctr;


layout(location = 0) out vec4 out_color;
layout(location = 1) out vec4 out_depth;

float scene(vec3 p) {

	vec3 p1 = p;
	pMod3(p1, vec3(1));

	//return fSphere(p1, 0.95);
	float bound = fSphere(p - v_world_ctr, 1);

	return fOpIntersectionRound(bound, fSphere(p1, 0.75), 0.5);
}



vec3 normal4(in vec3 p, float eps) {
	vec2 e = vec2(-eps, eps);
	// tetrahedral points
	float t1 = scene(p + e.yxx), t2 = scene(p + e.xxy), t3 = scene(p + e.xyx), t4 = scene(p + e.yyy); 
	vec3 n = (e.yxx*t1 + e.xxy*t2 + e.xyx*t3 + e.yyy*t4);
	// normalize for a consistent SDF:
	//return n / (4.*eps*eps);
	// otherwise:
	return normalize(n);
}

// field represents density, so positive inside, negative outside
float sample(in vec3 p, in float iso=0.) {
	vec3 d3 = abs(p-0.5)/0.5;
	float d = min(min(d3.x, d3.y), d3.z);
	float f = texture(u_volume_tex, p).x;
	//return f - iso;

	float a = abs(p.y - 0.5);
	a = smoothstep(0., 0.5, a);

	float s = -fSphere(p-0.5, 0.5);
	//s = -fBoxCheap(p-0.5, vec3(0.45));
	// if s < 0, then f should also be < 0
	// but how to do that smoothly?

	return fOpUnionSoft(s, f, 0.5);
	//return min(s, f);
	return f;
}

vec3 volnormal4(in vec3 p, in sampler3D tex, float eps) {
	vec2 e = vec2(-eps, eps);
	// tetra points
	float t1 = sample(p+e.yxx);
	float t2 = sample(p+e.xxy);
	float t3 = sample(p+e.xyx);
	float t4 = sample(p+e.yyy);
	vec3 n = t1*e.yxx + t2*e.xxy + t3*e.xyx + t4*e.yyy;
	return normalize(n);
}

void main() {

	// // if you want to warp in the frag shader you can too:
	// vec4 clip0 = u_projmatrix_prev * u_viewmatrix_prev * v_instmatrix_prev * vec4(v_position.xyz, 1);
	// // as a texture coordinate over the screen area
	// // divide by w (perspective) then map from -1,1 to 0,1 (-> texcoord)
	// // retex.z gives a distance measure. 
	// vec3 retex = (clip0.xyz/clip0.w)*0.5 + 0.5;

	// // or use the vertex shader calculation:
	// //retex = (v_clipspace0.xyz/v_clipspace0.w)*0.5+0.5;


	// bool offscreen = any(lessThan(retex.xyz, vec3(0))) || any(greaterThan(retex.xyz, vec3(1)));

	
	// // the surface texture via warped reprojection from the previous frame:
	// // use v_warped.xy instead of retex.xy to see why sufficient tesselation is important
	// //vec4 color_prev = texture(u_color_prev, v_warped.xy);
	// // this is pretty close though:
	// vec4 depth_prev = texture(u_depth_prev, retex.xy);
	// //vec4 color_prev = texture(u_color_prev, retex.xy);


	// //float depth = gl_FragCoord.z;
	// float depth = 1. - v_clipspace1.z/v_far;
	// // compare depths:
	// // hmm probably this should be something like a smoothstep on absdiff...
	// bool occluded = (depth_prev.x - depth) > 0.01;
	// //float occlude = 1.-smoothstep(0., 0.01, abs(depth - depth_prev.x));

	// // proportional:
	// float occlude = 1.-smoothstep(0, 0.05, abs((depth - depth_prev.x)/(depth + depth_prev.x)));

	// // we want the eye ray for this pixel to do normals properly.
	// // can't this be done in the vertex shader?
	// // isn't there a simpler math for this?
	// vec3 eye_prev = eyeFromViewMatrix(u_viewmatrix_prev);
	// vec3 world_prev = (v_instmatrix_prev * vec4(v_position.xyz, 1)).xyz;
	// vec3 ray0 = mat3(u_viewmatrix_prev) * normalize(eye_prev - world_prev);


	// // transform normals to view space:
	// vec3 n = normalize(v_normal);
	// vec3 n0 = mat3(u_viewmatrix_prev)*mat3(v_instmatrix_prev)*n;
	// vec3 n1 = mat3(u_viewmatrix)*mat3(v_instmatrix)*n;

	// float oblique = max(0., dot(n0, ray0));

	// // just some example surface texture:
	// vec4 grid = vec4(mod((v_uv+1.) * 3., 1.), 0, 1.);
	// grid.xy = floor(v_uv * 3.)/3.;
	// vec4 norm = vec4(v_normal*0.5 + 0.5, 1);
	// vec4 surface = mix(grid, norm, 0.5);
	// surface.rgb = hash33(v_position.xyz);
	// //surface.rgb = hash33(vec3(grid.xy, t * 0.003));
	// //surface.rgb *= vec3(oblique);
	// surface.rgb *= v_color;
	// surface.rgb *= occlude;

	// float blur = 0.;
	// //blur = 8.*pow(1.-oblique, 4.);
	// //blur = 8.*(1.-occlude);
	// vec4 color_prev = texture(u_color_prev, retex.xy, blur);

	// // choose between them:
	// out_color = mix(surface, color_prev, (offscreen) ? 0. : pow(oblique, 0.01) * occlude);

	//out_color = vec4((1.-occlude));
	//out_color = vec4(pow(1.-oblique, 4.));

	//out_color = vec4(smoothstep(0, 0.1, occlude));
	//out_color = vec4(ray, 1.);	
	//out_color = vec4(n0, 1.);
	//out_color = vec4(hidden);

	//out_color = vec4(occluded ? 1. : 0.);

	// handle case of previous position being off-screen:
	//if (offscreen) out_color = vec4(1.);
	//out_color += vec4(depth - retex.z) * -v_far;

	// let's also write out flow:
	// we'll scale it up and offset it to get it into a visible range
	//out_depth = vec4(v_flow, 1)*16. + 0.5;

//	out_depth = vec4(depth, depth, depth, 1.);

	out_color = vec4(v_uv, 0, 1);

	vec3 rd = normalize(v_world_dir);
	vec3 ro = v_world;
	vec3 n, vn;
    
    vec3 p = ro;
	
    float t = 0;
    bool hit = false;

	if (false) {
		float EPS = 0.001;
		int maxsteps = 15;
		float d;
		for (int i=0; i<maxsteps; i++) {
			d = scene(p);
			t += d;
			p = ro + t*rd;
			if (abs(d) < EPS) {
				hit = true;
				n = normal4(p, EPS);
				break;
			}
		}

	} else {
		ro = v_raypos * 0.5 + 0.5;
		rd = normalize(v_raydir);
		float iso = 0.;
		float tmax = 2.;
		float dt = 0.1 / u_N;
		p = ro;
		for (t=0.; t < tmax; t += dt) {
			p = ro + t*rd;
			float c = sample(p, iso);
			// did we cross the surface?
			if (c >= 0.) {
			//	if (c < 0.) {

				// refine:
				float t0 = t-dt;
				float c0 = sample(ro + t0*rd, iso);
				// we want the point `a` between t0 and t where the line from c0 to c is exactly 0.5
				// 0.5 = c0 + a*(c - c0)  => a = (0.5-c0)/(c-c0) 
				float a = (iso-c0)/(c-c0);
				t = t0 + a*(t-t0);
				p = ro + t*rd;

				// this is normal in world space
				n = volnormal4(p, u_volume_tex, 0.08);
				vn = mat3(u_viewmatrix) * n;


				hit = true;
				break;
			}
		}
	}

    if (hit) {
        out_color = vec4(n*0.5+0.5, 1.);

		
		// simple lighting
		out_color *= vec4(pow(abs(dot(rd, n)), 0.95));

    } else {
        discard;
        out_color = vec4(0.2);
    }

	//out_color = vec4(p, 1);
}