#version 330
#include "math.glsl"

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec3 a_normal;

// instanced variable:
in vec4 i_pos;
in vec4 i_quat;

out vec3 v_normal;
out float v_value;

uniform mat4 u_viewmatrix;
uniform mat4 u_projmatrix;
uniform mat4 u_modelmatrix;
uniform sampler3D u_tex;

void main() {
	
	v_value = texture(u_tex, i_pos.xyz).r;

	float s = v_value * v_value * v_value;

	vec4 vertex = vec4(a_position * s, 1.);
	vertex = quat_rotate(i_quat, vertex);
	vertex.xyz += i_pos.xyz;
	gl_Position = u_projmatrix * u_viewmatrix * u_modelmatrix * vertex;

	v_normal = mat3(u_viewmatrix) * mat3(u_modelmatrix) * a_normal;
}