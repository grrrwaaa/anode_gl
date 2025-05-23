const assert = require("assert")
const path = require("path")
const fs = require("fs")
//const {EOL} = require('os');
const { vec2, vec3, vec4, quat, mat2, mat2d, mat3, mat4} = require("gl-matrix")

function ok(gl, msg="gl not ok: ") {
	let err = gl.getError();
    if (err) console.error(msg+" "+err+" "+gl.getErrorString(err))
	//assert(!err, msg+" "+err+" "+gl.getErrorString(err));
}

// utility to get byte size of various GL types:
function byteSizeForGLType(gl, gltype) {
	switch (gltype) {
		case gl.BYTE:
		case gl.UNSIGNED_BYTE: return 1;
		case gl.SHORT:
		case gl.UNSIGNED_SHORT: 
		case gl.HALF_FLOAT: return 2;
		case gl.INT:
		case gl.UNSIGNED_INT: 
		case gl.FLOAT: return 4;
		default: console.error("unknown gl datatype in sizeForType()")
	}
}

// utility to help turn shader code into a shader object:
function createShader(gl, type, source, name) {
    let shader = gl.createShader(type);
    gl.shaderSource(shader, source);
    gl.compileShader(shader);
    let success = gl.getShaderParameter(shader, gl.COMPILE_STATUS);
    if (success) {
        return shader;
    }
    console.error("compile error in shader " + name);
    const log = gl.getShaderInfoLog(shader)
    const loglines = log.split(/\r\n|\n/);
    const sourcelines = source.split(/\r\n|\n/);
    loglines.forEach((line => {
        // parse out the line & column?
        //0(846) : warning C7022: unrecognized profile specifier "..."
        //0(846) : error C0502: syntax error at token "..."
        console.error(line)
        const matches = line.match(/\d+\((\d+)\)/)
        if (matches && matches.length > 1) {
            const sourceline = matches[1]-1
            const from = Math.max(0, sourceline-1)
            const to = Math.min(sourcelines.length-1, sourceline+1)
            for (i=from; i<=to; i++) console.error(i==sourceline?"-->":"   ", sourcelines[i])
        }
    }))
    gl.deleteShader(shader);
    return undefined;
}
  
// utility to turn shader objects into a GPU-loaded shader program
// uses the most common case a program of 1 vertex and 1 fragment shader:
function createProgram(gl, vertexShader, fragmentShader) {
    let program = gl.createProgram();
    gl.attachShader(program, vertexShader);
    gl.attachShader(program, fragmentShader);
    gl.linkProgram(program);
    let success = gl.getProgramParameter(program, gl.LINK_STATUS);
    if (success) {
        return program;
    }
    console.error("shader program error", gl.getProgramInfoLog(program));  
    gl.deleteProgram(program);
    return undefined;
}

function makeProgram(gl, vertexCode, fragmentCode, name="") {
	// create GLSL shaders, upload the GLSL source, compile the shaders
    let vertexShader = createShader(gl, gl.VERTEX_SHADER, vertexCode, name);
    let fragmentShader = createShader(gl, gl.FRAGMENT_SHADER, fragmentCode, name);
    // Link the two shaders into a program
    let program = createProgram(gl, vertexShader, fragmentShader);

    // can delete shaders now
    gl.deleteShader(vertexShader);
    gl.deleteShader(fragmentShader);
	
	let uniforms = {}
	uniformsFromCode(gl, program, vertexCode, uniforms)
	uniformsFromCode(gl, program, fragmentCode, uniforms)
	return {
		id: program,
		begin: function() { gl.useProgram(this.id); return this; },
		end: function() { gl.useProgram(0); return this; },
		// uniform: function(name, x, y, z, w) {
		// 	uniforms[name].set(x, y, z, w);
		// 	return this; 
		// },
        uniform: function(k, ...args) {
            let setter = uniforms[k]
            if (!setter) {
                console.error("uniform not found", k, name)
            } else {
                setter.set.apply(this, args);
            }
            return this;
        },

        uniformsFrom(src) {
            for (let k of Object.keys(this.uniforms)) {
                let v = src[k]
                if (v !== undefined) this.uniform(k, v)
            }
            return this;
        },

        setuniforms(dict) {
            for (let k in dict) {
                if (this.uniforms[k]) this.uniform(k, dict[k])
            }
            return this;
        },

        dispose() {
            gl.deleteProgram(this.id)
        },

        uniforms
	}
}

function createComputeProgram(gl, computeShader) {
    let program = gl.createProgram();
    gl.attachShader(program, computeShader);
    gl.linkProgram(program);
    let success = gl.getProgramParameter(program, gl.LINK_STATUS);
    if (success) {
        return program;
    }
    console.error("shader program error", gl.getProgramInfoLog(program));  
    gl.deleteProgram(program);
    return undefined;
}

function makeComputeProgram(gl, source, name="") {
	let shader = createShader(gl, gl.COMPUTE_SHADER, source, name)
	let program = createComputeProgram(gl, shader)
	// can delete shaders now
    gl.deleteShader(shader);

    let uniforms = {}
	uniformsFromCode(gl, program, source, uniforms)

	return {
		id: program,
		begin: function() { gl.useProgram(this.id); return this; },
		end: function() { gl.useProgram(0); return this; },
		dispose() {
            gl.deleteProgram(this.id)
        },
        uniform: function(name, x, y, z, w) {
			uniforms[name].set(x, y, z, w);
			return this; 
		},

		uniforms
	}
}

// combine above functions to create a program from GLSL code:
function makeProgramFromCode(gl, vertexCode, fragmentCode) {
    // create GLSL shaders, upload the GLSL source, compile the shaders
    let vertexShader = createShader(gl, gl.VERTEX_SHADER, vertexCode);
    let fragmentShader = createShader(gl, gl.FRAGMENT_SHADER, fragmentCode);
    // Link the two shaders into a program
    return createProgram(gl, vertexShader, fragmentShader);
}

function isTypedArray(a) { return ArrayBuffer.isView(a); }
function isArrayOrTypedArray(a) { return Array.isArray(a) || isTypedArray(a); }

function uniformsFromCode(gl, program, code, uniforms = {}) {
	const regex = /uniform\s+(\w+)\s+(\w+)/g;
	let match
	while (match = regex.exec(code)) {
		let type = match[1];
		let name = match[2];
        let location = gl.getUniformLocation(program, name);
        let setter;
        switch (type) {
            case "mat4": 
            case "mat3": 
            case "mat2": 
                setter = (m, transpose=false) => ArrayBuffer.isView(m) ? gl.uniformMatrix4fv(location, transpose, m) : gl.uniformMatrix4fv(location, transpose, new Float32Array(m));
            break;
            case "vec4": 
                setter = (x, y, z, w) => isArrayOrTypedArray(x) ? gl.uniform4f(location, x[0], x[1], x[2], x[3]) : gl.uniform4f(location, x, y, z, w); 
                break;
            case "vec3": 
                setter = (x, y, z) => isArrayOrTypedArray(x) ? gl.uniform3f(location, x[0], x[1], x[2]) : gl.uniform3f(location, x, y, z); 
                break;
            case "vec2": 
                setter = (x, y) => isArrayOrTypedArray(x) ? gl.uniform2f(location, x[0], x[1]) : gl.uniform2f(location, x, y); 
                break;
            case "float": 
                setter = (x) => isArrayOrTypedArray(x) ? gl.uniform1f(location, x[0]) : gl.uniform1f(location, x); 
                break;
            case "ivec4": 
            case "uvec4": 
            case "bvec4": 
                setter = (x, y, z, w) => isArrayOrTypedArray(x) ? gl.uniform4i(location, x[0], x[1], x[2], x[3]) : gl.uniform4i(location, x, y, z, w); 
                break;
            case "ivec3": 
            case "uvec4": 
            case "bvec4": 
                setter = (x, y, z) => isArrayOrTypedArray(x) ? gl.uniform3i(location, x[0], x[1], x[2]) : gl.uniform3i(location, x, y, z); 
                break;
            case "ivec2": 
            case "uvec4": 
            case "bvec4": 
                setter = (x, y) => isArrayOrTypedArray(x) ? gl.uniform2i(location, x[0], x[1]) : gl.uniform2i(location, x, y); 
                break;
            //case "bool":
            //case "int": 
            default:
                setter = (x) => isArrayOrTypedArray(x) ? gl.uniform1i(location, x[0]) : gl.uniform1i(location, x); 
                break;
        }
        uniforms[name] = { 
            set: setter,
            name: name,
            type: type,
            location: location,
        };
    };
    return uniforms;
}


// create a GPU buffer to hold some vertex data:
function makeBuffer(gl, vertices) {
    let buffer = gl.createBuffer();
    // Bind it to ARRAY_BUFFER (think of it as ARRAY_BUFFER = positionBuffer)
    gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(vertices), gl.STATIC_DRAW);
    gl.bindBuffer(gl.ARRAY_BUFFER, null); // done.
    return buffer;
}

function loadTexture(gl, url, flipY=false, premultiply=false) {

    let tex = {
        id: gl.createTexture(),
        data: null,
        width: 1,
        height: 1,
        channels: 4,
        format: gl.RGBA,
        dataType: gl.UNSIGNED_BYTE,

        bind(unit = 0) {
            gl.activeTexture(gl.TEXTURE0 + unit);
            //gl.enable(gl.TEXTURE_2D);
            gl.bindTexture(gl.TEXTURE_2D, this.id);
            return this;
        },
        unbind(unit = 0) {
            gl.activeTexture(gl.TEXTURE0 + unit);
            //gl.enable(gl.TEXTURE_2D);
            gl.bindTexture(gl.TEXTURE_2D, null);
            return this;
        },

        dispose() {
            gl.deleteTextures(this.id)
            return this;
        },
    };
    
    gl.bindTexture(gl.TEXTURE_2D, tex.id);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.CLAMP_TO_EDGE);
  
    // Because images have to be download over the internet
    // they might take a moment until they are ready.
    // Until then put a single pixel in the texture so we can
    // use it immediately. When the image has finished downloading
    // we'll update the texture with the contents of the image.
    gl.texImage2D(gl.TEXTURE_2D, 0, tex.format, tex.width, tex.height, 0, tex.format, tex.dataType, new Uint8Array([0, 0, 0, 255]));
  
    const image = new Image();
    image.onload = function() {
        gl.bindTexture(gl.TEXTURE_2D, tex.id);
        gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL, flipY);
        gl.pixelStorei(gl.UNPACK_PREMULTIPLY_ALPHA_WEBGL, premultiply);
        gl.texImage2D(gl.TEXTURE_2D, 0, tex.format, tex.format, tex.dataType, image);

        // WebGL1 has different requirements for power of 2 images
        // vs non power of 2 images so check if the image is a
        // power of 2 in both dimensions.
        if (utils.isPowerOf2(tex.width) && utils.isPowerOf2(tex.height)) {
            // Yes, it's a power of 2. Generate mips.
            gl.generateMipmap(gl.TEXTURE_2D);
        } else {
            // No, it's not a power of 2. Turn of mips and set
            // wrapping to clamp to edge
            gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE);
            gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.CLAMP_TO_EDGE);
            gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR);
        }
    };
    image.src = url;
  
    return tex;
}

