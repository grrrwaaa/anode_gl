const { vec2, vec3, vec4, quat, mat2, mat2d, mat3, mat4} = require("gl-matrix")

module.paths.push(__dirname)
const gl = require('gles3.js'),
	glfw = require('glfw3.js'),
    Window = require("window.js"),
	glutils = require('glutils.js'),
	Shaderman = require('shaderman.js')
const Prng = require("prng.js")

const Rnd = new Prng("blahblahseed")

let window = new Window({
	sync: true
})
const shaderman = new Shaderman(gl)
let w = 2
let h = 1
const quad_vao = glutils.createVao(gl, glutils.makeQuad({
	//min:[-w/2, -h/2], max: [w/2, h/2],
	min: 0, max: 1,
	div: 32
}))

const overlay_quad_vao = glutils.createVao(gl, glutils.makeQuad({
	min: -1, max: -0.66
}))

let fbo = glutils.makeFboWithDepth(gl)

let cubeprogram = glutils.makeProgram(gl,
`#version 330
uniform mat4 u_viewmatrix;
uniform mat4 u_projmatrix;

// instanced variable:
in vec4 i_pos;
in vec4 i_quat;

in vec3 a_position;
in vec3 a_normal;
in vec2 a_texCoord;
out vec4 v_color;
out vec3 v_normal;

// http://www.geeks3d.com/20141201/how-to-rotate-a-vertex-by-a-quaternion-in-glsl/
vec3 quat_rotate( vec4 q, vec3 v ){
	return v + 2.0 * cross( q.xyz, cross( q.xyz, v ) + q.w * v );
}
vec4 quat_rotate( vec4 q, vec4 v ){
	return vec4(v.xyz + 2.0 * cross( q.xyz, cross( q.xyz, v.xyz ) + q.w * v.xyz), v.w );
}

void main() {
	// Multiply the position by the matrix.
	vec4 vertex = vec4(a_position, 1.);
	vertex = quat_rotate(i_quat, vertex);
	vertex.xyz += i_pos.xyz;
	gl_Position = u_projmatrix * u_viewmatrix * vertex;

	v_normal = quat_rotate(i_quat, a_normal);

	v_color = vec4(v_normal*0.25+0.25, 1.);
	v_color += vec4(a_texCoord*0.5, 0., 1.);
}
`,
`#version 330
precision mediump float;

in vec4 v_color;
in vec3 v_normal;
out vec4 outColor;

void main() {
	outColor = v_color;
}
`);

// create a VAO from a basic geometry and shader
let cube = glutils.createVao(gl, glutils.makeCube({ min:-0.1, max:0.1, div: 8 }), cubeprogram.id);

// create a VBO & friendly interface for the instances:
// TODO: could perhaps derive the fields from the vertex shader GLSL?
let cubes = glutils.createInstances(gl, [
	{ name:"i_pos", components:4 },
	{ name:"i_quat", components:4 },
], 200)

// the .instances provides a convenient interface to the underlying arraybuffer
cubes.instances.forEach(obj => {
	// each field is exposed as a corresponding typedarray view
	// making it easy to use other libraries such as gl-matrix
	// this is all writing into one contiguous block of binary memory for all instances (fast)
	vec4.set(obj.i_pos, 
		(Rnd.random()-0.5) * 5,
		(Rnd.random()-0.5) * 5,
		(Rnd.random()-1) * 5,
		1
	);
	//quat.random(obj.i_quat);
	quat.set(obj.i_quat, Rnd.srandom(), Rnd.srandom(), Rnd.srandom(), Rnd.srandom())
	quat.normalize(obj.i_quat, obj.i_quat)
})
cubes.bind().submit().unbind();

// attach these instances to an existing VAO:
cubes.attachTo(cube);

function scene(projmatrix, viewmatrix) {
	cubeprogram.begin()
	.uniform("u_viewmatrix", viewmatrix)
	.uniform("u_projmatrix", projmatrix)
	cube.bind().drawInstanced(cubes.count).unbind()
	cubeprogram.end();
}

