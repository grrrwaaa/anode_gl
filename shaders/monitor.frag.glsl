#version 330
precision mediump float;

uniform vec4 crop;
uniform vec4 blend;

uniform vec2 resolution;
uniform vec2 grid_origin;
uniform vec2 grid_scale;
uniform sampler2D u_tex;

in vec2 v_uv;
in vec2 v_coord;

layout(location = 0) out vec4 out_color;

float max2 (vec2 v) {
  return max (v.x, v.y);
}

void main() {

    float aspect = resolution.x / resolution.y;

    vec2 pixel = v_coord * resolution;

    out_color = vec4(v_coord, 0, 1);

    // edge blending
    out_color  *= smoothstep(crop.x, crop.x+blend.x, pixel.x);
    out_color  *= 1-smoothstep(crop.z + blend.z, crop.z, resolution.x-pixel.x-1);
    out_color  *= smoothstep(crop.y, crop.y+blend.y, pixel.y);
    out_color  *= 1-smoothstep(crop.w+blend.w, crop.w, resolution.y-pixel.y-1);

    if (true) {
        
    //     // XYZ->RGB checkergrid:
    //     vec3 p = v_pos * (mod(floor(v_pos), 4.)+2.);
    //     if (mod(p.x, 2.) < 1. ^^ mod(p.y, 2.) < 1. ^^ mod(p.z, 2.) < 1.) {
    //    //     out_color += 0.2 + vec4(floor(v_pos)/vec3(20, 10, 10), 1.);
    //     } 
        
        // gridlines:
        //vec2 p = v_uv;
        vec2 p = abs(0.5-mod((v_uv * resolution/grid_scale + 0.5), 1.));
        vec2 p2 = exp(-100.*p);
        //out_color = mix(out_color, vec4(1), 0.5*length(p2));

        //out_color.rgb += vec3(0.5, 0.5, 1) * length(p2);

        // origin line:

        out_color.rgb += vec3(max2(exp(-0.5*abs(pixel - grid_origin))));

        vec2 grid1 = mod(pixel - grid_origin, grid_scale.x);
        out_color.rgb += vec3(max2(exp(-3.*abs(grid1))));

        
        vec2 grid2 = mod(pixel - grid_origin, grid_scale.y);
        out_color.rgb += vec3(max2(exp(-1*abs(grid2))));

    }

    // edge masking
    out_color  *= step(crop.x, pixel.x);
    out_color  *= step(crop.z, resolution.x-1-pixel.x);
    out_color  *= step(crop.y, pixel.y);
    out_color  *= step(crop.w, resolution.y-1-pixel.y);
}