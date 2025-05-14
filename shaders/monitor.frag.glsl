#version 330
precision mediump float;

uniform sampler2D u_tex;

in vec2 v_uv;

layout(location = 0) out vec4 out_color;

void main() {
    out_color = vec4(v_uv, 0, 1);

    if (true) {
        
    //     // XYZ->RGB checkergrid:
    //     vec3 p = v_pos * (mod(floor(v_pos), 4.)+2.);
    //     if (mod(p.x, 2.) < 1. ^^ mod(p.y, 2.) < 1. ^^ mod(p.z, 2.) < 1.) {
    //    //     out_color += 0.2 + vec4(floor(v_pos)/vec3(20, 10, 10), 1.);
    //     } 
        
        // gridlines:
        //vec2 p = v_uv;
        vec2 p = abs(0.5-mod((v_uv * 8. + 0.5), 1.));
        vec2 p2 = exp(-100.*p);
        //out_color = mix(out_color, vec4(1), 0.5*length(p2));

        out_color.rgb += vec3(0.5, 0.5, 1) * length(p2);

    }
}