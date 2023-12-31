const assert = require("assert")
const { vec2, vec3, vec4, quat, mat2, mat2d, mat3, mat4} = require("gl-matrix")
const gl = require('./gles3.js') 
const glfw = require('./glfw3.js')
const glutils = require('./glutils.js');

if (!glfw.init()) {
	console.log("Failed to initialize GLFW");
	process.exit(-1);
}
let version = glfw.getVersion();
console.log('glfw ' + version.major + '.' + version.minor + '.' + version.rev);
console.log('glfw version-string: ' + glfw.getVersionString());

// Open OpenGL window
glfw.defaultWindowHints();
glfw.windowHint(glfw.CONTEXT_VERSION_MAJOR, 3);
glfw.windowHint(glfw.CONTEXT_VERSION_MINOR, 3);
glfw.windowHint(glfw.OPENGL_FORWARD_COMPAT, 1);
glfw.windowHint(glfw.OPENGL_PROFILE, glfw.OPENGL_CORE_PROFILE);

let window = glfw.createWindow(720, 480, "Test");
if (!window) {
	console.log("Failed to open GLFW window");
	glfw.terminate();
	process.exit(-1);
}

// glfw.setWindowPosCallback(window, function(w, x, y) {
// 	console.log("window moved", w, x, y)
// 	return 1;
// })

// glfw.setMouseButtonCallback(window, function(...args) {
// 	console.log("mouse button", args);
// })

glfw.makeContextCurrent(window);
console.log(gl.glewInit());

//can only be called after window creation!
console.log('GL ' + glfw.getWindowAttrib(window, glfw.CONTEXT_VERSION_MAJOR) + '.' + glfw.getWindowAttrib(window, glfw.CONTEXT_VERSION_MINOR) + '.' + glfw.getWindowAttrib(window, glfw.CONTEXT_REVISION) + " Core Profile?: " + (glfw.getWindowAttrib(window, glfw.OPENGL_PROFILE)==glfw.OPENGL_CORE_PROFILE));

// Enable vertical sync (on cards that support it)
glfw.swapInterval(1); // 0 for vsync off

let cubeprogram = glutils.makeProgram(gl,
`#version 330
uniform mat4 u_modelmatrix;
uniform mat4 u_viewmatrix;
uniform mat4 u_projmatrix;
in vec3 a_position;
in vec3 a_normal;
in vec2 a_texCoord;
out vec4 v_color;

void main() {
	// Multiply the position by the matrix.
	vec3 vertex = a_position.xyz;
	gl_Position = u_projmatrix * u_viewmatrix * u_modelmatrix * vec4(vertex, 1);

	v_color = vec4(a_normal*0.25+0.25, 1.);
	v_color += vec4(a_texCoord*0.5, 0., 1.);

	// if using gl.POINTS:
	gl_PointSize = 10.;
}
`,
`#version 330
precision mediump float;

in vec4 v_color;
out vec4 outColor;

void main() {
	outColor = v_color;
}
`);
let s = 0.1
let cube = glutils.createVao(gl, glutils.makeCube({
	min: [-s*2, -s, s*-10],
	max: [ s*2,  s, 0]
}), cubeprogram.id);

let target = glutils.createVao(gl, glutils.makeCube({
	min: [-0.1, -0.1, -0.1],
	max: [ 0.1,  0.1,  0.1]
}), cubeprogram.id);

let targetpt = [2, 0, 0]

let view = {
	pos: [0,0,0],
	quat: quat.create(),
}

let t = glfw.getTime();
let fps = 60;



function lookToward(view_quat, view_pos, target_pos=[0,0,0], amt=1, fwd=[0,0,-1]) {

	// world space direction vector from viewer to target
	let dir = vec3.create()
	vec3.sub(dir, target_pos, view_pos);
	let r = quat.create()
	glutils.quat_rotation_to(r, view_quat, dir, fwd);
	
	let q1 = quat.create()
	quat.multiply(q1, r, view_quat)

	quat.slerp(view_quat, view_quat, q1, amt)
}

function animate() {
	if(glfw.windowShouldClose(window) || glfw.getKey(window, glfw.KEY_ESCAPE)) {
		shutdown();
	} else {
		setImmediate(animate)
	}

	let t1 = glfw.getTime();
	let dt = t1-t;
	fps += 0.1*((1/dt)-fps);
	t = t1;
	glfw.setWindowTitle(window, `fps ${fps}`);
	// Get window size (may be different than the requested size)
	let dim = glfw.getFramebufferSize(window);

	let vel = vec3.create()
	vec3.random(vel, Math.random()*Math.sin(t)*Math.sin(t)*2)
	vec3.add(targetpt, targetpt, vel);
	// keep it on a sphere:
	vec3.normalize(targetpt, targetpt);
	vec3.scale(targetpt, targetpt, 2.);

	// update view to follow it:
	lookToward(view.quat, view.pos, targetpt, dt)

	// Compute the matrix
	let viewmatrix = mat4.create();
	let projmatrix = mat4.create();
	let modelmatrix = mat4.create();
	mat4.lookAt(viewmatrix, [0, 0, 3], [0, 0, 0], [0, 1, 0]);
	mat4.perspective(projmatrix, Math.PI/2, dim[0]/dim[1], 0.01, 30);

	

	gl.viewport(0, 0, dim[0], dim[1]);
	gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
	gl.enable(gl.DEPTH_TEST)

	cubeprogram.begin();
	cubeprogram.uniform("u_viewmatrix", viewmatrix);
	cubeprogram.uniform("u_projmatrix", projmatrix);

	mat4.fromRotationTranslation(modelmatrix, view.quat, view.pos);
	cubeprogram.uniform("u_modelmatrix", modelmatrix);
	cube.bind().draw().unbind();

	mat4.fromTranslation(modelmatrix, targetpt)
	cubeprogram.uniform("u_modelmatrix", modelmatrix);
	target.bind().draw().unbind();

	cubeprogram.end();

	// Swap buffers
	glfw.swapBuffers(window);
	glfw.pollEvents();
	
}

function shutdown() {
	// Close OpenGL window and terminate GLFW
	glfw.destroyWindow(window);
	glfw.terminate();

	process.exit(0);
}

animate();