function createTexture(gl, opt={}) {
    const isFloat = !!opt.float;//&& EXT_color_buffer_float;
    const channels = opt.channels || 4; // RGBA
    const width = opt.width || 16;
    const height = opt.height || 1;
    const multisample = opt.multisample || 0;
    const wrapx = opt.wrapx || opt.wrap || gl.CLAMP_TO_EDGE;
    const wrapy = opt.wrapy || opt.wrap || gl.CLAMP_TO_EDGE;
    
    let format = gl.RGBA;
    if (channels == 1) {
        format = gl.RED;
    } else if (channels == 2) {
        format = gl.LUMINANCE_ALPHA;
    } else if (channels == 3) {
        format = gl.RGB;
    }

    let internalFormat = format;
    let type = gl.UNSIGNED_BYTE;
    if (isFloat) {
        type = gl.FLOAT;
        if (channels == 1) {
            internalFormat = gl.R32F;
        } else if (channels == 2) {
            internalFormat = gl.RG32F;
        } else if (channels == 3) {
            internalFormat = gl.RGB32F;
        } else {	
            internalFormat = gl.RGBA32F;
        }
    }

    //console.log("texture", isFloat, channels, width, height)
    //console.log(format, gl.RGBA);
    //console.log(internalFormat, gl.RGBA32F);

    let tex = {
        id: gl.createTexture(),
        data: opt.data,
        isFloat,
        width,
        height,
        channels,
        format,
        type,
        multisample: !!opt.multisample,
        filter_min: opt.filter_min || opt.filter || gl.NEAREST,
        filter_mag: opt.filter_mag || opt.filter || gl.NEAREST,
        wrapx,
        wrapy,
        internalFormat,  // type of data we are supplying,
        
        // allocate local data
        allocate() {
            if (!this.data) {
                let elements = this.width * this.height * this.channels;
                if (this.isFloat) {
                    this.data = new Float32Array(elements);
                } else {
                    this.data = new Uint8Array(elements);
                }
            }
            return this;
        },
        
        // bind() first
        submit() {
            let mipLevel = 0;
            let border = 0;                 // must be 0
            if (this.multisample) {
                gl.texStorage2DMultisample(gl.TEXTURE_2D_MULTISAMPLE, this.multisample, this.internalFormat, this.width, this.height, false)
            } else {
                gl.texImage2D(gl.TEXTURE_2D, mipLevel, this.internalFormat, this.width, this.height, border, this.format, this.type, this.data);
                gl.generateMipmap(gl.TEXTURE_2D);
            }
            //assert(!gl.getError(), 'gl error in texture submit');
            return this;
        },
        
        bind(unit = 0) {
            gl.activeTexture(gl.TEXTURE0 + unit);
            //gl.enable(gl.TEXTURE_2D);
            gl.bindTexture(gl.TEXTURE_2D, this.id);
            return this;
        },
        unbind(unit = 0) {
            gl.activeTexture(gl.TEXTURE0 + unit);
            //gl.enable(gl.TEXTURE_2D);
            gl.bindTexture(gl.TEXTURE_2D, null);
            return this;
        },

        // TODO read / readInto methods for accessing underlying data
        read(pos) {
            let x = Math.floor(pos[0]);
            let y = Math.floor(pos[1]);
            let idx = (y*this.width + x) * this.channels; // TODO: assumes single-channel
            return this.data[idx];
        },

        dispose() {
            gl.deleteTextures(this.id)
            return this;
        },
    };

    tex.allocate().bind().submit();

    // unless we get `OES_texture_float_linear` we can not filter floating point
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, tex.wrapx);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, tex.wrapy);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, tex.filter_min);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, tex.filter_mag);
    
    return tex.unbind();
}

function img2tex(gl, filepath, options) {
    options = Object.assign({
        // use REPEAT for continuously texturing surfaces
        wrap: gl.CLAMP_TO_EDGE,
        // typically, LINEAR_MIPMAP_LINEAR if mipmap = true
        // LINEAR or NEAREST if not
        minfilter: gl.LINEAR_MIPMAP_LINEAR,
        magfilter: gl.LINEAR,
        // can also set specific options:
        // minfilter: gl.LINEAR_MIPMAP_LINEAR,
        // magfilter: gl.LINEAR_MIPMAP_LINEAR,
        mipmap: true,

        // TODO:
        // flipY: false,  // flip image in Y axis
        // premultiply: false,  // premultiply RGB by A
    }, options)

    let ext = path.extname(filepath).toLowerCase()
    let tex
    if (ext == ".png") {
        const pnglib = require("pngjs").PNG
        let img = pnglib.sync.read(fs.readFileSync(filepath))
        tex = createPixelTexture(gl, img.width, img.height)
        tex.data = img.data
    } else if (ext == ".jpg" || ext == ".jpeg") {
        const jpeg = require('jpeg-js');
        let jpg = jpeg.decode(fs.readFileSync(filepath));
        tex = createPixelTexture(gl, jpg.width, jpg.height)
        assert(tex.data.length == jpg.data.length);
        tex.data = jpg.data;
    // TODO openEXR
    } else {
        console.error("unknown file extension", filepath)
        return
    }
    tex.bind().submit()
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, options.wrap);
	gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, options.wrap);
	gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, options.minfilter || options.filter);
	gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, options.magfilter || options.filter);
	if (options.mipmap) gl.generateMipmap(gl.TEXTURE_2D);
	tex.unbind();
    return tex
}

function createPixelTexture(gl, width, height, floatingpoint=false) {

    floatingpoint =  floatingpoint && (!!gl.getExtension("EXT_color_buffer_float"));
    const channels = 4; // RGBA


    let tex = {
        id: gl.createTexture(),
        data: null,
        width: width,
        height: height,
        channels: channels,
        format: gl.RGBA,
        dataType: floatingpoint ? gl.FLOAT : gl.UNSIGNED_BYTE,  // type of data we are supplying,
        
        load(url) {
            if (!this.data) this.allocate();

            let self = this;
            const img = new Image();   // Create new img element
            const canvas = new OffscreenCanvas(this.width, this.height);
            img.onload = function() {

                // TODO: assert width/height match?
                let ctx = canvas.getContext("2d");
                ctx.drawImage(img, 0, 0);
                let imgdata = ctx.getImageData(0, 0, self.width, self.height);
                let binary = new Uint8ClampedArray(imgdata.data.buffer);
                let length = imgdata.data.length;
                for (let i=0; i<length; i++) {
                    self.data[i*4+0] = (binary[i*4+0] / 255);
                    self.data[i*4+1] = (binary[i*4+1] / 255);
                    self.data[i*4+2] = (binary[i*4+2] / 255);
                    self.data[i*4+3] = (binary[i*4+3] / 255);
                }
                self.bind().submit();
                // self.width = this.width;
                // self.height = this.height;
                // self.canvas.width = self.width;
                // self.canvas.height = self.height;
                // let length = self.width * self.height;
                // let ctx = self.canvas.getContext("2d");
                // ctx.drawImage(img, 0, 0);
                // self.imgdata = ctx.getImageData(0, 0, self.width, self.height);
                // let binary = new Uint8ClampedArray(self.imgdata.data.buffer);
                // let data = new Float32Array(length*4);
                // for (let i=0; i<length; i++) {
                //     data[i*4+0] = (binary[i*4+0] / 255);
                //     data[i*4+1] = (binary[i*4+1] / 255);
                //     data[i*4+2] = (binary[i*4+2] / 255);
                //     data[i*4+3] = (binary[i*4+3] / 255);
                // }
                // self.data = data;

                // if (callback) callback.apply(self);
            }
            img.src = url; // Set source path
            return this;
        },

        // allocate local data
        allocate() {
            if (!this.data) {
                let elements = width * height * channels;
                if (floatingpoint) {
                    this.data = new Float32Array(elements);
                } else {
                    this.data = new Uint8Array(elements);
                }
            }
            return this;
        },
        
        // bind() first
        submit(miplevels = 4) {
            let internalFormat = floatingpoint ? gl.RGBA32F : gl.RGBA;   // format we want in the texture
            // gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_BASE_LEVEL, 0);
            // gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAX_LEVEL, miplevels-1);
            //gl.texParameterf(gl.TEXTURE_2D, gl.TEXTURE_MAX_ANISOTROPY, 2.0);
            if (miplevels > 1) {
                gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR_MIPMAP_LINEAR);
            } else {
                gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR);
            }
            gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.LINEAR);
            gl.texImage2D(gl.TEXTURE_2D, 0, internalFormat, this.width, this.height, 0, this.format, this.dataType, this.data);
            if (miplevels > 1) gl.generateMipmap(gl.TEXTURE_2D)
            
            return this;
        },
        
        bind(unit = 0) {
            gl.activeTexture(gl.TEXTURE0 + unit);
            //gl.enable(gl.TEXTURE_2D);
            gl.bindTexture(gl.TEXTURE_2D, this.id);
            return this;
        },
        unbind(unit = 0) {
            gl.activeTexture(gl.TEXTURE0 + unit);
            //gl.enable(gl.TEXTURE_2D);
            gl.bindTexture(gl.TEXTURE_2D, null);
            return this;
        },

        read(x, y) {
            if (!this.data) return 0;
    
            let idx = 4*(Math.floor(x) + Math.floor(y) * this.width);
            return this.data[idx+1];
        },
    
        readInto(x, y, v) {
            if (this.data) {
                let idx = 4*(Math.floor(x) + Math.floor(y) * this.width);
                v[0] = this.data[idx];
                v[1] = this.data[idx+1];
                v[2] = this.data[idx+2];
                v[3] = this.data[idx+3];
            }
            return v;
        },
    
        readDot(x, y, xyz) {
            if (!this.data) return 0;
            let idx = 4*(Math.floor(x) + Math.floor(y) * this.width);
            return this.data[idx] * xyz[0]
                 + this.data[idx+1] * xyz[1]
                 + this.data[idx+2] * xyz[2];
        },

        dispose() {
            gl.deleteTextures(this.id)
            return this;
        },
    };

    tex.allocate()
    tex.bind()
    tex.submit();
    ok(gl, "pixeltex")

    // unless we get `OES_texture_float_linear` we can not filter floating point
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.CLAMP_TO_EDGE);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST);
    

    return tex.unbind();
}

