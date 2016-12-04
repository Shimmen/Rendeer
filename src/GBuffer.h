#pragma once

#include "FrameBuffer.h"
#include "Texture2D.h"

class Shader;

class GBuffer
{
public:

	GBuffer(int renderWidth, int renderHeight);
	virtual ~GBuffer();

	void BindAsRenderTarget() const;
	void BindAsUniform(const Shader& lightShader) const;

private: // TODO: Make private?

	FrameBuffer frameBuffer;
	Texture2D albedo;
	Texture2D normal;
	Texture2D material;
	Texture2D depth;

};
