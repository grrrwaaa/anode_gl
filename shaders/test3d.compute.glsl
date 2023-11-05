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
	vec3 coord = vec3(voxel_coord);
	vec3 dim = vec3(gl_NumWorkGroups);
	// as a 0..1 normalized coordinate:
	vec3 u = coord/dim;

	// GL_REPEAT wasn't working so seems like I have to do it this way
	ivec3 C = voxel_coord;

	vec4 oldC = imageLoad(img_in, C);
	vec4 oldx0 = imageLoad(img_in, (voxel_coord + ivec3(-1, 0, 0)) % idim);
	vec4 oldx2 = imageLoad(img_in, (voxel_coord + ivec3( 1, 0, 0)) % idim);
	vec4 oldy0 = imageLoad(img_in, (voxel_coord + ivec3( 0,-1, 0)) % idim);
	vec4 oldy2 = imageLoad(img_in, (voxel_coord + ivec3( 0, 1, 0)) % idim);
	vec4 oldz0 = imageLoad(img_in, (voxel_coord + ivec3( 0, 0,-1)) % idim);
	vec4 oldz2 = imageLoad(img_in, (voxel_coord + ivec3( 0, 0, 1)) % idim);

	vec4 avg = (oldx0 + oldx2 + oldy0 + oldy2 + oldz0 + oldz2) / 6.;

	vec4 old = mix(oldC, avg, vec4(0.01, 0.1, 1, 0.05));

	// create a new position relative to time:
	float a = t * 0.9;
	vec3 pos = vec3(
		sin(a), 
		sin(a * 1.2), 
		sin(a * 1.5)
	) * 0.4 + 0.5;
	pos += (hash31(t) - 0.5)*0.3;
	pos *= dim;

	float d = distance(coord, pos);
	d = max(0., d - 0.);
	
    vec4 value = vec4(exp(-0.2*d)) * (sin(t * 1.56425) + 0.5);


	//value = max(value, old);
	value += old * 0.999;

	value += 0.0015*sin(3.*(t + u.x + u.y + u.z));

	
	// color it:
	value.rgb = mix(old.rgb, hash44(vec4(pos, t)).rgb, exp(-0.4*d)); 

	//value = clamp(value, 0., 1.);
	
    imageStore(img_out, voxel_coord, vec4(value));
}