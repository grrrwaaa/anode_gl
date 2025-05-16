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

let displays_path = "displays.json"

let displays = []

function load() {
    if (fs.existsSync(displays_path)) {
        try {
            displays = JSON.parse(fs.readFileSync(displays_path, "utf-8"))
        } catch(e) {
            console.error(e)
        }
    } else {
        console.error(`file ${displays_path} not found`)
    }

    console.log(displays)
}
function save() {
    fs.writeFileSync(displays_path, JSON.stringify(displays, null, "\t"))
}
load()

let monitors = glfw.getMonitors()
for (let i in monitors) {
    let monitor = monitors[i]
    let mode = glfw.getVideoMode(monitor)

    let display = Object.assign({
        // defaults:
        title: `display${i}`,
        use: true,
        resolution: [720, 480],
        desktop: {
            pos: [0, 0]
        },
        "crop": {
			"left": 0,
			"right": 0,
			"bottom": 0,
			"top": 0
		},
		"blend": {
			"left": 0,
			"right": 0,
			"bottom": 0,
			"top": 0
		},
        grid: {
            scale: [100, 1000], // pixels per grid line
            origin: [mode.width/2, mode.height/2], // pixel position
        }
    }, displays[i])
    
    // always overwrite:
    display.monitor = i
    display.resolution = [mode.width, mode.height]
    display.aspect = [mode.width / mode.height]
    display.hz = mode.refreshRate

    displays[i] = display
}
save()

function makeWindow(i, display) {
    let win = new Window({
        display,
        title: display.title,
        monitor: display.monitor,
        width: display.resolution[0],
        height: display.resolution[1],
        decorated: display.use,
        pos: [0, 0],

        use(bool) {
            if (bool) {
                this.width = this.display.resolution[0]
                this.height = this.display.resolution[1]
                glfw.setWindowAttrib(this.window, glfw.DECORATED, 0)
            } else {
                this.width = this.display.resolution[0]/4
                this.height = this.display.resolution[1]/4
                glfw.setWindowAttrib(this.window, glfw.DECORATED, 1)
            }
            glfw.setWindowSize(this.window, this.width, this.height)
        },

        draw: function() {
            let { t, dt, dim, frame, display } = this
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
            .uniform("crop", display.crop.left, display.crop.bottom, display.crop.right, display.crop.top)
            .uniform("blend", display.blend.left, display.blend.bottom, display.blend.right, display.blend.top)
            .uniform("resolution", display.resolution)
            .uniform("grid_scale", display.grid.scale)
            .uniform("grid_origin", display.grid.origin)
            this.quad_vao.bind().draw()

            if (1) {
                gl.disable(gl.DEPTH_TEST)
                gl.enable(gl.BLEND)
                gl.blendFunc(gl.SRC_ALPHA, gl.ONE);
                let textmatrix = mat4.create()
                let s = 0.05
                mat4.translate(textmatrix, textmatrix, [s - 1, 1 - s*2, 0])
                mat4.scale(textmatrix, textmatrix, [s, s * aspect, s])
                this.text.clear()
                .write(`title: ${display.title}`)
                .write(`${display.resolution[0]}x${display.resolution[1]}, ${display.hz}Hz, fps ${Math.round(1 / dt)}`)
                .write(`Esc or Q to quit, F for fullscreen`)
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
            let {display} = this
            let shift = mod % 2
            let ctrl = Math.floor(mod / 2) % 2

            if (down) {
                switch(key) {
                    case 70: { // F

                        display.use = !display.use
                        this.use(display.use)
                    } break;
                    case 81: 
                    case 256: { // Q, Esc
                        process.exit() // quit
                    } break;
                    default: console.log("key", key, shift, ctrl)
                }
            }
        }
    })

    display.desktop.pos = glfw.getWindowPos(win.window)
    win.use(display.use)

    windows[i] = win
}

let windows = []
for (let i = 0; i<monitors.length; i++) {
    let display = displays[i]

    if (!display.use) continue

    makeWindow(i, display)
}
save()


// now monitor it for changes:
let mtime = fs.statSync(displays_path).mtimeMs
let watcher = fs.watchFile(displays_path, {
    persistent: true,
    interval: 100,
}, (curr, prev) => {
    
    load()

    for (let i = 0; i<displays.length; i++) {
        let display = displays[i]
        let win = windows[i]

        if (!win && display.use) makeWindow(i, display)
        if (!win) continue
        win.use(display.use)

        win.display = display
    }
})

Window.syncfps = 60
Window.animate()