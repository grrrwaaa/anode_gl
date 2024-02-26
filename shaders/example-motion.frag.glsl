#version 330
precision mediump float;

uniform sampler2D u_previousframe;
uniform float test;

uniform mat4 u_modelmatrix_prev;
uniform mat4 u_viewmatrix_prev;
uniform mat4 u_projmatrix_prev;

in vec2 v_uv;
in vec3 v_normal;
in vec3 v_warped;
in vec3 v_position;
in vec3 v_flow;

layout(location = 0) out vec4 frag_out0;
layout(location = 1) out vec4 frag_out1;

void main() {

	// if you want to warp in the frag shader you can too:
	vec4 clip0 = u_projmatrix_prev * u_viewmatrix_prev * u_modelmatrix_prev * vec4(v_position.xyz, 1);
	// as a texture coordinate over the screen area
	// divide by w (perspective) then map from -1,1 to 0,1 (-> texcoord)
	vec3 retex = (clip0.xyz/clip0.w)*0.5 + 0.5;

	// just some example surface texture:
	vec4 grid = vec4(mod((v_uv+1.) * 10., 1.), 0, 1.);
	vec4 norm = vec4(v_normal*0.5 + 0.5, 1);
	vec4 surface = mix(grid, norm, 0.5);
	
	// the surface texture via warped reprojection from the previous frame:
	// use v_warped.xy instead of retex.xy to see why sufficient tesselation is important
	vec4 warped = texture(u_previousframe, retex.xy);

	// choose between them:
	frag_out0 = mix(surface, warped, test);

	// let's also write out flow:
	// we'll scale it up and offset it to get it into a visible range
	frag_out1 = vec4(v_flow, 1)*16. + 0.5;
}