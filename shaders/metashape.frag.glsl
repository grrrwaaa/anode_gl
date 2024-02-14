#version 330
#include "hg_sdf.glsl"
#include "hash.glsl"
precision mediump float;

uniform float t;

in vec3 v_raypos;
in vec3 v_raydir;

out vec4 out_color;

vec3 r0 = hash31(10.);
vec3 r1 = hash31(11.);
vec3 r2 = hash31(12.);
vec3 r3 = hash31(20.);
vec3 r4 = hash31(21.);
vec3 r5 = hash31(22.);

// res.x = distance
// res.yzw = xyz normals
vec4 sdBezier( in vec3 pos, in vec3 A, in vec3 B, in vec3 C ) {
    const float pi = 3.1415927410125732421875;
    const float tau = 6.283185482025146484375;
    const float i3 = 1.0 / 3.0;
    const float sqrt3 = sqrt(3.0);

    vec3 a = B - A;
    vec3 b = A - 2.0 * B + C;
    vec3 c = a * 2.0;
    vec3 d = A - pos;
    
    float kk = 1.0 / dot(b,b);
    float kx = kk * dot(a, b);
    float ky = kk * (2.0 * dot(a, a) + dot(d, b)) * i3;
    float kz = kk * dot(d, a);
    
    float p  = ky - kx * kx;
    float q  = kx * (2.0 * kx * kx - 3.0 * ky) + kz;
    float p3 = p * p * p;
    float h  = q * q + 4.0 * p3;
    bool tsth = h >= 0.0;
    h = sqrt(h);
    float k = p3 / q;
    bool tstp = abs(p) < 0.01;
    vec2 x = float(!tstp) * (vec2(h, -h) - q) * 0.5 + float(tstp) * vec2(k, -k - q);
    vec2 uv = sign(x) * pow(abs(x), vec2(i3));
    float t1 = clamp(uv.x + uv.y - kx, 0.0, 1.0);
    vec3  qv3 = d + (c + b * t1) * t1;
    float z = sqrt(-p);
    float v = acos(q / (p * z * 2.0)) * i3;
    float m = cos(v);
    float n = sin(v) * sqrt3;
    vec2 t2 = clamp(vec2(m + m, -n - m) * z - kx, 0.0, 1.0);
    vec3  qx = d + (c + b * t2.x) * t2.x;
    float dx = dot(qx, qx);
    vec3  qy = d + (c + b * t2.y) * t2.y;
    float dy = dot(qy, qy);
    bool tstdxy = dx < dy;
    vec4 res = float(tsth) * vec4(dot(qv3, qv3), qv3)
        + float(!tsth) * (float(tstdxy) * vec4(dx, qx) + float(!tstdxy) * vec4(dy, qy));
    
    res.x = sqrt(res.x);
    res.yzw /= -res.x;
    
    return res;
}

float scene(vec3 p) {
    const float pi = 3.1415927410125732421875;
    float w = 0.2;
    float w2 = 0.25;

    float t0 = t * -5;

    vec3 p1 = p; pModPolar(p1.yz, float(21.));

    vec3 wb = vec3(0.1, 0.05, 0.05);
    vec3 w0 = vec3(0.3, 0, 0);

    float s = fSphere(p - w0, 0.001);
    // try also fOpUnionStairs and fOpUnionColumns fOpUnionChamfer

    float soft = 0.25;
    float radius = 0.05;
    float steps = 2.;

    s = fOpUnionColumns(s, fCapsule(p1, w0 + sin(t0 * r0)*wb/2., w0 + w0 + sin(t0 * r1)*wb, radius), soft, steps);
    s = fOpUnionColumns(s, fCapsule(p1, w0 + sin(t0 * r2)*wb/2., w0 + w0 + sin(t0 * r3)*wb, radius), soft, steps);
    s = fOpUnionColumns(s, fCapsule(p1, w0 + sin(t0 * r4)*wb/2., w0 + w0 + sin(t0 * r5)*wb, radius), soft, steps);


    float r = 0.1;
    float s0 = fCapsule(p, vec3(0), vec3(1-r, 0, 0), r);

    r = 0.1;
    float s1 = fCapsule(p, vec3(0), vec3(0, 0, (1-r)), r);

    //s = fOpUnionRound(s0, s1, 0.2);

    float wf = 0.985;
    float wi = 1.-wf;
    float rf = 0.4;

    float twist = -0.9;
    
    for (float f = 0.; f < pi*2.; f += 1.3) {
        float tf = t*(5. + f);
        float rf2 = (cos(-t*f)*0.7+0.3)*rf;
        float len = (sin(t*2.2 - f*2.)*0.3+0.7);

        float d = sdBezier(p, 
            vec3(w0), 
            vec3(-wf * len/2., rf2*sin(tf + f + twist), rf2*cos(tf + sin(f+t) + twist)), 
            vec3(-wf * len, rf*sin(tf + f + twist*2.), rf*cos(tf + f + twist*2.))
        ).x - wi;

        s = fOpUnionSoft(s, d, 0.15);
    }


    return s;
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

    vec3 rd = normalize(v_raydir);
	vec3 ro = v_raypos;

    float EPS = 0.001;
	int maxsteps = 15;
    vec3 p = ro;
    float t = 0;
    bool hit = false;
    float d;
    for (int i=0; i<maxsteps; i++) {
		d = scene(p);
		t += d;
		p = ro + t*rd;
		if (abs(d) < EPS) {
			//hit = true;
			break;
		}
	}

    hit = abs(d) < 0.9;

    if (hit) {
        vec3 n = normal4(p, 0.01);
        out_color = vec4(n*0.5+0.5, 1.);
    } else {
        discard;
        out_color = vec4(0.05);
    }
}