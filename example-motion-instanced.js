/* 
An instanced version of example-motion.js	

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

const {
	quat_rotate,
	quat_unrotate,
	quat_rotation_to,
	quat_fromAxisAngle,
	wrap, wrap_relative, 
	vec3_wrap, vec3_wrap_relative,
} = glutils

const scriptname = __filename.slice(__dirname.length + 1, -3)

let window = new Window({
	width: 1024, height: 720
})
const shaderman = new Shaderman(gl)
const quad_vao = glutils.createVao(gl, glutils.makeQuad())
const FAR = 32

const cube_vao = glutils.createVao(gl, glutils.makeCube({
	div: 4
}))

// always use vec4 
// location starts at 4, because 0-3 are reserved for pos, normal, texcoord, color
let cubes = glutils.createInstances(gl, [
	{ location: 4, name:"i_pos", components:4 },
	{ location: 5, name:"i_quat", components:4 },
	
	// previous position & orientation:
	{ location: 6, name:"i_pos0", components:4 },
	{ location: 7, name:"i_quat0", components:4 },
], 64)
// the .instances provides a convenient interface to the underlying arraybuffer
cubes.instances.forEach((obj, i)=> {
	// each field is exposed as a corresponding typedarray view
	// making it easy to use other libraries such as gl-matrix
	// this is all writing into one contiguous block of binary memory for all instances (fast)
	vec4.set(obj.i_pos, 
		(Math.random()-0.5) * FAR,
		(Math.random()-0.5) * FAR,
		(Math.random()-0.5) * FAR,
		1
	);
	
	quat.random(obj.i_quat);

	if (i==0) {
		vec3.set(obj.i_pos, 0, 0, 0)
		quat.set(obj.i_quat, 0, 0, 0, 1)
	}
})
cubes.bind().submit().unbind();
cubes.attachTo(cube_vao);

// Either way it gets blurry, mipmaps might not be necessary
let mipmap_color = true

// we'll want a MRT fbo to gather data:
let gbo = glutils.makeGbuffer(gl, window.width, window.height, [
	{ float:false, mipmap: mipmap_color, wrap: gl.CLAMP_TO_EDGE },
	{ float:true, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
	// { float:true, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
	// { float:false, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
]) 

let gbo_prev = glutils.makeGbuffer(gl, window.width, window.height, [
	{ float:false, mipmap: mipmap_color, wrap: gl.CLAMP_TO_EDGE },
	{ float:true, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
	// { float:true, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
	// { float:false, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
]) 

let viewmatrix_prev = mat4.create()
let projmatrix_prev = mat4.create()

window.draw = function() {
	let { t, dt, dim } = this;
	let aspect = dim[0]/dim[1]

	let test = ((Math.floor(t) % 2) == 1) ? 1 : 0
	let showflow = 0 //((Math.floor(t/6) % 3) == 2) ? 1 : 0

	let center = cubes.instances[0].i_pos
	let q = [0.5, 0.1, 0, 0]
	quat.fromEuler(q, 0, 0, 0.4)
	quat.normalize(q, q)
	for (let [i, obj] of Object.entries(cubes.instances)) {

		// copy old:
		vec3.copy(obj.i_pos0, obj.i_pos)
		quat.copy(obj.i_quat0, obj.i_quat)

		// move according to heading:
		let spd = 20*i/cubes.count
		let v = [spd * dt, 0, 0]
		quat_rotate(v, obj.i_quat, v);
		vec3.add(obj.i_pos, obj.i_pos, v)

		// wrap in space around the central agent
		vec3.sub(obj.i_pos, obj.i_pos, center)
		vec3_wrap_relative(obj.i_pos, obj.i_pos, FAR/2)
		vec3.add(obj.i_pos, obj.i_pos, center)

		//let obj = cubes.instances[Math.floor(Math.random() * cubes.count)];
		// change its orientation:
		//quat.random(q);
		//quat.slerp(obj.i_quat, obj.i_quat, q, 0.05);
		quat.multiply(obj.i_quat, obj.i_quat, q);
		quat.normalize(obj.i_quat, obj.i_quat)


	}
	// submit to GPU:
	cubes.bind().submit().unbind()

	let viewmatrix = mat4.create()
	let projmatrix = mat4.create()
	
	let r = 4 + Math.sin(t*0.2)*2
	let a = t/5
	let eye = [r * Math.cos(a), 0, r * Math.sin(a)]

	vec3.add(eye, eye, center)
	mat4.ortho(projmatrix, -aspect, aspect, -1, 1, 0, 10)
	mat4.perspective(projmatrix, Math.PI * 0.5, aspect, 0.1, FAR)
	mat4.lookAt(viewmatrix, eye, [0, 0, 0], [0, 1, 0])

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
			gl.clearColor(0, 0, 0, 1);
			gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
			gl.enable(gl.DEPTH_TEST)

			// bind previous frame's image to sample from:
			gbo_prev.bind(0, 0)
			gbo_prev.bind(1, 1)
			

			shaderman.shaders[scriptname].begin()
			.uniform("u_viewmatrix", viewmatrix)
			.uniform("u_projmatrix", projmatrix)
			.uniform("u_viewmatrix_prev", viewmatrix_prev)
			.uniform("u_projmatrix_prev", projmatrix_prev)
			.uniform("u_color_prev", 0)
			.uniform("u_depth_prev", 1)
			.uniform("test", test)
			.uniform("t", t)
			//tex.bind()
			//cube_vao.bind().draw()
			cube_vao.bind().drawInstanced(cubes.count).unbind()
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

	mat4.copy(viewmatrix_prev, viewmatrix)
	mat4.copy(projmatrix_prev, projmatrix)
}

Window.syncfps = 30;
Window.animate()