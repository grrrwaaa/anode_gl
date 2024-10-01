const { vec2, vec3, vec4, quat, mat2, mat2d, mat3, mat4} = require("gl-matrix")

const { gl, glfw, glutils, Window, Shaderman } = require('./index.js')
    
/*

    In this example we render a cube two different ways
    first as a vertex-based geometry, second as a ray-marched full screen quad

    you should see depth thrashing between the two methods, proving that they are accurately placed

    this by itself is not very useful, it's more to demonstrate how to accurately calculate the position and depth of a raymarched object
    so that it can be combined with other vertex-based geometry

    note that it also works from a view inside the cube
    the code in the raymarching shader also shows how you would compute the ray origin and end for such a view
    which is useful for e.g. raymarching from inside arbitrary objects based on axis aligned bounding boxes, or for volumetric clouds, etc. 

    the code in the shader also shows how to get the face normal of the entry & exit planes of the cube
    
    


*/

let window = new Window({
	width: 1024,
	height: 1024,
})
const shaderman = new Shaderman(gl)
const quad_vao = glutils.createVao(gl, glutils.makeQuad())

let cube_size = 1.5
let cube_vao = glutils.createVao(gl, glutils.makeCube({
	min: -cube_size, max: cube_size
}))

let N = 32
let vol = glutils.createTexture3D(gl, { 
	float:true, 
	channels: 4,
	width:N,  
});


window.draw = function() {
	let { t, dt, dim } = this;

	let aspect = dim[0]/dim[1]
	let near = 0.01, far = 10

	let viewmatrix = mat4.create();
	let projmatrix = mat4.create();
	let modelmatrix = mat4.create();
	let modelmatrix_inverse = mat4.create();
	let viewmatrix_inverse = mat4.create();
	let projmatrix_inverse = mat4.create();

	// let at = [0.5, 0.5, 0.5]
	// let d = 0.5 + 0.25*Math.sin(t * 0.25)
	// let h = at[1] + 0.125*Math.sin(t * 0.125)
	// let a = t / 8
	// let eye = [at[0] + d*Math.cos(a), h, at[2] + d*Math.sin(a)]
	// mat4.lookAt(viewmatrix, eye, at, [0, 1, 0]);
    
    let ctr = [0, 0, 0]

	let a = t*0.1
    let r = 4 * Math.sin(a * 4.)
	let eye = [ r * Math.sin(a)  +ctr[0], r * Math.sin(a*1.3)  +ctr[1], r * Math.cos(a*1.5)  +ctr[2]]
	let at = [ Math.cos(a*1.2)*0.2+ctr[0], Math.sin(a*1.1)*0.1 +ctr[1], Math.sin(a*1.4)*0.2 +ctr[2] ]

	
	mat4.lookAt(viewmatrix, eye, at, [0, 1, 0]);
	mat4.perspective(projmatrix, Math.PI*0.6, aspect, near, far);

	mat4.rotateY(modelmatrix, modelmatrix, t);
	mat4.translate(modelmatrix, modelmatrix, [0, Math.cos(t), 0]);
	let s = Math.sin(t)+1.1
	mat4.scale(modelmatrix, modelmatrix, [s, s, s])
	
	mat4.invert(modelmatrix_inverse, modelmatrix)
	mat4.invert(viewmatrix_inverse, viewmatrix)
	mat4.invert(projmatrix_inverse, projmatrix)



	gl.viewport(0, 0, dim[0], dim[1]);
	gl.clearColor(0., 0., 0., 1);
	gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
	gl.enable(gl.DEPTH_TEST)


    if ((t % 1) < 0.5) {
		shaderman.shaders.geom.begin()
		.uniform("u_modelmatrix", modelmatrix)
		.uniform("u_viewmatrix", viewmatrix)
		.uniform("u_projmatrix", projmatrix)
		cube_vao.bind().draw()
	}

    shaderman.shaders.volume.begin()
    .uniform("u_modelmatrix", modelmatrix)
    .uniform("u_viewmatrix", viewmatrix)
    .uniform("u_projmatrix", projmatrix)
    .uniform("u_modelmatrix_inverse", modelmatrix_inverse)
    .uniform("u_viewmatrix_inverse", viewmatrix_inverse)
    .uniform("u_projmatrix_inverse", projmatrix_inverse)
	.uniform("u_cube_size", cube_size)
    quad_vao.bind().draw()

        


	
	if (Math.floor(t+dt) > Math.floor(t)) {
		console.log("fps", 1/dt)
	}

}

window.onpointerbutton = function(button, action, mods) {
	console.log(button, action, mods)
}

window.onkey = function(key, scan, down, mod) {
	console.log(key, scan, down, mod)
}

Window.syncfps = 60
Window.animate()