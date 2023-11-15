const { vec2, vec3, vec4, quat, mat2, mat2d, mat3, mat4} = require("gl-matrix")

module.paths.push(__dirname)
const gl = require('gles3.js'),
	glfw = require('glfw3.js'),
    Window = require("window.js"),
	glutils = require('glutils.js'),
	Shaderman = require('shaderman.js')
const { CON_0_ATI } = require("./gles3")

let window = new Window({
	width: 1024,
	height: 1024,
	CONTEXT_VERSION_MAJOR: 4, // need gl 4.3 for compute shaders
	CONTEXT_VERSION_MINOR: 3,
})
const shaderman = new Shaderman(gl)
const quad_vao = glutils.createVao(gl, glutils.makeQuad())

/*
	Compute shaders
	- are not part of the graphics pipeline
	- define the data space they operate on
	- can pull data from and write to textures, image loads, shader storage blocks
	- whereas vertex shaders run per vertex, fragment shaders per fragment, compute shaders run per (abstract) "work item"

	Work groups
	- smallest amount of compute operations that can be executed from host application
	- they are 3D, though any dimension can be set to 1 for 2D and 1D operation
	- work groups may operate in any order
	- the invocations per work group is the "local size"
	- data can be shared within a work group but not between work groups
*/
let max_compute_work_group_count = []
let max_compute_work_group_size = []
let max_compute_work_group_invocations = gl.getIntegerv(gl.MAX_COMPUTE_WORK_GROUP_INVOCATIONS);
for (let idx = 0; idx < 3; idx++) {
	max_compute_work_group_count[idx] = gl.getIntegeri_v(gl.MAX_COMPUTE_WORK_GROUP_COUNT, idx);
	max_compute_work_group_size[idx] = gl.getIntegeri_v(gl.MAX_COMPUTE_WORK_GROUP_SIZE, idx);
}	
console.log("maximum number of work groups in each dimension", max_compute_work_group_count)
console.log("maximum size of work groups in each dimension", max_compute_work_group_size)
console.log("Number of invocations in a single local work group that may be dispatched to a compute shader ", max_compute_work_group_invocations)


//console.log(program)

// let tex = glutils.createTexture(gl, {
// 	width: 512, height: 512, 
// 	float: true,
// })

// 3d texture resolution NxNxN
let N = 64 * 2
// cube instances MxMxM
//let M = 16 

let tex3dA = glutils.createTexture3D(gl, { 
	float:true, 
	channels: 4,
	width:N,  
});
//tex3dA.data.forEach((v,i,a) => a[i] = 0.2)
//tex3dA.bind()
// gl.texParameteri(gl.TEXTURE_3D, gl.TEXTURE_WRAP_S, gl.REPEAT);
// gl.texParameteri(gl.TEXTURE_3D, gl.TEXTURE_WRAP_T, gl.REPEAT);
// gl.texParameteri(gl.TEXTURE_3D, gl.TEXTURE_WRAP_R, gl.REPEAT);
//tex3dA.submit()

let tex3dB = glutils.createTexture3D(gl, { 
	float:true, 
	channels: 4,
	width:N,  
});

let fluid_tex3dA = glutils.createTexture3D(gl, { 
	float:true, 
	channels: 4,
	width:N,  
});
let fluid_tex3dB = glutils.createTexture3D(gl, { 
	float:true, 
	channels: 4,
	width:N,  
});

let vol = glutils.createVao(gl, glutils.makeCube({ min:0, max:1, div: 128 }))

