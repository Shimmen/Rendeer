#include "GLState.h"

#include <cassert>

// To make it more clear (from only looking at the cpp file) if the function is static or not
#define STATIC

/////////////////////////////////////////

void GL::ContextState::GetEnum(GLenum key, GLenum *value)
{
	GLint val;
	glGetIntegerv(key, &val);
	*value = static_cast<GLenum>(val);
}

void GL::ContextState::FetchCurrentGLState()
{
	assert(glGetError() == GL_NO_ERROR);

	glGetIntegerv(GL_VIEWPORT, viewportDims);

	glGetFloatv(GL_COLOR_CLEAR_VALUE, clearColor);

	glGetBooleanv(GL_BLEND, &blendingEnabled);
	GetEnum(GL_BLEND_EQUATION_RGB, &blendEquationRGB);
	GetEnum(GL_BLEND_EQUATION_ALPHA, &blendEquationAlpha);
	GetEnum(GL_BLEND_SRC_RGB, &blendSrcRGB);
	GetEnum(GL_BLEND_SRC_ALPHA, &blendSrcAlpha);
	GetEnum(GL_BLEND_DST_RGB, &blendDstRGB);
	GetEnum(GL_BLEND_DST_ALPHA, &blendDstAlpha);

	glGetBooleanv(GL_DEPTH_TEST, &depthTest);
	GetEnum(GL_DEPTH_FUNC, &depthFunction);
	glGetBooleanv(GL_DEPTH_WRITEMASK, &depthMask);
	glGetFloatv(GL_DEPTH_CLEAR_VALUE, &clearDepth);

	glGetBooleanv(GL_CULL_FACE, &faceCullingEnabled);
	GetEnum(GL_CULL_FACE_MODE, &cullFace);
	GetEnum(GL_FRONT_FACE, &frontFace);

	assert(glGetError() == GL_NO_ERROR);
}

/////////////////////////////////////////

STATIC GL::ContextState GL::state{};

STATIC void GL::SetViewport(int x, int y, unsigned int width, unsigned int height)
{
	if (state.viewportDims[0] != x || state.viewportDims[1] != y || state.viewportDims[2] != width || state.viewportDims[3] != height)
	{
		state.viewportDims[0] = x;
		state.viewportDims[1] = y;
		state.viewportDims[2] = static_cast<int>(width);
		state.viewportDims[3] = static_cast<int>(height);
		glViewport(x, y, width, height);
	}
}

STATIC void GL::GetClearColor(float *r, float *g, float *b, float *a)
{
	*r = state.clearColor[0];
	*g = state.clearColor[1];
	*b = state.clearColor[2];
	*a = state.clearColor[3];
}

STATIC void GL::SetClearColor(float r, float g, float b, float a)
{
	if (r != state.clearColor[0] || g != state.clearColor[1] || b != state.clearColor[2] || a != state.clearColor[3])
	{
		state.clearColor[0] = r;
		state.clearColor[1] = g;
		state.clearColor[2] = b;
		state.clearColor[3] = a;
		glClearColor(r, g, b, a);
	}
}

STATIC void GL::GetBlendEquation(GLenum *modeRGB, GLenum *modeAlpha)
{
	*modeRGB = state.blendEquationRGB;
	*modeAlpha = state.blendEquationAlpha;
}

STATIC void GL::SetBlendEquation(GLenum modeRGB, GLenum modeAlpha)
{
	if (state.blendEquationRGB != modeRGB || state.blendEquationAlpha != modeAlpha)
	{
		state.blendEquationRGB = modeRGB;
		state.blendEquationAlpha = modeAlpha;
		glBlendEquationSeparate(modeRGB, modeAlpha);
	}
}

STATIC void GL::GetBlendFunction(GLenum *srcRGB, GLenum *dstRGB, GLenum *srcAlpha, GLenum *dstAlpha)
{
	*srcRGB = state.blendSrcRGB;
	*dstRGB = state.blendDstRGB;
	*srcAlpha = state.blendSrcAlpha;
	*dstAlpha = state.blendDstAlpha;
}

STATIC void GL::SetBlendFunction(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
	if (state.blendSrcRGB != srcRGB || state.blendDstRGB != dstRGB || state.blendSrcAlpha != srcAlpha || state.blendDstAlpha != dstRGB)
	{
		state.blendSrcRGB = srcRGB;
		state.blendDstRGB = dstRGB;
		state.blendSrcAlpha = srcAlpha;
		state.blendDstAlpha = dstAlpha;
		glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
	}
}

STATIC void GL::SetBlendingEnabled(bool enabled)
{
	if (state.blendingEnabled != enabled)
	{
		state.blendingEnabled = enabled;
		EnableOrDisable(GL_BLEND, enabled);
	}
}

STATIC void GL::SetDepthTestEnabled(bool enabled)
{
	if (state.depthTest != enabled)
	{
		state.depthTest = enabled;
		EnableOrDisable(GL_DEPTH_TEST, enabled);
	}
}

STATIC void GL::SetDepthFunction(GLenum function)
{
	if (state.depthFunction != function)
	{
		state.depthFunction = function;
		glDepthFunc(function);
	}
}

STATIC void GL::SetDepthMask(bool mask)
{
	if (state.depthMask != mask)
	{
		state.depthMask = mask;
		glDepthMask(mask);
	}
}

STATIC void GL::SetClearDepth(float depth)
{
	if (state.clearDepth != depth)
	{
		state.clearDepth = depth;
		glClearDepth(depth);
	}
}

STATIC void GL::SetFaceCullingEnabled(bool enabled)
{
	if (state.faceCullingEnabled != enabled)
	{
		state.faceCullingEnabled = enabled;
		EnableOrDisable(GL_CULL_FACE, enabled);
	}
}

STATIC void GL::SetFrontFace(GLenum frontFaceWinding)
{
	if (state.frontFace != frontFaceWinding)
	{
		state.frontFace = frontFaceWinding;
		glFrontFace(frontFaceWinding);
	}
}

STATIC void GL::SetCullFace(GLenum face)
{
	if (state.cullFace != face)
	{
		state.cullFace = face;
		glCullFace(face);
	}
}
