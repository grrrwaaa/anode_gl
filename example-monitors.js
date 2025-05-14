const assert = require("assert"),
    fs = require("fs"),
    os = require("os"),
    path = require("path")
const { Worker } = require('worker_threads')
const child_process = require('child_process');
const { vec2, vec3, vec4, quat, mat2, mat2d, mat3, mat4 } = require("gl-matrix")
//const grandiose = require('grandiose');
const { gl, glfw, Window, glutils, Shaderman, Prng, Config } = require("./index.js")
const Text = require("./text.js");
const { text } = require("stream/consumers");

let monitors = glfw.getMonitors()
for (let [i, monitor] of Object.entries(monitors)) {
    let mode = glfw.getVideoMode(monitor)


    let title = `monitor ${i}`

    let win = new Window({
        title,
        monitor: i,
        width: mode.width,
        height: mode.height,
        decorated: 0,
        pos: [0, 0],

        draw: function() {
            let { t, dt, dim, frame } = this
            let [width, height] = dim
            let aspect = width/height

            if (!this.shaderman) {
                this.shaderman = new Shaderman(gl)
                this.quad_vao = glutils.createVao(gl, glutils.makeQuad())
                this.text = new Text(gl)
            }


            gl.viewport(0, 0, dim[0], dim[1]);
            gl.enable(gl.DEPTH_TEST)
            gl.clearColor(0, 0, 0, 1);
            gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

            this.shaderman.shaders.monitor.begin()
            this.quad_vao.bind().draw()

            if (1) {
                gl.disable(gl.DEPTH_TEST)
                gl.enable(gl.BLEND)
                gl.blendFunc(gl.SRC_ALPHA, gl.ONE);
                let textmatrix = mat4.create()
                let s = 0.1
                mat4.translate(textmatrix, textmatrix, [s - 1, 1 - s*2, 0])
                mat4.scale(textmatrix, textmatrix, [s, s * aspect, s])
                this.text.clear()
                .write(this.title)
                .write(`${mode.width}x${mode.height}, ${mode.refreshRate}Hz`)
                .write(`fps ${Math.round(1 / dt)} frame ${frame}`)
                .write(`Esc or Q to quit`)
                .submit()
                .draw({
                    modelmatrix: textmatrix
                })
                mat4.identity(textmatrix)
                mat4.translate(textmatrix, textmatrix, [-0.5, -0.5, 0])
                mat4.rotateZ(textmatrix, textmatrix, Math.PI)
                mat4.translate(textmatrix, textmatrix, [-0.5, -0.5, 0])
                mat4.translate(textmatrix, textmatrix, [s - 1, 1 - s*2, 0])
                mat4.scale(textmatrix, textmatrix, [s, s * aspect, s])
                this.text.draw({
                    modelmatrix: textmatrix
                })
                gl.disable(gl.BLEND)
                gl.enable(gl.DEPTH_TEST)
            }
        },

        onkey: function(key, scan, down, mod) {
            let shift = mod % 2
            let ctrl = Math.floor(mod / 2) % 2

            if (down) {
                switch(key) {
                    case 81: 
                    case 256: { // Q, Esc
                        process.exit() // quit
                    } break;
                    default: console.log("key", key, shift, ctrl)
                }
            }
        }
    })

}

//Window.syncfps = 60
Window.animate()