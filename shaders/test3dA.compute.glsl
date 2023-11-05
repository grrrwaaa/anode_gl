#version 430 core

#include "hash.glsl"

// local size of work group
// using local size=1 so we can operate per-pixel.
layout (local_size_x = 1, local_size_y = 1, local_size_z = 1) in;

// a 3D image (a single layer of a texture) 
// compute shaders use pixel coordinates, not normalized coordinates
// the internal format must match the texture
layout(rgba32f, binding = 0) writeonly uniform image3D img_out;
// ivec imageSize(gimage image​);
// gvec4 imageLoad(gimage image​, IMAGE_COORD);
// void imageStore(gimage image​, IMAGE_COORD, gvec4 data​);


layout(rgba32f, binding = 1) readonly uniform image3D img_in;

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

void main() {

	// since our local size is 1,1 the global ID is the texel coordinate:
    ivec3 voxel_coord = ivec3(gl_GlobalInvocationID.xyz);
	ivec3 idim = ivec3(gl_NumWorkGroups);
	vec3 P = vec3(voxel_coord);
	vec3 dim = vec3(gl_NumWorkGroups);
	// as a 0..1 normalized coordinate:
	vec3 u = P/dim;

	vec4 p = imageLoad(img_in, voxel_coord);

	// init:
	if (t < 0.1) {
		float dim = 1.;
		// position:
		p.xyz = (floor(P/dim)+0.5)*dim;
		p.w = 0.;
		// velocity:
		//p.zw = (D(P).xy-0.5) * 2.;
	}

	// see if there's a nearer particle
    // in each axis consider a couple of steps:
    // if particle.xy there is actually closer to our pixel, use that particle instead
    else {
        int N=1;
		for (int z=-N; z<N; z++) {
        	for (int y=-N; y<=N; y++) {
            	for (int x=-N; x<N; x++) {
					//vec4 n = B(P+vec2(x, y));
					vec4 n = imageLoad(img_in, voxel_coord + ivec3(x, y, z));
					// if `n` is nearer to our pixel, use it
					// here we should be thinking about distance to surface point,
					// not distance to particle center
					// e.g. for spheres we should care about the sphere radius
					// but if they are all equal we can ignore that
					if (length(P - n.xyz) < length(P - p.xyz)) p = n;
				}
            }
        }
	}
	// now we have our nearest particle `p`

	// advect the particle 
    // careful here: all calculations should be in terms of `p` only
    // if you use pixel locations, it will spawn new siblings of the particle
    //p.zw = rotate2(p.zw, 0.02* rand(p.xy));
    vec3 vel = 0.25*(hash33(p.xyz) - 0.5);
	//vel += 0.1*vec3(sin(p.x/dim.x+t), sin(p.y/dim.y+t*1.1), sin(p.z/dim.z+t*1.2));
    p.xyz += vel;
  

	
	// // GL_REPEAT wasn't working so seems like I have to do it this way
	// ivec3 C = voxel_coord;
	// ivec3 E = (voxel_coord + ivec3(1, 0, 0)) % idim;
	// ivec3 W = (voxel_coord + ivec3(-1, 0, 0)) % idim;

	// vec4 oldC = imageLoad(img_in, C);
	// vec4 oldE = imageLoad(img_in, E);
	// vec4 oldW = imageLoad(img_in, W);

	// vec4 old = mix(oldC, mix(oldE, oldW, 0.5), 0.) * 0.9999;

	// // create a new position relative to time:
	// float a = t * 1.;
	// vec3 pos = vec3(
	// 	sin(a), 
	// 	sin(a * 1.2), 
	// 	sin(a * 1.5)
	// ) * 0.4 + 0.5;

	// pos += (hash31(t) - 0.5)*0.4;

	// pos *= dim;
	
    // vec4 value = vec4(exp(-0.2*distance(coord, pos)));

	// value = max(value, old);

	// value = clamp(value, 0., 1.);
	
    // imageStore(img_out, voxel_coord, vec4(value));

	// // reset
	

	imageStore(img_out, voxel_coord, p);
}