#version 330
precision mediump float;

in vec3 v_normal;

layout(location = 0) out vec4 frag_out0;

void main() {
	vec3 N = normalize(v_normal);
	frag_out0 = vec4(1.);
	frag_out0 = vec4(N*0.5 + 0.5, 1.);

	vec3 L = normalize(vec3(0.5, 2, 1));
	float d = max(0., dot(L, N));
	float c = mix(d, 0.4, 0.2);

	frag_out0 = vec4(c);
}