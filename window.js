/*
	It would be nice to have a general abstraction over the common window needs, e.g.
	- multiwindow
	- fullscreen
	- UI (mouse, key)

	...as well as grouping the usual setup stuff

	There should be a shared window manager, 
	- init some things only on the first window
	- iterate windows in the animate()
*/


// IMPORTANT: must create window first, before using any gl calls

// let win1 = new Window({
//     // width, height, monitor, fullscreen, title, sync
//     init() {
//         console.log("init")
//     },
// 	draw() {
//         // this.t, this.dt, this.fps, this.frame, this.dim
// 		let f = 0
// 		gl.clearColor(f, 1-f, 0, 1);
// 		gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
// 	}
//     // onkey(key, scan, down, mod),
//     // onpointermove(2*px/dim[0] - 1, -2*py/dim[1] + 1),
//     // onpointerbutton(button, action, mods),
//     // onpointerscroll(dy, dx),
//     // 
// })

// let win2 = new Window({
// 	draw() {
// 		let f = 1
// 		gl.clearColor(f, 1-f, 0, 1);
// 		gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
// 	}
// })

// Window.animate()

const gl = require('./gles3.js') 
const glutils = require('./glutils.js')
const glfw = require('./glfw3.js')
const { ok } = glutils;

// once only
if (!glfw.init()) {
	console.log("Failed to initialize GLFW");
	process.exit(-1);
}

let version = glfw.getVersion();
console.log('glfw ' + version.major + '.' + version.minor + '.' + version.rev);
console.log('glfw version-string: ' + glfw.getVersionString());


class Window {

	gl = gl;

	monitor = 0;
	title = "";
	fullscreen = false;
	decorated = true;

	pos = [40, 40];

	// callbacks:
	init = null;
	draw = null;
	onkey = null;
	onpointermove = null;
	onpointerbutton = null;
	onpointerscroll = null;

	// internal:
	window = null;
	mode = null;

	t = glfw.getTime();
	fps = 60;
	dt = 1/60;
	frame = 0;

	pointer = {
		pos: [0.5, 0.5],
		vel: [0, 0],
		// up(0) or down(1) for three mouse buttons:
		buttons: [0, 0, 0],
		scroll: [0, 0],
	};

	static syncfps = 0;
	static all = new Set()

	constructor(options = {}) {
		Object.assign(this, options)

		this.title = this.title || `anode${Window.all.size}`

		glfw.defaultWindowHints();
		glfw.windowHint(glfw.CONTEXT_VERSION_MAJOR, options.CONTEXT_VERSION_MAJOR || 3);
		glfw.windowHint(glfw.CONTEXT_VERSION_MINOR, options.CONTEXT_VERSION_MINOR || 3);
		glfw.windowHint(glfw.OPENGL_FORWARD_COMPAT, 1);
		glfw.windowHint(glfw.OPENGL_PROFILE, glfw.OPENGL_CORE_PROFILE);
		glfw.windowHint(glfw.SAMPLES, 4);

		let monitors = glfw.getMonitors()
		this.monitor = typeof(this.monitor == "number") ? monitors[this.monitor % monitors.length] : this.monitor;
		this.mode = glfw.getVideoMode(this.monitor)
		this.fps = this.mode.refreshRate

		if (this.fullscreen) {
			glfw.windowHint(glfw.DECORATED, 0);
		} else {
			glfw.windowHint(glfw.DECORATED, this.decorated);
		}

		// for context sharing:
		const [first_window] = Window.all

		this.window = glfw.createWindow(this.width || this.mode.width/2, this.height || this.mode.height/2, this.title, null, first_window ? first_window.window : null);
		if (!this.window) {
			console.log("Failed to open GLFW window");
			glfw.terminate();
			process.exit(-1);
		}

		this.setFullscreen(this.fullscreen)

		// Enable vertical sync (on cards that support it)
		// NOTE: per issue https://github.com/glfw/glfw/issues/1267 this should happen *before* makeContextCurrent
		// but I also seem to need to do it *after* as well
		glfw.swapInterval(!!this.sync)
		glfw.makeContextCurrent(this.window)  
		glfw.swapInterval(!!this.sync)
		if (options.multisample) gl.enable(gl.MULTISAMPLE);

		console.log(gl.glewInit());
		//can only be called after window creation!
		console.log('GL ' + glfw.getWindowAttrib(this.window, glfw.CONTEXT_VERSION_MAJOR) + '.' + glfw.getWindowAttrib(this.window, glfw.CONTEXT_VERSION_MINOR) + '.' + glfw.getWindowAttrib(this.window, glfw.CONTEXT_REVISION) + " Core Profile?: " + (glfw.getWindowAttrib(this.window, glfw.OPENGL_PROFILE)==glfw.OPENGL_CORE_PROFILE));

		// opportunity to set up GL items now the context is valid:
		if (this.init) this.init()

		glfw.setKeyCallback(this.window, (win, key, scan, down, mod) => {
			if (this.onkey) this.onkey(key, scan, down, mod);
		})

		glfw.setCursorPosCallback(this.window, (window, px, py) => {
			let dim = glfw.getWindowSize(window)
			let sx = px/dim[0]
			let sy = py/dim[1]
			this.pointer.vel[0] = sx - this.pointer.pos[0]
			this.pointer.vel[1] = sy - this.pointer.pos[1]
			this.pointer.pos[0] = sx
			this.pointer.pos[1] = sy

			if (this.onpointermove) this.onpointermove(2*px/dim[0] - 1, -2*py/dim[1] + 1);
		})
		glfw.setMouseButtonCallback(this.window, (window, button, action, mods) => {
			// button 0: left, 1: right, 2: middle
			// action 0: up, 1: down
			// mods is a bitmask for shift, ctrl, alt, win/mac etc.
			this.pointer.buttons[button] = action

			if (this.onpointerbutton) this.onpointerbutton(button, action, mods)
		});
		glfw.setScrollCallback(this.window, (window, dx, dy) => {
			this.pointer.scroll = [dx, dy]
			if (this.onpointerscroll) this.onpointerscroll(dy, dx);
		})
		
		Window.all.add(this)
	}

