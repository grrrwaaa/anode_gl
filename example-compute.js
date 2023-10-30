module.paths.push(__dirname)
const gl = require('gles3.js'),
	glfw = require('glfw3.js'),
    Window = require("window.js"),
	glutils = require('glutils.js'),
	Shaderman = require('shaderman.js')

let window = new Window({})
const shaderman = new Shaderman(gl)
const quad_vao = glutils.createVao(gl, glutils.makeQuad())

/*
	Compute shaders
	- are not part of the graphics pipeline
	- define the data space they operate on
	- can pull data from and write to textures, image loads, shader storage blocks
	- whereas vertex shaders run per vertex, fragment shaders per fragment, compute shaders run per (abstract) "work item"

	Work groups
	- smallest amount of compute operations that can be executed from host application
	- they are 3D, though any dimension can be set to 1 for 2D and 1D operation
	- work groups may operate in any order
	- the invocations per work group is the "local size"
	- data can be shared within a work group but not between work groups
*/
let max_compute_work_group_count = []
let max_compute_work_group_size = []
let max_compute_work_group_invocations = gl.getIntegerv(gl.MAX_COMPUTE_WORK_GROUP_INVOCATIONS);
for (let idx = 0; idx < 3; idx++) {
	max_compute_work_group_count[idx] = gl.getIntegeri_v(gl.MAX_COMPUTE_WORK_GROUP_COUNT, idx);
	max_compute_work_group_size[idx] = gl.getIntegeri_v(gl.MAX_COMPUTE_WORK_GROUP_SIZE, idx);
}	
console.log("maximum number of work groups in each dimension", max_compute_work_group_count)
console.log("maximum size of work groups in each dimension", max_compute_work_group_size)
console.log("Number of invocations in a single local work group that may be dispatched to a compute shader ", max_compute_work_group_invocations)

let compute_name = "test"
let compute_source = `
#version 430 core

// local size of work group
// using local size=1 so we can operate per-pixel.
layout (local_size_x = 1, local_size_y = 1, local_size_z = 1) in;

// a 2D image (a single layer of a texture) 
// compute shaders use pixel coordinates, not normalized coordinates
// the internal format must match the texture
layout(rgba32f, binding = 0) uniform image2D imgOutput;

// variables
uniform float t; 

/*
some built-in variables:
uvec3	gl_NumWorkGroups	number of work groups that have been dispatched
uvec3	gl_WorkGroupSize	size of the work group (local size) operated on (what we defined above)
uvec3	gl_WorkGroupID		index of the work group currently being operated on
uvec3	gl_LocalInvocationID	index of the current work item in the work group
uint	gl_LocalInvocationIndex	1d index representation of gl_LocalInvocationID
uvec3	gl_GlobalInvocationID	global index of the current work item
*/

void main() {
    vec4 value = vec4(0.0, 0.0, 0.0, 1.0);

	// since our local size is 1,1 the global ID is the texel coordinate:
    ivec2 texelCoord = ivec2(gl_GlobalInvocationID.xy);
	
	// normalized to the image size, which equals the number of workgroups:
    value.x = mod(t + float(texelCoord.x)/(gl_NumWorkGroups.x), 1.);
    value.y = float(texelCoord.y)/(gl_NumWorkGroups.y);
	
    imageStore(imgOutput, texelCoord, value);
}
`
let program = glutils.makeComputeProgram(gl, compute_source, compute_name)
//console.log(program)

let tex = glutils.createTexture(gl, {
	width: 512, height: 512, 
	float: true,
})

window.draw = function() {
	let { t, dt, dim } = this;

	// void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
	// access can be GL_READ_ONLY, GL_WRITE_ONLY, or GL_READ_WRITE
	gl.bindImageTexture(0, tex.id, 0, 0, 0, gl.READ_WRITE, tex.internalFormat);
	// bind shader
	program.begin()
	.uniform("t", t)
	// this is how to run the shader, with X, Y, Z work groups
	// here we run 1 work group per pixel (and z=1 because the image is 2D)
	// they happen in an unspecified order
	gl.dispatchCompute(tex.width, tex.height, 1);
	// make sure writing to image has finished before we use it
	// this will block the CPU; maybe want to push this call back to just before the texture is going to be used
	// see https://registry.khronos.org/OpenGL-Refpages/gl4/html/glMemoryBarrier.xhtml
	// lazy option is gl.ALL_BARRIER_BITS
	gl.memoryBarrier(gl.SHADER_IMAGE_ACCESS_BARRIER_BIT);

	gl.viewport(0, 0, dim[0], dim[1]);
	gl.clearColor(0., 0., 0., 1);
	gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
	gl.enable(gl.DEPTH_TEST)

	shaderman.shaders.show.begin()
	tex.bind()
	quad_vao.bind().draw()

}

Window.animate()