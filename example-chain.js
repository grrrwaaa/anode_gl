
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

const NUM_INSTANCES = 1e2;
const NUM_SEGMENTS = 8

let window = new Window({

})
const shaderman = new Shaderman(gl)
let cube_vao = glutils.createVao(gl, glutils.makeCube({
    min: [-1, -1, 0], max: 1
}))

let cubes = glutils.createInstances(gl, [
	{ name:"i_pos", 	components:4, 	location:5 },
	{ name:"i_quat", 	components:4, 	location:6 },
	{ name:"i_vel", 	components:4, 	location:7 },
	{ name:"i_force", 	components:4, 	location:8 },
], NUM_INSTANCES)

// the .instances provides a convenient interface to the underlying arraybuffer
cubes.instances.forEach(obj => {
	// each field is exposed as a corresponding typedarray view
	// making it easy to use other libraries such as gl-matrix
	// this is all writing into one contiguous block of binary memory for all instances (fast)
	vec4.set(obj.i_pos, 
		(Math.random()-0.5),
		(Math.random()-0.5),
		(Math.random()-0.5),
		1
	);
	quat.random(obj.i_quat);
    
    vec4.set(obj.i_vel, 0, 0, 0, 0);
    vec4.set(obj.i_force, 0, 0, 0, 0);
})
cubes.bind().submit().unbind();

//console.log(cubes)

// attach these instances to an existing VAO:
cubes.attachTo(cube_vao);


let lookat = [0, 0, 0]
let eye = [0, 0, 1]

