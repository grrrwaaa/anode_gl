/* THIS IS A GENERATED FILE -- DO NOT EDIT!! */

#include "node-gles3.h"

napi_value ActiveTexture(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum texture = getUint32(env, args[0]);
	// void glActiveTexture(GLenum texture)
	glActiveTexture(texture);
	return NULL;
}

napi_value AttachShader(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint program = getUint32(env, args[0]);
	GLuint shader = getUint32(env, args[1]);
	// void glAttachShader(GLuint program, GLuint shader)
	glAttachShader(program, shader);
	return NULL;
}

napi_value BindAttribLocation(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint program = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLchar * name = nullptr;
	status = getCharacterArray(env, args[2], name);
	// void glBindAttribLocation(GLuint program, GLuint index, const GLchar *name)
	glBindAttribLocation(program, index, name);
	return NULL;
}

napi_value BindBuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	// void glBindBuffer(GLenum target, GLuint buffer)
	glBindBuffer(target, buffer);
	return NULL;
}

napi_value BindFramebuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLuint framebuffer = getUint32(env, args[1]);
	// void glBindFramebuffer(GLenum target, GLuint framebuffer)
	glBindFramebuffer(target, framebuffer);
	return NULL;
}

napi_value BindRenderbuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLuint renderbuffer = getUint32(env, args[1]);
	// void glBindRenderbuffer(GLenum target, GLuint renderbuffer)
	glBindRenderbuffer(target, renderbuffer);
	return NULL;
}

napi_value BindTexture(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLuint texture = getUint32(env, args[1]);
	// void glBindTexture(GLenum target, GLuint texture)
	glBindTexture(target, texture);
	return NULL;
}

napi_value BlendColor(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLfloat red = getDouble(env, args[0]);
	GLfloat green = getDouble(env, args[1]);
	GLfloat blue = getDouble(env, args[2]);
	GLfloat alpha = getDouble(env, args[3]);
	// void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
	glBlendColor(red, green, blue, alpha);
	return NULL;
}

napi_value BlendEquation(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum mode = getUint32(env, args[0]);
	// void glBlendEquation(GLenum mode)
	glBlendEquation(mode);
	return NULL;
}

napi_value BlendEquationSeparate(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum modeRGB = getUint32(env, args[0]);
	GLenum modeAlpha = getUint32(env, args[1]);
	// void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
	glBlendEquationSeparate(modeRGB, modeAlpha);
	return NULL;
}

napi_value BlendFunc(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum sfactor = getUint32(env, args[0]);
	GLenum dfactor = getUint32(env, args[1]);
	// void glBlendFunc(GLenum sfactor, GLenum dfactor)
	glBlendFunc(sfactor, dfactor);
	return NULL;
}

napi_value BlendFuncSeparate(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum sfactorRGB = getUint32(env, args[0]);
	GLenum dfactorRGB = getUint32(env, args[1]);
	GLenum sfactorAlpha = getUint32(env, args[2]);
	GLenum dfactorAlpha = getUint32(env, args[3]);
	// void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
	glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
	return NULL;
}

napi_value BufferSubData(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLintptr offset = getInt32(env, args[1]);
	GLsizeiptr size = getUint32(env, args[2]);
	void * data = nullptr;
	status = getTypedArray(env, args[3], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void *data)
	glBufferSubData(target, offset, size, data);
	return NULL;
}

napi_value CheckFramebufferStatus(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum target = getUint32(env, args[0]);
	// GLenum glCheckFramebufferStatus(GLenum target)
	GLenum result = glCheckFramebufferStatus(target);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value Clear(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLbitfield mask = getUint32(env, args[0]);
	// void glClear(GLbitfield mask)
	glClear(mask);
	return NULL;
}

napi_value ClearColor(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLfloat red = getDouble(env, args[0]);
	GLfloat green = getDouble(env, args[1]);
	GLfloat blue = getDouble(env, args[2]);
	GLfloat alpha = getDouble(env, args[3]);
	// void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
	glClearColor(red, green, blue, alpha);
	return NULL;
}

napi_value ClearDepthf(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLfloat d = getDouble(env, args[0]);
	// void glClearDepthf(GLfloat d)
	glClearDepthf(d);
	return NULL;
}

napi_value ClearStencil(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLint s = getInt32(env, args[0]);
	// void glClearStencil(GLint s)
	glClearStencil(s);
	return NULL;
}

napi_value ColorMask(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLboolean red = getBool(env, args[0]);
	GLboolean green = getBool(env, args[1]);
	GLboolean blue = getBool(env, args[2]);
	GLboolean alpha = getBool(env, args[3]);
	// void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
	glColorMask(red, green, blue, alpha);
	return NULL;
}

napi_value CompileShader(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint shader = getUint32(env, args[0]);
	// void glCompileShader(GLuint shader)
	glCompileShader(shader);
	return NULL;
}

napi_value CompressedTexImage2D(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[8];
	size_t argc = checkArgCount(env, info, args, 8, 8);
	GLenum target = getUint32(env, args[0]);
	GLint level = getInt32(env, args[1]);
	GLenum internalformat = getUint32(env, args[2]);
	GLsizei width = getInt32(env, args[3]);
	GLsizei height = getInt32(env, args[4]);
	GLint border = getInt32(env, args[5]);
	GLsizei imageSize = getInt32(env, args[6]);
	void * data = nullptr;
	status = getTypedArray(env, args[7], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data)
	glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
	return NULL;
}

napi_value CompressedTexSubImage2D(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[9];
	size_t argc = checkArgCount(env, info, args, 9, 9);
	GLenum target = getUint32(env, args[0]);
	GLint level = getInt32(env, args[1]);
	GLint xoffset = getInt32(env, args[2]);
	GLint yoffset = getInt32(env, args[3]);
	GLsizei width = getInt32(env, args[4]);
	GLsizei height = getInt32(env, args[5]);
	GLenum format = getUint32(env, args[6]);
	GLsizei imageSize = getInt32(env, args[7]);
	void * data = nullptr;
	status = getTypedArray(env, args[8], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data)
	glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
	return NULL;
}

napi_value CopyTexImage2D(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[8];
	size_t argc = checkArgCount(env, info, args, 8, 8);
	GLenum target = getUint32(env, args[0]);
	GLint level = getInt32(env, args[1]);
	GLenum internalformat = getUint32(env, args[2]);
	GLint x = getInt32(env, args[3]);
	GLint y = getInt32(env, args[4]);
	GLsizei width = getInt32(env, args[5]);
	GLsizei height = getInt32(env, args[6]);
	GLint border = getInt32(env, args[7]);
	// void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
	glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
	return NULL;
}

napi_value CopyTexSubImage2D(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[8];
	size_t argc = checkArgCount(env, info, args, 8, 8);
	GLenum target = getUint32(env, args[0]);
	GLint level = getInt32(env, args[1]);
	GLint xoffset = getInt32(env, args[2]);
	GLint yoffset = getInt32(env, args[3]);
	GLint x = getInt32(env, args[4]);
	GLint y = getInt32(env, args[5]);
	GLsizei width = getInt32(env, args[6]);
	GLsizei height = getInt32(env, args[7]);
	// void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
	glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
	return NULL;
}

napi_value CreateShader(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum type = getUint32(env, args[0]);
	// GLuint glCreateShader(GLenum type)
	GLuint result = glCreateShader(type);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value CullFace(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum mode = getUint32(env, args[0]);
	// void glCullFace(GLenum mode)
	glCullFace(mode);
	return NULL;
}

napi_value DeleteProgram(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint program = getUint32(env, args[0]);
	// void glDeleteProgram(GLuint program)
	glDeleteProgram(program);
	return NULL;
}

napi_value DeleteRenderbuffers(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint * renderbuffers = nullptr;
	status = getTypedArray(env, args[1], renderbuffers);
	// void glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers)
	glDeleteRenderbuffers(n, renderbuffers);
	return NULL;
}

napi_value DeleteShader(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint shader = getUint32(env, args[0]);
	// void glDeleteShader(GLuint shader)
	glDeleteShader(shader);
	return NULL;
}

napi_value DepthFunc(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum func = getUint32(env, args[0]);
	// void glDepthFunc(GLenum func)
	glDepthFunc(func);
	return NULL;
}

napi_value DepthMask(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLboolean flag = getBool(env, args[0]);
	// void glDepthMask(GLboolean flag)
	glDepthMask(flag);
	return NULL;
}

napi_value DepthRangef(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLfloat n = getDouble(env, args[0]);
	GLfloat f = getDouble(env, args[1]);
	// void glDepthRangef(GLfloat n, GLfloat f)
	glDepthRangef(n, f);
	return NULL;
}

napi_value DetachShader(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint program = getUint32(env, args[0]);
	GLuint shader = getUint32(env, args[1]);
	// void glDetachShader(GLuint program, GLuint shader)
	glDetachShader(program, shader);
	return NULL;
}

napi_value Disable(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum cap = getUint32(env, args[0]);
	// void glDisable(GLenum cap)
	glDisable(cap);
	return NULL;
}

napi_value DisableVertexAttribArray(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint index = getUint32(env, args[0]);
	// void glDisableVertexAttribArray(GLuint index)
	glDisableVertexAttribArray(index);
	return NULL;
}

napi_value DrawArrays(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum mode = getUint32(env, args[0]);
	GLint first = getInt32(env, args[1]);
	GLsizei count = getInt32(env, args[2]);
	// void glDrawArrays(GLenum mode, GLint first, GLsizei count)
	glDrawArrays(mode, first, count);
	return NULL;
}

napi_value DrawElements(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum mode = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	void * indices = nullptr;
	status = getTypedArray(env, args[3], *(void **)&indices);
	if (status != napi_ok) return nullptr;
	// void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void *indices)
	glDrawElements(mode, count, type, indices);
	return NULL;
}

napi_value Enable(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum cap = getUint32(env, args[0]);
	// void glEnable(GLenum cap)
	glEnable(cap);
	return NULL;
}

napi_value EnableVertexAttribArray(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint index = getUint32(env, args[0]);
	// void glEnableVertexAttribArray(GLuint index)
	glEnableVertexAttribArray(index);
	return NULL;
}

napi_value Finish(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glFinish(void)
	glFinish();
	return NULL;
}

napi_value Flush(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glFlush(void)
	glFlush();
	return NULL;
}

napi_value FramebufferRenderbuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLenum attachment = getUint32(env, args[1]);
	GLenum renderbuffertarget = getUint32(env, args[2]);
	GLuint renderbuffer = getUint32(env, args[3]);
	// void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
	glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
	return NULL;
}

napi_value FramebufferTexture2D(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLenum attachment = getUint32(env, args[1]);
	GLenum textarget = getUint32(env, args[2]);
	GLuint texture = getUint32(env, args[3]);
	GLint level = getInt32(env, args[4]);
	// void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
	glFramebufferTexture2D(target, attachment, textarget, texture, level);
	return NULL;
}

napi_value FrontFace(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum mode = getUint32(env, args[0]);
	// void glFrontFace(GLenum mode)
	glFrontFace(mode);
	return NULL;
}

napi_value GenBuffers(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint * buffers = nullptr;
	status = getTypedArray(env, args[1], buffers);
	// void glGenBuffers(GLsizei n, GLuint *buffers)
	glGenBuffers(n, buffers);
	return NULL;
}

napi_value GenerateMipmap(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum target = getUint32(env, args[0]);
	// void glGenerateMipmap(GLenum target)
	glGenerateMipmap(target);
	return NULL;
}

napi_value GenFramebuffers(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint * framebuffers = nullptr;
	status = getTypedArray(env, args[1], framebuffers);
	// void glGenFramebuffers(GLsizei n, GLuint *framebuffers)
	glGenFramebuffers(n, framebuffers);
	return NULL;
}

napi_value GenRenderbuffers(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint * renderbuffers = nullptr;
	status = getTypedArray(env, args[1], renderbuffers);
	// void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers)
	glGenRenderbuffers(n, renderbuffers);
	return NULL;
}

napi_value GenTextures(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint * textures = nullptr;
	status = getTypedArray(env, args[1], textures);
	// void glGenTextures(GLsizei n, GLuint *textures)
	glGenTextures(n, textures);
	return NULL;
}

napi_value GetActiveAttrib(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLuint program = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLsizei bufSize = getInt32(env, args[2]);
	GLsizei length_result;
	GLsizei * length = &length_result;
	GLint size_result;
	GLint * size = &size_result;
	GLenum type_result;
	GLenum * type = &type_result;
	GLchar * name;
	status = getTypedArray(env, args[6], name);
	// void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
	glGetActiveAttrib(program, index, bufSize, length, size, type, name);
	return NULL;
}

napi_value GetActiveUniform(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLuint program = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLsizei bufSize = getInt32(env, args[2]);
	GLsizei length_result;
	GLsizei * length = &length_result;
	GLint size_result;
	GLint * size = &size_result;
	GLenum type_result;
	GLenum * type = &type_result;
	GLchar * name;
	status = getTypedArray(env, args[6], name);
	// void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
	glGetActiveUniform(program, index, bufSize, length, size, type, name);
	return NULL;
}

napi_value GetAttachedShaders(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint program = getUint32(env, args[0]);
	GLsizei maxCount = getInt32(env, args[1]);
	GLsizei count_result;
	GLsizei * count = &count_result;
	GLuint shaders_result;
	GLuint * shaders = &shaders_result;
	// void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders)
	glGetAttachedShaders(program, maxCount, count, shaders);
	return NULL;
}

napi_value GetBooleanv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLboolean data_result;
	GLboolean * data = &data_result;
	// void glGetBooleanv(GLenum pname, GLboolean *data)
	glGetBooleanv(pname, data);
	return NULL;
}

napi_value GetBufferParameteriv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint params_result;
	GLint * params = &params_result;
	// void glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params)
	glGetBufferParameteriv(target, pname, params);
	return NULL;
}

napi_value GetFloatv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat data_result;
	GLfloat * data = &data_result;
	// void glGetFloatv(GLenum pname, GLfloat *data)
	glGetFloatv(pname, data);
	return NULL;
}

napi_value GetFramebufferAttachmentParameteriv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLenum attachment = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLint params_result;
	GLint * params = &params_result;
	// void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params)
	glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
	return NULL;
}

napi_value GetProgramiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint program = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint params_result;
	GLint * params = &params_result;
	// void glGetProgramiv(GLuint program, GLenum pname, GLint *params)
	glGetProgramiv(program, pname, params);
	return NULL;
}

napi_value GetRenderbufferParameteriv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint params_result;
	GLint * params = &params_result;
	// void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params)
	glGetRenderbufferParameteriv(target, pname, params);
	return NULL;
}

napi_value GetShaderiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint shader = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint params_result;
	GLint * params = &params_result;
	// void glGetShaderiv(GLuint shader, GLenum pname, GLint *params)
	glGetShaderiv(shader, pname, params);
	return NULL;
}

napi_value GetShaderPrecisionFormat(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum shadertype = getUint32(env, args[0]);
	GLenum precisiontype = getUint32(env, args[1]);
	GLint range_result;
	GLint * range = &range_result;
	GLint precision_result;
	GLint * precision = &precision_result;
	// void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision)
	glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
	return NULL;
}

napi_value GetShaderSource(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint shader = getUint32(env, args[0]);
	GLsizei bufSize = getInt32(env, args[1]);
	GLsizei length_result;
	GLsizei * length = &length_result;
	GLchar * source;
	status = getTypedArray(env, args[3], source);
	// void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source)
	glGetShaderSource(shader, bufSize, length, source);
	return NULL;
}

napi_value GetTexParameterfv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat params_result;
	GLfloat * params = &params_result;
	// void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params)
	glGetTexParameterfv(target, pname, params);
	return NULL;
}

napi_value GetTexParameteriv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint params_result;
	GLint * params = &params_result;
	// void glGetTexParameteriv(GLenum target, GLenum pname, GLint *params)
	glGetTexParameteriv(target, pname, params);
	return NULL;
}

napi_value GetUniformfv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint program = getUint32(env, args[0]);
	GLint location = getInt32(env, args[1]);
	GLfloat params_result;
	GLfloat * params = &params_result;
	// void glGetUniformfv(GLuint program, GLint location, GLfloat *params)
	glGetUniformfv(program, location, params);
	return NULL;
}

napi_value GetUniformiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint program = getUint32(env, args[0]);
	GLint location = getInt32(env, args[1]);
	GLint params_result;
	GLint * params = &params_result;
	// void glGetUniformiv(GLuint program, GLint location, GLint *params)
	glGetUniformiv(program, location, params);
	return NULL;
}

napi_value GetVertexAttribfv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint index = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat params_result;
	GLfloat * params = &params_result;
	// void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params)
	glGetVertexAttribfv(index, pname, params);
	return NULL;
}

napi_value GetVertexAttribiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint index = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint params_result;
	GLint * params = &params_result;
	// void glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params)
	glGetVertexAttribiv(index, pname, params);
	return NULL;
}

napi_value GetVertexAttribPointerv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint index = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	void * pointer_result = nullptr;
	void ** pointer = &pointer_result;
	// void glGetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer)
	glGetVertexAttribPointerv(index, pname, pointer);
	return NULL;
}

napi_value Hint(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLenum mode = getUint32(env, args[1]);
	// void glHint(GLenum target, GLenum mode)
	glHint(target, mode);
	return NULL;
}

napi_value IsBuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint buffer = getUint32(env, args[0]);
	// GLboolean glIsBuffer(GLuint buffer)
	GLboolean result = glIsBuffer(buffer);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value IsEnabled(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum cap = getUint32(env, args[0]);
	// GLboolean glIsEnabled(GLenum cap)
	GLboolean result = glIsEnabled(cap);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value IsFramebuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint framebuffer = getUint32(env, args[0]);
	// GLboolean glIsFramebuffer(GLuint framebuffer)
	GLboolean result = glIsFramebuffer(framebuffer);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value IsProgram(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint program = getUint32(env, args[0]);
	// GLboolean glIsProgram(GLuint program)
	GLboolean result = glIsProgram(program);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value IsRenderbuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint renderbuffer = getUint32(env, args[0]);
	// GLboolean glIsRenderbuffer(GLuint renderbuffer)
	GLboolean result = glIsRenderbuffer(renderbuffer);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value IsShader(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint shader = getUint32(env, args[0]);
	// GLboolean glIsShader(GLuint shader)
	GLboolean result = glIsShader(shader);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value IsTexture(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint texture = getUint32(env, args[0]);
	// GLboolean glIsTexture(GLuint texture)
	GLboolean result = glIsTexture(texture);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value LineWidth(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLfloat width = getDouble(env, args[0]);
	// void glLineWidth(GLfloat width)
	glLineWidth(width);
	return NULL;
}

napi_value LinkProgram(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint program = getUint32(env, args[0]);
	// void glLinkProgram(GLuint program)
	glLinkProgram(program);
	return NULL;
}

napi_value PixelStorei(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint param = getInt32(env, args[1]);
	// void glPixelStorei(GLenum pname, GLint param)
	glPixelStorei(pname, param);
	return NULL;
}

napi_value PolygonOffset(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLfloat factor = getDouble(env, args[0]);
	GLfloat units = getDouble(env, args[1]);
	// void glPolygonOffset(GLfloat factor, GLfloat units)
	glPolygonOffset(factor, units);
	return NULL;
}

napi_value ReadPixels(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLint x = getInt32(env, args[0]);
	GLint y = getInt32(env, args[1]);
	GLsizei width = getInt32(env, args[2]);
	GLsizei height = getInt32(env, args[3]);
	GLenum format = getUint32(env, args[4]);
	GLenum type = getUint32(env, args[5]);
	void * pixels = nullptr;
	status = getTypedArray(env, args[6], *(void **)&pixels);
	if (status != napi_ok) return nullptr;
	// void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels)
	glReadPixels(x, y, width, height, format, type, pixels);
	return NULL;
}

napi_value ReleaseShaderCompiler(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glReleaseShaderCompiler(void)
	glReleaseShaderCompiler();
	return NULL;
}

napi_value RenderbufferStorage(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLsizei width = getInt32(env, args[2]);
	GLsizei height = getInt32(env, args[3]);
	// void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
	glRenderbufferStorage(target, internalformat, width, height);
	return NULL;
}

napi_value SampleCoverage(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLfloat value = getDouble(env, args[0]);
	GLboolean invert = getBool(env, args[1]);
	// void glSampleCoverage(GLfloat value, GLboolean invert)
	glSampleCoverage(value, invert);
	return NULL;
}

napi_value Scissor(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLint x = getInt32(env, args[0]);
	GLint y = getInt32(env, args[1]);
	GLsizei width = getInt32(env, args[2]);
	GLsizei height = getInt32(env, args[3]);
	// void glScissor(GLint x, GLint y, GLsizei width, GLsizei height)
	glScissor(x, y, width, height);
	return NULL;
}

napi_value ShaderBinary(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLsizei count = getInt32(env, args[0]);
	GLuint * shaders = nullptr;
	status = getTypedArray(env, args[1], shaders);
	GLenum binaryformat = getUint32(env, args[2]);
	void * binary = nullptr;
	status = getTypedArray(env, args[3], *(void **)&binary);
	if (status != napi_ok) return nullptr;
	GLsizei length = getInt32(env, args[4]);
	// void glShaderBinary(GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length)
	glShaderBinary(count, shaders, binaryformat, binary, length);
	return NULL;
}

napi_value StencilFunc(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum func = getUint32(env, args[0]);
	GLint ref = getInt32(env, args[1]);
	GLuint mask = getUint32(env, args[2]);
	// void glStencilFunc(GLenum func, GLint ref, GLuint mask)
	glStencilFunc(func, ref, mask);
	return NULL;
}

napi_value StencilFuncSeparate(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum face = getUint32(env, args[0]);
	GLenum func = getUint32(env, args[1]);
	GLint ref = getInt32(env, args[2]);
	GLuint mask = getUint32(env, args[3]);
	// void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
	glStencilFuncSeparate(face, func, ref, mask);
	return NULL;
}

napi_value StencilMask(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint mask = getUint32(env, args[0]);
	// void glStencilMask(GLuint mask)
	glStencilMask(mask);
	return NULL;
}

napi_value StencilMaskSeparate(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum face = getUint32(env, args[0]);
	GLuint mask = getUint32(env, args[1]);
	// void glStencilMaskSeparate(GLenum face, GLuint mask)
	glStencilMaskSeparate(face, mask);
	return NULL;
}

napi_value StencilOp(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum fail = getUint32(env, args[0]);
	GLenum zfail = getUint32(env, args[1]);
	GLenum zpass = getUint32(env, args[2]);
	// void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
	glStencilOp(fail, zfail, zpass);
	return NULL;
}

napi_value StencilOpSeparate(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum face = getUint32(env, args[0]);
	GLenum sfail = getUint32(env, args[1]);
	GLenum dpfail = getUint32(env, args[2]);
	GLenum dppass = getUint32(env, args[3]);
	// void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
	glStencilOpSeparate(face, sfail, dpfail, dppass);
	return NULL;
}

napi_value TexImage2D(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[9];
	size_t argc = checkArgCount(env, info, args, 9, 9);
	GLenum target = getUint32(env, args[0]);
	GLint level = getInt32(env, args[1]);
	GLint internalformat = getInt32(env, args[2]);
	GLsizei width = getInt32(env, args[3]);
	GLsizei height = getInt32(env, args[4]);
	GLint border = getInt32(env, args[5]);
	GLenum format = getUint32(env, args[6]);
	GLenum type = getUint32(env, args[7]);
	void * pixels = nullptr;
	status = getTypedArray(env, args[8], *(void **)&pixels);
	if (status != napi_ok) return nullptr;
	// void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels)
	glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
	return NULL;
}

napi_value TexParameterf(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat param = getDouble(env, args[2]);
	// void glTexParameterf(GLenum target, GLenum pname, GLfloat param)
	glTexParameterf(target, pname, param);
	return NULL;
}

napi_value TexParameterfv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat * params = nullptr;
	status = getTypedArray(env, args[2], params);
	// void glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params)
	glTexParameterfv(target, pname, params);
	return NULL;
}

napi_value TexParameteri(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint param = getInt32(env, args[2]);
	// void glTexParameteri(GLenum target, GLenum pname, GLint param)
	glTexParameteri(target, pname, param);
	return NULL;
}

napi_value TexParameteriv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint * params = nullptr;
	status = getTypedArray(env, args[2], params);
	// void glTexParameteriv(GLenum target, GLenum pname, const GLint *params)
	glTexParameteriv(target, pname, params);
	return NULL;
}

napi_value TexSubImage2D(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[9];
	size_t argc = checkArgCount(env, info, args, 9, 9);
	GLenum target = getUint32(env, args[0]);
	GLint level = getInt32(env, args[1]);
	GLint xoffset = getInt32(env, args[2]);
	GLint yoffset = getInt32(env, args[3]);
	GLsizei width = getInt32(env, args[4]);
	GLsizei height = getInt32(env, args[5]);
	GLenum format = getUint32(env, args[6]);
	GLenum type = getUint32(env, args[7]);
	void * pixels = nullptr;
	status = getTypedArray(env, args[8], *(void **)&pixels);
	if (status != napi_ok) return nullptr;
	// void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels)
	glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
	return NULL;
}

napi_value Uniform1f(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLint location = getInt32(env, args[0]);
	GLfloat v0 = getDouble(env, args[1]);
	// void glUniform1f(GLint location, GLfloat v0)
	glUniform1f(location, v0);
	return NULL;
}

napi_value Uniform1fv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLfloat * value = nullptr;
	status = getTypedArray(env, args[2], value);
	// void glUniform1fv(GLint location, GLsizei count, const GLfloat *value)
	glUniform1fv(location, count, value);
	return NULL;
}

napi_value Uniform1i(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLint location = getInt32(env, args[0]);
	GLint v0 = getInt32(env, args[1]);
	// void glUniform1i(GLint location, GLint v0)
	glUniform1i(location, v0);
	return NULL;
}

napi_value Uniform1iv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLint * value = nullptr;
	status = getTypedArray(env, args[2], value);
	// void glUniform1iv(GLint location, GLsizei count, const GLint *value)
	glUniform1iv(location, count, value);
	return NULL;
}

napi_value Uniform2f(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint location = getInt32(env, args[0]);
	GLfloat v0 = getDouble(env, args[1]);
	GLfloat v1 = getDouble(env, args[2]);
	// void glUniform2f(GLint location, GLfloat v0, GLfloat v1)
	glUniform2f(location, v0, v1);
	return NULL;
}

napi_value Uniform2fv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLfloat * value = nullptr;
	status = getTypedArray(env, args[2], value);
	// void glUniform2fv(GLint location, GLsizei count, const GLfloat *value)
	glUniform2fv(location, count, value);
	return NULL;
}

napi_value Uniform2i(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint location = getInt32(env, args[0]);
	GLint v0 = getInt32(env, args[1]);
	GLint v1 = getInt32(env, args[2]);
	// void glUniform2i(GLint location, GLint v0, GLint v1)
	glUniform2i(location, v0, v1);
	return NULL;
}

napi_value Uniform2iv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLint * value = nullptr;
	status = getTypedArray(env, args[2], value);
	// void glUniform2iv(GLint location, GLsizei count, const GLint *value)
	glUniform2iv(location, count, value);
	return NULL;
}

napi_value Uniform3f(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLint location = getInt32(env, args[0]);
	GLfloat v0 = getDouble(env, args[1]);
	GLfloat v1 = getDouble(env, args[2]);
	GLfloat v2 = getDouble(env, args[3]);
	// void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
	glUniform3f(location, v0, v1, v2);
	return NULL;
}

napi_value Uniform3fv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLfloat * value = nullptr;
	status = getTypedArray(env, args[2], value);
	// void glUniform3fv(GLint location, GLsizei count, const GLfloat *value)
	glUniform3fv(location, count, value);
	return NULL;
}

napi_value Uniform3i(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLint location = getInt32(env, args[0]);
	GLint v0 = getInt32(env, args[1]);
	GLint v1 = getInt32(env, args[2]);
	GLint v2 = getInt32(env, args[3]);
	// void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2)
	glUniform3i(location, v0, v1, v2);
	return NULL;
}

napi_value Uniform3iv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLint * value = nullptr;
	status = getTypedArray(env, args[2], value);
	// void glUniform3iv(GLint location, GLsizei count, const GLint *value)
	glUniform3iv(location, count, value);
	return NULL;
}

napi_value Uniform4f(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLint location = getInt32(env, args[0]);
	GLfloat v0 = getDouble(env, args[1]);
	GLfloat v1 = getDouble(env, args[2]);
	GLfloat v2 = getDouble(env, args[3]);
	GLfloat v3 = getDouble(env, args[4]);
	// void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
	glUniform4f(location, v0, v1, v2, v3);
	return NULL;
}

napi_value Uniform4fv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLfloat * value = nullptr;
	status = getTypedArray(env, args[2], value);
	// void glUniform4fv(GLint location, GLsizei count, const GLfloat *value)
	glUniform4fv(location, count, value);
	return NULL;
}

napi_value Uniform4i(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLint location = getInt32(env, args[0]);
	GLint v0 = getInt32(env, args[1]);
	GLint v1 = getInt32(env, args[2]);
	GLint v2 = getInt32(env, args[3]);
	GLint v3 = getInt32(env, args[4]);
	// void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
	glUniform4i(location, v0, v1, v2, v3);
	return NULL;
}

napi_value Uniform4iv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLint * value = nullptr;
	status = getTypedArray(env, args[2], value);
	// void glUniform4iv(GLint location, GLsizei count, const GLint *value)
	glUniform4iv(location, count, value);
	return NULL;
}

napi_value UseProgram(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint program = getUint32(env, args[0]);
	// void glUseProgram(GLuint program)
	glUseProgram(program);
	return NULL;
}

napi_value ValidateProgram(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint program = getUint32(env, args[0]);
	// void glValidateProgram(GLuint program)
	glValidateProgram(program);
	return NULL;
}

napi_value VertexAttrib1f(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint index = getUint32(env, args[0]);
	GLfloat x = getDouble(env, args[1]);
	// void glVertexAttrib1f(GLuint index, GLfloat x)
	glVertexAttrib1f(index, x);
	return NULL;
}

napi_value VertexAttrib1fv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint index = getUint32(env, args[0]);
	GLfloat * v = nullptr;
	status = getTypedArray(env, args[1], v);
	// void glVertexAttrib1fv(GLuint index, const GLfloat *v)
	glVertexAttrib1fv(index, v);
	return NULL;
}

napi_value VertexAttrib2f(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint index = getUint32(env, args[0]);
	GLfloat x = getDouble(env, args[1]);
	GLfloat y = getDouble(env, args[2]);
	// void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y)
	glVertexAttrib2f(index, x, y);
	return NULL;
}

napi_value VertexAttrib2fv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint index = getUint32(env, args[0]);
	GLfloat * v = nullptr;
	status = getTypedArray(env, args[1], v);
	// void glVertexAttrib2fv(GLuint index, const GLfloat *v)
	glVertexAttrib2fv(index, v);
	return NULL;
}

napi_value VertexAttrib3f(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint index = getUint32(env, args[0]);
	GLfloat x = getDouble(env, args[1]);
	GLfloat y = getDouble(env, args[2]);
	GLfloat z = getDouble(env, args[3]);
	// void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z)
	glVertexAttrib3f(index, x, y, z);
	return NULL;
}

napi_value VertexAttrib3fv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint index = getUint32(env, args[0]);
	GLfloat * v = nullptr;
	status = getTypedArray(env, args[1], v);
	// void glVertexAttrib3fv(GLuint index, const GLfloat *v)
	glVertexAttrib3fv(index, v);
	return NULL;
}

napi_value VertexAttrib4f(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint index = getUint32(env, args[0]);
	GLfloat x = getDouble(env, args[1]);
	GLfloat y = getDouble(env, args[2]);
	GLfloat z = getDouble(env, args[3]);
	GLfloat w = getDouble(env, args[4]);
	// void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
	glVertexAttrib4f(index, x, y, z, w);
	return NULL;
}

napi_value VertexAttrib4fv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint index = getUint32(env, args[0]);
	GLfloat * v = nullptr;
	status = getTypedArray(env, args[1], v);
	// void glVertexAttrib4fv(GLuint index, const GLfloat *v)
	glVertexAttrib4fv(index, v);
	return NULL;
}

napi_value Viewport(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLint x = getInt32(env, args[0]);
	GLint y = getInt32(env, args[1]);
	GLsizei width = getInt32(env, args[2]);
	GLsizei height = getInt32(env, args[3]);
	// void glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
	glViewport(x, y, width, height);
	return NULL;
}

napi_value ReadBuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum src = getUint32(env, args[0]);
	// void glReadBuffer(GLenum src)
	glReadBuffer(src);
	return NULL;
}

napi_value DrawRangeElements(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum mode = getUint32(env, args[0]);
	GLuint start = getUint32(env, args[1]);
	GLuint end = getUint32(env, args[2]);
	GLsizei count = getInt32(env, args[3]);
	GLenum type = getUint32(env, args[4]);
	void * indices = nullptr;
	status = getTypedArray(env, args[5], *(void **)&indices);
	if (status != napi_ok) return nullptr;
	// void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices)
	glDrawRangeElements(mode, start, end, count, type, indices);
	return NULL;
}

napi_value TexImage3D(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[10];
	size_t argc = checkArgCount(env, info, args, 10, 10);
	GLenum target = getUint32(env, args[0]);
	GLint level = getInt32(env, args[1]);
	GLint internalformat = getInt32(env, args[2]);
	GLsizei width = getInt32(env, args[3]);
	GLsizei height = getInt32(env, args[4]);
	GLsizei depth = getInt32(env, args[5]);
	GLint border = getInt32(env, args[6]);
	GLenum format = getUint32(env, args[7]);
	GLenum type = getUint32(env, args[8]);
	void * pixels = nullptr;
	status = getTypedArray(env, args[9], *(void **)&pixels);
	if (status != napi_ok) return nullptr;
	// void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels)
	glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);
	return NULL;
}

napi_value TexSubImage3D(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[11];
	size_t argc = checkArgCount(env, info, args, 11, 11);
	GLenum target = getUint32(env, args[0]);
	GLint level = getInt32(env, args[1]);
	GLint xoffset = getInt32(env, args[2]);
	GLint yoffset = getInt32(env, args[3]);
	GLint zoffset = getInt32(env, args[4]);
	GLsizei width = getInt32(env, args[5]);
	GLsizei height = getInt32(env, args[6]);
	GLsizei depth = getInt32(env, args[7]);
	GLenum format = getUint32(env, args[8]);
	GLenum type = getUint32(env, args[9]);
	void * pixels = nullptr;
	status = getTypedArray(env, args[10], *(void **)&pixels);
	if (status != napi_ok) return nullptr;
	// void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels)
	glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
	return NULL;
}

napi_value CopyTexSubImage3D(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[9];
	size_t argc = checkArgCount(env, info, args, 9, 9);
	GLenum target = getUint32(env, args[0]);
	GLint level = getInt32(env, args[1]);
	GLint xoffset = getInt32(env, args[2]);
	GLint yoffset = getInt32(env, args[3]);
	GLint zoffset = getInt32(env, args[4]);
	GLint x = getInt32(env, args[5]);
	GLint y = getInt32(env, args[6]);
	GLsizei width = getInt32(env, args[7]);
	GLsizei height = getInt32(env, args[8]);
	// void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
	glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
	return NULL;
}

napi_value CompressedTexImage3D(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[9];
	size_t argc = checkArgCount(env, info, args, 9, 9);
	GLenum target = getUint32(env, args[0]);
	GLint level = getInt32(env, args[1]);
	GLenum internalformat = getUint32(env, args[2]);
	GLsizei width = getInt32(env, args[3]);
	GLsizei height = getInt32(env, args[4]);
	GLsizei depth = getInt32(env, args[5]);
	GLint border = getInt32(env, args[6]);
	GLsizei imageSize = getInt32(env, args[7]);
	void * data = nullptr;
	status = getTypedArray(env, args[8], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data)
	glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);
	return NULL;
}

napi_value CompressedTexSubImage3D(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[11];
	size_t argc = checkArgCount(env, info, args, 11, 11);
	GLenum target = getUint32(env, args[0]);
	GLint level = getInt32(env, args[1]);
	GLint xoffset = getInt32(env, args[2]);
	GLint yoffset = getInt32(env, args[3]);
	GLint zoffset = getInt32(env, args[4]);
	GLsizei width = getInt32(env, args[5]);
	GLsizei height = getInt32(env, args[6]);
	GLsizei depth = getInt32(env, args[7]);
	GLenum format = getUint32(env, args[8]);
	GLsizei imageSize = getInt32(env, args[9]);
	void * data = nullptr;
	status = getTypedArray(env, args[10], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data)
	glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
	return NULL;
}

napi_value GenQueries(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint * ids = nullptr;
	status = getTypedArray(env, args[1], ids);
	// void glGenQueries(GLsizei n, GLuint *ids)
	glGenQueries(n, ids);
	return NULL;
}

napi_value DeleteQueries(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint * ids = nullptr;
	status = getTypedArray(env, args[1], ids);
	// void glDeleteQueries(GLsizei n, const GLuint *ids)
	glDeleteQueries(n, ids);
	return NULL;
}

napi_value IsQuery(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint id = getUint32(env, args[0]);
	// GLboolean glIsQuery(GLuint id)
	GLboolean result = glIsQuery(id);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value BeginQuery(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLuint id = getUint32(env, args[1]);
	// void glBeginQuery(GLenum target, GLuint id)
	glBeginQuery(target, id);
	return NULL;
}

napi_value EndQuery(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum target = getUint32(env, args[0]);
	// void glEndQuery(GLenum target)
	glEndQuery(target);
	return NULL;
}

napi_value GetQueryiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint params_result;
	GLint * params = &params_result;
	// void glGetQueryiv(GLenum target, GLenum pname, GLint *params)
	glGetQueryiv(target, pname, params);
	return NULL;
}

napi_value GetQueryObjectuiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint id = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLuint params_result;
	GLuint * params = &params_result;
	// void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint *params)
	glGetQueryObjectuiv(id, pname, params);
	return NULL;
}

napi_value UnmapBuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum target = getUint32(env, args[0]);
	// GLboolean glUnmapBuffer(GLenum target)
	GLboolean result = glUnmapBuffer(target);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value GetBufferPointerv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	void * params_result = nullptr;
	void ** params = &params_result;
	// void glGetBufferPointerv(GLenum target, GLenum pname, void **params)
	glGetBufferPointerv(target, pname, params);
	return NULL;
}

napi_value UniformMatrix2x3fv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLboolean transpose = getBool(env, args[2]);
	GLfloat * value = nullptr;
	status = getTypedArray(env, args[3], value);
	// void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	glUniformMatrix2x3fv(location, count, transpose, value);
	return NULL;
}

napi_value UniformMatrix3x2fv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLboolean transpose = getBool(env, args[2]);
	GLfloat * value = nullptr;
	status = getTypedArray(env, args[3], value);
	// void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	glUniformMatrix3x2fv(location, count, transpose, value);
	return NULL;
}

napi_value UniformMatrix2x4fv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLboolean transpose = getBool(env, args[2]);
	GLfloat * value = nullptr;
	status = getTypedArray(env, args[3], value);
	// void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	glUniformMatrix2x4fv(location, count, transpose, value);
	return NULL;
}

napi_value UniformMatrix4x2fv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLboolean transpose = getBool(env, args[2]);
	GLfloat * value = nullptr;
	status = getTypedArray(env, args[3], value);
	// void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	glUniformMatrix4x2fv(location, count, transpose, value);
	return NULL;
}

napi_value UniformMatrix3x4fv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLboolean transpose = getBool(env, args[2]);
	GLfloat * value = nullptr;
	status = getTypedArray(env, args[3], value);
	// void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	glUniformMatrix3x4fv(location, count, transpose, value);
	return NULL;
}

napi_value UniformMatrix4x3fv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLboolean transpose = getBool(env, args[2]);
	GLfloat * value = nullptr;
	status = getTypedArray(env, args[3], value);
	// void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
	glUniformMatrix4x3fv(location, count, transpose, value);
	return NULL;
}

napi_value BlitFramebuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[10];
	size_t argc = checkArgCount(env, info, args, 10, 10);
	GLint srcX0 = getInt32(env, args[0]);
	GLint srcY0 = getInt32(env, args[1]);
	GLint srcX1 = getInt32(env, args[2]);
	GLint srcY1 = getInt32(env, args[3]);
	GLint dstX0 = getInt32(env, args[4]);
	GLint dstY0 = getInt32(env, args[5]);
	GLint dstX1 = getInt32(env, args[6]);
	GLint dstY1 = getInt32(env, args[7]);
	GLbitfield mask = getUint32(env, args[8]);
	GLenum filter = getUint32(env, args[9]);
	// void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
	glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
	return NULL;
}

napi_value RenderbufferStorageMultisample(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLsizei samples = getInt32(env, args[1]);
	GLenum internalformat = getUint32(env, args[2]);
	GLsizei width = getInt32(env, args[3]);
	GLsizei height = getInt32(env, args[4]);
	// void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
	glRenderbufferStorageMultisample(target, samples, internalformat, width, height);
	return NULL;
}

napi_value FramebufferTextureLayer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLenum attachment = getUint32(env, args[1]);
	GLuint texture = getUint32(env, args[2]);
	GLint level = getInt32(env, args[3]);
	GLint layer = getInt32(env, args[4]);
	// void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
	glFramebufferTextureLayer(target, attachment, texture, level, layer);
	return NULL;
}

napi_value FlushMappedBufferRange(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLintptr offset = getInt32(env, args[1]);
	GLsizeiptr length = getUint32(env, args[2]);
	// void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length)
	glFlushMappedBufferRange(target, offset, length);
	return NULL;
}

napi_value BindVertexArray(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint array = getUint32(env, args[0]);
	// void glBindVertexArray(GLuint array)
	glBindVertexArray(array);
	return NULL;
}

napi_value GenVertexArrays(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint * arrays = nullptr;
	status = getTypedArray(env, args[1], arrays);
	// void glGenVertexArrays(GLsizei n, GLuint *arrays)
	glGenVertexArrays(n, arrays);
	return NULL;
}

napi_value IsVertexArray(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint array = getUint32(env, args[0]);
	// GLboolean glIsVertexArray(GLuint array)
	GLboolean result = glIsVertexArray(array);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value BeginTransformFeedback(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum primitiveMode = getUint32(env, args[0]);
	// void glBeginTransformFeedback(GLenum primitiveMode)
	glBeginTransformFeedback(primitiveMode);
	return NULL;
}

napi_value EndTransformFeedback(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glEndTransformFeedback(void)
	glEndTransformFeedback();
	return NULL;
}

napi_value BindBufferRange(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	GLintptr offset = getInt32(env, args[3]);
	GLsizeiptr size = getUint32(env, args[4]);
	// void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
	glBindBufferRange(target, index, buffer, offset, size);
	return NULL;
}

napi_value BindBufferBase(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	// void glBindBufferBase(GLenum target, GLuint index, GLuint buffer)
	glBindBufferBase(target, index, buffer);
	return NULL;
}

napi_value TransformFeedbackVaryings(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint program = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLchar ** varyings = nullptr;
	status = getListOfStrings(env, args[2], varyings);
	GLenum bufferMode = getUint32(env, args[3]);
	// void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode)
	glTransformFeedbackVaryings(program, count, varyings, bufferMode);
	return NULL;
}

napi_value GetTransformFeedbackVarying(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLuint program = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLsizei bufSize = getInt32(env, args[2]);
	GLsizei length_result;
	GLsizei * length = &length_result;
	GLsizei size_result;
	GLsizei * size = &size_result;
	GLenum type_result;
	GLenum * type = &type_result;
	GLchar * name;
	status = getTypedArray(env, args[6], name);
	// void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name)
	glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name);
	return NULL;
}

napi_value VertexAttribIPointer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint index = getUint32(env, args[0]);
	GLint size = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLsizei stride = getInt32(env, args[3]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[4], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer)
	glVertexAttribIPointer(index, size, type, stride, pointer);
	return NULL;
}

napi_value GetVertexAttribIiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint index = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint params_result;
	GLint * params = &params_result;
	// void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint *params)
	glGetVertexAttribIiv(index, pname, params);
	return NULL;
}

napi_value GetVertexAttribIuiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint index = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLuint params_result;
	GLuint * params = &params_result;
	// void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint *params)
	glGetVertexAttribIuiv(index, pname, params);
	return NULL;
}

napi_value VertexAttribI4i(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint index = getUint32(env, args[0]);
	GLint x = getInt32(env, args[1]);
	GLint y = getInt32(env, args[2]);
	GLint z = getInt32(env, args[3]);
	GLint w = getInt32(env, args[4]);
	// void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w)
	glVertexAttribI4i(index, x, y, z, w);
	return NULL;
}

napi_value VertexAttribI4ui(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint index = getUint32(env, args[0]);
	GLuint x = getUint32(env, args[1]);
	GLuint y = getUint32(env, args[2]);
	GLuint z = getUint32(env, args[3]);
	GLuint w = getUint32(env, args[4]);
	// void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)
	glVertexAttribI4ui(index, x, y, z, w);
	return NULL;
}

napi_value VertexAttribI4iv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint index = getUint32(env, args[0]);
	GLint * v = nullptr;
	status = getTypedArray(env, args[1], v);
	// void glVertexAttribI4iv(GLuint index, const GLint *v)
	glVertexAttribI4iv(index, v);
	return NULL;
}

napi_value VertexAttribI4uiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint index = getUint32(env, args[0]);
	GLuint * v = nullptr;
	status = getTypedArray(env, args[1], v);
	// void glVertexAttribI4uiv(GLuint index, const GLuint *v)
	glVertexAttribI4uiv(index, v);
	return NULL;
}

napi_value GetUniformuiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint program = getUint32(env, args[0]);
	GLint location = getInt32(env, args[1]);
	GLuint params_result;
	GLuint * params = &params_result;
	// void glGetUniformuiv(GLuint program, GLint location, GLuint *params)
	glGetUniformuiv(program, location, params);
	return NULL;
}

napi_value GetFragDataLocation(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint program = getUint32(env, args[0]);
	GLchar * name;
	status = getTypedArray(env, args[1], name);
	// GLint glGetFragDataLocation(GLuint program, const GLchar *name)
	GLint result = glGetFragDataLocation(program, name);
	napi_value result_value = nullptr;
	status = napi_create_int32(env, (int32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value Uniform1ui(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLint location = getInt32(env, args[0]);
	GLuint v0 = getUint32(env, args[1]);
	// void glUniform1ui(GLint location, GLuint v0)
	glUniform1ui(location, v0);
	return NULL;
}

napi_value Uniform2ui(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint location = getInt32(env, args[0]);
	GLuint v0 = getUint32(env, args[1]);
	GLuint v1 = getUint32(env, args[2]);
	// void glUniform2ui(GLint location, GLuint v0, GLuint v1)
	glUniform2ui(location, v0, v1);
	return NULL;
}

napi_value Uniform3ui(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLint location = getInt32(env, args[0]);
	GLuint v0 = getUint32(env, args[1]);
	GLuint v1 = getUint32(env, args[2]);
	GLuint v2 = getUint32(env, args[3]);
	// void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2)
	glUniform3ui(location, v0, v1, v2);
	return NULL;
}

napi_value Uniform4ui(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLint location = getInt32(env, args[0]);
	GLuint v0 = getUint32(env, args[1]);
	GLuint v1 = getUint32(env, args[2]);
	GLuint v2 = getUint32(env, args[3]);
	GLuint v3 = getUint32(env, args[4]);
	// void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
	glUniform4ui(location, v0, v1, v2, v3);
	return NULL;
}

napi_value Uniform1uiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLuint * value = nullptr;
	status = getTypedArray(env, args[2], value);
	// void glUniform1uiv(GLint location, GLsizei count, const GLuint *value)
	glUniform1uiv(location, count, value);
	return NULL;
}

napi_value Uniform2uiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLuint * value = nullptr;
	status = getTypedArray(env, args[2], value);
	// void glUniform2uiv(GLint location, GLsizei count, const GLuint *value)
	glUniform2uiv(location, count, value);
	return NULL;
}

napi_value Uniform3uiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLuint * value = nullptr;
	status = getTypedArray(env, args[2], value);
	// void glUniform3uiv(GLint location, GLsizei count, const GLuint *value)
	glUniform3uiv(location, count, value);
	return NULL;
}

napi_value Uniform4uiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint location = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLuint * value = nullptr;
	status = getTypedArray(env, args[2], value);
	// void glUniform4uiv(GLint location, GLsizei count, const GLuint *value)
	glUniform4uiv(location, count, value);
	return NULL;
}

napi_value ClearBufferiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum buffer = getUint32(env, args[0]);
	GLint drawbuffer = getInt32(env, args[1]);
	GLint * value = nullptr;
	status = getTypedArray(env, args[2], value);
	// void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint *value)
	glClearBufferiv(buffer, drawbuffer, value);
	return NULL;
}

napi_value ClearBufferuiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum buffer = getUint32(env, args[0]);
	GLint drawbuffer = getInt32(env, args[1]);
	GLuint * value = nullptr;
	status = getTypedArray(env, args[2], value);
	// void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint *value)
	glClearBufferuiv(buffer, drawbuffer, value);
	return NULL;
}

napi_value ClearBufferfi(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum buffer = getUint32(env, args[0]);
	GLint drawbuffer = getInt32(env, args[1]);
	GLfloat depth = getDouble(env, args[2]);
	GLint stencil = getInt32(env, args[3]);
	// void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
	glClearBufferfi(buffer, drawbuffer, depth, stencil);
	return NULL;
}

napi_value CopyBufferSubData(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum readTarget = getUint32(env, args[0]);
	GLenum writeTarget = getUint32(env, args[1]);
	GLintptr readOffset = getInt32(env, args[2]);
	GLintptr writeOffset = getInt32(env, args[3]);
	GLsizeiptr size = getUint32(env, args[4]);
	// void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
	glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size);
	return NULL;
}

napi_value GetUniformIndices(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint program = getUint32(env, args[0]);
	GLsizei uniformCount = getInt32(env, args[1]);
	GLchar ** uniformNames = nullptr;
	status = getListOfStrings(env, args[2], uniformNames);
	GLuint uniformIndices_result;
	GLuint * uniformIndices = &uniformIndices_result;
	// void glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices)
	glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices);
	return NULL;
}

napi_value GetActiveUniformsiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint program = getUint32(env, args[0]);
	GLsizei uniformCount = getInt32(env, args[1]);
	GLuint uniformIndices_result;
	GLuint * uniformIndices = &uniformIndices_result;
	GLenum pname = getUint32(env, args[3]);
	GLint params_result;
	GLint * params = &params_result;
	// void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params)
	glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params);
	return NULL;
}

napi_value GetUniformBlockIndex(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint program = getUint32(env, args[0]);
	GLchar * uniformBlockName;
	status = getTypedArray(env, args[1], uniformBlockName);
	// GLuint glGetUniformBlockIndex(GLuint program, const GLchar *uniformBlockName)
	GLuint result = glGetUniformBlockIndex(program, uniformBlockName);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value GetActiveUniformBlockiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint program = getUint32(env, args[0]);
	GLuint uniformBlockIndex = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLint params_result;
	GLint * params = &params_result;
	// void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params)
	glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params);
	return NULL;
}

napi_value GetActiveUniformBlockName(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint program = getUint32(env, args[0]);
	GLuint uniformBlockIndex = getUint32(env, args[1]);
	GLsizei bufSize = getInt32(env, args[2]);
	GLsizei length_result;
	GLsizei * length = &length_result;
	GLchar * uniformBlockName;
	status = getTypedArray(env, args[4], uniformBlockName);
	// void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName)
	glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName);
	return NULL;
}

napi_value UniformBlockBinding(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint program = getUint32(env, args[0]);
	GLuint uniformBlockIndex = getUint32(env, args[1]);
	GLuint uniformBlockBinding = getUint32(env, args[2]);
	// void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)
	glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
	return NULL;
}

napi_value DrawArraysInstanced(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum mode = getUint32(env, args[0]);
	GLint first = getInt32(env, args[1]);
	GLsizei count = getInt32(env, args[2]);
	GLsizei instancecount = getInt32(env, args[3]);
	// void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount)
	glDrawArraysInstanced(mode, first, count, instancecount);
	return NULL;
}

napi_value DrawElementsInstanced(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum mode = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	void * indices = nullptr;
	status = getTypedArray(env, args[3], *(void **)&indices);
	if (status != napi_ok) return nullptr;
	GLsizei instancecount = getInt32(env, args[4]);
	// void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount)
	glDrawElementsInstanced(mode, count, type, indices, instancecount);
	return NULL;
}

napi_value FenceSync(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum condition = getUint32(env, args[0]);
	GLbitfield flags = getUint32(env, args[1]);
	// GLsync glFenceSync(GLenum condition, GLbitfield flags)
	GLsync result = glFenceSync(condition, flags);
	napi_value result_value = nullptr;
	status = napi_create_external(env, (void *)result, NULL, NULL, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value IsSync(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLsync sync = nullptr;
	status = getTypedArray(env, args[0], *(void **)&sync);
	if (status != napi_ok) return nullptr;
	// GLboolean glIsSync(GLsync sync)
	GLboolean result = glIsSync(sync);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value DeleteSync(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLsync sync = nullptr;
	status = getTypedArray(env, args[0], *(void **)&sync);
	if (status != napi_ok) return nullptr;
	// void glDeleteSync(GLsync sync)
	glDeleteSync(sync);
	return NULL;
}

napi_value ClientWaitSync(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLsync sync = nullptr;
	status = getTypedArray(env, args[0], *(void **)&sync);
	if (status != napi_ok) return nullptr;
	GLbitfield flags = getUint32(env, args[1]);
	uint64_t timeout = 0;
	uint32_t timeout_uint32;
	bool timeout_lossless;
		status = napi_get_value_uint32(env, args[2], &timeout_uint32);
		timeout = timeout_uint32;
	if (status != napi_ok) return nullptr;
	// GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
	GLenum result = glClientWaitSync(sync, flags, timeout);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value WaitSync(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLsync sync = nullptr;
	status = getTypedArray(env, args[0], *(void **)&sync);
	if (status != napi_ok) return nullptr;
	GLbitfield flags = getUint32(env, args[1]);
	uint64_t timeout = 0;
	uint32_t timeout_uint32;
	bool timeout_lossless;
		status = napi_get_value_uint32(env, args[2], &timeout_uint32);
		timeout = timeout_uint32;
	if (status != napi_ok) return nullptr;
	// void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
	glWaitSync(sync, flags, timeout);
	return NULL;
}

napi_value GetSynciv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLsync sync = nullptr;
	status = getTypedArray(env, args[0], *(void **)&sync);
	if (status != napi_ok) return nullptr;
	GLenum pname = getUint32(env, args[1]);
	GLsizei bufSize = getInt32(env, args[2]);
	GLsizei length_result;
	GLsizei * length = &length_result;
	GLint values_result;
	GLint * values = &values_result;
	// void glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values)
	glGetSynciv(sync, pname, bufSize, length, values);
	return NULL;
}

napi_value GenSamplers(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei count = getInt32(env, args[0]);
	GLuint * samplers = nullptr;
	status = getTypedArray(env, args[1], samplers);
	// void glGenSamplers(GLsizei count, GLuint *samplers)
	glGenSamplers(count, samplers);
	return NULL;
}

napi_value DeleteSamplers(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei count = getInt32(env, args[0]);
	GLuint * samplers = nullptr;
	status = getTypedArray(env, args[1], samplers);
	// void glDeleteSamplers(GLsizei count, const GLuint *samplers)
	glDeleteSamplers(count, samplers);
	return NULL;
}

napi_value IsSampler(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint sampler = getUint32(env, args[0]);
	// GLboolean glIsSampler(GLuint sampler)
	GLboolean result = glIsSampler(sampler);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value BindSampler(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint unit = getUint32(env, args[0]);
	GLuint sampler = getUint32(env, args[1]);
	// void glBindSampler(GLuint unit, GLuint sampler)
	glBindSampler(unit, sampler);
	return NULL;
}

napi_value SamplerParameteri(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint sampler = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint param = getInt32(env, args[2]);
	// void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param)
	glSamplerParameteri(sampler, pname, param);
	return NULL;
}

napi_value SamplerParameteriv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint sampler = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint * param = nullptr;
	status = getTypedArray(env, args[2], param);
	// void glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint *param)
	glSamplerParameteriv(sampler, pname, param);
	return NULL;
}

napi_value SamplerParameterf(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint sampler = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat param = getDouble(env, args[2]);
	// void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param)
	glSamplerParameterf(sampler, pname, param);
	return NULL;
}

napi_value SamplerParameterfv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint sampler = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat * param = nullptr;
	status = getTypedArray(env, args[2], param);
	// void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat *param)
	glSamplerParameterfv(sampler, pname, param);
	return NULL;
}

napi_value GetSamplerParameteriv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint sampler = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint params_result;
	GLint * params = &params_result;
	// void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint *params)
	glGetSamplerParameteriv(sampler, pname, params);
	return NULL;
}

napi_value GetSamplerParameterfv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint sampler = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat params_result;
	GLfloat * params = &params_result;
	// void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat *params)
	glGetSamplerParameterfv(sampler, pname, params);
	return NULL;
}

napi_value VertexAttribDivisor(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint index = getUint32(env, args[0]);
	GLuint divisor = getUint32(env, args[1]);
	// void glVertexAttribDivisor(GLuint index, GLuint divisor)
	glVertexAttribDivisor(index, divisor);
	return NULL;
}

napi_value BindTransformFeedback(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLuint id = getUint32(env, args[1]);
	// void glBindTransformFeedback(GLenum target, GLuint id)
	glBindTransformFeedback(target, id);
	return NULL;
}

napi_value DeleteTransformFeedbacks(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint * ids = nullptr;
	status = getTypedArray(env, args[1], ids);
	// void glDeleteTransformFeedbacks(GLsizei n, const GLuint *ids)
	glDeleteTransformFeedbacks(n, ids);
	return NULL;
}

napi_value GenTransformFeedbacks(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint * ids = nullptr;
	status = getTypedArray(env, args[1], ids);
	// void glGenTransformFeedbacks(GLsizei n, GLuint *ids)
	glGenTransformFeedbacks(n, ids);
	return NULL;
}

napi_value IsTransformFeedback(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint id = getUint32(env, args[0]);
	// GLboolean glIsTransformFeedback(GLuint id)
	GLboolean result = glIsTransformFeedback(id);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value PauseTransformFeedback(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glPauseTransformFeedback(void)
	glPauseTransformFeedback();
	return NULL;
}

napi_value ResumeTransformFeedback(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glResumeTransformFeedback(void)
	glResumeTransformFeedback();
	return NULL;
}

napi_value GetProgramBinary(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint program = getUint32(env, args[0]);
	GLsizei bufSize = getInt32(env, args[1]);
	GLsizei length_result;
	GLsizei * length = &length_result;
	GLenum binaryFormat_result;
	GLenum * binaryFormat = &binaryFormat_result;
	void * binary = nullptr;
	status = getTypedArray(env, args[4], *(void **)&binary);
	if (status != napi_ok) return nullptr;
	// void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary)
	glGetProgramBinary(program, bufSize, length, binaryFormat, binary);
	return NULL;
}

napi_value ProgramBinary(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint program = getUint32(env, args[0]);
	GLenum binaryFormat = getUint32(env, args[1]);
	void * binary = nullptr;
	status = getTypedArray(env, args[2], *(void **)&binary);
	if (status != napi_ok) return nullptr;
	GLsizei length = getInt32(env, args[3]);
	// void glProgramBinary(GLuint program, GLenum binaryFormat, const void *binary, GLsizei length)
	glProgramBinary(program, binaryFormat, binary, length);
	return NULL;
}

napi_value ProgramParameteri(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint program = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint value = getInt32(env, args[2]);
	// void glProgramParameteri(GLuint program, GLenum pname, GLint value)
	glProgramParameteri(program, pname, value);
	return NULL;
}

napi_value InvalidateFramebuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLsizei numAttachments = getInt32(env, args[1]);
	GLenum * attachments = nullptr;
	status = getTypedArray(env, args[2], attachments);
	// void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments)
	glInvalidateFramebuffer(target, numAttachments, attachments);
	return NULL;
}

napi_value InvalidateSubFramebuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLenum target = getUint32(env, args[0]);
	GLsizei numAttachments = getInt32(env, args[1]);
	GLenum * attachments = nullptr;
	status = getTypedArray(env, args[2], attachments);
	GLint x = getInt32(env, args[3]);
	GLint y = getInt32(env, args[4]);
	GLsizei width = getInt32(env, args[5]);
	GLsizei height = getInt32(env, args[6]);
	// void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height)
	glInvalidateSubFramebuffer(target, numAttachments, attachments, x, y, width, height);
	return NULL;
}

napi_value TexStorage2D(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLsizei levels = getInt32(env, args[1]);
	GLenum internalformat = getUint32(env, args[2]);
	GLsizei width = getInt32(env, args[3]);
	GLsizei height = getInt32(env, args[4]);
	// void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
	glTexStorage2D(target, levels, internalformat, width, height);
	return NULL;
}

napi_value TexStorage3D(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum target = getUint32(env, args[0]);
	GLsizei levels = getInt32(env, args[1]);
	GLenum internalformat = getUint32(env, args[2]);
	GLsizei width = getInt32(env, args[3]);
	GLsizei height = getInt32(env, args[4]);
	GLsizei depth = getInt32(env, args[5]);
	// void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
	glTexStorage3D(target, levels, internalformat, width, height, depth);
	return NULL;
}

napi_value GetInternalformativ(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLsizei bufSize = getInt32(env, args[3]);
	GLint params_result;
	GLint * params = &params_result;
	// void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params)
	glGetInternalformativ(target, internalformat, pname, bufSize, params);
	return NULL;
}

napi_value ClientActiveTexture(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum texture = getUint32(env, args[0]);
	// void glClientActiveTexture(GLenum texture)
	glClientActiveTexture(texture);
	return NULL;
}

napi_value FogCoordPointer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum type = getUint32(env, args[0]);
	GLsizei stride = getInt32(env, args[1]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[2], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glFogCoordPointer(GLenum type, GLsizei stride, const void *pointer)
	glFogCoordPointer(type, stride, pointer);
	return NULL;
}

napi_value FogCoordd(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLdouble coord;
	// void glFogCoordd(GLdouble coord)
	glFogCoordd(coord);
	return NULL;
}

napi_value FogCoorddv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLdouble * coord;
	// void glFogCoorddv(const GLdouble *coord)
	glFogCoorddv(coord);
	return NULL;
}

napi_value FogCoordf(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLfloat coord = getDouble(env, args[0]);
	// void glFogCoordf(GLfloat coord)
	glFogCoordf(coord);
	return NULL;
}

napi_value FogCoordfv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLfloat * coord = nullptr;
	status = getTypedArray(env, args[0], coord);
	// void glFogCoordfv(const GLfloat *coord)
	glFogCoordfv(coord);
	return NULL;
}

napi_value MultiDrawArrays(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum mode = getUint32(env, args[0]);
	GLint * first = nullptr;
	status = getTypedArray(env, args[1], first);
	GLsizei * count = nullptr;
	status = getTypedArray(env, args[2], count);
	GLsizei drawcount = getInt32(env, args[3]);
	// void glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount)
	glMultiDrawArrays(mode, first, count, drawcount);
	return NULL;
}

napi_value MultiDrawElements(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum mode = getUint32(env, args[0]);
	GLsizei * count = nullptr;
	status = getTypedArray(env, args[1], count);
	GLenum type = getUint32(env, args[2]);
	void * indices_result = nullptr;
	void ** indices = &indices_result;
	GLsizei drawcount = getInt32(env, args[4]);
	// void glMultiDrawElements(GLenum mode, const GLsizei *count, GLenum type, const void *const* indices, GLsizei drawcount)
	glMultiDrawElements(mode, count, type, indices, drawcount);
	return NULL;
}

napi_value PointParameterf(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat param = getDouble(env, args[1]);
	// void glPointParameterf(GLenum pname, GLfloat param)
	glPointParameterf(pname, param);
	return NULL;
}

napi_value PointParameterfv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat * params = nullptr;
	status = getTypedArray(env, args[1], params);
	// void glPointParameterfv(GLenum pname, const GLfloat *params)
	glPointParameterfv(pname, params);
	return NULL;
}

napi_value PointParameteri(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint param = getInt32(env, args[1]);
	// void glPointParameteri(GLenum pname, GLint param)
	glPointParameteri(pname, param);
	return NULL;
}

napi_value PointParameteriv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint * params = nullptr;
	status = getTypedArray(env, args[1], params);
	// void glPointParameteriv(GLenum pname, const GLint *params)
	glPointParameteriv(pname, params);
	return NULL;
}

napi_value SecondaryColorPointer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLint size = getInt32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	GLsizei stride = getInt32(env, args[2]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[3], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const void *pointer)
	glSecondaryColorPointer(size, type, stride, pointer);
	return NULL;
}

napi_value BeginConditionalRender(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint id = getUint32(env, args[0]);
	GLenum mode = getUint32(env, args[1]);
	// void glBeginConditionalRender(GLuint id, GLenum mode)
	glBeginConditionalRender(id, mode);
	return NULL;
}

napi_value BindFragDataLocation(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint program = getUint32(env, args[0]);
	GLuint colorNumber = getUint32(env, args[1]);
	GLchar* name;
	// void glBindFragDataLocation(GLuint program, GLuint colorNumber, const GLchar* name)
	glBindFragDataLocation(program, colorNumber, name);
	return NULL;
}

napi_value ClampColor(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLenum clamp = getUint32(env, args[1]);
	// void glClampColor(GLenum target, GLenum clamp)
	glClampColor(target, clamp);
	return NULL;
}

napi_value ColorMaski(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint buf = getUint32(env, args[0]);
	GLboolean red = getBool(env, args[1]);
	GLboolean green = getBool(env, args[2]);
	GLboolean blue = getBool(env, args[3]);
	GLboolean alpha = getBool(env, args[4]);
	// void glColorMaski(GLuint buf, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
	glColorMaski(buf, red, green, blue, alpha);
	return NULL;
}

napi_value Disablei(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum cap = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	// void glDisablei(GLenum cap, GLuint index)
	glDisablei(cap, index);
	return NULL;
}

napi_value Enablei(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum cap = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	// void glEnablei(GLenum cap, GLuint index)
	glEnablei(cap, index);
	return NULL;
}

napi_value EndConditionalRender(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glEndConditionalRender(void)
	glEndConditionalRender();
	return NULL;
}

napi_value IsEnabledi(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum cap = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	// GLboolean glIsEnabledi(GLenum cap, GLuint index)
	GLboolean result = glIsEnabledi(cap, index);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value TexParameterIiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint* params;
	// void glTexParameterIiv(GLenum target, GLenum pname, const GLint* params)
	glTexParameterIiv(target, pname, params);
	return NULL;
}

napi_value TexParameterIuiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLuint* params;
	// void glTexParameterIuiv(GLenum target, GLenum pname, const GLuint* params)
	glTexParameterIuiv(target, pname, params);
	return NULL;
}

napi_value PrimitiveRestartIndex(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint buffer = getUint32(env, args[0]);
	// void glPrimitiveRestartIndex(GLuint buffer)
	glPrimitiveRestartIndex(buffer);
	return NULL;
}

napi_value TexBuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum internalFormat = getUint32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	// void glTexBuffer(GLenum target, GLenum internalFormat, GLuint buffer)
	glTexBuffer(target, internalFormat, buffer);
	return NULL;
}

napi_value FramebufferTexture(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLenum attachment = getUint32(env, args[1]);
	GLuint texture = getUint32(env, args[2]);
	GLint level = getInt32(env, args[3]);
	// void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level)
	glFramebufferTexture(target, attachment, texture, level);
	return NULL;
}

napi_value BlendEquationSeparatei(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint buf = getUint32(env, args[0]);
	GLenum modeRGB = getUint32(env, args[1]);
	GLenum modeAlpha = getUint32(env, args[2]);
	// void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
	glBlendEquationSeparatei(buf, modeRGB, modeAlpha);
	return NULL;
}

napi_value BlendEquationi(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint buf = getUint32(env, args[0]);
	GLenum mode = getUint32(env, args[1]);
	// void glBlendEquationi(GLuint buf, GLenum mode)
	glBlendEquationi(buf, mode);
	return NULL;
}

napi_value BlendFuncSeparatei(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint buf = getUint32(env, args[0]);
	GLenum srcRGB = getUint32(env, args[1]);
	GLenum dstRGB = getUint32(env, args[2]);
	GLenum srcAlpha = getUint32(env, args[3]);
	GLenum dstAlpha = getUint32(env, args[4]);
	// void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
	glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
	return NULL;
}

napi_value BlendFunci(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint buf = getUint32(env, args[0]);
	GLenum src = getUint32(env, args[1]);
	GLenum dst = getUint32(env, args[2]);
	// void glBlendFunci(GLuint buf, GLenum src, GLenum dst)
	glBlendFunci(buf, src, dst);
	return NULL;
}

napi_value MinSampleShading(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLclampf value;
	// void glMinSampleShading(GLclampf value)
	glMinSampleShading(value);
	return NULL;
}

napi_value DebugMessageCallbackAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLDEBUGPROCAMD callback;
	void * userParam = nullptr;
	status = getTypedArray(env, args[1], *(void **)&userParam);
	if (status != napi_ok) return nullptr;
	// void glDebugMessageCallbackAMD(GLDEBUGPROCAMD callback, void *userParam)
	glDebugMessageCallbackAMD(callback, userParam);
	return NULL;
}

napi_value DebugMessageEnableAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum category = getUint32(env, args[0]);
	GLenum severity = getUint32(env, args[1]);
	GLsizei count = getInt32(env, args[2]);
	GLuint* ids;
	GLboolean enabled = getBool(env, args[4]);
	// void glDebugMessageEnableAMD(GLenum category, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled)
	glDebugMessageEnableAMD(category, severity, count, ids, enabled);
	return NULL;
}

napi_value DebugMessageInsertAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum category = getUint32(env, args[0]);
	GLenum severity = getUint32(env, args[1]);
	GLuint id = getUint32(env, args[2]);
	GLsizei length = getInt32(env, args[3]);
	GLchar* buf;
	// void glDebugMessageInsertAMD(GLenum category, GLenum severity, GLuint id, GLsizei length, const GLchar* buf)
	glDebugMessageInsertAMD(category, severity, id, length, buf);
	return NULL;
}

napi_value BlendEquationIndexedAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint buf = getUint32(env, args[0]);
	GLenum mode = getUint32(env, args[1]);
	// void glBlendEquationIndexedAMD(GLuint buf, GLenum mode)
	glBlendEquationIndexedAMD(buf, mode);
	return NULL;
}

napi_value BlendEquationSeparateIndexedAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint buf = getUint32(env, args[0]);
	GLenum modeRGB = getUint32(env, args[1]);
	GLenum modeAlpha = getUint32(env, args[2]);
	// void glBlendEquationSeparateIndexedAMD(GLuint buf, GLenum modeRGB, GLenum modeAlpha)
	glBlendEquationSeparateIndexedAMD(buf, modeRGB, modeAlpha);
	return NULL;
}

napi_value BlendFuncIndexedAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint buf = getUint32(env, args[0]);
	GLenum src = getUint32(env, args[1]);
	GLenum dst = getUint32(env, args[2]);
	// void glBlendFuncIndexedAMD(GLuint buf, GLenum src, GLenum dst)
	glBlendFuncIndexedAMD(buf, src, dst);
	return NULL;
}

napi_value BlendFuncSeparateIndexedAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint buf = getUint32(env, args[0]);
	GLenum srcRGB = getUint32(env, args[1]);
	GLenum dstRGB = getUint32(env, args[2]);
	GLenum srcAlpha = getUint32(env, args[3]);
	GLenum dstAlpha = getUint32(env, args[4]);
	// void glBlendFuncSeparateIndexedAMD(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
	glBlendFuncSeparateIndexedAMD(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
	return NULL;
}

napi_value VertexAttribParameteriAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint index = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint param = getInt32(env, args[2]);
	// void glVertexAttribParameteriAMD(GLuint index, GLenum pname, GLint param)
	glVertexAttribParameteriAMD(index, pname, param);
	return NULL;
}

napi_value MultiDrawArraysIndirectAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum mode = getUint32(env, args[0]);
	void * indirect = nullptr;
	status = getTypedArray(env, args[1], *(void **)&indirect);
	if (status != napi_ok) return nullptr;
	GLsizei primcount = getInt32(env, args[2]);
	GLsizei stride = getInt32(env, args[3]);
	// void glMultiDrawArraysIndirectAMD(GLenum mode, const void *indirect, GLsizei primcount, GLsizei stride)
	glMultiDrawArraysIndirectAMD(mode, indirect, primcount, stride);
	return NULL;
}

napi_value MultiDrawElementsIndirectAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum mode = getUint32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	void * indirect = nullptr;
	status = getTypedArray(env, args[2], *(void **)&indirect);
	if (status != napi_ok) return nullptr;
	GLsizei primcount = getInt32(env, args[3]);
	GLsizei stride = getInt32(env, args[4]);
	// void glMultiDrawElementsIndirectAMD(GLenum mode, GLenum type, const void *indirect, GLsizei primcount, GLsizei stride)
	glMultiDrawElementsIndirectAMD(mode, type, indirect, primcount, stride);
	return NULL;
}

napi_value DeleteNamesAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum identifier = getUint32(env, args[0]);
	GLuint num = getUint32(env, args[1]);
	GLuint* names;
	// void glDeleteNamesAMD(GLenum identifier, GLuint num, const GLuint* names)
	glDeleteNamesAMD(identifier, num, names);
	return NULL;
}

napi_value GenNamesAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum identifier = getUint32(env, args[0]);
	GLuint num = getUint32(env, args[1]);
	GLuint* names;
	// void glGenNamesAMD(GLenum identifier, GLuint num, GLuint* names)
	glGenNamesAMD(identifier, num, names);
	return NULL;
}

napi_value IsNameAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum identifier = getUint32(env, args[0]);
	GLuint name = getUint32(env, args[1]);
	// GLboolean glIsNameAMD(GLenum identifier, GLuint name)
	GLboolean result = glIsNameAMD(identifier, name);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value QueryObjectParameteruiAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLuint id = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLuint param = getUint32(env, args[3]);
	// void glQueryObjectParameteruiAMD(GLenum target, GLuint id, GLenum pname, GLuint param)
	glQueryObjectParameteruiAMD(target, id, pname, param);
	return NULL;
}

napi_value BeginPerfMonitorAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint monitor = getUint32(env, args[0]);
	// void glBeginPerfMonitorAMD(GLuint monitor)
	glBeginPerfMonitorAMD(monitor);
	return NULL;
}

napi_value DeletePerfMonitorsAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* monitors;
	// void glDeletePerfMonitorsAMD(GLsizei n, GLuint* monitors)
	glDeletePerfMonitorsAMD(n, monitors);
	return NULL;
}

napi_value EndPerfMonitorAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint monitor = getUint32(env, args[0]);
	// void glEndPerfMonitorAMD(GLuint monitor)
	glEndPerfMonitorAMD(monitor);
	return NULL;
}

napi_value GenPerfMonitorsAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* monitors;
	// void glGenPerfMonitorsAMD(GLsizei n, GLuint* monitors)
	glGenPerfMonitorsAMD(n, monitors);
	return NULL;
}

napi_value SelectPerfMonitorCountersAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint monitor = getUint32(env, args[0]);
	GLboolean enable = getBool(env, args[1]);
	GLuint group = getUint32(env, args[2]);
	GLint numCounters = getInt32(env, args[3]);
	GLuint* counterList;
	// void glSelectPerfMonitorCountersAMD(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint* counterList)
	glSelectPerfMonitorCountersAMD(monitor, enable, group, numCounters, counterList);
	return NULL;
}

napi_value SetMultisamplefvAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum pname = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLfloat* val;
	// void glSetMultisamplefvAMD(GLenum pname, GLuint index, const GLfloat* val)
	glSetMultisamplefvAMD(pname, index, val);
	return NULL;
}

napi_value TexStorageSparseAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLenum target = getUint32(env, args[0]);
	GLenum internalFormat = getUint32(env, args[1]);
	GLsizei width = getInt32(env, args[2]);
	GLsizei height = getInt32(env, args[3]);
	GLsizei depth = getInt32(env, args[4]);
	GLsizei layers = getInt32(env, args[5]);
	GLbitfield flags = getUint32(env, args[6]);
	// void glTexStorageSparseAMD(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags)
	glTexStorageSparseAMD(target, internalFormat, width, height, depth, layers, flags);
	return NULL;
}

napi_value TextureStorageSparseAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[8];
	size_t argc = checkArgCount(env, info, args, 8, 8);
	GLuint texture = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum internalFormat = getUint32(env, args[2]);
	GLsizei width = getInt32(env, args[3]);
	GLsizei height = getInt32(env, args[4]);
	GLsizei depth = getInt32(env, args[5]);
	GLsizei layers = getInt32(env, args[6]);
	GLbitfield flags = getUint32(env, args[7]);
	// void glTextureStorageSparseAMD(GLuint texture, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags)
	glTextureStorageSparseAMD(texture, target, internalFormat, width, height, depth, layers, flags);
	return NULL;
}

napi_value StencilOpValueAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum face = getUint32(env, args[0]);
	GLuint value = getUint32(env, args[1]);
	// void glStencilOpValueAMD(GLenum face, GLuint value)
	glStencilOpValueAMD(face, value);
	return NULL;
}

napi_value TessellationFactorAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLfloat factor = getDouble(env, args[0]);
	// void glTessellationFactorAMD(GLfloat factor)
	glTessellationFactorAMD(factor);
	return NULL;
}

napi_value TessellationModeAMD(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum mode = getUint32(env, args[0]);
	// void glTessellationModeAMD(GLenum mode)
	glTessellationModeAMD(mode);
	return NULL;
}

napi_value BlitFramebufferANGLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[10];
	size_t argc = checkArgCount(env, info, args, 10, 10);
	GLint srcX0 = getInt32(env, args[0]);
	GLint srcY0 = getInt32(env, args[1]);
	GLint srcX1 = getInt32(env, args[2]);
	GLint srcY1 = getInt32(env, args[3]);
	GLint dstX0 = getInt32(env, args[4]);
	GLint dstY0 = getInt32(env, args[5]);
	GLint dstX1 = getInt32(env, args[6]);
	GLint dstY1 = getInt32(env, args[7]);
	GLbitfield mask = getUint32(env, args[8]);
	GLenum filter = getUint32(env, args[9]);
	// void glBlitFramebufferANGLE(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
	glBlitFramebufferANGLE(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
	return NULL;
}

napi_value RenderbufferStorageMultisampleANGLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLsizei samples = getInt32(env, args[1]);
	GLenum internalformat = getUint32(env, args[2]);
	GLsizei width = getInt32(env, args[3]);
	GLsizei height = getInt32(env, args[4]);
	// void glRenderbufferStorageMultisampleANGLE(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
	glRenderbufferStorageMultisampleANGLE(target, samples, internalformat, width, height);
	return NULL;
}

napi_value DrawArraysInstancedANGLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum mode = getUint32(env, args[0]);
	GLint first = getInt32(env, args[1]);
	GLsizei count = getInt32(env, args[2]);
	GLsizei primcount = getInt32(env, args[3]);
	// void glDrawArraysInstancedANGLE(GLenum mode, GLint first, GLsizei count, GLsizei primcount)
	glDrawArraysInstancedANGLE(mode, first, count, primcount);
	return NULL;
}

napi_value DrawElementsInstancedANGLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum mode = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	void * indices = nullptr;
	status = getTypedArray(env, args[3], *(void **)&indices);
	if (status != napi_ok) return nullptr;
	GLsizei primcount = getInt32(env, args[4]);
	// void glDrawElementsInstancedANGLE(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount)
	glDrawElementsInstancedANGLE(mode, count, type, indices, primcount);
	return NULL;
}

napi_value VertexAttribDivisorANGLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint index = getUint32(env, args[0]);
	GLuint divisor = getUint32(env, args[1]);
	// void glVertexAttribDivisorANGLE(GLuint index, GLuint divisor)
	glVertexAttribDivisorANGLE(index, divisor);
	return NULL;
}

napi_value BeginQueryANGLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLuint id = getUint32(env, args[1]);
	// void glBeginQueryANGLE(GLenum target, GLuint id)
	glBeginQueryANGLE(target, id);
	return NULL;
}

napi_value DeleteQueriesANGLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* ids;
	// void glDeleteQueriesANGLE(GLsizei n, const GLuint* ids)
	glDeleteQueriesANGLE(n, ids);
	return NULL;
}

napi_value EndQueryANGLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum target = getUint32(env, args[0]);
	// void glEndQueryANGLE(GLenum target)
	glEndQueryANGLE(target);
	return NULL;
}

napi_value GenQueriesANGLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* ids;
	// void glGenQueriesANGLE(GLsizei n, GLuint* ids)
	glGenQueriesANGLE(n, ids);
	return NULL;
}

napi_value IsQueryANGLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint id = getUint32(env, args[0]);
	// GLboolean glIsQueryANGLE(GLuint id)
	GLboolean result = glIsQueryANGLE(id);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value QueryCounterANGLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint id = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	// void glQueryCounterANGLE(GLuint id, GLenum target)
	glQueryCounterANGLE(id, target);
	return NULL;
}

napi_value DrawElementArrayAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum mode = getUint32(env, args[0]);
	GLint first = getInt32(env, args[1]);
	GLsizei count = getInt32(env, args[2]);
	// void glDrawElementArrayAPPLE(GLenum mode, GLint first, GLsizei count)
	glDrawElementArrayAPPLE(mode, first, count);
	return NULL;
}

napi_value DrawRangeElementArrayAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum mode = getUint32(env, args[0]);
	GLuint start = getUint32(env, args[1]);
	GLuint end = getUint32(env, args[2]);
	GLint first = getInt32(env, args[3]);
	GLsizei count = getInt32(env, args[4]);
	// void glDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count)
	glDrawRangeElementArrayAPPLE(mode, start, end, first, count);
	return NULL;
}

napi_value ElementPointerAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum type = getUint32(env, args[0]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[1], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glElementPointerAPPLE(GLenum type, const void *pointer)
	glElementPointerAPPLE(type, pointer);
	return NULL;
}

napi_value MultiDrawElementArrayAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum mode = getUint32(env, args[0]);
	GLint* first;
	GLsizei * count = nullptr;
	status = getTypedArray(env, args[2], count);
	GLsizei primcount = getInt32(env, args[3]);
	// void glMultiDrawElementArrayAPPLE(GLenum mode, const GLint* first, const GLsizei *count, GLsizei primcount)
	glMultiDrawElementArrayAPPLE(mode, first, count, primcount);
	return NULL;
}

napi_value MultiDrawRangeElementArrayAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum mode = getUint32(env, args[0]);
	GLuint start = getUint32(env, args[1]);
	GLuint end = getUint32(env, args[2]);
	GLint* first;
	GLsizei * count = nullptr;
	status = getTypedArray(env, args[4], count);
	GLsizei primcount = getInt32(env, args[5]);
	// void glMultiDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, const GLint* first, const GLsizei *count, GLsizei primcount)
	glMultiDrawRangeElementArrayAPPLE(mode, start, end, first, count, primcount);
	return NULL;
}

napi_value DeleteFencesAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* fences;
	// void glDeleteFencesAPPLE(GLsizei n, const GLuint* fences)
	glDeleteFencesAPPLE(n, fences);
	return NULL;
}

napi_value FinishFenceAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint fence = getUint32(env, args[0]);
	// void glFinishFenceAPPLE(GLuint fence)
	glFinishFenceAPPLE(fence);
	return NULL;
}

napi_value FinishObjectAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum object = getUint32(env, args[0]);
	GLint name = getInt32(env, args[1]);
	// void glFinishObjectAPPLE(GLenum object, GLint name)
	glFinishObjectAPPLE(object, name);
	return NULL;
}

napi_value GenFencesAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* fences;
	// void glGenFencesAPPLE(GLsizei n, GLuint* fences)
	glGenFencesAPPLE(n, fences);
	return NULL;
}

napi_value IsFenceAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint fence = getUint32(env, args[0]);
	// GLboolean glIsFenceAPPLE(GLuint fence)
	GLboolean result = glIsFenceAPPLE(fence);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value SetFenceAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint fence = getUint32(env, args[0]);
	// void glSetFenceAPPLE(GLuint fence)
	glSetFenceAPPLE(fence);
	return NULL;
}

napi_value TestFenceAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint fence = getUint32(env, args[0]);
	// GLboolean glTestFenceAPPLE(GLuint fence)
	GLboolean result = glTestFenceAPPLE(fence);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value TestObjectAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum object = getUint32(env, args[0]);
	GLuint name = getUint32(env, args[1]);
	// GLboolean glTestObjectAPPLE(GLenum object, GLuint name)
	GLboolean result = glTestObjectAPPLE(object, name);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value BufferParameteriAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint param = getInt32(env, args[2]);
	// void glBufferParameteriAPPLE(GLenum target, GLenum pname, GLint param)
	glBufferParameteriAPPLE(target, pname, param);
	return NULL;
}

napi_value FlushMappedBufferRangeAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLintptr offset = getInt32(env, args[1]);
	GLsizeiptr size = getUint32(env, args[2]);
	// void glFlushMappedBufferRangeAPPLE(GLenum target, GLintptr offset, GLsizeiptr size)
	glFlushMappedBufferRangeAPPLE(target, offset, size);
	return NULL;
}

napi_value ObjectPurgeableAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum objectType = getUint32(env, args[0]);
	GLuint name = getUint32(env, args[1]);
	GLenum option = getUint32(env, args[2]);
	// GLenum glObjectPurgeableAPPLE(GLenum objectType, GLuint name, GLenum option)
	GLenum result = glObjectPurgeableAPPLE(objectType, name, option);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value ObjectUnpurgeableAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum objectType = getUint32(env, args[0]);
	GLuint name = getUint32(env, args[1]);
	GLenum option = getUint32(env, args[2]);
	// GLenum glObjectUnpurgeableAPPLE(GLenum objectType, GLuint name, GLenum option)
	GLenum result = glObjectUnpurgeableAPPLE(objectType, name, option);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value TextureRangeAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLsizei length = getInt32(env, args[1]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[2], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glTextureRangeAPPLE(GLenum target, GLsizei length, void *pointer)
	glTextureRangeAPPLE(target, length, pointer);
	return NULL;
}

napi_value BindVertexArrayAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint array = getUint32(env, args[0]);
	// void glBindVertexArrayAPPLE(GLuint array)
	glBindVertexArrayAPPLE(array);
	return NULL;
}

napi_value DeleteVertexArraysAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* arrays;
	// void glDeleteVertexArraysAPPLE(GLsizei n, const GLuint* arrays)
	glDeleteVertexArraysAPPLE(n, arrays);
	return NULL;
}

napi_value GenVertexArraysAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* arrays;
	// void glGenVertexArraysAPPLE(GLsizei n, const GLuint* arrays)
	glGenVertexArraysAPPLE(n, arrays);
	return NULL;
}

napi_value IsVertexArrayAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint array = getUint32(env, args[0]);
	// GLboolean glIsVertexArrayAPPLE(GLuint array)
	GLboolean result = glIsVertexArrayAPPLE(array);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value FlushVertexArrayRangeAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei length = getInt32(env, args[0]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[1], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glFlushVertexArrayRangeAPPLE(GLsizei length, void *pointer)
	glFlushVertexArrayRangeAPPLE(length, pointer);
	return NULL;
}

napi_value VertexArrayParameteriAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint param = getInt32(env, args[1]);
	// void glVertexArrayParameteriAPPLE(GLenum pname, GLint param)
	glVertexArrayParameteriAPPLE(pname, param);
	return NULL;
}

napi_value VertexArrayRangeAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei length = getInt32(env, args[0]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[1], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glVertexArrayRangeAPPLE(GLsizei length, void *pointer)
	glVertexArrayRangeAPPLE(length, pointer);
	return NULL;
}

napi_value DisableVertexAttribAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint index = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	// void glDisableVertexAttribAPPLE(GLuint index, GLenum pname)
	glDisableVertexAttribAPPLE(index, pname);
	return NULL;
}

napi_value EnableVertexAttribAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint index = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	// void glEnableVertexAttribAPPLE(GLuint index, GLenum pname)
	glEnableVertexAttribAPPLE(index, pname);
	return NULL;
}

napi_value IsVertexAttribEnabledAPPLE(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint index = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	// GLboolean glIsVertexAttribEnabledAPPLE(GLuint index, GLenum pname)
	GLboolean result = glIsVertexAttribEnabledAPPLE(index, pname);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value MemoryBarrierByRegion(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLbitfield barriers = getUint32(env, args[0]);
	// void glMemoryBarrierByRegion(GLbitfield barriers)
	glMemoryBarrierByRegion(barriers);
	return NULL;
}

napi_value DrawArraysInstancedBaseInstance(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum mode = getUint32(env, args[0]);
	GLint first = getInt32(env, args[1]);
	GLsizei count = getInt32(env, args[2]);
	GLsizei primcount = getInt32(env, args[3]);
	GLuint baseinstance = getUint32(env, args[4]);
	// void glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLuint baseinstance)
	glDrawArraysInstancedBaseInstance(mode, first, count, primcount, baseinstance);
	return NULL;
}

napi_value DrawElementsInstancedBaseInstance(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum mode = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	void * indices = nullptr;
	status = getTypedArray(env, args[3], *(void **)&indices);
	if (status != napi_ok) return nullptr;
	GLsizei primcount = getInt32(env, args[4]);
	GLuint baseinstance = getUint32(env, args[5]);
	// void glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount, GLuint baseinstance)
	glDrawElementsInstancedBaseInstance(mode, count, type, indices, primcount, baseinstance);
	return NULL;
}

napi_value DrawElementsInstancedBaseVertexBaseInstance(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLenum mode = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	void * indices = nullptr;
	status = getTypedArray(env, args[3], *(void **)&indices);
	if (status != napi_ok) return nullptr;
	GLsizei primcount = getInt32(env, args[4]);
	GLint basevertex = getInt32(env, args[5]);
	GLuint baseinstance = getUint32(env, args[6]);
	// void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount, GLint basevertex, GLuint baseinstance)
	glDrawElementsInstancedBaseVertexBaseInstance(mode, count, type, indices, primcount, basevertex, baseinstance);
	return NULL;
}

napi_value BindFragDataLocationIndexed(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint program = getUint32(env, args[0]);
	GLuint colorNumber = getUint32(env, args[1]);
	GLuint index = getUint32(env, args[2]);
	GLchar * name = nullptr;
	status = getCharacterArray(env, args[3], name);
	// void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name)
	glBindFragDataLocationIndexed(program, colorNumber, index, name);
	return NULL;
}

napi_value BufferStorage(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLsizeiptr size = getUint32(env, args[1]);
	void * data = nullptr;
	status = getTypedArray(env, args[2], *(void **)&data);
	if (status != napi_ok) return nullptr;
	GLbitfield flags = getUint32(env, args[3]);
	// void glBufferStorage(GLenum target, GLsizeiptr size, const void *data, GLbitfield flags)
	glBufferStorage(target, size, data, flags);
	return NULL;
}

napi_value NamedBufferStorageEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint buffer = getUint32(env, args[0]);
	GLsizeiptr size = getUint32(env, args[1]);
	void * data = nullptr;
	status = getTypedArray(env, args[2], *(void **)&data);
	if (status != napi_ok) return nullptr;
	GLbitfield flags = getUint32(env, args[3]);
	// void glNamedBufferStorageEXT(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags)
	glNamedBufferStorageEXT(buffer, size, data, flags);
	return NULL;
}

napi_value ClearBufferData(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLenum format = getUint32(env, args[2]);
	GLenum type = getUint32(env, args[3]);
	void * data = nullptr;
	status = getTypedArray(env, args[4], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data)
	glClearBufferData(target, internalformat, format, type, data);
	return NULL;
}

napi_value ClearBufferSubData(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLenum target = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLintptr offset = getInt32(env, args[2]);
	GLsizeiptr size = getUint32(env, args[3]);
	GLenum format = getUint32(env, args[4]);
	GLenum type = getUint32(env, args[5]);
	void * data = nullptr;
	status = getTypedArray(env, args[6], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data)
	glClearBufferSubData(target, internalformat, offset, size, format, type, data);
	return NULL;
}

napi_value ClearNamedBufferDataEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint buffer = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLenum format = getUint32(env, args[2]);
	GLenum type = getUint32(env, args[3]);
	void * data = nullptr;
	status = getTypedArray(env, args[4], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glClearNamedBufferDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data)
	glClearNamedBufferDataEXT(buffer, internalformat, format, type, data);
	return NULL;
}

napi_value ClearNamedBufferSubDataEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLuint buffer = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLintptr offset = getInt32(env, args[2]);
	GLsizeiptr size = getUint32(env, args[3]);
	GLenum format = getUint32(env, args[4]);
	GLenum type = getUint32(env, args[5]);
	void * data = nullptr;
	status = getTypedArray(env, args[6], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glClearNamedBufferSubDataEXT(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data)
	glClearNamedBufferSubDataEXT(buffer, internalformat, offset, size, format, type, data);
	return NULL;
}

napi_value ClearTexImage(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint texture = getUint32(env, args[0]);
	GLint level = getInt32(env, args[1]);
	GLenum format = getUint32(env, args[2]);
	GLenum type = getUint32(env, args[3]);
	void * data = nullptr;
	status = getTypedArray(env, args[4], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glClearTexImage(GLuint texture, GLint level, GLenum format, GLenum type, const void *data)
	glClearTexImage(texture, level, format, type, data);
	return NULL;
}

napi_value ClearTexSubImage(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[11];
	size_t argc = checkArgCount(env, info, args, 11, 11);
	GLuint texture = getUint32(env, args[0]);
	GLint level = getInt32(env, args[1]);
	GLint xoffset = getInt32(env, args[2]);
	GLint yoffset = getInt32(env, args[3]);
	GLint zoffset = getInt32(env, args[4]);
	GLsizei width = getInt32(env, args[5]);
	GLsizei height = getInt32(env, args[6]);
	GLsizei depth = getInt32(env, args[7]);
	GLenum format = getUint32(env, args[8]);
	GLenum type = getUint32(env, args[9]);
	void * data = nullptr;
	status = getTypedArray(env, args[10], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glClearTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data)
	glClearTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data);
	return NULL;
}

napi_value ClipControl(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum origin = getUint32(env, args[0]);
	GLenum depth = getUint32(env, args[1]);
	// void glClipControl(GLenum origin, GLenum depth)
	glClipControl(origin, depth);
	return NULL;
}

napi_value DispatchCompute(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint num_groups_x = getUint32(env, args[0]);
	GLuint num_groups_y = getUint32(env, args[1]);
	GLuint num_groups_z = getUint32(env, args[2]);
	// void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z)
	glDispatchCompute(num_groups_x, num_groups_y, num_groups_z);
	return NULL;
}

napi_value DispatchComputeIndirect(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLintptr indirect = getInt32(env, args[0]);
	// void glDispatchComputeIndirect(GLintptr indirect)
	glDispatchComputeIndirect(indirect);
	return NULL;
}

napi_value CopyImageSubData(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[15];
	size_t argc = checkArgCount(env, info, args, 15, 15);
	GLuint srcName = getUint32(env, args[0]);
	GLenum srcTarget = getUint32(env, args[1]);
	GLint srcLevel = getInt32(env, args[2]);
	GLint srcX = getInt32(env, args[3]);
	GLint srcY = getInt32(env, args[4]);
	GLint srcZ = getInt32(env, args[5]);
	GLuint dstName = getUint32(env, args[6]);
	GLenum dstTarget = getUint32(env, args[7]);
	GLint dstLevel = getInt32(env, args[8]);
	GLint dstX = getInt32(env, args[9]);
	GLint dstY = getInt32(env, args[10]);
	GLint dstZ = getInt32(env, args[11]);
	GLsizei srcWidth = getInt32(env, args[12]);
	GLsizei srcHeight = getInt32(env, args[13]);
	GLsizei srcDepth = getInt32(env, args[14]);
	// void glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)
	glCopyImageSubData(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
	return NULL;
}

napi_value BindTextureUnit(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint unit = getUint32(env, args[0]);
	GLuint texture = getUint32(env, args[1]);
	// void glBindTextureUnit(GLuint unit, GLuint texture)
	glBindTextureUnit(unit, texture);
	return NULL;
}

napi_value BlitNamedFramebuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[12];
	size_t argc = checkArgCount(env, info, args, 12, 12);
	GLuint readFramebuffer = getUint32(env, args[0]);
	GLuint drawFramebuffer = getUint32(env, args[1]);
	GLint srcX0 = getInt32(env, args[2]);
	GLint srcY0 = getInt32(env, args[3]);
	GLint srcX1 = getInt32(env, args[4]);
	GLint srcY1 = getInt32(env, args[5]);
	GLint dstX0 = getInt32(env, args[6]);
	GLint dstY0 = getInt32(env, args[7]);
	GLint dstX1 = getInt32(env, args[8]);
	GLint dstY1 = getInt32(env, args[9]);
	GLbitfield mask = getUint32(env, args[10]);
	GLenum filter = getUint32(env, args[11]);
	// void glBlitNamedFramebuffer(GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
	glBlitNamedFramebuffer(readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
	return NULL;
}

napi_value CheckNamedFramebufferStatus(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	// GLenum glCheckNamedFramebufferStatus(GLuint framebuffer, GLenum target)
	GLenum result = glCheckNamedFramebufferStatus(framebuffer, target);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value ClearNamedBufferData(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint buffer = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLenum format = getUint32(env, args[2]);
	GLenum type = getUint32(env, args[3]);
	void * data = nullptr;
	status = getTypedArray(env, args[4], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glClearNamedBufferData(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data)
	glClearNamedBufferData(buffer, internalformat, format, type, data);
	return NULL;
}

napi_value ClearNamedBufferSubData(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLuint buffer = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLintptr offset = getInt32(env, args[2]);
	GLsizeiptr size = getUint32(env, args[3]);
	GLenum format = getUint32(env, args[4]);
	GLenum type = getUint32(env, args[5]);
	void * data = nullptr;
	status = getTypedArray(env, args[6], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glClearNamedBufferSubData(GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data)
	glClearNamedBufferSubData(buffer, internalformat, offset, size, format, type, data);
	return NULL;
}

napi_value ClearNamedFramebufferfi(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum buffer = getUint32(env, args[1]);
	GLfloat depth = getDouble(env, args[2]);
	GLint stencil = getInt32(env, args[3]);
	// void glClearNamedFramebufferfi(GLuint framebuffer, GLenum buffer, GLfloat depth, GLint stencil)
	glClearNamedFramebufferfi(framebuffer, buffer, depth, stencil);
	return NULL;
}

napi_value ClearNamedFramebufferfv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum buffer = getUint32(env, args[1]);
	GLint drawbuffer = getInt32(env, args[2]);
	GLfloat* value;
	// void glClearNamedFramebufferfv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value)
	glClearNamedFramebufferfv(framebuffer, buffer, drawbuffer, value);
	return NULL;
}

napi_value ClearNamedFramebufferiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum buffer = getUint32(env, args[1]);
	GLint drawbuffer = getInt32(env, args[2]);
	GLint* value;
	// void glClearNamedFramebufferiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value)
	glClearNamedFramebufferiv(framebuffer, buffer, drawbuffer, value);
	return NULL;
}

napi_value ClearNamedFramebufferuiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum buffer = getUint32(env, args[1]);
	GLint drawbuffer = getInt32(env, args[2]);
	GLuint* value;
	// void glClearNamedFramebufferuiv(GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value)
	glClearNamedFramebufferuiv(framebuffer, buffer, drawbuffer, value);
	return NULL;
}

napi_value CopyNamedBufferSubData(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint readBuffer = getUint32(env, args[0]);
	GLuint writeBuffer = getUint32(env, args[1]);
	GLintptr readOffset = getInt32(env, args[2]);
	GLintptr writeOffset = getInt32(env, args[3]);
	GLsizeiptr size = getUint32(env, args[4]);
	// void glCopyNamedBufferSubData(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
	glCopyNamedBufferSubData(readBuffer, writeBuffer, readOffset, writeOffset, size);
	return NULL;
}

napi_value CreateBuffers(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* buffers;
	// void glCreateBuffers(GLsizei n, GLuint* buffers)
	glCreateBuffers(n, buffers);
	return NULL;
}

napi_value CreateFramebuffers(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* framebuffers;
	// void glCreateFramebuffers(GLsizei n, GLuint* framebuffers)
	glCreateFramebuffers(n, framebuffers);
	return NULL;
}

napi_value CreateProgramPipelines(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* pipelines;
	// void glCreateProgramPipelines(GLsizei n, GLuint* pipelines)
	glCreateProgramPipelines(n, pipelines);
	return NULL;
}

napi_value CreateQueries(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLsizei n = getInt32(env, args[1]);
	GLuint* ids;
	// void glCreateQueries(GLenum target, GLsizei n, GLuint* ids)
	glCreateQueries(target, n, ids);
	return NULL;
}

napi_value CreateRenderbuffers(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* renderbuffers;
	// void glCreateRenderbuffers(GLsizei n, GLuint* renderbuffers)
	glCreateRenderbuffers(n, renderbuffers);
	return NULL;
}

napi_value CreateSamplers(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* samplers;
	// void glCreateSamplers(GLsizei n, GLuint* samplers)
	glCreateSamplers(n, samplers);
	return NULL;
}

napi_value CreateTextures(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLsizei n = getInt32(env, args[1]);
	GLuint* textures;
	// void glCreateTextures(GLenum target, GLsizei n, GLuint* textures)
	glCreateTextures(target, n, textures);
	return NULL;
}

napi_value CreateTransformFeedbacks(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* ids;
	// void glCreateTransformFeedbacks(GLsizei n, GLuint* ids)
	glCreateTransformFeedbacks(n, ids);
	return NULL;
}

napi_value CreateVertexArrays(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* arrays;
	// void glCreateVertexArrays(GLsizei n, GLuint* arrays)
	glCreateVertexArrays(n, arrays);
	return NULL;
}

napi_value DisableVertexArrayAttrib(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	// void glDisableVertexArrayAttrib(GLuint vaobj, GLuint index)
	glDisableVertexArrayAttrib(vaobj, index);
	return NULL;
}

napi_value EnableVertexArrayAttrib(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	// void glEnableVertexArrayAttrib(GLuint vaobj, GLuint index)
	glEnableVertexArrayAttrib(vaobj, index);
	return NULL;
}

napi_value FlushMappedNamedBufferRange(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint buffer = getUint32(env, args[0]);
	GLintptr offset = getInt32(env, args[1]);
	GLsizeiptr length = getUint32(env, args[2]);
	// void glFlushMappedNamedBufferRange(GLuint buffer, GLintptr offset, GLsizeiptr length)
	glFlushMappedNamedBufferRange(buffer, offset, length);
	return NULL;
}

napi_value GenerateTextureMipmap(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint texture = getUint32(env, args[0]);
	// void glGenerateTextureMipmap(GLuint texture)
	glGenerateTextureMipmap(texture);
	return NULL;
}

napi_value InvalidateNamedFramebufferData(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint framebuffer = getUint32(env, args[0]);
	GLsizei numAttachments = getInt32(env, args[1]);
	GLenum* attachments;
	// void glInvalidateNamedFramebufferData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments)
	glInvalidateNamedFramebufferData(framebuffer, numAttachments, attachments);
	return NULL;
}

napi_value InvalidateNamedFramebufferSubData(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLuint framebuffer = getUint32(env, args[0]);
	GLsizei numAttachments = getInt32(env, args[1]);
	GLenum* attachments;
	GLint x = getInt32(env, args[3]);
	GLint y = getInt32(env, args[4]);
	GLsizei width = getInt32(env, args[5]);
	GLsizei height = getInt32(env, args[6]);
	// void glInvalidateNamedFramebufferSubData(GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height)
	glInvalidateNamedFramebufferSubData(framebuffer, numAttachments, attachments, x, y, width, height);
	return NULL;
}

napi_value NamedBufferData(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint buffer = getUint32(env, args[0]);
	GLsizeiptr size = getUint32(env, args[1]);
	void * data = nullptr;
	status = getTypedArray(env, args[2], *(void **)&data);
	if (status != napi_ok) return nullptr;
	GLenum usage = getUint32(env, args[3]);
	// void glNamedBufferData(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage)
	glNamedBufferData(buffer, size, data, usage);
	return NULL;
}

napi_value NamedBufferStorage(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint buffer = getUint32(env, args[0]);
	GLsizeiptr size = getUint32(env, args[1]);
	void * data = nullptr;
	status = getTypedArray(env, args[2], *(void **)&data);
	if (status != napi_ok) return nullptr;
	GLbitfield flags = getUint32(env, args[3]);
	// void glNamedBufferStorage(GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags)
	glNamedBufferStorage(buffer, size, data, flags);
	return NULL;
}

napi_value NamedBufferSubData(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint buffer = getUint32(env, args[0]);
	GLintptr offset = getInt32(env, args[1]);
	GLsizeiptr size = getUint32(env, args[2]);
	void * data = nullptr;
	status = getTypedArray(env, args[3], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glNamedBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data)
	glNamedBufferSubData(buffer, offset, size, data);
	return NULL;
}

napi_value NamedFramebufferDrawBuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum mode = getUint32(env, args[1]);
	// void glNamedFramebufferDrawBuffer(GLuint framebuffer, GLenum mode)
	glNamedFramebufferDrawBuffer(framebuffer, mode);
	return NULL;
}

napi_value NamedFramebufferDrawBuffers(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint framebuffer = getUint32(env, args[0]);
	GLsizei n = getInt32(env, args[1]);
	GLenum* bufs;
	// void glNamedFramebufferDrawBuffers(GLuint framebuffer, GLsizei n, const GLenum* bufs)
	glNamedFramebufferDrawBuffers(framebuffer, n, bufs);
	return NULL;
}

napi_value NamedFramebufferParameteri(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint param = getInt32(env, args[2]);
	// void glNamedFramebufferParameteri(GLuint framebuffer, GLenum pname, GLint param)
	glNamedFramebufferParameteri(framebuffer, pname, param);
	return NULL;
}

napi_value NamedFramebufferReadBuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum mode = getUint32(env, args[1]);
	// void glNamedFramebufferReadBuffer(GLuint framebuffer, GLenum mode)
	glNamedFramebufferReadBuffer(framebuffer, mode);
	return NULL;
}

napi_value NamedFramebufferRenderbuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum attachment = getUint32(env, args[1]);
	GLenum renderbuffertarget = getUint32(env, args[2]);
	GLuint renderbuffer = getUint32(env, args[3]);
	// void glNamedFramebufferRenderbuffer(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
	glNamedFramebufferRenderbuffer(framebuffer, attachment, renderbuffertarget, renderbuffer);
	return NULL;
}

napi_value NamedFramebufferTexture(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum attachment = getUint32(env, args[1]);
	GLuint texture = getUint32(env, args[2]);
	GLint level = getInt32(env, args[3]);
	// void glNamedFramebufferTexture(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level)
	glNamedFramebufferTexture(framebuffer, attachment, texture, level);
	return NULL;
}

napi_value NamedFramebufferTextureLayer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum attachment = getUint32(env, args[1]);
	GLuint texture = getUint32(env, args[2]);
	GLint level = getInt32(env, args[3]);
	GLint layer = getInt32(env, args[4]);
	// void glNamedFramebufferTextureLayer(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer)
	glNamedFramebufferTextureLayer(framebuffer, attachment, texture, level, layer);
	return NULL;
}

napi_value NamedRenderbufferStorage(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint renderbuffer = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLsizei width = getInt32(env, args[2]);
	GLsizei height = getInt32(env, args[3]);
	// void glNamedRenderbufferStorage(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height)
	glNamedRenderbufferStorage(renderbuffer, internalformat, width, height);
	return NULL;
}

napi_value NamedRenderbufferStorageMultisample(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint renderbuffer = getUint32(env, args[0]);
	GLsizei samples = getInt32(env, args[1]);
	GLenum internalformat = getUint32(env, args[2]);
	GLsizei width = getInt32(env, args[3]);
	GLsizei height = getInt32(env, args[4]);
	// void glNamedRenderbufferStorageMultisample(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
	glNamedRenderbufferStorageMultisample(renderbuffer, samples, internalformat, width, height);
	return NULL;
}

napi_value TextureBuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint texture = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	// void glTextureBuffer(GLuint texture, GLenum internalformat, GLuint buffer)
	glTextureBuffer(texture, internalformat, buffer);
	return NULL;
}

napi_value TextureBufferRange(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint texture = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	GLintptr offset = getInt32(env, args[3]);
	GLsizeiptr size = getUint32(env, args[4]);
	// void glTextureBufferRange(GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)
	glTextureBufferRange(texture, internalformat, buffer, offset, size);
	return NULL;
}

napi_value TextureParameterIiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint texture = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint* params;
	// void glTextureParameterIiv(GLuint texture, GLenum pname, const GLint* params)
	glTextureParameterIiv(texture, pname, params);
	return NULL;
}

napi_value TextureParameterIuiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint texture = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLuint* params;
	// void glTextureParameterIuiv(GLuint texture, GLenum pname, const GLuint* params)
	glTextureParameterIuiv(texture, pname, params);
	return NULL;
}

napi_value TextureParameterf(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint texture = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat param = getDouble(env, args[2]);
	// void glTextureParameterf(GLuint texture, GLenum pname, GLfloat param)
	glTextureParameterf(texture, pname, param);
	return NULL;
}

napi_value TextureParameterfv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint texture = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat* param;
	// void glTextureParameterfv(GLuint texture, GLenum pname, const GLfloat* param)
	glTextureParameterfv(texture, pname, param);
	return NULL;
}

napi_value TextureParameteri(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint texture = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint param = getInt32(env, args[2]);
	// void glTextureParameteri(GLuint texture, GLenum pname, GLint param)
	glTextureParameteri(texture, pname, param);
	return NULL;
}

napi_value TextureParameteriv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint texture = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint* param;
	// void glTextureParameteriv(GLuint texture, GLenum pname, const GLint* param)
	glTextureParameteriv(texture, pname, param);
	return NULL;
}

napi_value TransformFeedbackBufferBase(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint xfb = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	// void glTransformFeedbackBufferBase(GLuint xfb, GLuint index, GLuint buffer)
	glTransformFeedbackBufferBase(xfb, index, buffer);
	return NULL;
}

napi_value TransformFeedbackBufferRange(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint xfb = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	GLintptr offset = getInt32(env, args[3]);
	GLsizeiptr size = getUint32(env, args[4]);
	// void glTransformFeedbackBufferRange(GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
	glTransformFeedbackBufferRange(xfb, index, buffer, offset, size);
	return NULL;
}

napi_value UnmapNamedBuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint buffer = getUint32(env, args[0]);
	// GLboolean glUnmapNamedBuffer(GLuint buffer)
	GLboolean result = glUnmapNamedBuffer(buffer);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value VertexArrayAttribBinding(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint attribindex = getUint32(env, args[1]);
	GLuint bindingindex = getUint32(env, args[2]);
	// void glVertexArrayAttribBinding(GLuint vaobj, GLuint attribindex, GLuint bindingindex)
	glVertexArrayAttribBinding(vaobj, attribindex, bindingindex);
	return NULL;
}

napi_value VertexArrayAttribFormat(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint attribindex = getUint32(env, args[1]);
	GLint size = getInt32(env, args[2]);
	GLenum type = getUint32(env, args[3]);
	GLboolean normalized = getBool(env, args[4]);
	GLuint relativeoffset = getUint32(env, args[5]);
	// void glVertexArrayAttribFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
	glVertexArrayAttribFormat(vaobj, attribindex, size, type, normalized, relativeoffset);
	return NULL;
}

napi_value VertexArrayAttribIFormat(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint attribindex = getUint32(env, args[1]);
	GLint size = getInt32(env, args[2]);
	GLenum type = getUint32(env, args[3]);
	GLuint relativeoffset = getUint32(env, args[4]);
	// void glVertexArrayAttribIFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
	glVertexArrayAttribIFormat(vaobj, attribindex, size, type, relativeoffset);
	return NULL;
}

napi_value VertexArrayAttribLFormat(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint attribindex = getUint32(env, args[1]);
	GLint size = getInt32(env, args[2]);
	GLenum type = getUint32(env, args[3]);
	GLuint relativeoffset = getUint32(env, args[4]);
	// void glVertexArrayAttribLFormat(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
	glVertexArrayAttribLFormat(vaobj, attribindex, size, type, relativeoffset);
	return NULL;
}

napi_value VertexArrayBindingDivisor(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint bindingindex = getUint32(env, args[1]);
	GLuint divisor = getUint32(env, args[2]);
	// void glVertexArrayBindingDivisor(GLuint vaobj, GLuint bindingindex, GLuint divisor)
	glVertexArrayBindingDivisor(vaobj, bindingindex, divisor);
	return NULL;
}

napi_value VertexArrayElementBuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	// void glVertexArrayElementBuffer(GLuint vaobj, GLuint buffer)
	glVertexArrayElementBuffer(vaobj, buffer);
	return NULL;
}

napi_value VertexArrayVertexBuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint bindingindex = getUint32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	GLintptr offset = getInt32(env, args[3]);
	GLsizei stride = getInt32(env, args[4]);
	// void glVertexArrayVertexBuffer(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
	glVertexArrayVertexBuffer(vaobj, bindingindex, buffer, offset, stride);
	return NULL;
}

napi_value VertexArrayVertexBuffers(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint first = getUint32(env, args[1]);
	GLsizei count = getInt32(env, args[2]);
	GLuint* buffers;
	GLintptr * offsets;
	GLsizei * strides = nullptr;
	status = getTypedArray(env, args[5], strides);
	// void glVertexArrayVertexBuffers(GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr *offsets, const GLsizei *strides)
	glVertexArrayVertexBuffers(vaobj, first, count, buffers, offsets, strides);
	return NULL;
}

napi_value DrawElementsBaseVertex(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum mode = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	void * indices = nullptr;
	status = getTypedArray(env, args[3], *(void **)&indices);
	if (status != napi_ok) return nullptr;
	GLint basevertex = getInt32(env, args[4]);
	// void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex)
	glDrawElementsBaseVertex(mode, count, type, indices, basevertex);
	return NULL;
}

napi_value DrawElementsInstancedBaseVertex(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum mode = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	void * indices = nullptr;
	status = getTypedArray(env, args[3], *(void **)&indices);
	if (status != napi_ok) return nullptr;
	GLsizei primcount = getInt32(env, args[4]);
	GLint basevertex = getInt32(env, args[5]);
	// void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount, GLint basevertex)
	glDrawElementsInstancedBaseVertex(mode, count, type, indices, primcount, basevertex);
	return NULL;
}

napi_value DrawRangeElementsBaseVertex(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLenum mode = getUint32(env, args[0]);
	GLuint start = getUint32(env, args[1]);
	GLuint end = getUint32(env, args[2]);
	GLsizei count = getInt32(env, args[3]);
	GLenum type = getUint32(env, args[4]);
	void * indices = nullptr;
	status = getTypedArray(env, args[5], *(void **)&indices);
	if (status != napi_ok) return nullptr;
	GLint basevertex = getInt32(env, args[6]);
	// void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex)
	glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex);
	return NULL;
}

napi_value MultiDrawElementsBaseVertex(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum mode = getUint32(env, args[0]);
	GLsizei* count;
	GLenum type = getUint32(env, args[2]);
	void * * indices;
	GLsizei primcount = getInt32(env, args[4]);
	GLint * basevertex = nullptr;
	status = getTypedArray(env, args[5], basevertex);
	// void glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei* count, GLenum type, const void *const *indices, GLsizei primcount, const GLint *basevertex)
	glMultiDrawElementsBaseVertex(mode, count, type, indices, primcount, basevertex);
	return NULL;
}

napi_value DrawArraysIndirect(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum mode = getUint32(env, args[0]);
	void * indirect = nullptr;
	status = getTypedArray(env, args[1], *(void **)&indirect);
	if (status != napi_ok) return nullptr;
	// void glDrawArraysIndirect(GLenum mode, const void *indirect)
	glDrawArraysIndirect(mode, indirect);
	return NULL;
}

napi_value DrawElementsIndirect(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum mode = getUint32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	void * indirect = nullptr;
	status = getTypedArray(env, args[2], *(void **)&indirect);
	if (status != napi_ok) return nullptr;
	// void glDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect)
	glDrawElementsIndirect(mode, type, indirect);
	return NULL;
}

napi_value FramebufferParameteri(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint param = getInt32(env, args[2]);
	// void glFramebufferParameteri(GLenum target, GLenum pname, GLint param)
	glFramebufferParameteri(target, pname, param);
	return NULL;
}

napi_value NamedFramebufferParameteriEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint param = getInt32(env, args[2]);
	// void glNamedFramebufferParameteriEXT(GLuint framebuffer, GLenum pname, GLint param)
	glNamedFramebufferParameteriEXT(framebuffer, pname, param);
	return NULL;
}

napi_value ColorSubTable(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum target = getUint32(env, args[0]);
	GLsizei start = getInt32(env, args[1]);
	GLsizei count = getInt32(env, args[2]);
	GLenum format = getUint32(env, args[3]);
	GLenum type = getUint32(env, args[4]);
	void * data = nullptr;
	status = getTypedArray(env, args[5], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data)
	glColorSubTable(target, start, count, format, type, data);
	return NULL;
}

napi_value ColorTable(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum target = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLsizei width = getInt32(env, args[2]);
	GLenum format = getUint32(env, args[3]);
	GLenum type = getUint32(env, args[4]);
	void * table = nullptr;
	status = getTypedArray(env, args[5], *(void **)&table);
	if (status != napi_ok) return nullptr;
	// void glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table)
	glColorTable(target, internalformat, width, format, type, table);
	return NULL;
}

napi_value ColorTableParameterfv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat * params = nullptr;
	status = getTypedArray(env, args[2], params);
	// void glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat *params)
	glColorTableParameterfv(target, pname, params);
	return NULL;
}

napi_value ColorTableParameteriv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint * params = nullptr;
	status = getTypedArray(env, args[2], params);
	// void glColorTableParameteriv(GLenum target, GLenum pname, const GLint *params)
	glColorTableParameteriv(target, pname, params);
	return NULL;
}

napi_value ConvolutionParameterf(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat params = getDouble(env, args[2]);
	// void glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params)
	glConvolutionParameterf(target, pname, params);
	return NULL;
}

napi_value ConvolutionParameterfv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat * params = nullptr;
	status = getTypedArray(env, args[2], params);
	// void glConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat *params)
	glConvolutionParameterfv(target, pname, params);
	return NULL;
}

napi_value ConvolutionParameteri(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint params = getInt32(env, args[2]);
	// void glConvolutionParameteri(GLenum target, GLenum pname, GLint params)
	glConvolutionParameteri(target, pname, params);
	return NULL;
}

napi_value ConvolutionParameteriv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint * params = nullptr;
	status = getTypedArray(env, args[2], params);
	// void glConvolutionParameteriv(GLenum target, GLenum pname, const GLint *params)
	glConvolutionParameteriv(target, pname, params);
	return NULL;
}

napi_value CopyColorSubTable(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLsizei start = getInt32(env, args[1]);
	GLint x = getInt32(env, args[2]);
	GLint y = getInt32(env, args[3]);
	GLsizei width = getInt32(env, args[4]);
	// void glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width)
	glCopyColorSubTable(target, start, x, y, width);
	return NULL;
}

napi_value CopyColorTable(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLint x = getInt32(env, args[2]);
	GLint y = getInt32(env, args[3]);
	GLsizei width = getInt32(env, args[4]);
	// void glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width)
	glCopyColorTable(target, internalformat, x, y, width);
	return NULL;
}

napi_value Histogram(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLsizei width = getInt32(env, args[1]);
	GLenum internalformat = getUint32(env, args[2]);
	GLboolean sink = getBool(env, args[3]);
	// void glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink)
	glHistogram(target, width, internalformat, sink);
	return NULL;
}

napi_value Minmax(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLboolean sink = getBool(env, args[2]);
	// void glMinmax(GLenum target, GLenum internalformat, GLboolean sink)
	glMinmax(target, internalformat, sink);
	return NULL;
}

napi_value ResetHistogram(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum target = getUint32(env, args[0]);
	// void glResetHistogram(GLenum target)
	glResetHistogram(target);
	return NULL;
}

napi_value ResetMinmax(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum target = getUint32(env, args[0]);
	// void glResetMinmax(GLenum target)
	glResetMinmax(target);
	return NULL;
}

napi_value InvalidateBufferData(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint buffer = getUint32(env, args[0]);
	// void glInvalidateBufferData(GLuint buffer)
	glInvalidateBufferData(buffer);
	return NULL;
}

napi_value InvalidateBufferSubData(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint buffer = getUint32(env, args[0]);
	GLintptr offset = getInt32(env, args[1]);
	GLsizeiptr length = getUint32(env, args[2]);
	// void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length)
	glInvalidateBufferSubData(buffer, offset, length);
	return NULL;
}

napi_value InvalidateTexImage(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint texture = getUint32(env, args[0]);
	GLint level = getInt32(env, args[1]);
	// void glInvalidateTexImage(GLuint texture, GLint level)
	glInvalidateTexImage(texture, level);
	return NULL;
}

napi_value InvalidateTexSubImage(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[8];
	size_t argc = checkArgCount(env, info, args, 8, 8);
	GLuint texture = getUint32(env, args[0]);
	GLint level = getInt32(env, args[1]);
	GLint xoffset = getInt32(env, args[2]);
	GLint yoffset = getInt32(env, args[3]);
	GLint zoffset = getInt32(env, args[4]);
	GLsizei width = getInt32(env, args[5]);
	GLsizei height = getInt32(env, args[6]);
	GLsizei depth = getInt32(env, args[7]);
	// void glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth)
	glInvalidateTexSubImage(texture, level, xoffset, yoffset, zoffset, width, height, depth);
	return NULL;
}

napi_value BindBuffersBase(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLuint first = getUint32(env, args[1]);
	GLsizei count = getInt32(env, args[2]);
	GLuint* buffers;
	// void glBindBuffersBase(GLenum target, GLuint first, GLsizei count, const GLuint* buffers)
	glBindBuffersBase(target, first, count, buffers);
	return NULL;
}

napi_value BindBuffersRange(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum target = getUint32(env, args[0]);
	GLuint first = getUint32(env, args[1]);
	GLsizei count = getInt32(env, args[2]);
	GLuint* buffers;
	GLintptr * offsets;
	GLsizeiptr * sizes;
	// void glBindBuffersRange(GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr *offsets, const GLsizeiptr *sizes)
	glBindBuffersRange(target, first, count, buffers, offsets, sizes);
	return NULL;
}

napi_value BindImageTextures(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint first = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLuint* textures;
	// void glBindImageTextures(GLuint first, GLsizei count, const GLuint* textures)
	glBindImageTextures(first, count, textures);
	return NULL;
}

napi_value BindSamplers(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint first = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLuint* samplers;
	// void glBindSamplers(GLuint first, GLsizei count, const GLuint* samplers)
	glBindSamplers(first, count, samplers);
	return NULL;
}

napi_value BindTextures(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint first = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLuint* textures;
	// void glBindTextures(GLuint first, GLsizei count, const GLuint* textures)
	glBindTextures(first, count, textures);
	return NULL;
}

napi_value BindVertexBuffers(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint first = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLuint* buffers;
	GLintptr * offsets;
	GLsizei * strides = nullptr;
	status = getTypedArray(env, args[4], strides);
	// void glBindVertexBuffers(GLuint first, GLsizei count, const GLuint* buffers, const GLintptr *offsets, const GLsizei *strides)
	glBindVertexBuffers(first, count, buffers, offsets, strides);
	return NULL;
}

napi_value MultiDrawArraysIndirect(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum mode = getUint32(env, args[0]);
	void * indirect = nullptr;
	status = getTypedArray(env, args[1], *(void **)&indirect);
	if (status != napi_ok) return nullptr;
	GLsizei primcount = getInt32(env, args[2]);
	GLsizei stride = getInt32(env, args[3]);
	// void glMultiDrawArraysIndirect(GLenum mode, const void *indirect, GLsizei primcount, GLsizei stride)
	glMultiDrawArraysIndirect(mode, indirect, primcount, stride);
	return NULL;
}

napi_value MultiDrawElementsIndirect(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum mode = getUint32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	void * indirect = nullptr;
	status = getTypedArray(env, args[2], *(void **)&indirect);
	if (status != napi_ok) return nullptr;
	GLsizei primcount = getInt32(env, args[3]);
	GLsizei stride = getInt32(env, args[4]);
	// void glMultiDrawElementsIndirect(GLenum mode, GLenum type, const void *indirect, GLsizei primcount, GLsizei stride)
	glMultiDrawElementsIndirect(mode, type, indirect, primcount, stride);
	return NULL;
}

napi_value ProvokingVertex(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum mode = getUint32(env, args[0]);
	// void glProvokingVertex(GLenum mode)
	glProvokingVertex(mode);
	return NULL;
}

napi_value SamplerParameterIiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint sampler = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint* params;
	// void glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint* params)
	glSamplerParameterIiv(sampler, pname, params);
	return NULL;
}

napi_value SamplerParameterIuiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint sampler = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLuint* params;
	// void glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint* params)
	glSamplerParameterIuiv(sampler, pname, params);
	return NULL;
}

napi_value ActiveShaderProgram(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint pipeline = getUint32(env, args[0]);
	GLuint program = getUint32(env, args[1]);
	// void glActiveShaderProgram(GLuint pipeline, GLuint program)
	glActiveShaderProgram(pipeline, program);
	return NULL;
}

napi_value BindProgramPipeline(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint pipeline = getUint32(env, args[0]);
	// void glBindProgramPipeline(GLuint pipeline)
	glBindProgramPipeline(pipeline);
	return NULL;
}

napi_value CreateShaderProgramv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum type = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLchar *  * strings;
	// GLuint glCreateShaderProgramv(GLenum type, GLsizei count, const GLchar * const * strings)
	GLuint result = glCreateShaderProgramv(type, count, strings);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value DeleteProgramPipelines(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* pipelines;
	// void glDeleteProgramPipelines(GLsizei n, const GLuint* pipelines)
	glDeleteProgramPipelines(n, pipelines);
	return NULL;
}

napi_value GenProgramPipelines(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* pipelines;
	// void glGenProgramPipelines(GLsizei n, GLuint* pipelines)
	glGenProgramPipelines(n, pipelines);
	return NULL;
}

napi_value IsProgramPipeline(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint pipeline = getUint32(env, args[0]);
	// GLboolean glIsProgramPipeline(GLuint pipeline)
	GLboolean result = glIsProgramPipeline(pipeline);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value UseProgramStages(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint pipeline = getUint32(env, args[0]);
	GLbitfield stages = getUint32(env, args[1]);
	GLuint program = getUint32(env, args[2]);
	// void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program)
	glUseProgramStages(pipeline, stages, program);
	return NULL;
}

napi_value ValidateProgramPipeline(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint pipeline = getUint32(env, args[0]);
	// void glValidateProgramPipeline(GLuint pipeline)
	glValidateProgramPipeline(pipeline);
	return NULL;
}

napi_value BindImageTexture(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLuint unit = getUint32(env, args[0]);
	GLuint texture = getUint32(env, args[1]);
	GLint level = getInt32(env, args[2]);
	GLboolean layered = getBool(env, args[3]);
	GLint layer = getInt32(env, args[4]);
	GLenum access = getUint32(env, args[5]);
	GLenum format = getUint32(env, args[6]);
	// void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format)
	glBindImageTexture(unit, texture, level, layered, layer, access, format);
	return NULL;
}

napi_value MemoryBarrier(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLbitfield barriers = getUint32(env, args[0]);
	// void glMemoryBarrier(GLbitfield barriers)
	glMemoryBarrier(barriers);
	return NULL;
}

napi_value ShaderStorageBlockBinding(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint program = getUint32(env, args[0]);
	GLuint storageBlockIndex = getUint32(env, args[1]);
	GLuint storageBlockBinding = getUint32(env, args[2]);
	// void glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding)
	glShaderStorageBlockBinding(program, storageBlockIndex, storageBlockBinding);
	return NULL;
}

napi_value UniformSubroutinesuiv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum shadertype = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLuint* indices;
	// void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint* indices)
	glUniformSubroutinesuiv(shadertype, count, indices);
	return NULL;
}

napi_value TexturePageCommitmentEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[9];
	size_t argc = checkArgCount(env, info, args, 9, 9);
	GLuint texture = getUint32(env, args[0]);
	GLint level = getInt32(env, args[1]);
	GLint xoffset = getInt32(env, args[2]);
	GLint yoffset = getInt32(env, args[3]);
	GLint zoffset = getInt32(env, args[4]);
	GLsizei width = getInt32(env, args[5]);
	GLsizei height = getInt32(env, args[6]);
	GLsizei depth = getInt32(env, args[7]);
	GLboolean commit = getBool(env, args[8]);
	// void glTexturePageCommitmentEXT(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit)
	glTexturePageCommitmentEXT(texture, level, xoffset, yoffset, zoffset, width, height, depth, commit);
	return NULL;
}

napi_value PatchParameterfv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat* values;
	// void glPatchParameterfv(GLenum pname, const GLfloat* values)
	glPatchParameterfv(pname, values);
	return NULL;
}

napi_value PatchParameteri(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint value = getInt32(env, args[1]);
	// void glPatchParameteri(GLenum pname, GLint value)
	glPatchParameteri(pname, value);
	return NULL;
}

napi_value TextureBarrier(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glTextureBarrier(void)
	glTextureBarrier();
	return NULL;
}

napi_value TexBufferRange(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	GLintptr offset = getInt32(env, args[3]);
	GLsizeiptr size = getUint32(env, args[4]);
	// void glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)
	glTexBufferRange(target, internalformat, buffer, offset, size);
	return NULL;
}

napi_value TextureBufferRangeEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLuint texture = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum internalformat = getUint32(env, args[2]);
	GLuint buffer = getUint32(env, args[3]);
	GLintptr offset = getInt32(env, args[4]);
	GLsizeiptr size = getUint32(env, args[5]);
	// void glTextureBufferRangeEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size)
	glTextureBufferRangeEXT(texture, target, internalformat, buffer, offset, size);
	return NULL;
}

napi_value SampleMaski(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint index = getUint32(env, args[0]);
	GLbitfield mask = getUint32(env, args[1]);
	// void glSampleMaski(GLuint index, GLbitfield mask)
	glSampleMaski(index, mask);
	return NULL;
}

napi_value TextureView(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[8];
	size_t argc = checkArgCount(env, info, args, 8, 8);
	GLuint texture = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLuint origtexture = getUint32(env, args[2]);
	GLenum internalformat = getUint32(env, args[3]);
	GLuint minlevel = getUint32(env, args[4]);
	GLuint numlevels = getUint32(env, args[5]);
	GLuint minlayer = getUint32(env, args[6]);
	GLuint numlayers = getUint32(env, args[7]);
	// void glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers)
	glTextureView(texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers);
	return NULL;
}

napi_value QueryCounter(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint id = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	// void glQueryCounter(GLuint id, GLenum target)
	glQueryCounter(id, target);
	return NULL;
}

napi_value DrawTransformFeedback(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum mode = getUint32(env, args[0]);
	GLuint id = getUint32(env, args[1]);
	// void glDrawTransformFeedback(GLenum mode, GLuint id)
	glDrawTransformFeedback(mode, id);
	return NULL;
}

napi_value BeginQueryIndexed(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLuint id = getUint32(env, args[2]);
	// void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id)
	glBeginQueryIndexed(target, index, id);
	return NULL;
}

napi_value DrawTransformFeedbackStream(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum mode = getUint32(env, args[0]);
	GLuint id = getUint32(env, args[1]);
	GLuint stream = getUint32(env, args[2]);
	// void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream)
	glDrawTransformFeedbackStream(mode, id, stream);
	return NULL;
}

napi_value EndQueryIndexed(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	// void glEndQueryIndexed(GLenum target, GLuint index)
	glEndQueryIndexed(target, index);
	return NULL;
}

napi_value DrawTransformFeedbackInstanced(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum mode = getUint32(env, args[0]);
	GLuint id = getUint32(env, args[1]);
	GLsizei primcount = getInt32(env, args[2]);
	// void glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei primcount)
	glDrawTransformFeedbackInstanced(mode, id, primcount);
	return NULL;
}

napi_value DrawTransformFeedbackStreamInstanced(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum mode = getUint32(env, args[0]);
	GLuint id = getUint32(env, args[1]);
	GLuint stream = getUint32(env, args[2]);
	GLsizei primcount = getInt32(env, args[3]);
	// void glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei primcount)
	glDrawTransformFeedbackStreamInstanced(mode, id, stream, primcount);
	return NULL;
}

napi_value VertexAttribLPointer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint index = getUint32(env, args[0]);
	GLint size = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLsizei stride = getInt32(env, args[3]);
	void* pointer;
	// void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer)
	glVertexAttribLPointer(index, size, type, stride, pointer);
	return NULL;
}

napi_value BindVertexBuffer(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint bindingindex = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	GLintptr offset = getInt32(env, args[2]);
	GLsizei stride = getInt32(env, args[3]);
	// void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
	glBindVertexBuffer(bindingindex, buffer, offset, stride);
	return NULL;
}

napi_value VertexArrayBindVertexBufferEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint bindingindex = getUint32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	GLintptr offset = getInt32(env, args[3]);
	GLsizei stride = getInt32(env, args[4]);
	// void glVertexArrayBindVertexBufferEXT(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride)
	glVertexArrayBindVertexBufferEXT(vaobj, bindingindex, buffer, offset, stride);
	return NULL;
}

napi_value VertexArrayVertexAttribBindingEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint attribindex = getUint32(env, args[1]);
	GLuint bindingindex = getUint32(env, args[2]);
	// void glVertexArrayVertexAttribBindingEXT(GLuint vaobj, GLuint attribindex, GLuint bindingindex)
	glVertexArrayVertexAttribBindingEXT(vaobj, attribindex, bindingindex);
	return NULL;
}

napi_value VertexArrayVertexAttribFormatEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint attribindex = getUint32(env, args[1]);
	GLint size = getInt32(env, args[2]);
	GLenum type = getUint32(env, args[3]);
	GLboolean normalized = getBool(env, args[4]);
	GLuint relativeoffset = getUint32(env, args[5]);
	// void glVertexArrayVertexAttribFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
	glVertexArrayVertexAttribFormatEXT(vaobj, attribindex, size, type, normalized, relativeoffset);
	return NULL;
}

napi_value VertexArrayVertexAttribIFormatEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint attribindex = getUint32(env, args[1]);
	GLint size = getInt32(env, args[2]);
	GLenum type = getUint32(env, args[3]);
	GLuint relativeoffset = getUint32(env, args[4]);
	// void glVertexArrayVertexAttribIFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
	glVertexArrayVertexAttribIFormatEXT(vaobj, attribindex, size, type, relativeoffset);
	return NULL;
}

napi_value VertexArrayVertexAttribLFormatEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint attribindex = getUint32(env, args[1]);
	GLint size = getInt32(env, args[2]);
	GLenum type = getUint32(env, args[3]);
	GLuint relativeoffset = getUint32(env, args[4]);
	// void glVertexArrayVertexAttribLFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
	glVertexArrayVertexAttribLFormatEXT(vaobj, attribindex, size, type, relativeoffset);
	return NULL;
}

napi_value VertexArrayVertexBindingDivisorEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint bindingindex = getUint32(env, args[1]);
	GLuint divisor = getUint32(env, args[2]);
	// void glVertexArrayVertexBindingDivisorEXT(GLuint vaobj, GLuint bindingindex, GLuint divisor)
	glVertexArrayVertexBindingDivisorEXT(vaobj, bindingindex, divisor);
	return NULL;
}

napi_value VertexAttribBinding(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint attribindex = getUint32(env, args[0]);
	GLuint bindingindex = getUint32(env, args[1]);
	// void glVertexAttribBinding(GLuint attribindex, GLuint bindingindex)
	glVertexAttribBinding(attribindex, bindingindex);
	return NULL;
}

napi_value VertexAttribFormat(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint attribindex = getUint32(env, args[0]);
	GLint size = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLboolean normalized = getBool(env, args[3]);
	GLuint relativeoffset = getUint32(env, args[4]);
	// void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset)
	glVertexAttribFormat(attribindex, size, type, normalized, relativeoffset);
	return NULL;
}

napi_value VertexAttribIFormat(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint attribindex = getUint32(env, args[0]);
	GLint size = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLuint relativeoffset = getUint32(env, args[3]);
	// void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
	glVertexAttribIFormat(attribindex, size, type, relativeoffset);
	return NULL;
}

napi_value VertexAttribLFormat(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint attribindex = getUint32(env, args[0]);
	GLint size = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLuint relativeoffset = getUint32(env, args[3]);
	// void glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset)
	glVertexAttribLFormat(attribindex, size, type, relativeoffset);
	return NULL;
}

napi_value VertexBindingDivisor(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint bindingindex = getUint32(env, args[0]);
	GLuint divisor = getUint32(env, args[1]);
	// void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor)
	glVertexBindingDivisor(bindingindex, divisor);
	return NULL;
}

napi_value DepthRangeArrayv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint first = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLclampd * v;
	// void glDepthRangeArrayv(GLuint first, GLsizei count, const GLclampd * v)
	glDepthRangeArrayv(first, count, v);
	return NULL;
}

napi_value DepthRangeIndexed(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint index = getUint32(env, args[0]);
	GLclampd n;
	GLclampd f;
	// void glDepthRangeIndexed(GLuint index, GLclampd n, GLclampd f)
	glDepthRangeIndexed(index, n, f);
	return NULL;
}

napi_value ScissorArrayv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint first = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLint * v = nullptr;
	status = getTypedArray(env, args[2], v);
	// void glScissorArrayv(GLuint first, GLsizei count, const GLint * v)
	glScissorArrayv(first, count, v);
	return NULL;
}

napi_value ScissorIndexed(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint index = getUint32(env, args[0]);
	GLint left = getInt32(env, args[1]);
	GLint bottom = getInt32(env, args[2]);
	GLsizei width = getInt32(env, args[3]);
	GLsizei height = getInt32(env, args[4]);
	// void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height)
	glScissorIndexed(index, left, bottom, width, height);
	return NULL;
}

napi_value ScissorIndexedv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint index = getUint32(env, args[0]);
	GLint * v = nullptr;
	status = getTypedArray(env, args[1], v);
	// void glScissorIndexedv(GLuint index, const GLint * v)
	glScissorIndexedv(index, v);
	return NULL;
}

napi_value ViewportArrayv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint first = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLfloat * v = nullptr;
	status = getTypedArray(env, args[2], v);
	// void glViewportArrayv(GLuint first, GLsizei count, const GLfloat * v)
	glViewportArrayv(first, count, v);
	return NULL;
}

napi_value ViewportIndexedf(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint index = getUint32(env, args[0]);
	GLfloat x = getDouble(env, args[1]);
	GLfloat y = getDouble(env, args[2]);
	GLfloat w = getDouble(env, args[3]);
	GLfloat h = getDouble(env, args[4]);
	// void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h)
	glViewportIndexedf(index, x, y, w, h);
	return NULL;
}

napi_value ViewportIndexedfv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint index = getUint32(env, args[0]);
	GLfloat * v = nullptr;
	status = getTypedArray(env, args[1], v);
	// void glViewportIndexedfv(GLuint index, const GLfloat * v)
	glViewportIndexedfv(index, v);
	return NULL;
}

napi_value DrawBuffersATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLenum* bufs;
	// void glDrawBuffersATI(GLsizei n, const GLenum* bufs)
	glDrawBuffersATI(n, bufs);
	return NULL;
}

napi_value DrawElementArrayATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum mode = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	// void glDrawElementArrayATI(GLenum mode, GLsizei count)
	glDrawElementArrayATI(mode, count);
	return NULL;
}

napi_value DrawRangeElementArrayATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum mode = getUint32(env, args[0]);
	GLuint start = getUint32(env, args[1]);
	GLuint end = getUint32(env, args[2]);
	GLsizei count = getInt32(env, args[3]);
	// void glDrawRangeElementArrayATI(GLenum mode, GLuint start, GLuint end, GLsizei count)
	glDrawRangeElementArrayATI(mode, start, end, count);
	return NULL;
}

napi_value ElementPointerATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum type = getUint32(env, args[0]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[1], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glElementPointerATI(GLenum type, const void *pointer)
	glElementPointerATI(type, pointer);
	return NULL;
}

napi_value TexBumpParameterfvATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat * param = nullptr;
	status = getTypedArray(env, args[1], param);
	// void glTexBumpParameterfvATI(GLenum pname, GLfloat *param)
	glTexBumpParameterfvATI(pname, param);
	return NULL;
}

napi_value TexBumpParameterivATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint * param = nullptr;
	status = getTypedArray(env, args[1], param);
	// void glTexBumpParameterivATI(GLenum pname, GLint *param)
	glTexBumpParameterivATI(pname, param);
	return NULL;
}

napi_value BeginFragmentShaderATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glBeginFragmentShaderATI(void)
	glBeginFragmentShaderATI();
	return NULL;
}

napi_value BindFragmentShaderATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint id = getUint32(env, args[0]);
	// void glBindFragmentShaderATI(GLuint id)
	glBindFragmentShaderATI(id);
	return NULL;
}

napi_value DeleteFragmentShaderATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint id = getUint32(env, args[0]);
	// void glDeleteFragmentShaderATI(GLuint id)
	glDeleteFragmentShaderATI(id);
	return NULL;
}

napi_value EndFragmentShaderATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glEndFragmentShaderATI(void)
	glEndFragmentShaderATI();
	return NULL;
}

napi_value GenFragmentShadersATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint range = getUint32(env, args[0]);
	// GLuint glGenFragmentShadersATI(GLuint range)
	GLuint result = glGenFragmentShadersATI(range);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value PassTexCoordATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint dst = getUint32(env, args[0]);
	GLuint coord = getUint32(env, args[1]);
	GLenum swizzle = getUint32(env, args[2]);
	// void glPassTexCoordATI(GLuint dst, GLuint coord, GLenum swizzle)
	glPassTexCoordATI(dst, coord, swizzle);
	return NULL;
}

napi_value SampleMapATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint dst = getUint32(env, args[0]);
	GLuint interp = getUint32(env, args[1]);
	GLenum swizzle = getUint32(env, args[2]);
	// void glSampleMapATI(GLuint dst, GLuint interp, GLenum swizzle)
	glSampleMapATI(dst, interp, swizzle);
	return NULL;
}

napi_value SetFragmentShaderConstantATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint dst = getUint32(env, args[0]);
	GLfloat* value;
	// void glSetFragmentShaderConstantATI(GLuint dst, const GLfloat* value)
	glSetFragmentShaderConstantATI(dst, value);
	return NULL;
}

napi_value UnmapObjectBufferATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint buffer = getUint32(env, args[0]);
	// void glUnmapObjectBufferATI(GLuint buffer)
	glUnmapObjectBufferATI(buffer);
	return NULL;
}

napi_value PNTrianglesfATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat param = getDouble(env, args[1]);
	// void glPNTrianglesfATI(GLenum pname, GLfloat param)
	glPNTrianglesfATI(pname, param);
	return NULL;
}

napi_value PNTrianglesiATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint param = getInt32(env, args[1]);
	// void glPNTrianglesiATI(GLenum pname, GLint param)
	glPNTrianglesiATI(pname, param);
	return NULL;
}

napi_value StencilFuncSeparateATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum frontfunc = getUint32(env, args[0]);
	GLenum backfunc = getUint32(env, args[1]);
	GLint ref = getInt32(env, args[2]);
	GLuint mask = getUint32(env, args[3]);
	// void glStencilFuncSeparateATI(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask)
	glStencilFuncSeparateATI(frontfunc, backfunc, ref, mask);
	return NULL;
}

napi_value StencilOpSeparateATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum face = getUint32(env, args[0]);
	GLenum sfail = getUint32(env, args[1]);
	GLenum dpfail = getUint32(env, args[2]);
	GLenum dppass = getUint32(env, args[3]);
	// void glStencilOpSeparateATI(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
	glStencilOpSeparateATI(face, sfail, dpfail, dppass);
	return NULL;
}

napi_value ArrayObjectATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum array = getUint32(env, args[0]);
	GLint size = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLsizei stride = getInt32(env, args[3]);
	GLuint buffer = getUint32(env, args[4]);
	GLuint offset = getUint32(env, args[5]);
	// void glArrayObjectATI(GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset)
	glArrayObjectATI(array, size, type, stride, buffer, offset);
	return NULL;
}

napi_value FreeObjectBufferATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint buffer = getUint32(env, args[0]);
	// void glFreeObjectBufferATI(GLuint buffer)
	glFreeObjectBufferATI(buffer);
	return NULL;
}

napi_value IsObjectBufferATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint buffer = getUint32(env, args[0]);
	// GLboolean glIsObjectBufferATI(GLuint buffer)
	GLboolean result = glIsObjectBufferATI(buffer);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value NewObjectBufferATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLsizei size = getInt32(env, args[0]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[1], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	GLenum usage = getUint32(env, args[2]);
	// GLuint glNewObjectBufferATI(GLsizei size, const void *pointer, GLenum usage)
	GLuint result = glNewObjectBufferATI(size, pointer, usage);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value UpdateObjectBufferATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint buffer = getUint32(env, args[0]);
	GLuint offset = getUint32(env, args[1]);
	GLsizei size = getInt32(env, args[2]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[3], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	GLenum preserve = getUint32(env, args[4]);
	// void glUpdateObjectBufferATI(GLuint buffer, GLuint offset, GLsizei size, const void *pointer, GLenum preserve)
	glUpdateObjectBufferATI(buffer, offset, size, pointer, preserve);
	return NULL;
}

napi_value VariantArrayObjectATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint id = getUint32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	GLsizei stride = getInt32(env, args[2]);
	GLuint buffer = getUint32(env, args[3]);
	GLuint offset = getUint32(env, args[4]);
	// void glVariantArrayObjectATI(GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset)
	glVariantArrayObjectATI(id, type, stride, buffer, offset);
	return NULL;
}

napi_value VertexAttribArrayObjectATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLuint index = getUint32(env, args[0]);
	GLint size = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLboolean normalized = getBool(env, args[3]);
	GLsizei stride = getInt32(env, args[4]);
	GLuint buffer = getUint32(env, args[5]);
	GLuint offset = getUint32(env, args[6]);
	// void glVertexAttribArrayObjectATI(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset)
	glVertexAttribArrayObjectATI(index, size, type, normalized, stride, buffer, offset);
	return NULL;
}

napi_value ClientActiveVertexStreamATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum stream = getUint32(env, args[0]);
	// void glClientActiveVertexStreamATI(GLenum stream)
	glClientActiveVertexStreamATI(stream);
	return NULL;
}

napi_value VertexBlendEnvfATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat param = getDouble(env, args[1]);
	// void glVertexBlendEnvfATI(GLenum pname, GLfloat param)
	glVertexBlendEnvfATI(pname, param);
	return NULL;
}

napi_value VertexBlendEnviATI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint param = getInt32(env, args[1]);
	// void glVertexBlendEnviATI(GLenum pname, GLint param)
	glVertexBlendEnviATI(pname, param);
	return NULL;
}

napi_value UniformBufferEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint program = getUint32(env, args[0]);
	GLint location = getInt32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	// void glUniformBufferEXT(GLuint program, GLint location, GLuint buffer)
	glUniformBufferEXT(program, location, buffer);
	return NULL;
}

napi_value BlendColorEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLclampf red;
	GLclampf green;
	GLclampf blue;
	GLclampf alpha;
	// void glBlendColorEXT(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
	glBlendColorEXT(red, green, blue, alpha);
	return NULL;
}

napi_value BlendEquationSeparateEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum modeRGB = getUint32(env, args[0]);
	GLenum modeAlpha = getUint32(env, args[1]);
	// void glBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha)
	glBlendEquationSeparateEXT(modeRGB, modeAlpha);
	return NULL;
}

napi_value BlendFuncSeparateEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum sfactorRGB = getUint32(env, args[0]);
	GLenum dfactorRGB = getUint32(env, args[1]);
	GLenum sfactorAlpha = getUint32(env, args[2]);
	GLenum dfactorAlpha = getUint32(env, args[3]);
	// void glBlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
	glBlendFuncSeparateEXT(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
	return NULL;
}

napi_value BlendEquationEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum mode = getUint32(env, args[0]);
	// void glBlendEquationEXT(GLenum mode)
	glBlendEquationEXT(mode);
	return NULL;
}

napi_value ColorSubTableEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum target = getUint32(env, args[0]);
	GLsizei start = getInt32(env, args[1]);
	GLsizei count = getInt32(env, args[2]);
	GLenum format = getUint32(env, args[3]);
	GLenum type = getUint32(env, args[4]);
	void * data = nullptr;
	status = getTypedArray(env, args[5], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glColorSubTableEXT(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data)
	glColorSubTableEXT(target, start, count, format, type, data);
	return NULL;
}

napi_value CopyColorSubTableEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLsizei start = getInt32(env, args[1]);
	GLint x = getInt32(env, args[2]);
	GLint y = getInt32(env, args[3]);
	GLsizei width = getInt32(env, args[4]);
	// void glCopyColorSubTableEXT(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width)
	glCopyColorSubTableEXT(target, start, x, y, width);
	return NULL;
}

napi_value LockArraysEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLint first = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	// void glLockArraysEXT(GLint first, GLsizei count)
	glLockArraysEXT(first, count);
	return NULL;
}

napi_value UnlockArraysEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glUnlockArraysEXT(void)
	glUnlockArraysEXT();
	return NULL;
}

napi_value ConvolutionParameterfEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat param = getDouble(env, args[2]);
	// void glConvolutionParameterfEXT(GLenum target, GLenum pname, GLfloat param)
	glConvolutionParameterfEXT(target, pname, param);
	return NULL;
}

napi_value ConvolutionParameterfvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat* params;
	// void glConvolutionParameterfvEXT(GLenum target, GLenum pname, const GLfloat* params)
	glConvolutionParameterfvEXT(target, pname, params);
	return NULL;
}

napi_value ConvolutionParameteriEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint param = getInt32(env, args[2]);
	// void glConvolutionParameteriEXT(GLenum target, GLenum pname, GLint param)
	glConvolutionParameteriEXT(target, pname, param);
	return NULL;
}

napi_value ConvolutionParameterivEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint* params;
	// void glConvolutionParameterivEXT(GLenum target, GLenum pname, const GLint* params)
	glConvolutionParameterivEXT(target, pname, params);
	return NULL;
}

napi_value BinormalPointerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum type = getUint32(env, args[0]);
	GLsizei stride = getInt32(env, args[1]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[2], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glBinormalPointerEXT(GLenum type, GLsizei stride, void *pointer)
	glBinormalPointerEXT(type, stride, pointer);
	return NULL;
}

napi_value TangentPointerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum type = getUint32(env, args[0]);
	GLsizei stride = getInt32(env, args[1]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[2], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glTangentPointerEXT(GLenum type, GLsizei stride, void *pointer)
	glTangentPointerEXT(type, stride, pointer);
	return NULL;
}

napi_value CullParameterdvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLdouble* params;
	// void glCullParameterdvEXT(GLenum pname, GLdouble* params)
	glCullParameterdvEXT(pname, params);
	return NULL;
}

napi_value CullParameterfvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat* params;
	// void glCullParameterfvEXT(GLenum pname, GLfloat* params)
	glCullParameterfvEXT(pname, params);
	return NULL;
}

napi_value LabelObjectEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum type = getUint32(env, args[0]);
	GLuint object = getUint32(env, args[1]);
	GLsizei length = getInt32(env, args[2]);
	GLchar* label;
	// void glLabelObjectEXT(GLenum type, GLuint object, GLsizei length, const GLchar* label)
	glLabelObjectEXT(type, object, length, label);
	return NULL;
}

napi_value InsertEventMarkerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei length = getInt32(env, args[0]);
	GLchar* marker;
	// void glInsertEventMarkerEXT(GLsizei length, const GLchar* marker)
	glInsertEventMarkerEXT(length, marker);
	return NULL;
}

napi_value PopGroupMarkerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glPopGroupMarkerEXT(void)
	glPopGroupMarkerEXT();
	return NULL;
}

napi_value PushGroupMarkerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei length = getInt32(env, args[0]);
	GLchar* marker;
	// void glPushGroupMarkerEXT(GLsizei length, const GLchar* marker)
	glPushGroupMarkerEXT(length, marker);
	return NULL;
}

napi_value DepthBoundsEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLclampd zmin;
	GLclampd zmax;
	// void glDepthBoundsEXT(GLclampd zmin, GLclampd zmax)
	glDepthBoundsEXT(zmin, zmax);
	return NULL;
}

napi_value BindMultiTextureEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum texunit = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLuint texture = getUint32(env, args[2]);
	// void glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture)
	glBindMultiTextureEXT(texunit, target, texture);
	return NULL;
}

napi_value CheckNamedFramebufferStatusEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	// GLenum glCheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target)
	GLenum result = glCheckNamedFramebufferStatusEXT(framebuffer, target);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value ClientAttribDefaultEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLbitfield mask = getUint32(env, args[0]);
	// void glClientAttribDefaultEXT(GLbitfield mask)
	glClientAttribDefaultEXT(mask);
	return NULL;
}

napi_value DisableClientStateIndexedEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum array = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	// void glDisableClientStateIndexedEXT(GLenum array, GLuint index)
	glDisableClientStateIndexedEXT(array, index);
	return NULL;
}

napi_value DisableClientStateiEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum array = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	// void glDisableClientStateiEXT(GLenum array, GLuint index)
	glDisableClientStateiEXT(array, index);
	return NULL;
}

napi_value DisableVertexArrayAttribEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	// void glDisableVertexArrayAttribEXT(GLuint vaobj, GLuint index)
	glDisableVertexArrayAttribEXT(vaobj, index);
	return NULL;
}

napi_value DisableVertexArrayEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint vaobj = getUint32(env, args[0]);
	GLenum array = getUint32(env, args[1]);
	// void glDisableVertexArrayEXT(GLuint vaobj, GLenum array)
	glDisableVertexArrayEXT(vaobj, array);
	return NULL;
}

napi_value EnableClientStateIndexedEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum array = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	// void glEnableClientStateIndexedEXT(GLenum array, GLuint index)
	glEnableClientStateIndexedEXT(array, index);
	return NULL;
}

napi_value EnableClientStateiEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum array = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	// void glEnableClientStateiEXT(GLenum array, GLuint index)
	glEnableClientStateiEXT(array, index);
	return NULL;
}

napi_value EnableVertexArrayAttribEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	// void glEnableVertexArrayAttribEXT(GLuint vaobj, GLuint index)
	glEnableVertexArrayAttribEXT(vaobj, index);
	return NULL;
}

napi_value EnableVertexArrayEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint vaobj = getUint32(env, args[0]);
	GLenum array = getUint32(env, args[1]);
	// void glEnableVertexArrayEXT(GLuint vaobj, GLenum array)
	glEnableVertexArrayEXT(vaobj, array);
	return NULL;
}

napi_value FlushMappedNamedBufferRangeEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint buffer = getUint32(env, args[0]);
	GLintptr offset = getInt32(env, args[1]);
	GLsizeiptr length = getUint32(env, args[2]);
	// void glFlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length)
	glFlushMappedNamedBufferRangeEXT(buffer, offset, length);
	return NULL;
}

napi_value FramebufferDrawBufferEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum mode = getUint32(env, args[1]);
	// void glFramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode)
	glFramebufferDrawBufferEXT(framebuffer, mode);
	return NULL;
}

napi_value FramebufferDrawBuffersEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint framebuffer = getUint32(env, args[0]);
	GLsizei n = getInt32(env, args[1]);
	GLenum* bufs;
	// void glFramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, const GLenum* bufs)
	glFramebufferDrawBuffersEXT(framebuffer, n, bufs);
	return NULL;
}

napi_value FramebufferReadBufferEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum mode = getUint32(env, args[1]);
	// void glFramebufferReadBufferEXT(GLuint framebuffer, GLenum mode)
	glFramebufferReadBufferEXT(framebuffer, mode);
	return NULL;
}

napi_value GenerateMultiTexMipmapEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum texunit = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	// void glGenerateMultiTexMipmapEXT(GLenum texunit, GLenum target)
	glGenerateMultiTexMipmapEXT(texunit, target);
	return NULL;
}

napi_value GenerateTextureMipmapEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint texture = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	// void glGenerateTextureMipmapEXT(GLuint texture, GLenum target)
	glGenerateTextureMipmapEXT(texture, target);
	return NULL;
}

napi_value MatrixFrustumEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLenum matrixMode = getUint32(env, args[0]);
	GLdouble l;
	GLdouble r;
	GLdouble b;
	GLdouble t;
	GLdouble n;
	GLdouble f;
	// void glMatrixFrustumEXT(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f)
	glMatrixFrustumEXT(matrixMode, l, r, b, t, n, f);
	return NULL;
}

napi_value MatrixLoadIdentityEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum matrixMode = getUint32(env, args[0]);
	// void glMatrixLoadIdentityEXT(GLenum matrixMode)
	glMatrixLoadIdentityEXT(matrixMode);
	return NULL;
}

napi_value MatrixLoadTransposedEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum matrixMode = getUint32(env, args[0]);
	GLdouble* m;
	// void glMatrixLoadTransposedEXT(GLenum matrixMode, const GLdouble* m)
	glMatrixLoadTransposedEXT(matrixMode, m);
	return NULL;
}

napi_value MatrixLoadTransposefEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum matrixMode = getUint32(env, args[0]);
	GLfloat* m;
	// void glMatrixLoadTransposefEXT(GLenum matrixMode, const GLfloat* m)
	glMatrixLoadTransposefEXT(matrixMode, m);
	return NULL;
}

napi_value MatrixLoaddEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum matrixMode = getUint32(env, args[0]);
	GLdouble* m;
	// void glMatrixLoaddEXT(GLenum matrixMode, const GLdouble* m)
	glMatrixLoaddEXT(matrixMode, m);
	return NULL;
}

napi_value MatrixLoadfEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum matrixMode = getUint32(env, args[0]);
	GLfloat* m;
	// void glMatrixLoadfEXT(GLenum matrixMode, const GLfloat* m)
	glMatrixLoadfEXT(matrixMode, m);
	return NULL;
}

napi_value MatrixMultTransposedEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum matrixMode = getUint32(env, args[0]);
	GLdouble* m;
	// void glMatrixMultTransposedEXT(GLenum matrixMode, const GLdouble* m)
	glMatrixMultTransposedEXT(matrixMode, m);
	return NULL;
}

napi_value MatrixMultTransposefEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum matrixMode = getUint32(env, args[0]);
	GLfloat* m;
	// void glMatrixMultTransposefEXT(GLenum matrixMode, const GLfloat* m)
	glMatrixMultTransposefEXT(matrixMode, m);
	return NULL;
}

napi_value MatrixMultdEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum matrixMode = getUint32(env, args[0]);
	GLdouble* m;
	// void glMatrixMultdEXT(GLenum matrixMode, const GLdouble* m)
	glMatrixMultdEXT(matrixMode, m);
	return NULL;
}

napi_value MatrixMultfEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum matrixMode = getUint32(env, args[0]);
	GLfloat* m;
	// void glMatrixMultfEXT(GLenum matrixMode, const GLfloat* m)
	glMatrixMultfEXT(matrixMode, m);
	return NULL;
}

napi_value MatrixOrthoEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLenum matrixMode = getUint32(env, args[0]);
	GLdouble l;
	GLdouble r;
	GLdouble b;
	GLdouble t;
	GLdouble n;
	GLdouble f;
	// void glMatrixOrthoEXT(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f)
	glMatrixOrthoEXT(matrixMode, l, r, b, t, n, f);
	return NULL;
}

napi_value MatrixPopEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum matrixMode = getUint32(env, args[0]);
	// void glMatrixPopEXT(GLenum matrixMode)
	glMatrixPopEXT(matrixMode);
	return NULL;
}

napi_value MatrixPushEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum matrixMode = getUint32(env, args[0]);
	// void glMatrixPushEXT(GLenum matrixMode)
	glMatrixPushEXT(matrixMode);
	return NULL;
}

napi_value MatrixRotatedEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum matrixMode = getUint32(env, args[0]);
	GLdouble angle;
	GLdouble x;
	GLdouble y;
	GLdouble z;
	// void glMatrixRotatedEXT(GLenum matrixMode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z)
	glMatrixRotatedEXT(matrixMode, angle, x, y, z);
	return NULL;
}

napi_value MatrixRotatefEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum matrixMode = getUint32(env, args[0]);
	GLfloat angle = getDouble(env, args[1]);
	GLfloat x = getDouble(env, args[2]);
	GLfloat y = getDouble(env, args[3]);
	GLfloat z = getDouble(env, args[4]);
	// void glMatrixRotatefEXT(GLenum matrixMode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
	glMatrixRotatefEXT(matrixMode, angle, x, y, z);
	return NULL;
}

napi_value MatrixScaledEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum matrixMode = getUint32(env, args[0]);
	GLdouble x;
	GLdouble y;
	GLdouble z;
	// void glMatrixScaledEXT(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z)
	glMatrixScaledEXT(matrixMode, x, y, z);
	return NULL;
}

napi_value MatrixScalefEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum matrixMode = getUint32(env, args[0]);
	GLfloat x = getDouble(env, args[1]);
	GLfloat y = getDouble(env, args[2]);
	GLfloat z = getDouble(env, args[3]);
	// void glMatrixScalefEXT(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z)
	glMatrixScalefEXT(matrixMode, x, y, z);
	return NULL;
}

napi_value MatrixTranslatedEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum matrixMode = getUint32(env, args[0]);
	GLdouble x;
	GLdouble y;
	GLdouble z;
	// void glMatrixTranslatedEXT(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z)
	glMatrixTranslatedEXT(matrixMode, x, y, z);
	return NULL;
}

napi_value MatrixTranslatefEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum matrixMode = getUint32(env, args[0]);
	GLfloat x = getDouble(env, args[1]);
	GLfloat y = getDouble(env, args[2]);
	GLfloat z = getDouble(env, args[3]);
	// void glMatrixTranslatefEXT(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z)
	glMatrixTranslatefEXT(matrixMode, x, y, z);
	return NULL;
}

napi_value MultiTexBufferEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texunit = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum internalformat = getUint32(env, args[2]);
	GLuint buffer = getUint32(env, args[3]);
	// void glMultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer)
	glMultiTexBufferEXT(texunit, target, internalformat, buffer);
	return NULL;
}

napi_value MultiTexCoordPointerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum texunit = getUint32(env, args[0]);
	GLint size = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLsizei stride = getInt32(env, args[3]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[4], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const void *pointer)
	glMultiTexCoordPointerEXT(texunit, size, type, stride, pointer);
	return NULL;
}

napi_value MultiTexEnvfEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texunit = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLfloat param = getDouble(env, args[3]);
	// void glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param)
	glMultiTexEnvfEXT(texunit, target, pname, param);
	return NULL;
}

napi_value MultiTexEnvfvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texunit = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLfloat* params;
	// void glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat* params)
	glMultiTexEnvfvEXT(texunit, target, pname, params);
	return NULL;
}

napi_value MultiTexEnviEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texunit = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLint param = getInt32(env, args[3]);
	// void glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param)
	glMultiTexEnviEXT(texunit, target, pname, param);
	return NULL;
}

napi_value MultiTexEnvivEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texunit = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLint* params;
	// void glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params)
	glMultiTexEnvivEXT(texunit, target, pname, params);
	return NULL;
}

napi_value MultiTexGendEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texunit = getUint32(env, args[0]);
	GLenum coord = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLdouble param;
	// void glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param)
	glMultiTexGendEXT(texunit, coord, pname, param);
	return NULL;
}

napi_value MultiTexGendvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texunit = getUint32(env, args[0]);
	GLenum coord = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLdouble* params;
	// void glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLdouble* params)
	glMultiTexGendvEXT(texunit, coord, pname, params);
	return NULL;
}

napi_value MultiTexGenfEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texunit = getUint32(env, args[0]);
	GLenum coord = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLfloat param = getDouble(env, args[3]);
	// void glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param)
	glMultiTexGenfEXT(texunit, coord, pname, param);
	return NULL;
}

napi_value MultiTexGenfvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texunit = getUint32(env, args[0]);
	GLenum coord = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLfloat* params;
	// void glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLfloat* params)
	glMultiTexGenfvEXT(texunit, coord, pname, params);
	return NULL;
}

napi_value MultiTexGeniEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texunit = getUint32(env, args[0]);
	GLenum coord = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLint param = getInt32(env, args[3]);
	// void glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param)
	glMultiTexGeniEXT(texunit, coord, pname, param);
	return NULL;
}

napi_value MultiTexGenivEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texunit = getUint32(env, args[0]);
	GLenum coord = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLint* params;
	// void glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, const GLint* params)
	glMultiTexGenivEXT(texunit, coord, pname, params);
	return NULL;
}

napi_value MultiTexParameterIivEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texunit = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLint* params;
	// void glMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* params)
	glMultiTexParameterIivEXT(texunit, target, pname, params);
	return NULL;
}

napi_value MultiTexParameterIuivEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texunit = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLuint* params;
	// void glMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, const GLuint* params)
	glMultiTexParameterIuivEXT(texunit, target, pname, params);
	return NULL;
}

napi_value MultiTexParameterfEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texunit = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLfloat param = getDouble(env, args[3]);
	// void glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param)
	glMultiTexParameterfEXT(texunit, target, pname, param);
	return NULL;
}

napi_value MultiTexParameterfvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texunit = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLfloat* param;
	// void glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat* param)
	glMultiTexParameterfvEXT(texunit, target, pname, param);
	return NULL;
}

napi_value MultiTexParameteriEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texunit = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLint param = getInt32(env, args[3]);
	// void glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param)
	glMultiTexParameteriEXT(texunit, target, pname, param);
	return NULL;
}

napi_value MultiTexParameterivEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texunit = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLint* param;
	// void glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint* param)
	glMultiTexParameterivEXT(texunit, target, pname, param);
	return NULL;
}

napi_value MultiTexRenderbufferEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum texunit = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLuint renderbuffer = getUint32(env, args[2]);
	// void glMultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer)
	glMultiTexRenderbufferEXT(texunit, target, renderbuffer);
	return NULL;
}

napi_value NamedBufferDataEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint buffer = getUint32(env, args[0]);
	GLsizeiptr size = getUint32(env, args[1]);
	void * data = nullptr;
	status = getTypedArray(env, args[2], *(void **)&data);
	if (status != napi_ok) return nullptr;
	GLenum usage = getUint32(env, args[3]);
	// void glNamedBufferDataEXT(GLuint buffer, GLsizeiptr size, const void *data, GLenum usage)
	glNamedBufferDataEXT(buffer, size, data, usage);
	return NULL;
}

napi_value NamedBufferSubDataEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint buffer = getUint32(env, args[0]);
	GLintptr offset = getInt32(env, args[1]);
	GLsizeiptr size = getUint32(env, args[2]);
	void * data = nullptr;
	status = getTypedArray(env, args[3], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data)
	glNamedBufferSubDataEXT(buffer, offset, size, data);
	return NULL;
}

napi_value NamedCopyBufferSubDataEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint readBuffer = getUint32(env, args[0]);
	GLuint writeBuffer = getUint32(env, args[1]);
	GLintptr readOffset = getInt32(env, args[2]);
	GLintptr writeOffset = getInt32(env, args[3]);
	GLsizeiptr size = getUint32(env, args[4]);
	// void glNamedCopyBufferSubDataEXT(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
	glNamedCopyBufferSubDataEXT(readBuffer, writeBuffer, readOffset, writeOffset, size);
	return NULL;
}

napi_value NamedFramebufferRenderbufferEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum attachment = getUint32(env, args[1]);
	GLenum renderbuffertarget = getUint32(env, args[2]);
	GLuint renderbuffer = getUint32(env, args[3]);
	// void glNamedFramebufferRenderbufferEXT(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
	glNamedFramebufferRenderbufferEXT(framebuffer, attachment, renderbuffertarget, renderbuffer);
	return NULL;
}

napi_value NamedFramebufferTextureEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum attachment = getUint32(env, args[1]);
	GLuint texture = getUint32(env, args[2]);
	GLint level = getInt32(env, args[3]);
	// void glNamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level)
	glNamedFramebufferTextureEXT(framebuffer, attachment, texture, level);
	return NULL;
}

napi_value NamedFramebufferTextureFaceEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum attachment = getUint32(env, args[1]);
	GLuint texture = getUint32(env, args[2]);
	GLint level = getInt32(env, args[3]);
	GLenum face = getUint32(env, args[4]);
	// void glNamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face)
	glNamedFramebufferTextureFaceEXT(framebuffer, attachment, texture, level, face);
	return NULL;
}

napi_value NamedFramebufferTextureLayerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint framebuffer = getUint32(env, args[0]);
	GLenum attachment = getUint32(env, args[1]);
	GLuint texture = getUint32(env, args[2]);
	GLint level = getInt32(env, args[3]);
	GLint layer = getInt32(env, args[4]);
	// void glNamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer)
	glNamedFramebufferTextureLayerEXT(framebuffer, attachment, texture, level, layer);
	return NULL;
}

napi_value NamedProgramStringEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint program = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum format = getUint32(env, args[2]);
	GLsizei len = getInt32(env, args[3]);
	void * string = nullptr;
	status = getTypedArray(env, args[4], *(void **)&string);
	if (status != napi_ok) return nullptr;
	// void glNamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, const void *string)
	glNamedProgramStringEXT(program, target, format, len, string);
	return NULL;
}

napi_value NamedRenderbufferStorageEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint renderbuffer = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLsizei width = getInt32(env, args[2]);
	GLsizei height = getInt32(env, args[3]);
	// void glNamedRenderbufferStorageEXT(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height)
	glNamedRenderbufferStorageEXT(renderbuffer, internalformat, width, height);
	return NULL;
}

napi_value NamedRenderbufferStorageMultisampleCoverageEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLuint renderbuffer = getUint32(env, args[0]);
	GLsizei coverageSamples = getInt32(env, args[1]);
	GLsizei colorSamples = getInt32(env, args[2]);
	GLenum internalformat = getUint32(env, args[3]);
	GLsizei width = getInt32(env, args[4]);
	GLsizei height = getInt32(env, args[5]);
	// void glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height)
	glNamedRenderbufferStorageMultisampleCoverageEXT(renderbuffer, coverageSamples, colorSamples, internalformat, width, height);
	return NULL;
}

napi_value NamedRenderbufferStorageMultisampleEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint renderbuffer = getUint32(env, args[0]);
	GLsizei samples = getInt32(env, args[1]);
	GLenum internalformat = getUint32(env, args[2]);
	GLsizei width = getInt32(env, args[3]);
	GLsizei height = getInt32(env, args[4]);
	// void glNamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
	glNamedRenderbufferStorageMultisampleEXT(renderbuffer, samples, internalformat, width, height);
	return NULL;
}

napi_value PushClientAttribDefaultEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLbitfield mask = getUint32(env, args[0]);
	// void glPushClientAttribDefaultEXT(GLbitfield mask)
	glPushClientAttribDefaultEXT(mask);
	return NULL;
}

napi_value TextureBufferEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint texture = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum internalformat = getUint32(env, args[2]);
	GLuint buffer = getUint32(env, args[3]);
	// void glTextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer)
	glTextureBufferEXT(texture, target, internalformat, buffer);
	return NULL;
}

napi_value TextureParameterIivEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint texture = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLint* params;
	// void glTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, const GLint* params)
	glTextureParameterIivEXT(texture, target, pname, params);
	return NULL;
}

napi_value TextureParameterIuivEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint texture = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLuint* params;
	// void glTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, const GLuint* params)
	glTextureParameterIuivEXT(texture, target, pname, params);
	return NULL;
}

napi_value TextureParameterfEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint texture = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLfloat param = getDouble(env, args[3]);
	// void glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param)
	glTextureParameterfEXT(texture, target, pname, param);
	return NULL;
}

napi_value TextureParameterfvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint texture = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLfloat* param;
	// void glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, const GLfloat* param)
	glTextureParameterfvEXT(texture, target, pname, param);
	return NULL;
}

napi_value TextureParameteriEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint texture = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLint param = getInt32(env, args[3]);
	// void glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param)
	glTextureParameteriEXT(texture, target, pname, param);
	return NULL;
}

napi_value TextureParameterivEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint texture = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLint* param;
	// void glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, const GLint* param)
	glTextureParameterivEXT(texture, target, pname, param);
	return NULL;
}

napi_value TextureRenderbufferEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint texture = getUint32(env, args[0]);
	GLenum target = getUint32(env, args[1]);
	GLuint renderbuffer = getUint32(env, args[2]);
	// void glTextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer)
	glTextureRenderbufferEXT(texture, target, renderbuffer);
	return NULL;
}

napi_value UnmapNamedBufferEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint buffer = getUint32(env, args[0]);
	// GLboolean glUnmapNamedBufferEXT(GLuint buffer)
	GLboolean result = glUnmapNamedBufferEXT(buffer);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value VertexArrayColorOffsetEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	GLint size = getInt32(env, args[2]);
	GLenum type = getUint32(env, args[3]);
	GLsizei stride = getInt32(env, args[4]);
	GLintptr offset = getInt32(env, args[5]);
	// void glVertexArrayColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset)
	glVertexArrayColorOffsetEXT(vaobj, buffer, size, type, stride, offset);
	return NULL;
}

napi_value VertexArrayEdgeFlagOffsetEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	GLsizei stride = getInt32(env, args[2]);
	GLintptr offset = getInt32(env, args[3]);
	// void glVertexArrayEdgeFlagOffsetEXT(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset)
	glVertexArrayEdgeFlagOffsetEXT(vaobj, buffer, stride, offset);
	return NULL;
}

napi_value VertexArrayFogCoordOffsetEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLsizei stride = getInt32(env, args[3]);
	GLintptr offset = getInt32(env, args[4]);
	// void glVertexArrayFogCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset)
	glVertexArrayFogCoordOffsetEXT(vaobj, buffer, type, stride, offset);
	return NULL;
}

napi_value VertexArrayIndexOffsetEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLsizei stride = getInt32(env, args[3]);
	GLintptr offset = getInt32(env, args[4]);
	// void glVertexArrayIndexOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset)
	glVertexArrayIndexOffsetEXT(vaobj, buffer, type, stride, offset);
	return NULL;
}

napi_value VertexArrayMultiTexCoordOffsetEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	GLenum texunit = getUint32(env, args[2]);
	GLint size = getInt32(env, args[3]);
	GLenum type = getUint32(env, args[4]);
	GLsizei stride = getInt32(env, args[5]);
	GLintptr offset = getInt32(env, args[6]);
	// void glVertexArrayMultiTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset)
	glVertexArrayMultiTexCoordOffsetEXT(vaobj, buffer, texunit, size, type, stride, offset);
	return NULL;
}

napi_value VertexArrayNormalOffsetEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLsizei stride = getInt32(env, args[3]);
	GLintptr offset = getInt32(env, args[4]);
	// void glVertexArrayNormalOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset)
	glVertexArrayNormalOffsetEXT(vaobj, buffer, type, stride, offset);
	return NULL;
}

napi_value VertexArraySecondaryColorOffsetEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	GLint size = getInt32(env, args[2]);
	GLenum type = getUint32(env, args[3]);
	GLsizei stride = getInt32(env, args[4]);
	GLintptr offset = getInt32(env, args[5]);
	// void glVertexArraySecondaryColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset)
	glVertexArraySecondaryColorOffsetEXT(vaobj, buffer, size, type, stride, offset);
	return NULL;
}

napi_value VertexArrayTexCoordOffsetEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	GLint size = getInt32(env, args[2]);
	GLenum type = getUint32(env, args[3]);
	GLsizei stride = getInt32(env, args[4]);
	GLintptr offset = getInt32(env, args[5]);
	// void glVertexArrayTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset)
	glVertexArrayTexCoordOffsetEXT(vaobj, buffer, size, type, stride, offset);
	return NULL;
}

napi_value VertexArrayVertexAttribDivisorEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLuint divisor = getUint32(env, args[2]);
	// void glVertexArrayVertexAttribDivisorEXT(GLuint vaobj, GLuint index, GLuint divisor)
	glVertexArrayVertexAttribDivisorEXT(vaobj, index, divisor);
	return NULL;
}

napi_value VertexArrayVertexAttribIOffsetEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	GLuint index = getUint32(env, args[2]);
	GLint size = getInt32(env, args[3]);
	GLenum type = getUint32(env, args[4]);
	GLsizei stride = getInt32(env, args[5]);
	GLintptr offset = getInt32(env, args[6]);
	// void glVertexArrayVertexAttribIOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset)
	glVertexArrayVertexAttribIOffsetEXT(vaobj, buffer, index, size, type, stride, offset);
	return NULL;
}

napi_value VertexArrayVertexAttribOffsetEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[8];
	size_t argc = checkArgCount(env, info, args, 8, 8);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	GLuint index = getUint32(env, args[2]);
	GLint size = getInt32(env, args[3]);
	GLenum type = getUint32(env, args[4]);
	GLboolean normalized = getBool(env, args[5]);
	GLsizei stride = getInt32(env, args[6]);
	GLintptr offset = getInt32(env, args[7]);
	// void glVertexArrayVertexAttribOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset)
	glVertexArrayVertexAttribOffsetEXT(vaobj, buffer, index, size, type, normalized, stride, offset);
	return NULL;
}

napi_value VertexArrayVertexOffsetEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	GLint size = getInt32(env, args[2]);
	GLenum type = getUint32(env, args[3]);
	GLsizei stride = getInt32(env, args[4]);
	GLintptr offset = getInt32(env, args[5]);
	// void glVertexArrayVertexOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset)
	glVertexArrayVertexOffsetEXT(vaobj, buffer, size, type, stride, offset);
	return NULL;
}

napi_value ColorMaskIndexedEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint buf = getUint32(env, args[0]);
	GLboolean r = getBool(env, args[1]);
	GLboolean g = getBool(env, args[2]);
	GLboolean b = getBool(env, args[3]);
	GLboolean a = getBool(env, args[4]);
	// void glColorMaskIndexedEXT(GLuint buf, GLboolean r, GLboolean g, GLboolean b, GLboolean a)
	glColorMaskIndexedEXT(buf, r, g, b, a);
	return NULL;
}

napi_value DisableIndexedEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	// void glDisableIndexedEXT(GLenum target, GLuint index)
	glDisableIndexedEXT(target, index);
	return NULL;
}

napi_value EnableIndexedEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	// void glEnableIndexedEXT(GLenum target, GLuint index)
	glEnableIndexedEXT(target, index);
	return NULL;
}

napi_value IsEnabledIndexedEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	// GLboolean glIsEnabledIndexedEXT(GLenum target, GLuint index)
	GLboolean result = glIsEnabledIndexedEXT(target, index);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value DrawArraysInstancedEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum mode = getUint32(env, args[0]);
	GLint start = getInt32(env, args[1]);
	GLsizei count = getInt32(env, args[2]);
	GLsizei primcount = getInt32(env, args[3]);
	// void glDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount)
	glDrawArraysInstancedEXT(mode, start, count, primcount);
	return NULL;
}

napi_value DrawElementsInstancedEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum mode = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	void * indices = nullptr;
	status = getTypedArray(env, args[3], *(void **)&indices);
	if (status != napi_ok) return nullptr;
	GLsizei primcount = getInt32(env, args[4]);
	// void glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount)
	glDrawElementsInstancedEXT(mode, count, type, indices, primcount);
	return NULL;
}

napi_value DrawRangeElementsEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum mode = getUint32(env, args[0]);
	GLuint start = getUint32(env, args[1]);
	GLuint end = getUint32(env, args[2]);
	GLsizei count = getInt32(env, args[3]);
	GLenum type = getUint32(env, args[4]);
	void * indices = nullptr;
	status = getTypedArray(env, args[5], *(void **)&indices);
	if (status != napi_ok) return nullptr;
	// void glDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices)
	glDrawRangeElementsEXT(mode, start, end, count, type, indices);
	return NULL;
}

napi_value FogCoordPointerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum type = getUint32(env, args[0]);
	GLsizei stride = getInt32(env, args[1]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[2], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glFogCoordPointerEXT(GLenum type, GLsizei stride, const void *pointer)
	glFogCoordPointerEXT(type, stride, pointer);
	return NULL;
}

napi_value FogCoorddEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLdouble coord;
	// void glFogCoorddEXT(GLdouble coord)
	glFogCoorddEXT(coord);
	return NULL;
}

napi_value FogCoorddvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLdouble * coord;
	// void glFogCoorddvEXT(const GLdouble *coord)
	glFogCoorddvEXT(coord);
	return NULL;
}

napi_value FogCoordfEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLfloat coord = getDouble(env, args[0]);
	// void glFogCoordfEXT(GLfloat coord)
	glFogCoordfEXT(coord);
	return NULL;
}

napi_value FogCoordfvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLfloat * coord = nullptr;
	status = getTypedArray(env, args[0], coord);
	// void glFogCoordfvEXT(const GLfloat *coord)
	glFogCoordfvEXT(coord);
	return NULL;
}

napi_value FragmentColorMaterialEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum face = getUint32(env, args[0]);
	GLenum mode = getUint32(env, args[1]);
	// void glFragmentColorMaterialEXT(GLenum face, GLenum mode)
	glFragmentColorMaterialEXT(face, mode);
	return NULL;
}

napi_value FragmentLightModelfEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat param = getDouble(env, args[1]);
	// void glFragmentLightModelfEXT(GLenum pname, GLfloat param)
	glFragmentLightModelfEXT(pname, param);
	return NULL;
}

napi_value FragmentLightModelfvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat* params;
	// void glFragmentLightModelfvEXT(GLenum pname, GLfloat* params)
	glFragmentLightModelfvEXT(pname, params);
	return NULL;
}

napi_value FragmentLightModeliEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint param = getInt32(env, args[1]);
	// void glFragmentLightModeliEXT(GLenum pname, GLint param)
	glFragmentLightModeliEXT(pname, param);
	return NULL;
}

napi_value FragmentLightModelivEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint* params;
	// void glFragmentLightModelivEXT(GLenum pname, GLint* params)
	glFragmentLightModelivEXT(pname, params);
	return NULL;
}

napi_value FragmentLightfEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum light = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat param = getDouble(env, args[2]);
	// void glFragmentLightfEXT(GLenum light, GLenum pname, GLfloat param)
	glFragmentLightfEXT(light, pname, param);
	return NULL;
}

napi_value FragmentLightfvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum light = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat* params;
	// void glFragmentLightfvEXT(GLenum light, GLenum pname, GLfloat* params)
	glFragmentLightfvEXT(light, pname, params);
	return NULL;
}

napi_value FragmentLightiEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum light = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint param = getInt32(env, args[2]);
	// void glFragmentLightiEXT(GLenum light, GLenum pname, GLint param)
	glFragmentLightiEXT(light, pname, param);
	return NULL;
}

napi_value FragmentLightivEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum light = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint* params;
	// void glFragmentLightivEXT(GLenum light, GLenum pname, GLint* params)
	glFragmentLightivEXT(light, pname, params);
	return NULL;
}

napi_value FragmentMaterialfEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum face = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat param = getDouble(env, args[2]);
	// void glFragmentMaterialfEXT(GLenum face, GLenum pname, const GLfloat param)
	glFragmentMaterialfEXT(face, pname, param);
	return NULL;
}

napi_value FragmentMaterialfvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum face = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat* params;
	// void glFragmentMaterialfvEXT(GLenum face, GLenum pname, const GLfloat* params)
	glFragmentMaterialfvEXT(face, pname, params);
	return NULL;
}

napi_value FragmentMaterialiEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum face = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint param = getInt32(env, args[2]);
	// void glFragmentMaterialiEXT(GLenum face, GLenum pname, const GLint param)
	glFragmentMaterialiEXT(face, pname, param);
	return NULL;
}

napi_value FragmentMaterialivEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum face = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint* params;
	// void glFragmentMaterialivEXT(GLenum face, GLenum pname, const GLint* params)
	glFragmentMaterialivEXT(face, pname, params);
	return NULL;
}

napi_value LightEnviEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint param = getInt32(env, args[1]);
	// void glLightEnviEXT(GLenum pname, GLint param)
	glLightEnviEXT(pname, param);
	return NULL;
}

napi_value BlitFramebufferEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[10];
	size_t argc = checkArgCount(env, info, args, 10, 10);
	GLint srcX0 = getInt32(env, args[0]);
	GLint srcY0 = getInt32(env, args[1]);
	GLint srcX1 = getInt32(env, args[2]);
	GLint srcY1 = getInt32(env, args[3]);
	GLint dstX0 = getInt32(env, args[4]);
	GLint dstY0 = getInt32(env, args[5]);
	GLint dstX1 = getInt32(env, args[6]);
	GLint dstY1 = getInt32(env, args[7]);
	GLbitfield mask = getUint32(env, args[8]);
	GLenum filter = getUint32(env, args[9]);
	// void glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
	glBlitFramebufferEXT(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
	return NULL;
}

napi_value RenderbufferStorageMultisampleEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLsizei samples = getInt32(env, args[1]);
	GLenum internalformat = getUint32(env, args[2]);
	GLsizei width = getInt32(env, args[3]);
	GLsizei height = getInt32(env, args[4]);
	// void glRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
	glRenderbufferStorageMultisampleEXT(target, samples, internalformat, width, height);
	return NULL;
}

napi_value BindFramebufferEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLuint framebuffer = getUint32(env, args[1]);
	// void glBindFramebufferEXT(GLenum target, GLuint framebuffer)
	glBindFramebufferEXT(target, framebuffer);
	return NULL;
}

napi_value BindRenderbufferEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLuint renderbuffer = getUint32(env, args[1]);
	// void glBindRenderbufferEXT(GLenum target, GLuint renderbuffer)
	glBindRenderbufferEXT(target, renderbuffer);
	return NULL;
}

napi_value CheckFramebufferStatusEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum target = getUint32(env, args[0]);
	// GLenum glCheckFramebufferStatusEXT(GLenum target)
	GLenum result = glCheckFramebufferStatusEXT(target);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value DeleteFramebuffersEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* framebuffers;
	// void glDeleteFramebuffersEXT(GLsizei n, const GLuint* framebuffers)
	glDeleteFramebuffersEXT(n, framebuffers);
	return NULL;
}

napi_value DeleteRenderbuffersEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* renderbuffers;
	// void glDeleteRenderbuffersEXT(GLsizei n, const GLuint* renderbuffers)
	glDeleteRenderbuffersEXT(n, renderbuffers);
	return NULL;
}

napi_value FramebufferRenderbufferEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLenum attachment = getUint32(env, args[1]);
	GLenum renderbuffertarget = getUint32(env, args[2]);
	GLuint renderbuffer = getUint32(env, args[3]);
	// void glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
	glFramebufferRenderbufferEXT(target, attachment, renderbuffertarget, renderbuffer);
	return NULL;
}

napi_value GenFramebuffersEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* framebuffers;
	// void glGenFramebuffersEXT(GLsizei n, GLuint* framebuffers)
	glGenFramebuffersEXT(n, framebuffers);
	return NULL;
}

napi_value GenRenderbuffersEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* renderbuffers;
	// void glGenRenderbuffersEXT(GLsizei n, GLuint* renderbuffers)
	glGenRenderbuffersEXT(n, renderbuffers);
	return NULL;
}

napi_value GenerateMipmapEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum target = getUint32(env, args[0]);
	// void glGenerateMipmapEXT(GLenum target)
	glGenerateMipmapEXT(target);
	return NULL;
}

napi_value IsFramebufferEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint framebuffer = getUint32(env, args[0]);
	// GLboolean glIsFramebufferEXT(GLuint framebuffer)
	GLboolean result = glIsFramebufferEXT(framebuffer);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value IsRenderbufferEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint renderbuffer = getUint32(env, args[0]);
	// GLboolean glIsRenderbufferEXT(GLuint renderbuffer)
	GLboolean result = glIsRenderbufferEXT(renderbuffer);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value RenderbufferStorageEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLsizei width = getInt32(env, args[2]);
	GLsizei height = getInt32(env, args[3]);
	// void glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
	glRenderbufferStorageEXT(target, internalformat, width, height);
	return NULL;
}

napi_value FramebufferTextureEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLenum attachment = getUint32(env, args[1]);
	GLuint texture = getUint32(env, args[2]);
	GLint level = getInt32(env, args[3]);
	// void glFramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level)
	glFramebufferTextureEXT(target, attachment, texture, level);
	return NULL;
}

napi_value FramebufferTextureFaceEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLenum attachment = getUint32(env, args[1]);
	GLuint texture = getUint32(env, args[2]);
	GLint level = getInt32(env, args[3]);
	GLenum face = getUint32(env, args[4]);
	// void glFramebufferTextureFaceEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face)
	glFramebufferTextureFaceEXT(target, attachment, texture, level, face);
	return NULL;
}

napi_value ProgramParameteriEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint program = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint value = getInt32(env, args[2]);
	// void glProgramParameteriEXT(GLuint program, GLenum pname, GLint value)
	glProgramParameteriEXT(program, pname, value);
	return NULL;
}

napi_value BindFragDataLocationEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint program = getUint32(env, args[0]);
	GLuint color = getUint32(env, args[1]);
	GLchar * name = nullptr;
	status = getCharacterArray(env, args[2], name);
	// void glBindFragDataLocationEXT(GLuint program, GLuint color, const GLchar *name)
	glBindFragDataLocationEXT(program, color, name);
	return NULL;
}

napi_value VertexAttribIPointerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint index = getUint32(env, args[0]);
	GLint size = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLsizei stride = getInt32(env, args[3]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[4], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glVertexAttribIPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer)
	glVertexAttribIPointerEXT(index, size, type, stride, pointer);
	return NULL;
}

napi_value HistogramEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLsizei width = getInt32(env, args[1]);
	GLenum internalformat = getUint32(env, args[2]);
	GLboolean sink = getBool(env, args[3]);
	// void glHistogramEXT(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink)
	glHistogramEXT(target, width, internalformat, sink);
	return NULL;
}

napi_value MinmaxEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLboolean sink = getBool(env, args[2]);
	// void glMinmaxEXT(GLenum target, GLenum internalformat, GLboolean sink)
	glMinmaxEXT(target, internalformat, sink);
	return NULL;
}

napi_value ResetHistogramEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum target = getUint32(env, args[0]);
	// void glResetHistogramEXT(GLenum target)
	glResetHistogramEXT(target);
	return NULL;
}

napi_value ResetMinmaxEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum target = getUint32(env, args[0]);
	// void glResetMinmaxEXT(GLenum target)
	glResetMinmaxEXT(target);
	return NULL;
}

napi_value IndexFuncEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum func = getUint32(env, args[0]);
	GLfloat ref = getDouble(env, args[1]);
	// void glIndexFuncEXT(GLenum func, GLfloat ref)
	glIndexFuncEXT(func, ref);
	return NULL;
}

napi_value IndexMaterialEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum face = getUint32(env, args[0]);
	GLenum mode = getUint32(env, args[1]);
	// void glIndexMaterialEXT(GLenum face, GLenum mode)
	glIndexMaterialEXT(face, mode);
	return NULL;
}

napi_value ApplyTextureEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum mode = getUint32(env, args[0]);
	// void glApplyTextureEXT(GLenum mode)
	glApplyTextureEXT(mode);
	return NULL;
}

napi_value TextureLightEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum pname = getUint32(env, args[0]);
	// void glTextureLightEXT(GLenum pname)
	glTextureLightEXT(pname);
	return NULL;
}

napi_value TextureMaterialEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum face = getUint32(env, args[0]);
	GLenum mode = getUint32(env, args[1]);
	// void glTextureMaterialEXT(GLenum face, GLenum mode)
	glTextureMaterialEXT(face, mode);
	return NULL;
}

napi_value MultiDrawArraysEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum mode = getUint32(env, args[0]);
	GLint* first;
	GLsizei * count = nullptr;
	status = getTypedArray(env, args[2], count);
	GLsizei primcount = getInt32(env, args[3]);
	// void glMultiDrawArraysEXT(GLenum mode, const GLint* first, const GLsizei *count, GLsizei primcount)
	glMultiDrawArraysEXT(mode, first, count, primcount);
	return NULL;
}

napi_value MultiDrawElementsEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum mode = getUint32(env, args[0]);
	GLsizei* count;
	GLenum type = getUint32(env, args[2]);
	void * * indices;
	GLsizei primcount = getInt32(env, args[4]);
	// void glMultiDrawElementsEXT(GLenum mode, GLsizei* count, GLenum type, const void *const *indices, GLsizei primcount)
	glMultiDrawElementsEXT(mode, count, type, indices, primcount);
	return NULL;
}

napi_value SampleMaskEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLclampf value;
	GLboolean invert = getBool(env, args[1]);
	// void glSampleMaskEXT(GLclampf value, GLboolean invert)
	glSampleMaskEXT(value, invert);
	return NULL;
}

napi_value SamplePatternEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum pattern = getUint32(env, args[0]);
	// void glSamplePatternEXT(GLenum pattern)
	glSamplePatternEXT(pattern);
	return NULL;
}

napi_value ColorTableEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum target = getUint32(env, args[0]);
	GLenum internalFormat = getUint32(env, args[1]);
	GLsizei width = getInt32(env, args[2]);
	GLenum format = getUint32(env, args[3]);
	GLenum type = getUint32(env, args[4]);
	void * data = nullptr;
	status = getTypedArray(env, args[5], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glColorTableEXT(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const void *data)
	glColorTableEXT(target, internalFormat, width, format, type, data);
	return NULL;
}

napi_value PixelTransformParameterfEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat param = getDouble(env, args[2]);
	// void glPixelTransformParameterfEXT(GLenum target, GLenum pname, const GLfloat param)
	glPixelTransformParameterfEXT(target, pname, param);
	return NULL;
}

napi_value PixelTransformParameterfvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat* params;
	// void glPixelTransformParameterfvEXT(GLenum target, GLenum pname, const GLfloat* params)
	glPixelTransformParameterfvEXT(target, pname, params);
	return NULL;
}

napi_value PixelTransformParameteriEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint param = getInt32(env, args[2]);
	// void glPixelTransformParameteriEXT(GLenum target, GLenum pname, const GLint param)
	glPixelTransformParameteriEXT(target, pname, param);
	return NULL;
}

napi_value PixelTransformParameterivEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint* params;
	// void glPixelTransformParameterivEXT(GLenum target, GLenum pname, const GLint* params)
	glPixelTransformParameterivEXT(target, pname, params);
	return NULL;
}

napi_value PointParameterfEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat param = getDouble(env, args[1]);
	// void glPointParameterfEXT(GLenum pname, GLfloat param)
	glPointParameterfEXT(pname, param);
	return NULL;
}

napi_value PointParameterfvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat* params;
	// void glPointParameterfvEXT(GLenum pname, const GLfloat* params)
	glPointParameterfvEXT(pname, params);
	return NULL;
}

napi_value PolygonOffsetEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLfloat factor = getDouble(env, args[0]);
	GLfloat bias = getDouble(env, args[1]);
	// void glPolygonOffsetEXT(GLfloat factor, GLfloat bias)
	glPolygonOffsetEXT(factor, bias);
	return NULL;
}

napi_value PolygonOffsetClampEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLfloat factor = getDouble(env, args[0]);
	GLfloat units = getDouble(env, args[1]);
	GLfloat clamp = getDouble(env, args[2]);
	// void glPolygonOffsetClampEXT(GLfloat factor, GLfloat units, GLfloat clamp)
	glPolygonOffsetClampEXT(factor, units, clamp);
	return NULL;
}

napi_value ProvokingVertexEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum mode = getUint32(env, args[0]);
	// void glProvokingVertexEXT(GLenum mode)
	glProvokingVertexEXT(mode);
	return NULL;
}

napi_value CoverageModulationNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum components = getUint32(env, args[0]);
	// void glCoverageModulationNV(GLenum components)
	glCoverageModulationNV(components);
	return NULL;
}

napi_value CoverageModulationTableNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLfloat* v;
	// void glCoverageModulationTableNV(GLsizei n, const GLfloat* v)
	glCoverageModulationTableNV(n, v);
	return NULL;
}

napi_value RasterSamplesEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint samples = getUint32(env, args[0]);
	GLboolean fixedsamplelocations = getBool(env, args[1]);
	// void glRasterSamplesEXT(GLuint samples, GLboolean fixedsamplelocations)
	glRasterSamplesEXT(samples, fixedsamplelocations);
	return NULL;
}

napi_value BeginSceneEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glBeginSceneEXT(void)
	glBeginSceneEXT();
	return NULL;
}

napi_value EndSceneEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glEndSceneEXT(void)
	glEndSceneEXT();
	return NULL;
}

napi_value SecondaryColorPointerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLint size = getInt32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	GLsizei stride = getInt32(env, args[2]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[3], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, const void *pointer)
	glSecondaryColorPointerEXT(size, type, stride, pointer);
	return NULL;
}

napi_value ActiveProgramEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint program = getUint32(env, args[0]);
	// void glActiveProgramEXT(GLuint program)
	glActiveProgramEXT(program);
	return NULL;
}

napi_value CreateShaderProgramEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum type = getUint32(env, args[0]);
	GLchar* string;
	// GLuint glCreateShaderProgramEXT(GLenum type, const GLchar* string)
	GLuint result = glCreateShaderProgramEXT(type, string);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value UseShaderProgramEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum type = getUint32(env, args[0]);
	GLuint program = getUint32(env, args[1]);
	// void glUseShaderProgramEXT(GLenum type, GLuint program)
	glUseShaderProgramEXT(type, program);
	return NULL;
}

napi_value BindImageTextureEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLuint index = getUint32(env, args[0]);
	GLuint texture = getUint32(env, args[1]);
	GLint level = getInt32(env, args[2]);
	GLboolean layered = getBool(env, args[3]);
	GLint layer = getInt32(env, args[4]);
	GLenum access = getUint32(env, args[5]);
	GLint format = getInt32(env, args[6]);
	// void glBindImageTextureEXT(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format)
	glBindImageTextureEXT(index, texture, level, layered, layer, access, format);
	return NULL;
}

napi_value MemoryBarrierEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLbitfield barriers = getUint32(env, args[0]);
	// void glMemoryBarrierEXT(GLbitfield barriers)
	glMemoryBarrierEXT(barriers);
	return NULL;
}

napi_value ActiveStencilFaceEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum face = getUint32(env, args[0]);
	// void glActiveStencilFaceEXT(GLenum face)
	glActiveStencilFaceEXT(face);
	return NULL;
}

napi_value FramebufferTextureLayerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLenum attachment = getUint32(env, args[1]);
	GLuint texture = getUint32(env, args[2]);
	GLint level = getInt32(env, args[3]);
	GLint layer = getInt32(env, args[4]);
	// void glFramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
	glFramebufferTextureLayerEXT(target, attachment, texture, level, layer);
	return NULL;
}

napi_value TexBufferEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	// void glTexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer)
	glTexBufferEXT(target, internalformat, buffer);
	return NULL;
}

napi_value ClearColorIiEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLint red = getInt32(env, args[0]);
	GLint green = getInt32(env, args[1]);
	GLint blue = getInt32(env, args[2]);
	GLint alpha = getInt32(env, args[3]);
	// void glClearColorIiEXT(GLint red, GLint green, GLint blue, GLint alpha)
	glClearColorIiEXT(red, green, blue, alpha);
	return NULL;
}

napi_value ClearColorIuiEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint red = getUint32(env, args[0]);
	GLuint green = getUint32(env, args[1]);
	GLuint blue = getUint32(env, args[2]);
	GLuint alpha = getUint32(env, args[3]);
	// void glClearColorIuiEXT(GLuint red, GLuint green, GLuint blue, GLuint alpha)
	glClearColorIuiEXT(red, green, blue, alpha);
	return NULL;
}

napi_value TexParameterIivEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint * params = nullptr;
	status = getTypedArray(env, args[2], params);
	// void glTexParameterIivEXT(GLenum target, GLenum pname, const GLint *params)
	glTexParameterIivEXT(target, pname, params);
	return NULL;
}

napi_value TexParameterIuivEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLuint * params = nullptr;
	status = getTypedArray(env, args[2], params);
	// void glTexParameterIuivEXT(GLenum target, GLenum pname, const GLuint *params)
	glTexParameterIuivEXT(target, pname, params);
	return NULL;
}

napi_value AreTexturesResidentEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLsizei n = getInt32(env, args[0]);
	GLuint* textures;
	GLboolean* residences;
	// GLboolean glAreTexturesResidentEXT(GLsizei n, const GLuint* textures, GLboolean* residences)
	GLboolean result = glAreTexturesResidentEXT(n, textures, residences);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value BindTextureEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLuint texture = getUint32(env, args[1]);
	// void glBindTextureEXT(GLenum target, GLuint texture)
	glBindTextureEXT(target, texture);
	return NULL;
}

napi_value DeleteTexturesEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* textures;
	// void glDeleteTexturesEXT(GLsizei n, const GLuint* textures)
	glDeleteTexturesEXT(n, textures);
	return NULL;
}

napi_value GenTexturesEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* textures;
	// void glGenTexturesEXT(GLsizei n, GLuint* textures)
	glGenTexturesEXT(n, textures);
	return NULL;
}

napi_value IsTextureEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint texture = getUint32(env, args[0]);
	// GLboolean glIsTextureEXT(GLuint texture)
	GLboolean result = glIsTextureEXT(texture);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value PrioritizeTexturesEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLsizei n = getInt32(env, args[0]);
	GLuint* textures;
	GLclampf* priorities;
	// void glPrioritizeTexturesEXT(GLsizei n, const GLuint* textures, const GLclampf* priorities)
	glPrioritizeTexturesEXT(n, textures, priorities);
	return NULL;
}

napi_value TextureNormalEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum mode = getUint32(env, args[0]);
	// void glTextureNormalEXT(GLenum mode)
	glTextureNormalEXT(mode);
	return NULL;
}

napi_value BeginTransformFeedbackEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum primitiveMode = getUint32(env, args[0]);
	// void glBeginTransformFeedbackEXT(GLenum primitiveMode)
	glBeginTransformFeedbackEXT(primitiveMode);
	return NULL;
}

napi_value BindBufferBaseEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	// void glBindBufferBaseEXT(GLenum target, GLuint index, GLuint buffer)
	glBindBufferBaseEXT(target, index, buffer);
	return NULL;
}

napi_value BindBufferOffsetEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	GLintptr offset = getInt32(env, args[3]);
	// void glBindBufferOffsetEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset)
	glBindBufferOffsetEXT(target, index, buffer, offset);
	return NULL;
}

napi_value BindBufferRangeEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	GLintptr offset = getInt32(env, args[3]);
	GLsizeiptr size = getUint32(env, args[4]);
	// void glBindBufferRangeEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
	glBindBufferRangeEXT(target, index, buffer, offset, size);
	return NULL;
}

napi_value EndTransformFeedbackEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glEndTransformFeedbackEXT(void)
	glEndTransformFeedbackEXT();
	return NULL;
}

napi_value TransformFeedbackVaryingsEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint program = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLchar * * varyings;
	GLenum bufferMode = getUint32(env, args[3]);
	// void glTransformFeedbackVaryingsEXT(GLuint program, GLsizei count, const GLchar * const* varyings, GLenum bufferMode)
	glTransformFeedbackVaryingsEXT(program, count, varyings, bufferMode);
	return NULL;
}

napi_value ArrayElementEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLint i = getInt32(env, args[0]);
	// void glArrayElementEXT(GLint i)
	glArrayElementEXT(i);
	return NULL;
}

napi_value ColorPointerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLint size = getInt32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	GLsizei stride = getInt32(env, args[2]);
	GLsizei count = getInt32(env, args[3]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[4], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer)
	glColorPointerEXT(size, type, stride, count, pointer);
	return NULL;
}

napi_value DrawArraysEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum mode = getUint32(env, args[0]);
	GLint first = getInt32(env, args[1]);
	GLsizei count = getInt32(env, args[2]);
	// void glDrawArraysEXT(GLenum mode, GLint first, GLsizei count)
	glDrawArraysEXT(mode, first, count);
	return NULL;
}

napi_value EdgeFlagPointerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLsizei stride = getInt32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLboolean* pointer;
	// void glEdgeFlagPointerEXT(GLsizei stride, GLsizei count, const GLboolean* pointer)
	glEdgeFlagPointerEXT(stride, count, pointer);
	return NULL;
}

napi_value IndexPointerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum type = getUint32(env, args[0]);
	GLsizei stride = getInt32(env, args[1]);
	GLsizei count = getInt32(env, args[2]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[3], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glIndexPointerEXT(GLenum type, GLsizei stride, GLsizei count, const void *pointer)
	glIndexPointerEXT(type, stride, count, pointer);
	return NULL;
}

napi_value NormalPointerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum type = getUint32(env, args[0]);
	GLsizei stride = getInt32(env, args[1]);
	GLsizei count = getInt32(env, args[2]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[3], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glNormalPointerEXT(GLenum type, GLsizei stride, GLsizei count, const void *pointer)
	glNormalPointerEXT(type, stride, count, pointer);
	return NULL;
}

napi_value TexCoordPointerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLint size = getInt32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	GLsizei stride = getInt32(env, args[2]);
	GLsizei count = getInt32(env, args[3]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[4], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glTexCoordPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer)
	glTexCoordPointerEXT(size, type, stride, count, pointer);
	return NULL;
}

napi_value VertexPointerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLint size = getInt32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	GLsizei stride = getInt32(env, args[2]);
	GLsizei count = getInt32(env, args[3]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[4], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glVertexPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer)
	glVertexPointerEXT(size, type, stride, count, pointer);
	return NULL;
}

napi_value VertexArrayVertexAttribLOffsetEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLuint vaobj = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	GLuint index = getUint32(env, args[2]);
	GLint size = getInt32(env, args[3]);
	GLenum type = getUint32(env, args[4]);
	GLsizei stride = getInt32(env, args[5]);
	GLintptr offset = getInt32(env, args[6]);
	// void glVertexArrayVertexAttribLOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset)
	glVertexArrayVertexAttribLOffsetEXT(vaobj, buffer, index, size, type, stride, offset);
	return NULL;
}

napi_value VertexAttribLPointerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint index = getUint32(env, args[0]);
	GLint size = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLsizei stride = getInt32(env, args[3]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[4], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glVertexAttribLPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer)
	glVertexAttribLPointerEXT(index, size, type, stride, pointer);
	return NULL;
}

napi_value BeginVertexShaderEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glBeginVertexShaderEXT(void)
	glBeginVertexShaderEXT();
	return NULL;
}

napi_value BindLightParameterEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum light = getUint32(env, args[0]);
	GLenum value = getUint32(env, args[1]);
	// GLuint glBindLightParameterEXT(GLenum light, GLenum value)
	GLuint result = glBindLightParameterEXT(light, value);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value BindMaterialParameterEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum face = getUint32(env, args[0]);
	GLenum value = getUint32(env, args[1]);
	// GLuint glBindMaterialParameterEXT(GLenum face, GLenum value)
	GLuint result = glBindMaterialParameterEXT(face, value);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value BindParameterEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum value = getUint32(env, args[0]);
	// GLuint glBindParameterEXT(GLenum value)
	GLuint result = glBindParameterEXT(value);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value BindTexGenParameterEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum unit = getUint32(env, args[0]);
	GLenum coord = getUint32(env, args[1]);
	GLenum value = getUint32(env, args[2]);
	// GLuint glBindTexGenParameterEXT(GLenum unit, GLenum coord, GLenum value)
	GLuint result = glBindTexGenParameterEXT(unit, coord, value);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value BindTextureUnitParameterEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum unit = getUint32(env, args[0]);
	GLenum value = getUint32(env, args[1]);
	// GLuint glBindTextureUnitParameterEXT(GLenum unit, GLenum value)
	GLuint result = glBindTextureUnitParameterEXT(unit, value);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value BindVertexShaderEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint id = getUint32(env, args[0]);
	// void glBindVertexShaderEXT(GLuint id)
	glBindVertexShaderEXT(id);
	return NULL;
}

napi_value DeleteVertexShaderEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint id = getUint32(env, args[0]);
	// void glDeleteVertexShaderEXT(GLuint id)
	glDeleteVertexShaderEXT(id);
	return NULL;
}

napi_value DisableVariantClientStateEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint id = getUint32(env, args[0]);
	// void glDisableVariantClientStateEXT(GLuint id)
	glDisableVariantClientStateEXT(id);
	return NULL;
}

napi_value EnableVariantClientStateEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint id = getUint32(env, args[0]);
	// void glEnableVariantClientStateEXT(GLuint id)
	glEnableVariantClientStateEXT(id);
	return NULL;
}

napi_value EndVertexShaderEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glEndVertexShaderEXT(void)
	glEndVertexShaderEXT();
	return NULL;
}

napi_value ExtractComponentEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint res = getUint32(env, args[0]);
	GLuint src = getUint32(env, args[1]);
	GLuint num = getUint32(env, args[2]);
	// void glExtractComponentEXT(GLuint res, GLuint src, GLuint num)
	glExtractComponentEXT(res, src, num);
	return NULL;
}

napi_value GenSymbolsEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum dataType = getUint32(env, args[0]);
	GLenum storageType = getUint32(env, args[1]);
	GLenum range = getUint32(env, args[2]);
	GLuint components = getUint32(env, args[3]);
	// GLuint glGenSymbolsEXT(GLenum dataType, GLenum storageType, GLenum range, GLuint components)
	GLuint result = glGenSymbolsEXT(dataType, storageType, range, components);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value GenVertexShadersEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint range = getUint32(env, args[0]);
	// GLuint glGenVertexShadersEXT(GLuint range)
	GLuint result = glGenVertexShadersEXT(range);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value InsertComponentEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint res = getUint32(env, args[0]);
	GLuint src = getUint32(env, args[1]);
	GLuint num = getUint32(env, args[2]);
	// void glInsertComponentEXT(GLuint res, GLuint src, GLuint num)
	glInsertComponentEXT(res, src, num);
	return NULL;
}

napi_value IsVariantEnabledEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint id = getUint32(env, args[0]);
	GLenum cap = getUint32(env, args[1]);
	// GLboolean glIsVariantEnabledEXT(GLuint id, GLenum cap)
	GLboolean result = glIsVariantEnabledEXT(id, cap);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value SetInvariantEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint id = getUint32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	void * addr = nullptr;
	status = getTypedArray(env, args[2], *(void **)&addr);
	if (status != napi_ok) return nullptr;
	// void glSetInvariantEXT(GLuint id, GLenum type, void *addr)
	glSetInvariantEXT(id, type, addr);
	return NULL;
}

napi_value SetLocalConstantEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint id = getUint32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	void * addr = nullptr;
	status = getTypedArray(env, args[2], *(void **)&addr);
	if (status != napi_ok) return nullptr;
	// void glSetLocalConstantEXT(GLuint id, GLenum type, void *addr)
	glSetLocalConstantEXT(id, type, addr);
	return NULL;
}

napi_value SwizzleEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLuint res = getUint32(env, args[0]);
	GLuint in = getUint32(env, args[1]);
	GLenum outX = getUint32(env, args[2]);
	GLenum outY = getUint32(env, args[3]);
	GLenum outZ = getUint32(env, args[4]);
	GLenum outW = getUint32(env, args[5]);
	// void glSwizzleEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW)
	glSwizzleEXT(res, in, outX, outY, outZ, outW);
	return NULL;
}

napi_value VariantPointerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint id = getUint32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	GLuint stride = getUint32(env, args[2]);
	void * addr = nullptr;
	status = getTypedArray(env, args[3], *(void **)&addr);
	if (status != napi_ok) return nullptr;
	// void glVariantPointerEXT(GLuint id, GLenum type, GLuint stride, void *addr)
	glVariantPointerEXT(id, type, stride, addr);
	return NULL;
}

napi_value VariantbvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint id = getUint32(env, args[0]);
	GLbyte * addr;
	// void glVariantbvEXT(GLuint id, GLbyte *addr)
	glVariantbvEXT(id, addr);
	return NULL;
}

napi_value VariantdvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint id = getUint32(env, args[0]);
	GLdouble * addr;
	// void glVariantdvEXT(GLuint id, GLdouble *addr)
	glVariantdvEXT(id, addr);
	return NULL;
}

napi_value VariantfvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint id = getUint32(env, args[0]);
	GLfloat * addr = nullptr;
	status = getTypedArray(env, args[1], addr);
	// void glVariantfvEXT(GLuint id, GLfloat *addr)
	glVariantfvEXT(id, addr);
	return NULL;
}

napi_value VariantivEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint id = getUint32(env, args[0]);
	GLint * addr = nullptr;
	status = getTypedArray(env, args[1], addr);
	// void glVariantivEXT(GLuint id, GLint *addr)
	glVariantivEXT(id, addr);
	return NULL;
}

napi_value VariantsvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint id = getUint32(env, args[0]);
	GLshort * addr;
	// void glVariantsvEXT(GLuint id, GLshort *addr)
	glVariantsvEXT(id, addr);
	return NULL;
}

napi_value VariantubvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint id = getUint32(env, args[0]);
	GLubyte * addr;
	// void glVariantubvEXT(GLuint id, GLubyte *addr)
	glVariantubvEXT(id, addr);
	return NULL;
}

napi_value VariantuivEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint id = getUint32(env, args[0]);
	GLuint * addr = nullptr;
	status = getTypedArray(env, args[1], addr);
	// void glVariantuivEXT(GLuint id, GLuint *addr)
	glVariantuivEXT(id, addr);
	return NULL;
}

napi_value VariantusvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint id = getUint32(env, args[0]);
	GLushort * addr;
	// void glVariantusvEXT(GLuint id, GLushort *addr)
	glVariantusvEXT(id, addr);
	return NULL;
}

napi_value WriteMaskEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLuint res = getUint32(env, args[0]);
	GLuint in = getUint32(env, args[1]);
	GLenum outX = getUint32(env, args[2]);
	GLenum outY = getUint32(env, args[3]);
	GLenum outZ = getUint32(env, args[4]);
	GLenum outW = getUint32(env, args[5]);
	// void glWriteMaskEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW)
	glWriteMaskEXT(res, in, outX, outY, outZ, outW);
	return NULL;
}

napi_value VertexWeightPointerEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLint size = getInt32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	GLsizei stride = getInt32(env, args[2]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[3], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glVertexWeightPointerEXT(GLint size, GLenum type, GLsizei stride, void *pointer)
	glVertexWeightPointerEXT(size, type, stride, pointer);
	return NULL;
}

napi_value VertexWeightfEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLfloat weight = getDouble(env, args[0]);
	// void glVertexWeightfEXT(GLfloat weight)
	glVertexWeightfEXT(weight);
	return NULL;
}

napi_value VertexWeightfvEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLfloat* weight;
	// void glVertexWeightfvEXT(GLfloat* weight)
	glVertexWeightfvEXT(weight);
	return NULL;
}

napi_value ImportSyncEXT(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum external_sync_type = getUint32(env, args[0]);
	GLintptr external_sync = getInt32(env, args[1]);
	GLbitfield flags = getUint32(env, args[2]);
	// GLsync glImportSyncEXT(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags)
	GLsync result = glImportSyncEXT(external_sync_type, external_sync, flags);
	napi_value result_value = nullptr;
	status = napi_create_external(env, (void *)result, NULL, NULL, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value FrameTerminatorGREMEDY(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glFrameTerminatorGREMEDY(void)
	glFrameTerminatorGREMEDY();
	return NULL;
}

napi_value StringMarkerGREMEDY(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei len = getInt32(env, args[0]);
	void * string = nullptr;
	status = getTypedArray(env, args[1], *(void **)&string);
	if (status != napi_ok) return nullptr;
	// void glStringMarkerGREMEDY(GLsizei len, const void *string)
	glStringMarkerGREMEDY(len, string);
	return NULL;
}

napi_value ImageTransformParameterfHP(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat param = getDouble(env, args[2]);
	// void glImageTransformParameterfHP(GLenum target, GLenum pname, const GLfloat param)
	glImageTransformParameterfHP(target, pname, param);
	return NULL;
}

napi_value ImageTransformParameterfvHP(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat* params;
	// void glImageTransformParameterfvHP(GLenum target, GLenum pname, const GLfloat* params)
	glImageTransformParameterfvHP(target, pname, params);
	return NULL;
}

napi_value ImageTransformParameteriHP(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint param = getInt32(env, args[2]);
	// void glImageTransformParameteriHP(GLenum target, GLenum pname, const GLint param)
	glImageTransformParameteriHP(target, pname, param);
	return NULL;
}

napi_value ImageTransformParameterivHP(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint* params;
	// void glImageTransformParameterivHP(GLenum target, GLenum pname, const GLint* params)
	glImageTransformParameterivHP(target, pname, params);
	return NULL;
}

napi_value MultiModeDrawArraysIBM(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum* mode;
	GLint * first = nullptr;
	status = getTypedArray(env, args[1], first);
	GLsizei * count = nullptr;
	status = getTypedArray(env, args[2], count);
	GLsizei primcount = getInt32(env, args[3]);
	GLint modestride = getInt32(env, args[4]);
	// void glMultiModeDrawArraysIBM(const GLenum* mode, const GLint *first, const GLsizei *count, GLsizei primcount, GLint modestride)
	glMultiModeDrawArraysIBM(mode, first, count, primcount, modestride);
	return NULL;
}

napi_value MultiModeDrawElementsIBM(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum* mode;
	GLsizei * count = nullptr;
	status = getTypedArray(env, args[1], count);
	GLenum type = getUint32(env, args[2]);
	void * * indices;
	GLsizei primcount = getInt32(env, args[4]);
	GLint modestride = getInt32(env, args[5]);
	// void glMultiModeDrawElementsIBM(const GLenum* mode, const GLsizei *count, GLenum type, const void *const *indices, GLsizei primcount, GLint modestride)
	glMultiModeDrawElementsIBM(mode, count, type, indices, primcount, modestride);
	return NULL;
}

napi_value SyncTextureINTEL(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint texture = getUint32(env, args[0]);
	// void glSyncTextureINTEL(GLuint texture)
	glSyncTextureINTEL(texture);
	return NULL;
}

napi_value BeginPerfQueryINTEL(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint queryHandle = getUint32(env, args[0]);
	// void glBeginPerfQueryINTEL(GLuint queryHandle)
	glBeginPerfQueryINTEL(queryHandle);
	return NULL;
}

napi_value CreatePerfQueryINTEL(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint queryId = getUint32(env, args[0]);
	GLuint* queryHandle;
	// void glCreatePerfQueryINTEL(GLuint queryId, GLuint* queryHandle)
	glCreatePerfQueryINTEL(queryId, queryHandle);
	return NULL;
}

napi_value DeletePerfQueryINTEL(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint queryHandle = getUint32(env, args[0]);
	// void glDeletePerfQueryINTEL(GLuint queryHandle)
	glDeletePerfQueryINTEL(queryHandle);
	return NULL;
}

napi_value EndPerfQueryINTEL(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint queryHandle = getUint32(env, args[0]);
	// void glEndPerfQueryINTEL(GLuint queryHandle)
	glEndPerfQueryINTEL(queryHandle);
	return NULL;
}

napi_value TexScissorFuncINTEL(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum lfunc = getUint32(env, args[1]);
	GLenum hfunc = getUint32(env, args[2]);
	// void glTexScissorFuncINTEL(GLenum target, GLenum lfunc, GLenum hfunc)
	glTexScissorFuncINTEL(target, lfunc, hfunc);
	return NULL;
}

napi_value TexScissorINTEL(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLclampf tlow;
	GLclampf thigh;
	// void glTexScissorINTEL(GLenum target, GLclampf tlow, GLclampf thigh)
	glTexScissorINTEL(target, tlow, thigh);
	return NULL;
}

napi_value BlendBarrierKHR(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glBlendBarrierKHR(void)
	glBlendBarrierKHR();
	return NULL;
}

napi_value DebugMessageCallback(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLDEBUGPROC callback;
	void * userParam = nullptr;
	status = getTypedArray(env, args[1], *(void **)&userParam);
	if (status != napi_ok) return nullptr;
	// void glDebugMessageCallback(GLDEBUGPROC callback, const void *userParam)
	glDebugMessageCallback(callback, userParam);
	return NULL;
}

napi_value DebugMessageControl(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum source = getUint32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	GLenum severity = getUint32(env, args[2]);
	GLsizei count = getInt32(env, args[3]);
	GLuint* ids;
	GLboolean enabled = getBool(env, args[5]);
	// void glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled)
	glDebugMessageControl(source, type, severity, count, ids, enabled);
	return NULL;
}

napi_value DebugMessageInsert(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum source = getUint32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	GLuint id = getUint32(env, args[2]);
	GLenum severity = getUint32(env, args[3]);
	GLsizei length = getInt32(env, args[4]);
	GLchar* buf;
	// void glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf)
	glDebugMessageInsert(source, type, id, severity, length, buf);
	return NULL;
}

napi_value ObjectLabel(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum identifier = getUint32(env, args[0]);
	GLuint name = getUint32(env, args[1]);
	GLsizei length = getInt32(env, args[2]);
	GLchar* label;
	// void glObjectLabel(GLenum identifier, GLuint name, GLsizei length, const GLchar* label)
	glObjectLabel(identifier, name, length, label);
	return NULL;
}

napi_value ObjectPtrLabel(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	void * ptr = nullptr;
	status = getTypedArray(env, args[0], *(void **)&ptr);
	if (status != napi_ok) return nullptr;
	GLsizei length = getInt32(env, args[1]);
	GLchar* label;
	// void glObjectPtrLabel(const void *ptr, GLsizei length, const GLchar* label)
	glObjectPtrLabel(ptr, length, label);
	return NULL;
}

napi_value PopDebugGroup(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glPopDebugGroup(void)
	glPopDebugGroup();
	return NULL;
}

napi_value PushDebugGroup(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum source = getUint32(env, args[0]);
	GLuint id = getUint32(env, args[1]);
	GLsizei length = getInt32(env, args[2]);
	GLchar * message = nullptr;
	status = getCharacterArray(env, args[3], message);
	// void glPushDebugGroup(GLenum source, GLuint id, GLsizei length, const GLchar * message)
	glPushDebugGroup(source, id, length, message);
	return NULL;
}

napi_value ReadnPixels(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[8];
	size_t argc = checkArgCount(env, info, args, 8, 8);
	GLint x = getInt32(env, args[0]);
	GLint y = getInt32(env, args[1]);
	GLsizei width = getInt32(env, args[2]);
	GLsizei height = getInt32(env, args[3]);
	GLenum format = getUint32(env, args[4]);
	GLenum type = getUint32(env, args[5]);
	GLsizei bufSize = getInt32(env, args[6]);
	void * data = nullptr;
	status = getTypedArray(env, args[7], *(void **)&data);
	if (status != napi_ok) return nullptr;
	// void glReadnPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data)
	glReadnPixels(x, y, width, height, format, type, bufSize, data);
	return NULL;
}

napi_value BufferRegionEnabled(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// GLuint glBufferRegionEnabled(void)
	GLuint result = glBufferRegionEnabled();
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value DeleteBufferRegion(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum region = getUint32(env, args[0]);
	// void glDeleteBufferRegion(GLenum region)
	glDeleteBufferRegion(region);
	return NULL;
}

napi_value DrawBufferRegion(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLuint region = getUint32(env, args[0]);
	GLint x = getInt32(env, args[1]);
	GLint y = getInt32(env, args[2]);
	GLsizei width = getInt32(env, args[3]);
	GLsizei height = getInt32(env, args[4]);
	GLint xDest = getInt32(env, args[5]);
	GLint yDest = getInt32(env, args[6]);
	// void glDrawBufferRegion(GLuint region, GLint x, GLint y, GLsizei width, GLsizei height, GLint xDest, GLint yDest)
	glDrawBufferRegion(region, x, y, width, height, xDest, yDest);
	return NULL;
}

napi_value NewBufferRegion(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum region = getUint32(env, args[0]);
	// GLuint glNewBufferRegion(GLenum region)
	GLuint result = glNewBufferRegion(region);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value ReadBufferRegion(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint region = getUint32(env, args[0]);
	GLint x = getInt32(env, args[1]);
	GLint y = getInt32(env, args[2]);
	GLsizei width = getInt32(env, args[3]);
	GLsizei height = getInt32(env, args[4]);
	// void glReadBufferRegion(GLuint region, GLint x, GLint y, GLsizei width, GLsizei height)
	glReadBufferRegion(region, x, y, width, height);
	return NULL;
}

napi_value ResizeBuffersMESA(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glResizeBuffersMESA(void)
	glResizeBuffersMESA();
	return NULL;
}

napi_value BeginConditionalRenderNVX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint id = getUint32(env, args[0]);
	// void glBeginConditionalRenderNVX(GLuint id)
	glBeginConditionalRenderNVX(id);
	return NULL;
}

napi_value EndConditionalRenderNVX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glEndConditionalRenderNVX(void)
	glEndConditionalRenderNVX();
	return NULL;
}

napi_value MultiDrawArraysIndirectBindlessNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum mode = getUint32(env, args[0]);
	void * indirect = nullptr;
	status = getTypedArray(env, args[1], *(void **)&indirect);
	if (status != napi_ok) return nullptr;
	GLsizei drawCount = getInt32(env, args[2]);
	GLsizei stride = getInt32(env, args[3]);
	GLint vertexBufferCount = getInt32(env, args[4]);
	// void glMultiDrawArraysIndirectBindlessNV(GLenum mode, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount)
	glMultiDrawArraysIndirectBindlessNV(mode, indirect, drawCount, stride, vertexBufferCount);
	return NULL;
}

napi_value MultiDrawElementsIndirectBindlessNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum mode = getUint32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	void * indirect = nullptr;
	status = getTypedArray(env, args[2], *(void **)&indirect);
	if (status != napi_ok) return nullptr;
	GLsizei drawCount = getInt32(env, args[3]);
	GLsizei stride = getInt32(env, args[4]);
	GLint vertexBufferCount = getInt32(env, args[5]);
	// void glMultiDrawElementsIndirectBindlessNV(GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount)
	glMultiDrawElementsIndirectBindlessNV(mode, type, indirect, drawCount, stride, vertexBufferCount);
	return NULL;
}

napi_value MultiDrawArraysIndirectBindlessCountNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum mode = getUint32(env, args[0]);
	void * indirect = nullptr;
	status = getTypedArray(env, args[1], *(void **)&indirect);
	if (status != napi_ok) return nullptr;
	GLintptr drawCount = getInt32(env, args[2]);
	GLsizei maxDrawCount = getInt32(env, args[3]);
	GLsizei stride = getInt32(env, args[4]);
	GLint vertexBufferCount = getInt32(env, args[5]);
	// void glMultiDrawArraysIndirectBindlessCountNV(GLenum mode, const void *indirect, GLintptr drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount)
	glMultiDrawArraysIndirectBindlessCountNV(mode, indirect, drawCount, maxDrawCount, stride, vertexBufferCount);
	return NULL;
}

napi_value MultiDrawElementsIndirectBindlessCountNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLenum mode = getUint32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	void * indirect = nullptr;
	status = getTypedArray(env, args[2], *(void **)&indirect);
	if (status != napi_ok) return nullptr;
	GLintptr drawCount = getInt32(env, args[3]);
	GLsizei maxDrawCount = getInt32(env, args[4]);
	GLsizei stride = getInt32(env, args[5]);
	GLint vertexBufferCount = getInt32(env, args[6]);
	// void glMultiDrawElementsIndirectBindlessCountNV(GLenum mode, GLenum type, const void *indirect, GLintptr drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount)
	glMultiDrawElementsIndirectBindlessCountNV(mode, type, indirect, drawCount, maxDrawCount, stride, vertexBufferCount);
	return NULL;
}

napi_value IsImageHandleResidentNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	uint64_t handle = 0;
	uint32_t handle_uint32;
	bool handle_lossless;
		status = napi_get_value_uint32(env, args[0], &handle_uint32);
		handle = handle_uint32;
	if (status != napi_ok) return nullptr;
	// GLboolean glIsImageHandleResidentNV(GLuint64 handle)
	GLboolean result = glIsImageHandleResidentNV(handle);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value IsTextureHandleResidentNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	uint64_t handle = 0;
	uint32_t handle_uint32;
	bool handle_lossless;
		status = napi_get_value_uint32(env, args[0], &handle_uint32);
		handle = handle_uint32;
	if (status != napi_ok) return nullptr;
	// GLboolean glIsTextureHandleResidentNV(GLuint64 handle)
	GLboolean result = glIsTextureHandleResidentNV(handle);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value MakeImageHandleNonResidentNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	uint64_t handle = 0;
	uint32_t handle_uint32;
	bool handle_lossless;
		status = napi_get_value_uint32(env, args[0], &handle_uint32);
		handle = handle_uint32;
	if (status != napi_ok) return nullptr;
	// void glMakeImageHandleNonResidentNV(GLuint64 handle)
	glMakeImageHandleNonResidentNV(handle);
	return NULL;
}

napi_value MakeImageHandleResidentNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	uint64_t handle = 0;
	uint32_t handle_uint32;
	bool handle_lossless;
		status = napi_get_value_uint32(env, args[0], &handle_uint32);
		handle = handle_uint32;
	if (status != napi_ok) return nullptr;
	GLenum access = getUint32(env, args[1]);
	// void glMakeImageHandleResidentNV(GLuint64 handle, GLenum access)
	glMakeImageHandleResidentNV(handle, access);
	return NULL;
}

napi_value MakeTextureHandleNonResidentNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	uint64_t handle = 0;
	uint32_t handle_uint32;
	bool handle_lossless;
		status = napi_get_value_uint32(env, args[0], &handle_uint32);
		handle = handle_uint32;
	if (status != napi_ok) return nullptr;
	// void glMakeTextureHandleNonResidentNV(GLuint64 handle)
	glMakeTextureHandleNonResidentNV(handle);
	return NULL;
}

napi_value MakeTextureHandleResidentNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	uint64_t handle = 0;
	uint32_t handle_uint32;
	bool handle_lossless;
		status = napi_get_value_uint32(env, args[0], &handle_uint32);
		handle = handle_uint32;
	if (status != napi_ok) return nullptr;
	// void glMakeTextureHandleResidentNV(GLuint64 handle)
	glMakeTextureHandleResidentNV(handle);
	return NULL;
}

napi_value BlendBarrierNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glBlendBarrierNV(void)
	glBlendBarrierNV();
	return NULL;
}

napi_value BlendParameteriNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint value = getInt32(env, args[1]);
	// void glBlendParameteriNV(GLenum pname, GLint value)
	glBlendParameteriNV(pname, value);
	return NULL;
}

napi_value BeginConditionalRenderNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint id = getUint32(env, args[0]);
	GLenum mode = getUint32(env, args[1]);
	// void glBeginConditionalRenderNV(GLuint id, GLenum mode)
	glBeginConditionalRenderNV(id, mode);
	return NULL;
}

napi_value EndConditionalRenderNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glEndConditionalRenderNV(void)
	glEndConditionalRenderNV();
	return NULL;
}

napi_value SubpixelPrecisionBiasNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint xbits = getUint32(env, args[0]);
	GLuint ybits = getUint32(env, args[1]);
	// void glSubpixelPrecisionBiasNV(GLuint xbits, GLuint ybits)
	glSubpixelPrecisionBiasNV(xbits, ybits);
	return NULL;
}

napi_value ConservativeRasterParameterfNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat value = getDouble(env, args[1]);
	// void glConservativeRasterParameterfNV(GLenum pname, GLfloat value)
	glConservativeRasterParameterfNV(pname, value);
	return NULL;
}

napi_value CopyImageSubDataNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[15];
	size_t argc = checkArgCount(env, info, args, 15, 15);
	GLuint srcName = getUint32(env, args[0]);
	GLenum srcTarget = getUint32(env, args[1]);
	GLint srcLevel = getInt32(env, args[2]);
	GLint srcX = getInt32(env, args[3]);
	GLint srcY = getInt32(env, args[4]);
	GLint srcZ = getInt32(env, args[5]);
	GLuint dstName = getUint32(env, args[6]);
	GLenum dstTarget = getUint32(env, args[7]);
	GLint dstLevel = getInt32(env, args[8]);
	GLint dstX = getInt32(env, args[9]);
	GLint dstY = getInt32(env, args[10]);
	GLint dstZ = getInt32(env, args[11]);
	GLsizei width = getInt32(env, args[12]);
	GLsizei height = getInt32(env, args[13]);
	GLsizei depth = getInt32(env, args[14]);
	// void glCopyImageSubDataNV(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth)
	glCopyImageSubDataNV(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth);
	return NULL;
}

napi_value ClearDepthdNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLdouble depth;
	// void glClearDepthdNV(GLdouble depth)
	glClearDepthdNV(depth);
	return NULL;
}

napi_value DepthBoundsdNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLdouble zmin;
	GLdouble zmax;
	// void glDepthBoundsdNV(GLdouble zmin, GLdouble zmax)
	glDepthBoundsdNV(zmin, zmax);
	return NULL;
}

napi_value DepthRangedNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLdouble zNear;
	GLdouble zFar;
	// void glDepthRangedNV(GLdouble zNear, GLdouble zFar)
	glDepthRangedNV(zNear, zFar);
	return NULL;
}

napi_value DrawTextureNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[11];
	size_t argc = checkArgCount(env, info, args, 11, 11);
	GLuint texture = getUint32(env, args[0]);
	GLuint sampler = getUint32(env, args[1]);
	GLfloat x0 = getDouble(env, args[2]);
	GLfloat y0 = getDouble(env, args[3]);
	GLfloat x1 = getDouble(env, args[4]);
	GLfloat y1 = getDouble(env, args[5]);
	GLfloat z = getDouble(env, args[6]);
	GLfloat s0 = getDouble(env, args[7]);
	GLfloat t0 = getDouble(env, args[8]);
	GLfloat s1 = getDouble(env, args[9]);
	GLfloat t1 = getDouble(env, args[10]);
	// void glDrawTextureNV(GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1)
	glDrawTextureNV(texture, sampler, x0, y0, x1, y1, z, s0, t0, s1, t1);
	return NULL;
}

napi_value EvalMapsNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLenum mode = getUint32(env, args[1]);
	// void glEvalMapsNV(GLenum target, GLenum mode)
	glEvalMapsNV(target, mode);
	return NULL;
}

napi_value MapControlPointsNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[9];
	size_t argc = checkArgCount(env, info, args, 9, 9);
	GLenum target = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLsizei ustride = getInt32(env, args[3]);
	GLsizei vstride = getInt32(env, args[4]);
	GLint uorder = getInt32(env, args[5]);
	GLint vorder = getInt32(env, args[6]);
	GLboolean packed = getBool(env, args[7]);
	void * points = nullptr;
	status = getTypedArray(env, args[8], *(void **)&points);
	if (status != napi_ok) return nullptr;
	// void glMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const void *points)
	glMapControlPointsNV(target, index, type, ustride, vstride, uorder, vorder, packed, points);
	return NULL;
}

napi_value MapParameterfvNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat* params;
	// void glMapParameterfvNV(GLenum target, GLenum pname, const GLfloat* params)
	glMapParameterfvNV(target, pname, params);
	return NULL;
}

napi_value MapParameterivNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint* params;
	// void glMapParameterivNV(GLenum target, GLenum pname, const GLint* params)
	glMapParameterivNV(target, pname, params);
	return NULL;
}

napi_value SampleMaskIndexedNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint index = getUint32(env, args[0]);
	GLbitfield mask = getUint32(env, args[1]);
	// void glSampleMaskIndexedNV(GLuint index, GLbitfield mask)
	glSampleMaskIndexedNV(index, mask);
	return NULL;
}

napi_value TexRenderbufferNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLuint renderbuffer = getUint32(env, args[1]);
	// void glTexRenderbufferNV(GLenum target, GLuint renderbuffer)
	glTexRenderbufferNV(target, renderbuffer);
	return NULL;
}

napi_value DeleteFencesNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* fences;
	// void glDeleteFencesNV(GLsizei n, const GLuint* fences)
	glDeleteFencesNV(n, fences);
	return NULL;
}

napi_value FinishFenceNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint fence = getUint32(env, args[0]);
	// void glFinishFenceNV(GLuint fence)
	glFinishFenceNV(fence);
	return NULL;
}

napi_value GenFencesNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* fences;
	// void glGenFencesNV(GLsizei n, GLuint* fences)
	glGenFencesNV(n, fences);
	return NULL;
}

napi_value IsFenceNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint fence = getUint32(env, args[0]);
	// GLboolean glIsFenceNV(GLuint fence)
	GLboolean result = glIsFenceNV(fence);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value SetFenceNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint fence = getUint32(env, args[0]);
	GLenum condition = getUint32(env, args[1]);
	// void glSetFenceNV(GLuint fence, GLenum condition)
	glSetFenceNV(fence, condition);
	return NULL;
}

napi_value TestFenceNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint fence = getUint32(env, args[0]);
	// GLboolean glTestFenceNV(GLuint fence)
	GLboolean result = glTestFenceNV(fence);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value FragmentCoverageColorNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint color = getUint32(env, args[0]);
	// void glFragmentCoverageColorNV(GLuint color)
	glFragmentCoverageColorNV(color);
	return NULL;
}

napi_value RenderbufferStorageMultisampleCoverageNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum target = getUint32(env, args[0]);
	GLsizei coverageSamples = getInt32(env, args[1]);
	GLsizei colorSamples = getInt32(env, args[2]);
	GLenum internalformat = getUint32(env, args[3]);
	GLsizei width = getInt32(env, args[4]);
	GLsizei height = getInt32(env, args[5]);
	// void glRenderbufferStorageMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height)
	glRenderbufferStorageMultisampleCoverageNV(target, coverageSamples, colorSamples, internalformat, width, height);
	return NULL;
}

napi_value ProgramVertexLimitNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLint limit = getInt32(env, args[1]);
	// void glProgramVertexLimitNV(GLenum target, GLint limit)
	glProgramVertexLimitNV(target, limit);
	return NULL;
}

napi_value FogCoordhNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLhalf fog;
	// void glFogCoordhNV(GLhalf fog)
	glFogCoordhNV(fog);
	return NULL;
}

napi_value FogCoordhvNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLhalf* fog;
	// void glFogCoordhvNV(const GLhalf* fog)
	glFogCoordhvNV(fog);
	return NULL;
}

napi_value VertexWeighthNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLhalf weight;
	// void glVertexWeighthNV(GLhalf weight)
	glVertexWeighthNV(weight);
	return NULL;
}

napi_value VertexWeighthvNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLhalf* weight;
	// void glVertexWeighthvNV(const GLhalf* weight)
	glVertexWeighthvNV(weight);
	return NULL;
}

napi_value BeginOcclusionQueryNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint id = getUint32(env, args[0]);
	// void glBeginOcclusionQueryNV(GLuint id)
	glBeginOcclusionQueryNV(id);
	return NULL;
}

napi_value DeleteOcclusionQueriesNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* ids;
	// void glDeleteOcclusionQueriesNV(GLsizei n, const GLuint* ids)
	glDeleteOcclusionQueriesNV(n, ids);
	return NULL;
}

napi_value EndOcclusionQueryNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glEndOcclusionQueryNV(void)
	glEndOcclusionQueryNV();
	return NULL;
}

napi_value GenOcclusionQueriesNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* ids;
	// void glGenOcclusionQueriesNV(GLsizei n, GLuint* ids)
	glGenOcclusionQueriesNV(n, ids);
	return NULL;
}

napi_value IsOcclusionQueryNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint id = getUint32(env, args[0]);
	// GLboolean glIsOcclusionQueryNV(GLuint id)
	GLboolean result = glIsOcclusionQueryNV(id);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value ProgramBufferParametersIivNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	GLuint index = getUint32(env, args[2]);
	GLsizei count = getInt32(env, args[3]);
	GLint * params = nullptr;
	status = getTypedArray(env, args[4], params);
	// void glProgramBufferParametersIivNV(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLint *params)
	glProgramBufferParametersIivNV(target, buffer, index, count, params);
	return NULL;
}

napi_value ProgramBufferParametersIuivNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	GLuint index = getUint32(env, args[2]);
	GLsizei count = getInt32(env, args[3]);
	GLuint * params = nullptr;
	status = getTypedArray(env, args[4], params);
	// void glProgramBufferParametersIuivNV(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLuint *params)
	glProgramBufferParametersIuivNV(target, buffer, index, count, params);
	return NULL;
}

napi_value ProgramBufferParametersfvNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLuint buffer = getUint32(env, args[1]);
	GLuint index = getUint32(env, args[2]);
	GLsizei count = getInt32(env, args[3]);
	GLfloat * params = nullptr;
	status = getTypedArray(env, args[4], params);
	// void glProgramBufferParametersfvNV(GLenum target, GLuint buffer, GLuint index, GLsizei count, const GLfloat *params)
	glProgramBufferParametersfvNV(target, buffer, index, count, params);
	return NULL;
}

napi_value CopyPathNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint resultPath = getUint32(env, args[0]);
	GLuint srcPath = getUint32(env, args[1]);
	// void glCopyPathNV(GLuint resultPath, GLuint srcPath)
	glCopyPathNV(resultPath, srcPath);
	return NULL;
}

napi_value CoverFillPathInstancedNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLsizei numPaths = getInt32(env, args[0]);
	GLenum pathNameType = getUint32(env, args[1]);
	void * paths = nullptr;
	status = getTypedArray(env, args[2], *(void **)&paths);
	if (status != napi_ok) return nullptr;
	GLuint pathBase = getUint32(env, args[3]);
	GLenum coverMode = getUint32(env, args[4]);
	GLenum transformType = getUint32(env, args[5]);
	GLfloat * transformValues = nullptr;
	status = getTypedArray(env, args[6], transformValues);
	// void glCoverFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues)
	glCoverFillPathInstancedNV(numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues);
	return NULL;
}

napi_value CoverFillPathNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint path = getUint32(env, args[0]);
	GLenum coverMode = getUint32(env, args[1]);
	// void glCoverFillPathNV(GLuint path, GLenum coverMode)
	glCoverFillPathNV(path, coverMode);
	return NULL;
}

napi_value CoverStrokePathInstancedNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLsizei numPaths = getInt32(env, args[0]);
	GLenum pathNameType = getUint32(env, args[1]);
	void * paths = nullptr;
	status = getTypedArray(env, args[2], *(void **)&paths);
	if (status != napi_ok) return nullptr;
	GLuint pathBase = getUint32(env, args[3]);
	GLenum coverMode = getUint32(env, args[4]);
	GLenum transformType = getUint32(env, args[5]);
	GLfloat * transformValues = nullptr;
	status = getTypedArray(env, args[6], transformValues);
	// void glCoverStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues)
	glCoverStrokePathInstancedNV(numPaths, pathNameType, paths, pathBase, coverMode, transformType, transformValues);
	return NULL;
}

napi_value CoverStrokePathNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint path = getUint32(env, args[0]);
	GLenum coverMode = getUint32(env, args[1]);
	// void glCoverStrokePathNV(GLuint path, GLenum coverMode)
	glCoverStrokePathNV(path, coverMode);
	return NULL;
}

napi_value DeletePathsNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint path = getUint32(env, args[0]);
	GLsizei range = getInt32(env, args[1]);
	// void glDeletePathsNV(GLuint path, GLsizei range)
	glDeletePathsNV(path, range);
	return NULL;
}

napi_value GenPathsNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLsizei range = getInt32(env, args[0]);
	// GLuint glGenPathsNV(GLsizei range)
	GLuint result = glGenPathsNV(range);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value InterpolatePathsNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint resultPath = getUint32(env, args[0]);
	GLuint pathA = getUint32(env, args[1]);
	GLuint pathB = getUint32(env, args[2]);
	GLfloat weight = getDouble(env, args[3]);
	// void glInterpolatePathsNV(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight)
	glInterpolatePathsNV(resultPath, pathA, pathB, weight);
	return NULL;
}

napi_value IsPathNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint path = getUint32(env, args[0]);
	// GLboolean glIsPathNV(GLuint path)
	GLboolean result = glIsPathNV(path);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value IsPointInFillPathNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint path = getUint32(env, args[0]);
	GLuint mask = getUint32(env, args[1]);
	GLfloat x = getDouble(env, args[2]);
	GLfloat y = getDouble(env, args[3]);
	// GLboolean glIsPointInFillPathNV(GLuint path, GLuint mask, GLfloat x, GLfloat y)
	GLboolean result = glIsPointInFillPathNV(path, mask, x, y);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value IsPointInStrokePathNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint path = getUint32(env, args[0]);
	GLfloat x = getDouble(env, args[1]);
	GLfloat y = getDouble(env, args[2]);
	// GLboolean glIsPointInStrokePathNV(GLuint path, GLfloat x, GLfloat y)
	GLboolean result = glIsPointInStrokePathNV(path, x, y);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value PathColorGenNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum color = getUint32(env, args[0]);
	GLenum genMode = getUint32(env, args[1]);
	GLenum colorFormat = getUint32(env, args[2]);
	GLfloat* coeffs;
	// void glPathColorGenNV(GLenum color, GLenum genMode, GLenum colorFormat, const GLfloat* coeffs)
	glPathColorGenNV(color, genMode, colorFormat, coeffs);
	return NULL;
}

napi_value PathCommandsNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLuint path = getUint32(env, args[0]);
	GLsizei numCommands = getInt32(env, args[1]);
	GLubyte* commands;
	GLsizei numCoords = getInt32(env, args[3]);
	GLenum coordType = getUint32(env, args[4]);
	void* coords;
	// void glPathCommandsNV(GLuint path, GLsizei numCommands, const GLubyte* commands, GLsizei numCoords, GLenum coordType, const void*coords)
	glPathCommandsNV(path, numCommands, commands, numCoords, coordType, coords);
	return NULL;
}

napi_value PathCoordsNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint path = getUint32(env, args[0]);
	GLsizei numCoords = getInt32(env, args[1]);
	GLenum coordType = getUint32(env, args[2]);
	void * coords = nullptr;
	status = getTypedArray(env, args[3], *(void **)&coords);
	if (status != napi_ok) return nullptr;
	// void glPathCoordsNV(GLuint path, GLsizei numCoords, GLenum coordType, const void *coords)
	glPathCoordsNV(path, numCoords, coordType, coords);
	return NULL;
}

napi_value PathCoverDepthFuncNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum zfunc = getUint32(env, args[0]);
	// void glPathCoverDepthFuncNV(GLenum zfunc)
	glPathCoverDepthFuncNV(zfunc);
	return NULL;
}

napi_value PathDashArrayNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint path = getUint32(env, args[0]);
	GLsizei dashCount = getInt32(env, args[1]);
	GLfloat* dashArray;
	// void glPathDashArrayNV(GLuint path, GLsizei dashCount, const GLfloat* dashArray)
	glPathDashArrayNV(path, dashCount, dashArray);
	return NULL;
}

napi_value PathFogGenNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum genMode = getUint32(env, args[0]);
	// void glPathFogGenNV(GLenum genMode)
	glPathFogGenNV(genMode);
	return NULL;
}

napi_value PathGlyphIndexArrayNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[8];
	size_t argc = checkArgCount(env, info, args, 8, 8);
	GLuint firstPathName = getUint32(env, args[0]);
	GLenum fontTarget = getUint32(env, args[1]);
	void * fontName = nullptr;
	status = getTypedArray(env, args[2], *(void **)&fontName);
	if (status != napi_ok) return nullptr;
	GLbitfield fontStyle = getUint32(env, args[3]);
	GLuint firstGlyphIndex = getUint32(env, args[4]);
	GLsizei numGlyphs = getInt32(env, args[5]);
	GLuint pathParameterTemplate = getUint32(env, args[6]);
	GLfloat emScale = getDouble(env, args[7]);
	// GLenum glPathGlyphIndexArrayNV(GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale)
	GLenum result = glPathGlyphIndexArrayNV(firstPathName, fontTarget, fontName, fontStyle, firstGlyphIndex, numGlyphs, pathParameterTemplate, emScale);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value PathGlyphRangeNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[9];
	size_t argc = checkArgCount(env, info, args, 9, 9);
	GLuint firstPathName = getUint32(env, args[0]);
	GLenum fontTarget = getUint32(env, args[1]);
	void * fontName = nullptr;
	status = getTypedArray(env, args[2], *(void **)&fontName);
	if (status != napi_ok) return nullptr;
	GLbitfield fontStyle = getUint32(env, args[3]);
	GLuint firstGlyph = getUint32(env, args[4]);
	GLsizei numGlyphs = getInt32(env, args[5]);
	GLenum handleMissingGlyphs = getUint32(env, args[6]);
	GLuint pathParameterTemplate = getUint32(env, args[7]);
	GLfloat emScale = getDouble(env, args[8]);
	// void glPathGlyphRangeNV(GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale)
	glPathGlyphRangeNV(firstPathName, fontTarget, fontName, fontStyle, firstGlyph, numGlyphs, handleMissingGlyphs, pathParameterTemplate, emScale);
	return NULL;
}

napi_value PathGlyphsNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[10];
	size_t argc = checkArgCount(env, info, args, 10, 10);
	GLuint firstPathName = getUint32(env, args[0]);
	GLenum fontTarget = getUint32(env, args[1]);
	void * fontName = nullptr;
	status = getTypedArray(env, args[2], *(void **)&fontName);
	if (status != napi_ok) return nullptr;
	GLbitfield fontStyle = getUint32(env, args[3]);
	GLsizei numGlyphs = getInt32(env, args[4]);
	GLenum type = getUint32(env, args[5]);
	void* charcodes;
	GLenum handleMissingGlyphs = getUint32(env, args[7]);
	GLuint pathParameterTemplate = getUint32(env, args[8]);
	GLfloat emScale = getDouble(env, args[9]);
	// void glPathGlyphsNV(GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void*charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale)
	glPathGlyphsNV(firstPathName, fontTarget, fontName, fontStyle, numGlyphs, type, charcodes, handleMissingGlyphs, pathParameterTemplate, emScale);
	return NULL;
}

napi_value PathMemoryGlyphIndexArrayNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[9];
	size_t argc = checkArgCount(env, info, args, 9, 9);
	GLuint firstPathName = getUint32(env, args[0]);
	GLenum fontTarget = getUint32(env, args[1]);
	GLsizeiptr fontSize = getUint32(env, args[2]);
	void * fontData = nullptr;
	status = getTypedArray(env, args[3], *(void **)&fontData);
	if (status != napi_ok) return nullptr;
	GLsizei faceIndex = getInt32(env, args[4]);
	GLuint firstGlyphIndex = getUint32(env, args[5]);
	GLsizei numGlyphs = getInt32(env, args[6]);
	GLuint pathParameterTemplate = getUint32(env, args[7]);
	GLfloat emScale = getDouble(env, args[8]);
	// GLenum glPathMemoryGlyphIndexArrayNV(GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void *fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale)
	GLenum result = glPathMemoryGlyphIndexArrayNV(firstPathName, fontTarget, fontSize, fontData, faceIndex, firstGlyphIndex, numGlyphs, pathParameterTemplate, emScale);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value PathParameterfNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint path = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat value = getDouble(env, args[2]);
	// void glPathParameterfNV(GLuint path, GLenum pname, GLfloat value)
	glPathParameterfNV(path, pname, value);
	return NULL;
}

napi_value PathParameterfvNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint path = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat* value;
	// void glPathParameterfvNV(GLuint path, GLenum pname, const GLfloat* value)
	glPathParameterfvNV(path, pname, value);
	return NULL;
}

napi_value PathParameteriNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint path = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint value = getInt32(env, args[2]);
	// void glPathParameteriNV(GLuint path, GLenum pname, GLint value)
	glPathParameteriNV(path, pname, value);
	return NULL;
}

napi_value PathParameterivNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint path = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint* value;
	// void glPathParameterivNV(GLuint path, GLenum pname, const GLint* value)
	glPathParameterivNV(path, pname, value);
	return NULL;
}

napi_value PathStencilDepthOffsetNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLfloat factor = getDouble(env, args[0]);
	GLfloat units = getDouble(env, args[1]);
	// void glPathStencilDepthOffsetNV(GLfloat factor, GLfloat units)
	glPathStencilDepthOffsetNV(factor, units);
	return NULL;
}

napi_value PathStencilFuncNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum func = getUint32(env, args[0]);
	GLint ref = getInt32(env, args[1]);
	GLuint mask = getUint32(env, args[2]);
	// void glPathStencilFuncNV(GLenum func, GLint ref, GLuint mask)
	glPathStencilFuncNV(func, ref, mask);
	return NULL;
}

napi_value PathStringNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint path = getUint32(env, args[0]);
	GLenum format = getUint32(env, args[1]);
	GLsizei length = getInt32(env, args[2]);
	void * pathString = nullptr;
	status = getTypedArray(env, args[3], *(void **)&pathString);
	if (status != napi_ok) return nullptr;
	// void glPathStringNV(GLuint path, GLenum format, GLsizei length, const void *pathString)
	glPathStringNV(path, format, length, pathString);
	return NULL;
}

napi_value PathSubCommandsNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[8];
	size_t argc = checkArgCount(env, info, args, 8, 8);
	GLuint path = getUint32(env, args[0]);
	GLsizei commandStart = getInt32(env, args[1]);
	GLsizei commandsToDelete = getInt32(env, args[2]);
	GLsizei numCommands = getInt32(env, args[3]);
	GLubyte* commands;
	GLsizei numCoords = getInt32(env, args[5]);
	GLenum coordType = getUint32(env, args[6]);
	void* coords;
	// void glPathSubCommandsNV(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte* commands, GLsizei numCoords, GLenum coordType, const void*coords)
	glPathSubCommandsNV(path, commandStart, commandsToDelete, numCommands, commands, numCoords, coordType, coords);
	return NULL;
}

napi_value PathSubCoordsNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint path = getUint32(env, args[0]);
	GLsizei coordStart = getInt32(env, args[1]);
	GLsizei numCoords = getInt32(env, args[2]);
	GLenum coordType = getUint32(env, args[3]);
	void * coords = nullptr;
	status = getTypedArray(env, args[4], *(void **)&coords);
	if (status != napi_ok) return nullptr;
	// void glPathSubCoordsNV(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void *coords)
	glPathSubCoordsNV(path, coordStart, numCoords, coordType, coords);
	return NULL;
}

napi_value PathTexGenNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum texCoordSet = getUint32(env, args[0]);
	GLenum genMode = getUint32(env, args[1]);
	GLint components = getInt32(env, args[2]);
	GLfloat* coeffs;
	// void glPathTexGenNV(GLenum texCoordSet, GLenum genMode, GLint components, const GLfloat* coeffs)
	glPathTexGenNV(texCoordSet, genMode, components, coeffs);
	return NULL;
}

napi_value PointAlongPathNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[8];
	size_t argc = checkArgCount(env, info, args, 8, 8);
	GLuint path = getUint32(env, args[0]);
	GLsizei startSegment = getInt32(env, args[1]);
	GLsizei numSegments = getInt32(env, args[2]);
	GLfloat distance = getDouble(env, args[3]);
	GLfloat* x;
	GLfloat * y = nullptr;
	status = getTypedArray(env, args[5], y);
	GLfloat * tangentX = nullptr;
	status = getTypedArray(env, args[6], tangentX);
	GLfloat * tangentY = nullptr;
	status = getTypedArray(env, args[7], tangentY);
	// GLboolean glPointAlongPathNV(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat* x, GLfloat *y, GLfloat *tangentX, GLfloat *tangentY)
	GLboolean result = glPointAlongPathNV(path, startSegment, numSegments, distance, x, y, tangentX, tangentY);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value ProgramPathFragmentInputGenNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint program = getUint32(env, args[0]);
	GLint location = getInt32(env, args[1]);
	GLenum genMode = getUint32(env, args[2]);
	GLint components = getInt32(env, args[3]);
	GLfloat* coeffs;
	// void glProgramPathFragmentInputGenNV(GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat* coeffs)
	glProgramPathFragmentInputGenNV(program, location, genMode, components, coeffs);
	return NULL;
}

napi_value StencilFillPathInstancedNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[8];
	size_t argc = checkArgCount(env, info, args, 8, 8);
	GLsizei numPaths = getInt32(env, args[0]);
	GLenum pathNameType = getUint32(env, args[1]);
	void * paths = nullptr;
	status = getTypedArray(env, args[2], *(void **)&paths);
	if (status != napi_ok) return nullptr;
	GLuint pathBase = getUint32(env, args[3]);
	GLenum fillMode = getUint32(env, args[4]);
	GLuint mask = getUint32(env, args[5]);
	GLenum transformType = getUint32(env, args[6]);
	GLfloat * transformValues = nullptr;
	status = getTypedArray(env, args[7], transformValues);
	// void glStencilFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat *transformValues)
	glStencilFillPathInstancedNV(numPaths, pathNameType, paths, pathBase, fillMode, mask, transformType, transformValues);
	return NULL;
}

napi_value StencilFillPathNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint path = getUint32(env, args[0]);
	GLenum fillMode = getUint32(env, args[1]);
	GLuint mask = getUint32(env, args[2]);
	// void glStencilFillPathNV(GLuint path, GLenum fillMode, GLuint mask)
	glStencilFillPathNV(path, fillMode, mask);
	return NULL;
}

napi_value StencilStrokePathInstancedNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[8];
	size_t argc = checkArgCount(env, info, args, 8, 8);
	GLsizei numPaths = getInt32(env, args[0]);
	GLenum pathNameType = getUint32(env, args[1]);
	void * paths = nullptr;
	status = getTypedArray(env, args[2], *(void **)&paths);
	if (status != napi_ok) return nullptr;
	GLuint pathBase = getUint32(env, args[3]);
	GLint reference = getInt32(env, args[4]);
	GLuint mask = getUint32(env, args[5]);
	GLenum transformType = getUint32(env, args[6]);
	GLfloat * transformValues = nullptr;
	status = getTypedArray(env, args[7], transformValues);
	// void glStencilStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat *transformValues)
	glStencilStrokePathInstancedNV(numPaths, pathNameType, paths, pathBase, reference, mask, transformType, transformValues);
	return NULL;
}

napi_value StencilStrokePathNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint path = getUint32(env, args[0]);
	GLint reference = getInt32(env, args[1]);
	GLuint mask = getUint32(env, args[2]);
	// void glStencilStrokePathNV(GLuint path, GLint reference, GLuint mask)
	glStencilStrokePathNV(path, reference, mask);
	return NULL;
}

napi_value StencilThenCoverFillPathInstancedNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[9];
	size_t argc = checkArgCount(env, info, args, 9, 9);
	GLsizei numPaths = getInt32(env, args[0]);
	GLenum pathNameType = getUint32(env, args[1]);
	void * paths = nullptr;
	status = getTypedArray(env, args[2], *(void **)&paths);
	if (status != napi_ok) return nullptr;
	GLuint pathBase = getUint32(env, args[3]);
	GLenum fillMode = getUint32(env, args[4]);
	GLuint mask = getUint32(env, args[5]);
	GLenum coverMode = getUint32(env, args[6]);
	GLenum transformType = getUint32(env, args[7]);
	GLfloat * transformValues = nullptr;
	status = getTypedArray(env, args[8], transformValues);
	// void glStencilThenCoverFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues)
	glStencilThenCoverFillPathInstancedNV(numPaths, pathNameType, paths, pathBase, fillMode, mask, coverMode, transformType, transformValues);
	return NULL;
}

napi_value StencilThenCoverFillPathNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint path = getUint32(env, args[0]);
	GLenum fillMode = getUint32(env, args[1]);
	GLuint mask = getUint32(env, args[2]);
	GLenum coverMode = getUint32(env, args[3]);
	// void glStencilThenCoverFillPathNV(GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode)
	glStencilThenCoverFillPathNV(path, fillMode, mask, coverMode);
	return NULL;
}

napi_value StencilThenCoverStrokePathInstancedNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[9];
	size_t argc = checkArgCount(env, info, args, 9, 9);
	GLsizei numPaths = getInt32(env, args[0]);
	GLenum pathNameType = getUint32(env, args[1]);
	void * paths = nullptr;
	status = getTypedArray(env, args[2], *(void **)&paths);
	if (status != napi_ok) return nullptr;
	GLuint pathBase = getUint32(env, args[3]);
	GLint reference = getInt32(env, args[4]);
	GLuint mask = getUint32(env, args[5]);
	GLenum coverMode = getUint32(env, args[6]);
	GLenum transformType = getUint32(env, args[7]);
	GLfloat * transformValues = nullptr;
	status = getTypedArray(env, args[8], transformValues);
	// void glStencilThenCoverStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues)
	glStencilThenCoverStrokePathInstancedNV(numPaths, pathNameType, paths, pathBase, reference, mask, coverMode, transformType, transformValues);
	return NULL;
}

napi_value StencilThenCoverStrokePathNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint path = getUint32(env, args[0]);
	GLint reference = getInt32(env, args[1]);
	GLuint mask = getUint32(env, args[2]);
	GLenum coverMode = getUint32(env, args[3]);
	// void glStencilThenCoverStrokePathNV(GLuint path, GLint reference, GLuint mask, GLenum coverMode)
	glStencilThenCoverStrokePathNV(path, reference, mask, coverMode);
	return NULL;
}

napi_value TransformPathNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint resultPath = getUint32(env, args[0]);
	GLuint srcPath = getUint32(env, args[1]);
	GLenum transformType = getUint32(env, args[2]);
	GLfloat* transformValues;
	// void glTransformPathNV(GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat* transformValues)
	glTransformPathNV(resultPath, srcPath, transformType, transformValues);
	return NULL;
}

napi_value FlushPixelDataRangeNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum target = getUint32(env, args[0]);
	// void glFlushPixelDataRangeNV(GLenum target)
	glFlushPixelDataRangeNV(target);
	return NULL;
}

napi_value PixelDataRangeNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLsizei length = getInt32(env, args[1]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[2], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glPixelDataRangeNV(GLenum target, GLsizei length, void *pointer)
	glPixelDataRangeNV(target, length, pointer);
	return NULL;
}

napi_value PointParameteriNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint param = getInt32(env, args[1]);
	// void glPointParameteriNV(GLenum pname, GLint param)
	glPointParameteriNV(pname, param);
	return NULL;
}

napi_value PointParameterivNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint* params;
	// void glPointParameterivNV(GLenum pname, const GLint* params)
	glPointParameterivNV(pname, params);
	return NULL;
}

napi_value PresentFrameDualFillNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[13];
	size_t argc = checkArgCount(env, info, args, 13, 13);
	GLuint video_slot = getUint32(env, args[0]);
	GLuint64EXT minPresentTime;
	GLuint beginPresentTimeId = getUint32(env, args[2]);
	GLuint presentDurationId = getUint32(env, args[3]);
	GLenum type = getUint32(env, args[4]);
	GLenum target0 = getUint32(env, args[5]);
	GLuint fill0 = getUint32(env, args[6]);
	GLenum target1 = getUint32(env, args[7]);
	GLuint fill1 = getUint32(env, args[8]);
	GLenum target2 = getUint32(env, args[9]);
	GLuint fill2 = getUint32(env, args[10]);
	GLenum target3 = getUint32(env, args[11]);
	GLuint fill3 = getUint32(env, args[12]);
	// void glPresentFrameDualFillNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3)
	glPresentFrameDualFillNV(video_slot, minPresentTime, beginPresentTimeId, presentDurationId, type, target0, fill0, target1, fill1, target2, fill2, target3, fill3);
	return NULL;
}

napi_value PresentFrameKeyedNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[11];
	size_t argc = checkArgCount(env, info, args, 11, 11);
	GLuint video_slot = getUint32(env, args[0]);
	GLuint64EXT minPresentTime;
	GLuint beginPresentTimeId = getUint32(env, args[2]);
	GLuint presentDurationId = getUint32(env, args[3]);
	GLenum type = getUint32(env, args[4]);
	GLenum target0 = getUint32(env, args[5]);
	GLuint fill0 = getUint32(env, args[6]);
	GLuint key0 = getUint32(env, args[7]);
	GLenum target1 = getUint32(env, args[8]);
	GLuint fill1 = getUint32(env, args[9]);
	GLuint key1 = getUint32(env, args[10]);
	// void glPresentFrameKeyedNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1)
	glPresentFrameKeyedNV(video_slot, minPresentTime, beginPresentTimeId, presentDurationId, type, target0, fill0, key0, target1, fill1, key1);
	return NULL;
}

napi_value PrimitiveRestartIndexNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint index = getUint32(env, args[0]);
	// void glPrimitiveRestartIndexNV(GLuint index)
	glPrimitiveRestartIndexNV(index);
	return NULL;
}

napi_value PrimitiveRestartNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glPrimitiveRestartNV(void)
	glPrimitiveRestartNV();
	return NULL;
}

napi_value CombinerInputNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum stage = getUint32(env, args[0]);
	GLenum portion = getUint32(env, args[1]);
	GLenum variable = getUint32(env, args[2]);
	GLenum input = getUint32(env, args[3]);
	GLenum mapping = getUint32(env, args[4]);
	GLenum componentUsage = getUint32(env, args[5]);
	// void glCombinerInputNV(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage)
	glCombinerInputNV(stage, portion, variable, input, mapping, componentUsage);
	return NULL;
}

napi_value CombinerOutputNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[10];
	size_t argc = checkArgCount(env, info, args, 10, 10);
	GLenum stage = getUint32(env, args[0]);
	GLenum portion = getUint32(env, args[1]);
	GLenum abOutput = getUint32(env, args[2]);
	GLenum cdOutput = getUint32(env, args[3]);
	GLenum sumOutput = getUint32(env, args[4]);
	GLenum scale = getUint32(env, args[5]);
	GLenum bias = getUint32(env, args[6]);
	GLboolean abDotProduct = getBool(env, args[7]);
	GLboolean cdDotProduct = getBool(env, args[8]);
	GLboolean muxSum = getBool(env, args[9]);
	// void glCombinerOutputNV(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum)
	glCombinerOutputNV(stage, portion, abOutput, cdOutput, sumOutput, scale, bias, abDotProduct, cdDotProduct, muxSum);
	return NULL;
}

napi_value CombinerParameterfNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat param = getDouble(env, args[1]);
	// void glCombinerParameterfNV(GLenum pname, GLfloat param)
	glCombinerParameterfNV(pname, param);
	return NULL;
}

napi_value CombinerParameterfvNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat* params;
	// void glCombinerParameterfvNV(GLenum pname, const GLfloat* params)
	glCombinerParameterfvNV(pname, params);
	return NULL;
}

napi_value CombinerParameteriNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint param = getInt32(env, args[1]);
	// void glCombinerParameteriNV(GLenum pname, GLint param)
	glCombinerParameteriNV(pname, param);
	return NULL;
}

napi_value CombinerParameterivNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint* params;
	// void glCombinerParameterivNV(GLenum pname, const GLint* params)
	glCombinerParameterivNV(pname, params);
	return NULL;
}

napi_value FinalCombinerInputNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum variable = getUint32(env, args[0]);
	GLenum input = getUint32(env, args[1]);
	GLenum mapping = getUint32(env, args[2]);
	GLenum componentUsage = getUint32(env, args[3]);
	// void glFinalCombinerInputNV(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage)
	glFinalCombinerInputNV(variable, input, mapping, componentUsage);
	return NULL;
}

napi_value CombinerStageParameterfvNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum stage = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat* params;
	// void glCombinerStageParameterfvNV(GLenum stage, GLenum pname, const GLfloat* params)
	glCombinerStageParameterfvNV(stage, pname, params);
	return NULL;
}

napi_value FramebufferSampleLocationsfvNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLuint start = getUint32(env, args[1]);
	GLsizei count = getInt32(env, args[2]);
	GLfloat* v;
	// void glFramebufferSampleLocationsfvNV(GLenum target, GLuint start, GLsizei count, const GLfloat* v)
	glFramebufferSampleLocationsfvNV(target, start, count, v);
	return NULL;
}

napi_value NamedFramebufferSampleLocationsfvNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint framebuffer = getUint32(env, args[0]);
	GLuint start = getUint32(env, args[1]);
	GLsizei count = getInt32(env, args[2]);
	GLfloat* v;
	// void glNamedFramebufferSampleLocationsfvNV(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat* v)
	glNamedFramebufferSampleLocationsfvNV(framebuffer, start, count, v);
	return NULL;
}

napi_value IsBufferResidentNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum target = getUint32(env, args[0]);
	// GLboolean glIsBufferResidentNV(GLenum target)
	GLboolean result = glIsBufferResidentNV(target);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value IsNamedBufferResidentNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint buffer = getUint32(env, args[0]);
	// GLboolean glIsNamedBufferResidentNV(GLuint buffer)
	GLboolean result = glIsNamedBufferResidentNV(buffer);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value MakeBufferNonResidentNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum target = getUint32(env, args[0]);
	// void glMakeBufferNonResidentNV(GLenum target)
	glMakeBufferNonResidentNV(target);
	return NULL;
}

napi_value MakeBufferResidentNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLenum access = getUint32(env, args[1]);
	// void glMakeBufferResidentNV(GLenum target, GLenum access)
	glMakeBufferResidentNV(target, access);
	return NULL;
}

napi_value MakeNamedBufferNonResidentNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint buffer = getUint32(env, args[0]);
	// void glMakeNamedBufferNonResidentNV(GLuint buffer)
	glMakeNamedBufferNonResidentNV(buffer);
	return NULL;
}

napi_value MakeNamedBufferResidentNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint buffer = getUint32(env, args[0]);
	GLenum access = getUint32(env, args[1]);
	// void glMakeNamedBufferResidentNV(GLuint buffer, GLenum access)
	glMakeNamedBufferResidentNV(buffer, access);
	return NULL;
}

napi_value TextureBarrierNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glTextureBarrierNV(void)
	glTextureBarrierNV();
	return NULL;
}

napi_value ActiveVaryingNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint program = getUint32(env, args[0]);
	GLchar * name = nullptr;
	status = getCharacterArray(env, args[1], name);
	// void glActiveVaryingNV(GLuint program, const GLchar *name)
	glActiveVaryingNV(program, name);
	return NULL;
}

napi_value BeginTransformFeedbackNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum primitiveMode = getUint32(env, args[0]);
	// void glBeginTransformFeedbackNV(GLenum primitiveMode)
	glBeginTransformFeedbackNV(primitiveMode);
	return NULL;
}

napi_value BindBufferBaseNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	// void glBindBufferBaseNV(GLenum target, GLuint index, GLuint buffer)
	glBindBufferBaseNV(target, index, buffer);
	return NULL;
}

napi_value BindBufferOffsetNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	GLintptr offset = getInt32(env, args[3]);
	// void glBindBufferOffsetNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset)
	glBindBufferOffsetNV(target, index, buffer, offset);
	return NULL;
}

napi_value BindBufferRangeNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLuint buffer = getUint32(env, args[2]);
	GLintptr offset = getInt32(env, args[3]);
	GLsizeiptr size = getUint32(env, args[4]);
	// void glBindBufferRangeNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
	glBindBufferRangeNV(target, index, buffer, offset, size);
	return NULL;
}

napi_value EndTransformFeedbackNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glEndTransformFeedbackNV(void)
	glEndTransformFeedbackNV();
	return NULL;
}

napi_value TransformFeedbackAttribsNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint count = getUint32(env, args[0]);
	GLint * attribs = nullptr;
	status = getTypedArray(env, args[1], attribs);
	GLenum bufferMode = getUint32(env, args[2]);
	// void glTransformFeedbackAttribsNV(GLuint count, const GLint *attribs, GLenum bufferMode)
	glTransformFeedbackAttribsNV(count, attribs, bufferMode);
	return NULL;
}

napi_value TransformFeedbackVaryingsNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint program = getUint32(env, args[0]);
	GLsizei count = getInt32(env, args[1]);
	GLint * locations = nullptr;
	status = getTypedArray(env, args[2], locations);
	GLenum bufferMode = getUint32(env, args[3]);
	// void glTransformFeedbackVaryingsNV(GLuint program, GLsizei count, const GLint *locations, GLenum bufferMode)
	glTransformFeedbackVaryingsNV(program, count, locations, bufferMode);
	return NULL;
}

napi_value BindTransformFeedbackNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLuint id = getUint32(env, args[1]);
	// void glBindTransformFeedbackNV(GLenum target, GLuint id)
	glBindTransformFeedbackNV(target, id);
	return NULL;
}

napi_value DeleteTransformFeedbacksNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* ids;
	// void glDeleteTransformFeedbacksNV(GLsizei n, const GLuint* ids)
	glDeleteTransformFeedbacksNV(n, ids);
	return NULL;
}

napi_value DrawTransformFeedbackNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum mode = getUint32(env, args[0]);
	GLuint id = getUint32(env, args[1]);
	// void glDrawTransformFeedbackNV(GLenum mode, GLuint id)
	glDrawTransformFeedbackNV(mode, id);
	return NULL;
}

napi_value GenTransformFeedbacksNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* ids;
	// void glGenTransformFeedbacksNV(GLsizei n, GLuint* ids)
	glGenTransformFeedbacksNV(n, ids);
	return NULL;
}

napi_value IsTransformFeedbackNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint id = getUint32(env, args[0]);
	// GLboolean glIsTransformFeedbackNV(GLuint id)
	GLboolean result = glIsTransformFeedbackNV(id);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value PauseTransformFeedbackNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glPauseTransformFeedbackNV(void)
	glPauseTransformFeedbackNV();
	return NULL;
}

napi_value ResumeTransformFeedbackNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glResumeTransformFeedbackNV(void)
	glResumeTransformFeedbackNV();
	return NULL;
}

napi_value VDPAUFiniNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glVDPAUFiniNV(void)
	glVDPAUFiniNV();
	return NULL;
}

napi_value VDPAUGetSurfaceivNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLvdpauSurfaceNV surface;
	GLenum pname = getUint32(env, args[1]);
	GLsizei bufSize = getInt32(env, args[2]);
	GLsizei* length;
	GLint * values = nullptr;
	status = getTypedArray(env, args[4], values);
	// void glVDPAUGetSurfaceivNV(GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei* length, GLint *values)
	glVDPAUGetSurfaceivNV(surface, pname, bufSize, length, values);
	return NULL;
}

napi_value VDPAUInitNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	void* vdpDevice;
	void* getProcAddress;
	// void glVDPAUInitNV(const void* vdpDevice, const void*getProcAddress)
	glVDPAUInitNV(vdpDevice, getProcAddress);
	return NULL;
}

napi_value VDPAUIsSurfaceNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLvdpauSurfaceNV surface;
	// void glVDPAUIsSurfaceNV(GLvdpauSurfaceNV surface)
	glVDPAUIsSurfaceNV(surface);
	return NULL;
}

napi_value VDPAUMapSurfacesNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei numSurfaces = getInt32(env, args[0]);
	GLvdpauSurfaceNV* surfaces;
	// void glVDPAUMapSurfacesNV(GLsizei numSurfaces, const GLvdpauSurfaceNV* surfaces)
	glVDPAUMapSurfacesNV(numSurfaces, surfaces);
	return NULL;
}

napi_value VDPAUSurfaceAccessNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLvdpauSurfaceNV surface;
	GLenum access = getUint32(env, args[1]);
	// void glVDPAUSurfaceAccessNV(GLvdpauSurfaceNV surface, GLenum access)
	glVDPAUSurfaceAccessNV(surface, access);
	return NULL;
}

napi_value VDPAUUnmapSurfacesNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei numSurface = getInt32(env, args[0]);
	GLvdpauSurfaceNV* surfaces;
	// void glVDPAUUnmapSurfacesNV(GLsizei numSurface, const GLvdpauSurfaceNV* surfaces)
	glVDPAUUnmapSurfacesNV(numSurface, surfaces);
	return NULL;
}

napi_value VDPAUUnregisterSurfaceNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLvdpauSurfaceNV surface;
	// void glVDPAUUnregisterSurfaceNV(GLvdpauSurfaceNV surface)
	glVDPAUUnregisterSurfaceNV(surface);
	return NULL;
}

napi_value FlushVertexArrayRangeNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glFlushVertexArrayRangeNV(void)
	glFlushVertexArrayRangeNV();
	return NULL;
}

napi_value VertexArrayRangeNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei length = getInt32(env, args[0]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[1], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glVertexArrayRangeNV(GLsizei length, void *pointer)
	glVertexArrayRangeNV(length, pointer);
	return NULL;
}

napi_value VertexAttribLFormatNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint index = getUint32(env, args[0]);
	GLint size = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLsizei stride = getInt32(env, args[3]);
	// void glVertexAttribLFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride)
	glVertexAttribLFormatNV(index, size, type, stride);
	return NULL;
}

napi_value BufferAddressRangeNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum pname = getUint32(env, args[0]);
	GLuint index = getUint32(env, args[1]);
	GLuint64EXT address;
	GLsizeiptr length = getUint32(env, args[3]);
	// void glBufferAddressRangeNV(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length)
	glBufferAddressRangeNV(pname, index, address, length);
	return NULL;
}

napi_value ColorFormatNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint size = getInt32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	GLsizei stride = getInt32(env, args[2]);
	// void glColorFormatNV(GLint size, GLenum type, GLsizei stride)
	glColorFormatNV(size, type, stride);
	return NULL;
}

napi_value EdgeFlagFormatNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLsizei stride = getInt32(env, args[0]);
	// void glEdgeFlagFormatNV(GLsizei stride)
	glEdgeFlagFormatNV(stride);
	return NULL;
}

napi_value FogCoordFormatNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum type = getUint32(env, args[0]);
	GLsizei stride = getInt32(env, args[1]);
	// void glFogCoordFormatNV(GLenum type, GLsizei stride)
	glFogCoordFormatNV(type, stride);
	return NULL;
}

napi_value IndexFormatNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum type = getUint32(env, args[0]);
	GLsizei stride = getInt32(env, args[1]);
	// void glIndexFormatNV(GLenum type, GLsizei stride)
	glIndexFormatNV(type, stride);
	return NULL;
}

napi_value NormalFormatNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum type = getUint32(env, args[0]);
	GLsizei stride = getInt32(env, args[1]);
	// void glNormalFormatNV(GLenum type, GLsizei stride)
	glNormalFormatNV(type, stride);
	return NULL;
}

napi_value SecondaryColorFormatNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint size = getInt32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	GLsizei stride = getInt32(env, args[2]);
	// void glSecondaryColorFormatNV(GLint size, GLenum type, GLsizei stride)
	glSecondaryColorFormatNV(size, type, stride);
	return NULL;
}

napi_value TexCoordFormatNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint size = getInt32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	GLsizei stride = getInt32(env, args[2]);
	// void glTexCoordFormatNV(GLint size, GLenum type, GLsizei stride)
	glTexCoordFormatNV(size, type, stride);
	return NULL;
}

napi_value VertexAttribFormatNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint index = getUint32(env, args[0]);
	GLint size = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLboolean normalized = getBool(env, args[3]);
	GLsizei stride = getInt32(env, args[4]);
	// void glVertexAttribFormatNV(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride)
	glVertexAttribFormatNV(index, size, type, normalized, stride);
	return NULL;
}

napi_value VertexAttribIFormatNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint index = getUint32(env, args[0]);
	GLint size = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLsizei stride = getInt32(env, args[3]);
	// void glVertexAttribIFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride)
	glVertexAttribIFormatNV(index, size, type, stride);
	return NULL;
}

napi_value VertexFormatNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLint size = getInt32(env, args[0]);
	GLenum type = getUint32(env, args[1]);
	GLsizei stride = getInt32(env, args[2]);
	// void glVertexFormatNV(GLint size, GLenum type, GLsizei stride)
	glVertexFormatNV(size, type, stride);
	return NULL;
}

napi_value AreProgramsResidentNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLsizei n = getInt32(env, args[0]);
	GLuint* ids;
	GLboolean * residences = nullptr;
	status = getTypedArray(env, args[2], residences);
	// GLboolean glAreProgramsResidentNV(GLsizei n, const GLuint* ids, GLboolean *residences)
	GLboolean result = glAreProgramsResidentNV(n, ids, residences);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value BindProgramNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum target = getUint32(env, args[0]);
	GLuint id = getUint32(env, args[1]);
	// void glBindProgramNV(GLenum target, GLuint id)
	glBindProgramNV(target, id);
	return NULL;
}

napi_value DeleteProgramsNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* ids;
	// void glDeleteProgramsNV(GLsizei n, const GLuint* ids)
	glDeleteProgramsNV(n, ids);
	return NULL;
}

napi_value ExecuteProgramNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLuint id = getUint32(env, args[1]);
	GLfloat* params;
	// void glExecuteProgramNV(GLenum target, GLuint id, const GLfloat* params)
	glExecuteProgramNV(target, id, params);
	return NULL;
}

napi_value GenProgramsNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* ids;
	// void glGenProgramsNV(GLsizei n, GLuint* ids)
	glGenProgramsNV(n, ids);
	return NULL;
}

napi_value IsProgramNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint id = getUint32(env, args[0]);
	// GLboolean glIsProgramNV(GLuint id)
	GLboolean result = glIsProgramNV(id);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value LoadProgramNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLuint id = getUint32(env, args[1]);
	GLsizei len = getInt32(env, args[2]);
	GLubyte* program;
	// void glLoadProgramNV(GLenum target, GLuint id, GLsizei len, const GLubyte* program)
	glLoadProgramNV(target, id, len, program);
	return NULL;
}

napi_value RequestResidentProgramsNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLuint* ids;
	// void glRequestResidentProgramsNV(GLsizei n, GLuint* ids)
	glRequestResidentProgramsNV(n, ids);
	return NULL;
}

napi_value TrackMatrixNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLuint address = getUint32(env, args[1]);
	GLenum matrix = getUint32(env, args[2]);
	GLenum transform = getUint32(env, args[3]);
	// void glTrackMatrixNV(GLenum target, GLuint address, GLenum matrix, GLenum transform)
	glTrackMatrixNV(target, address, matrix, transform);
	return NULL;
}

napi_value VertexAttribPointerNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint index = getUint32(env, args[0]);
	GLint size = getInt32(env, args[1]);
	GLenum type = getUint32(env, args[2]);
	GLsizei stride = getInt32(env, args[3]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[4], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glVertexAttribPointerNV(GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer)
	glVertexAttribPointerNV(index, size, type, stride, pointer);
	return NULL;
}

napi_value BeginVideoCaptureNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint video_capture_slot = getUint32(env, args[0]);
	// void glBeginVideoCaptureNV(GLuint video_capture_slot)
	glBeginVideoCaptureNV(video_capture_slot);
	return NULL;
}

napi_value BindVideoCaptureStreamBufferNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint video_capture_slot = getUint32(env, args[0]);
	GLuint stream = getUint32(env, args[1]);
	GLenum frame_region = getUint32(env, args[2]);
	GLintptrARB offset;
	// void glBindVideoCaptureStreamBufferNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset)
	glBindVideoCaptureStreamBufferNV(video_capture_slot, stream, frame_region, offset);
	return NULL;
}

napi_value BindVideoCaptureStreamTextureNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLuint video_capture_slot = getUint32(env, args[0]);
	GLuint stream = getUint32(env, args[1]);
	GLenum frame_region = getUint32(env, args[2]);
	GLenum target = getUint32(env, args[3]);
	GLuint texture = getUint32(env, args[4]);
	// void glBindVideoCaptureStreamTextureNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture)
	glBindVideoCaptureStreamTextureNV(video_capture_slot, stream, frame_region, target, texture);
	return NULL;
}

napi_value EndVideoCaptureNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint video_capture_slot = getUint32(env, args[0]);
	// void glEndVideoCaptureNV(GLuint video_capture_slot)
	glEndVideoCaptureNV(video_capture_slot);
	return NULL;
}

napi_value VideoCaptureNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLuint video_capture_slot = getUint32(env, args[0]);
	GLuint* sequence_num;
	GLuint64EXT * capture_time;
	// GLenum glVideoCaptureNV(GLuint video_capture_slot, GLuint* sequence_num, GLuint64EXT *capture_time)
	GLenum result = glVideoCaptureNV(video_capture_slot, sequence_num, capture_time);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value VideoCaptureStreamParameterdvNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint video_capture_slot = getUint32(env, args[0]);
	GLuint stream = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLdouble* params;
	// void glVideoCaptureStreamParameterdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble* params)
	glVideoCaptureStreamParameterdvNV(video_capture_slot, stream, pname, params);
	return NULL;
}

napi_value VideoCaptureStreamParameterfvNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint video_capture_slot = getUint32(env, args[0]);
	GLuint stream = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLfloat* params;
	// void glVideoCaptureStreamParameterfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat* params)
	glVideoCaptureStreamParameterfvNV(video_capture_slot, stream, pname, params);
	return NULL;
}

napi_value VideoCaptureStreamParameterivNV(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLuint video_capture_slot = getUint32(env, args[0]);
	GLuint stream = getUint32(env, args[1]);
	GLenum pname = getUint32(env, args[2]);
	GLint* params;
	// void glVideoCaptureStreamParameterivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint* params)
	glVideoCaptureStreamParameterivNV(video_capture_slot, stream, pname, params);
	return NULL;
}

napi_value FramebufferTextureMultiviewOVR(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum target = getUint32(env, args[0]);
	GLenum attachment = getUint32(env, args[1]);
	GLuint texture = getUint32(env, args[2]);
	GLint level = getInt32(env, args[3]);
	GLint baseViewIndex = getInt32(env, args[4]);
	GLsizei numViews = getInt32(env, args[5]);
	// void glFramebufferTextureMultiviewOVR(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews)
	glFramebufferTextureMultiviewOVR(target, attachment, texture, level, baseViewIndex, numViews);
	return NULL;
}

napi_value AlphaFuncx(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum func = getUint32(env, args[0]);
	GLclampx ref;
	// void glAlphaFuncx(GLenum func, GLclampx ref)
	glAlphaFuncx(func, ref);
	return NULL;
}

napi_value ClearColorx(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLclampx red;
	GLclampx green;
	GLclampx blue;
	GLclampx alpha;
	// void glClearColorx(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha)
	glClearColorx(red, green, blue, alpha);
	return NULL;
}

napi_value ClearDepthx(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLclampx depth;
	// void glClearDepthx(GLclampx depth)
	glClearDepthx(depth);
	return NULL;
}

napi_value DepthRangex(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLclampx zNear;
	GLclampx zFar;
	// void glDepthRangex(GLclampx zNear, GLclampx zFar)
	glDepthRangex(zNear, zFar);
	return NULL;
}

napi_value Fogx(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfixed param;
	// void glFogx(GLenum pname, GLfixed param)
	glFogx(pname, param);
	return NULL;
}

napi_value Fogxv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfixed* params;
	// void glFogxv(GLenum pname, const GLfixed* params)
	glFogxv(pname, params);
	return NULL;
}

napi_value Frustumf(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLfloat left = getDouble(env, args[0]);
	GLfloat right = getDouble(env, args[1]);
	GLfloat bottom = getDouble(env, args[2]);
	GLfloat top = getDouble(env, args[3]);
	GLfloat zNear = getDouble(env, args[4]);
	GLfloat zFar = getDouble(env, args[5]);
	// void glFrustumf(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar)
	glFrustumf(left, right, bottom, top, zNear, zFar);
	return NULL;
}

napi_value Frustumx(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLfixed left;
	GLfixed right;
	GLfixed bottom;
	GLfixed top;
	GLfixed zNear;
	GLfixed zFar;
	// void glFrustumx(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar)
	glFrustumx(left, right, bottom, top, zNear, zFar);
	return NULL;
}

napi_value LightModelx(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfixed param;
	// void glLightModelx(GLenum pname, GLfixed param)
	glLightModelx(pname, param);
	return NULL;
}

napi_value LightModelxv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfixed* params;
	// void glLightModelxv(GLenum pname, const GLfixed* params)
	glLightModelxv(pname, params);
	return NULL;
}

napi_value Lightx(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum light = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfixed param;
	// void glLightx(GLenum light, GLenum pname, GLfixed param)
	glLightx(light, pname, param);
	return NULL;
}

napi_value Lightxv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum light = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfixed* params;
	// void glLightxv(GLenum light, GLenum pname, const GLfixed* params)
	glLightxv(light, pname, params);
	return NULL;
}

napi_value LineWidthx(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLfixed width;
	// void glLineWidthx(GLfixed width)
	glLineWidthx(width);
	return NULL;
}

napi_value LoadMatrixx(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLfixed* m;
	// void glLoadMatrixx(const GLfixed* m)
	glLoadMatrixx(m);
	return NULL;
}

napi_value Materialx(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum face = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfixed param;
	// void glMaterialx(GLenum face, GLenum pname, GLfixed param)
	glMaterialx(face, pname, param);
	return NULL;
}

napi_value Materialxv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum face = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfixed* params;
	// void glMaterialxv(GLenum face, GLenum pname, const GLfixed* params)
	glMaterialxv(face, pname, params);
	return NULL;
}

napi_value MultMatrixx(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLfixed* m;
	// void glMultMatrixx(const GLfixed* m)
	glMultMatrixx(m);
	return NULL;
}

napi_value Orthof(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLfloat left = getDouble(env, args[0]);
	GLfloat right = getDouble(env, args[1]);
	GLfloat bottom = getDouble(env, args[2]);
	GLfloat top = getDouble(env, args[3]);
	GLfloat zNear = getDouble(env, args[4]);
	GLfloat zFar = getDouble(env, args[5]);
	// void glOrthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar)
	glOrthof(left, right, bottom, top, zNear, zFar);
	return NULL;
}

napi_value Orthox(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLfixed left;
	GLfixed right;
	GLfixed bottom;
	GLfixed top;
	GLfixed zNear;
	GLfixed zFar;
	// void glOrthox(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar)
	glOrthox(left, right, bottom, top, zNear, zFar);
	return NULL;
}

napi_value PointSizex(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLfixed size;
	// void glPointSizex(GLfixed size)
	glPointSizex(size);
	return NULL;
}

napi_value PolygonOffsetx(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLfixed factor;
	GLfixed units;
	// void glPolygonOffsetx(GLfixed factor, GLfixed units)
	glPolygonOffsetx(factor, units);
	return NULL;
}

napi_value Rotatex(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLfixed angle;
	GLfixed x;
	GLfixed y;
	GLfixed z;
	// void glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z)
	glRotatex(angle, x, y, z);
	return NULL;
}

napi_value SampleCoveragex(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLclampx value;
	GLboolean invert = getBool(env, args[1]);
	// void glSampleCoveragex(GLclampx value, GLboolean invert)
	glSampleCoveragex(value, invert);
	return NULL;
}

napi_value Scalex(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLfixed x;
	GLfixed y;
	GLfixed z;
	// void glScalex(GLfixed x, GLfixed y, GLfixed z)
	glScalex(x, y, z);
	return NULL;
}

napi_value TexEnvx(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfixed param;
	// void glTexEnvx(GLenum target, GLenum pname, GLfixed param)
	glTexEnvx(target, pname, param);
	return NULL;
}

napi_value TexEnvxv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfixed* params;
	// void glTexEnvxv(GLenum target, GLenum pname, const GLfixed* params)
	glTexEnvxv(target, pname, params);
	return NULL;
}

napi_value TexParameterx(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfixed param;
	// void glTexParameterx(GLenum target, GLenum pname, GLfixed param)
	glTexParameterx(target, pname, param);
	return NULL;
}

napi_value Translatex(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLfixed x;
	GLfixed y;
	GLfixed z;
	// void glTranslatex(GLfixed x, GLfixed y, GLfixed z)
	glTranslatex(x, y, z);
	return NULL;
}

napi_value ClipPlanef(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum plane = getUint32(env, args[0]);
	GLfloat* equation;
	// void glClipPlanef(GLenum plane, const GLfloat* equation)
	glClipPlanef(plane, equation);
	return NULL;
}

napi_value ClipPlanex(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum plane = getUint32(env, args[0]);
	GLfixed* equation;
	// void glClipPlanex(GLenum plane, const GLfixed* equation)
	glClipPlanex(plane, equation);
	return NULL;
}

napi_value PointParameterx(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfixed param;
	// void glPointParameterx(GLenum pname, GLfixed param)
	glPointParameterx(pname, param);
	return NULL;
}

napi_value PointParameterxv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfixed* params;
	// void glPointParameterxv(GLenum pname, const GLfixed* params)
	glPointParameterxv(pname, params);
	return NULL;
}

napi_value TexParameterxv(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfixed* params;
	// void glTexParameterxv(GLenum target, GLenum pname, const GLfixed* params)
	glTexParameterxv(target, pname, params);
	return NULL;
}

napi_value IsSupportedREGAL(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLchar* ext;
	// GLboolean glIsSupportedREGAL(const GLchar* ext)
	GLboolean result = glIsSupportedREGAL(ext);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value LogMessageCallbackREGAL(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLLOGPROCREGAL callback;
	// void glLogMessageCallbackREGAL(GLLOGPROCREGAL callback)
	glLogMessageCallbackREGAL(callback);
	return NULL;
}

napi_value DetailTexFuncSGIS(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLsizei n = getInt32(env, args[1]);
	GLfloat* points;
	// void glDetailTexFuncSGIS(GLenum target, GLsizei n, const GLfloat* points)
	glDetailTexFuncSGIS(target, n, points);
	return NULL;
}

napi_value FogFuncSGIS(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLsizei n = getInt32(env, args[0]);
	GLfloat* points;
	// void glFogFuncSGIS(GLsizei n, const GLfloat* points)
	glFogFuncSGIS(n, points);
	return NULL;
}

napi_value SampleMaskSGIS(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLclampf value;
	GLboolean invert = getBool(env, args[1]);
	// void glSampleMaskSGIS(GLclampf value, GLboolean invert)
	glSampleMaskSGIS(value, invert);
	return NULL;
}

napi_value SamplePatternSGIS(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum pattern = getUint32(env, args[0]);
	// void glSamplePatternSGIS(GLenum pattern)
	glSamplePatternSGIS(pattern);
	return NULL;
}

napi_value SharpenTexFuncSGIS(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLsizei n = getInt32(env, args[1]);
	GLfloat* points;
	// void glSharpenTexFuncSGIS(GLenum target, GLsizei n, const GLfloat* points)
	glSharpenTexFuncSGIS(target, n, points);
	return NULL;
}

napi_value TexFilterFuncSGIS(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLenum target = getUint32(env, args[0]);
	GLenum filter = getUint32(env, args[1]);
	GLsizei n = getInt32(env, args[2]);
	GLfloat* weights;
	// void glTexFilterFuncSGIS(GLenum target, GLenum filter, GLsizei n, const GLfloat* weights)
	glTexFilterFuncSGIS(target, filter, n, weights);
	return NULL;
}

napi_value AsyncMarkerSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint marker = getUint32(env, args[0]);
	// void glAsyncMarkerSGIX(GLuint marker)
	glAsyncMarkerSGIX(marker);
	return NULL;
}

napi_value DeleteAsyncMarkersSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLuint marker = getUint32(env, args[0]);
	GLsizei range = getInt32(env, args[1]);
	// void glDeleteAsyncMarkersSGIX(GLuint marker, GLsizei range)
	glDeleteAsyncMarkersSGIX(marker, range);
	return NULL;
}

napi_value FinishAsyncSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint* markerp;
	// GLint glFinishAsyncSGIX(GLuint* markerp)
	GLint result = glFinishAsyncSGIX(markerp);
	napi_value result_value = nullptr;
	status = napi_create_int32(env, (int32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value GenAsyncMarkersSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLsizei range = getInt32(env, args[0]);
	// GLuint glGenAsyncMarkersSGIX(GLsizei range)
	GLuint result = glGenAsyncMarkersSGIX(range);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value IsAsyncMarkerSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint marker = getUint32(env, args[0]);
	// GLboolean glIsAsyncMarkerSGIX(GLuint marker)
	GLboolean result = glIsAsyncMarkerSGIX(marker);
	napi_value result_value = nullptr;
	status = napi_create_uint32(env, (uint32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value PollAsyncSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint* markerp;
	// GLint glPollAsyncSGIX(GLuint* markerp)
	GLint result = glPollAsyncSGIX(markerp);
	napi_value result_value = nullptr;
	status = napi_create_int32(env, (int32_t)result, &result_value);
	return (status == napi_ok) ? result_value : nullptr;
}

napi_value FlushRasterSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glFlushRasterSGIX(void)
	glFlushRasterSGIX();
	return NULL;
}

napi_value TextureFogSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum pname = getUint32(env, args[0]);
	// void glTextureFogSGIX(GLenum pname)
	glTextureFogSGIX(pname);
	return NULL;
}

napi_value FragmentColorMaterialSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum face = getUint32(env, args[0]);
	GLenum mode = getUint32(env, args[1]);
	// void glFragmentColorMaterialSGIX(GLenum face, GLenum mode)
	glFragmentColorMaterialSGIX(face, mode);
	return NULL;
}

napi_value FragmentLightModelfSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat param = getDouble(env, args[1]);
	// void glFragmentLightModelfSGIX(GLenum pname, GLfloat param)
	glFragmentLightModelfSGIX(pname, param);
	return NULL;
}

napi_value FragmentLightModelfvSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat* params;
	// void glFragmentLightModelfvSGIX(GLenum pname, GLfloat* params)
	glFragmentLightModelfvSGIX(pname, params);
	return NULL;
}

napi_value FragmentLightModeliSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint param = getInt32(env, args[1]);
	// void glFragmentLightModeliSGIX(GLenum pname, GLint param)
	glFragmentLightModeliSGIX(pname, param);
	return NULL;
}

napi_value FragmentLightModelivSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint* params;
	// void glFragmentLightModelivSGIX(GLenum pname, GLint* params)
	glFragmentLightModelivSGIX(pname, params);
	return NULL;
}

napi_value FragmentLightfSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum light = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat param = getDouble(env, args[2]);
	// void glFragmentLightfSGIX(GLenum light, GLenum pname, GLfloat param)
	glFragmentLightfSGIX(light, pname, param);
	return NULL;
}

napi_value FragmentLightfvSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum light = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat* params;
	// void glFragmentLightfvSGIX(GLenum light, GLenum pname, GLfloat* params)
	glFragmentLightfvSGIX(light, pname, params);
	return NULL;
}

napi_value FragmentLightiSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum light = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint param = getInt32(env, args[2]);
	// void glFragmentLightiSGIX(GLenum light, GLenum pname, GLint param)
	glFragmentLightiSGIX(light, pname, param);
	return NULL;
}

napi_value FragmentLightivSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum light = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint* params;
	// void glFragmentLightivSGIX(GLenum light, GLenum pname, GLint* params)
	glFragmentLightivSGIX(light, pname, params);
	return NULL;
}

napi_value FragmentMaterialfSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum face = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat param = getDouble(env, args[2]);
	// void glFragmentMaterialfSGIX(GLenum face, GLenum pname, const GLfloat param)
	glFragmentMaterialfSGIX(face, pname, param);
	return NULL;
}

napi_value FragmentMaterialfvSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum face = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat* params;
	// void glFragmentMaterialfvSGIX(GLenum face, GLenum pname, const GLfloat* params)
	glFragmentMaterialfvSGIX(face, pname, params);
	return NULL;
}

napi_value FragmentMaterialiSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum face = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint param = getInt32(env, args[2]);
	// void glFragmentMaterialiSGIX(GLenum face, GLenum pname, const GLint param)
	glFragmentMaterialiSGIX(face, pname, param);
	return NULL;
}

napi_value FragmentMaterialivSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum face = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint* params;
	// void glFragmentMaterialivSGIX(GLenum face, GLenum pname, const GLint* params)
	glFragmentMaterialivSGIX(face, pname, params);
	return NULL;
}

napi_value FrameZoomSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLint factor = getInt32(env, args[0]);
	// void glFrameZoomSGIX(GLint factor)
	glFrameZoomSGIX(factor);
	return NULL;
}

napi_value PixelTexGenSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLenum mode = getUint32(env, args[0]);
	// void glPixelTexGenSGIX(GLenum mode)
	glPixelTexGenSGIX(mode);
	return NULL;
}

napi_value ReferencePlaneSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLdouble* equation;
	// void glReferencePlaneSGIX(const GLdouble* equation)
	glReferencePlaneSGIX(equation);
	return NULL;
}

napi_value SpriteParameterfSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat param = getDouble(env, args[1]);
	// void glSpriteParameterfSGIX(GLenum pname, GLfloat param)
	glSpriteParameterfSGIX(pname, param);
	return NULL;
}

napi_value SpriteParameterfvSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLfloat* params;
	// void glSpriteParameterfvSGIX(GLenum pname, GLfloat* params)
	glSpriteParameterfvSGIX(pname, params);
	return NULL;
}

napi_value SpriteParameteriSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint param = getInt32(env, args[1]);
	// void glSpriteParameteriSGIX(GLenum pname, GLint param)
	glSpriteParameteriSGIX(pname, param);
	return NULL;
}

napi_value SpriteParameterivSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[2];
	size_t argc = checkArgCount(env, info, args, 2, 2);
	GLenum pname = getUint32(env, args[0]);
	GLint* params;
	// void glSpriteParameterivSGIX(GLenum pname, GLint* params)
	glSpriteParameterivSGIX(pname, params);
	return NULL;
}

napi_value TagSampleBufferSGIX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glTagSampleBufferSGIX(void)
	glTagSampleBufferSGIX();
	return NULL;
}

napi_value ColorTableParameterfvSGI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLfloat* params;
	// void glColorTableParameterfvSGI(GLenum target, GLenum pname, const GLfloat* params)
	glColorTableParameterfvSGI(target, pname, params);
	return NULL;
}

napi_value ColorTableParameterivSGI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum target = getUint32(env, args[0]);
	GLenum pname = getUint32(env, args[1]);
	GLint* params;
	// void glColorTableParameterivSGI(GLenum target, GLenum pname, const GLint* params)
	glColorTableParameterivSGI(target, pname, params);
	return NULL;
}

napi_value ColorTableSGI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[6];
	size_t argc = checkArgCount(env, info, args, 6, 6);
	GLenum target = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLsizei width = getInt32(env, args[2]);
	GLenum format = getUint32(env, args[3]);
	GLenum type = getUint32(env, args[4]);
	void * table = nullptr;
	status = getTypedArray(env, args[5], *(void **)&table);
	if (status != napi_ok) return nullptr;
	// void glColorTableSGI(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table)
	glColorTableSGI(target, internalformat, width, format, type, table);
	return NULL;
}

napi_value CopyColorTableSGI(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[5];
	size_t argc = checkArgCount(env, info, args, 5, 5);
	GLenum target = getUint32(env, args[0]);
	GLenum internalformat = getUint32(env, args[1]);
	GLint x = getInt32(env, args[2]);
	GLint y = getInt32(env, args[3]);
	GLsizei width = getInt32(env, args[4]);
	// void glCopyColorTableSGI(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width)
	glCopyColorTableSGI(target, internalformat, x, y, width);
	return NULL;
}

napi_value FinishTextureSUNX(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	// void glFinishTextureSUNX(void)
	glFinishTextureSUNX();
	return NULL;
}

napi_value GlobalAlphaFactorbSUN(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLbyte factor;
	// void glGlobalAlphaFactorbSUN(GLbyte factor)
	glGlobalAlphaFactorbSUN(factor);
	return NULL;
}

napi_value GlobalAlphaFactordSUN(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLdouble factor;
	// void glGlobalAlphaFactordSUN(GLdouble factor)
	glGlobalAlphaFactordSUN(factor);
	return NULL;
}

napi_value GlobalAlphaFactorfSUN(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLfloat factor = getDouble(env, args[0]);
	// void glGlobalAlphaFactorfSUN(GLfloat factor)
	glGlobalAlphaFactorfSUN(factor);
	return NULL;
}

napi_value GlobalAlphaFactoriSUN(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLint factor = getInt32(env, args[0]);
	// void glGlobalAlphaFactoriSUN(GLint factor)
	glGlobalAlphaFactoriSUN(factor);
	return NULL;
}

napi_value GlobalAlphaFactorsSUN(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLshort factor;
	// void glGlobalAlphaFactorsSUN(GLshort factor)
	glGlobalAlphaFactorsSUN(factor);
	return NULL;
}

napi_value GlobalAlphaFactorubSUN(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLubyte factor;
	// void glGlobalAlphaFactorubSUN(GLubyte factor)
	glGlobalAlphaFactorubSUN(factor);
	return NULL;
}

napi_value GlobalAlphaFactoruiSUN(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint factor = getUint32(env, args[0]);
	// void glGlobalAlphaFactoruiSUN(GLuint factor)
	glGlobalAlphaFactoruiSUN(factor);
	return NULL;
}

napi_value GlobalAlphaFactorusSUN(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLushort factor;
	// void glGlobalAlphaFactorusSUN(GLushort factor)
	glGlobalAlphaFactorusSUN(factor);
	return NULL;
}

napi_value ReadVideoPixelsSUN(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[7];
	size_t argc = checkArgCount(env, info, args, 7, 7);
	GLint x = getInt32(env, args[0]);
	GLint y = getInt32(env, args[1]);
	GLsizei width = getInt32(env, args[2]);
	GLsizei height = getInt32(env, args[3]);
	GLenum format = getUint32(env, args[4]);
	GLenum type = getUint32(env, args[5]);
	void* pixels;
	// void glReadVideoPixelsSUN(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels)
	glReadVideoPixelsSUN(x, y, width, height, format, type, pixels);
	return NULL;
}

napi_value ReplacementCodePointerSUN(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[3];
	size_t argc = checkArgCount(env, info, args, 3, 3);
	GLenum type = getUint32(env, args[0]);
	GLsizei stride = getInt32(env, args[1]);
	void * pointer = nullptr;
	status = getTypedArray(env, args[2], *(void **)&pointer);
	if (status != napi_ok) return nullptr;
	// void glReplacementCodePointerSUN(GLenum type, GLsizei stride, const void *pointer)
	glReplacementCodePointerSUN(type, stride, pointer);
	return NULL;
}

napi_value ReplacementCodeubSUN(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLubyte code;
	// void glReplacementCodeubSUN(GLubyte code)
	glReplacementCodeubSUN(code);
	return NULL;
}

napi_value ReplacementCodeubvSUN(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLubyte* code;
	// void glReplacementCodeubvSUN(const GLubyte* code)
	glReplacementCodeubvSUN(code);
	return NULL;
}

napi_value ReplacementCodeuiSUN(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint code = getUint32(env, args[0]);
	// void glReplacementCodeuiSUN(GLuint code)
	glReplacementCodeuiSUN(code);
	return NULL;
}

napi_value ReplacementCodeuivSUN(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLuint* code;
	// void glReplacementCodeuivSUN(const GLuint* code)
	glReplacementCodeuivSUN(code);
	return NULL;
}

napi_value ReplacementCodeusSUN(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLushort code;
	// void glReplacementCodeusSUN(GLushort code)
	glReplacementCodeusSUN(code);
	return NULL;
}

napi_value ReplacementCodeusvSUN(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[1];
	size_t argc = checkArgCount(env, info, args, 1, 1);
	GLushort* code;
	// void glReplacementCodeusvSUN(const GLushort* code)
	glReplacementCodeusvSUN(code);
	return NULL;
}

napi_value AddSwapHintRectWIN(napi_env env, napi_callback_info info) {
	napi_status status = napi_ok;
	napi_value args[4];
	size_t argc = checkArgCount(env, info, args, 4, 4);
	GLint x = getInt32(env, args[0]);
	GLint y = getInt32(env, args[1]);
	GLsizei width = getInt32(env, args[2]);
	GLsizei height = getInt32(env, args[3]);
	// void glAddSwapHintRectWIN(GLint x, GLint y, GLsizei width, GLsizei height)
	glAddSwapHintRectWIN(x, y, width, height);
	return NULL;
}

napi_value init(napi_env env, napi_value exports) {
	napi_status status;
	napi_property_descriptor properties[] = {
		{ "glewInit", 0, glewInit, 0, 0, 0, napi_default, 0 },
		{ "getError", 0, GetError, 0, 0, 0, napi_default, 0 },
		{ "getErrorString", 0, GetErrorString, 0, 0, 0, napi_default, 0 },
		{ "clearBufferfv", 0, ClearBufferfv, 0, 0, 0, napi_default, 0 },
		{ "bufferData", 0, BufferData, 0, 0, 0, napi_default, 0 },
		{ "getBufferData", 0, GetBufferData, 0, 0, 0, napi_default, 0 },
		{ "getBufferSubData", 0, GetBufferSubData, 0, 0, 0, napi_default, 0 },
		{ "createBuffer", 0, CreateBuffer, 0, 0, 0, napi_default, 0 },
		{ "deleteBuffers", 0, DeleteBuffers, 0, 0, 0, napi_default, 0 },
		{ "createFramebuffer", 0, CreateFramebuffer, 0, 0, 0, napi_default, 0 },
		{ "deleteFramebuffers", 0, DeleteFramebuffers, 0, 0, 0, napi_default, 0 },
		{ "createProgram", 0, CreateProgram, 0, 0, 0, napi_default, 0 },
		{ "createRenderbuffer", 0, CreateRenderbuffer, 0, 0, 0, napi_default, 0 },
		{ "createTexture", 0, CreateTexture, 0, 0, 0, napi_default, 0 },
		{ "deleteTextures", 0, DeleteTextures, 0, 0, 0, napi_default, 0 },
		{ "createVertexArray", 0, CreateVertexArray, 0, 0, 0, napi_default, 0 },
		{ "deleteVertexArrays", 0, DeleteVertexArrays, 0, 0, 0, napi_default, 0 },
		{ "drawBuffers", 0, DrawBuffers, 0, 0, 0, napi_default, 0 },
		{ "texStorage2DMultisample", 0, TexStorage2DMultisample, 0, 0, 0, napi_default, 0 },
		{ "getAttribLocation", 0, GetAttribLocation, 0, 0, 0, napi_default, 0 },
		{ "getIntegerv", 0, GetIntegerv, 0, 0, 0, napi_default, 0 },
		{ "getInteger64v", 0, GetInteger64v, 0, 0, 0, napi_default, 0 },
		{ "getIntegeri_v", 0, GetIntegeri_v, 0, 0, 0, napi_default, 0 },
		{ "getInteger64i_v", 0, GetInteger64i_v, 0, 0, 0, napi_default, 0 },
		{ "getBufferParameteri64v", 0, GetBufferParameteri64v, 0, 0, 0, napi_default, 0 },
		{ "getTexImage", 0, GetTexImage, 0, 0, 0, napi_default, 0 },
		{ "getTextureSubImage", 0, GetTextureSubImage, 0, 0, 0, napi_default, 0 },
		{ "getProgramInfoLog", 0, GetProgramInfoLog, 0, 0, 0, napi_default, 0 },
		{ "getProgramParameter", 0, GetProgramParameter, 0, 0, 0, napi_default, 0 },
		{ "getShaderInfoLog", 0, GetShaderInfoLog, 0, 0, 0, napi_default, 0 },
		{ "getShaderParameter", 0, GetShaderParameter, 0, 0, 0, napi_default, 0 },
		{ "getUniformLocation", 0, GetUniformLocation, 0, 0, 0, napi_default, 0 },
		{ "shaderSource", 0, ShaderSource, 0, 0, 0, napi_default, 0 },
		{ "uniformMatrix2fv", 0, UniformMatrix2fv, 0, 0, 0, napi_default, 0 },
		{ "uniformMatrix3fv", 0, UniformMatrix3fv, 0, 0, 0, napi_default, 0 },
		{ "uniformMatrix4fv", 0, UniformMatrix4fv, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribPointer", 0, VertexAttribPointer, 0, 0, 0, napi_default, 0 },
		{ "activeTexture", 0, ActiveTexture, 0, 0, 0, napi_default, 0 },
		{ "attachShader", 0, AttachShader, 0, 0, 0, napi_default, 0 },
		{ "bindAttribLocation", 0, BindAttribLocation, 0, 0, 0, napi_default, 0 },
		{ "bindBuffer", 0, BindBuffer, 0, 0, 0, napi_default, 0 },
		{ "bindFramebuffer", 0, BindFramebuffer, 0, 0, 0, napi_default, 0 },
		{ "bindRenderbuffer", 0, BindRenderbuffer, 0, 0, 0, napi_default, 0 },
		{ "bindTexture", 0, BindTexture, 0, 0, 0, napi_default, 0 },
		{ "blendColor", 0, BlendColor, 0, 0, 0, napi_default, 0 },
		{ "blendEquation", 0, BlendEquation, 0, 0, 0, napi_default, 0 },
		{ "blendEquationSeparate", 0, BlendEquationSeparate, 0, 0, 0, napi_default, 0 },
		{ "blendFunc", 0, BlendFunc, 0, 0, 0, napi_default, 0 },
		{ "blendFuncSeparate", 0, BlendFuncSeparate, 0, 0, 0, napi_default, 0 },
		{ "bufferSubData", 0, BufferSubData, 0, 0, 0, napi_default, 0 },
		{ "checkFramebufferStatus", 0, CheckFramebufferStatus, 0, 0, 0, napi_default, 0 },
		{ "clear", 0, Clear, 0, 0, 0, napi_default, 0 },
		{ "clearColor", 0, ClearColor, 0, 0, 0, napi_default, 0 },
		{ "clearDepthf", 0, ClearDepthf, 0, 0, 0, napi_default, 0 },
		{ "clearStencil", 0, ClearStencil, 0, 0, 0, napi_default, 0 },
		{ "colorMask", 0, ColorMask, 0, 0, 0, napi_default, 0 },
		{ "compileShader", 0, CompileShader, 0, 0, 0, napi_default, 0 },
		{ "compressedTexImage2D", 0, CompressedTexImage2D, 0, 0, 0, napi_default, 0 },
		{ "compressedTexSubImage2D", 0, CompressedTexSubImage2D, 0, 0, 0, napi_default, 0 },
		{ "copyTexImage2D", 0, CopyTexImage2D, 0, 0, 0, napi_default, 0 },
		{ "copyTexSubImage2D", 0, CopyTexSubImage2D, 0, 0, 0, napi_default, 0 },
		{ "createShader", 0, CreateShader, 0, 0, 0, napi_default, 0 },
		{ "cullFace", 0, CullFace, 0, 0, 0, napi_default, 0 },
		{ "deleteProgram", 0, DeleteProgram, 0, 0, 0, napi_default, 0 },
		{ "deleteRenderbuffers", 0, DeleteRenderbuffers, 0, 0, 0, napi_default, 0 },
		{ "deleteShader", 0, DeleteShader, 0, 0, 0, napi_default, 0 },
		{ "depthFunc", 0, DepthFunc, 0, 0, 0, napi_default, 0 },
		{ "depthMask", 0, DepthMask, 0, 0, 0, napi_default, 0 },
		{ "depthRangef", 0, DepthRangef, 0, 0, 0, napi_default, 0 },
		{ "detachShader", 0, DetachShader, 0, 0, 0, napi_default, 0 },
		{ "disable", 0, Disable, 0, 0, 0, napi_default, 0 },
		{ "disableVertexAttribArray", 0, DisableVertexAttribArray, 0, 0, 0, napi_default, 0 },
		{ "drawArrays", 0, DrawArrays, 0, 0, 0, napi_default, 0 },
		{ "drawElements", 0, DrawElements, 0, 0, 0, napi_default, 0 },
		{ "enable", 0, Enable, 0, 0, 0, napi_default, 0 },
		{ "enableVertexAttribArray", 0, EnableVertexAttribArray, 0, 0, 0, napi_default, 0 },
		{ "finish", 0, Finish, 0, 0, 0, napi_default, 0 },
		{ "flush", 0, Flush, 0, 0, 0, napi_default, 0 },
		{ "framebufferRenderbuffer", 0, FramebufferRenderbuffer, 0, 0, 0, napi_default, 0 },
		{ "framebufferTexture2D", 0, FramebufferTexture2D, 0, 0, 0, napi_default, 0 },
		{ "frontFace", 0, FrontFace, 0, 0, 0, napi_default, 0 },
		{ "genBuffers", 0, GenBuffers, 0, 0, 0, napi_default, 0 },
		{ "generateMipmap", 0, GenerateMipmap, 0, 0, 0, napi_default, 0 },
		{ "genFramebuffers", 0, GenFramebuffers, 0, 0, 0, napi_default, 0 },
		{ "genRenderbuffers", 0, GenRenderbuffers, 0, 0, 0, napi_default, 0 },
		{ "genTextures", 0, GenTextures, 0, 0, 0, napi_default, 0 },
		{ "getActiveAttrib", 0, GetActiveAttrib, 0, 0, 0, napi_default, 0 },
		{ "getActiveUniform", 0, GetActiveUniform, 0, 0, 0, napi_default, 0 },
		{ "getAttachedShaders", 0, GetAttachedShaders, 0, 0, 0, napi_default, 0 },
		{ "getBooleanv", 0, GetBooleanv, 0, 0, 0, napi_default, 0 },
		{ "getBufferParameteriv", 0, GetBufferParameteriv, 0, 0, 0, napi_default, 0 },
		{ "getFloatv", 0, GetFloatv, 0, 0, 0, napi_default, 0 },
		{ "getFramebufferAttachmentParameteriv", 0, GetFramebufferAttachmentParameteriv, 0, 0, 0, napi_default, 0 },
		{ "getProgramiv", 0, GetProgramiv, 0, 0, 0, napi_default, 0 },
		{ "getRenderbufferParameteriv", 0, GetRenderbufferParameteriv, 0, 0, 0, napi_default, 0 },
		{ "getShaderiv", 0, GetShaderiv, 0, 0, 0, napi_default, 0 },
		{ "getShaderPrecisionFormat", 0, GetShaderPrecisionFormat, 0, 0, 0, napi_default, 0 },
		{ "getShaderSource", 0, GetShaderSource, 0, 0, 0, napi_default, 0 },
		{ "getTexParameterfv", 0, GetTexParameterfv, 0, 0, 0, napi_default, 0 },
		{ "getTexParameteriv", 0, GetTexParameteriv, 0, 0, 0, napi_default, 0 },
		{ "getUniformfv", 0, GetUniformfv, 0, 0, 0, napi_default, 0 },
		{ "getUniformiv", 0, GetUniformiv, 0, 0, 0, napi_default, 0 },
		{ "getVertexAttribfv", 0, GetVertexAttribfv, 0, 0, 0, napi_default, 0 },
		{ "getVertexAttribiv", 0, GetVertexAttribiv, 0, 0, 0, napi_default, 0 },
		{ "getVertexAttribPointerv", 0, GetVertexAttribPointerv, 0, 0, 0, napi_default, 0 },
		{ "hint", 0, Hint, 0, 0, 0, napi_default, 0 },
		{ "isBuffer", 0, IsBuffer, 0, 0, 0, napi_default, 0 },
		{ "isEnabled", 0, IsEnabled, 0, 0, 0, napi_default, 0 },
		{ "isFramebuffer", 0, IsFramebuffer, 0, 0, 0, napi_default, 0 },
		{ "isProgram", 0, IsProgram, 0, 0, 0, napi_default, 0 },
		{ "isRenderbuffer", 0, IsRenderbuffer, 0, 0, 0, napi_default, 0 },
		{ "isShader", 0, IsShader, 0, 0, 0, napi_default, 0 },
		{ "isTexture", 0, IsTexture, 0, 0, 0, napi_default, 0 },
		{ "lineWidth", 0, LineWidth, 0, 0, 0, napi_default, 0 },
		{ "linkProgram", 0, LinkProgram, 0, 0, 0, napi_default, 0 },
		{ "pixelStorei", 0, PixelStorei, 0, 0, 0, napi_default, 0 },
		{ "polygonOffset", 0, PolygonOffset, 0, 0, 0, napi_default, 0 },
		{ "readPixels", 0, ReadPixels, 0, 0, 0, napi_default, 0 },
		{ "releaseShaderCompiler", 0, ReleaseShaderCompiler, 0, 0, 0, napi_default, 0 },
		{ "renderbufferStorage", 0, RenderbufferStorage, 0, 0, 0, napi_default, 0 },
		{ "sampleCoverage", 0, SampleCoverage, 0, 0, 0, napi_default, 0 },
		{ "scissor", 0, Scissor, 0, 0, 0, napi_default, 0 },
		{ "shaderBinary", 0, ShaderBinary, 0, 0, 0, napi_default, 0 },
		{ "stencilFunc", 0, StencilFunc, 0, 0, 0, napi_default, 0 },
		{ "stencilFuncSeparate", 0, StencilFuncSeparate, 0, 0, 0, napi_default, 0 },
		{ "stencilMask", 0, StencilMask, 0, 0, 0, napi_default, 0 },
		{ "stencilMaskSeparate", 0, StencilMaskSeparate, 0, 0, 0, napi_default, 0 },
		{ "stencilOp", 0, StencilOp, 0, 0, 0, napi_default, 0 },
		{ "stencilOpSeparate", 0, StencilOpSeparate, 0, 0, 0, napi_default, 0 },
		{ "texImage2D", 0, TexImage2D, 0, 0, 0, napi_default, 0 },
		{ "texParameterf", 0, TexParameterf, 0, 0, 0, napi_default, 0 },
		{ "texParameterfv", 0, TexParameterfv, 0, 0, 0, napi_default, 0 },
		{ "texParameteri", 0, TexParameteri, 0, 0, 0, napi_default, 0 },
		{ "texParameteriv", 0, TexParameteriv, 0, 0, 0, napi_default, 0 },
		{ "texSubImage2D", 0, TexSubImage2D, 0, 0, 0, napi_default, 0 },
		{ "uniform1f", 0, Uniform1f, 0, 0, 0, napi_default, 0 },
		{ "uniform1fv", 0, Uniform1fv, 0, 0, 0, napi_default, 0 },
		{ "uniform1i", 0, Uniform1i, 0, 0, 0, napi_default, 0 },
		{ "uniform1iv", 0, Uniform1iv, 0, 0, 0, napi_default, 0 },
		{ "uniform2f", 0, Uniform2f, 0, 0, 0, napi_default, 0 },
		{ "uniform2fv", 0, Uniform2fv, 0, 0, 0, napi_default, 0 },
		{ "uniform2i", 0, Uniform2i, 0, 0, 0, napi_default, 0 },
		{ "uniform2iv", 0, Uniform2iv, 0, 0, 0, napi_default, 0 },
		{ "uniform3f", 0, Uniform3f, 0, 0, 0, napi_default, 0 },
		{ "uniform3fv", 0, Uniform3fv, 0, 0, 0, napi_default, 0 },
		{ "uniform3i", 0, Uniform3i, 0, 0, 0, napi_default, 0 },
		{ "uniform3iv", 0, Uniform3iv, 0, 0, 0, napi_default, 0 },
		{ "uniform4f", 0, Uniform4f, 0, 0, 0, napi_default, 0 },
		{ "uniform4fv", 0, Uniform4fv, 0, 0, 0, napi_default, 0 },
		{ "uniform4i", 0, Uniform4i, 0, 0, 0, napi_default, 0 },
		{ "uniform4iv", 0, Uniform4iv, 0, 0, 0, napi_default, 0 },
		{ "useProgram", 0, UseProgram, 0, 0, 0, napi_default, 0 },
		{ "validateProgram", 0, ValidateProgram, 0, 0, 0, napi_default, 0 },
		{ "vertexAttrib1f", 0, VertexAttrib1f, 0, 0, 0, napi_default, 0 },
		{ "vertexAttrib1fv", 0, VertexAttrib1fv, 0, 0, 0, napi_default, 0 },
		{ "vertexAttrib2f", 0, VertexAttrib2f, 0, 0, 0, napi_default, 0 },
		{ "vertexAttrib2fv", 0, VertexAttrib2fv, 0, 0, 0, napi_default, 0 },
		{ "vertexAttrib3f", 0, VertexAttrib3f, 0, 0, 0, napi_default, 0 },
		{ "vertexAttrib3fv", 0, VertexAttrib3fv, 0, 0, 0, napi_default, 0 },
		{ "vertexAttrib4f", 0, VertexAttrib4f, 0, 0, 0, napi_default, 0 },
		{ "vertexAttrib4fv", 0, VertexAttrib4fv, 0, 0, 0, napi_default, 0 },
		{ "viewport", 0, Viewport, 0, 0, 0, napi_default, 0 },
		{ "readBuffer", 0, ReadBuffer, 0, 0, 0, napi_default, 0 },
		{ "drawRangeElements", 0, DrawRangeElements, 0, 0, 0, napi_default, 0 },
		{ "texImage3D", 0, TexImage3D, 0, 0, 0, napi_default, 0 },
		{ "texSubImage3D", 0, TexSubImage3D, 0, 0, 0, napi_default, 0 },
		{ "copyTexSubImage3D", 0, CopyTexSubImage3D, 0, 0, 0, napi_default, 0 },
		{ "compressedTexImage3D", 0, CompressedTexImage3D, 0, 0, 0, napi_default, 0 },
		{ "compressedTexSubImage3D", 0, CompressedTexSubImage3D, 0, 0, 0, napi_default, 0 },
		{ "genQueries", 0, GenQueries, 0, 0, 0, napi_default, 0 },
		{ "deleteQueries", 0, DeleteQueries, 0, 0, 0, napi_default, 0 },
		{ "isQuery", 0, IsQuery, 0, 0, 0, napi_default, 0 },
		{ "beginQuery", 0, BeginQuery, 0, 0, 0, napi_default, 0 },
		{ "endQuery", 0, EndQuery, 0, 0, 0, napi_default, 0 },
		{ "getQueryiv", 0, GetQueryiv, 0, 0, 0, napi_default, 0 },
		{ "getQueryObjectuiv", 0, GetQueryObjectuiv, 0, 0, 0, napi_default, 0 },
		{ "unmapBuffer", 0, UnmapBuffer, 0, 0, 0, napi_default, 0 },
		{ "getBufferPointerv", 0, GetBufferPointerv, 0, 0, 0, napi_default, 0 },
		{ "uniformMatrix2x3fv", 0, UniformMatrix2x3fv, 0, 0, 0, napi_default, 0 },
		{ "uniformMatrix3x2fv", 0, UniformMatrix3x2fv, 0, 0, 0, napi_default, 0 },
		{ "uniformMatrix2x4fv", 0, UniformMatrix2x4fv, 0, 0, 0, napi_default, 0 },
		{ "uniformMatrix4x2fv", 0, UniformMatrix4x2fv, 0, 0, 0, napi_default, 0 },
		{ "uniformMatrix3x4fv", 0, UniformMatrix3x4fv, 0, 0, 0, napi_default, 0 },
		{ "uniformMatrix4x3fv", 0, UniformMatrix4x3fv, 0, 0, 0, napi_default, 0 },
		{ "blitFramebuffer", 0, BlitFramebuffer, 0, 0, 0, napi_default, 0 },
		{ "renderbufferStorageMultisample", 0, RenderbufferStorageMultisample, 0, 0, 0, napi_default, 0 },
		{ "framebufferTextureLayer", 0, FramebufferTextureLayer, 0, 0, 0, napi_default, 0 },
		{ "flushMappedBufferRange", 0, FlushMappedBufferRange, 0, 0, 0, napi_default, 0 },
		{ "bindVertexArray", 0, BindVertexArray, 0, 0, 0, napi_default, 0 },
		{ "genVertexArrays", 0, GenVertexArrays, 0, 0, 0, napi_default, 0 },
		{ "isVertexArray", 0, IsVertexArray, 0, 0, 0, napi_default, 0 },
		{ "beginTransformFeedback", 0, BeginTransformFeedback, 0, 0, 0, napi_default, 0 },
		{ "endTransformFeedback", 0, EndTransformFeedback, 0, 0, 0, napi_default, 0 },
		{ "bindBufferRange", 0, BindBufferRange, 0, 0, 0, napi_default, 0 },
		{ "bindBufferBase", 0, BindBufferBase, 0, 0, 0, napi_default, 0 },
		{ "transformFeedbackVaryings", 0, TransformFeedbackVaryings, 0, 0, 0, napi_default, 0 },
		{ "getTransformFeedbackVarying", 0, GetTransformFeedbackVarying, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribIPointer", 0, VertexAttribIPointer, 0, 0, 0, napi_default, 0 },
		{ "getVertexAttribIiv", 0, GetVertexAttribIiv, 0, 0, 0, napi_default, 0 },
		{ "getVertexAttribIuiv", 0, GetVertexAttribIuiv, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribI4i", 0, VertexAttribI4i, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribI4ui", 0, VertexAttribI4ui, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribI4iv", 0, VertexAttribI4iv, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribI4uiv", 0, VertexAttribI4uiv, 0, 0, 0, napi_default, 0 },
		{ "getUniformuiv", 0, GetUniformuiv, 0, 0, 0, napi_default, 0 },
		{ "getFragDataLocation", 0, GetFragDataLocation, 0, 0, 0, napi_default, 0 },
		{ "uniform1ui", 0, Uniform1ui, 0, 0, 0, napi_default, 0 },
		{ "uniform2ui", 0, Uniform2ui, 0, 0, 0, napi_default, 0 },
		{ "uniform3ui", 0, Uniform3ui, 0, 0, 0, napi_default, 0 },
		{ "uniform4ui", 0, Uniform4ui, 0, 0, 0, napi_default, 0 },
		{ "uniform1uiv", 0, Uniform1uiv, 0, 0, 0, napi_default, 0 },
		{ "uniform2uiv", 0, Uniform2uiv, 0, 0, 0, napi_default, 0 },
		{ "uniform3uiv", 0, Uniform3uiv, 0, 0, 0, napi_default, 0 },
		{ "uniform4uiv", 0, Uniform4uiv, 0, 0, 0, napi_default, 0 },
		{ "clearBufferiv", 0, ClearBufferiv, 0, 0, 0, napi_default, 0 },
		{ "clearBufferuiv", 0, ClearBufferuiv, 0, 0, 0, napi_default, 0 },
		{ "clearBufferfi", 0, ClearBufferfi, 0, 0, 0, napi_default, 0 },
		{ "copyBufferSubData", 0, CopyBufferSubData, 0, 0, 0, napi_default, 0 },
		{ "getUniformIndices", 0, GetUniformIndices, 0, 0, 0, napi_default, 0 },
		{ "getActiveUniformsiv", 0, GetActiveUniformsiv, 0, 0, 0, napi_default, 0 },
		{ "getUniformBlockIndex", 0, GetUniformBlockIndex, 0, 0, 0, napi_default, 0 },
		{ "getActiveUniformBlockiv", 0, GetActiveUniformBlockiv, 0, 0, 0, napi_default, 0 },
		{ "getActiveUniformBlockName", 0, GetActiveUniformBlockName, 0, 0, 0, napi_default, 0 },
		{ "uniformBlockBinding", 0, UniformBlockBinding, 0, 0, 0, napi_default, 0 },
		{ "drawArraysInstanced", 0, DrawArraysInstanced, 0, 0, 0, napi_default, 0 },
		{ "drawElementsInstanced", 0, DrawElementsInstanced, 0, 0, 0, napi_default, 0 },
		{ "fenceSync", 0, FenceSync, 0, 0, 0, napi_default, 0 },
		{ "isSync", 0, IsSync, 0, 0, 0, napi_default, 0 },
		{ "deleteSync", 0, DeleteSync, 0, 0, 0, napi_default, 0 },
		{ "clientWaitSync", 0, ClientWaitSync, 0, 0, 0, napi_default, 0 },
		{ "waitSync", 0, WaitSync, 0, 0, 0, napi_default, 0 },
		{ "getSynciv", 0, GetSynciv, 0, 0, 0, napi_default, 0 },
		{ "genSamplers", 0, GenSamplers, 0, 0, 0, napi_default, 0 },
		{ "deleteSamplers", 0, DeleteSamplers, 0, 0, 0, napi_default, 0 },
		{ "isSampler", 0, IsSampler, 0, 0, 0, napi_default, 0 },
		{ "bindSampler", 0, BindSampler, 0, 0, 0, napi_default, 0 },
		{ "samplerParameteri", 0, SamplerParameteri, 0, 0, 0, napi_default, 0 },
		{ "samplerParameteriv", 0, SamplerParameteriv, 0, 0, 0, napi_default, 0 },
		{ "samplerParameterf", 0, SamplerParameterf, 0, 0, 0, napi_default, 0 },
		{ "samplerParameterfv", 0, SamplerParameterfv, 0, 0, 0, napi_default, 0 },
		{ "getSamplerParameteriv", 0, GetSamplerParameteriv, 0, 0, 0, napi_default, 0 },
		{ "getSamplerParameterfv", 0, GetSamplerParameterfv, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribDivisor", 0, VertexAttribDivisor, 0, 0, 0, napi_default, 0 },
		{ "bindTransformFeedback", 0, BindTransformFeedback, 0, 0, 0, napi_default, 0 },
		{ "deleteTransformFeedbacks", 0, DeleteTransformFeedbacks, 0, 0, 0, napi_default, 0 },
		{ "genTransformFeedbacks", 0, GenTransformFeedbacks, 0, 0, 0, napi_default, 0 },
		{ "isTransformFeedback", 0, IsTransformFeedback, 0, 0, 0, napi_default, 0 },
		{ "pauseTransformFeedback", 0, PauseTransformFeedback, 0, 0, 0, napi_default, 0 },
		{ "resumeTransformFeedback", 0, ResumeTransformFeedback, 0, 0, 0, napi_default, 0 },
		{ "getProgramBinary", 0, GetProgramBinary, 0, 0, 0, napi_default, 0 },
		{ "programBinary", 0, ProgramBinary, 0, 0, 0, napi_default, 0 },
		{ "programParameteri", 0, ProgramParameteri, 0, 0, 0, napi_default, 0 },
		{ "invalidateFramebuffer", 0, InvalidateFramebuffer, 0, 0, 0, napi_default, 0 },
		{ "invalidateSubFramebuffer", 0, InvalidateSubFramebuffer, 0, 0, 0, napi_default, 0 },
		{ "texStorage2D", 0, TexStorage2D, 0, 0, 0, napi_default, 0 },
		{ "texStorage3D", 0, TexStorage3D, 0, 0, 0, napi_default, 0 },
		{ "getInternalformativ", 0, GetInternalformativ, 0, 0, 0, napi_default, 0 },
		{ "clientActiveTexture", 0, ClientActiveTexture, 0, 0, 0, napi_default, 0 },
		{ "fogCoordPointer", 0, FogCoordPointer, 0, 0, 0, napi_default, 0 },
		{ "fogCoordd", 0, FogCoordd, 0, 0, 0, napi_default, 0 },
		{ "fogCoorddv", 0, FogCoorddv, 0, 0, 0, napi_default, 0 },
		{ "fogCoordf", 0, FogCoordf, 0, 0, 0, napi_default, 0 },
		{ "fogCoordfv", 0, FogCoordfv, 0, 0, 0, napi_default, 0 },
		{ "multiDrawArrays", 0, MultiDrawArrays, 0, 0, 0, napi_default, 0 },
		{ "multiDrawElements", 0, MultiDrawElements, 0, 0, 0, napi_default, 0 },
		{ "pointParameterf", 0, PointParameterf, 0, 0, 0, napi_default, 0 },
		{ "pointParameterfv", 0, PointParameterfv, 0, 0, 0, napi_default, 0 },
		{ "pointParameteri", 0, PointParameteri, 0, 0, 0, napi_default, 0 },
		{ "pointParameteriv", 0, PointParameteriv, 0, 0, 0, napi_default, 0 },
		{ "secondaryColorPointer", 0, SecondaryColorPointer, 0, 0, 0, napi_default, 0 },
		{ "beginConditionalRender", 0, BeginConditionalRender, 0, 0, 0, napi_default, 0 },
		{ "bindFragDataLocation", 0, BindFragDataLocation, 0, 0, 0, napi_default, 0 },
		{ "clampColor", 0, ClampColor, 0, 0, 0, napi_default, 0 },
		{ "colorMaski", 0, ColorMaski, 0, 0, 0, napi_default, 0 },
		{ "disablei", 0, Disablei, 0, 0, 0, napi_default, 0 },
		{ "enablei", 0, Enablei, 0, 0, 0, napi_default, 0 },
		{ "endConditionalRender", 0, EndConditionalRender, 0, 0, 0, napi_default, 0 },
		{ "isEnabledi", 0, IsEnabledi, 0, 0, 0, napi_default, 0 },
		{ "texParameterIiv", 0, TexParameterIiv, 0, 0, 0, napi_default, 0 },
		{ "texParameterIuiv", 0, TexParameterIuiv, 0, 0, 0, napi_default, 0 },
		{ "primitiveRestartIndex", 0, PrimitiveRestartIndex, 0, 0, 0, napi_default, 0 },
		{ "texBuffer", 0, TexBuffer, 0, 0, 0, napi_default, 0 },
		{ "framebufferTexture", 0, FramebufferTexture, 0, 0, 0, napi_default, 0 },
		{ "blendEquationSeparatei", 0, BlendEquationSeparatei, 0, 0, 0, napi_default, 0 },
		{ "blendEquationi", 0, BlendEquationi, 0, 0, 0, napi_default, 0 },
		{ "blendFuncSeparatei", 0, BlendFuncSeparatei, 0, 0, 0, napi_default, 0 },
		{ "blendFunci", 0, BlendFunci, 0, 0, 0, napi_default, 0 },
		{ "minSampleShading", 0, MinSampleShading, 0, 0, 0, napi_default, 0 },
		{ "debugMessageCallbackAMD", 0, DebugMessageCallbackAMD, 0, 0, 0, napi_default, 0 },
		{ "debugMessageEnableAMD", 0, DebugMessageEnableAMD, 0, 0, 0, napi_default, 0 },
		{ "debugMessageInsertAMD", 0, DebugMessageInsertAMD, 0, 0, 0, napi_default, 0 },
		{ "blendEquationIndexedAMD", 0, BlendEquationIndexedAMD, 0, 0, 0, napi_default, 0 },
		{ "blendEquationSeparateIndexedAMD", 0, BlendEquationSeparateIndexedAMD, 0, 0, 0, napi_default, 0 },
		{ "blendFuncIndexedAMD", 0, BlendFuncIndexedAMD, 0, 0, 0, napi_default, 0 },
		{ "blendFuncSeparateIndexedAMD", 0, BlendFuncSeparateIndexedAMD, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribParameteriAMD", 0, VertexAttribParameteriAMD, 0, 0, 0, napi_default, 0 },
		{ "multiDrawArraysIndirectAMD", 0, MultiDrawArraysIndirectAMD, 0, 0, 0, napi_default, 0 },
		{ "multiDrawElementsIndirectAMD", 0, MultiDrawElementsIndirectAMD, 0, 0, 0, napi_default, 0 },
		{ "deleteNamesAMD", 0, DeleteNamesAMD, 0, 0, 0, napi_default, 0 },
		{ "genNamesAMD", 0, GenNamesAMD, 0, 0, 0, napi_default, 0 },
		{ "isNameAMD", 0, IsNameAMD, 0, 0, 0, napi_default, 0 },
		{ "queryObjectParameteruiAMD", 0, QueryObjectParameteruiAMD, 0, 0, 0, napi_default, 0 },
		{ "beginPerfMonitorAMD", 0, BeginPerfMonitorAMD, 0, 0, 0, napi_default, 0 },
		{ "deletePerfMonitorsAMD", 0, DeletePerfMonitorsAMD, 0, 0, 0, napi_default, 0 },
		{ "endPerfMonitorAMD", 0, EndPerfMonitorAMD, 0, 0, 0, napi_default, 0 },
		{ "genPerfMonitorsAMD", 0, GenPerfMonitorsAMD, 0, 0, 0, napi_default, 0 },
		{ "selectPerfMonitorCountersAMD", 0, SelectPerfMonitorCountersAMD, 0, 0, 0, napi_default, 0 },
		{ "setMultisamplefvAMD", 0, SetMultisamplefvAMD, 0, 0, 0, napi_default, 0 },
		{ "texStorageSparseAMD", 0, TexStorageSparseAMD, 0, 0, 0, napi_default, 0 },
		{ "textureStorageSparseAMD", 0, TextureStorageSparseAMD, 0, 0, 0, napi_default, 0 },
		{ "stencilOpValueAMD", 0, StencilOpValueAMD, 0, 0, 0, napi_default, 0 },
		{ "tessellationFactorAMD", 0, TessellationFactorAMD, 0, 0, 0, napi_default, 0 },
		{ "tessellationModeAMD", 0, TessellationModeAMD, 0, 0, 0, napi_default, 0 },
		{ "blitFramebufferANGLE", 0, BlitFramebufferANGLE, 0, 0, 0, napi_default, 0 },
		{ "renderbufferStorageMultisampleANGLE", 0, RenderbufferStorageMultisampleANGLE, 0, 0, 0, napi_default, 0 },
		{ "drawArraysInstancedANGLE", 0, DrawArraysInstancedANGLE, 0, 0, 0, napi_default, 0 },
		{ "drawElementsInstancedANGLE", 0, DrawElementsInstancedANGLE, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribDivisorANGLE", 0, VertexAttribDivisorANGLE, 0, 0, 0, napi_default, 0 },
		{ "beginQueryANGLE", 0, BeginQueryANGLE, 0, 0, 0, napi_default, 0 },
		{ "deleteQueriesANGLE", 0, DeleteQueriesANGLE, 0, 0, 0, napi_default, 0 },
		{ "endQueryANGLE", 0, EndQueryANGLE, 0, 0, 0, napi_default, 0 },
		{ "genQueriesANGLE", 0, GenQueriesANGLE, 0, 0, 0, napi_default, 0 },
		{ "isQueryANGLE", 0, IsQueryANGLE, 0, 0, 0, napi_default, 0 },
		{ "queryCounterANGLE", 0, QueryCounterANGLE, 0, 0, 0, napi_default, 0 },
		{ "drawElementArrayAPPLE", 0, DrawElementArrayAPPLE, 0, 0, 0, napi_default, 0 },
		{ "drawRangeElementArrayAPPLE", 0, DrawRangeElementArrayAPPLE, 0, 0, 0, napi_default, 0 },
		{ "elementPointerAPPLE", 0, ElementPointerAPPLE, 0, 0, 0, napi_default, 0 },
		{ "multiDrawElementArrayAPPLE", 0, MultiDrawElementArrayAPPLE, 0, 0, 0, napi_default, 0 },
		{ "multiDrawRangeElementArrayAPPLE", 0, MultiDrawRangeElementArrayAPPLE, 0, 0, 0, napi_default, 0 },
		{ "deleteFencesAPPLE", 0, DeleteFencesAPPLE, 0, 0, 0, napi_default, 0 },
		{ "finishFenceAPPLE", 0, FinishFenceAPPLE, 0, 0, 0, napi_default, 0 },
		{ "finishObjectAPPLE", 0, FinishObjectAPPLE, 0, 0, 0, napi_default, 0 },
		{ "genFencesAPPLE", 0, GenFencesAPPLE, 0, 0, 0, napi_default, 0 },
		{ "isFenceAPPLE", 0, IsFenceAPPLE, 0, 0, 0, napi_default, 0 },
		{ "setFenceAPPLE", 0, SetFenceAPPLE, 0, 0, 0, napi_default, 0 },
		{ "testFenceAPPLE", 0, TestFenceAPPLE, 0, 0, 0, napi_default, 0 },
		{ "testObjectAPPLE", 0, TestObjectAPPLE, 0, 0, 0, napi_default, 0 },
		{ "bufferParameteriAPPLE", 0, BufferParameteriAPPLE, 0, 0, 0, napi_default, 0 },
		{ "flushMappedBufferRangeAPPLE", 0, FlushMappedBufferRangeAPPLE, 0, 0, 0, napi_default, 0 },
		{ "objectPurgeableAPPLE", 0, ObjectPurgeableAPPLE, 0, 0, 0, napi_default, 0 },
		{ "objectUnpurgeableAPPLE", 0, ObjectUnpurgeableAPPLE, 0, 0, 0, napi_default, 0 },
		{ "textureRangeAPPLE", 0, TextureRangeAPPLE, 0, 0, 0, napi_default, 0 },
		{ "bindVertexArrayAPPLE", 0, BindVertexArrayAPPLE, 0, 0, 0, napi_default, 0 },
		{ "deleteVertexArraysAPPLE", 0, DeleteVertexArraysAPPLE, 0, 0, 0, napi_default, 0 },
		{ "genVertexArraysAPPLE", 0, GenVertexArraysAPPLE, 0, 0, 0, napi_default, 0 },
		{ "isVertexArrayAPPLE", 0, IsVertexArrayAPPLE, 0, 0, 0, napi_default, 0 },
		{ "flushVertexArrayRangeAPPLE", 0, FlushVertexArrayRangeAPPLE, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayParameteriAPPLE", 0, VertexArrayParameteriAPPLE, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayRangeAPPLE", 0, VertexArrayRangeAPPLE, 0, 0, 0, napi_default, 0 },
		{ "disableVertexAttribAPPLE", 0, DisableVertexAttribAPPLE, 0, 0, 0, napi_default, 0 },
		{ "enableVertexAttribAPPLE", 0, EnableVertexAttribAPPLE, 0, 0, 0, napi_default, 0 },
		{ "isVertexAttribEnabledAPPLE", 0, IsVertexAttribEnabledAPPLE, 0, 0, 0, napi_default, 0 },
		{ "memoryBarrierByRegion", 0, MemoryBarrierByRegion, 0, 0, 0, napi_default, 0 },
		{ "drawArraysInstancedBaseInstance", 0, DrawArraysInstancedBaseInstance, 0, 0, 0, napi_default, 0 },
		{ "drawElementsInstancedBaseInstance", 0, DrawElementsInstancedBaseInstance, 0, 0, 0, napi_default, 0 },
		{ "drawElementsInstancedBaseVertexBaseInstance", 0, DrawElementsInstancedBaseVertexBaseInstance, 0, 0, 0, napi_default, 0 },
		{ "bindFragDataLocationIndexed", 0, BindFragDataLocationIndexed, 0, 0, 0, napi_default, 0 },
		{ "bufferStorage", 0, BufferStorage, 0, 0, 0, napi_default, 0 },
		{ "namedBufferStorageEXT", 0, NamedBufferStorageEXT, 0, 0, 0, napi_default, 0 },
		{ "clearBufferData", 0, ClearBufferData, 0, 0, 0, napi_default, 0 },
		{ "clearBufferSubData", 0, ClearBufferSubData, 0, 0, 0, napi_default, 0 },
		{ "clearNamedBufferDataEXT", 0, ClearNamedBufferDataEXT, 0, 0, 0, napi_default, 0 },
		{ "clearNamedBufferSubDataEXT", 0, ClearNamedBufferSubDataEXT, 0, 0, 0, napi_default, 0 },
		{ "clearTexImage", 0, ClearTexImage, 0, 0, 0, napi_default, 0 },
		{ "clearTexSubImage", 0, ClearTexSubImage, 0, 0, 0, napi_default, 0 },
		{ "clipControl", 0, ClipControl, 0, 0, 0, napi_default, 0 },
		{ "dispatchCompute", 0, DispatchCompute, 0, 0, 0, napi_default, 0 },
		{ "dispatchComputeIndirect", 0, DispatchComputeIndirect, 0, 0, 0, napi_default, 0 },
		{ "copyImageSubData", 0, CopyImageSubData, 0, 0, 0, napi_default, 0 },
		{ "bindTextureUnit", 0, BindTextureUnit, 0, 0, 0, napi_default, 0 },
		{ "blitNamedFramebuffer", 0, BlitNamedFramebuffer, 0, 0, 0, napi_default, 0 },
		{ "checkNamedFramebufferStatus", 0, CheckNamedFramebufferStatus, 0, 0, 0, napi_default, 0 },
		{ "clearNamedBufferData", 0, ClearNamedBufferData, 0, 0, 0, napi_default, 0 },
		{ "clearNamedBufferSubData", 0, ClearNamedBufferSubData, 0, 0, 0, napi_default, 0 },
		{ "clearNamedFramebufferfi", 0, ClearNamedFramebufferfi, 0, 0, 0, napi_default, 0 },
		{ "clearNamedFramebufferfv", 0, ClearNamedFramebufferfv, 0, 0, 0, napi_default, 0 },
		{ "clearNamedFramebufferiv", 0, ClearNamedFramebufferiv, 0, 0, 0, napi_default, 0 },
		{ "clearNamedFramebufferuiv", 0, ClearNamedFramebufferuiv, 0, 0, 0, napi_default, 0 },
		{ "copyNamedBufferSubData", 0, CopyNamedBufferSubData, 0, 0, 0, napi_default, 0 },
		{ "createBuffers", 0, CreateBuffers, 0, 0, 0, napi_default, 0 },
		{ "createFramebuffers", 0, CreateFramebuffers, 0, 0, 0, napi_default, 0 },
		{ "createProgramPipelines", 0, CreateProgramPipelines, 0, 0, 0, napi_default, 0 },
		{ "createQueries", 0, CreateQueries, 0, 0, 0, napi_default, 0 },
		{ "createRenderbuffers", 0, CreateRenderbuffers, 0, 0, 0, napi_default, 0 },
		{ "createSamplers", 0, CreateSamplers, 0, 0, 0, napi_default, 0 },
		{ "createTextures", 0, CreateTextures, 0, 0, 0, napi_default, 0 },
		{ "createTransformFeedbacks", 0, CreateTransformFeedbacks, 0, 0, 0, napi_default, 0 },
		{ "createVertexArrays", 0, CreateVertexArrays, 0, 0, 0, napi_default, 0 },
		{ "disableVertexArrayAttrib", 0, DisableVertexArrayAttrib, 0, 0, 0, napi_default, 0 },
		{ "enableVertexArrayAttrib", 0, EnableVertexArrayAttrib, 0, 0, 0, napi_default, 0 },
		{ "flushMappedNamedBufferRange", 0, FlushMappedNamedBufferRange, 0, 0, 0, napi_default, 0 },
		{ "generateTextureMipmap", 0, GenerateTextureMipmap, 0, 0, 0, napi_default, 0 },
		{ "invalidateNamedFramebufferData", 0, InvalidateNamedFramebufferData, 0, 0, 0, napi_default, 0 },
		{ "invalidateNamedFramebufferSubData", 0, InvalidateNamedFramebufferSubData, 0, 0, 0, napi_default, 0 },
		{ "namedBufferData", 0, NamedBufferData, 0, 0, 0, napi_default, 0 },
		{ "namedBufferStorage", 0, NamedBufferStorage, 0, 0, 0, napi_default, 0 },
		{ "namedBufferSubData", 0, NamedBufferSubData, 0, 0, 0, napi_default, 0 },
		{ "namedFramebufferDrawBuffer", 0, NamedFramebufferDrawBuffer, 0, 0, 0, napi_default, 0 },
		{ "namedFramebufferDrawBuffers", 0, NamedFramebufferDrawBuffers, 0, 0, 0, napi_default, 0 },
		{ "namedFramebufferParameteri", 0, NamedFramebufferParameteri, 0, 0, 0, napi_default, 0 },
		{ "namedFramebufferReadBuffer", 0, NamedFramebufferReadBuffer, 0, 0, 0, napi_default, 0 },
		{ "namedFramebufferRenderbuffer", 0, NamedFramebufferRenderbuffer, 0, 0, 0, napi_default, 0 },
		{ "namedFramebufferTexture", 0, NamedFramebufferTexture, 0, 0, 0, napi_default, 0 },
		{ "namedFramebufferTextureLayer", 0, NamedFramebufferTextureLayer, 0, 0, 0, napi_default, 0 },
		{ "namedRenderbufferStorage", 0, NamedRenderbufferStorage, 0, 0, 0, napi_default, 0 },
		{ "namedRenderbufferStorageMultisample", 0, NamedRenderbufferStorageMultisample, 0, 0, 0, napi_default, 0 },
		{ "textureBuffer", 0, TextureBuffer, 0, 0, 0, napi_default, 0 },
		{ "textureBufferRange", 0, TextureBufferRange, 0, 0, 0, napi_default, 0 },
		{ "textureParameterIiv", 0, TextureParameterIiv, 0, 0, 0, napi_default, 0 },
		{ "textureParameterIuiv", 0, TextureParameterIuiv, 0, 0, 0, napi_default, 0 },
		{ "textureParameterf", 0, TextureParameterf, 0, 0, 0, napi_default, 0 },
		{ "textureParameterfv", 0, TextureParameterfv, 0, 0, 0, napi_default, 0 },
		{ "textureParameteri", 0, TextureParameteri, 0, 0, 0, napi_default, 0 },
		{ "textureParameteriv", 0, TextureParameteriv, 0, 0, 0, napi_default, 0 },
		{ "transformFeedbackBufferBase", 0, TransformFeedbackBufferBase, 0, 0, 0, napi_default, 0 },
		{ "transformFeedbackBufferRange", 0, TransformFeedbackBufferRange, 0, 0, 0, napi_default, 0 },
		{ "unmapNamedBuffer", 0, UnmapNamedBuffer, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayAttribBinding", 0, VertexArrayAttribBinding, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayAttribFormat", 0, VertexArrayAttribFormat, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayAttribIFormat", 0, VertexArrayAttribIFormat, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayAttribLFormat", 0, VertexArrayAttribLFormat, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayBindingDivisor", 0, VertexArrayBindingDivisor, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayElementBuffer", 0, VertexArrayElementBuffer, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayVertexBuffer", 0, VertexArrayVertexBuffer, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayVertexBuffers", 0, VertexArrayVertexBuffers, 0, 0, 0, napi_default, 0 },
		{ "drawElementsBaseVertex", 0, DrawElementsBaseVertex, 0, 0, 0, napi_default, 0 },
		{ "drawElementsInstancedBaseVertex", 0, DrawElementsInstancedBaseVertex, 0, 0, 0, napi_default, 0 },
		{ "drawRangeElementsBaseVertex", 0, DrawRangeElementsBaseVertex, 0, 0, 0, napi_default, 0 },
		{ "multiDrawElementsBaseVertex", 0, MultiDrawElementsBaseVertex, 0, 0, 0, napi_default, 0 },
		{ "drawArraysIndirect", 0, DrawArraysIndirect, 0, 0, 0, napi_default, 0 },
		{ "drawElementsIndirect", 0, DrawElementsIndirect, 0, 0, 0, napi_default, 0 },
		{ "framebufferParameteri", 0, FramebufferParameteri, 0, 0, 0, napi_default, 0 },
		{ "namedFramebufferParameteriEXT", 0, NamedFramebufferParameteriEXT, 0, 0, 0, napi_default, 0 },
		{ "colorSubTable", 0, ColorSubTable, 0, 0, 0, napi_default, 0 },
		{ "colorTable", 0, ColorTable, 0, 0, 0, napi_default, 0 },
		{ "colorTableParameterfv", 0, ColorTableParameterfv, 0, 0, 0, napi_default, 0 },
		{ "colorTableParameteriv", 0, ColorTableParameteriv, 0, 0, 0, napi_default, 0 },
		{ "convolutionParameterf", 0, ConvolutionParameterf, 0, 0, 0, napi_default, 0 },
		{ "convolutionParameterfv", 0, ConvolutionParameterfv, 0, 0, 0, napi_default, 0 },
		{ "convolutionParameteri", 0, ConvolutionParameteri, 0, 0, 0, napi_default, 0 },
		{ "convolutionParameteriv", 0, ConvolutionParameteriv, 0, 0, 0, napi_default, 0 },
		{ "copyColorSubTable", 0, CopyColorSubTable, 0, 0, 0, napi_default, 0 },
		{ "copyColorTable", 0, CopyColorTable, 0, 0, 0, napi_default, 0 },
		{ "histogram", 0, Histogram, 0, 0, 0, napi_default, 0 },
		{ "minmax", 0, Minmax, 0, 0, 0, napi_default, 0 },
		{ "resetHistogram", 0, ResetHistogram, 0, 0, 0, napi_default, 0 },
		{ "resetMinmax", 0, ResetMinmax, 0, 0, 0, napi_default, 0 },
		{ "invalidateBufferData", 0, InvalidateBufferData, 0, 0, 0, napi_default, 0 },
		{ "invalidateBufferSubData", 0, InvalidateBufferSubData, 0, 0, 0, napi_default, 0 },
		{ "invalidateTexImage", 0, InvalidateTexImage, 0, 0, 0, napi_default, 0 },
		{ "invalidateTexSubImage", 0, InvalidateTexSubImage, 0, 0, 0, napi_default, 0 },
		{ "bindBuffersBase", 0, BindBuffersBase, 0, 0, 0, napi_default, 0 },
		{ "bindBuffersRange", 0, BindBuffersRange, 0, 0, 0, napi_default, 0 },
		{ "bindImageTextures", 0, BindImageTextures, 0, 0, 0, napi_default, 0 },
		{ "bindSamplers", 0, BindSamplers, 0, 0, 0, napi_default, 0 },
		{ "bindTextures", 0, BindTextures, 0, 0, 0, napi_default, 0 },
		{ "bindVertexBuffers", 0, BindVertexBuffers, 0, 0, 0, napi_default, 0 },
		{ "multiDrawArraysIndirect", 0, MultiDrawArraysIndirect, 0, 0, 0, napi_default, 0 },
		{ "multiDrawElementsIndirect", 0, MultiDrawElementsIndirect, 0, 0, 0, napi_default, 0 },
		{ "provokingVertex", 0, ProvokingVertex, 0, 0, 0, napi_default, 0 },
		{ "samplerParameterIiv", 0, SamplerParameterIiv, 0, 0, 0, napi_default, 0 },
		{ "samplerParameterIuiv", 0, SamplerParameterIuiv, 0, 0, 0, napi_default, 0 },
		{ "activeShaderProgram", 0, ActiveShaderProgram, 0, 0, 0, napi_default, 0 },
		{ "bindProgramPipeline", 0, BindProgramPipeline, 0, 0, 0, napi_default, 0 },
		{ "createShaderProgramv", 0, CreateShaderProgramv, 0, 0, 0, napi_default, 0 },
		{ "deleteProgramPipelines", 0, DeleteProgramPipelines, 0, 0, 0, napi_default, 0 },
		{ "genProgramPipelines", 0, GenProgramPipelines, 0, 0, 0, napi_default, 0 },
		{ "isProgramPipeline", 0, IsProgramPipeline, 0, 0, 0, napi_default, 0 },
		{ "useProgramStages", 0, UseProgramStages, 0, 0, 0, napi_default, 0 },
		{ "validateProgramPipeline", 0, ValidateProgramPipeline, 0, 0, 0, napi_default, 0 },
		{ "bindImageTexture", 0, BindImageTexture, 0, 0, 0, napi_default, 0 },
		{ "memoryBarrier", 0, MemoryBarrier, 0, 0, 0, napi_default, 0 },
		{ "shaderStorageBlockBinding", 0, ShaderStorageBlockBinding, 0, 0, 0, napi_default, 0 },
		{ "uniformSubroutinesuiv", 0, UniformSubroutinesuiv, 0, 0, 0, napi_default, 0 },
		{ "texturePageCommitmentEXT", 0, TexturePageCommitmentEXT, 0, 0, 0, napi_default, 0 },
		{ "patchParameterfv", 0, PatchParameterfv, 0, 0, 0, napi_default, 0 },
		{ "patchParameteri", 0, PatchParameteri, 0, 0, 0, napi_default, 0 },
		{ "textureBarrier", 0, TextureBarrier, 0, 0, 0, napi_default, 0 },
		{ "texBufferRange", 0, TexBufferRange, 0, 0, 0, napi_default, 0 },
		{ "textureBufferRangeEXT", 0, TextureBufferRangeEXT, 0, 0, 0, napi_default, 0 },
		{ "sampleMaski", 0, SampleMaski, 0, 0, 0, napi_default, 0 },
		{ "textureView", 0, TextureView, 0, 0, 0, napi_default, 0 },
		{ "queryCounter", 0, QueryCounter, 0, 0, 0, napi_default, 0 },
		{ "drawTransformFeedback", 0, DrawTransformFeedback, 0, 0, 0, napi_default, 0 },
		{ "beginQueryIndexed", 0, BeginQueryIndexed, 0, 0, 0, napi_default, 0 },
		{ "drawTransformFeedbackStream", 0, DrawTransformFeedbackStream, 0, 0, 0, napi_default, 0 },
		{ "endQueryIndexed", 0, EndQueryIndexed, 0, 0, 0, napi_default, 0 },
		{ "drawTransformFeedbackInstanced", 0, DrawTransformFeedbackInstanced, 0, 0, 0, napi_default, 0 },
		{ "drawTransformFeedbackStreamInstanced", 0, DrawTransformFeedbackStreamInstanced, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribLPointer", 0, VertexAttribLPointer, 0, 0, 0, napi_default, 0 },
		{ "bindVertexBuffer", 0, BindVertexBuffer, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayBindVertexBufferEXT", 0, VertexArrayBindVertexBufferEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayVertexAttribBindingEXT", 0, VertexArrayVertexAttribBindingEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayVertexAttribFormatEXT", 0, VertexArrayVertexAttribFormatEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayVertexAttribIFormatEXT", 0, VertexArrayVertexAttribIFormatEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayVertexAttribLFormatEXT", 0, VertexArrayVertexAttribLFormatEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayVertexBindingDivisorEXT", 0, VertexArrayVertexBindingDivisorEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribBinding", 0, VertexAttribBinding, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribFormat", 0, VertexAttribFormat, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribIFormat", 0, VertexAttribIFormat, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribLFormat", 0, VertexAttribLFormat, 0, 0, 0, napi_default, 0 },
		{ "vertexBindingDivisor", 0, VertexBindingDivisor, 0, 0, 0, napi_default, 0 },
		{ "depthRangeArrayv", 0, DepthRangeArrayv, 0, 0, 0, napi_default, 0 },
		{ "depthRangeIndexed", 0, DepthRangeIndexed, 0, 0, 0, napi_default, 0 },
		{ "scissorArrayv", 0, ScissorArrayv, 0, 0, 0, napi_default, 0 },
		{ "scissorIndexed", 0, ScissorIndexed, 0, 0, 0, napi_default, 0 },
		{ "scissorIndexedv", 0, ScissorIndexedv, 0, 0, 0, napi_default, 0 },
		{ "viewportArrayv", 0, ViewportArrayv, 0, 0, 0, napi_default, 0 },
		{ "viewportIndexedf", 0, ViewportIndexedf, 0, 0, 0, napi_default, 0 },
		{ "viewportIndexedfv", 0, ViewportIndexedfv, 0, 0, 0, napi_default, 0 },
		{ "drawBuffersATI", 0, DrawBuffersATI, 0, 0, 0, napi_default, 0 },
		{ "drawElementArrayATI", 0, DrawElementArrayATI, 0, 0, 0, napi_default, 0 },
		{ "drawRangeElementArrayATI", 0, DrawRangeElementArrayATI, 0, 0, 0, napi_default, 0 },
		{ "elementPointerATI", 0, ElementPointerATI, 0, 0, 0, napi_default, 0 },
		{ "texBumpParameterfvATI", 0, TexBumpParameterfvATI, 0, 0, 0, napi_default, 0 },
		{ "texBumpParameterivATI", 0, TexBumpParameterivATI, 0, 0, 0, napi_default, 0 },
		{ "beginFragmentShaderATI", 0, BeginFragmentShaderATI, 0, 0, 0, napi_default, 0 },
		{ "bindFragmentShaderATI", 0, BindFragmentShaderATI, 0, 0, 0, napi_default, 0 },
		{ "deleteFragmentShaderATI", 0, DeleteFragmentShaderATI, 0, 0, 0, napi_default, 0 },
		{ "endFragmentShaderATI", 0, EndFragmentShaderATI, 0, 0, 0, napi_default, 0 },
		{ "genFragmentShadersATI", 0, GenFragmentShadersATI, 0, 0, 0, napi_default, 0 },
		{ "passTexCoordATI", 0, PassTexCoordATI, 0, 0, 0, napi_default, 0 },
		{ "sampleMapATI", 0, SampleMapATI, 0, 0, 0, napi_default, 0 },
		{ "setFragmentShaderConstantATI", 0, SetFragmentShaderConstantATI, 0, 0, 0, napi_default, 0 },
		{ "unmapObjectBufferATI", 0, UnmapObjectBufferATI, 0, 0, 0, napi_default, 0 },
		{ "pNTrianglesfATI", 0, PNTrianglesfATI, 0, 0, 0, napi_default, 0 },
		{ "pNTrianglesiATI", 0, PNTrianglesiATI, 0, 0, 0, napi_default, 0 },
		{ "stencilFuncSeparateATI", 0, StencilFuncSeparateATI, 0, 0, 0, napi_default, 0 },
		{ "stencilOpSeparateATI", 0, StencilOpSeparateATI, 0, 0, 0, napi_default, 0 },
		{ "arrayObjectATI", 0, ArrayObjectATI, 0, 0, 0, napi_default, 0 },
		{ "freeObjectBufferATI", 0, FreeObjectBufferATI, 0, 0, 0, napi_default, 0 },
		{ "isObjectBufferATI", 0, IsObjectBufferATI, 0, 0, 0, napi_default, 0 },
		{ "newObjectBufferATI", 0, NewObjectBufferATI, 0, 0, 0, napi_default, 0 },
		{ "updateObjectBufferATI", 0, UpdateObjectBufferATI, 0, 0, 0, napi_default, 0 },
		{ "variantArrayObjectATI", 0, VariantArrayObjectATI, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribArrayObjectATI", 0, VertexAttribArrayObjectATI, 0, 0, 0, napi_default, 0 },
		{ "clientActiveVertexStreamATI", 0, ClientActiveVertexStreamATI, 0, 0, 0, napi_default, 0 },
		{ "vertexBlendEnvfATI", 0, VertexBlendEnvfATI, 0, 0, 0, napi_default, 0 },
		{ "vertexBlendEnviATI", 0, VertexBlendEnviATI, 0, 0, 0, napi_default, 0 },
		{ "uniformBufferEXT", 0, UniformBufferEXT, 0, 0, 0, napi_default, 0 },
		{ "blendColorEXT", 0, BlendColorEXT, 0, 0, 0, napi_default, 0 },
		{ "blendEquationSeparateEXT", 0, BlendEquationSeparateEXT, 0, 0, 0, napi_default, 0 },
		{ "blendFuncSeparateEXT", 0, BlendFuncSeparateEXT, 0, 0, 0, napi_default, 0 },
		{ "blendEquationEXT", 0, BlendEquationEXT, 0, 0, 0, napi_default, 0 },
		{ "colorSubTableEXT", 0, ColorSubTableEXT, 0, 0, 0, napi_default, 0 },
		{ "copyColorSubTableEXT", 0, CopyColorSubTableEXT, 0, 0, 0, napi_default, 0 },
		{ "lockArraysEXT", 0, LockArraysEXT, 0, 0, 0, napi_default, 0 },
		{ "unlockArraysEXT", 0, UnlockArraysEXT, 0, 0, 0, napi_default, 0 },
		{ "convolutionParameterfEXT", 0, ConvolutionParameterfEXT, 0, 0, 0, napi_default, 0 },
		{ "convolutionParameterfvEXT", 0, ConvolutionParameterfvEXT, 0, 0, 0, napi_default, 0 },
		{ "convolutionParameteriEXT", 0, ConvolutionParameteriEXT, 0, 0, 0, napi_default, 0 },
		{ "convolutionParameterivEXT", 0, ConvolutionParameterivEXT, 0, 0, 0, napi_default, 0 },
		{ "binormalPointerEXT", 0, BinormalPointerEXT, 0, 0, 0, napi_default, 0 },
		{ "tangentPointerEXT", 0, TangentPointerEXT, 0, 0, 0, napi_default, 0 },
		{ "cullParameterdvEXT", 0, CullParameterdvEXT, 0, 0, 0, napi_default, 0 },
		{ "cullParameterfvEXT", 0, CullParameterfvEXT, 0, 0, 0, napi_default, 0 },
		{ "labelObjectEXT", 0, LabelObjectEXT, 0, 0, 0, napi_default, 0 },
		{ "insertEventMarkerEXT", 0, InsertEventMarkerEXT, 0, 0, 0, napi_default, 0 },
		{ "popGroupMarkerEXT", 0, PopGroupMarkerEXT, 0, 0, 0, napi_default, 0 },
		{ "pushGroupMarkerEXT", 0, PushGroupMarkerEXT, 0, 0, 0, napi_default, 0 },
		{ "depthBoundsEXT", 0, DepthBoundsEXT, 0, 0, 0, napi_default, 0 },
		{ "bindMultiTextureEXT", 0, BindMultiTextureEXT, 0, 0, 0, napi_default, 0 },
		{ "checkNamedFramebufferStatusEXT", 0, CheckNamedFramebufferStatusEXT, 0, 0, 0, napi_default, 0 },
		{ "clientAttribDefaultEXT", 0, ClientAttribDefaultEXT, 0, 0, 0, napi_default, 0 },
		{ "disableClientStateIndexedEXT", 0, DisableClientStateIndexedEXT, 0, 0, 0, napi_default, 0 },
		{ "disableClientStateiEXT", 0, DisableClientStateiEXT, 0, 0, 0, napi_default, 0 },
		{ "disableVertexArrayAttribEXT", 0, DisableVertexArrayAttribEXT, 0, 0, 0, napi_default, 0 },
		{ "disableVertexArrayEXT", 0, DisableVertexArrayEXT, 0, 0, 0, napi_default, 0 },
		{ "enableClientStateIndexedEXT", 0, EnableClientStateIndexedEXT, 0, 0, 0, napi_default, 0 },
		{ "enableClientStateiEXT", 0, EnableClientStateiEXT, 0, 0, 0, napi_default, 0 },
		{ "enableVertexArrayAttribEXT", 0, EnableVertexArrayAttribEXT, 0, 0, 0, napi_default, 0 },
		{ "enableVertexArrayEXT", 0, EnableVertexArrayEXT, 0, 0, 0, napi_default, 0 },
		{ "flushMappedNamedBufferRangeEXT", 0, FlushMappedNamedBufferRangeEXT, 0, 0, 0, napi_default, 0 },
		{ "framebufferDrawBufferEXT", 0, FramebufferDrawBufferEXT, 0, 0, 0, napi_default, 0 },
		{ "framebufferDrawBuffersEXT", 0, FramebufferDrawBuffersEXT, 0, 0, 0, napi_default, 0 },
		{ "framebufferReadBufferEXT", 0, FramebufferReadBufferEXT, 0, 0, 0, napi_default, 0 },
		{ "generateMultiTexMipmapEXT", 0, GenerateMultiTexMipmapEXT, 0, 0, 0, napi_default, 0 },
		{ "generateTextureMipmapEXT", 0, GenerateTextureMipmapEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixFrustumEXT", 0, MatrixFrustumEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixLoadIdentityEXT", 0, MatrixLoadIdentityEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixLoadTransposedEXT", 0, MatrixLoadTransposedEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixLoadTransposefEXT", 0, MatrixLoadTransposefEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixLoaddEXT", 0, MatrixLoaddEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixLoadfEXT", 0, MatrixLoadfEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixMultTransposedEXT", 0, MatrixMultTransposedEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixMultTransposefEXT", 0, MatrixMultTransposefEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixMultdEXT", 0, MatrixMultdEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixMultfEXT", 0, MatrixMultfEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixOrthoEXT", 0, MatrixOrthoEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixPopEXT", 0, MatrixPopEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixPushEXT", 0, MatrixPushEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixRotatedEXT", 0, MatrixRotatedEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixRotatefEXT", 0, MatrixRotatefEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixScaledEXT", 0, MatrixScaledEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixScalefEXT", 0, MatrixScalefEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixTranslatedEXT", 0, MatrixTranslatedEXT, 0, 0, 0, napi_default, 0 },
		{ "matrixTranslatefEXT", 0, MatrixTranslatefEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexBufferEXT", 0, MultiTexBufferEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexCoordPointerEXT", 0, MultiTexCoordPointerEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexEnvfEXT", 0, MultiTexEnvfEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexEnvfvEXT", 0, MultiTexEnvfvEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexEnviEXT", 0, MultiTexEnviEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexEnvivEXT", 0, MultiTexEnvivEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexGendEXT", 0, MultiTexGendEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexGendvEXT", 0, MultiTexGendvEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexGenfEXT", 0, MultiTexGenfEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexGenfvEXT", 0, MultiTexGenfvEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexGeniEXT", 0, MultiTexGeniEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexGenivEXT", 0, MultiTexGenivEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexParameterIivEXT", 0, MultiTexParameterIivEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexParameterIuivEXT", 0, MultiTexParameterIuivEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexParameterfEXT", 0, MultiTexParameterfEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexParameterfvEXT", 0, MultiTexParameterfvEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexParameteriEXT", 0, MultiTexParameteriEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexParameterivEXT", 0, MultiTexParameterivEXT, 0, 0, 0, napi_default, 0 },
		{ "multiTexRenderbufferEXT", 0, MultiTexRenderbufferEXT, 0, 0, 0, napi_default, 0 },
		{ "namedBufferDataEXT", 0, NamedBufferDataEXT, 0, 0, 0, napi_default, 0 },
		{ "namedBufferSubDataEXT", 0, NamedBufferSubDataEXT, 0, 0, 0, napi_default, 0 },
		{ "namedCopyBufferSubDataEXT", 0, NamedCopyBufferSubDataEXT, 0, 0, 0, napi_default, 0 },
		{ "namedFramebufferRenderbufferEXT", 0, NamedFramebufferRenderbufferEXT, 0, 0, 0, napi_default, 0 },
		{ "namedFramebufferTextureEXT", 0, NamedFramebufferTextureEXT, 0, 0, 0, napi_default, 0 },
		{ "namedFramebufferTextureFaceEXT", 0, NamedFramebufferTextureFaceEXT, 0, 0, 0, napi_default, 0 },
		{ "namedFramebufferTextureLayerEXT", 0, NamedFramebufferTextureLayerEXT, 0, 0, 0, napi_default, 0 },
		{ "namedProgramStringEXT", 0, NamedProgramStringEXT, 0, 0, 0, napi_default, 0 },
		{ "namedRenderbufferStorageEXT", 0, NamedRenderbufferStorageEXT, 0, 0, 0, napi_default, 0 },
		{ "namedRenderbufferStorageMultisampleCoverageEXT", 0, NamedRenderbufferStorageMultisampleCoverageEXT, 0, 0, 0, napi_default, 0 },
		{ "namedRenderbufferStorageMultisampleEXT", 0, NamedRenderbufferStorageMultisampleEXT, 0, 0, 0, napi_default, 0 },
		{ "pushClientAttribDefaultEXT", 0, PushClientAttribDefaultEXT, 0, 0, 0, napi_default, 0 },
		{ "textureBufferEXT", 0, TextureBufferEXT, 0, 0, 0, napi_default, 0 },
		{ "textureParameterIivEXT", 0, TextureParameterIivEXT, 0, 0, 0, napi_default, 0 },
		{ "textureParameterIuivEXT", 0, TextureParameterIuivEXT, 0, 0, 0, napi_default, 0 },
		{ "textureParameterfEXT", 0, TextureParameterfEXT, 0, 0, 0, napi_default, 0 },
		{ "textureParameterfvEXT", 0, TextureParameterfvEXT, 0, 0, 0, napi_default, 0 },
		{ "textureParameteriEXT", 0, TextureParameteriEXT, 0, 0, 0, napi_default, 0 },
		{ "textureParameterivEXT", 0, TextureParameterivEXT, 0, 0, 0, napi_default, 0 },
		{ "textureRenderbufferEXT", 0, TextureRenderbufferEXT, 0, 0, 0, napi_default, 0 },
		{ "unmapNamedBufferEXT", 0, UnmapNamedBufferEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayColorOffsetEXT", 0, VertexArrayColorOffsetEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayEdgeFlagOffsetEXT", 0, VertexArrayEdgeFlagOffsetEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayFogCoordOffsetEXT", 0, VertexArrayFogCoordOffsetEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayIndexOffsetEXT", 0, VertexArrayIndexOffsetEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayMultiTexCoordOffsetEXT", 0, VertexArrayMultiTexCoordOffsetEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayNormalOffsetEXT", 0, VertexArrayNormalOffsetEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArraySecondaryColorOffsetEXT", 0, VertexArraySecondaryColorOffsetEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayTexCoordOffsetEXT", 0, VertexArrayTexCoordOffsetEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayVertexAttribDivisorEXT", 0, VertexArrayVertexAttribDivisorEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayVertexAttribIOffsetEXT", 0, VertexArrayVertexAttribIOffsetEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayVertexAttribOffsetEXT", 0, VertexArrayVertexAttribOffsetEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayVertexOffsetEXT", 0, VertexArrayVertexOffsetEXT, 0, 0, 0, napi_default, 0 },
		{ "colorMaskIndexedEXT", 0, ColorMaskIndexedEXT, 0, 0, 0, napi_default, 0 },
		{ "disableIndexedEXT", 0, DisableIndexedEXT, 0, 0, 0, napi_default, 0 },
		{ "enableIndexedEXT", 0, EnableIndexedEXT, 0, 0, 0, napi_default, 0 },
		{ "isEnabledIndexedEXT", 0, IsEnabledIndexedEXT, 0, 0, 0, napi_default, 0 },
		{ "drawArraysInstancedEXT", 0, DrawArraysInstancedEXT, 0, 0, 0, napi_default, 0 },
		{ "drawElementsInstancedEXT", 0, DrawElementsInstancedEXT, 0, 0, 0, napi_default, 0 },
		{ "drawRangeElementsEXT", 0, DrawRangeElementsEXT, 0, 0, 0, napi_default, 0 },
		{ "fogCoordPointerEXT", 0, FogCoordPointerEXT, 0, 0, 0, napi_default, 0 },
		{ "fogCoorddEXT", 0, FogCoorddEXT, 0, 0, 0, napi_default, 0 },
		{ "fogCoorddvEXT", 0, FogCoorddvEXT, 0, 0, 0, napi_default, 0 },
		{ "fogCoordfEXT", 0, FogCoordfEXT, 0, 0, 0, napi_default, 0 },
		{ "fogCoordfvEXT", 0, FogCoordfvEXT, 0, 0, 0, napi_default, 0 },
		{ "fragmentColorMaterialEXT", 0, FragmentColorMaterialEXT, 0, 0, 0, napi_default, 0 },
		{ "fragmentLightModelfEXT", 0, FragmentLightModelfEXT, 0, 0, 0, napi_default, 0 },
		{ "fragmentLightModelfvEXT", 0, FragmentLightModelfvEXT, 0, 0, 0, napi_default, 0 },
		{ "fragmentLightModeliEXT", 0, FragmentLightModeliEXT, 0, 0, 0, napi_default, 0 },
		{ "fragmentLightModelivEXT", 0, FragmentLightModelivEXT, 0, 0, 0, napi_default, 0 },
		{ "fragmentLightfEXT", 0, FragmentLightfEXT, 0, 0, 0, napi_default, 0 },
		{ "fragmentLightfvEXT", 0, FragmentLightfvEXT, 0, 0, 0, napi_default, 0 },
		{ "fragmentLightiEXT", 0, FragmentLightiEXT, 0, 0, 0, napi_default, 0 },
		{ "fragmentLightivEXT", 0, FragmentLightivEXT, 0, 0, 0, napi_default, 0 },
		{ "fragmentMaterialfEXT", 0, FragmentMaterialfEXT, 0, 0, 0, napi_default, 0 },
		{ "fragmentMaterialfvEXT", 0, FragmentMaterialfvEXT, 0, 0, 0, napi_default, 0 },
		{ "fragmentMaterialiEXT", 0, FragmentMaterialiEXT, 0, 0, 0, napi_default, 0 },
		{ "fragmentMaterialivEXT", 0, FragmentMaterialivEXT, 0, 0, 0, napi_default, 0 },
		{ "lightEnviEXT", 0, LightEnviEXT, 0, 0, 0, napi_default, 0 },
		{ "blitFramebufferEXT", 0, BlitFramebufferEXT, 0, 0, 0, napi_default, 0 },
		{ "renderbufferStorageMultisampleEXT", 0, RenderbufferStorageMultisampleEXT, 0, 0, 0, napi_default, 0 },
		{ "bindFramebufferEXT", 0, BindFramebufferEXT, 0, 0, 0, napi_default, 0 },
		{ "bindRenderbufferEXT", 0, BindRenderbufferEXT, 0, 0, 0, napi_default, 0 },
		{ "checkFramebufferStatusEXT", 0, CheckFramebufferStatusEXT, 0, 0, 0, napi_default, 0 },
		{ "deleteFramebuffersEXT", 0, DeleteFramebuffersEXT, 0, 0, 0, napi_default, 0 },
		{ "deleteRenderbuffersEXT", 0, DeleteRenderbuffersEXT, 0, 0, 0, napi_default, 0 },
		{ "framebufferRenderbufferEXT", 0, FramebufferRenderbufferEXT, 0, 0, 0, napi_default, 0 },
		{ "genFramebuffersEXT", 0, GenFramebuffersEXT, 0, 0, 0, napi_default, 0 },
		{ "genRenderbuffersEXT", 0, GenRenderbuffersEXT, 0, 0, 0, napi_default, 0 },
		{ "generateMipmapEXT", 0, GenerateMipmapEXT, 0, 0, 0, napi_default, 0 },
		{ "isFramebufferEXT", 0, IsFramebufferEXT, 0, 0, 0, napi_default, 0 },
		{ "isRenderbufferEXT", 0, IsRenderbufferEXT, 0, 0, 0, napi_default, 0 },
		{ "renderbufferStorageEXT", 0, RenderbufferStorageEXT, 0, 0, 0, napi_default, 0 },
		{ "framebufferTextureEXT", 0, FramebufferTextureEXT, 0, 0, 0, napi_default, 0 },
		{ "framebufferTextureFaceEXT", 0, FramebufferTextureFaceEXT, 0, 0, 0, napi_default, 0 },
		{ "programParameteriEXT", 0, ProgramParameteriEXT, 0, 0, 0, napi_default, 0 },
		{ "bindFragDataLocationEXT", 0, BindFragDataLocationEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribIPointerEXT", 0, VertexAttribIPointerEXT, 0, 0, 0, napi_default, 0 },
		{ "histogramEXT", 0, HistogramEXT, 0, 0, 0, napi_default, 0 },
		{ "minmaxEXT", 0, MinmaxEXT, 0, 0, 0, napi_default, 0 },
		{ "resetHistogramEXT", 0, ResetHistogramEXT, 0, 0, 0, napi_default, 0 },
		{ "resetMinmaxEXT", 0, ResetMinmaxEXT, 0, 0, 0, napi_default, 0 },
		{ "indexFuncEXT", 0, IndexFuncEXT, 0, 0, 0, napi_default, 0 },
		{ "indexMaterialEXT", 0, IndexMaterialEXT, 0, 0, 0, napi_default, 0 },
		{ "applyTextureEXT", 0, ApplyTextureEXT, 0, 0, 0, napi_default, 0 },
		{ "textureLightEXT", 0, TextureLightEXT, 0, 0, 0, napi_default, 0 },
		{ "textureMaterialEXT", 0, TextureMaterialEXT, 0, 0, 0, napi_default, 0 },
		{ "multiDrawArraysEXT", 0, MultiDrawArraysEXT, 0, 0, 0, napi_default, 0 },
		{ "multiDrawElementsEXT", 0, MultiDrawElementsEXT, 0, 0, 0, napi_default, 0 },
		{ "sampleMaskEXT", 0, SampleMaskEXT, 0, 0, 0, napi_default, 0 },
		{ "samplePatternEXT", 0, SamplePatternEXT, 0, 0, 0, napi_default, 0 },
		{ "colorTableEXT", 0, ColorTableEXT, 0, 0, 0, napi_default, 0 },
		{ "pixelTransformParameterfEXT", 0, PixelTransformParameterfEXT, 0, 0, 0, napi_default, 0 },
		{ "pixelTransformParameterfvEXT", 0, PixelTransformParameterfvEXT, 0, 0, 0, napi_default, 0 },
		{ "pixelTransformParameteriEXT", 0, PixelTransformParameteriEXT, 0, 0, 0, napi_default, 0 },
		{ "pixelTransformParameterivEXT", 0, PixelTransformParameterivEXT, 0, 0, 0, napi_default, 0 },
		{ "pointParameterfEXT", 0, PointParameterfEXT, 0, 0, 0, napi_default, 0 },
		{ "pointParameterfvEXT", 0, PointParameterfvEXT, 0, 0, 0, napi_default, 0 },
		{ "polygonOffsetEXT", 0, PolygonOffsetEXT, 0, 0, 0, napi_default, 0 },
		{ "polygonOffsetClampEXT", 0, PolygonOffsetClampEXT, 0, 0, 0, napi_default, 0 },
		{ "provokingVertexEXT", 0, ProvokingVertexEXT, 0, 0, 0, napi_default, 0 },
		{ "coverageModulationNV", 0, CoverageModulationNV, 0, 0, 0, napi_default, 0 },
		{ "coverageModulationTableNV", 0, CoverageModulationTableNV, 0, 0, 0, napi_default, 0 },
		{ "rasterSamplesEXT", 0, RasterSamplesEXT, 0, 0, 0, napi_default, 0 },
		{ "beginSceneEXT", 0, BeginSceneEXT, 0, 0, 0, napi_default, 0 },
		{ "endSceneEXT", 0, EndSceneEXT, 0, 0, 0, napi_default, 0 },
		{ "secondaryColorPointerEXT", 0, SecondaryColorPointerEXT, 0, 0, 0, napi_default, 0 },
		{ "activeProgramEXT", 0, ActiveProgramEXT, 0, 0, 0, napi_default, 0 },
		{ "createShaderProgramEXT", 0, CreateShaderProgramEXT, 0, 0, 0, napi_default, 0 },
		{ "useShaderProgramEXT", 0, UseShaderProgramEXT, 0, 0, 0, napi_default, 0 },
		{ "bindImageTextureEXT", 0, BindImageTextureEXT, 0, 0, 0, napi_default, 0 },
		{ "memoryBarrierEXT", 0, MemoryBarrierEXT, 0, 0, 0, napi_default, 0 },
		{ "activeStencilFaceEXT", 0, ActiveStencilFaceEXT, 0, 0, 0, napi_default, 0 },
		{ "framebufferTextureLayerEXT", 0, FramebufferTextureLayerEXT, 0, 0, 0, napi_default, 0 },
		{ "texBufferEXT", 0, TexBufferEXT, 0, 0, 0, napi_default, 0 },
		{ "clearColorIiEXT", 0, ClearColorIiEXT, 0, 0, 0, napi_default, 0 },
		{ "clearColorIuiEXT", 0, ClearColorIuiEXT, 0, 0, 0, napi_default, 0 },
		{ "texParameterIivEXT", 0, TexParameterIivEXT, 0, 0, 0, napi_default, 0 },
		{ "texParameterIuivEXT", 0, TexParameterIuivEXT, 0, 0, 0, napi_default, 0 },
		{ "areTexturesResidentEXT", 0, AreTexturesResidentEXT, 0, 0, 0, napi_default, 0 },
		{ "bindTextureEXT", 0, BindTextureEXT, 0, 0, 0, napi_default, 0 },
		{ "deleteTexturesEXT", 0, DeleteTexturesEXT, 0, 0, 0, napi_default, 0 },
		{ "genTexturesEXT", 0, GenTexturesEXT, 0, 0, 0, napi_default, 0 },
		{ "isTextureEXT", 0, IsTextureEXT, 0, 0, 0, napi_default, 0 },
		{ "prioritizeTexturesEXT", 0, PrioritizeTexturesEXT, 0, 0, 0, napi_default, 0 },
		{ "textureNormalEXT", 0, TextureNormalEXT, 0, 0, 0, napi_default, 0 },
		{ "beginTransformFeedbackEXT", 0, BeginTransformFeedbackEXT, 0, 0, 0, napi_default, 0 },
		{ "bindBufferBaseEXT", 0, BindBufferBaseEXT, 0, 0, 0, napi_default, 0 },
		{ "bindBufferOffsetEXT", 0, BindBufferOffsetEXT, 0, 0, 0, napi_default, 0 },
		{ "bindBufferRangeEXT", 0, BindBufferRangeEXT, 0, 0, 0, napi_default, 0 },
		{ "endTransformFeedbackEXT", 0, EndTransformFeedbackEXT, 0, 0, 0, napi_default, 0 },
		{ "transformFeedbackVaryingsEXT", 0, TransformFeedbackVaryingsEXT, 0, 0, 0, napi_default, 0 },
		{ "arrayElementEXT", 0, ArrayElementEXT, 0, 0, 0, napi_default, 0 },
		{ "colorPointerEXT", 0, ColorPointerEXT, 0, 0, 0, napi_default, 0 },
		{ "drawArraysEXT", 0, DrawArraysEXT, 0, 0, 0, napi_default, 0 },
		{ "edgeFlagPointerEXT", 0, EdgeFlagPointerEXT, 0, 0, 0, napi_default, 0 },
		{ "indexPointerEXT", 0, IndexPointerEXT, 0, 0, 0, napi_default, 0 },
		{ "normalPointerEXT", 0, NormalPointerEXT, 0, 0, 0, napi_default, 0 },
		{ "texCoordPointerEXT", 0, TexCoordPointerEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexPointerEXT", 0, VertexPointerEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayVertexAttribLOffsetEXT", 0, VertexArrayVertexAttribLOffsetEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribLPointerEXT", 0, VertexAttribLPointerEXT, 0, 0, 0, napi_default, 0 },
		{ "beginVertexShaderEXT", 0, BeginVertexShaderEXT, 0, 0, 0, napi_default, 0 },
		{ "bindLightParameterEXT", 0, BindLightParameterEXT, 0, 0, 0, napi_default, 0 },
		{ "bindMaterialParameterEXT", 0, BindMaterialParameterEXT, 0, 0, 0, napi_default, 0 },
		{ "bindParameterEXT", 0, BindParameterEXT, 0, 0, 0, napi_default, 0 },
		{ "bindTexGenParameterEXT", 0, BindTexGenParameterEXT, 0, 0, 0, napi_default, 0 },
		{ "bindTextureUnitParameterEXT", 0, BindTextureUnitParameterEXT, 0, 0, 0, napi_default, 0 },
		{ "bindVertexShaderEXT", 0, BindVertexShaderEXT, 0, 0, 0, napi_default, 0 },
		{ "deleteVertexShaderEXT", 0, DeleteVertexShaderEXT, 0, 0, 0, napi_default, 0 },
		{ "disableVariantClientStateEXT", 0, DisableVariantClientStateEXT, 0, 0, 0, napi_default, 0 },
		{ "enableVariantClientStateEXT", 0, EnableVariantClientStateEXT, 0, 0, 0, napi_default, 0 },
		{ "endVertexShaderEXT", 0, EndVertexShaderEXT, 0, 0, 0, napi_default, 0 },
		{ "extractComponentEXT", 0, ExtractComponentEXT, 0, 0, 0, napi_default, 0 },
		{ "genSymbolsEXT", 0, GenSymbolsEXT, 0, 0, 0, napi_default, 0 },
		{ "genVertexShadersEXT", 0, GenVertexShadersEXT, 0, 0, 0, napi_default, 0 },
		{ "insertComponentEXT", 0, InsertComponentEXT, 0, 0, 0, napi_default, 0 },
		{ "isVariantEnabledEXT", 0, IsVariantEnabledEXT, 0, 0, 0, napi_default, 0 },
		{ "setInvariantEXT", 0, SetInvariantEXT, 0, 0, 0, napi_default, 0 },
		{ "setLocalConstantEXT", 0, SetLocalConstantEXT, 0, 0, 0, napi_default, 0 },
		{ "swizzleEXT", 0, SwizzleEXT, 0, 0, 0, napi_default, 0 },
		{ "variantPointerEXT", 0, VariantPointerEXT, 0, 0, 0, napi_default, 0 },
		{ "variantbvEXT", 0, VariantbvEXT, 0, 0, 0, napi_default, 0 },
		{ "variantdvEXT", 0, VariantdvEXT, 0, 0, 0, napi_default, 0 },
		{ "variantfvEXT", 0, VariantfvEXT, 0, 0, 0, napi_default, 0 },
		{ "variantivEXT", 0, VariantivEXT, 0, 0, 0, napi_default, 0 },
		{ "variantsvEXT", 0, VariantsvEXT, 0, 0, 0, napi_default, 0 },
		{ "variantubvEXT", 0, VariantubvEXT, 0, 0, 0, napi_default, 0 },
		{ "variantuivEXT", 0, VariantuivEXT, 0, 0, 0, napi_default, 0 },
		{ "variantusvEXT", 0, VariantusvEXT, 0, 0, 0, napi_default, 0 },
		{ "writeMaskEXT", 0, WriteMaskEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexWeightPointerEXT", 0, VertexWeightPointerEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexWeightfEXT", 0, VertexWeightfEXT, 0, 0, 0, napi_default, 0 },
		{ "vertexWeightfvEXT", 0, VertexWeightfvEXT, 0, 0, 0, napi_default, 0 },
		{ "importSyncEXT", 0, ImportSyncEXT, 0, 0, 0, napi_default, 0 },
		{ "frameTerminatorGREMEDY", 0, FrameTerminatorGREMEDY, 0, 0, 0, napi_default, 0 },
		{ "stringMarkerGREMEDY", 0, StringMarkerGREMEDY, 0, 0, 0, napi_default, 0 },
		{ "imageTransformParameterfHP", 0, ImageTransformParameterfHP, 0, 0, 0, napi_default, 0 },
		{ "imageTransformParameterfvHP", 0, ImageTransformParameterfvHP, 0, 0, 0, napi_default, 0 },
		{ "imageTransformParameteriHP", 0, ImageTransformParameteriHP, 0, 0, 0, napi_default, 0 },
		{ "imageTransformParameterivHP", 0, ImageTransformParameterivHP, 0, 0, 0, napi_default, 0 },
		{ "multiModeDrawArraysIBM", 0, MultiModeDrawArraysIBM, 0, 0, 0, napi_default, 0 },
		{ "multiModeDrawElementsIBM", 0, MultiModeDrawElementsIBM, 0, 0, 0, napi_default, 0 },
		{ "syncTextureINTEL", 0, SyncTextureINTEL, 0, 0, 0, napi_default, 0 },
		{ "beginPerfQueryINTEL", 0, BeginPerfQueryINTEL, 0, 0, 0, napi_default, 0 },
		{ "createPerfQueryINTEL", 0, CreatePerfQueryINTEL, 0, 0, 0, napi_default, 0 },
		{ "deletePerfQueryINTEL", 0, DeletePerfQueryINTEL, 0, 0, 0, napi_default, 0 },
		{ "endPerfQueryINTEL", 0, EndPerfQueryINTEL, 0, 0, 0, napi_default, 0 },
		{ "texScissorFuncINTEL", 0, TexScissorFuncINTEL, 0, 0, 0, napi_default, 0 },
		{ "texScissorINTEL", 0, TexScissorINTEL, 0, 0, 0, napi_default, 0 },
		{ "blendBarrierKHR", 0, BlendBarrierKHR, 0, 0, 0, napi_default, 0 },
		{ "debugMessageCallback", 0, DebugMessageCallback, 0, 0, 0, napi_default, 0 },
		{ "debugMessageControl", 0, DebugMessageControl, 0, 0, 0, napi_default, 0 },
		{ "debugMessageInsert", 0, DebugMessageInsert, 0, 0, 0, napi_default, 0 },
		{ "objectLabel", 0, ObjectLabel, 0, 0, 0, napi_default, 0 },
		{ "objectPtrLabel", 0, ObjectPtrLabel, 0, 0, 0, napi_default, 0 },
		{ "popDebugGroup", 0, PopDebugGroup, 0, 0, 0, napi_default, 0 },
		{ "pushDebugGroup", 0, PushDebugGroup, 0, 0, 0, napi_default, 0 },
		{ "readnPixels", 0, ReadnPixels, 0, 0, 0, napi_default, 0 },
		{ "bufferRegionEnabled", 0, BufferRegionEnabled, 0, 0, 0, napi_default, 0 },
		{ "deleteBufferRegion", 0, DeleteBufferRegion, 0, 0, 0, napi_default, 0 },
		{ "drawBufferRegion", 0, DrawBufferRegion, 0, 0, 0, napi_default, 0 },
		{ "newBufferRegion", 0, NewBufferRegion, 0, 0, 0, napi_default, 0 },
		{ "readBufferRegion", 0, ReadBufferRegion, 0, 0, 0, napi_default, 0 },
		{ "resizeBuffersMESA", 0, ResizeBuffersMESA, 0, 0, 0, napi_default, 0 },
		{ "beginConditionalRenderNVX", 0, BeginConditionalRenderNVX, 0, 0, 0, napi_default, 0 },
		{ "endConditionalRenderNVX", 0, EndConditionalRenderNVX, 0, 0, 0, napi_default, 0 },
		{ "multiDrawArraysIndirectBindlessNV", 0, MultiDrawArraysIndirectBindlessNV, 0, 0, 0, napi_default, 0 },
		{ "multiDrawElementsIndirectBindlessNV", 0, MultiDrawElementsIndirectBindlessNV, 0, 0, 0, napi_default, 0 },
		{ "multiDrawArraysIndirectBindlessCountNV", 0, MultiDrawArraysIndirectBindlessCountNV, 0, 0, 0, napi_default, 0 },
		{ "multiDrawElementsIndirectBindlessCountNV", 0, MultiDrawElementsIndirectBindlessCountNV, 0, 0, 0, napi_default, 0 },
		{ "isImageHandleResidentNV", 0, IsImageHandleResidentNV, 0, 0, 0, napi_default, 0 },
		{ "isTextureHandleResidentNV", 0, IsTextureHandleResidentNV, 0, 0, 0, napi_default, 0 },
		{ "makeImageHandleNonResidentNV", 0, MakeImageHandleNonResidentNV, 0, 0, 0, napi_default, 0 },
		{ "makeImageHandleResidentNV", 0, MakeImageHandleResidentNV, 0, 0, 0, napi_default, 0 },
		{ "makeTextureHandleNonResidentNV", 0, MakeTextureHandleNonResidentNV, 0, 0, 0, napi_default, 0 },
		{ "makeTextureHandleResidentNV", 0, MakeTextureHandleResidentNV, 0, 0, 0, napi_default, 0 },
		{ "blendBarrierNV", 0, BlendBarrierNV, 0, 0, 0, napi_default, 0 },
		{ "blendParameteriNV", 0, BlendParameteriNV, 0, 0, 0, napi_default, 0 },
		{ "beginConditionalRenderNV", 0, BeginConditionalRenderNV, 0, 0, 0, napi_default, 0 },
		{ "endConditionalRenderNV", 0, EndConditionalRenderNV, 0, 0, 0, napi_default, 0 },
		{ "subpixelPrecisionBiasNV", 0, SubpixelPrecisionBiasNV, 0, 0, 0, napi_default, 0 },
		{ "conservativeRasterParameterfNV", 0, ConservativeRasterParameterfNV, 0, 0, 0, napi_default, 0 },
		{ "copyImageSubDataNV", 0, CopyImageSubDataNV, 0, 0, 0, napi_default, 0 },
		{ "clearDepthdNV", 0, ClearDepthdNV, 0, 0, 0, napi_default, 0 },
		{ "depthBoundsdNV", 0, DepthBoundsdNV, 0, 0, 0, napi_default, 0 },
		{ "depthRangedNV", 0, DepthRangedNV, 0, 0, 0, napi_default, 0 },
		{ "drawTextureNV", 0, DrawTextureNV, 0, 0, 0, napi_default, 0 },
		{ "evalMapsNV", 0, EvalMapsNV, 0, 0, 0, napi_default, 0 },
		{ "mapControlPointsNV", 0, MapControlPointsNV, 0, 0, 0, napi_default, 0 },
		{ "mapParameterfvNV", 0, MapParameterfvNV, 0, 0, 0, napi_default, 0 },
		{ "mapParameterivNV", 0, MapParameterivNV, 0, 0, 0, napi_default, 0 },
		{ "sampleMaskIndexedNV", 0, SampleMaskIndexedNV, 0, 0, 0, napi_default, 0 },
		{ "texRenderbufferNV", 0, TexRenderbufferNV, 0, 0, 0, napi_default, 0 },
		{ "deleteFencesNV", 0, DeleteFencesNV, 0, 0, 0, napi_default, 0 },
		{ "finishFenceNV", 0, FinishFenceNV, 0, 0, 0, napi_default, 0 },
		{ "genFencesNV", 0, GenFencesNV, 0, 0, 0, napi_default, 0 },
		{ "isFenceNV", 0, IsFenceNV, 0, 0, 0, napi_default, 0 },
		{ "setFenceNV", 0, SetFenceNV, 0, 0, 0, napi_default, 0 },
		{ "testFenceNV", 0, TestFenceNV, 0, 0, 0, napi_default, 0 },
		{ "fragmentCoverageColorNV", 0, FragmentCoverageColorNV, 0, 0, 0, napi_default, 0 },
		{ "renderbufferStorageMultisampleCoverageNV", 0, RenderbufferStorageMultisampleCoverageNV, 0, 0, 0, napi_default, 0 },
		{ "programVertexLimitNV", 0, ProgramVertexLimitNV, 0, 0, 0, napi_default, 0 },
		{ "fogCoordhNV", 0, FogCoordhNV, 0, 0, 0, napi_default, 0 },
		{ "fogCoordhvNV", 0, FogCoordhvNV, 0, 0, 0, napi_default, 0 },
		{ "vertexWeighthNV", 0, VertexWeighthNV, 0, 0, 0, napi_default, 0 },
		{ "vertexWeighthvNV", 0, VertexWeighthvNV, 0, 0, 0, napi_default, 0 },
		{ "beginOcclusionQueryNV", 0, BeginOcclusionQueryNV, 0, 0, 0, napi_default, 0 },
		{ "deleteOcclusionQueriesNV", 0, DeleteOcclusionQueriesNV, 0, 0, 0, napi_default, 0 },
		{ "endOcclusionQueryNV", 0, EndOcclusionQueryNV, 0, 0, 0, napi_default, 0 },
		{ "genOcclusionQueriesNV", 0, GenOcclusionQueriesNV, 0, 0, 0, napi_default, 0 },
		{ "isOcclusionQueryNV", 0, IsOcclusionQueryNV, 0, 0, 0, napi_default, 0 },
		{ "programBufferParametersIivNV", 0, ProgramBufferParametersIivNV, 0, 0, 0, napi_default, 0 },
		{ "programBufferParametersIuivNV", 0, ProgramBufferParametersIuivNV, 0, 0, 0, napi_default, 0 },
		{ "programBufferParametersfvNV", 0, ProgramBufferParametersfvNV, 0, 0, 0, napi_default, 0 },
		{ "copyPathNV", 0, CopyPathNV, 0, 0, 0, napi_default, 0 },
		{ "coverFillPathInstancedNV", 0, CoverFillPathInstancedNV, 0, 0, 0, napi_default, 0 },
		{ "coverFillPathNV", 0, CoverFillPathNV, 0, 0, 0, napi_default, 0 },
		{ "coverStrokePathInstancedNV", 0, CoverStrokePathInstancedNV, 0, 0, 0, napi_default, 0 },
		{ "coverStrokePathNV", 0, CoverStrokePathNV, 0, 0, 0, napi_default, 0 },
		{ "deletePathsNV", 0, DeletePathsNV, 0, 0, 0, napi_default, 0 },
		{ "genPathsNV", 0, GenPathsNV, 0, 0, 0, napi_default, 0 },
		{ "interpolatePathsNV", 0, InterpolatePathsNV, 0, 0, 0, napi_default, 0 },
		{ "isPathNV", 0, IsPathNV, 0, 0, 0, napi_default, 0 },
		{ "isPointInFillPathNV", 0, IsPointInFillPathNV, 0, 0, 0, napi_default, 0 },
		{ "isPointInStrokePathNV", 0, IsPointInStrokePathNV, 0, 0, 0, napi_default, 0 },
		{ "pathColorGenNV", 0, PathColorGenNV, 0, 0, 0, napi_default, 0 },
		{ "pathCommandsNV", 0, PathCommandsNV, 0, 0, 0, napi_default, 0 },
		{ "pathCoordsNV", 0, PathCoordsNV, 0, 0, 0, napi_default, 0 },
		{ "pathCoverDepthFuncNV", 0, PathCoverDepthFuncNV, 0, 0, 0, napi_default, 0 },
		{ "pathDashArrayNV", 0, PathDashArrayNV, 0, 0, 0, napi_default, 0 },
		{ "pathFogGenNV", 0, PathFogGenNV, 0, 0, 0, napi_default, 0 },
		{ "pathGlyphIndexArrayNV", 0, PathGlyphIndexArrayNV, 0, 0, 0, napi_default, 0 },
		{ "pathGlyphRangeNV", 0, PathGlyphRangeNV, 0, 0, 0, napi_default, 0 },
		{ "pathGlyphsNV", 0, PathGlyphsNV, 0, 0, 0, napi_default, 0 },
		{ "pathMemoryGlyphIndexArrayNV", 0, PathMemoryGlyphIndexArrayNV, 0, 0, 0, napi_default, 0 },
		{ "pathParameterfNV", 0, PathParameterfNV, 0, 0, 0, napi_default, 0 },
		{ "pathParameterfvNV", 0, PathParameterfvNV, 0, 0, 0, napi_default, 0 },
		{ "pathParameteriNV", 0, PathParameteriNV, 0, 0, 0, napi_default, 0 },
		{ "pathParameterivNV", 0, PathParameterivNV, 0, 0, 0, napi_default, 0 },
		{ "pathStencilDepthOffsetNV", 0, PathStencilDepthOffsetNV, 0, 0, 0, napi_default, 0 },
		{ "pathStencilFuncNV", 0, PathStencilFuncNV, 0, 0, 0, napi_default, 0 },
		{ "pathStringNV", 0, PathStringNV, 0, 0, 0, napi_default, 0 },
		{ "pathSubCommandsNV", 0, PathSubCommandsNV, 0, 0, 0, napi_default, 0 },
		{ "pathSubCoordsNV", 0, PathSubCoordsNV, 0, 0, 0, napi_default, 0 },
		{ "pathTexGenNV", 0, PathTexGenNV, 0, 0, 0, napi_default, 0 },
		{ "pointAlongPathNV", 0, PointAlongPathNV, 0, 0, 0, napi_default, 0 },
		{ "programPathFragmentInputGenNV", 0, ProgramPathFragmentInputGenNV, 0, 0, 0, napi_default, 0 },
		{ "stencilFillPathInstancedNV", 0, StencilFillPathInstancedNV, 0, 0, 0, napi_default, 0 },
		{ "stencilFillPathNV", 0, StencilFillPathNV, 0, 0, 0, napi_default, 0 },
		{ "stencilStrokePathInstancedNV", 0, StencilStrokePathInstancedNV, 0, 0, 0, napi_default, 0 },
		{ "stencilStrokePathNV", 0, StencilStrokePathNV, 0, 0, 0, napi_default, 0 },
		{ "stencilThenCoverFillPathInstancedNV", 0, StencilThenCoverFillPathInstancedNV, 0, 0, 0, napi_default, 0 },
		{ "stencilThenCoverFillPathNV", 0, StencilThenCoverFillPathNV, 0, 0, 0, napi_default, 0 },
		{ "stencilThenCoverStrokePathInstancedNV", 0, StencilThenCoverStrokePathInstancedNV, 0, 0, 0, napi_default, 0 },
		{ "stencilThenCoverStrokePathNV", 0, StencilThenCoverStrokePathNV, 0, 0, 0, napi_default, 0 },
		{ "transformPathNV", 0, TransformPathNV, 0, 0, 0, napi_default, 0 },
		{ "flushPixelDataRangeNV", 0, FlushPixelDataRangeNV, 0, 0, 0, napi_default, 0 },
		{ "pixelDataRangeNV", 0, PixelDataRangeNV, 0, 0, 0, napi_default, 0 },
		{ "pointParameteriNV", 0, PointParameteriNV, 0, 0, 0, napi_default, 0 },
		{ "pointParameterivNV", 0, PointParameterivNV, 0, 0, 0, napi_default, 0 },
		{ "presentFrameDualFillNV", 0, PresentFrameDualFillNV, 0, 0, 0, napi_default, 0 },
		{ "presentFrameKeyedNV", 0, PresentFrameKeyedNV, 0, 0, 0, napi_default, 0 },
		{ "primitiveRestartIndexNV", 0, PrimitiveRestartIndexNV, 0, 0, 0, napi_default, 0 },
		{ "primitiveRestartNV", 0, PrimitiveRestartNV, 0, 0, 0, napi_default, 0 },
		{ "combinerInputNV", 0, CombinerInputNV, 0, 0, 0, napi_default, 0 },
		{ "combinerOutputNV", 0, CombinerOutputNV, 0, 0, 0, napi_default, 0 },
		{ "combinerParameterfNV", 0, CombinerParameterfNV, 0, 0, 0, napi_default, 0 },
		{ "combinerParameterfvNV", 0, CombinerParameterfvNV, 0, 0, 0, napi_default, 0 },
		{ "combinerParameteriNV", 0, CombinerParameteriNV, 0, 0, 0, napi_default, 0 },
		{ "combinerParameterivNV", 0, CombinerParameterivNV, 0, 0, 0, napi_default, 0 },
		{ "finalCombinerInputNV", 0, FinalCombinerInputNV, 0, 0, 0, napi_default, 0 },
		{ "combinerStageParameterfvNV", 0, CombinerStageParameterfvNV, 0, 0, 0, napi_default, 0 },
		{ "framebufferSampleLocationsfvNV", 0, FramebufferSampleLocationsfvNV, 0, 0, 0, napi_default, 0 },
		{ "namedFramebufferSampleLocationsfvNV", 0, NamedFramebufferSampleLocationsfvNV, 0, 0, 0, napi_default, 0 },
		{ "isBufferResidentNV", 0, IsBufferResidentNV, 0, 0, 0, napi_default, 0 },
		{ "isNamedBufferResidentNV", 0, IsNamedBufferResidentNV, 0, 0, 0, napi_default, 0 },
		{ "makeBufferNonResidentNV", 0, MakeBufferNonResidentNV, 0, 0, 0, napi_default, 0 },
		{ "makeBufferResidentNV", 0, MakeBufferResidentNV, 0, 0, 0, napi_default, 0 },
		{ "makeNamedBufferNonResidentNV", 0, MakeNamedBufferNonResidentNV, 0, 0, 0, napi_default, 0 },
		{ "makeNamedBufferResidentNV", 0, MakeNamedBufferResidentNV, 0, 0, 0, napi_default, 0 },
		{ "textureBarrierNV", 0, TextureBarrierNV, 0, 0, 0, napi_default, 0 },
		{ "activeVaryingNV", 0, ActiveVaryingNV, 0, 0, 0, napi_default, 0 },
		{ "beginTransformFeedbackNV", 0, BeginTransformFeedbackNV, 0, 0, 0, napi_default, 0 },
		{ "bindBufferBaseNV", 0, BindBufferBaseNV, 0, 0, 0, napi_default, 0 },
		{ "bindBufferOffsetNV", 0, BindBufferOffsetNV, 0, 0, 0, napi_default, 0 },
		{ "bindBufferRangeNV", 0, BindBufferRangeNV, 0, 0, 0, napi_default, 0 },
		{ "endTransformFeedbackNV", 0, EndTransformFeedbackNV, 0, 0, 0, napi_default, 0 },
		{ "transformFeedbackAttribsNV", 0, TransformFeedbackAttribsNV, 0, 0, 0, napi_default, 0 },
		{ "transformFeedbackVaryingsNV", 0, TransformFeedbackVaryingsNV, 0, 0, 0, napi_default, 0 },
		{ "bindTransformFeedbackNV", 0, BindTransformFeedbackNV, 0, 0, 0, napi_default, 0 },
		{ "deleteTransformFeedbacksNV", 0, DeleteTransformFeedbacksNV, 0, 0, 0, napi_default, 0 },
		{ "drawTransformFeedbackNV", 0, DrawTransformFeedbackNV, 0, 0, 0, napi_default, 0 },
		{ "genTransformFeedbacksNV", 0, GenTransformFeedbacksNV, 0, 0, 0, napi_default, 0 },
		{ "isTransformFeedbackNV", 0, IsTransformFeedbackNV, 0, 0, 0, napi_default, 0 },
		{ "pauseTransformFeedbackNV", 0, PauseTransformFeedbackNV, 0, 0, 0, napi_default, 0 },
		{ "resumeTransformFeedbackNV", 0, ResumeTransformFeedbackNV, 0, 0, 0, napi_default, 0 },
		{ "vDPAUFiniNV", 0, VDPAUFiniNV, 0, 0, 0, napi_default, 0 },
		{ "vDPAUGetSurfaceivNV", 0, VDPAUGetSurfaceivNV, 0, 0, 0, napi_default, 0 },
		{ "vDPAUInitNV", 0, VDPAUInitNV, 0, 0, 0, napi_default, 0 },
		{ "vDPAUIsSurfaceNV", 0, VDPAUIsSurfaceNV, 0, 0, 0, napi_default, 0 },
		{ "vDPAUMapSurfacesNV", 0, VDPAUMapSurfacesNV, 0, 0, 0, napi_default, 0 },
		{ "vDPAUSurfaceAccessNV", 0, VDPAUSurfaceAccessNV, 0, 0, 0, napi_default, 0 },
		{ "vDPAUUnmapSurfacesNV", 0, VDPAUUnmapSurfacesNV, 0, 0, 0, napi_default, 0 },
		{ "vDPAUUnregisterSurfaceNV", 0, VDPAUUnregisterSurfaceNV, 0, 0, 0, napi_default, 0 },
		{ "flushVertexArrayRangeNV", 0, FlushVertexArrayRangeNV, 0, 0, 0, napi_default, 0 },
		{ "vertexArrayRangeNV", 0, VertexArrayRangeNV, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribLFormatNV", 0, VertexAttribLFormatNV, 0, 0, 0, napi_default, 0 },
		{ "bufferAddressRangeNV", 0, BufferAddressRangeNV, 0, 0, 0, napi_default, 0 },
		{ "colorFormatNV", 0, ColorFormatNV, 0, 0, 0, napi_default, 0 },
		{ "edgeFlagFormatNV", 0, EdgeFlagFormatNV, 0, 0, 0, napi_default, 0 },
		{ "fogCoordFormatNV", 0, FogCoordFormatNV, 0, 0, 0, napi_default, 0 },
		{ "indexFormatNV", 0, IndexFormatNV, 0, 0, 0, napi_default, 0 },
		{ "normalFormatNV", 0, NormalFormatNV, 0, 0, 0, napi_default, 0 },
		{ "secondaryColorFormatNV", 0, SecondaryColorFormatNV, 0, 0, 0, napi_default, 0 },
		{ "texCoordFormatNV", 0, TexCoordFormatNV, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribFormatNV", 0, VertexAttribFormatNV, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribIFormatNV", 0, VertexAttribIFormatNV, 0, 0, 0, napi_default, 0 },
		{ "vertexFormatNV", 0, VertexFormatNV, 0, 0, 0, napi_default, 0 },
		{ "areProgramsResidentNV", 0, AreProgramsResidentNV, 0, 0, 0, napi_default, 0 },
		{ "bindProgramNV", 0, BindProgramNV, 0, 0, 0, napi_default, 0 },
		{ "deleteProgramsNV", 0, DeleteProgramsNV, 0, 0, 0, napi_default, 0 },
		{ "executeProgramNV", 0, ExecuteProgramNV, 0, 0, 0, napi_default, 0 },
		{ "genProgramsNV", 0, GenProgramsNV, 0, 0, 0, napi_default, 0 },
		{ "isProgramNV", 0, IsProgramNV, 0, 0, 0, napi_default, 0 },
		{ "loadProgramNV", 0, LoadProgramNV, 0, 0, 0, napi_default, 0 },
		{ "requestResidentProgramsNV", 0, RequestResidentProgramsNV, 0, 0, 0, napi_default, 0 },
		{ "trackMatrixNV", 0, TrackMatrixNV, 0, 0, 0, napi_default, 0 },
		{ "vertexAttribPointerNV", 0, VertexAttribPointerNV, 0, 0, 0, napi_default, 0 },
		{ "beginVideoCaptureNV", 0, BeginVideoCaptureNV, 0, 0, 0, napi_default, 0 },
		{ "bindVideoCaptureStreamBufferNV", 0, BindVideoCaptureStreamBufferNV, 0, 0, 0, napi_default, 0 },
		{ "bindVideoCaptureStreamTextureNV", 0, BindVideoCaptureStreamTextureNV, 0, 0, 0, napi_default, 0 },
		{ "endVideoCaptureNV", 0, EndVideoCaptureNV, 0, 0, 0, napi_default, 0 },
		{ "videoCaptureNV", 0, VideoCaptureNV, 0, 0, 0, napi_default, 0 },
		{ "videoCaptureStreamParameterdvNV", 0, VideoCaptureStreamParameterdvNV, 0, 0, 0, napi_default, 0 },
		{ "videoCaptureStreamParameterfvNV", 0, VideoCaptureStreamParameterfvNV, 0, 0, 0, napi_default, 0 },
		{ "videoCaptureStreamParameterivNV", 0, VideoCaptureStreamParameterivNV, 0, 0, 0, napi_default, 0 },
		{ "framebufferTextureMultiviewOVR", 0, FramebufferTextureMultiviewOVR, 0, 0, 0, napi_default, 0 },
		{ "alphaFuncx", 0, AlphaFuncx, 0, 0, 0, napi_default, 0 },
		{ "clearColorx", 0, ClearColorx, 0, 0, 0, napi_default, 0 },
		{ "clearDepthx", 0, ClearDepthx, 0, 0, 0, napi_default, 0 },
		{ "depthRangex", 0, DepthRangex, 0, 0, 0, napi_default, 0 },
		{ "fogx", 0, Fogx, 0, 0, 0, napi_default, 0 },
		{ "fogxv", 0, Fogxv, 0, 0, 0, napi_default, 0 },
		{ "frustumf", 0, Frustumf, 0, 0, 0, napi_default, 0 },
		{ "frustumx", 0, Frustumx, 0, 0, 0, napi_default, 0 },
		{ "lightModelx", 0, LightModelx, 0, 0, 0, napi_default, 0 },
		{ "lightModelxv", 0, LightModelxv, 0, 0, 0, napi_default, 0 },
		{ "lightx", 0, Lightx, 0, 0, 0, napi_default, 0 },
		{ "lightxv", 0, Lightxv, 0, 0, 0, napi_default, 0 },
		{ "lineWidthx", 0, LineWidthx, 0, 0, 0, napi_default, 0 },
		{ "loadMatrixx", 0, LoadMatrixx, 0, 0, 0, napi_default, 0 },
		{ "materialx", 0, Materialx, 0, 0, 0, napi_default, 0 },
		{ "materialxv", 0, Materialxv, 0, 0, 0, napi_default, 0 },
		{ "multMatrixx", 0, MultMatrixx, 0, 0, 0, napi_default, 0 },
		{ "orthof", 0, Orthof, 0, 0, 0, napi_default, 0 },
		{ "orthox", 0, Orthox, 0, 0, 0, napi_default, 0 },
		{ "pointSizex", 0, PointSizex, 0, 0, 0, napi_default, 0 },
		{ "polygonOffsetx", 0, PolygonOffsetx, 0, 0, 0, napi_default, 0 },
		{ "rotatex", 0, Rotatex, 0, 0, 0, napi_default, 0 },
		{ "sampleCoveragex", 0, SampleCoveragex, 0, 0, 0, napi_default, 0 },
		{ "scalex", 0, Scalex, 0, 0, 0, napi_default, 0 },
		{ "texEnvx", 0, TexEnvx, 0, 0, 0, napi_default, 0 },
		{ "texEnvxv", 0, TexEnvxv, 0, 0, 0, napi_default, 0 },
		{ "texParameterx", 0, TexParameterx, 0, 0, 0, napi_default, 0 },
		{ "translatex", 0, Translatex, 0, 0, 0, napi_default, 0 },
		{ "clipPlanef", 0, ClipPlanef, 0, 0, 0, napi_default, 0 },
		{ "clipPlanex", 0, ClipPlanex, 0, 0, 0, napi_default, 0 },
		{ "pointParameterx", 0, PointParameterx, 0, 0, 0, napi_default, 0 },
		{ "pointParameterxv", 0, PointParameterxv, 0, 0, 0, napi_default, 0 },
		{ "texParameterxv", 0, TexParameterxv, 0, 0, 0, napi_default, 0 },
		{ "isSupportedREGAL", 0, IsSupportedREGAL, 0, 0, 0, napi_default, 0 },
		{ "logMessageCallbackREGAL", 0, LogMessageCallbackREGAL, 0, 0, 0, napi_default, 0 },
		{ "detailTexFuncSGIS", 0, DetailTexFuncSGIS, 0, 0, 0, napi_default, 0 },
		{ "fogFuncSGIS", 0, FogFuncSGIS, 0, 0, 0, napi_default, 0 },
		{ "sampleMaskSGIS", 0, SampleMaskSGIS, 0, 0, 0, napi_default, 0 },
		{ "samplePatternSGIS", 0, SamplePatternSGIS, 0, 0, 0, napi_default, 0 },
		{ "sharpenTexFuncSGIS", 0, SharpenTexFuncSGIS, 0, 0, 0, napi_default, 0 },
		{ "texFilterFuncSGIS", 0, TexFilterFuncSGIS, 0, 0, 0, napi_default, 0 },
		{ "asyncMarkerSGIX", 0, AsyncMarkerSGIX, 0, 0, 0, napi_default, 0 },
		{ "deleteAsyncMarkersSGIX", 0, DeleteAsyncMarkersSGIX, 0, 0, 0, napi_default, 0 },
		{ "finishAsyncSGIX", 0, FinishAsyncSGIX, 0, 0, 0, napi_default, 0 },
		{ "genAsyncMarkersSGIX", 0, GenAsyncMarkersSGIX, 0, 0, 0, napi_default, 0 },
		{ "isAsyncMarkerSGIX", 0, IsAsyncMarkerSGIX, 0, 0, 0, napi_default, 0 },
		{ "pollAsyncSGIX", 0, PollAsyncSGIX, 0, 0, 0, napi_default, 0 },
		{ "flushRasterSGIX", 0, FlushRasterSGIX, 0, 0, 0, napi_default, 0 },
		{ "textureFogSGIX", 0, TextureFogSGIX, 0, 0, 0, napi_default, 0 },
		{ "fragmentColorMaterialSGIX", 0, FragmentColorMaterialSGIX, 0, 0, 0, napi_default, 0 },
		{ "fragmentLightModelfSGIX", 0, FragmentLightModelfSGIX, 0, 0, 0, napi_default, 0 },
		{ "fragmentLightModelfvSGIX", 0, FragmentLightModelfvSGIX, 0, 0, 0, napi_default, 0 },
		{ "fragmentLightModeliSGIX", 0, FragmentLightModeliSGIX, 0, 0, 0, napi_default, 0 },
		{ "fragmentLightModelivSGIX", 0, FragmentLightModelivSGIX, 0, 0, 0, napi_default, 0 },
		{ "fragmentLightfSGIX", 0, FragmentLightfSGIX, 0, 0, 0, napi_default, 0 },
		{ "fragmentLightfvSGIX", 0, FragmentLightfvSGIX, 0, 0, 0, napi_default, 0 },
		{ "fragmentLightiSGIX", 0, FragmentLightiSGIX, 0, 0, 0, napi_default, 0 },
		{ "fragmentLightivSGIX", 0, FragmentLightivSGIX, 0, 0, 0, napi_default, 0 },
		{ "fragmentMaterialfSGIX", 0, FragmentMaterialfSGIX, 0, 0, 0, napi_default, 0 },
		{ "fragmentMaterialfvSGIX", 0, FragmentMaterialfvSGIX, 0, 0, 0, napi_default, 0 },
		{ "fragmentMaterialiSGIX", 0, FragmentMaterialiSGIX, 0, 0, 0, napi_default, 0 },
		{ "fragmentMaterialivSGIX", 0, FragmentMaterialivSGIX, 0, 0, 0, napi_default, 0 },
		{ "frameZoomSGIX", 0, FrameZoomSGIX, 0, 0, 0, napi_default, 0 },
		{ "pixelTexGenSGIX", 0, PixelTexGenSGIX, 0, 0, 0, napi_default, 0 },
		{ "referencePlaneSGIX", 0, ReferencePlaneSGIX, 0, 0, 0, napi_default, 0 },
		{ "spriteParameterfSGIX", 0, SpriteParameterfSGIX, 0, 0, 0, napi_default, 0 },
		{ "spriteParameterfvSGIX", 0, SpriteParameterfvSGIX, 0, 0, 0, napi_default, 0 },
		{ "spriteParameteriSGIX", 0, SpriteParameteriSGIX, 0, 0, 0, napi_default, 0 },
		{ "spriteParameterivSGIX", 0, SpriteParameterivSGIX, 0, 0, 0, napi_default, 0 },
		{ "tagSampleBufferSGIX", 0, TagSampleBufferSGIX, 0, 0, 0, napi_default, 0 },
		{ "colorTableParameterfvSGI", 0, ColorTableParameterfvSGI, 0, 0, 0, napi_default, 0 },
		{ "colorTableParameterivSGI", 0, ColorTableParameterivSGI, 0, 0, 0, napi_default, 0 },
		{ "colorTableSGI", 0, ColorTableSGI, 0, 0, 0, napi_default, 0 },
		{ "copyColorTableSGI", 0, CopyColorTableSGI, 0, 0, 0, napi_default, 0 },
		{ "finishTextureSUNX", 0, FinishTextureSUNX, 0, 0, 0, napi_default, 0 },
		{ "globalAlphaFactorbSUN", 0, GlobalAlphaFactorbSUN, 0, 0, 0, napi_default, 0 },
		{ "globalAlphaFactordSUN", 0, GlobalAlphaFactordSUN, 0, 0, 0, napi_default, 0 },
		{ "globalAlphaFactorfSUN", 0, GlobalAlphaFactorfSUN, 0, 0, 0, napi_default, 0 },
		{ "globalAlphaFactoriSUN", 0, GlobalAlphaFactoriSUN, 0, 0, 0, napi_default, 0 },
		{ "globalAlphaFactorsSUN", 0, GlobalAlphaFactorsSUN, 0, 0, 0, napi_default, 0 },
		{ "globalAlphaFactorubSUN", 0, GlobalAlphaFactorubSUN, 0, 0, 0, napi_default, 0 },
		{ "globalAlphaFactoruiSUN", 0, GlobalAlphaFactoruiSUN, 0, 0, 0, napi_default, 0 },
		{ "globalAlphaFactorusSUN", 0, GlobalAlphaFactorusSUN, 0, 0, 0, napi_default, 0 },
		{ "readVideoPixelsSUN", 0, ReadVideoPixelsSUN, 0, 0, 0, napi_default, 0 },
		{ "replacementCodePointerSUN", 0, ReplacementCodePointerSUN, 0, 0, 0, napi_default, 0 },
		{ "replacementCodeubSUN", 0, ReplacementCodeubSUN, 0, 0, 0, napi_default, 0 },
		{ "replacementCodeubvSUN", 0, ReplacementCodeubvSUN, 0, 0, 0, napi_default, 0 },
		{ "replacementCodeuiSUN", 0, ReplacementCodeuiSUN, 0, 0, 0, napi_default, 0 },
		{ "replacementCodeuivSUN", 0, ReplacementCodeuivSUN, 0, 0, 0, napi_default, 0 },
		{ "replacementCodeusSUN", 0, ReplacementCodeusSUN, 0, 0, 0, napi_default, 0 },
		{ "replacementCodeusvSUN", 0, ReplacementCodeusvSUN, 0, 0, 0, napi_default, 0 },
		{ "addSwapHintRectWIN", 0, AddSwapHintRectWIN, 0, 0, 0, napi_default, 0 }
	};
	status = napi_define_properties(env, exports, 1086, properties);
	//assert(status == napi_ok);
	return exports;
}
NAPI_MODULE(NODE_GYP_MODULE_NAME, init)