function createTexture3D(gl, opt={}) {
    const isFloat = !!opt.float || !!opt.isFloat;//&& EXT_color_buffer_float;
    const channels = opt.channels || 4; // RGBA
    const width = opt.width || 16;
    const height = opt.height || width;
    const depth = opt.depth || width;
    
    let format = gl.RGBA;
    if (channels == 1) {
        format = gl.RED;
    } else if (channels == 2) {
        format = gl.LUMINANCE_ALPHA;
    } else if (channels == 3) {
        format = gl.RGB;
    }

    let internalFormat = format;
    let type = gl.UNSIGNED_BYTE;
    if (isFloat) {
        type = gl.FLOAT;
        if (channels == 1) {
            internalFormat = gl.R32F;
        } else if (channels == 2) {
            internalFormat = gl.RG32F;
        } else if (channels == 3) {
            internalFormat = gl.RGB32F;
        } else {	
            internalFormat = gl.RGBA32F;
        }
    }

    //console.log("texture", isFloat, channels, width, height, depth)
    //console.log(format, gl.RGBA);
    //console.log(internalFormat, gl.RGBA32F);

    let tex = {
        id: gl.createTexture(),
        data: null,
        isFloat: isFloat,
        width: width,
		height: height,
		depth: depth,
        channels: channels,
		elements: 0,
        format: format,
        type: type,
        filter_min: opt.filter_min || opt.filter || gl.LINEAR,
        filter_mag: opt.filter_mag || opt.filter || gl.LINEAR,
        internalFormat: internalFormat,  // type of data we are supplying,

        clone() {
            return createTexture3D(gl, opt=this)
        },
        
        // allocate local data
        allocate() {
            if (!this.data) {
                let elements = this.width * this.height * this.depth * this.channels;
				this.elements = elements;
                if (this.isFloat) {
                    this.data = new Float32Array(elements);
                } else {
                    this.data = new Uint8Array(elements);
                }
            }
            return this;
        },
        
        // bind() first
        submit() {
			//gl.enable(gl.TEXTURE_3D)
			//gl.texImage3D(gl.TEXTURE_3D, mipLevel, this.internalFormat, this.width, this.height, this.depth, border, this.format, this.type, this.data);
			gl.texImage3D(gl.TEXTURE_3D, 0, this.internalFormat, this.width, this.height, this.depth, 0, this.format, this.type, this.data);
			//console.log(gl.TEXTURE_3D, this.internalFormat == gl.RGBA32F, this.format == gl.RGBA, this.type == gl.FLOAT);
            return this;
        },
        
        bind(unit = 0) {
			gl.activeTexture(gl.TEXTURE0 + unit);
		//	gl.enable(gl.TEXTURE_3D) // not needed in core profile
			gl.bindTexture(gl.TEXTURE_3D, this.id);
            return this;
        },
        unbind(unit = 0) {
			gl.activeTexture(gl.TEXTURE0 + unit);
			//gl.enable(gl.TEXTURE_3D)  // not needed in core profile
            gl.bindTexture(gl.TEXTURE_3D, null);
            return this;
        },

        dispose() {
            gl.deleteTextures(this.id)
        },

        // copy texture back to CPU
        // must bind() first!
        getData() {
            gl.getTexImage(gl.TEXTURE_3D, 0, this.format, this.type, this.data)
            return this;
        },

        writeFileSync(filepath) {
            this.bind().getData()
            fs.writeFileSync(filepath, Buffer.from(this.data.buffer))
            console.log("wrote", filepath)
        },

        writeFile(filepath) {
            this.bind().getData()
            fs.writeFile(filepath, Buffer.from(this.data.buffer), ()=>{
                console.log("wrote", filepath)
            })
        },

        readFileSync(filepath) {
            if (fs.existsSync(filepath)) {
                // load it:
                const loadedBuffer = fs.readFileSync(filepath)
                if (this.isFloat) {
                    this.data = new Float32Array(loadedBuffer.buffer);
                } else {
                    this.data = new Uint8Array(loadedBuffer.buffer);
                }
                this.bind().submit()
                console.log("read", filepath)
            }
        },

        // TODO read / readInto methods for accessing underlying data
        read(pos) {
            let x = Math.floor(pos[0]);
            let y = Math.floor(pos[1]);
            let z = Math.floor(pos[2]);
            let idx = ((this.height*z + y)*this.width + x) * this.channels; // TODO: assumes single-channel
            return this.data[idx];
        },

        read_wrap(pos) {
            let x = wrap(Math.floor(pos[0]), this.width);
            let y = wrap(Math.floor(pos[1]), this.height);
            let z = wrap(Math.floor(pos[2]), this.depth);
            let idx = ((this.height*z + y)*this.width + x) * this.channels; 
            return this.data.subarray(idx, idx+this.channels);
        },

        readInto_wrap_interp(pos, result=[]) {
            let [ x, y, z ] = pos;
            let xi = Math.floor(x);
            let yi = Math.floor(y);
            let zi = Math.floor(z);
            let xa0 = x - xi, ya0 = y - yi, za0 = z - zi;
            let xa1 = 1-xa0, ya1 = 1-ya0, za1 = 1-za0
            let xi0 = wrap(Math.floor(pos[0]), this.width);
            let yi0 = wrap(Math.floor(pos[1]), this.height);
            let zi0 = wrap(Math.floor(pos[2]), this.depth);
            let xi1 = wrap(xi0+1, this.width);
            let yi1 = wrap(yi0+1, this.height);
            let zi1 = wrap(zi0+1, this.depth);
            let idx000 = ((this.height*zi0 + yi0)*this.width + xi0) * this.channels; 
            let idx001 = ((this.height*zi0 + yi0)*this.width + xi1) * this.channels; 
            let idx010 = ((this.height*zi0 + yi1)*this.width + xi0) * this.channels; 
            let idx011 = ((this.height*zi0 + yi1)*this.width + xi1) * this.channels; 
            let idx100 = ((this.height*zi1 + yi0)*this.width + xi0) * this.channels; 
            let idx101 = ((this.height*zi1 + yi0)*this.width + xi1) * this.channels; 
            let idx110 = ((this.height*zi1 + yi1)*this.width + xi0) * this.channels; 
            let idx111 = ((this.height*zi1 + yi1)*this.width + xi1) * this.channels; 
            let data000 = this.data.subarray(idx000, idx000+this.channels);
            let data001 = this.data.subarray(idx001, idx001+this.channels);
            let data010 = this.data.subarray(idx010, idx010+this.channels);
            let data011 = this.data.subarray(idx011, idx011+this.channels);
            let data100 = this.data.subarray(idx100, idx100+this.channels);
            let data101 = this.data.subarray(idx101, idx101+this.channels);
            let data110 = this.data.subarray(idx110, idx110+this.channels);
            let data111 = this.data.subarray(idx111, idx111+this.channels);

            for (let i=0; i<this.channels; i++) {
                result[i] = data000[i]*za0*ya0*xa0 + 
                            data001[i]*za0*ya0*xa1 + 
                            data010[i]*za0*ya1*xa0 + 
                            data011[i]*za0*ya1*xa1 + 
                            data100[i]*za1*ya0*xa0 + 
                            data101[i]*za1*ya0*xa1 + 
                            data110[i]*za1*ya1*xa0 + 
                            data111[i]*za1*ya1*xa1;
            }
            return result
        },
	};

    tex.allocate().bind().submit()

    // unless we get `OES_texture_float_linear` we can not filter floating point
    gl.texParameteri(gl.TEXTURE_3D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE);
    gl.texParameteri(gl.TEXTURE_3D, gl.TEXTURE_WRAP_T, gl.CLAMP_TO_EDGE);
    gl.texParameteri(gl.TEXTURE_3D, gl.TEXTURE_WRAP_R, gl.CLAMP_TO_EDGE);
    gl.texParameteri(gl.TEXTURE_3D, gl.TEXTURE_MIN_FILTER, tex.filter_min);
    gl.texParameteri(gl.TEXTURE_3D, gl.TEXTURE_MAG_FILTER, tex.filter_mag);
    
    return tex.unbind();
}

function makeFboWithDepth(gl, width=1024, height=1024, mipmap=false, multisample=0, repeat) {
    
	const id = gl.createFramebuffer();
	const colorTexture = gl.createTexture();
	const depthTexture = gl.createTexture();
    const texture_target = multisample ? gl.TEXTURE_2D_MULTISAMPLE : gl.TEXTURE_2D
    repeat = repeat || gl.CLAMP_TO_BORDER
	{		
		gl.bindFramebuffer(gl.FRAMEBUFFER, id);
		
		// define size and format of level 0
		const level = 0;
        const border = 0;


        if (multisample) {
            gl.enable(gl.TEXTURE_2D_MULTISAMPLE)

            gl.bindTexture(gl.TEXTURE_2D_MULTISAMPLE, colorTexture);
            gl.texStorage2DMultisample(gl.TEXTURE_2D_MULTISAMPLE, multisample, gl.RGBA, width, height, true)
            gl.framebufferTexture2D(gl.FRAMEBUFFER, gl.COLOR_ATTACHMENT0, gl.TEXTURE_2D_MULTISAMPLE, colorTexture, level);

            // depth texture
            gl.bindTexture(gl.TEXTURE_2D_MULTISAMPLE, depthTexture);
            gl.texStorage2DMultisample(gl.TEXTURE_2D_MULTISAMPLE, multisample, gl.DEPTH_COMPONENT, width, height, true)
            gl.framebufferTexture2D(gl.FRAMEBUFFER, gl.DEPTH_ATTACHMENT, gl.TEXTURE_2D_MULTISAMPLE, depthTexture, level);
        } else {
            //gl.enable(gl.TEXTURE_2D)
		    gl.bindTexture(gl.TEXTURE_2D, colorTexture);
		    gl.texImage2D(gl.TEXTURE_2D, level, gl.RGBA, width, height, border, gl.RGBA, gl.UNSIGNED_BYTE, null);
            if (mipmap) gl.generateMipmap(gl.TEXTURE_2D); 

            // set the filtering so we don't need mips
            gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, (mipmap) ? gl.LINEAR_MIPMAP_LINEAR : gl.LINEAR);
            gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.LINEAR);
            gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, repeat);
            gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, repeat);
            gl.framebufferTexture2D(gl.FRAMEBUFFER, gl.COLOR_ATTACHMENT0, gl.TEXTURE_2D, colorTexture, level);

            // depth texture
            gl.bindTexture(gl.TEXTURE_2D, depthTexture);
            gl.texImage2D(gl.TEXTURE_2D, level, gl.DEPTH_COMPONENT24, width, height, border, gl.DEPTH_COMPONENT, gl.UNSIGNED_INT, null);
            // set the filtering so we don't need mips
            gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST);
            gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST);
            gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, repeat);
            gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, repeat);
            gl.framebufferTexture2D(gl.FRAMEBUFFER, gl.DEPTH_ATTACHMENT, gl.TEXTURE_2D, depthTexture, level);
        }

        gl.bindFramebuffer(gl.FRAMEBUFFER, null);
	}

	return {
		id: id,
		colorTexture: colorTexture,
		depthTexture: depthTexture,
		width: width,
        height: height,
        
        // be sure to set viewport & clear after begin()
        begin() {
            gl.bindFramebuffer(gl.FRAMEBUFFER, id);
            return this;
        },

        end(unit=0) {
            gl.bindFramebuffer(gl.FRAMEBUFFER, null);
            if (mipmap){
                this.bind()
		        if (mipmap && !multisample) gl.generateMipmap(gl.TEXTURE_2D);
            }
            return this;
        },

        bind(unit=0) {
            gl.activeTexture(gl.TEXTURE0 + unit);
			gl.bindTexture(texture_target, colorTexture);
            return this;
        },
        unbind(unit=0) {
            gl.activeTexture(gl.TEXTURE0 + unit);
			gl.bindTexture(texture_target, null);
            return this;
        },

        bindDepth(unit=1) {
            gl.activeTexture(gl.TEXTURE0 + unit);
			gl.bindTexture(texture_target, depthTexture);
            return this;
        },
        unbindDepth(unit=1) {
            gl.activeTexture(gl.TEXTURE0 + unit);
			gl.bindTexture(texture_target, null);
            return this;
        },


        dispose() {
            gl.deleteFramebuffers(this.id)
            gl.deleteTextures(this.colorTexture)
            gl.deleteTextures(this.depthTexture)
            return this;
        },
	}
}


function makeGbuffer(gl, width=1024, height=1024, config=[
	{ float:false, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
	{ float:true, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
	{ float:true, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
	{ float:false, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
]) {

	const id = gl.createFramebuffer();
	const depthTexture = gl.createTexture();
	let textures = []
	let attachments = []
	{		
		gl.bindFramebuffer(gl.FRAMEBUFFER, id);
		const level = 0;
		const border = 0;

		for (let i=0; i<config.length; i++) {
			let cfg = config[i];

			let format = gl.RGBA;
			let internalFormat = format;
			let type = gl.UNSIGNED_BYTE;

			if (cfg.float) {
				type = gl.FLOAT;
				internalFormat = gl.RGBA32F;
			}

            let wrap = cfg.wrap || gl.CLAMP_TO_EDGE

            cfg.format = format
            cfg.internalFormat = internalFormat
            cfg.type = type
            cfg.wrap = wrap
		
			// define size and format of level 0
			//gl.enable(gl.TEXTURE_2D)
			const tex = gl.createTexture();
			gl.bindTexture(gl.TEXTURE_2D, tex);
			gl.texImage2D(gl.TEXTURE_2D, 0, internalFormat, width, height, 0,
				format, type, null);
            if (cfg.mipmap) gl.generateMipmap(gl.TEXTURE_2D); 
			// set the filtering so we don't need mips
			gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, (cfg.mipmap) ? gl.LINEAR_MIPMAP_LINEAR : gl.LINEAR);
			gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.LINEAR);
			gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, wrap);
			gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, wrap);
			gl.framebufferTexture2D(gl.FRAMEBUFFER, gl.COLOR_ATTACHMENT0+i, gl.TEXTURE_2D, tex, 0);

			textures[i] = tex
			attachments[i] = gl.COLOR_ATTACHMENT0+i
            config[i] = cfg
		}
		gl.drawBuffers(attachments);

		// depth texture
		gl.bindTexture(gl.TEXTURE_2D, depthTexture);
		gl.texImage2D(gl.TEXTURE_2D, level, gl.DEPTH_COMPONENT24,
			width, height, border,
			gl.DEPTH_COMPONENT, gl.UNSIGNED_INT, null);
		//gl.texStorage2D(gl.TEXTURE_2D, 1, gl.DEPTH_COMPONENT24, width, height);

		// set the filtering so we don't need mips
		gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST);
		gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST);
		gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE);
		gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.CLAMP_TO_EDGE);
		gl.framebufferTexture2D(gl.FRAMEBUFFER, gl.DEPTH_ATTACHMENT, gl.TEXTURE_2D, depthTexture, level);

		if (gl.checkFramebufferStatus(gl.FRAMEBUFFER) !== gl.FRAMEBUFFER_COMPLETE) {
			console.error("can't use frame buffer")
			// See http://www.khronos.org/opengles/sdk/docs/man/xhtml/glCheckFramebufferStatus.xml
		}
		gl.bindFramebuffer(gl.FRAMEBUFFER, null);
	}

	return {
		id: id,
		textures: textures,
        config: config,
        colorTexture: textures[0],
		depthTexture: depthTexture,
		width: width,
        height: height,
        data: [],

        clone(gl) {
            return makeGbuffer(gl, this.width, this.height, this.config)
        },
        
        // be sure to set viewport & clear after begin()
        begin() {
            gl.bindFramebuffer(gl.FRAMEBUFFER, id);
            return this; 
        },

        end() {
            gl.bindFramebuffer(gl.FRAMEBUFFER, null);
            for (let i=0; i<config.length; i++) {
                let cfg = config[i];
                if (cfg.mipmap){
                    this.bind(i)
                    gl.generateMipmap(gl.TEXTURE_2D);
                }
            }
            return this; 
        },

        bind(texture=0, unit=0) {
            gl.activeTexture(gl.TEXTURE0 + unit);
			gl.bindTexture(gl.TEXTURE_2D, this.textures[texture]);
            return this;
        },
        // must bind first
        submit(texture=0, data) {
            gl.texImage2D(gl.TEXTURE_2D, 0, config[texture].internalFormat, this.width, this.height, 0, config[texture].format, config[texture].type, data || this.data[texture]);
            if (config[texture].mipmap) gl.generateMipmap(gl.TEXTURE_2D);
            return this;
        },
        unbind(unit=0) {
            gl.activeTexture(gl.TEXTURE0 + unit);
			gl.bindTexture(gl.TEXTURE_2D, null);
            return this;
        },

        dispose() {
            gl.deleteFramebuffers(this.id)
            for (let tex in textures) gl.deleteTextures(tex)
            gl.deleteTextures(this.depthTexture)
            return this;
        },

        allocate(attachment=0) {
            const cfg = this.config[attachment]
            if (cfg.float) {
                if (!this.data[attachment]) this.data[attachment] = new Float32Array(this.width * this.height * 4);
            } else {
                if (!this.data[attachment]) this.data[attachment] = new Uint8Array(this.width * this.height * 4);
            }
            return this;
        },

        allocateAll() {
            for (let attachment=0; attachment < config.length; attachment++) {
                this.allocate(attachment);
            }
            return this;
        },

        // reads the GPU memory back into this.data
        getData(attachment = 0) {
            this.allocate(attachment)
            const cfg = this.config[attachment]
            gl.bindTexture(gl.TEXTURE_2D, this.textures[attachment])
            gl.getTexImage(gl.TEXTURE_2D, 0, cfg.format, cfg.type, this.data[attachment]);
            return this;
        },
        
        // reads the GPU memory back into this.data
        // must begin() first!
        // warning: can be slow
        readPixels(attachment = 0) {
            const cfg = this.config[attachment]
            if (cfg.float) {
                if (!this.data[attachment]) this.data[attachment] = new Float32Array(this.width * this.height * 4);
            } else {
                if (!this.data[attachment]) this.data[attachment] = new Uint8Array(this.width * this.height * 4);
            }
            gl.readBuffer(gl.COLOR_ATTACHMENT0 + attachment);
            gl.readPixels(0, 0, this.width, this.height, cfg.format, cfg.type, this.data[attachment]);
            return this;
        },
	}
}

