/*	
	A minimal example of how we can use a compute shader to update the data in a VBO
*/

module.paths.push(__dirname)
const gl = require('gles3.js'),
	glfw = require('glfw3.js'),
    Window = require("window.js"),
	glutils = require('glutils.js'),
	Shaderman = require('shaderman.js')

const { vec2, vec3, vec4, quat, mat2, mat2d, mat3, mat4} = require("gl-matrix")


const NUM_INSTANCES = 1e5;

let window = new Window({
	CONTEXT_VERSION_MAJOR: 4, // need gl 4.3 for compute shaders
	CONTEXT_VERSION_MINOR: 3,
})
const shaderman = new Shaderman(gl)
let cube_vao = glutils.createVao(gl, glutils.makeCube())

let cubes = glutils.createInstances(gl, [
	{ name:"i_pos", 	components:4, 	location:5 },
	{ name:"i_quat", 	components:4, 	location:6 },
], NUM_INSTANCES)

// the .instances provides a convenient interface to the underlying arraybuffer
cubes.instances.forEach(obj => {
	// each field is exposed as a corresponding typedarray view
	// making it easy to use other libraries such as gl-matrix
	// this is all writing into one contiguous block of binary memory for all instances (fast)
	vec4.set(obj.i_pos, 
		(Math.random()-0.5),
		(Math.random()-0.5),
		(Math.random()-0.5),
		1
	);
	quat.random(obj.i_quat);
})
cubes.bind().submit().unbind();

console.log(cubes)

// attach these instances to an existing VAO:
cubes.attachTo(cube_vao);



window.draw = function() {
	let { t, dt, dim } = this;

	// bind compute shader
	shaderman.computes.icube.begin()
	.uniform("t", t)
	.uniform("dt", dt)

	// use VAO buffer for a compute shader:
	gl.bindBuffer(gl.SHADER_STORAGE_BUFFER, cubes.id);
	// gl.bufferData(gl.SHADER_STORAGE_BUFFER, vertices, gl.STATIC_DRAW); // if you wanted to CPU-submit data here
	gl.bindBufferBase(gl.SHADER_STORAGE_BUFFER, 0, cubes.id);

	// run one shader per vertex:
	// perhaps would be better to run as NxN though
	gl.dispatchCompute(NUM_INSTANCES, 1, 1);
	// make sure buffer writing has finished before we use it
	gl.memoryBarrier(gl.SHADER_STORAGE_BARRIER_BIT);

	// if you want to pull them back to CPU:
	if (Math.floor(t+dt)>Math.floor(t)) {
		
		//gl.getBufferData(gl.ARRAY_BUFFER, cubes.data)
		//gl.getBufferSubData(gl.ARRAY_BUFFER, 0, cubes.data.byteLength, cubes.data)	
		cubes.bind().getData()
		console.log(new Float32Array(cubes.data))
	}


	// Compute the matrix
	let modelmatrix = mat4.create();
	let viewmatrix = mat4.create();
	let projmatrix = mat4.create();
	let a = t/5
	let r = (Math.sin(a+1)) / 2
	let eye = [r*Math.cos(a), 0, r*Math.sin(a)]
	mat4.lookAt(viewmatrix, eye, [0, 0, 0], [0, 1, 0]);
	mat4.perspective(projmatrix, Math.PI/2, dim[0]/dim[1], 0.01, 100);
	
	let modelmatrix_inverse = mat4.create();
	let viewmatrix_inverse = mat4.create();
	let projmatrix_inverse = mat4.create();
	mat4.invert(modelmatrix_inverse, modelmatrix)
	mat4.invert(viewmatrix_inverse, viewmatrix)
	mat4.invert(projmatrix_inverse, projmatrix)

	gl.viewport(0, 0, dim[0], dim[1]);
	gl.clearColor(0., 0., 0., 1);
	gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
	gl.enable(gl.DEPTH_TEST)

	// draw points

	// gl.enable(gl.BLEND);
	// gl.blendFunc(gl.SRC_ALPHA, gl.ONE);
	// gl.depthMask(false)

	shaderman.shaders.icube.begin()
	.uniform("u_viewmatrix", viewmatrix)
	.uniform("u_projmatrix", projmatrix)
    .uniform("u_viewmatrix_inverse", viewmatrix_inverse)
    .uniform("u_projmatrix_inverse", projmatrix_inverse)
	.uniform("u_size", 1/500)
	cube_vao.bind().drawInstanced(cubes.count).unbind()

	gl.disable(gl.BLEND)
	gl.depthMask(true)

	if (Math.floor(t+dt) > Math.floor(t)) console.log("fps", 1/dt)
}

Window.syncfps = 60
Window.animate()