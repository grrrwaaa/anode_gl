module.paths.push(__dirname)
const gl = require('gles3.js'),
	glfw = require('glfw3.js'),
    Window = require("window.js"),
	glutils = require('glutils.js'),
	Shaderman = require('shaderman.js')

const { vec2, vec3, vec4, quat, mat2, mat2d, mat3, mat4} = require("gl-matrix")

const scriptname = __filename.slice(__dirname.length + 1, -3)

let FAR = 30
let NUM_INSTANCES = 32

let window = new Window()
const shaderman = new Shaderman(gl)

const quad = glutils.createVao(gl, glutils.makeQuad({ div: 4 }))
const cube = glutils.createVao(gl, glutils.makeCube())

let quads = glutils.createInstances(gl, [
	{ location: 4, name:"i_pos", components:4 },
	{ location: 5, name:"i_quat", components:4 },
], NUM_INSTANCES)

let cubes = glutils.createInstances(gl, [
	{ location: 4, name:"i_pos", components:4 },
	{ location: 5, name:"i_quat", components:4 },
], NUM_INSTANCES)

quads.instances.forEach((obj, i)=> {
	// each field is exposed as a corresponding typedarray view
	// making it easy to use other libraries such as gl-matrix
	// this is all writing into one contiguous block of binary memory for all instances (fast)
	vec4.set(obj.i_pos, 
		(Math.random()-0.5) * FAR,
		(Math.random()-0.5) * FAR,
		(Math.random()-0.5) * FAR,
		1
	);
	if (i==0) vec3.set(obj.i_pos, 0, 0, 0, 1)

    quat.set(obj.i_quat, 0, 0, 0, 1)
	//quat.random(obj.i_quat);
})
quads.bind().submit().unbind();

quads.attachTo(quad);
quads.attachTo(cube);

window.draw = function() {
	let { t, dt, dim } = this;

    let q = quat.fromValues(0.01, 0, 0, 1)
    quat.normalize(q, q)
	for (let [i, obj] of Object.entries(quads.instances)) {
		//let obj = cubes.instances[Math.floor(Math.random() * cubes.count)];
		// change its orientation:
		//quat.random(q);
		//quat.slerp(obj.i_quat, obj.i_quat, q, 0.02);
        //quat.mul(obj.i_quat, obj.i_quat, q)
		quat.normalize(obj.i_quat, obj.i_quat)

        if (i==0) {
            obj.i_pos[0] = Math.sin(t)
        }
	}
	// submit to GPU:
	quads.bind().submit().unbind()

    // Compute the matrix
	let viewmatrix = mat4.create();
	let projmatrix = mat4.create();
	let modelmatrix = mat4.create();
	let modelmatrix_inverse = mat4.create();
	let viewmatrix_inverse = mat4.create();
	let projmatrix_inverse = mat4.create();
	let r = 3
	let a = t/4

	let at = [0, 0, 0]
	let eye = [r * Math.sin(a), 0, r*Math.cos(a)]
	vec3.add(eye, eye, at)

	mat4.lookAt(viewmatrix, eye, at, [0, 1, 0]);
	mat4.perspective(projmatrix, Math.PI/2, dim[0]/dim[1], 0.01, FAR);
	mat4.rotate(modelmatrix, modelmatrix, a/3, [1, 1, 0])
	
	mat4.invert(modelmatrix_inverse, modelmatrix)
	mat4.invert(viewmatrix_inverse, viewmatrix)
	mat4.invert(projmatrix_inverse, projmatrix)

    //console.log(viewmatrix)

    gl.viewport(0, 0, dim[0], dim[1]);
	gl.clearColor(0., 0., 0., 1);
	gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
	gl.enable(gl.DEPTH_TEST)

    
    shaderman.shaders[scriptname + ".cube"].begin()
	//.uniform("u_modelmatrix", modelmatrix)
	.uniform("u_viewmatrix", viewmatrix)
	.uniform("u_projmatrix", projmatrix)
    // .uniform("u_modelmatrix_inverse", modelmatrix_inverse)
    .uniform("u_viewmatrix_inverse", viewmatrix_inverse)
    .uniform("u_projmatrix_inverse", projmatrix_inverse)
    //.uniform("t", t)
    cube.bind().drawInstanced(quads.count).unbind()

	gl.enable(gl.BLEND);
	gl.blendEquation(gl.FUNC_ADD)
	gl.blendFunc(gl.SRC_ALPHA, gl.ONE);
	gl.blendFuncSeparate(gl.ONE, gl.ONE, gl.ZERO, gl.ONE_MINUS_SRC_ALPHA);
	gl.depthMask(false)

    let shader = shaderman.shaders[scriptname]
    shader.begin()
	//.uniform("u_modelmatrix", modelmatrix)
	.uniform("u_viewmatrix", viewmatrix)
	.uniform("u_projmatrix", projmatrix)
    // .uniform("u_modelmatrix_inverse", modelmatrix_inverse)
    .uniform("u_viewmatrix_inverse", viewmatrix_inverse)
    .uniform("u_projmatrix_inverse", projmatrix_inverse)
    .uniform("t", t)
    quad.bind().drawInstanced(quads.count).unbind()


	gl.disable(gl.BLEND)
	gl.depthMask(true)

	if (Math.floor(t+dt) > Math.floor(t)) console.log("fps", 1/dt)
}

Window.syncfps = 60
Window.animate()