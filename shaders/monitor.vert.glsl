#version 330
layout(location = 0) in vec3 a_position;
layout(location = 2) in vec2 a_texCoord;

out vec2 v_uv;
out vec2 v_coord;

void main() {
	v_uv = a_texCoord;

	gl_Position = vec4(a_position.xyz, 1.);
	v_coord = a_position.xy*0.5+0.5;
}