function makeGbufferPair(gl, width=1024, height=1024, config=[
	{ float:false, mipmap: false, wrap: gl.CLAMP_TO_EDGE },
]) {
    let readbuffer = makeGbuffer(...arguments)
    let writebuffer = readbuffer.clone(gl)
    return {
        readbuffer, writebuffer,

		width, height, config,

        swap() {
            let tmp = this.readbuffer;
            this.readbuffer = this.writebuffer;
            this.writebuffer = tmp;
            return this
        },

        begin() {
            this.writebuffer.begin()
            return this
        },
        readPixels() {
            this.writebuffer.readPixels(...arguments)
            return this
        },
        end() {
            this.writebuffer.end()
            this.swap()
            return this
        },

        bind() {
            this.readbuffer.bind(...arguments)
            return this
        },
        unbind() {
            this.readbuffer.unbind(...arguments)
            return this
        },
        // must bind first
        submit() {
            this.readbuffer.submit(...arguments)
            return this
        },

        allocate() { 
            this.readbuffer.allocate(...arguments)
            this.writebuffer.allocate(...arguments)
            return this
        },
        allocateAll() { 
            this.readbuffer.allocateAll(...arguments)
            this.writebuffer.allocateAll(...arguments)
            return this
        },

        dispose() {
            this.front.dispose()
            this.back.dispose()
        }
    }
}

function createFBO(gl, width=1024, height=1024, floatingpoint=false) {
    let id = gl.createFramebuffer();

    let colorRenderbuffer = gl.createRenderbuffer();
    gl.bindRenderbuffer(gl.RENDERBUFFER, colorRenderbuffer);
    gl.renderbufferStorageMultisample(gl.RENDERBUFFER, 4, gl.RGBA8, width, height);

    gl.bindFramebuffer(gl.FRAMEBUFFER, id);
    gl.framebufferRenderbuffer(gl.FRAMEBUFFER, gl.COLOR_ATTACHMENT0, gl.RENDERBUFFER, colorRenderbuffer);
    gl.bindFramebuffer(gl.FRAMEBUFFER, null);

    let fbo = {
		id: id,
		width: width,
		height: height,
		floatingpoint: floatingpoint,

        // what we currently read from:
        front: createPixelTexture(gl, width, height, floatingpoint),
        // what we currently draw to:
        back: createPixelTexture(gl, width, height, floatingpoint),
        
        bind() { 
            gl.bindFramebuffer(gl.FRAMEBUFFER, this.id); 
            return this; 
        },
        clear(r=0, g=0, b=0, a=1) {
            gl.clearBufferfv(gl.COLOR, 0, [r, g, b, a]);
            return this; 
        },
        unbind() { 
            gl.bindFramebuffer(gl.FRAMEBUFFER, null); 
            return this; 
        },
        swap() {
            [this.back, this.front] = [this.front, this.back];
            return this;
        },
        begin() {
            // make this the framebuffer we are rendering to.
            gl.bindFramebuffer(gl.FRAMEBUFFER, this.id);
            let attachmentPoint = gl.COLOR_ATTACHMENT0;
            let mipLevel = 0;               // the largest mip
            gl.framebufferTexture2D(gl.FRAMEBUFFER, attachmentPoint, gl.TEXTURE_2D, this.back.id, mipLevel);
            gl.viewport(0, 0, width, height);
            return this; 
        },
        
        end() {
            gl.bindFramebuffer(gl.FRAMEBUFFER, null);
            this.swap();
            return this; 
        },

        blit(dstid) {
            // Blit framebuffers, no Multisample texture 2d in WebGL 2
            gl.bindFramebuffer(gl.READ_FRAMEBUFFER, this.id);
            gl.bindFramebuffer(gl.DRAW_FRAMEBUFFER, dstid);
            //gl.clearBufferfv(gl.COLOR, 0, [0.0, 0.0, 0.0, 1.0]);
            gl.blitFramebuffer(
                0, 0, this.front.width, this.front.height,
                0, 0, this.front.width, this.front.height,
                gl.COLOR_BUFFER_BIT, gl.NEAREST // NEAREST is the only valid option at the moment
            );
            return this;
        },

        // reads the GPU memory back into this.data
        // must bind() first!
        // warning: can be slow
        readPixels(attachment = gl.COLOR_ATTACHMENT0) {
            if (!this.front.data) this.front.allocate();
            gl.readBuffer(attachment);
            gl.readPixels(0, 0, this.front.width, this.front.height, this.front.format, this.front.dataType, this.front.data);
            return this;
        },

        dispose() {
            gl.deleteFramebuffers(this.id)
            this.front.dispose();
            this.back.dispose();
            return this;
        },
    };

    fbo.bind().swap().unbind();
    return fbo;
}

