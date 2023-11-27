#version 330
uniform mat4 u_modelmatrix;
uniform mat4 u_viewmatrix;
uniform mat4 u_projmatrix;
uniform mat4 u_modelmatrix_prev;
uniform mat4 u_viewmatrix_prev;
uniform mat4 u_projmatrix_prev;

layout(location = 0) in vec3 a_position;
layout(location = 2) in vec3 a_normal;
layout(location = 2) in vec2 a_texCoord;

out vec2 v_uv;
out vec3 v_normal;
out vec3 v_warped;
out vec3 v_flow;
out vec3 v_position;

void main() {
	// Multiply the position by the matrix.
	vec4 vertex = vec4(a_position.xyz, 1);

	// get world, view, clip & texture space positions 
	// of current & previous vertex:
	vec4 vm1 = u_modelmatrix * vertex;
	vec4 vv1 = u_viewmatrix * vm1;
	vec4 vp1 = u_projmatrix * vv1;
	vec3 vt1 = vp1.xyz/vp1.w * 0.5 + 0.5;

	// we could have combined these 3 matrices into 1:
	vec4 vm0 = u_modelmatrix_prev * vertex;
	vec4 vv0 = u_viewmatrix_prev * vm0;
	vec4 vp0 = u_projmatrix_prev * vv0;
	// as a screen space texture coordinate
	// divide by w (perspective) then map from -1,1 to 0,1 (clip -> texcoord)
	vec3 vt0 = (vp0.xyz/vp0.w)*0.5 + 0.5;

	gl_Position = vp1;

	// screen texture-space change if you want it
	// e.g. for making maps of optical flow
	v_flow = vt1 - vt0;

	// the previous full-screen texcoord of this vertex
	v_warped = vt0; 

	v_uv = a_texCoord;
	v_normal = mat3(u_modelmatrix) * a_normal;
	v_position = a_position.xyz;
}