window.draw = function() {
	let { t, dt, dim } = this;

	let viewmatrix = mat4.create();
	let projmatrix = mat4.create();
	let modelmatrix = mat4.create();

	// standard projection matrix for window:
	let aspect = dim[0]/dim[1]
	let near = 0.01, far = 10
	let fovy = Math.PI * 0.75
	mat4.perspective(projmatrix, fovy, aspect, near, far);

	// generate some animated viewmatrix:
	let ex = Math.cos(t)
	let ez = 0.5+Math.sin(t)
	let at = [ex, ex, ez-2]
	let eye = [ex, ex, ez] 
	let up = [0, 1, 0]
	vec3.normalize(up, up)
	let uz = vec3.sub(vec3.create(), eye, at)
	vec3.normalize(uz, uz)
	let ux = vec3.cross(vec3.create(), up, uz)
	vec3.normalize(ux, ux)
	up = vec3.cross(vec3.create(), uz, ux)
	vec3.normalize(up, up)
	mat4.set(viewmatrix, 
		...ux, 0, 
		...up, 0, 
		...uz, 0, 
		-eye[0], -eye[1], -eye[2], 1
	)
	let mrot = mat4.fromRotation(mat4.create(), Math.sin(t), [1, 0, 1])
	mat4.multiply(viewmatrix, viewmatrix, mrot)

	
	// generate some animated plane pose:
	let pos = [
		2*Math.sin(t), 
		0, 
		Math.sin(t*2) -2
	]
	mat4.rotateX(modelmatrix, modelmatrix, Math.sin(t)*0.3)
	mat4.rotateY(modelmatrix, modelmatrix, Math.sin(t*3)*0.3)
	mat4.rotateZ(modelmatrix, modelmatrix, Math.sin(t*2)*0.3)
	mat4.translate(modelmatrix, modelmatrix, pos)
	// for a 2x1 aspect ratio plane:
	mat4.scale(modelmatrix, modelmatrix, [2, 1, 1])
	
	// render the scene into the plane:
	fbo.begin()
	{
		let dim = [fbo.width, fbo.height]
		gl.viewport(0, 0, dim[0], dim[1]);
		gl.clearColor(0.1, 0.1, 0.1, 1);
		gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
		gl.enable(gl.DEPTH_TEST)

		// compute the locations of 3 of the plane corners in world space
		// here we assume a unit quad and use the modelmatrix to transform to world space
		let a = vec3.transformMat4(vec3.create(), [0, 0, 0], modelmatrix)
		let b = vec3.transformMat4(vec3.create(), [1, 0, 0], modelmatrix)
		let c = vec3.transformMat4(vec3.create(), [0, 1, 0], modelmatrix)

		// derive new projection & view matrices for the plane
		// this depends on the global viewmatrix to take into account eye position & orientation
		// and the near/far for depth clipping
		scene(...glutils.viewThroughPlane(viewmatrix, a, b, c, near, far))
	}
	fbo.end()

	gl.viewport(0, 0, dim[0], dim[1]);
	gl.clearColor(0., 0., 0., 1);
	gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
	gl.enable(gl.DEPTH_TEST)

	// now render scene to the window:
	scene(projmatrix, viewmatrix)

	// insert the plane in 3D
	fbo.bind()
	shaderman.shaders.quad.begin()
	.uniform("u_modelmatrix", modelmatrix)
	.uniform("u_viewmatrix", viewmatrix)
	.uniform("u_projmatrix", projmatrix)
	quad_vao.bind().draw()

	// overlay in screenspace to show what the plane is seeing
	shaderman.shaders.quad.begin()
	.uniform("u_modelmatrix", mat4.create())
	.uniform("u_viewmatrix", mat4.create())
	.uniform("u_projmatrix", mat4.create())
	overlay_quad_vao.bind().draw()

}

Window.animate()