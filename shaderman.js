const path = require("path"),
	fs = require("fs"), 
	events = require('events'), 
	util = require('util')
const glutils = require("./glutils.js")


class Shaderman extends events.EventEmitter {
	// shaders contains a list of shaderprograms
	// indexed by the fragname
	shaders = {};
	// a similar list, but for compute shaders:
	computes = {};
	// the folder to watch
	folder = "shaders";
	// keeps track of the list of filepaths of shaders being watched
	modified = {};
	// given a filepath, which shader names need to be reloaded?
	dependencies = {}

	constructor(gl, folder = "shaders") {
		super();
		this.folder = folder
		this.watch(gl)

		// create a proxy around this.shaders
		// so that if we try to use "shaderman.shaders.foo" 
		// it will try to load a shader "foo.vert.glsl"+"foo.frag.glsl" from the shaders folder
		this.shaders = new Proxy({}, {
			get: (target, key, receiver) => {
				// if shader already exists, return it (bypassing proxy):
				if (target.hasOwnProperty(key)) return Reflect.get(target, key, receiver);

				// else try to load the shader with name "key"
				return this.create(gl, key, key)
			}
		})

		this.computes = new Proxy({}, {
			get: (target, key, receiver) => {
				// if shader already exists, return it (bypassing proxy):
				if (target.hasOwnProperty(key)) return Reflect.get(target, key, receiver);

				// else try to load the shader with name "key"
				return this.createCompute(gl, key)
			}
		})
	}

	// create(gl, "test") will load "test.vert.glsl" and "test.frag.glsl"
	// create(gl, "standard", "test") will load "standard.vert.glsl" and "test.frag.glsl"
	// in both cases the shader will be available under this.shaders["test"]
	// shaders can use #include "another.glsl" inside them for common code
	create(gl, vertname, fragname) {
		fragname = fragname || vertname
		let args = [vertname, fragname]
		let name = fragname
		let vertpath = path.join(this.folder, `${vertname}.vert.glsl`)
		let fragpath = path.join(this.folder, `${fragname}.frag.glsl`)
		let vertcode = fs.readFileSync(vertpath, "utf-8")
		let fragcode = fs.readFileSync(fragpath, "utf-8")

		this.addDependency(vertpath, args)
		this.addDependency(fragpath, args)

		const preprocessor = (code, folder) => {
			// TODO: handle #ifndefs
			code = code.replace(/#include\s+["']([^"']+)["']/g, (match, filepath) => {
				// make path absolute:
				filepath = path.join(folder, filepath)
				// did we already add this dependency?
				//console.log(filepath, this.hasDependency(filepath))
				//if (!this.hasDependency(filepath)) {
					// extract subpath:
					let subpath = path.dirname(filepath)
					if (fs.existsSync(filepath)) {
						this.addDependency(filepath, args)
						let subcode = preprocessor(fs.readFileSync(filepath, "utf-8"), subpath)
						return "\n"+subcode+"\n"
					}
				//}
				return "// filepath \n"
			});
			return code
		}

		vertcode = preprocessor(vertcode, this.folder)
		fragcode = preprocessor(fragcode, this.folder)

		let program = glutils.makeProgram(gl, vertcode, fragcode, name)
		this.shaders[name] = program
		return program
	}

	// create(gl, "test") will load "test.glsl" 
	// the shader will be available under this.computes["test"]
	createCompute(gl, computename) {
		let args = [computename]
		let name = computename
		let computepath = path.join(this.folder, `${computename}.compute.glsl`)
		let computecode = fs.readFileSync(computepath, "utf-8")

		this.addDependency(computepath, args)

		const preprocessor = (code, folder) => {
			// TODO: handle #ifndefs
			code = code.replace(/#include\s+["']([^"']+)["']/g, (match, filepath) => {
				// make path absolute:
				filepath = path.join(folder, filepath)
				// did we already add this dependency?
				//console.log(filepath, this.hasDependency(filepath))
				//if (!this.hasDependency(filepath)) {
					// extract subpath:
					let subpath = path.dirname(filepath)
					if (fs.existsSync(filepath)) {
						this.addDependency(filepath, args)
						let subcode = preprocessor(fs.readFileSync(filepath, "utf-8"), subpath)
						return "\n"+subcode+"\n"
					}
				//}
				return "// filepath \n"
			});
			return code
		}

		computecode = preprocessor(computecode, this.folder)

		let program = glutils.makeComputeProgram(gl, computecode, name)
		this.computes[name] = program
		return program
	}

	reload(gl, name) {
		if (this.shaders[name]) {
			this.shaders[name].dispose()
			return this.create(gl, name)
		} else if (this.computes[name]) {
			this.computes[name].dispose()
			return this.createCompute(gl, name)
		}
	}

	addDependency(filepath, args) {
		// store modtime:
		this.modified[filepath] = fs.statSync(filepath).mtimeMs
		// update dependencies:
		let deps = this.dependencies[filepath] || {}
		deps[args] = true
		this.dependencies[filepath] = deps
	}

	hasDependency(filepath) {
		return !!this.dependencies[filepath]
	}

	watch(gl) {
		this.watcher = fs.watch(this.folder, (eventType, filename) => {
			const filepath = path.join(this.folder, filename); 
			const mtime = fs.statSync(filepath).mtimeMs
			if (!this.modified[filepath]) {
				// not a watched file
				return
			};
			if (this.modified[filepath] != mtime) {
				this.modified[filepath] = mtime
				for (let args in this.dependencies[filepath]) {
					if (args.indexOf(",") >= 0) {
						let [vertname, fragname] = args.split(",")
						console.log("reload shader", filename, fragname)
						this.shaders[fragname].dispose()
						this.create(gl, vertname, fragname)

						this.emit('reload', vertname, fragname);
					} else {
						let computename = args
						console.log("reload shader", filename, computename)
						this.computes[computename].dispose()
						this.createCompute(gl, computename)

						this.emit('reload', computename);
					}
				}
			}
		})
	}

	dispose() {
		if (this.watcher) {
			this.watcher.close()
			this.watcher = null

			for (let k of Object.keys(this.shaders)) {
				this.shaders[k].dispose()
				this.shaders[k] = null
			}
		}
	}
}

module.exports = Shaderman