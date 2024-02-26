/* 
	This example is showing a kind of temporal warp lookup

	If the background is black, we are texturing a cube as normal

	If the background is red, the cube's surface is being motion-projected/warped view back in time from the last frame

	Here's how it works:
	- always capture the scene to an fbo
	- bounce between 2 fbos so we can use the previous frame's texture

	- to reproject, take the object vertex and apply the previous frame's model, view and proj matrices to get clip space, then divide by .w and map from -1,1 to 0,1 to get a texture coordinate spanning the screen
	- use this texture coordinate to grab color from the previous frame's fbo texture

	Notice how the texture gets mangled when off-screen

	We've also shown how to compute the screen-space optical flow, 
	which is just the current minus previous screentex coordinate,
	which we're writing into fbo channel 1
*/

const { vec2, vec3, vec4, quat, mat2, mat2d, mat3, mat4} = require("gl-matrix")

module.paths.push(__dirname)
const gl = require('gles3.js'),
	glfw = require('glfw3.js'),
    Window = require("window.js"),
	glutils = require('glutils.js'),
	Shaderman = require('shaderman.js')

const scriptname = __filename.slice(__dirname.length + 1, -3)

let window = new Window({
	CONTEXT_VERSION_MAJOR: 4, // need gl 4.3 for compute shaders
	CONTEXT_VERSION_MINOR: 3,
})
const shaderman = new Shaderman(gl)
const quad_vao = glutils.createVao(gl, glutils.makeQuad())

const cube_vao = glutils.createVao(gl, glutils.makeCube({
	div: 4
}))

// we'll want a MRT fbo to gather data:
let gbo = glutils.makeGbuffer(gl, window.width, window.height, [
	{ float:false, mipmap: true, wrap: gl.CLAMP_TO_EDGE },
	{ float:true, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
	// { float:true, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
	// { float:false, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
]) 

let gbo_prev = glutils.makeGbuffer(gl, window.width, window.height, [
	{ float:false, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
	{ float:true, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
	// { float:true, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
	// { float:false, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
]) 

let modelmatrix_prev = mat4.create()
let viewmatrix_prev = mat4.create()
let projmatrix_prev = mat4.create()

window.draw = function() {
	let { t, dt, dim } = this;
	let aspect = dim[0]/dim[1]

	let test = ((Math.floor(t/6) % 3) == 1) ? 1 : 0
	let showflow = ((Math.floor(t/6) % 3) == 2) ? 1 : 0

	let modelmatrix = mat4.create()
	let viewmatrix = mat4.create()
	let projmatrix = mat4.create()

	mat4.ortho(projmatrix, -aspect, aspect, -1, 1, 0, 10)
	mat4.perspective(projmatrix, Math.PI * 0.5, aspect, 0.1, 100)
	mat4.fromTranslation(modelmatrix, [2 * Math.sin(t * 7), Math.cos(t*5), 0])

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
			gl.clearColor(test && !showflow ? 0.5 : 0, 0, 0, 1);
			gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
			gl.enable(gl.DEPTH_TEST)

			gbo_prev.bind()

			shaderman.shaders[scriptname].begin()
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
	gbo.bind(showflow)
	quad_vao.bind().draw()

	mat4.copy(modelmatrix_prev, modelmatrix)
	mat4.copy(viewmatrix_prev, viewmatrix)
	mat4.copy(projmatrix_prev, projmatrix)
}

Window.syncfps = 30;
Window.animate()