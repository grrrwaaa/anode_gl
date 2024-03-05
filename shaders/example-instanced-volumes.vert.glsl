#version 330
#include "math.glsl"
uniform mat4 u_viewmatrix;
uniform mat4 u_projmatrix;
uniform mat4 u_viewmatrix_prev;
uniform mat4 u_projmatrix_prev;

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec3 a_normal;
layout(location = 2) in vec2 a_texCoord;

// instance vars:
layout(location = 4) in vec4 i_pos;
layout(location = 5) in vec4 i_quat;
layout(location = 6) in vec4 i_pos0;
layout(location = 7) in vec4 i_quat0;

out vec2 v_uv;
out vec3 v_color;
out vec3 v_normal;
out vec3 v_warped;
out vec3 v_flow;
out vec3 v_position;
out mat4 v_instmatrix;
out mat4 v_instmatrix_prev;
out float v_far;
out vec4 v_clipspace0;
out vec4 v_clipspace1;

out vec3 v_raypos;
out vec3 v_raydir;

out vec3 v_world;
out vec3 v_world_dir;
out vec3 v_world_ctr;

void main() {

	float hue = float(gl_InstanceID % 16)/16.;
	v_color = hsl2rgb(hue, 0.7, 0.7);

	// Multiply the position by the matrix.
	vec4 vertex = vec4(a_position.xyz, 1);

	// get world, view, clip & texture space positions 
	// of current & previous vertex:
	mat4 instmatrix = mat4_fromPosQuatScale(i_pos.xyz, i_quat, vec3(1.));
	vec4 vm1 = instmatrix * vertex;
	vec4 vv1 = u_viewmatrix * vm1;
	vec4 vp1 = u_projmatrix * vv1;
	// as a screen space texture coordinate
	// divide by w (perspective) then map from -1,1 to 0,1 (clip -> texcoord)
	vec3 vt1 = vp1.xyz/vp1.w * 0.5 + 0.5;

	// we could have combined these 3 matrices into 1:
	mat4 instmatrix_prev = mat4_fromPosQuatScale(i_pos0.xyz, i_quat0, vec3(1.));
	vec4 vm0 = instmatrix_prev * vertex;
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
	v_clipspace0 = vp0;
	v_clipspace1 = vp1;

	v_uv = a_texCoord;
	v_normal = a_normal;
	v_position = a_position.xyz;


	v_far = farFromProjMatrix(u_projmatrix);
	
	v_instmatrix = instmatrix;
	v_instmatrix_prev = instmatrix_prev;



    // Multiply the position by the matrix.
    vec4 world = instmatrix * vertex;
	gl_Position = u_projmatrix * u_viewmatrix * world;

    mat3 rot_matrix = mat3(instmatrix);
	vec3 eyepos = -(u_viewmatrix[3].xyz)*mat3(u_viewmatrix);

    vec3 ro_object = a_position.xyz;
	//vec3 rd_object = rot_matrix * normalize(world.xyz - eyepos);
    vec3 rd_object = normalize(world.xyz - eyepos) * rot_matrix;

    v_raypos = ro_object;
	v_raydir = rd_object;

    
    v_world = world.xyz;
    v_world_dir = normalize(world.xyz - eyepos);
    v_world_ctr = i_pos.xyz;
}