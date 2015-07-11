#pragma once

#include "FrameBuffer.h"
#include "Texture.h"

class GBuffer : public FrameBuffer
{
public:
	GBuffer(int renderWidth, int renderHeight)
		: FrameBuffer(false)
		, albedo(renderWidth, renderHeight, GL_RGB, GL_RGB8, GL_CLAMP_TO_BORDER, GL_LINEAR, GL_LINEAR)
		, normal(renderWidth, renderHeight, GL_RGB, GL_RGB8, GL_CLAMP_TO_BORDER, GL_NEAREST, GL_NEAREST)
		, depth(renderWidth, renderHeight, GL_DEPTH_COMPONENT, GL_DEPTH_COMPONENT24, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST)
	{
		this->AttachTexture(albedo, GL_COLOR_ATTACHMENT0);
		this->AttachTexture(normal, GL_COLOR_ATTACHMENT1);
		this->AttachTexture(depth, GL_DEPTH_ATTACHMENT);

		// Assign the correct draw buffers for this FrameBuffer
		const GLenum drawBuffers[2] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1 };
		glNamedFramebufferDrawBuffers(this->frameBufferHandle, 2, drawBuffers);
	}

	virtual ~GBuffer() {}

	inline Texture& GetAlbedoTexture() { return albedo; }
	inline Texture& GetNormalTexture() { return normal; }
	inline Texture& GetDepthTexture() { return depth; }

private:
	Texture albedo;
	Texture normal;
	Texture depth;
};
