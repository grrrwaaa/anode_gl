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
layout(location = 2) in vec3 a_normal;
layout(location = 2) in vec2 a_texCoord;

// instance vars:
layout(location = 4) in vec4 i_pos;
layout(location = 5) in vec4 i_quat;

out vec2 v_uv;
out vec3 v_normal;

out vec3 v_raypos;
out vec3 v_raydir;

void main() {
    vec3 size = vec3(1., 0.5, 0.5);
    mat4 instmatrix = mat4_fromPosQuatScale(i_pos.xyz, i_quat, size);

	v_uv = a_texCoord;
    v_normal = quat_rotate(i_quat, a_normal);

    // now we want the vertex to be screen aligned (view aligned)
    // that means rotating the quad to undo whatever rotation is in the model and view matrices
    //mat3 modelrot = mat3(instmatrix); // assumes no scaling here 
    //vec3 scale = vec3(length(modelrot[0]), length(modelrot[1]), length(modelrot[2]));
    //modelrot = mat3(modelrot[0]/scale.x, modelrot[1]/scale.y, modelrot[2]/scale.z);
    
    // should be safe to assume no scaling here, so this is pure rotation:
    mat3 viewrot = mat3(u_viewmatrix); 
	vec3 eyepos = -(u_viewmatrix[3].xyz)*mat3(u_viewmatrix);

	vec4 vertex = vec4(a_position.xyz, 1.);

    vec3 shift = vec3(0, 0, 1);


    //vertex.xyz *= size;
    //vertex.xyz = quat_unrotate(i_quat, vertex.xyz);
    vertex.xyz = vertex.xyz * viewrot; // undo view rotation
    //vertex.xyz = quat_rotate(i_quat, vertex.xyz);
    vertex.xyz += i_pos.xyz;
    vec3 world = vertex.xyz;
    vertex = u_viewmatrix * vertex; // apply view
    // this is wrong -- we should move toward camera in clip space not view space!
    vertex.xyz += shift; // move toward camera
	gl_Position = u_projmatrix * vertex;

    // this should be our world origin:
    vec3 world1 = (u_viewmatrix_inverse * vertex).xyz;

    vec4 truepos = u_projmatrix * u_viewmatrix * vec4(quat_rotate(i_quat, a_position.xyz) + i_pos.xyz, 1.);

    // we need a ray origin and direction in object space, as if bounded by a unit sphere

    v_raydir = world.xyz - eyepos;
    // v_raydir = quat_unrotate(i_quat, v_raydir);

    // clip space:
    // this is the near & far plane points that are in the same pixel as our vertex:
    vec4 nearpos = vec4(gl_Position.xy, -1, gl_Position.w);
    vec4 farpos = vec4(gl_Position.xy, 1, 1.);
    // converted to world space:
    nearpos = u_viewmatrix_inverse * u_projmatrix_inverse * nearpos;
    nearpos /= nearpos.w;
    farpos = u_viewmatrix_inverse * u_projmatrix_inverse * farpos;
    farpos /= farpos.w;
    
    vec3 rd_world = normalize(farpos.xyz - eyepos.xyz);

    v_normal = vec3(rd_world);

    // to objectspace:
    nearpos.xyz -= i_pos.xyz;
    farpos.xyz -= i_pos.xyz;

	// // to world space:
	// nearpos.xyz = quat_unrotate(i_quat, nearpos.xyz) - i_pos.xyz;
    // //nearpos /= nearpos.w;

	// farpos.xyz = quat_unrotate(i_quat, farpos.xyz) - i_pos.xyz;
    // //farpos /= farpos.w;

    v_raydir = normalize(farpos.xyz - eyepos.xyz);
    //v_raydir = quat_rotate(i_quat, v_raydir);

    // ray starts at quad (is this true? shouldn't it start 1 unit toward the camera from that?)
    v_raypos = world1 - i_pos.xyz; //a_position.xyz + shift;
    
    //v_raypos = quat_rotate(i_quat, v_raypos) * viewrot;
}