// geom should have vertices, can also have normals, indices, perhaps also vertexComponents
// if no program is given
// the attributes are laid out as follows:
// 0: position (vec2 or vec3 depending on geometry)
// 1: normal (vec3)
// 2: texcoord (vec2)
// 3: color (vec4)
function createVao(gl, geom, program) {
    let self = {
		id: gl.createVertexArray(),
        geom: geom,
        program: program,

        indexType: gl.UNSIGNED_SHORT,

        setGeom(geom) {
            this.bind();
            if (geom) {
                if (!geom.vertexComponents) geom.vertexComponents = 3;

                if (geom.vertices) {
                    if (!this.vertexBuffer) {
                        let buffer = gl.createBuffer();
                        this.vertexBuffer = buffer;
                        // look up in the shader program where the vertex attributes need to go.
                        let attrLoc = program ? gl.getAttribLocation(program, "a_position") : 0;
                        // Turn on the attribute
                        gl.enableVertexAttribArray(attrLoc);
                        // Tell the attribute how to get data out of buffer (ARRAY_BUFFER)
                        let size = geom.vertexComponents;  // how many components per vertex (e.g. 2D, 3D geometry)
                        let type = gl.FLOAT;   // the data is 32bit floats
                        let normalize = false; // don't normalize the data
                        let stride = 0;        // 0 = move forward size * sizeof(type) each iteration to get the next position
                        let offset = 0;        // start at the beginning of the buffer
                        gl.vertexAttribPointer(attrLoc, size, type, normalize, stride, offset);
                    }
                    gl.bindBuffer(gl.ARRAY_BUFFER, this.vertexBuffer);
                    gl.bufferData(gl.ARRAY_BUFFER, geom.vertices, gl.DYNAMIC_DRAW);
                    gl.bindBuffer(gl.ARRAY_BUFFER, 0);
                }
                if (geom.normals) {
                    if (!this.normalBuffer) {
                        let buffer = gl.createBuffer();
                        this.normalBuffer = buffer;
                        // look up in the shader program where the vertex attributes need to go.
                        let attrLoc = program ? gl.getAttribLocation(program, "a_normal") : 1;
                        // Turn on the attribute
                        gl.enableVertexAttribArray(attrLoc);
                        // Tell the attribute how to get data out of buffer (ARRAY_BUFFER)
                        let size = 3;          // 2 components per iteration
                        let type = gl.FLOAT;   // the data is 32bit floats
                        let normalize = false; // don't normalize the data
                        let stride = 0;        // 0 = move forward size * sizeof(type) each iteration to get the next position
                        let offset = 0;        // start at the beginning of the buffer
                        gl.vertexAttribPointer(attrLoc, size, type, normalize, stride, offset);
                    }
                    gl.bindBuffer(gl.ARRAY_BUFFER, this.normalBuffer);
                    gl.bufferData(gl.ARRAY_BUFFER, geom.normals, gl.DYNAMIC_DRAW);
                    gl.bindBuffer(gl.ARRAY_BUFFER, 0);
                }
                if (geom.texCoords) {
                    if (!this.normalBuffer) {
                        let buffer = gl.createBuffer();
                        this.texCoordBuffer = buffer;
                        // Bind it to ARRAY_BUFFER (think of it as ARRAY_BUFFER = positionBuffer)
                        // look up in the shader program where the vertex attributes need to go.
                        let attrLoc = program ? gl.getAttribLocation(program, "a_texCoord") : 2;
                        // Turn on the attribute
                        gl.enableVertexAttribArray(attrLoc);
                        // Tell the attribute how to get data out of positionBuffer (ARRAY_BUFFER)
                        let size = 2;          // 2 components per iteration
                        let type = gl.FLOAT;   // the data is 32bit floats
                        let normalize = false; // don't normalize the data
                        let stride = 0;        // 0 = move forward size * sizeof(type) each iteration to get the next position
                        let offset = 0;        // start at the beginning of the buffer
                        gl.vertexAttribPointer(attrLoc, size, type, normalize, stride, offset);
                    }
                    gl.bindBuffer(gl.ARRAY_BUFFER, this.texCoordBuffer);
                    gl.bufferData(gl.ARRAY_BUFFER, geom.texCoords, gl.DYNAMIC_DRAW);
                    gl.bindBuffer(gl.ARRAY_BUFFER, 0);
                }
                if (geom.colors) {
                    if (!this.colorBuffer) {
                        let buffer = gl.createBuffer();
                        this.colorBuffer = buffer;
                        // look up in the shader program where the vertex attributes need to go.
                        let attrLoc = program ? gl.getAttribLocation(program, "a_color") : 3;
                        // Turn on the attribute
                        gl.enableVertexAttribArray(attrLoc);
                        // Tell the attribute how to get data out of buffer (ARRAY_BUFFER)
                        let size = 4;          // components per iteration
                        let type = gl.FLOAT;   // the data is 32bit floats
                        let normalize = false; // don't normalize the data
                        let stride = 0;        // 0 = move forward size * sizeof(type) each iteration to get the next position
                        let offset = 0;        // start at the beginning of the buffer
                        gl.vertexAttribPointer(attrLoc, size, type, normalize, stride, offset);
                    }
                    gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
                    gl.bufferData(gl.ARRAY_BUFFER, geom.colors, gl.DYNAMIC_DRAW);
                    gl.bindBuffer(gl.ARRAY_BUFFER, 0);
                }
                if (geom.indices) {
                    if (!this.indexBuffer) {
                        let buffer = gl.createBuffer();
                        this.indexBuffer = buffer;
                    }
                    this.indexType = (geom.indices.constructor == Uint32Array) ? gl.UNSIGNED_INT : gl.UNSIGNED_SHORT;
                    gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, this.indexBuffer);
                    gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, geom.indices, gl.DYNAMIC_DRAW);
                }
            }
            this.unbind()
        },

        init(program) {
            this.bind();
            if (geom) {
                if (!geom.vertexComponents) geom.vertexComponents = 3;
                if (geom.vertices) {
                    let buffer = gl.createBuffer();
                    // Bind it to ARRAY_BUFFER (think of it as ARRAY_BUFFER = positionBuffer)
                    gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
                    gl.bufferData(gl.ARRAY_BUFFER, geom.vertices, gl.STATIC_DRAW);
                    // look up in the shader program where the vertex attributes need to go.
                    let attrLoc = program ? gl.getAttribLocation(program, "a_position") : 0;
                    // Turn on the attribute
                    gl.enableVertexAttribArray(attrLoc);
                    // Tell the attribute how to get data out of buffer (ARRAY_BUFFER)
                    let size = geom.vertexComponents;  // how many components per vertex (e.g. 2D, 3D geometry)
                    let type = gl.FLOAT;   // the data is 32bit floats
                    let normalize = false; // don't normalize the data
                    let stride = 0;        // 0 = move forward size * sizeof(type) each iteration to get the next position
                    let offset = 0;        // start at the beginning of the buffer
                    gl.vertexAttribPointer(attrLoc, size, type, normalize, stride, offset);
                    // done with buffer:
                    gl.bindBuffer(gl.ARRAY_BUFFER, 0);
                    this.vertexBuffer = buffer;
                }
                if (geom.normals) {
                    let buffer = gl.createBuffer();
                    // Bind it to ARRAY_BUFFER (think of it as ARRAY_BUFFER = positionBuffer)
                    gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
                    gl.bufferData(gl.ARRAY_BUFFER, geom.normals, gl.STATIC_DRAW);
                    // look up in the shader program where the vertex attributes need to go.
                    let attrLoc = program ? gl.getAttribLocation(program, "a_normal") : 1;
                    // Turn on the attribute
                    gl.enableVertexAttribArray(attrLoc);
                    // Tell the attribute how to get data out of buffer (ARRAY_BUFFER)
                    let size = 3;          // 2 components per iteration
                    let type = gl.FLOAT;   // the data is 32bit floats
                    let normalize = false; // don't normalize the data
                    let stride = 0;        // 0 = move forward size * sizeof(type) each iteration to get the next position
                    let offset = 0;        // start at the beginning of the buffer
                    gl.vertexAttribPointer(attrLoc, size, type, normalize, stride, offset);
                    // done with buffer:
                    gl.bindBuffer(gl.ARRAY_BUFFER, 0);
                    this.normalBuffer = buffer;
                }
                if (geom.texCoords) {
                    let buffer = gl.createBuffer();
                    // Bind it to ARRAY_BUFFER (think of it as ARRAY_BUFFER = positionBuffer)
                    gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
                    gl.bufferData(gl.ARRAY_BUFFER, geom.texCoords, gl.STATIC_DRAW);
                    // look up in the shader program where the vertex attributes need to go.
                    let attrLoc = program ? gl.getAttribLocation(program, "a_texCoord") : 2;
                    // Turn on the attribute
                    gl.enableVertexAttribArray(attrLoc);
                    // Tell the attribute how to get data out of positionBuffer (ARRAY_BUFFER)
                    let size = 2;          // 2 components per iteration
                    let type = gl.FLOAT;   // the data is 32bit floats
                    let normalize = false; // don't normalize the data
                    let stride = 0;        // 0 = move forward size * sizeof(type) each iteration to get the next position
                    let offset = 0;        // start at the beginning of the buffer
                    gl.vertexAttribPointer(attrLoc, size, type, normalize, stride, offset);
                    // done with buffer:
                    gl.bindBuffer(gl.ARRAY_BUFFER, 0);
                    this.texCoordBuffer = buffer;
                }
                if (geom.colors) {
                    let buffer = gl.createBuffer();
                    // Bind it to ARRAY_BUFFER (think of it as ARRAY_BUFFER = positionBuffer)
                    gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
                    gl.bufferData(gl.ARRAY_BUFFER, geom.colors, gl.STATIC_DRAW);
                    // look up in the shader program where the vertex attributes need to go.
                    let attrLoc = program ? gl.getAttribLocation(program, "a_color") : 3;
                    // Turn on the attribute
                    gl.enableVertexAttribArray(attrLoc);
                    // Tell the attribute how to get data out of buffer (ARRAY_BUFFER)
                    let size = 4;          // components per iteration
                    let type = gl.FLOAT;   // the data is 32bit floats
                    let normalize = false; // don't normalize the data
                    let stride = 0;        // 0 = move forward size * sizeof(type) each iteration to get the next position
                    let offset = 0;        // start at the beginning of the buffer
                    gl.vertexAttribPointer(attrLoc, size, type, normalize, stride, offset);
                    // done with buffer:
                    gl.bindBuffer(gl.ARRAY_BUFFER, 0);
                    this.colorBuffer = buffer;
                }
                if (geom.indices) {
                    // check type: 
                    if (geom.indices.constructor == Uint32Array) this.indexType = gl.UNSIGNED_INT 

                    let buffer = gl.createBuffer();
                    // Bind it to ARRAY_BUFFER (think of it as ARRAY_BUFFER = positionBuffer)
                    gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, buffer);
                    gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, geom.indices, gl.DYNAMIC_DRAW);
                    this.indexBuffer = buffer;
                }
            }
            this.unbind();
        },

        // assumes vao is already bound:
        setAttributes(buffer, bytestride, bufferFields, instanced) {
            gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
            for (let field of bufferFields) {
                const attrLoc = field.location != undefined ? field.location : gl.getAttribLocation(this.program, field.name);
                const normalize = false;
                const bytesize = field.bytesize / field.components;

                // watch out: if field.componnents > 4, it occupies several attribute slots
                // need to enable and bind each of them in turn:
                for (let i=0; i<field.components; i+=4) {
                    const loc = attrLoc + i/4; 
                    const byteoffset = field.byteoffset + (i * bytesize);
                    const components = Math.min(4, field.components - i);
                    gl.enableVertexAttribArray(loc);
                    gl.vertexAttribPointer(loc, components, field.type, normalize, bytestride, byteoffset);
                    if (instanced) {
                        gl.vertexAttribDivisor(loc, 1);
                    } else {
                        gl.vertexAttribDivisor(loc, 0);
                    }

                    //console.log("set attr", field.name, loc, components, instanced, bytestride, byteoffset)
                }
            }
            return this;
        },

        bind() {
            gl.bindVertexArray(this.id);
            return this;
        },
        unbind() {
            gl.bindVertexArray(this.id, null);
            return this;
        },
		// bind first:
		submit() {
            //gl.bufferData(gl.ARRAY_BUFFER, this.data, gl.DYNAMIC_DRAW);
            if (!geom) return
            if (geom.vertices) {
                gl.bindBuffer(gl.ARRAY_BUFFER, this.vertexBuffer);
                gl.bufferData(gl.ARRAY_BUFFER, geom.vertices, gl.DYNAMIC_DRAW);
            }
            if (geom.colors) {
                gl.bindBuffer(gl.ARRAY_BUFFER, this.colorBuffer);
                gl.bufferData(gl.ARRAY_BUFFER, geom.colors, gl.DYNAMIC_DRAW);
            }
            if (geom.normals) {
                gl.bindBuffer(gl.ARRAY_BUFFER, this.normalBuffer);
                gl.bufferData(gl.ARRAY_BUFFER, geom.normals, gl.DYNAMIC_DRAW);
            }
            if (geom.texCoords) {
                gl.bindBuffer(gl.ARRAY_BUFFER, this.texCoordBuffer);
                gl.bufferData(gl.ARRAY_BUFFER, geom.texCoords, gl.DYNAMIC_DRAW);
            }
            if (geom.indices) {
                gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, this.indexBuffer);
                gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, geom.indices, gl.DYNAMIC_DRAW);
            }
			return this;
		},

        attach(buffer, instanced=false) {
            this.bind().setAttributes(buffer.id, buffer.bytestride, buffer.fields, instanced).unbind();
            return this
        },

        draw(count=0, offset=0) {
			if (geom && geom.indices) gl.drawElements(gl.TRIANGLES, count ? count : geom.indices.length, this.indexType, offset);
			else gl.drawArrays(gl.TRIANGLES, offset, count ? count : geom.vertices.length/geom.vertexComponents);
			return this;
        },
        drawLines(count=0, offset=0) {
			if (geom && geom.indices) gl.drawElements(gl.LINES, count ? count : geom.indices.length, this.indexType, offset);
			else gl.drawArrays(gl.LINES, offset, count ? count : geom.vertices.length/geom.vertexComponents);
			return this;
        },
        drawPoints(count=0, offset=0) {
            if (geom && geom.indices) gl.drawElements(gl.POINTS, count ? count : geom.indices.length, this.indexType, offset);
			else gl.drawArrays(gl.POINTS, offset, count ? count : geom.vertices.length/geom.vertexComponents);
			return this;
        },
        drawInstanced(instanceCount=1, primitive=gl.TRIANGLES) {
            if (geom.indices) gl.drawElementsInstanced(primitive, geom.indices.length, this.indexType, 0, instanceCount);
            else gl.drawArraysInstanced(primitive, 0, geom.vertices.length/geom.vertexComponents, instanceCount)
			return this;
        },
        drawInstancedRange(instanceStart=0, instanceCount=1, primitive=gl.TRIANGLES) {
            if (geom.indices) gl.drawElementsInstanced(primitive, geom.indices.length, this.indexType, instanceStart, instanceCount);
            else gl.drawArraysInstanced(primitive, instanceStart, geom.vertices.length/geom.vertexComponents, instanceCount)
			return this;
        },


        dispose() {
            if(this.indexBuffer) gl.deleteBuffers(this.indexBuffer)
            if(this.texCoordBuffer) gl.deleteBuffers(this.texCoordBuffer)
            if(this.normalBuffer) gl.deleteBuffers(this.normalBuffer)
            if(this.colorBuffer) gl.deleteBuffers(this.colorBuffer)
            if(this.vertexBuffer) gl.deleteBuffers(this.vertexBuffer)
            gl.deleteVertexArrays(this.id)
        },
    }
    self.init(program);

    return self;
}

function createQuadVao(gl, program) {
    let self = {
        id: gl.createVertexArray(),
        init(program) {
            this.bind();
            {
                let positionBuffer = makeBuffer(gl, [
                    -1,  1,  -1, -1,   1, -1,
                    -1,  1,   1, -1,   1,  1
                ]);
                // look up in the shader program where the vertex attributes need to go.
                let positionAttributeLocation = gl.getAttribLocation(program, "a_position");
                // Turn on the attribute
                gl.enableVertexAttribArray(positionAttributeLocation);
                // Tell the attribute which buffer to use
                gl.bindBuffer(gl.ARRAY_BUFFER, positionBuffer);
                // Tell the attribute how to get data out of positionBuffer (ARRAY_BUFFER)
                let size = 2;          // 2 components per iteration
                let type = gl.FLOAT;   // the data is 32bit floats
                let normalize = false; // don't normalize the data
                let stride = 0;        // 0 = move forward size * sizeof(type) each iteration to get the next position
                let offset = 0;        // start at the beginning of the buffer
                gl.vertexAttribPointer(positionAttributeLocation, size, type, normalize, stride, offset);
                // done with buffer:
                gl.bindBuffer(gl.ARRAY_BUFFER, null);
            }
            {
                let texcoordBuffer = makeBuffer(gl, [
                    0, 1,  0, 0,   1, 0,
                    0, 1,  1, 0,   1, 1
                ]);
                // look up in the shader program where the vertex attributes need to go.
                let positionAttributeLocation = gl.getAttribLocation(program, "a_texCoord");
                // Turn on the attribute
                gl.enableVertexAttribArray(positionAttributeLocation);
                // Tell the attribute which buffer to use
                gl.bindBuffer(gl.ARRAY_BUFFER, texcoordBuffer);
                // Tell the attribute how to get data out of positionBuffer (ARRAY_BUFFER)
                let size = 2;          // 2 components per iteration
                let type = gl.FLOAT;   // the data is 32bit floats
                let normalize = false; // don't normalize the data
                let stride = 0;        // 0 = move forward size * sizeof(type) each iteration to get the next position
                let offset = 0;        // start at the beginning of the buffer
                gl.vertexAttribPointer(positionAttributeLocation, size, type, normalize, stride, offset);
                // done with buffer:
                gl.bindBuffer(gl.ARRAY_BUFFER, null);
            }
            this.unbind();
        },

        bind() {
            gl.bindVertexArray(this.id);
            return this;
        },
        unbind() {
            gl.bindVertexArray(this.id, null);
            return this;
        },
        draw() {
            // draw
            let primitiveType = gl.TRIANGLES;
            let offset = 0;
            let count = 6;
            gl.drawArrays(primitiveType, offset, count);
            return this;
        },

        dispose() {
            if(this.indexBuffer) gl.deleteBuffers(this.indexBuffer)
            if(this.texCoordBuffer) gl.deleteBuffers(this.texCoordBuffer)
            if(this.normalBuffer) gl.deleteBuffers(this.normalBuffer)
            if(this.colorBuffer) gl.deleteBuffers(this.colorBuffer)
            if(this.vertexBuffer) gl.deleteBuffers(this.vertexBuffer)
            gl.deleteVertexArrays(this.id)
        },
    }
    if (program) self.init(program);

    return self;
}


