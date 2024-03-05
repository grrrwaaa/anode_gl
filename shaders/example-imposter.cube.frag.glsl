#version 330
precision mediump float;

in vec2 v_uv;
in vec3 v_normal;
in vec3 v_pos;

out vec4 out_color;

void main() {
    //if (length(v_pos) > 0.25) discard;
	out_color = vec4(v_uv, 0., 1.);
    //out_color = vec4(v_normal*0.5+0.5, 1.);
    out_color = vec4(length(v_pos/2.));
}