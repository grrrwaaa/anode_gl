const assert = require("assert")
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
    byteSizeForGLType
} = glutils

const scriptname = __filename.slice(__dirname.length + 1, -3)

const FAR = 20

let window = new Window({
	width: 1024, height: 720
})
const shaderman = new Shaderman(gl)


let NUM_POINTS = 1e5

// the makeCube(), makeQuad() etc. methods create a geometry object as a "struct of arrays"
// i.e. geom.vertices, geom.normals, etc.

// but for things like particle fields, and for compute shaders,
// it makes more sense to have an "array of structs"
// in which ALL attributes of an object are contiguous in memory
// that's also what we used for making instances, and we can abuse the same interface here:

let particle_buffer = glutils.createInstances(gl, [
    { location: 0, name:"a_position", components:4 },
    { location: 3, name:"a_color", components:4 },
], NUM_POINTS)

// initialize particles:
particle_buffer.instances.forEach((o, i) => {
    let pos = o.a_position
    let col = o.a_color
    // random point, set .w to 1
    if (i) vec3.random(pos, FAR/2)
    pos[3] = 1

    vec4.set(col, 1, 1, 1, 1)
    vec3.random(col, 0.5)
    vec3.add(col, col, [0.5, 0.5, 0.5])
    col[3] = 1

})
particle_buffer.bind().submit()

let particle_vao = glutils.createVao(gl).attach(particle_buffer)



window.draw = function() {
	let { t, dt, dim } = this;
	let aspect = dim[0]/dim[1]
    let [width, height] = dim

    particle_buffer.instances.forEach((o, i) => {
        let pos = o.a_position
        let col = o.a_color

        let v = [0, 0, 0]
        vec3.random(v, dt)

        vec3.add(pos, pos, v)
    })
    particle_buffer.bind().submit()

	let viewmatrix = mat4.create()
	let projmatrix = mat4.create()
	
	let r = 4 + Math.sin(t*0.2)*2
	let a = t/5
    let center = [0, 0, 0]
	let eye = [r * Math.cos(a), 0, r * Math.sin(a)]

	vec3.add(eye, eye, center)
	mat4.ortho(projmatrix, -aspect, aspect, -1, 1, 0, 10)
	mat4.perspective(projmatrix, Math.PI * 0.5, aspect, 0.1, FAR)
	mat4.lookAt(viewmatrix, eye, [0, 0, 0], [0, 1, 0])

    gl.viewport(0, 0, width, height);
    gl.clearColor(0, 0, 0, 1);
    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
    gl.enable(gl.DEPTH_TEST)    

    shaderman.shaders[scriptname].begin()
    .uniform("u_viewmatrix", viewmatrix)
    .uniform("u_projmatrix", projmatrix)
    .uniform("u_resolution", dim)
    .uniform("u_radius", 0.1)
    //.uniform("t", t)
    //tex.bind()
    particle_vao.bind().drawPoints(particle_buffer.count)	
}

Window.syncfps = 30;
Window.animate()