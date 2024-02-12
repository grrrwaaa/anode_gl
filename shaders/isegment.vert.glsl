#version 330
#include "math.glsl"

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec3 a_normal;

// instanced variable:
layout(location = 5) in vec4 i_pos;
layout(location = 6) in vec4 i_quat;

out vec3 v_normal;

// out vec3 v_eyepos;
// out vec3 v_raypos;
// out vec3 v_raydir;
// //out vec4 v_world;
// out vec3 v_color;

// out vec3 v_ro_world;
// out mat4 v_instmatrix;
// out vec4 v_quat;
// flat out int v_id;

uniform mat4 u_viewmatrix;
uniform mat4 u_projmatrix;
uniform mat4 u_viewmatrix_inverse;
uniform mat4 u_projmatrix_inverse;
uniform vec3 u_size;



void main() {
	// v_id = gl_InstanceID % 5;
	// float hue = float(gl_InstanceID % 9)/9.;
	//v_color = hsl2rgb(hue, 0.7, 0.7);

	// get instance transformation as a matrix:
	mat4 instmatrix = mat4_fromPosQuatScale(i_pos.xyz, i_quat, (u_size));
	//v_instmatrix = instmatrix;
	//v_quat = i_quat;

	vec4 vertex = instmatrix * vec4( a_position.xyz, 1.);
	vec4 world = vec4(vertex.xyz, 1.);
	vec4 view = u_viewmatrix * world;
	gl_Position = u_projmatrix * view;

	// // derive eyepos (worldspace)
	// v_eyepos = -(u_viewmatrix[3].xyz)*mat3(u_viewmatrix);

	// // derive ray
	// vec3 ro_world = world.xyz;
	// vec3 ro_object = a_position.xyz;
	// vec3 rd_world = world.xyz - v_eyepos;
	// vec3 rd_object = quat_unrotate(i_quat, rd_world); // no need to scale, we'll normalize in the frag shader

	// v_raypos = ro_object;
	// v_raydir = rd_object;

	// v_ro_world = ro_world;

	// if we needed precision, refine this in frag shader based on the surface function
	//v_world = vec4(i_pos.xyz, length(view.xyz));


	//v_normal = vec3(/* mat3(u_modelmatrix) * */ quat_rotate(i_quat, a_normal));
	v_normal = mat3(u_viewmatrix) * quat_rotate(i_quat, a_normal);
}