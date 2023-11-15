#version 330
precision mediump float;

uniform sampler3D u_tex;
uniform float u_N;
uniform float iso;
uniform mat4 u_viewmatrix;


in vec4 v_color;
in vec3 v_normal;
in vec3 v_tc;
in vec3 v_eyepos, v_raydir, v_rayexit;
in vec3 v_viewpos;
in vec3 v_debug;
in vec3 v_ro, v_rd, v_re;

layout(location = 0) out vec4 out_color;
layout(location = 1) out vec4 out_depth;
layout(location = 2) out vec4 out_normal;

// assume box b:  0,0,0 to 1,1,1
float rayBoxExitDistance(vec3 ro, vec3 rd) {
	// pt = ro + rd*t => t = (pt-ro)/rd
	// assumes glsl handles case of rd component==0
    vec3 t1 = (0. - ro)/rd;
    vec3 t2 = (1. - ro)/rd;
	return min(min(max(t1.x, t2.x), max(t1.z, t2.z)), max(t1.y, t2.y));
}

// assume box b:  0,0,0 to 1,1,1
float rayBoxEntryDistance(vec3 ro, vec3 rd) {
	// pt = ro + rd*t => t = (pt-ro)/rd
	// assumes glsl handles case of rd component==0
    vec3 t1 = (0. - ro)/rd;
    vec3 t2 = (1. - ro)/rd;
	return max(max(min(t1.x, t2.x), min(t1.z, t2.z)), min(t1.y, t2.y));
}

vec3 normal4(in vec3 p, in sampler3D tex, float eps) {
	vec2 e = vec2(-eps, eps);
	// tetra points
	float t1 = texture(u_tex, p+e.yxx).w;
	float t2 = texture(u_tex, p+e.xxy).w;
	float t3 = texture(u_tex, p+e.xyx).w;
	float t4 = texture(u_tex, p+e.yyy).w;
	vec3 n = t1*e.yxx + t2*e.xxy + t3*e.xyx + t4*e.yyy;
	return normalize(n);
}

void main() {
	vec3 rd = normalize(v_rd);
	// this assumes we rendered with front-face culling
	// for back-face culling, 
	// ro = v_rayentry, 
	// and tmax = rayBoxExitDistance(ro, rd)
	float tmax = length(v_ro - v_re); //rayBoxExitDistance(v_rayexit, -rd);
	vec3 ro = v_ro; //v_rayexit - tmax*rd;

	// need to clamp ro to near plane, if we are inside the volume already


	// ok now step from t=0 to t=tmax
	float a = 0.;
	float dt = 0.05 / u_N;
	//float t0 = fract(tmax/dt);

	float v = 0.;

	out_color = vec4(0, 0, 0, 1);
	out_depth = vec4(0, 0, 0, 1);
	out_normal = vec4(0.5, 0.5, 1, 1);

	float t=0.;

	// if we start off inside, skip ahead:
	// for (; t < tmax; t += dt) {
	// 	vec3 pt = ro + t*rd;
	// 	float c = texture(u_tex, pt).x;
	// 	if (c < iso) break;
	// }

	float isInside = sign(texture(u_tex, ro).w - iso);

	for (; t < tmax; t += dt) {
		float weight = min(1., tmax-t);
		//float weight = min(t, 1.);
		vec3 pt = ro + t*rd;
		float c = texture(u_tex, pt).w;
		//c = sqrt(c);
		//v += max(c, 0.) * weight * 0.01;
		v = max(v, c/2.);
		//v = mix(pow(c * 2., 0.5), v, v);
		//a = max(a, c);
		// naive additive blending
		a += max(c, 0.)*dt * weight*16.; 
		// transmittance:
		float opacity = exp(-t * abs(c));
		//a += trans * dt * weight;
		//a = max(a, c*dt * weight*50.);
		// Cout(v) = Cin(v) * (1 - Opacity(x)) + Color(x) * Opacity(x)
		// float c1 = c*weight*8;
		// a = mix(c1, a, opacity);

		//a += 0.5*dt * weight;
		// did we cross the surface?
		if ((c - iso) * isInside <= 0.) {
		//if (abs(c-iso) < dt) {
			// actually probably want to estimate a refinement to `t` to get `c` closer to 0.5
			float t0 = t-dt;
			float c0 = texture(u_tex, ro + t0*rd).w;
			// we want the point `a` between t0 and t where the line from c0 to c is exactly 0.5
			// 0.5 = c0 + a*(c - c0)  => a = (0.5-c0)/(c-c0) 
			float a = (iso-c0)/(c-c0);
			float ta = t0 + a*(t-t0);

			vec3 pt = ro + ta*rd;

			// this is normal in world space
			vec3 n = normal4(pt, u_tex, 0.005);
			vec3 vn = mat3(u_viewmatrix) * n;
			//n = normalize(n);

			//if (isInside < 0.)
			//out_color += vec4(n*isInside*0.5+0.5, 1.);

			out_color.rgb = texture(u_tex, pt).rgb;

			// phongish
			float ndotl = dot(n, normalize(vec3(1)));
			ndotl = pow(max(0., ndotl), 1.0);
			out_color = mix(out_color, out_color * vec4(1.-(ndotl)), 0.5);

			// fresnelish
			float ndotr = dot(n, rd);
			ndotr = pow(abs(ndotr), 1.);
			out_color = mix(out_color, vec4(1.-abs(ndotr)), 0.3);

			

			// fade by distance:
			//out_color *= 1./(1.+t);
			//out_color *= exp(-2.*t);
			// gamma by distance:
			out_color = pow(out_color, vec4(t*3.));
			out_color.a = 1.;

			float d = 1.-t0/tmax;
			out_depth = vec4(d, d, d, 1.);
			out_normal = vec4(vn*-0.5+0.5, 1.);

			break;
		}
	}

	//a = t < tmax ? 1. : 0. ;
	//out_color = vec4(v_ro, 1.);

	// out_color = vec4(n*0.5+0.5, 1.);
	// float ndotr = dot(n, rd);
	// ndotr = pow(abs(ndotr), 0.5);
	// out_color = vec4(1.-abs(ndotr) );

	//a = 1. - exp(-(a)/tmax);
	//a = 1.-exp(a/tmax);

	//out_color = vec4(v_tc, 0.2);
	// float v = texture(u_tex, v_tc).r;
	// out_color = vec4(rd, 0.5);
	//out_color *= vec4(tmax);
	//out_color *= vec4(a);
	// out_color = vec4(0.1);
	// out_color = vec4(v_normal*0.5+0.5, 1.);
	//out_color = vec4(tmax);

	//out_color = vec4(v );
	//out_color = out_color;
	// out_color = v < 1. ? vec4(v) : out_color;

	//out_color = vec4(n, 1.);

	// out_color = vec4(v_tc, 0.2);
	//out_color = vec4(v_eyepos, 1);
	//out_color = vec4(v_debug, 1.);
}