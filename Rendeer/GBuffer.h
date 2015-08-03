#pragma once

#include "FrameBuffer.h"
#include "Texture.h"

class Shader;

class GBuffer
{
public:

	GBuffer(int renderWidth, int renderHeight);
	virtual ~GBuffer();

	void BindAsRenderTarget() const;
	void BindAsUniform(const Shader& lightShader) const;

private:

	FrameBuffer frameBuffer;
	Texture albedo;
	Texture normal;
	Texture material;
	Texture depth;

};
