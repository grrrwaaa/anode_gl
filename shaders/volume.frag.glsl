#version 330
precision mediump float;

uniform mat4 u_modelmatrix;
uniform mat4 u_viewmatrix;
uniform mat4 u_projmatrix;
uniform mat4 u_modelmatrix_inverse;
uniform mat4 u_viewmatrix_inverse;
uniform mat4 u_projmatrix_inverse;

uniform float u_cube_size;

in vec2 v_uv;

// ray origin & direction, in model space
in vec3 v_ro_model;
in vec3 v_rd_model;
in vec3 v_re_model;
// these are in world space:
in vec3 v_ro_world;
in vec3 v_rd_world;
in vec3 v_re_world;


out vec4 out_color;

// suitable to set gl_FragDepth:
float worldToDepth(vec3 worldpos) {
    float far = gl_DepthRange.far; 
    float near = gl_DepthRange.near;
    vec4 clip_space_pos = u_projmatrix * u_viewmatrix * u_modelmatrix * vec4(worldpos, 1.);
    return (((far-near) * clip_space_pos.z / clip_space_pos.w) + near + far) / 2.0;
}

void main() {
    vec3 ro = v_ro_model;
    vec3 rd = normalize(v_rd_model);

    // try to intersect with the axis-aligned bounding box:
    vec3 boxMin = vec3(-u_cube_size);
    vec3 boxMax = vec3( u_cube_size);

    vec3 invDir = 1./rd;
    // box bounds relative to ray, scaled by ray:
    vec3 tbot = (boxMin - ro) * invDir;
    vec3 ttop = (boxMax - ro) * invDir;
    vec3 tmin = min(ttop, tbot);
    vec3 tmax = max(ttop, tbot);
    // get ray progress at entry (t0) and exit (t1)
    vec2 tt = max(tmin.xx, tmin.yz);
    float t0 = max(tt.x, tt.y);
    tt = min(tmax.xx, tmax.yz);
    float t1 = min(tt.x, tt.y);
    // did the ray intersect with the bounding box?
    if (t1 < max(t0, 0.0)) discard;

    // entry & exit intersection positions:
    // (in the same coordinate space as ro, rd)
    vec3 p0 = ro + t0*rd; // entry
    vec3 p1 = ro + t1*rd; // exit
    // we need to take care of the danger of hitting the far clip; the ray should stop there
    // farclip is at re, in model space
    bool farclipped = length(v_re_model - p0) <= length(p1 - p0);
    vec3 ray_exit = farclipped ? v_re_model : p1;
    // is the eye inside the bounding box?
    bool inside = t0 < 0.;
    // if we are *outside* the box, our ray start should be p0, else ro
    vec3 ray_start = inside ? ro : p0;

    
    // convert world-space position to frag depth:
    gl_FragDepth = worldToDepth(p1);
    // we could now use this information to set up raymarching
    // for this demo we just draw the surface point
    vec3 res = inside ? p1 : p0;
    out_color = vec4(res, 1);
}