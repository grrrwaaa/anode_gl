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

let window = new Window({
	CONTEXT_VERSION_MAJOR: 4, // need gl 4.3 for compute shaders
	CONTEXT_VERSION_MINOR: 3,
})
const shaderman = new Shaderman(gl)

// create an initial array of points
const NUM_POINTS = 1e6;
const points = [];
// for compute shader, buffers should be aligned to 4x float
// better to just use vec4
// unfortunately createVao assumes vec3 for normals... 
// an array-of-struct Vao might be preferable to struct-of-array, but createVao doesn't know how to do that yet
for (let index = 0; index < NUM_POINTS; index++) {
	points.push((Math.random() - 0.5) * 2);
	points.push((Math.random() - 0.5) * 2);
	points.push((Math.random() - 0.5) * 2);
	points.push(1)
}

let points_vao = glutils.createVao(gl, {
	vertexComponents: 4, // vec4
	vertices: new Float32Array(points)
})


let compute_program = glutils.makeComputeProgram(gl, `
#version 450 core

// using local size=1 so we can operate per-vertex
layout (local_size_x = 1) in;

// here's our buffer of vertices coming in:
// consider "restrict writeonly" or "restrict readonly" for more efficiency if you can
layout(std430, binding = 0) buffer SSBO {
    vec4 position[];
};

uniform float t; 

void main() {
	// since our local size is 1 the global ID is the vertex index
    uint idx = gl_GlobalInvocationID.x;

	float a = t + float(idx);
	float r = 0.8;
	float dt = 0.003;
    position[idx] += dt * vec4(r*cos(a), r*sin(a), r*cos(2. * a), 1.);
}
`)

window.draw = function() {
	let { t, dt, dim } = this;


	// bind compute shader
	compute_program.begin()
	.uniform("t", t)

	// use VAO buffer for a compute shader:
	gl.bindBuffer(gl.SHADER_STORAGE_BUFFER, points_vao.vertexBuffer);
	//gl.bufferData(gl.SHADER_STORAGE_BUFFER, vertices, gl.STATIC_DRAW); // if you wanted to CPU-submit data here
	gl.bindBufferBase(gl.SHADER_STORAGE_BUFFER, 0, points_vao.vertexBuffer);

	// run one shader per vertex:
	gl.dispatchCompute(NUM_POINTS, 1, 1);
	// make sure buffer writing has finished before we use it
	gl.memoryBarrier(gl.SHADER_STORAGE_BARRIER_BIT);


	// Compute the matrix
	let modelmatrix = mat4.create();
	let viewmatrix = mat4.create();
	let projmatrix = mat4.create();
	let a = t/10
	let r = Math.sin(t/10)+1
	let eye = [r*Math.cos(a), 0, r*Math.sin(a)]
	mat4.lookAt(viewmatrix, eye, [0, 0, 0], [0, 1, 0]);
	mat4.perspective(projmatrix, Math.PI/2, dim[0]/dim[1], 0.01, 10);

	gl.viewport(0, 0, dim[0], dim[1]);
	gl.clearColor(0., 0., 0., 1);
	gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
	gl.enable(gl.DEPTH_TEST)

	// draw points

	gl.enable(gl.BLEND);
	gl.blendFunc(gl.SRC_ALPHA, gl.ONE);
	gl.depthMask(false)

	shaderman.shaders.point.begin()
	.uniform("u_viewmatrix", viewmatrix)
	.uniform("u_projmatrix", projmatrix)
	.uniform("u_modelmatrix", modelmatrix)
	.uniform("u_radius", 0.001)
	.uniform("u_resolution", dim)
	points_vao.bind().drawPoints()

	gl.disable(gl.BLEND)
	gl.depthMask(true)

	if (Math.floor(t+dt) > Math.floor(t)) {
		console.log("fps", 1/dt)
	}

}

Window.syncfps = 60
Window.animate()