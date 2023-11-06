#version 430 core

#include "hash.glsl"

// local size of work group
// using local size=1 so we can operate per-pixel.
layout (local_size_x = 1, local_size_y = 1, local_size_z = 1) in;

// a 3D image (a single layer of a texture) 
// compute shaders use pixel coordinates, not normalized coordinates
// the internal format must match the texture
layout(rgba32f, binding = 2) writeonly uniform image3D img_out;
// ivec imageSize(gimage image​);
// gvec4 imageLoad(gimage image​, IMAGE_COORD);
// void imageStore(gimage image​, IMAGE_COORD, gvec4 data​);


layout(binding = 3) uniform sampler3D fluid_tex;

// variables
uniform float t; 

#define PI 3.14159265

/*
some built-in variables:
uvec3	gl_NumWorkGroups	number of work groups that have been dispatched
uvec3	gl_WorkGroupSize	size of the work group (local size) operated on (what we defined above)
uvec3	gl_WorkGroupID		index of the work group currently being operated on
uvec3	gl_LocalInvocationID	index of the current work item in the work group
uint	gl_LocalInvocationIndex	1d index representation of gl_LocalInvocationID
uvec3	gl_GlobalInvocationID	global index of the current work item
*/

// interpolated looking back into where we came from:
vec3 prev(vec3 pos, vec3 dim) {
    pos -= 0.5*texture(fluid_tex, (pos)/dim).xyz;
    pos -= 0.5*texture(fluid_tex, (pos)/dim).xyz;
    return pos;
}

void main() {

	// since our local size is 1,1 the global ID is the texel coordinate:
    ivec3 voxel_coord = ivec3(gl_GlobalInvocationID.xyz);
	ivec3 idim = ivec3(gl_NumWorkGroups);
	vec3 P = vec3(voxel_coord)+0.5;
	vec3 dim = vec3(gl_NumWorkGroups);
	// as a 0..1 normalized coordinate:
	vec3 u = P/dim;

	vec3 pre = prev(P, dim);

	vec4 p = texture(fluid_tex, (pre)/dim);

	vec4 energy;

	// neighbourhood
    vec4 px = texture(fluid_tex, prev(P + vec3(1,0,0), dim)/dim);
    vec4 nx = texture(fluid_tex, prev(P - vec3(1,0,0), dim)/dim);
    vec4 py = texture(fluid_tex, prev(P + vec3(0,1,0), dim)/dim);
    vec4 ny = texture(fluid_tex, prev(P - vec3(0,1,0), dim)/dim);
    vec4 pz = texture(fluid_tex, prev(P + vec3(0,0,1), dim)/dim);
    vec4 nz = texture(fluid_tex, prev(P - vec3(0,0,1), dim)/dim);

	// diffused past:
    vec4 avg = (px + nx + py + ny + pz + nz)/6.;
	// ordered difference in the pressure/convergence/disorder (A.z) 
    // creates velocity in me (OUT.xy)
    vec3 force = vec3(nx.w-px.w, ny.w-py.w, nz.w-pz.w)/-6.;
	// variance in the velocity (A.xy) near me creates pressure/convergence/disorder in me
    float press = (nx.x-px.x + ny.y-py.y + nz.z-pz.z)/-6.;

	// either the velocity or the pressure should be diffused, but not both
	// I like blend=0 more, it gives more turbulence; 1 is more smoky
    float blend = 0.;  

	// new velocity derived from neighbourhood average
    energy.xyz = mix(p.xyz, avg.xyz, blend) + force;
	energy.w = mix(avg.w, p.w, blend) + press;

	// optional decays
    // xy or z, don't need to do both
    // OUT.xy *= 0.99;
    //energy.w *= 0.999;

	// add force of gravity to my velocity
    //energy.y -= energy.w/idim.y;


	// // optional add forces
    // float d = line2(COORD, DIM/2. - DIM.y*0.2* vec2(sin(iTime*0.2),cos(iTime*0.2)), DIM/2. + DIM.y*0.4* vec2(sin(iTime*.1618),cos(iTime*.1618)));
    // //if (d < 1.) 
    // {
    //     OUT += exp(-d) * vec4(cos(iTime*2.), sin(iTime*3.), 0, 1.);
    // }

	float t1 = t*0.1;
	vec3 c = vec3(cos(t1*2.), sin(t1*3.), sin(t1*1.7)) * 0.5 + 0.5;
	vec3 cu = c - u;
	float d = length(cu);
	float r = 0.2;
	if (d < r) {
		vec3 disturb = normalize(0.5-c) + (hash44(vec4(pre*dim, t)).xyz - 0.5);
		disturb *= 0.5; //*sin(t);
		energy.xyz = mix(disturb, energy.xyz, d/r);
	}

	// // my divergence is average of local divergence (diffusion)
    // // (reducing the effect here adds caustics instead)
    // energy.w = mix(energy.w, (px.w + py.w + nx.w + ny.w + pz.w + nz.w)/6., 1.);

	// float transfer = 1.;

	// // add gradient of local velocity to my divergence
    // // (The disorder of the order around Me gives Me disorder)
    // energy.w -= transfer*(nx.x-px.x + ny.y-py.y + nz.z-pz.z)/6.;

	// // add gradient of local divergence (a force) to my velocity
    // // (The order of the disorder around Me gives Me order.)
    // energy.xyz += (1./transfer)*-vec3(nx.w-px.w, ny.w-py.w, nz.w-pz.w)/6.;
	
	// speed limit & prevent explosions:
    energy.xyzw = clamp(energy.xyzw, vec4(-1), vec4(1));

   
	// boundary conditions:
    // if (P.x < 1. || P.y < 1. || P.z < 1.
	// || P.x > idim.x-1. || P.y > idim.y-1. || P.z > idim.y-1.) {
    //     //energy.xyz = vec3(0);
    // }

	if (P.x < 1. || P.x > idim.x-1.) {
		energy.xyz = length(energy.xyz) * normalize(energy.xyz * vec3(0, 1, 1));
	}
	if (P.y < 1. || P.y > idim.y-1.) {
		energy.xyz = length(energy.xyz) * normalize(energy.xyz * vec3(1, 0, 1));
	}
	if (P.z < 1. || P.z > idim.z-1.) {
		energy.xyz = length(energy.xyz) * normalize(energy.xyz * vec3(1, 1, 0));
	}
   

	// init:
	if (t < 0.1) {
		energy = 2.*(hash44(vec4(P, 1.)) - 0.5);
	}

	imageStore(img_out, voxel_coord, energy);
}