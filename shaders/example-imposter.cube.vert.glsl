#version 330
#include "math.glsl"
//uniform mat4 u_modelmatrix;
uniform mat4 u_viewmatrix;
uniform mat4 u_projmatrix;
// uniform mat4 u_modelmatrix_inverse;
uniform mat4 u_viewmatrix_inverse;
uniform mat4 u_projmatrix_inverse;
uniform float t;

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec3 a_normal;
layout(location = 2) in vec2 a_texCoord;

// instance vars:
layout(location = 4) in vec4 i_pos;
layout(location = 5) in vec4 i_quat;

out vec2 v_uv;
out vec3 v_normal;
out vec3 v_pos;

void main() {
    vec3 size = vec3(1., 0.5, 0.5);
    mat4 instmatrix = mat4_fromPosQuatScale(i_pos.xyz, i_quat, size);

	v_uv = a_texCoord;
    v_normal = quat_rotate(i_quat, a_normal);

    // should be safe to assume no scaling here, so this is pure rotation:
    mat3 viewrot = mat3(u_viewmatrix); 
	vec3 eyepos = -(u_viewmatrix[3].xyz)*mat3(u_viewmatrix);
	vec4 vertex = vec4(a_position.xyz, 1.);
    vertex.xyz = quat_rotate(i_quat, vertex.xyz);
    v_pos = vertex.xyz;
    vertex.xyz += i_pos.xyz;
    vec3 world = vertex.xyz;
    vertex = u_viewmatrix * vertex; 
	gl_Position = u_projmatrix * vertex;

}