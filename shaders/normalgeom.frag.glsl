#version 330
precision mediump float;

in vec2 v_uv;
in vec3 v_normal;
out vec4 out_color;

void main() {
	out_color = vec4(v_uv, 0., 1.);
	out_color = vec4(v_normal*0.5+0.5, 1);
}