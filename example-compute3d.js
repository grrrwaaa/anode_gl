const { vec2, vec3, vec4, quat, mat2, mat2d, mat3, mat4} = require("gl-matrix")

module.paths.push(__dirname)
const gl = require('gles3.js'),
	glfw = require('glfw3.js'),
    Window = require("window.js"),
	glutils = require('glutils.js'),
	Shaderman = require('shaderman.js')
const { CON_0_ATI } = require("./gles3")

let window = new Window({
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


let program = shaderman.computes.test3d

//console.log(program)

// let tex = glutils.createTexture(gl, {
// 	width: 512, height: 512, 
// 	float: true,
// })

// 3d texture resolution NxNxN
let N = 64 * 3
// cube instances MxMxM
let M = 16 

let tex3dA = glutils.createTexture3D(gl, { 
	float:true, 
	channels: 1,
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
	channels: 1,
	width:N,  
});

// lets make an instanced array of cubes:
let cube = glutils.createVao(gl, glutils.makeCube({ min:-0.5/M, max:0.5/M, div: 2 }), shaderman.shaders.icubes.id)
let cubes = glutils.createInstances(gl, [
	{ name:"i_pos", components:4 },
	{ name:"i_quat", components:4 },
], M*M*M)
// the .instances provides a convenient interface to the underlying arraybuffer
cubes.instances.forEach((obj, i) => {
	let x = 0.5 + i % M;
	let y = 0.5 + Math.floor(i/M) % M;
	let z = 0.5 + Math.floor(i/(M*M)) % M;
	// each field is exposed as a corresponding typedarray view
	// making it easy to use other libraries such as gl-matrix
	// this is all writing into one contiguous block of binary memory for all instances (fast)
	vec4.set(obj.i_pos, 
		x/M,
		y/M,
		z/M,
		1
	);
	quat.set(obj.i_quat, 0, 0, 0, 1);
})
cubes.bind().submit().unbind();
// attach these instances to an existing VAO:
cubes.attachTo(cube);

let vol = glutils.createVao(gl, glutils.makeCube({ min:0, max:1, div: 128 }))


window.draw = function() {
	let { t, dt, dim } = this;

	let viewmatrix = mat4.create();
	let projmatrix = mat4.create();
	let modelmatrix = mat4.create();
	let modelmatrix_inverse = mat4.create();
	let viewmatrix_inverse = mat4.create();
	let projmatrix_inverse = mat4.create();

	let aspect = dim[0]/dim[1]
	let near = 0.01, far = 10
	let at = [0.5, 0.5, 0.5]
	let d = 1 + 0.5*Math.sin(t * 0.5)
	let a = t / 8
	let eye = [at[0] + d*Math.cos(a), at[1], at[2] + d*Math.sin(a)]
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
	
	// void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
	// access can be READ_ONLY, WRITE_ONLY, or READ_WRITE
	gl.bindImageTexture(1, tex3dB.id, 0, true, 0, gl.READ_ONLY, tex3dB.internalFormat);
	gl.bindImageTexture(0, tex3dA.id, 0, true, 0, gl.WRITE_ONLY, tex3dA.internalFormat);
	
	// bind shader
	program.begin()
	.uniform("t", t)
	// this is how to run the shader, with X, Y, Z work groups
	// here we run 1 work group per pixel (and z=1 because the image is 2D)
	// they happen in an unspecified order
	gl.dispatchCompute(tex3dA.width, tex3dA.height, tex3dA.depth);
	// make sure writing to image has finished before we use it
	// this will block the CPU; maybe want to push this call back to just before the texture is going to be used
	// see https://registry.khronos.org/OpenGL-Refpages/gl4/html/glMemoryBarrier.xhtml
	// lazy option is gl.ALL_BARRIER_BITS
	//gl.memoryBarrier(gl.SHADER_IMAGE_ACCESS_BARRIER_BIT);
	gl.memoryBarrier(gl.ALL_BARRIER_BITS);

	gl.viewport(0, 0, dim[0], dim[1]);
	gl.clearColor(0., 0., 0., 1);
	gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
	gl.enable(gl.DEPTH_TEST)


	tex3dA.bind()

	if (0) {
		shaderman.shaders.icubes.begin()
		.uniform("u_modelmatrix", modelmatrix)
		.uniform("u_viewmatrix", viewmatrix)
		.uniform("u_projmatrix", projmatrix)
		cube.bind().drawInstanced(cubes.count)
	} else {

		// use back-face culling if you want to render from inside the cloud
		// this would be easier if the entire thing was handled by a cloud-pass, e.g. in gbuffer
		// then the near-plane origin & ray direction are in the shader pass,
		// the front & rear face intersections can be computed by the bounding box using model & view matrices
		// and any depth-buffer terminations can be handled in the same way
		gl.enable(gl.CULL_FACE);
		gl.cullFace(gl.FRONT)

		shaderman.shaders.vol.begin()
			.uniform("u_viewmatrix", viewmatrix)
			.uniform("u_projmatrix", projmatrix)
			.uniform("u_modelmatrix", modelmatrix)
			.uniform("u_modelmatrix_inverse", modelmatrix_inverse)
			.uniform("u_viewmatrix_inverse", viewmatrix_inverse)
			.uniform("u_projmatrix_inverse", projmatrix_inverse)
			.uniform("u_N", M)
			.uniform("u_tex", 0)
		vol.bind().draw().unbind()
		shaderman.shaders.vol.end();

		gl.disable(gl.CULL_FACE);
	}

	if (Math.floor(t+dt) > Math.floor(t)) {
		console.log("fps", 1/dt)
	}

}

Window.animate()