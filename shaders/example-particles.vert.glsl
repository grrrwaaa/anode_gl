#version 330
uniform mat4 u_viewmatrix;
uniform mat4 u_projmatrix;
uniform float u_radius;
uniform vec2 u_resolution;

layout(location = 0) in vec4 a_position;
layout(location = 3) in vec4 a_color;

out vec4 v_color;

void main() {
	// Multiply the position by the matrix.
	vec3 vertex = a_position.xyz;
	gl_Position = u_projmatrix * u_viewmatrix * vec4(vertex, 1);

    //vec2 centre = (0.5 * gl_Position.xy/gl_Position.w + 0.5) * u_resolution;
    gl_PointSize = u_radius * u_projmatrix[1][1] * u_resolution.y / gl_Position.w;

    v_color = a_color;
}