#version 330
precision mediump float;

uniform mat4 u_modelmatrix;
uniform mat4 u_viewmatrix;
uniform mat4 u_projmatrix;
uniform mat4 u_modelmatrix_inverse;
uniform mat4 u_viewmatrix_inverse;
uniform mat4 u_projmatrix_inverse;

in vec2 v_uv;

// ray origin & direction
in vec3 v_ro;
in vec3 v_rd;


out vec4 out_color;

// suitable to set gl_FragDepth:
float worldToDepth(vec3 worldpos) {
    float far = gl_DepthRange.far; 
    float near = gl_DepthRange.near;
    vec4 clip_space_pos = u_projmatrix * u_viewmatrix * u_modelmatrix * vec4(worldpos, 1.);
    return (((far-near) * clip_space_pos.z / clip_space_pos.w) + near + far) / 2.0;
}

// assumes boxmin/max are axis-aligned, and same world scale as ro, rd
bool intersectRayAABBox(vec3 boxMin, vec3 boxMax, vec3 ro, vec3 rd, out vec3 res) {
    vec3 invDir = 1./rd;
    // box bounds relative to ray, scaled by ray:
    vec3 tbot = (boxMin - ro) * invDir;
    vec3 ttop = (boxMax - ro) * invDir;
    vec3 tmin = min(ttop, tbot);
    vec3 tmax = max(ttop, tbot);

    vec2 t = max(tmin.xx, tmin.yz);
    float t0 = max(t.x, t.y);
    t = min(tmax.xx, tmax.yz);
    float t1 = min(t.x, t.y);

    bool inside = t0 < 0.;
    // entry & exit intersection positions:
    // (in the same coordinate space as ro, rd)
    vec3 p0 = ro + t0*rd; // entry
    vec3 p1 = ro + t1*rd; // exit

    // plane normals of the entry & exit points
    // vec3 n0 = normalize(floor(clamp( p0 / max(max(abs(p0.x), abs(p0.y)), abs(p0.z)), 0., 1.)*1.00001));
    // vec3 n1 = normalize(floor(clamp( p1 / max(max(abs(p1.x), abs(p1.y)), abs(p1.z)), 0., 1.)*1.00001));

    // if you wanted the real start point for a ray inside the cube, you'd use ro instead of p1 here; and p1 would be your ray end.
    res = inside ? p1 : p0;

    return t1 > max(t0, 0.0);
}

void main() {


    vec3 col = vec3(0);

    vec3 ro = v_ro;
    vec3 rd = normalize(v_rd);

    float t=0.;
    float tmax = 3.;
    float dt = 0.1;

    vec3 pt = ro;

    for (; t < tmax; t += dt) {

        // test intersection:
        vec3 res;
        // this AABB of -1, 1 would need to be translated for a non-origin world space position
        if (intersectRayAABBox(vec3(-1), vec3(1), pt, rd, res)) {
            // paint it
            col = vec3(res);

            // convert world-space position to frag depth:
            gl_FragDepth = worldToDepth(res);


            break;
        }

        // move forward:
        pt += t*rd;
    }

	out_color = vec4(v_uv, 0., 1.);
	//out_color = texture(u_tex, v_uv);
    out_color = vec4(col, 1);
}