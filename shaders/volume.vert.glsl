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
// these are in model space:
out vec3 v_ro_model;
out vec3 v_re_model;
out vec3 v_rd_model;
// these are in world space:
out vec3 v_ro_world;
out vec3 v_re_world;
out vec3 v_rd_world;

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

    // to world and model space:
    nearpos = u_projmatrix_inverse * nearpos;
    nearpos /= nearpos.w;
    vec4 nearpos_world = u_viewmatrix_inverse * nearpos;
    vec4 nearpos_model = u_modelmatrix_inverse * nearpos_world;

    farpos = u_projmatrix_inverse * farpos;
    farpos /= farpos.w;
    vec4 farpos_world = u_viewmatrix_inverse * farpos;
    vec4 farpos_model = u_modelmatrix_inverse * farpos_world;

// position of the eye in worldspace:
    //vec3 eyepos = -(u_viewmatrix[3].xyz)*mat3(u_viewmatrix);
    // that doesn't actually give us the near plane position though.

    v_ro_world = nearpos_world.xyz;
    v_re_world = farpos_world.xyz;
    v_rd_world = normalize(farpos_world.xyz - nearpos_world.xyz);

    v_ro_model = nearpos_model.xyz;
    v_re_model = farpos_model.xyz;
    v_rd_model = normalize(farpos_model.xyz - nearpos_model.xyz);
}