	dispose() {
		Window.all.remove(this)
	}

	toggleFullscreen() {
		this.setFullscreen(!this.fullscreen)
	}

	setFullscreen(bool) {
		let pos = glfw.getMonitorPos(this.monitor)
		this.mode = glfw.getVideoMode(this.monitor)
		if (bool) {
			// go fullscreen
			console.log("going to fullscreen at", this.mode.width, this.mode.height)
			glfw.setWindowAttrib(this.window, glfw.DECORATED, 0)
			// enable this if you want the window to always be on top (no alt-tabbing)
			glfw.setWindowAttrib(this.window, glfw.FLOATING , 1);
			glfw.setWindowSize(this.window, this.mode.width, this.mode.height)
			glfw.setWindowPos(this.window, pos[0], pos[1])
			// to hide the mouse:
			glfw.setInputMode(this.window, glfw.CURSOR, glfw.CURSOR_HIDDEN);

		} else {
			// exit fullscreen
			glfw.setWindowAttrib(this.window, glfw.DECORATED, this.decorated)
			// enable this if you want the window to always be on top (no alt-tabbing)
			glfw.setWindowAttrib(this.window, glfw.FLOATING , 0);
			glfw.setWindowSize(this.window, this.width || this.mode.width/2, this.height || this.mode.height/2)
			glfw.setWindowPos(this.window, pos[0]+this.pos[0], pos[1]+this.pos[1])
			// to show the mouse:
			glfw.setInputMode(this.window, glfw.CURSOR, glfw.CURSOR_NORMAL);
		}
		this.fullscreen = bool;
	}

	render(gl) {
		let t1 = glfw.getTime();
		this.dt = t1-this.t;
		this.fps += 0.1*((1/this.dt)-this.fps);
		this.t = t1;
		
		glfw.makeContextCurrent(this.window);

		// insert submit() and draw() here
		if (this.draw) this.draw(gl)

		// Swap buffers
		glfw.swapBuffers(this.window);

		this.frame++;
		
		this.pointer.scroll = [0, 0]
	}

	get dim() {
		return glfw.getFramebufferSize(this.window)
	}

	set dim(v) {
		[this.width, this.height] = v
		if (this.window && !this.fullscreen)
			glfw.setWindowSize(this.window, this.width, this.height)
		return this
	}

	static animate() {
		// get time at start:
		let t0 = glfw.getTime();
		glfw.pollEvents();

		for (let o of Window.all) {
			if (glfw.windowShouldClose(o.window) || glfw.getKey(o.window, glfw.KEY_ESCAPE)) {
				return;
			}
		}
		for (let o of Window.all) {
			o.render(gl);
		}

		// at end, so that any errors prevent repeat:
		if (Window.syncfps) {
			let sleep = Math.max(0, 1/Window.syncfps - (glfw.getTime() - t0));
			if (sleep > 0) {
				setTimeout(Window.animate, sleep*1000)
			} else {
				setImmediate(Window.animate)
			}
		} else {
			setImmediate(Window.animate)
		}
	}
}


module.exports = Window;