// fields is an array [
//	{ name:<string>, components:<int>, type:<gl.FLOAT etc.> }
//]
function createInstances(gl, fields, count=0) {
	assert(fields, "missing instance fields template");
	// generate byte offsets for the fields
	let bytestride = 0;
	for (let field of fields) {
		field.type = field.type || gl.FLOAT;
		field.components = field.components || 1;
		field.byteoffset = bytestride;
		field.bytesize = field.components * byteSizeForGLType(gl, field.type);
		bytestride += field.bytesize;
	}

	let instances = {
		id: gl.createBuffer(),
        count: count, // how many to render
        allocated: 0, // how many are allocated
		fields: fields,
		bytestride: bytestride,
		instances: [],
		data: null,

        // this will (re)allocate memory as needed for the count
        // if there was existing data in the arraybuffer, it will be copied over
		allocate(qty=1) {
            assert(qty > 0, "allocation requires an instance count")
            if (qty > this.allocated) {
                // need to allocate more space:
                const existingdata = this.data;
                const existingcount = this.allocated;
                this.data = new ArrayBuffer(this.bytestride * qty);
                this.allocated = qty;
                // copy any existing data:
                if (existingdata) {
                    new Uint8Array(this.data).set(new Uint8Array(existingdata));
                }

                // create interfaces for the instances:
                for (let i=0; i<this.allocated; i++) {
                    let byteoffset = i * this.bytestride;
                    let obj = this.instances[i];
                    if (i >= existingcount) {
                        // allocate new object:
                        obj = {
                            index: i,
                            byteoffset: byteoffset,
                        }
                        this.instances[i] = obj;
                    }
                    // map fields to the new arraybuffer:
                    for (let field of this.fields) {
                        obj[field.name] = new Float32Array(this.data, byteoffset + field.byteoffset, field.components);
                    }
                }
                this.instances.length = this.allocated;
            } 
            // can't render more than we have:
            this.count = Math.min(this.count, this.allocated);
			return this;
		},

		bind() {
			gl.bindBuffer(gl.ARRAY_BUFFER, this.id)
			return this;
		},

		// bind first:
		submit() {
			gl.bufferData(gl.ARRAY_BUFFER, this.data, gl.DYNAMIC_DRAW);
			return this;
		},
        
        // bind first:
        getData() {
            gl.getBufferData(gl.ARRAY_BUFFER, this.data)
        },

		unbind() {
			gl.bindBuffer(gl.ARRAY_BUFFER, null);
			return this;
		},

		attachTo(vao, instanced=true) {
			vao.bind().setAttributes(this.id, this.bytestride, this.fields, instanced).unbind();
			return this;
		},
        
        dispose() {
            gl.deleteBuffers(this.id)
        },
	}

	if (count) instances.allocate(count);

	return instances;
}

function createSlab(gl, fragCode, uniforms) {
    let vertCode = `#version 300 es
in vec4 a_position;
in vec2 a_texCoord;
out vec2 v_texCoord;
void main() {
    gl_Position = a_position;
    v_texCoord = a_texCoord;
}`
    let program = makeProgramFromCode(gl, vertCode, fragCode);
    let self = {
        program: program,
        quad: createQuadVao(gl, program),
        uniforms: uniformsFromCode(gl, program, vertCode + fragCode),

        uniform(name, ...args) {
            let setter = this.uniforms[name]
            if (!setter) {
                console.error("uniform not found", name, this)
            }
            setter.set.apply(this, args);
            return this;
        },

        setuniforms(dict) {
            this.use();
            for (let k in dict) {
                //this.uniforms[k].set.apply(this, dict[k]);
                this.uniform(k, dict[k])
            }
            return this;
        },

        begin() {
            gl.useProgram(this.program);
            return this;
        },

        end() {
            gl.useProgram(null);
            return this;
        },

        draw() {
            this.quad.bind().draw();
            return this;
        },

        dispose() {
            //this.program.dispose()
            if (this.program) gl.deleteProgram(this.program);
            this.quad.dispose()
        },
    };
    self.begin();
    if (uniforms) self.setuniforms(uniforms);
    self.end()
    return self;
}

function makeCube(options) {
    let opt = options || {}
    let min = opt.min;
    if (min == undefined) min = -1;
    if (typeof min == "number") min = [min, min, min];
    let max = opt.max; if (max == undefined) max = +1;
    if (typeof max == "number") max = [max, max, max];
    let div = opt.div; if (div == undefined) div = 1;
    if (typeof div == "number") div = [div, div, div];
    let span = [max[0]-min[0], max[1]-min[1], max[2]-min[2]];
    let step = [1/div[0], 1/div[1], 1/div[2]];
    let vertices = [];
    let normals = [];
    let texCoords = [];
    let indices = [];
    // front & back
    for (let y=0; y<div[1]; y++) {
        let ay = step[1] * y;
        let by = ay + step[1];
        let vay = min[1] + ay*span[1];
        let vby = min[1] + by*span[1];
        for (let x=0; x<div[0]; x++) {
            let ax = step[0] * x;
            let bx = ax + step[0];
            let vax = min[0] + ax*span[0];
            let vbx = min[0] + bx*span[0];
            let idx = vertices.length/3;
            vertices.push(
                // front:
                vax, vay, max[2],
                vbx, vay, max[2],
                vbx, vby, max[2],
                vax, vby, max[2],
                // back:
                vax, vay, min[2],
                vbx, vay, min[2],
                vbx, vby, min[2],
                vax, vby, min[2]
            );
            texCoords.push(
                // front:
                ax, ay,
                bx, ay,
                bx, by,
                ax, by,
                // // back:
                1-ax, ay,
                1-bx, ay,
                1-bx, by,
                1-ax, by
            );
            normals.push(
                // front:
                0, 0, 1,
                0, 0, 1,
                0, 0, 1,
                0, 0, 1,
                // back:
                0, 0, -1,
                0, 0, -1,
                0, 0, -1,
                0, 0, -1,
            );
            indices.push(
                // front:
                idx+0, idx+1, idx+2,
                idx+2, idx+3, idx+0,
                // back:
                idx+4, idx+6, idx+5,
                idx+7, idx+6, idx+4,
            );
        }
    }
    // top & bottom:
    for (let y=0; y<div[2]; y++) {
        let ay = step[2] * y;
        let by = ay + step[2];
        let vay = min[2] + ay*span[2];
        let vby = min[2] + by*span[2];
        for (let x=0; x<div[0]; x++) {
            let ax = step[0] * x;
            let bx = ax + step[0];
            let vax = min[0] + ax*span[0];
            let vbx = min[0] + bx*span[0];
            let idx = vertices.length/3;
            vertices.push(
                // up:
                vax, max[1], vay, 
                vbx, max[1], vay, 
                vbx, max[1], vby,
                vax, max[1], vby,
                // down:
                vax, min[1], vay, 
                vbx, min[1], vay,
                vbx, min[1], vby, 
                vax, min[1], vby
            );
            texCoords.push(
                // // up:
                1-ax, ay,
                1-bx, ay,
                1-bx, by,
                1-ax, by,
                // // down:
                ax, ay,
                bx, ay,
                bx, by,
                ax, by
            );
            normals.push(
                // up:
                0, 1, 0,
                0, 1, 0,
                0, 1, 0,
                0, 1, 0,
                // down:
                0, -1, 0,
                0, -1, 0,
                0, -1, 0,
                0, -1, 0
            );
            indices.push(
                idx+0, idx+2, idx+1,
                idx+3, idx+2, idx+0,
                idx+4, idx+5, idx+6,
                idx+6, idx+7, idx+4
            );
        }
    }
    // left & right:
    for (let y=0; y<div[2]; y++) {
        let ay = step[2] * y;
        let by = ay + step[2];
        let vay = min[2] + ay*span[2];
        let vby = min[2] + by*span[2];
        for (let x=0; x<div[1]; x++) {
            let ax = step[1] * x;
            let bx = ax + step[1];
            let vax = min[1] + ax*span[1];
            let vbx = min[1] + bx*span[1];
            let idx = vertices.length/3;
            vertices.push(
                // right:
                max[0], vax, vay, 
                max[0], vbx, vay, 
                max[0], vbx, vby,
                max[0], vax, vby,
                // left:
                min[0], vax, vay, 
                min[0], vbx, vay,
                min[0], vbx, vby, 
                min[0], vax, vby
            );
            texCoords.push(
                // // right:
                1-ax, 1-ay,
                1-bx, 1-ay,
                1-bx, 1-by,
                1-ax, 1-by,
                // // left:
                ax, 1-ay,
                bx, 1-ay,
                bx, 1-by,
                ax, 1-by
                // ax, ay,
                // bx, ay,
                // bx, by,
                // ax, by
            );
            normals.push(
                // right:
                1, 0, 0,
                1, 0, 0,
                1, 0, 0,
                1, 0, 0,
                // left:
                -1, 0, 0,
                -1, 0, 0,
                -1, 0, 0,
                -1, 0, 0
            );
            indices.push(
                idx+0, idx+1, idx+2,
                idx+2, idx+3, idx+0,
                idx+4, idx+6, idx+5,
                idx+7, idx+6, idx+4
            );
        }
    }
	return {
		vertexComponents: 3,
		vertices: new Float32Array(vertices),
		normals: new Float32Array(normals),
		texCoords: new Float32Array(texCoords),
		indices: new Uint32Array(indices),
	}
}

/*
options: {
    min: -1, // base height
    max: 1,  // top height
    div: [4, 1] // cols, rows
    radius: 1
}
*/
function makeOpenCylinder(options) {
    let opt = options || {}
    let min = opt.min; if (min == undefined) min = -1;
    let max = opt.max; if (max == undefined) max = +1;
    let div = opt.div; if (div == undefined) div = [4,1];
    if (typeof div == "number") div = [div, div];
    let radius = opt.radius; if (radius == undefined) radius = 1;
    let step = [1/div[0], 1/div[1]];
    let span = max-min;
    let vertices = [];
    let normals = [];
    let texCoords = [];
    let indices = [];

    // rows
    for (let y=0; y<div[1]; y++) {
        let ay = step[1] * y;
        let by = ay + step[1];
        let vay = min + ay*span;
        let vby = min + by*span;
        for (let x=0; x<div[0]; x++) {
            let ax = step[0] * x;
            let bx = ax + step[0];
            let nax = Math.sin(Math.PI * 2 * (ax))
            let naz = Math.cos(Math.PI * 2 * (ax))
            let nbx = Math.sin(Math.PI * 2 * (bx))
            let nbz = Math.cos(Math.PI * 2 * (bx))

            let vax = radius * nax
            let vaz = radius * naz
            let vbx = radius * nbx
            let vbz = radius * nbz

            let idx = vertices.length/3;
            vertices.push(
                vax, vay, vaz,
                vbx, vay, vbz,
                vbx, vby, vbz,
                vax, vby, vaz
            ); 
            texCoords.push(
                ax, ay,
                bx, ay,
                bx, by,
                ax, by
            );
            normals.push(
                nax, 0, naz,
                nbx, 0, nbz,
                nbx, 0, nbz,
                nax, 0, naz
            );
            indices.push(
                idx+0, idx+1, idx+2,
                idx+2, idx+3, idx+0
            );
        }
    }

	return {
		vertexComponents: 3,
		vertices: new Float32Array(vertices),
		normals: new Float32Array(normals),
		texCoords: new Float32Array(texCoords),
		indices: new Uint32Array(indices),
	}
}