window.draw = function() {
	let { t, dt, dim } = this;

    let avg = [0, 0, 0]
    let headcount = 0

    for (let i=0; i<cubes.count; i++) {
        let obj = cubes.instances[i]

        let pid = i-1;

        if (i % NUM_SEGMENTS == 0) {
            // a "head"

            // get a new random direction
			let q = [0, 0, 0, 1]

            let a = t + i

            let axis = [Math.cos(a), Math.sin(a*1.3), Math.sin(a*0.7)]
            let angle = 6 * Math.sin(a)

            quat_fromAxisAngle(q, axis, angle)
           // console.log(q)

			//quat.random(q);
            // slerp toward it
			quat.slerp(obj.i_quat, obj.i_quat, q, 0.08);

            // get a random velocity
			let vel = [0, 0, 0.1*Math.random()]
			glutils.quat_rotate(vel, obj.i_quat, vel)
            // apply it
			vec3.add(obj.i_pos, obj.i_pos, vel)

            vec3.add(avg, avg, obj.i_pos)
            headcount++

		} else {
            // a "tail"

            // turn to match parent
			let obj0 = cubes.instances[i-1]
			let quat1 = obj0.i_quat
            quat.slerp(obj.i_quat, obj.i_quat, quat1, 0.1)

            // position me so I join to parent:
			let dir = [0, 0, 0]
			quat_rotate(dir, obj.i_quat, [0, 0, 1])
			vec3.sub(obj.i_pos, obj0.i_pos, dir)

		}



        // let obj = cubes.instances[i];
        // let pos = obj.i_pos
        // let force = obj.i_force

        // let restlen = 1
        // let springk = 0.1

        // let pid = i-1;
        // if (pid >= 0) {
        //     let parent = cubes.instances[pid];
        //     let ppos = parent.i_pos

        //     let uf = vec3.create()
        //     quat_rotate(uf, obj.i_quat, vec3.fromValues(0, 0, 1))
        //     // our current end point
        //     let end = vec3.create()
        //     vec3.add(end, obj.i_pos, uf);

        //     // difference:
        //     let rel = vec3.create()
        //     vec3.sub(rel, ppos, end)
        //     // stretch:
        //     let d = vec3.length(rel) - restlen

        //     if (Math.abs(d) > 0.001) {
        //         // direction
        //         let dir = vec3.create()
        //         vec3.normalize(dir, rel)

        //         // force
        //         let F = vec3.create()
        //         vec3.scale(F, dir, springk*d)

        //         // add spring to our force
        //         vec3.add(force, force, F);
        //         // subtract parent's force from ours
        //         vec3.sub(force, force, parent.i_force)
        //         // subtract spring from parent's force
        //         vec3.sub(parent.i_force, parent.i_force, F)

        //         // vel += F/m
        //         // pos += vel


        //         vec3.add(pos, pos, force)

        //         // zero our force
        //         vec3.scale(force, force, 0)

                
                
        //         let uf = vec3.create()
        //         quat_rotate(uf, obj.i_quat, vec3.fromValues(0, 0, -1))
        //         // let end = vec3.create()
        //         // vec3.add(end, obj.i_pos, uz);

        //         let target = vec3.create()
        //         //vec3.add(target, parent.i_pos, uf);


        //         //vec3.lerp(obj.i_pos, obj.i_pos, target, 0.05);
        //     }
        // }


    }

    vec3.scale(avg, avg, 1/headcount)

	// submit to GPU:
	cubes.bind().submit().unbind()

	// // bind compute shader
	// shaderman.computes.icube.begin()
	// .uniform("t", t)
	// .uniform("dt", dt)

	// // use VAO buffer for a compute shader:
	// gl.bindBuffer(gl.SHADER_STORAGE_BUFFER, cubes.id);
	// // gl.bufferData(gl.SHADER_STORAGE_BUFFER, vertices, gl.STATIC_DRAW); // if you wanted to CPU-submit data here
	// gl.bindBufferBase(gl.SHADER_STORAGE_BUFFER, 0, cubes.id);

	// // run one shader per vertex:
	// // perhaps would be better to run as NxN though
	// gl.dispatchCompute(NUM_INSTANCES, 1, 1);
	// // make sure buffer writing has finished before we use it
	// gl.memoryBarrier(gl.SHADER_STORAGE_BARRIER_BIT);


	// Compute the matrix
	let modelmatrix = mat4.create();
	let viewmatrix = mat4.create();
	let projmatrix = mat4.create();
	// let a = t/5
	// let r = 5
	// let eye = [r*Math.cos(a), 0, r*Math.sin(a)]

    vec3.lerp(lookat, lookat, avg, 0.2)


    let v = vec3.sub([0, 0, 0], eye, lookat)
	vec3.normalize(v, v)
	vec3.scale(v, v, 10)
	vec3.add(v, v, lookat)

    vec3.lerp(eye, eye, v, 0.1)

	mat4.lookAt(viewmatrix, eye, lookat, [0, 1, 0]);
	mat4.perspective(projmatrix, Math.PI/2, dim[0]/dim[1], 0.01, 100);
	
	let modelmatrix_inverse = mat4.create();
	let viewmatrix_inverse = mat4.create();
	let projmatrix_inverse = mat4.create();
	mat4.invert(modelmatrix_inverse, modelmatrix)
	mat4.invert(viewmatrix_inverse, viewmatrix)
	mat4.invert(projmatrix_inverse, projmatrix)

	gl.viewport(0, 0, dim[0], dim[1]);
	gl.clearColor(0., 0., 0., 1);
	gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
	gl.enable(gl.DEPTH_TEST)

	// draw points

	// gl.enable(gl.BLEND);
	// gl.blendFunc(gl.SRC_ALPHA, gl.ONE);
	// gl.depthMask(false)

	shaderman.shaders.isegment.begin()
	//.uniform("u_modelmatrix", modelmatrix)
	.uniform("u_viewmatrix", viewmatrix)
	.uniform("u_projmatrix", projmatrix)
	.uniform("u_size", 0.05, 0.2, 1)
	cube_vao.bind().drawInstanced(cubes.count).unbind()

	gl.disable(gl.BLEND)
	gl.depthMask(true)

	if (Math.floor(t+dt) > Math.floor(t)) console.log("fps", 1/dt)
}

Window.syncfps = 60
Window.animate()