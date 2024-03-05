#version 330
uniform mat4 u_modelmatrix;
uniform mat4 u_viewmatrix;
uniform mat4 u_projmatrix;
uniform mat4 u_modelmatrix_inverse;
uniform mat4 u_viewmatrix_inverse;
uniform mat4 u_projmatrix_inverse;

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec3 a_normal;
layout(location = 2) in vec2 a_texCoord;

out vec2 v_uv;
out vec3 v_ro;
out vec3 v_rd;

void main() {
	v_uv = a_texCoord;

	// Multiply the position by the matrix.
    // if we assume the geometry is a full-screen quad, -1,-1 to 1,1
    // then Z=-1 is the near plane and Z=+1 is the far plane
	vec3 vertex = a_position.xyz;
	gl_Position = vec4(vertex, 1);

    // clip space:
    // this is the near & far plane
    vec4 nearpos = vec4(gl_Position.xy, -1, 1);
    vec4 farpos = vec4(gl_Position.xy, 1, 1);

    // to world space:
    nearpos = u_modelmatrix_inverse * u_viewmatrix_inverse * u_projmatrix_inverse * nearpos;
    nearpos /= nearpos.w;

    farpos = u_modelmatrix_inverse * u_viewmatrix_inverse * u_projmatrix_inverse * farpos;
    farpos /= farpos.w;

    // position of the eye in worldspace:
    vec3 eyepos = -(u_viewmatrix[3].xyz)*mat3(u_viewmatrix);
    // that doesn't actually give us the near plane position though.


    v_ro = nearpos.xyz;

    v_rd = normalize(farpos.xyz - nearpos.xyz);
}