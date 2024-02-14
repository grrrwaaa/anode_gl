module.paths.push(__dirname)
const gl = require('gles3.js'),
	glfw = require('glfw3.js'),
    Window = require("window.js"),
	glutils = require('glutils.js'),
	Shaderman = require('shaderman.js')

const { vec2, vec3, vec4, quat, mat2, mat2d, mat3, mat4} = require("gl-matrix")

const {
    quat_rotate,
    quat_unrotate,
    quat_rotation_to,
    quat_fromAxisAngle
} = glutils

let window = new Window({
    dim: [1600, 1600]
})
const shaderman = new Shaderman(gl)

let cube_geom = glutils.makeCube({ div: 10 })
let cube = glutils.createVao(gl, cube_geom);

window.draw = function() {
	let { t, dt, dim } = this;

    gl.viewport(0, 0, dim[0], dim[1]);
	gl.clearColor(0., 0., 0., 1);
	gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
	gl.enable(gl.DEPTH_TEST)

    // Compute the matrix
	let viewmatrix = mat4.create();
	let projmatrix = mat4.create();
	let modelmatrix = mat4.create();
	let r = 3

	mat4.lookAt(viewmatrix, [r * Math.sin(t), 0, r*Math.cos(t)], [0, 0, 0], [0, 1, 0]);
	mat4.perspective(projmatrix, Math.PI/2, dim[0]/dim[1], 0.01, 30);
	mat4.rotate(modelmatrix, modelmatrix, t/3, [1, 1, 0])

    let shader = shaderman.shaders.metashape
    shader.begin()
	.uniform("u_modelmatrix", modelmatrix)
	.uniform("u_viewmatrix", viewmatrix)
	.uniform("u_projmatrix", projmatrix)
    .uniform("t", t)
    cube.draw()

	gl.disable(gl.BLEND)
	gl.depthMask(true)

	if (Math.floor(t+dt) > Math.floor(t)) console.log("fps", 1/dt)
}

Window.syncfps = 60
Window.animate()