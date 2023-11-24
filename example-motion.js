/* 
	This example is showing a kind of temporal warp lookup

	If the background is blue, we texture a cube as normal

	If the background is red, the cube's surface is being motion-projected/warped view back in time from the last frame


*/

const { vec2, vec3, vec4, quat, mat2, mat2d, mat3, mat4} = require("gl-matrix")

module.paths.push(__dirname)
const gl = require('gles3.js'),
	glfw = require('glfw3.js'),
    Window = require("window.js"),
	glutils = require('glutils.js'),
	Shaderman = require('shaderman.js')

let window = new Window({
	CONTEXT_VERSION_MAJOR: 4, // need gl 4.3 for compute shaders
	CONTEXT_VERSION_MINOR: 3,
})
const shaderman = new Shaderman(gl)
const quad_vao = glutils.createVao(gl, glutils.makeQuad())

const cube_vao = glutils.createVao(gl, glutils.makeCube({
	div: 100
}))

// we'll want a MRT fbo to gather data:
let gbo = glutils.makeGbuffer(gl, window.width, window.height, [
	{ float:false, mipmap: true, wrap: gl.CLAMP_TO_EDGE },
	// { float:true, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
	// { float:true, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
	// { float:false, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
]) 

let gbo_prev = glutils.makeGbuffer(gl, window.width, window.height, [
	{ float:false, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
	// { float:true, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
	// { float:true, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
	// { float:false, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
]) 

let modelmatrix_prev = mat4.create()
let viewmatrix_prev = mat4.create()
let projmatrix_prev = mat4.create()

window.draw = function() {
	let { t, dt, dim } = this;
	let aspect = dim[0]/dim[1]

	let test =  Math.floor(t) % 2

	let modelmatrix = mat4.create()
	let viewmatrix = mat4.create()
	let projmatrix = mat4.create()

	mat4.ortho(projmatrix, -aspect, aspect, -1, 1, 0, 10)
	mat4.perspective(projmatrix, Math.PI * 0.5, aspect, 0.1, 100)
	mat4.fromTranslation(modelmatrix, [Math.sin(t * 3), 0, 0])

	mat4.lookAt(viewmatrix, [4 * Math.cos(t), 0, 4], [0, 2 * Math.sin(t), 0], [0, 1, 0])

	{
		{
			let tmp = gbo;
			gbo = gbo_prev;
			gbo_prev = tmp;
		}
		
		const { width, height, data } = gbo
		gbo.begin()
		{
			gl.viewport(0, 0, width, height);
			gl.clearColor(test*0.5, 0, (1-test)*0.5, 1);
			gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
			gl.enable(gl.DEPTH_TEST)

			gbo_prev.bind()

			shaderman.shaders.mocube.begin()
			.uniform("u_modelmatrix", modelmatrix)
			.uniform("u_viewmatrix", viewmatrix)
			.uniform("u_projmatrix", projmatrix)
			.uniform("u_modelmatrix_prev", modelmatrix_prev)
			.uniform("u_viewmatrix_prev", viewmatrix_prev)
			.uniform("u_projmatrix_prev", projmatrix_prev)
			.uniform("test", test)
			//tex.bind()
			cube_vao.bind().draw()
		}
		gbo.end()
	}
	
	gl.viewport(0, 0, dim[0], dim[1]);
	gl.clearColor(0., 0., 0., 1);
	gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
	gl.enable(gl.DEPTH_TEST)

	shaderman.shaders.show.begin()
	gbo.bind()
	quad_vao.bind().draw()

	mat4.copy(modelmatrix_prev, modelmatrix)
	mat4.copy(viewmatrix_prev, viewmatrix)
	mat4.copy(projmatrix_prev, projmatrix)
}

Window.syncfps = 30;
Window.animate()