function makeQuad(options) {
    let opt = options || {}
    let min = opt.min;
    if (min == undefined) min = -1;
    if (typeof min == "number") min = [min, min];
    let max = opt.max; if (max == undefined) max = +1;
    if (typeof max == "number") max = [max, max];
    let div = opt.div; if (div == undefined) div = 1;
    if (typeof div == "number") div = [div, div];
    let span = [max[0]-min[0], max[1]-min[1]];
    let step = [1/div[0], 1/div[1]];
    let flipY = opt.flipY
    let vertices = [];
    let normals = [];
    let texCoords = [];
    let indices = [];
    for (let y=0; y<div[1]; y++) {
        let ay = step[1] * y;
        let by = ay + step[1];
        let vay = min[1] + ay*span[1];
        let vby = min[1] + by*span[1];
        for (let x=0; x<div[0]; x++) {
            let ax = step[0] * x;
            let bx = ax + step[0];
            let vax = min[0] + ax*span[0];
            let vbx = min[0] + bx*span[0];
            let idx = vertices.length/2;
            vertices.push(
                vax, vay,
                vbx, vay,
                vbx, vby,
                vax, vby
            );
            texCoords.push(
                ax, flipY ? 1-ay : ay,
                bx, flipY ? 1-ay : ay,
                bx, flipY ? 1-by : by,
                ax, flipY ? 1-by : by
            );
            normals.push(
                0, 0, 1,
                0, 0, 1,
                0, 0, 1,
                0, 0, 1
            );
            indices.push(
                idx+0, idx+1, idx+2,
                idx+2, idx+3, idx+0
            );
        }
    }

	return {
		vertexComponents: 2,
		vertices: new Float32Array(vertices),
		normals: new Float32Array(normals),
		texCoords: new Float32Array(texCoords),
		indices: new Uint32Array(indices),
	}
}

function makeQuad3D(options) {
    let opt = options || {}
    let min = opt.min;
    if (min == undefined) min = -1;
    if (typeof min == "number") min = [min, min];
    let max = opt.max; if (max == undefined) max = +1;
    if (typeof max == "number") max = [max, max];
    let div = opt.div; if (div == undefined) div = 1;
    if (typeof div == "number") div = [div, div];

    let span = [max[0]-min[0], max[1]-min[1]];
    let step = [1/div[0], 1/div[1]];
    let vertices = [];
    let normals = [];
    let texCoords = [];
    let indices = [];
    for (let y=0; y<div[1]; y++) {
        let ay = step[1] * y;
        let by = ay + step[1];
        let vay = min[1] + ay*span[1];
        let vby = min[1] + by*span[1];
        for (let x=0; x<div[0]; x++) {
            let ax = step[0] * x;
            let bx = ax + step[0];
            let vax = min[0] + ax*span[0];
            let vbx = min[0] + bx*span[0];
            let idx = vertices.length/3;
            vertices.push(
                vax, vay, 0,
                vbx, vay, 0,
                vbx, vby, 0,
                vax, vby, 0
            );
            texCoords.push(
                ax, ay,
                bx, ay,
                bx, by,
                ax, by
            );
            normals.push(
                0, 0, 1,
                0, 0, 1,
                0, 0, 1,
                0, 0, 1
            );
            indices.push(
                idx+0, idx+1, idx+2,
                idx+2, idx+3, idx+0
            );
        }
    }

	return {
		vertexComponents: 3,
		vertices: new Float32Array(vertices),
		normals: new Float32Array(normals),
		texCoords: new Float32Array(texCoords),
		indices: new Uint32Array(indices),
	}
}

// by default, a simple line segment from [0,0,0] to [1,0,0]
function makeLine(options) {
    let opt = options || {}
    let min = opt.min; if (min == undefined) min = 0;
    let max = opt.max; if (max == undefined) max = 1;
    let div = opt.div; if (div == undefined) div = 1;
    let span = max-min;
    let step = 1/div;
    let vertices = [];
    let normals = [];
    let texCoords = [];
    let indices = [];
        for (let x=0; x<div; x++) {
            let a = step * x;
            let b = a + step;
            let va = min + a*span;
            let vb = min + b*span;
            let idx = vertices.length/1;
            vertices.push(
                va,
                vb
            );
            texCoords.push(
                a, a,
                b, a
            );
            // do normals even make sense?
            // perhaps it needs tangents also... 
            // normals.push(
            //     0, 1, 0,
            //     0, 1, 0
            // );
            indices.push(
                idx+0, idx+1
            );
        }

	return {
		vertexComponents: 1,
		vertices: new Float32Array(vertices),
		//normals: new Float32Array(normals),
		texCoords: new Float32Array(texCoords),
		indices: new Uint32Array(indices),
	}
}

function geomFromOBJ(objcode, options) {
    // create a normal per face
    options = options || {}
    let facenormals = options.facenormals
    // do not re-use vertices, unique vertex per triangle point
    // this is necessary for per face normals
    let soup = facenormals || options.soup
	let lines = objcode.split(/\r\n|\n/)
    let vertices = []
    let gvertices = []
	let normals = []
    let gnormals = []
	let texCoords = []
	let gtexCoords = []
    let colors = []
    let gcolors = []
	let memo = {}
	let gindices = []
	let indexcount=0;
	for (let line of lines) {
		if (line.substring(0,2) == "vn") {
			let match = line.match(/vn\s+([0-9.e-]+)\s+([0-9.e-]+)\s+([0-9.e-]+)/)
			normals.push([+match[1], +match[2], +match[3]])
		} else if (line.substring(0,2) == "vt") {
            let match = line.match(/vt\s+([0-9.e-]+)\s+([0-9.e-]+)/)
            texCoords.push([+match[1], +match[2]])
		} else if (line.substring(0,1) == "v") {
            let match = line.match(/v\s+([0-9.e-]+)\s+([0-9.e-]+)\s+([0-9.e-]+)(\s+([0-9.e-]+)\s+([0-9.e-]+)\s+([0-9.e-]+))?/)
            vertices.push([+match[1], +match[2], +match[3]])
            if (match[4]) colors.push([+match[5], +match[6], +match[7]])
		} else if (line.substring(0,1) == "f") {
			let face = []
            let fn = [] // vertices for face normal calculation
            let fncount = 0
			let match
            // this only works for v/vt/vn input
			let regex = /([0-9]+)\s*(\/\s*([0-9]*))?\s*(\/\s*([0-9]*))?/g
			while (match = regex.exec(line)) {
                let V = match[1]
                let T = match[3]
                let N = match[5]
				let name = `${V}/${T}/${N}`
				let id = memo[name]
			 	if (soup || id == undefined) {
					// a new vertex/normal/texcoord combo, create a new entry for it
					id = indexcount;
					let v = vertices[(+V)-1]
                    gvertices.push(v[0], v[1], v[2])
                    let c = colors[(+V)-1]
                    if (c) gcolors.push(c[0], c[1], c[2], 1)
                    if (T && texCoords.length) {
                        let vt = texCoords[(+T)-1]
                        gtexCoords.push(vt[0], vt[1])
                    }
                    if (N && normals.length) {
                        if (facenormals) {
                            fn.push(v)
                            //vec3.add(fn, fn, normals[(+N)-1])
                            fncount++
                        }
                        else {
                            let vn = normals[(+N)-1]
                            gnormals.push(vn[0], vn[1], vn[2])
                        }
                    } 
					memo[name] = id;
					indexcount++;
				}
				if (face.length >= 3) {
					// triangle strip
					//face.push(face[face.length-1], face[face.length-2]);
					// triangle fan poly
					face.push(face[face.length-1], face[0]);
				}
 				face.push(id);
			}
            if (facenormals && fncount) {

                // can't we just use the first 3 positions to get a normal
                // then apply this for all?
                let u = vec3.sub(vec3.create(), fn[1], fn[0])
                //vec3.normalize(u, u)
                let v = vec3.sub(vec3.create(), fn[2], fn[0])
                //vec3.normalize(u, u)
                let n = vec3.cross(vec3.create(), u, v)

                //console.log(n)

                vec3.normalize(n, n)
                for (let i=0; i<fncount; i++) {
                    gnormals.push(n[0], n[1], n[2])
                }
            }
			for (let id of face) {
				gindices.push(id);
			}
		} else {
			//console.log("ignored", line)
		}

    }
    let geom = {
        vertices: new Float32Array(gvertices)
    }
	if (gnormals.length) geom.normals = new Float32Array(gnormals)
	if (gtexCoords.length) geom.texCoords = new Float32Array(gtexCoords)
	if (gindices.length) {
        geom.indices = new Uint32Array(gindices)
    }
    if (gcolors.length) geom.colors = new Float32Array(gcolors)
	return geom
}

function geomToOBJ(geom) {
    /*
        geom could have 2 or 3 vertexComponents
        must have .vertices, might have normals, texCoords, probably has indices
        if we have .colors, append to vertices (xyzrgb)

    */
    let { vertexComponents, vertices, normals, texCoords, indices, colors } = geom
    let lines = []
    let numverts = vertices.length / vertexComponents
    // for each vertex... 
    for (let i=0; i<vertices.length; i+= vertexComponents) {
        let vs = Array.from(vertices.slice(i, i+vertexComponents)).map(s => Number(s))
        if (colors) {
            vs = vs.concat(Array.from(colors.slice(i*4/vertexComponents, i*4/vertexComponents+3)).map(s => Number(s)))
        }
        lines.push(`v ${vs.join(" ")}`)
    }

    for (let i=0; i<texCoords.length; i+= 2) {
        let vs = Array.from(texCoords.slice(i, i+2)).map(s => Number(s))
        lines.push(`vt ${vs.join(" ")}`)
    }

    for (let i=0; i<normals.length; i+= 3) {
        let vs = Array.from(normals.slice(i, i+3)).map(s => Number(s))
        lines.push(`vn ${vs.join(" ")}`)
    }

    for (let i=0; i<indices.length; i+=3) {
        let is = Array.from(indices.slice(i, i+3)).map(s => Number(s) + 1).map(n => `${n}/${n}/${n}`)
        lines.push(`f ${is.join(" ")}`)
    }

    return lines.join("\n")
}

function geomAddColors(geom) {
    let vc = geom.vertexComponents || 3
    let numverts = geom.vertices.length / vc
    geom.colors = new Float32Array(4 * numverts)
    return geom
}

function geomSetAllNormals(geom, normal) {
    let vc = geom.vertexComponents || 3
    let numverts = geom.vertices.length / vc
    let normals = geom.normals
    if (!geom.normals) {
        // create:
        normals = new Float32Array(numverts * 3)
        geom.normals = normals
    }
    for (let i=0; i<normals.length; i+= 3) {
        normals[i+0] = normal[0]
        normals[i+1] = normal[1]
        normals[i+2] = normal[2]
    }
    return geom
}

// m4 should be a mat4
// geom should have vertexComponents 3+
function geomTransform(geom, m4) {
    // apply mat4 mat to all vertices:
    let vc = geom.vertexComponents || 3
    if (vc < 3) console.log("warning: transforming a 2D geom with a mat4 may not work as intended")

    if (vc==3) {
        for (let i=0; i<geom.vertices.length; i+=vc) {
            let v = new Float32Array(geom.vertices.buffer, i*4, vc);
            vec3.transformMat4(v, v, m4)
        }
    } else if (vc==4) {
        for (let i=0; i<geom.vertices.length; i+=vc) {
            let v = new Float32Array(geom.vertices.buffer, i*4, vc);
            vec4.transformMat4(v, v, m4)
        }
    }

    if (geom.normals) {
        let m3 = mat3.fromMat4(mat3.create(), m4)
        let fr = mat3.frob(m3);
        mat3.multiplyScalar(m3, m3, 1/fr)
        for (let i=0; i<geom.normals.length; i+=3) {
            let v = new Float32Array(geom.normals.buffer, i*4, 3);
            vec3.transformMat3(v, v, m3)
        }
    }
    return geom
}

