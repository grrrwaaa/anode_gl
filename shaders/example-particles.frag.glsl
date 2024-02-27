#version 330
precision mediump float;

in vec4 v_color;
out vec4 out_color;

void main() {

    // get normalized -1..1 point coordinate
	vec2 pc = (gl_PointCoord - 0.5) * 2.0;
	// convert to distance:
	float d = length(pc);
    if (d > 1.) discard;

    float c = sqrt(1.0-d*d);
	out_color = vec4(v_color.rgb * c, 1.);
}