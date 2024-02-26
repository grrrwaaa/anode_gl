#version 330
#include "math.glsl"
#include "hash.glsl"
precision mediump float;

uniform sampler2D u_color_prev;
uniform sampler2D u_depth_prev;
uniform float test;

uniform mat4 u_viewmatrix;
uniform mat4 u_viewmatrix_prev;
uniform mat4 u_projmatrix_prev;
uniform float t;

in vec2 v_uv;
in vec3 v_normal;
in vec3 v_warped;
in vec3 v_position;
in vec3 v_flow;
in float v_far;

in mat4 v_instmatrix;
in mat4 v_instmatrix_prev;

in vec4 v_clipspace0;
in vec4 v_clipspace1;

layout(location = 0) out vec4 out_color;
layout(location = 1) out vec4 out_depth;

void main() {

	// if you want to warp in the frag shader you can too:
	vec4 clip0 = u_projmatrix_prev * u_viewmatrix_prev * v_instmatrix_prev * vec4(v_position.xyz, 1);
	// as a texture coordinate over the screen area
	// divide by w (perspective) then map from -1,1 to 0,1 (-> texcoord)
	// retex.z gives a distance measure. 
	vec3 retex = (clip0.xyz/clip0.w)*0.5 + 0.5;

	// or use the vertex shader calculation:
	//retex = (v_clipspace0.xyz/v_clipspace0.w)*0.5+0.5;


	bool offscreen = any(lessThan(retex.xyz, vec3(0))) || any(greaterThan(retex.xyz, vec3(1)));

	
	// the surface texture via warped reprojection from the previous frame:
	// use v_warped.xy instead of retex.xy to see why sufficient tesselation is important
	//vec4 color_prev = texture(u_color_prev, v_warped.xy);
	// this is pretty close though:
	vec4 color_prev = texture(u_color_prev, retex.xy);
	vec4 depth_prev = texture(u_depth_prev, retex.xy);
	//vec4 color_prev = texture(u_color_prev, retex.xy);


	//float depth = gl_FragCoord.z;
	float depth = 1. - v_clipspace1.z/v_far;
	// compare depths:
	// hmm probably this should be something like a smoothstep on absdiff...
	bool occluded = (depth_prev.x - depth) > 0.01;

	// we want the eye ray for this pixel to do normals properly.
	// can't this be done in the vertex shader?
	// isn't there a simpler math for this?
	vec3 eye_prev = eyeFromViewMatrix(u_viewmatrix_prev);
	vec3 world_prev = (v_instmatrix_prev * vec4(v_position.xyz, 1)).xyz;
	vec3 ray0 = mat3(u_viewmatrix_prev) * normalize(eye_prev - world_prev);


	// transform normals to view space:
	vec3 n = normalize(v_normal);
	vec3 n0 = mat3(u_viewmatrix_prev)*mat3(v_instmatrix_prev)*n;
	vec3 n1 = mat3(u_viewmatrix)*mat3(v_instmatrix)*n;

	float oblique = max(0., dot(n0, ray0));

	// just some example surface texture:
	vec4 grid = vec4(mod((v_uv+1.) * 3., 1.), 0, 1.);
	grid.xy = floor(v_uv * 3.)/3.;
	vec4 norm = vec4(v_normal*0.5 + 0.5, 1);
	vec4 surface = mix(grid, norm, 0.5);
	
	surface.rgb = hash33(vec3(grid.xy, t * 0.003));


	// choose between them:
	out_color = mix(surface, color_prev, (occluded || offscreen) ? 0. : pow(oblique, 0.01));


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

	out_depth = vec4(depth, depth, depth, 1.);
}