function geomTexTransform(geom, m3) {
    if (!geom.texCoords) {
        console.error("geom has no texCoords to transform")
    }
    for (let i=0; i<geom.texCoords.length; i+=2) {
        let v = new Float32Array(geom.texCoords.buffer, i*4, 2);
        vec2.transformMat3(v, v, m3)
    }
    return geom
}

function geomMergeTwo(A, B) {
    assert(!!A.indices === !!B.indices, "can't merge geometries if only one of them uses indices")
    assert(!!A.normals === !!B.normals, "can't merge geometries if only one of them uses normals")
    assert(!!A.texCoords === !!B.texCoords, "can't merge geometries if only one of them uses texCoords")
    assert(A.vertexComponents === B.vertexComponents, "can't merge if the vertex components don't match")
    
    let C = {
        vertexComponents: A.vertexComponents,
    }

    // indicies are a special case:
    if (A.indices) {
        const ni = A.indices.length
        const offset = A.vertices.length/A.vertexComponents;
        C.indices = new Uint32Array(A.indices.length + B.indices.length)
        C.indices.set(A.indices)
        for (let i=0; i<B.indices.length; i++) {
            C.indices[ni + i] = B.indices[i] + offset
        }
    }
    for (let k of ["vertices", "normals", "texCoords", "colors"]) {
        if (A[k] && B[k]) {
            C[k] = new Float32Array(A[k].length + B[k].length)
            C[k].set(A[k])
            C[k].set(B[k], A[k].length)
        }
    }
    return C;
}


// merge another geom into self:
function geomAppend(self, other) {
    assert(!!self.indices === !!other.indices, "can't merge geometries if only one of them uses indices")
    assert(!!self.normals === !!other.normals, "can't merge geometries if only one of them uses normals")
    assert(!!self.texCoords === !!other.texCoords, "can't merge geometries if only one of them uses texCoords")
    // indicies are a special case:
    if (self.indices && other.indices) {
        const ni = self.indices.length
        const offset = self.vertices.length/self.vertexComponents;
        const ar = new Uint32Array(ni + other.indices.length)
        ar.set(self.indices)
        for (let i=0; i<other.indices.length; i++) {
            ar[ni + i] = other.indices[i] + offset
        }
        self.indices = ar;
    }
    for (let k of ["vertices", "normals", "texCoords", "colors"]) {
        if (self[k] && other[k]) {
            const ar = new Float32Array(self[k].length + other[k].length)
            ar.set(self[k])
            ar.set(other[k], self[k].length)
            self[k] = ar;
        }
    }

    
    return self;
}

// merge a list of geoms:
function geomMerge(...geoms) {
    geoms = geoms.flat()
    if (geoms.length < 2) return geoms[0]

    let result = geomMergeTwo(geoms.shift(), geoms.shift())
    while (geoms.length) {
        geomAppend(result, geoms.shift())
    }
    
    return result;
}

// get the rotation that will turn `q` 
// so that its local `fwd` vector 
// points in the same direction as `dir`
function quat_rotation_to(out, q, dir, fwd=[0,0,-1]) {
	let v = vec3.create()
	let axis = vec3.create()
	// viewer's look direction in world space
	vec3.transformQuat(v, fwd, q); 
	// axis of rotation (not normalized)
	vec3.cross(axis, v, dir);
	let la = vec3.length(axis);
	let ld = vec3.length(dir); 
	// skips rotation if a) we are too close, 
	// or b) we are pointing in opposite directions
	if (ld > 0.000001 && la > 0.000001) {
		let sin_a = la / ld;
		let cos_a = vec3.dot(v, dir) / ld;
		let a = Math.atan2(sin_a, cos_a)
		// n becomes axis, but must first be normalized:
		vec3.scale(axis, axis, 1/la)
		quat.setAxisAngle(out, axis, a);
	} else {
		quat.identity(out);
	}
	return out
}

    
    //	q must be a normalized quaternion
  function quat_rotate(out, q, v) {
    let p = vec4.fromValues(
      q[3] * v[0] + q[1] * v[2] - q[2] * v[1], // x
      q[3] * v[1] + q[2] * v[0] - q[0] * v[2], // y
      q[3] * v[2] + q[0] * v[1] - q[1] * v[0], // z
      -q[0] * v[0] - q[1] * v[1] - q[2] * v[2] // w
    );
    return vec3.set(
      out,
      p[0] * q[3] - p[3] * q[0] + p[2] * q[1] - p[1] * q[2], // x
      p[1] * q[3] - p[3] * q[1] + p[0] * q[2] - p[2] * q[0], // y
      p[2] * q[3] - p[3] * q[2] + p[1] * q[0] - p[0] * q[1] // z
    );
  }
  
  // equiv. quat_rotate(quat_conj(q), v):
  // q must be a normalized quaternion
  function quat_unrotate(out, q, v) {
    // return quat_mul(quat_mul(quat_conj(q), vec4(v, 0)), q)[0]yz;
    // reduced:
    let p = vec4.fromValues(
      q[3] * v[0] - q[1] * v[2] + q[2] * v[1], // x
      q[3] * v[1] - q[2] * v[0] + q[0] * v[2], // y
      q[3] * v[2] - q[0] * v[1] + q[1] * v[0], // z
      q[0] * v[0] + q[1] * v[1] + q[2] * v[2] // w
    );
    return vec3.set(
      out,
      p[3] * q[0] + p[0] * q[3] + p[1] * q[2] - p[2] * q[1], // x
      p[3] * q[1] + p[1] * q[3] + p[2] * q[0] - p[0] * q[2], // y
      p[3] * q[2] + p[2] * q[3] + p[0] * q[1] - p[1] * q[0] // z
    );
  }

  function quat_fromAxisAngle(q, axis, angle) {
    let ax = vec3.normalize([0, 0, 0], axis);
    let c = Math.cos(0.5 * angle);
    let s = Math.sqrt(1.0 - c*c); 
    return quat.set(q, ax[0] * s, ax[1] * s, ax[2] * s, c);
  }
    
  function createCheckerTexture(gl, texSize = 8) 
  {
    let texture = gl.createTexture();
    gl.bindTexture( gl.TEXTURE_2D, texture );
    let texData = new Uint8Array(texSize * texSize * 4);
    for (let i=0; i<texSize; i++) {
      for (let j=0; j<texSize; j++) {
        let idx = (i*texSize + j) * 4;
        let val = 255 * ((i + j) % 2);
        texData[idx+0] = val;
        texData[idx+1] = val;
        texData[idx+2] = val;
        texData[idx+3] = 255;
      }
    }
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, texSize, texSize, 0, gl.RGBA, gl.UNSIGNED_BYTE, texData);
    gl.generateMipmap( gl.TEXTURE_2D );
    gl.texParameteri( gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.NEAREST_MIPMAP_LINEAR );
    gl.texParameteri( gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.NEAREST);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_T, gl.CLAMP_TO_EDGE);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_WRAP_S, gl.CLAMP_TO_EDGE);
    return texture;
}

function frustumFromPerspective(fovy, aspect, near, far) {
	let m = near * Math.tan(fovy/2)
	return [-m*aspect, m*aspect, -m, m, near, far]
}

function perspectiveFromFrustum(l, r, b, t, near, far) {
	// note, this assumes the camera is centered in the frame
	// a frustum could be off-axis but the perspective parameters can't
	let fovy = Math.atan2((t - b)/2, near)
	let aspect = (l - r)/(t - b)
	return [fovy, aspect, near, far]
}

// how to create a mat4 directly from a position vector and 3 unit axis vectors
function viewFromUnitVectorsAndPosition(pos, ux, uy, uz) {
	return [
		...ux, 0, 
		...uy, 0, 
		...uz, 0, 
		-pos[0], -pos[1], -pos[2], 1
	]
}

// set a projection matrix and view matrix to render onto an arbitrary plane
// viewmatrix is for the global camera
// a, b, c are the bottom-left, bottom-right, top-left corners of the plane in world space
// near, far are the near & far clip distances
// returns [projmatrix, viewmatrix] you can use to render the scene through the plane
function viewThroughPlane(viewmatrix, A, B, C, near, far) {
	
	// convert world-space plane to view space
	let va = vec3.transformMat4(vec3.create(), A, viewmatrix) 
	let vb = vec3.transformMat4(vec3.create(), B, viewmatrix)
	let vc = vec3.transformMat4(vec3.create(), C, viewmatrix)

	// get the right and up unit vectors of the plane in view space
	let vr = vec3.sub(vec3.create(), vb, va)
	let vu = vec3.sub(vec3.create(), vc, va)
	vec3.normalize(vr, vr)
	vec3.normalize(vu, vu)
	// get the normal unit vector to the plane in view space
	let vn = vec3.cross(vec3.create(), vr, vu)
	vec3.normalize(vn, vn)
	// we now have the plane's coordinate axes in view space

	// Find the distance from the eye to screen plane
	// by projecting one of these vectors along the plane normal 
	// (inverted because normal points out of screen)
	let d = -vec3.dot(va, vn);
	// we need the distance so that we can adapt the plane's field of view accordingly
	// the extents of the near plane are shrunk by perspective
	// which just means divide by distance
	let nd = near / d

	// Find the extents of the frustum at the near plane.
	// here we project the rays from eye to corner along the plane's coordinate axes
	// this gives us the required off-axis shift in the plane
	// then we scale them by our new near 
	let l = vec3.dot(vr, va) * nd;
	let r = vec3.dot(vr, vb) * nd;
	let b = vec3.dot(vu, va) * nd;
	let t = vec3.dot(vu, vc) * nd;
	let projmatrix_plane = mat4.frustum(mat4.create(), l, r, b, t, near, far) 

	// next take us back from the plane to the world (the viewmatrix)
	// rotate the out of the plane's coordinate system
	let rotm = mat4.fromValues(
		vr[0], vu[0], vn[0], 0,
		vr[1], vu[1], vn[1], 0,
		vr[2], vu[2], vn[2], 0,
		0, 0, 0, 1
	)
	// and then relative to world space
	let viewmatrix_plane = mat4.multiply(mat4.create(), rotm, viewmatrix)

	return [projmatrix_plane, viewmatrix_plane]
}

// Euclidean modulo. assumes n > 0
function wrap(a, n) { 
	const r = a % n;
	return r < 0 ? r + n : r; //a % n + (Math.sign(a) !== Math.sign(n) ? n : 0); 
}

// e.g. if n=4, it wraps in the range -4..4
function wrap_relative(a, n) { 
	return wrap(a + n, n*2) - n
}

function vec3_wrap(out, a, n) {
	out[0] = wrap(a[0], n)
	out[1] = wrap(a[1], n)
	out[2] = wrap(a[2], n)
	return out
}

function vec3_wrap_relative(out, a, n) {
	out[0] = wrap_relative(a[0], n)
	out[1] = wrap_relative(a[1], n)
	out[2] = wrap_relative(a[2], n)
	return out
}

module.exports = {

    byteSizeForGLType,

	createShader,
	createProgram,
    createComputeProgram,
	makeProgram,
    makeComputeProgram,
	makeProgramFromCode,
	uniformsFromCode,
	
	makeBuffer,

    loadTexture,
    createTexture,
	createPixelTexture,
	createCheckerTexture,
    createTexture3D,
    img2tex,

	createVao,
    createQuadVao,
    createInstances,

    makeFboWithDepth,
    makeGbuffer,
    makeGbufferPair,

	createFBO,
	createSlab,

	makeCube,
    makeQuad,
    makeQuad3D,
    makeLine,
    makeOpenCylinder,

    geomFromOBJ,
    geomToOBJ,
    geomAppend,
    geomMerge,
    geomTransform,
    geomTexTransform,
    geomSetAllNormals,
    geomAddColors,

	quat_rotate,
    quat_unrotate,
    quat_rotation_to,
    quat_fromAxisAngle,

    wrap, wrap_relative, 
    vec3_wrap, vec3_wrap_relative,
    
    frustumFromPerspective,
    perspectiveFromFrustum,
    viewFromUnitVectorsAndPosition,
    viewThroughPlane,

    ok,
    
    requestAnimationFrame: function(callback, delay=1000/60) {
        let t0 = process.hrtime();
        let timer = ()=>{
            let dt = process.hrtime(t0)
            // dt (in ms):
            let ms = (dt[0]*1e9 + dt[1]) * 1e-6;
            if (ms > delay) {
                callback();
            } else {
                setImmediate(timer);
            }
        }
        timer();
    },

}