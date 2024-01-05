#version 330
precision mediump float;

#include "math.glsl"
#include "hg_sdf.glsl"

uniform mat4 u_viewmatrix;
uniform mat4 u_projmatrix;
uniform mat4 u_viewmatrix_inverse;
uniform mat4 u_projmatrix_inverse;
uniform float u_size;

in vec3 v_normal;
in vec3 v_eyepos;
in vec3 v_raypos;
in vec3 v_raydir;
//in vec4 v_world;
in vec3 v_ro_world;
in mat4 v_instmatrix;
in vec4 v_quat;
in vec3 v_color;

flat in int v_id;

layout(location = 0) out vec4 frag_out0;


// suitable to set gl_FragDepth:
float worldToDepth(vec3 worldpos) {
    float far = gl_DepthRange.far; 
    float near = gl_DepthRange.near;
    vec4 clip_space_pos = u_projmatrix * u_viewmatrix * vec4(worldpos, 1.);
    return (((far-near) * clip_space_pos.z / clip_space_pos.w) + near + far) / 2.0;
}

bool raySphereIntersect(vec3 r0, vec3 rd, vec3 s0, float sr, out vec2 hit) {
    float a = dot(rd, rd);
    vec3 s0_r0 = r0 - s0;
    float b = 2.0*dot(rd, s0_r0);
    float c = dot(s0_r0, s0_r0) - (sr*sr);
	float d = b*b - 4.0*a*c;
	hit = vec2(-b - sqrt(d), -b + sqrt(d)) / (2.0*a);
    return (d > 0.0);
}

// Thanks for IQ's ray sphere instruction
// https://iquilezles.org/blog/?p=2411
bool iSphere(in vec3 ro, in vec3 rd, in vec4 sph, in float rad, out float t) {
	// This is relating directly to parametric equation
    // where we define a function xyz = ro + t*rd
    // solving the quadradic equation below
 	vec3 oc = ro - sph.xyz;
    float b = dot(oc, rd);
    float c = dot(oc, oc) - rad*rad;
    float d = b*b - c;
	bool hit = d > 0;
    if (hit) d = -b - sqrt(t);
    return hit;
}

float scene(vec3 p) {


	vec3 p1 = p;
	pModPolar(p1.zx, float(2 + v_id));

	float b0 = fSphere(p, 0.4);
	float b1 = fBox(p, vec3(0.7));

	float b2 = fCylinder(p, 0.5, 1.);
	float b3 = fCapsule(p1.xzy, 0.1, 0.8);


	return min(b0, b3);
}

// compute normal from a SDF gradient by sampling 4 tetrahedral points around a location p
// (cheaper than the usual technique of sampling 6 cardinal points)
// 'scene' should be the SDF evaluator 'float distance = scene(vec3 pos)''  
// 'eps' is the distance to compare points around the location 'p' 
// a smaller eps gives sharper edges, but it should be large enough to overcome sampling error
// in theory, the gradient magnitude of an SDF should everywhere = 1, 
// but in practice this isn’t always held, so need to normalize() the result
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

void main() {
	vec3 N = normalize(v_normal);
	frag_out0 = vec4(0.3);
	frag_out0 = vec4(N*0.5 + 0.5, 1.);

	vec3 rd = normalize(v_raydir);
	vec3 ro = v_raypos;

	bool hit = false;
	float t = 0.;
	float tmax = 3.;
	float EPS = 0.1;
	int maxsteps = 16;

	vec3 p = ro;

	for (int i=0; i<maxsteps; i++) {
		float d = scene(p);

		t += d;
		p = ro + t*rd;
		if (abs(d) < EPS) {
			hit = true;
			break;
		}

		
	}

	if (hit) {

		// paint it
		frag_out0 = vec4(1.);
		// turn object position into a world position:
		vec3 worldpos = (v_instmatrix * vec4(p, 1.)).xyz;
		float depth = worldToDepth(worldpos);
		gl_FragDepth = depth;

		// for a sphere, normal is easy:
		vec3 normal = normalize(p);
		normal = normal4(p, EPS);
		// but we need to rotate the normal back into world space
		normal = quat_rotate(v_quat, normal);

		// normal in view space:
		vec3 vnormal = mat3(u_viewmatrix) * normal;

		// cheap fresnel
		vec3 rd_world = quat_rotate(v_quat, rd);//normalize(mat3(u_viewmatrix) * rd);
		float f = dot(normal, rd_world);
		f = 1.-abs(f);


		vec3 color = mix(v_color, vnormal*f, 0.5);

		frag_out0 = vec4(color, 1.);

	} else {
		discard;
		frag_out0 = vec4(0.3);
		gl_FragDepth = 0.999999;
	}

	// // assume a simple sphere at origin, radius 1
	// vec2 hit; 
	// if (raySphereIntersect(ro, rd, vec3(0), 1., hit)) {
	// 	// position in object-space
	// 	vec3 op = ro + rd*hit.x; 
	// 	// for a sphere, normal is easy:
	// 	vec3 normal = normalize(op);
	// 	// but we need to rotate the normal back into world space
	// 	normal = quat_rotate(v_quat, normal);

	// 	// turn object position into a world position:
	// 	vec3 worldpos = (v_instmatrix * vec4(op, 1.)).xyz;
	// 	float depth = worldToDepth(worldpos);
	// 	gl_FragDepth = depth;

	// 	frag_out0 = vec4(normal*0.5+0.5, 1.);
	// 	//frag_out0 = vec4(worldpos, 1.);
	// } else {
	// 	discard;
	// 	frag_out0 = vec4(0.1);
	// 	gl_FragDepth = -1.;
	// }


}