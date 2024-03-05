#version 330
#include "hg_sdf.glsl"
#include "math.glsl"
#include "hash.glsl"
precision mediump float;

in vec2 v_uv;
in vec3 v_normal;

in vec3 v_raypos;
in vec3 v_raydir;

out vec4 out_color;

float scene(vec3 p) {
    //return fSphere(p, 0.5);
    return fBox(p, vec3(0.5));
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
    //if (length(v_uv -0.5) > 0.5) discard;
	out_color = vec4(v_uv, 0., 1.);
    out_color = vec4(v_normal*0.5+0.5, 1.);

    // ok we have bounds, how to ray into this?

    vec3 rd = normalize(v_raydir);
	vec3 ro = v_raypos;

    float EPS = 0.002;
	int maxsteps = 32;
    vec3 p = ro;
    float t = 0;
    bool hit = false;
    float d;
    for (int i=0; i<maxsteps; i++) {
		d = scene(p);
		t += d;
		p = ro + t*rd;
		if (abs(d) < EPS) {
			hit = true;
			break;
		}
	}

    

    //out_color = vec4(rd, 1.);
    out_color = vec4(ro, 1.);

    if (hit) {
        vec3 n = normal4(p, 0.01);
        out_color = vec4(n*0.5+0.5, 1.);
       // gl_FragDepth = computeDepth(p, v_instviewprojmatrix);
    } else {
        //discard;
        //out_color = vec4(0.1);
       // gl_FragDepth = 0.999999;
    }
}