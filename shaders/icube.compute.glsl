#version 450 core

#include "math.glsl"
#include "hash.glsl"

// using local size=1 so we can operate per-vertex
layout (local_size_x = 1) in;


// here's our buffer of instances
struct Instance {
	vec4 position;
	vec4 quat;
};
// consider "restrict writeonly" or "restrict readonly" for more efficiency if you can
layout(std430, binding = 0) buffer Instances {
    Instance vertices[];
};

uniform float t; 
uniform float dt;

void main() {
	// since our local size is 1 the global ID is the vertex index
    uint idx = gl_GlobalInvocationID.x;

	float a = t + float(idx);

	vec4 pos = vertices[idx].position;
	vec4 quat = vertices[idx].quat;

    //vec4 qr = normalize(hash44(vec4(pos.xyz, t))*2.-1.);
    vec4 qr = normalize(quat_random(hash32(vec2(t * 10., float(idx)))));
    vec3 pr = normalize(hash32(vec2(t * 10., float(idx)))*2.-1.);

    quat = normalize( quat_slerp(quat, qr, 0.04) );

    vec3 uz = -quat_rotate(quat, vec3(0, 0, 1));

    vec3 vel = uz * 0.02 + pr * 0.01;

    pos.xyz += dt * vel;

    // wrap in world
    float r = 1.;
    pos.xyz = mod(pos.xyz + r, r*2.) - r;


    vertices[idx].position.xyz = pos.xyz; //vec4(cos(a), sin(a), cos(2. * a), 1.);
	vertices[idx].quat = quat;

    //vertices[idx].quat = dt * vec4(cos(a), sin(a), cos(2. * a), 1.);
}