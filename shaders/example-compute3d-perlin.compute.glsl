#version 430 core

#include "perlin.glsl"

#include "lygia/generative/cnoise.glsl"
#include "lygia/generative/curl.glsl"
#include "lygia/generative/fbm.glsl"
#include "lygia/generative/gerstnerWave.glsl"
#include "lygia/generative/gnoise.glsl"
#include "lygia/generative/noised.glsl"
#include "lygia/generative/pnoise.glsl"
#include "lygia/generative/psrdnoise.glsl"
#include "lygia/generative/random.glsl"
#include "lygia/generative/snoise.glsl"
#include "lygia/generative/srandom.glsl"
#include "lygia/generative/voronoi.glsl"
#include "lygia/generative/voronoise.glsl"
#include "lygia/generative/wavelet.glsl"
#include "lygia/generative/worley.glsl"

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

	// // GL_REPEAT wasn't working so seems like I have to do it this way
	// ivec3 C = voxel_coord;

	// vec4 oldC = imageLoad(img_in, C);
	// vec4 oldx0 = imageLoad(img_in, (voxel_coord + ivec3(-1, 0, 0)) % idim);
	// vec4 oldx2 = imageLoad(img_in, (voxel_coord + ivec3( 1, 0, 0)) % idim);
	// vec4 oldy0 = imageLoad(img_in, (voxel_coord + ivec3( 0,-1, 0)) % idim);
	// vec4 oldy2 = imageLoad(img_in, (voxel_coord + ivec3( 0, 1, 0)) % idim);
	// vec4 oldz0 = imageLoad(img_in, (voxel_coord + ivec3( 0, 0,-1)) % idim);
	// vec4 oldz2 = imageLoad(img_in, (voxel_coord + ivec3( 0, 0, 1)) % idim);

	// vec4 avg = (oldx0 + oldx2 + oldy0 + oldy2 + oldz0 + oldz2) / 6.;

	// vec4 old = mix(oldC, avg, vec4(0.01, 0.1, 1, 0.05));

	// // create a new position relative to time:
	// float a = t * 0.9;
	// vec3 pos = vec3(
	// 	sin(a), 
	// 	sin(a * 1.2), 
	// 	sin(a * 1.5)
	// ) * 0.4 + 0.5;
	// pos += (hash31(t) - 0.5)*0.3;
	// pos *= dim;

	// float d = distance(coord, pos);
	// d = max(0., d - 0.);
	
    // vec4 value = vec4(exp(-0.2*d)) * (sin(t * 1.56425) + 0.5);


	// //value = max(value, old);
	// value += old * 0.999;

	// value += 0.0015*sin(3.*(t + u.x + u.y + u.z));

	
	// // color it:
	// value.rgb = mix(old.rgb, hash44(vec4(pos, t)).rgb, exp(-0.4*d)); 

	//value = clamp(value, 0., 1.);

    vec4 value = vec4(0);//hash44(vec4(coord, 0));
    value.w = sin(length(coord.xyz - dim/2.) * 0.1);
    value.w = sin(coord.x * coord.y * coord.z * 0.001);

    uint seed = 0x578437adU; // can be set to something else if you want a different set of random values
    int octaves = 1;
    float octaveGain = 0.25; // amp recursively applied to higher octaves
    float octaveFreq = 4.0; // frequency multiplier of each successive octave

    // position should be [0,1]
    // output is [-1,1]
    //float p = perlinNoise(vec3(u) * 2., seed, octaves, octaveGain, octaveFreq);
    vec3 pos = u + vec3(t * 0.15, 0, 0);

    vec3 vary = sin(pos*0.5)+2.;
   
    // basic idea of perlin noise is to layer up a few frequencies of noise
    float p = 1.0*perlinNoise(pos * 2., seed);

    p += 0.3*sin(pos.x+pos.y+pos.z * 4.)*perlinNoise(pos * 6., seed);
    //p += 0.05*cos(pos.x+pos.y+pos.z * 3.)*perlinNoise(pos * 24., seed);


	//p = worley(pos*4.)-0.5; // looks like a bunch of particle balls
	//p = voronoise(pos*4., 1., 0.5)-0.5; // expensive
	//p = curl(pos).x; // curl noise (this is expensive)
	//p = wavelet(pos * vec3(1, 1, 16))-0.1; // 
	//p = snoise(pos * 2.); // simplex noise
	//p = psrdnoise(pos * 4.); // Tiling simplex flow noise
	//p = pnoise(pos * 4., vec3(10.))-0.15; // periodic perlin noise
	//p = gnoise(pos * 6.); // gradient noise
	//p = fbm(pos, 32.)-0.5; // fractal brownian noise
	//p = cnoise(pos * 4.); // classic perlin noise
	value = vec4(p);

	value = noised(pos * 4.); // value noise;  .yzw is the gradient
	value = mix(value, noised(pos * 20.), 0.8*min(0., value.z*value.w));
	
    imageStore(img_out, voxel_coord, vec4(value));
}