#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

class GL
{
private:

	class ContextState
	{
	public:

		// Reads the current GL driver state into this object
		void FetchCurrentGLState();

		// TODO: GetDebugString()
		// Describes the current state in a nice table

	private:

		// Helper for getting enums (since there is no glGetEnum)
		void GetEnum(GLenum key, GLenum *value);

	public:

		// Add more as needed

		GLint viewportDims[4];

		GLfloat clearColor[4];

		GLboolean blendingEnabled;
		GLenum blendEquationRGB;
		GLenum blendEquationAlpha;
		GLenum blendSrcRGB;
		GLenum blendSrcAlpha;
		GLenum blendDstRGB;
		GLenum blendDstAlpha;

		GLboolean depthTest;
		GLenum depthFunction;
		GLboolean depthMask;
		GLfloat clearDepth;

		GLboolean faceCullingEnabled;
		GLenum frontFace;
		GLenum cullFace;
		
	};

public:

	//
	// Should be called before any other function in the GL scope to make proper use of the caching and optimizations!
	//
	static inline void FetchCurrentGLState() { return state.FetchCurrentGLState(); }

	// Actions
	static inline void Clear(GLenum bufferBits) { glClear(bufferBits); }

	// Viewport
	static void SetViewport(int x, int y, unsigned int width, unsigned int height);

	// Colors
	static void GetClearColor(float *r, float *g, float *b, float *a);
	static void SetClearColor(float r, float g, float b, float a);

	// Blending
	static inline bool IsBlending() { return state.blendingEnabled == GL_TRUE; }
	static void SetBlending(bool enabled);
	static void GetBlendEquation(GLenum *modeRGB, GLenum *modeAlpha);
	static void SetBlendEquation(GLenum modeRGB, GLenum modeAlpha);
	static void GetBlendFunction(GLenum *srcRgb, GLenum *dstRgb, GLenum *srcAlpha, GLenum *dstAlpha);
	static void SetBlendFunction(GLenum srcRgb, GLenum dstRgb, GLenum srcAlpha, GLenum dstAlpha);

	// Depth
	static inline bool IsDepthTesting() { return state.depthTest == GL_TRUE; }
	static void SetDepthTest(bool enabled);
	static inline GLenum GetDepthFunction() { return state.depthFunction; }
	static void SetDepthFunction(GLenum function);
	static inline bool GetDepthMask() { return state.depthMask == GL_TRUE; }
	static void SetDepthMask(bool mask);
	static inline float GetClearDepth() { return state.clearDepth; }
	static void SetClearDepth(float depth);

	// Culling & faces
	static inline bool IsFaceCulling() { return state.faceCullingEnabled == GL_TRUE; }
	static void SetFaceCulling(bool enabled);
	static inline GLenum GetFrontFace() { return state.frontFace; }
	static void SetFrontFace(GLenum frontFaceWinding);
	static inline GLenum GetCullFace() { return state.cullFace; }
	static void SetCullFace(GLenum face);

	// Generic functions (should be avoided if possible since they don't do any caching and similar optimisations)
	static inline void Enable(GLenum key) { glEnable(key); }
	static inline void Disable(GLenum key) { glDisable(key); }
	static inline void EnableOrDisable(GLenum key, bool enable) { (enable) ? Enable(key) : Disable(key); }

private:

	static ContextState state;

	// Global GL state -> static access
	GL() {}
	~GL() {}

};
