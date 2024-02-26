#version 330
uniform mat4 u_modelmatrix;
uniform mat4 u_viewmatrix;
uniform mat4 u_projmatrix;

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec3 a_normal;
layout(location = 2) in vec2 a_texCoord;

out vec3 v_raypos;
out vec3 v_raydir;

void main() {
	// Multiply the position by the matrix.
	vec4 vertex = vec4(a_position.xyz, 1);
    vec4 world = u_modelmatrix * vertex;
	gl_Position = u_projmatrix * u_viewmatrix * world;

    mat3 rot_matrix = mat3(u_modelmatrix);
	vec3 eyepos = -(u_viewmatrix[3].xyz)*mat3(u_viewmatrix);

    vec3 ro_object = a_position.xyz;
	//vec3 rd_object = rot_matrix * normalize(world.xyz - eyepos);
    vec3 rd_object = normalize(world.xyz - eyepos) * rot_matrix;

    v_raypos = ro_object;
	v_raydir = rd_object;
}