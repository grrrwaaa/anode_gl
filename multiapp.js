const { gl, glfw, glutils, Window, Shaderman } = require("./index.js")
const { vec2, vec3, vec4, quat, mat2, mat2d, mat3, mat4} = require("gl-matrix")

// anything here is global, will be visible to all apps:
// (I'm surprised that an FBO can be shared, but it seems to work)
let fbo
let shaderman

class App {

    window = null;

    constructor(options) {
        let window = new Window(options)

        // have to do it with `bind` to ensure `this` refers to the app. 
        window.draw = this.draw.bind(this)
        
        // i.e. are we the first window to be created? If so, create global resources:
        if (!fbo) {
            fbo = glutils.makeGbuffer(gl, 640, 480, [
                { float: false, mipmap: false, wrap: gl.CLAMP_TO_EDGE }, 
            ])

            shaderman = new Shaderman(gl)
        }

        // VAOs can't be shared between windows, so we have to create one per window:
        let quad_vao = glutils.createVao(gl, glutils.makeQuad3D())

        Object.assign(options, { 
            window, quad_vao
        })
        Object.assign(this, options)
    }

    draw(gl) {
        let { window } = this
        let { t, dt, width, height } = window

        if (this.title == "window0") {
            fbo.begin()
            {
                let { width, height } = fbo
                gl.viewport(0, 0, width, height);
                gl.clearColor(0, 0, 0, 0)
                gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
                gl.enable(gl.DEPTH_TEST)

                // Compute the matrix
                let viewmatrix = mat4.create();
                let projmatrix = mat4.create();
                let modelmatrix = mat4.create();
                mat4.lookAt(viewmatrix, [0, 0, 3], [0, 0, 0], [0, 1, 0]);
                mat4.perspective(projmatrix, Math.PI/2, width/height, 0.01, 30);

                //mat4.identity(modelmatrix);
                let axis = vec3.fromValues(Math.sin(t), 1., 0.);
                vec3.normalize(axis, axis);
                mat4.rotate(modelmatrix, modelmatrix, t, axis)

                shaderman.shaders.normalgeom.begin()
                .uniform("u_modelmatrix", modelmatrix)
                .uniform("u_viewmatrix", viewmatrix)
                .uniform("u_projmatrix", projmatrix)
                this.quad_vao.bind().draw()
            }
            fbo.end()
        }

        gl.viewport(0, 0, width, height);
        gl.clearColor(0, 1, 0, 0)
        gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
        gl.enable(gl.DEPTH_TEST)

        fbo.bind()
        shaderman.shaders.show.begin()
        this.quad_vao.bind().draw()

        
        if (Math.floor(t+dt) > Math.floor(t)) {
            console.log(`fps ${1/dt}`)
        }
    }
}

module.exports = App