// render destination
const export_dim = [1024, 1024]
let export_gbo = glutils.makeGbuffer(gl, ...export_dim, [
    { float: false, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
    { float: false, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
    { float: false, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
])



let t = 0

window.draw = function() {
	let { dt, dim } = this;

	let viewmatrix = mat4.create();
	let projmatrix = mat4.create();
	let modelmatrix = mat4.create();
	let modelmatrix_inverse = mat4.create();
	let viewmatrix_inverse = mat4.create();
	let projmatrix_inverse = mat4.create();

	let aspect = dim[0]/dim[1]
	let near = 0.01, far = 10
	// let at = [0.5, 0.5, 0.5]
	// let d = 0.5 + 0.25*Math.sin(t * 0.25)
	// let h = at[1] + 0.125*Math.sin(t * 0.125)
	// let a = t / 8
	// let eye = [at[0] + d*Math.cos(a), h, at[2] + d*Math.sin(a)]
	// mat4.lookAt(viewmatrix, eye, at, [0, 1, 0]);

	let a = t*0.05
	let eye = [ Math.sin(a)*0.4+0.5, Math.sin(a*1.3)*0.3 + 0.5, Math.cos(a*1.5)*0.4+0.5 ]
	let at = [ Math.cos(a*1.2)*0.2+0.5, Math.sin(a*1.1)*0.1 + 0.5, Math.sin(a*1.4)*0.2+0.5 ]
	let r = 0.5 + Math.sin(t);
	
	mat4.lookAt(viewmatrix, eye, at, [0, 1, 0]);
	mat4.perspective(projmatrix, Math.PI*0.6, aspect, near, far);
	
	mat4.invert(modelmatrix_inverse, modelmatrix)
	mat4.invert(viewmatrix_inverse, viewmatrix)
	mat4.invert(projmatrix_inverse, projmatrix)

	// swap textures for double buffer
	{
		let tmp = tex3dA;
		tex3dA = tex3dB;
		tex3dB = tmp;
	}
	{
		let tmp = fluid_tex3dA;
		fluid_tex3dA = fluid_tex3dB;
		fluid_tex3dB = tmp;
	}

	fluid_tex3dB.bind(3);
	gl.texParameteri(gl.TEXTURE_3D, gl.TEXTURE_WRAP_S, gl.REPEAT);
	gl.texParameteri(gl.TEXTURE_3D, gl.TEXTURE_WRAP_T, gl.REPEAT);
	gl.texParameteri(gl.TEXTURE_3D, gl.TEXTURE_WRAP_R, gl.REPEAT);
	gl.texParameteri(gl.TEXTURE_3D, gl.TEXTURE_MIN_FILTER, gl.LINEAR);
	gl.texParameteri(gl.TEXTURE_3D, gl.TEXTURE_MAG_FILTER, gl.LINEAR);
	
	gl.bindImageTexture(2, fluid_tex3dA.id, 0, true, 0, gl.WRITE_ONLY, tex3dA.internalFormat);

	shaderman.computes.fluid.begin()
	.uniform("t", t)

	gl.dispatchCompute(fluid_tex3dA.width, fluid_tex3dA.height, fluid_tex3dA.depth);

	// void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
	// access can be READ_ONLY, WRITE_ONLY, or READ_WRITE
	gl.bindImageTexture(1, tex3dB.id, 0, true, 0, gl.READ_ONLY, tex3dB.internalFormat);
	gl.bindImageTexture(0, tex3dA.id, 0, true, 0, gl.WRITE_ONLY, tex3dA.internalFormat);

	
	//gl.memoryBarrier(gl.SHADER_IMAGE_ACCESS_BARRIER_BIT);
	
	// bind shader
	shaderman.computes.particles.begin()
	.uniform("t", t)
	// this is how to run the shader, with X, Y, Z work groups
	// here we run 1 work group per pixel (and z=1 because the image is 2D)
	// they happen in an unspecified order
	gl.dispatchCompute(tex3dA.width, tex3dA.height, tex3dA.depth);
	// make sure writing to image has finished before we use it
	// this will block the CPU; maybe want to push this call back to just before the texture is going to be used
	// see https://registry.khronos.org/OpenGL-Refpages/gl4/html/glMemoryBarrier.xhtml
	// lazy option is gl.ALL_BARRIER_BITS
	gl.memoryBarrier(gl.SHADER_IMAGE_ACCESS_BARRIER_BIT);
	//gl.memoryBarrier(gl.ALL_BARRIER_BITS);

	// render offscreen:
	export_gbo.begin() 
	{
		const { width, height } = export_gbo
		const dim = [width, height]
		gl.viewport(0, 0, dim[0], dim[1]);
		gl.clearColor(0., 0., 0., 1);
		gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
		gl.enable(gl.DEPTH_TEST)

		tex3dA.bind()

		// use back-face culling if you want to render from inside the cloud
		// this would be easier if the entire thing was handled by a cloud-pass, e.g. in gbuffer
		// then the near-plane origin & ray direction are in the shader pass,
		// the front & rear face intersections can be computed by the bounding box using model & view matrices
		// and any depth-buffer terminations can be handled in the same way
		gl.enable(gl.CULL_FACE);
		gl.cullFace(gl.FRONT)

		shaderman.shaders.ptvol.begin()
			.uniform("u_viewmatrix", viewmatrix)
			.uniform("u_projmatrix", projmatrix)
			.uniform("u_modelmatrix", modelmatrix)
			.uniform("u_modelmatrix_inverse", modelmatrix_inverse)
			.uniform("u_viewmatrix_inverse", viewmatrix_inverse)
			.uniform("u_projmatrix_inverse", projmatrix_inverse)
			.uniform("u_N", N)
			.uniform("u_tex", 0)
			.uniform("u_field_tex", 3)
			.uniform("iso", 0.5)
		vol.bind().draw().unbind()
		shaderman.shaders.vol.end();

		gl.disable(gl.CULL_FACE);
	}
	export_gbo.end()

	gl.viewport(0, 0, dim[0], dim[1]);
	gl.clearColor(0., 0., 0., 1);
	gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
	gl.enable(gl.DEPTH_TEST)


	export_gbo.bind()
	shaderman.shaders.show.begin()
	quad_vao.bind().draw()

	
	if (Math.floor(t+dt) > Math.floor(t)) {
		console.log("fps", 1/dt)
	}
	t += dt;

}

window.onpointerbutton = function(button, action, mods) {
	console.log(button, action, mods)
}

window.onkey = function(key, scan, down, mod) {
	console.log(key, scan, down, mod)
}


shaderman.on('reload', () => {
	//t = 0;
});

Window.animate()