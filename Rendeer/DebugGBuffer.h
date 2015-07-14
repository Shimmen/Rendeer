#pragma once

#include "FrameBuffer.h"
#include "Texture.h"

class DebugGBuffer : public FrameBuffer
{
public:
	DebugGBuffer(int renderWidth, int renderHeight)
		: FrameBuffer()
		, albedo(renderWidth, renderHeight, GL_RGB, GL_RGB8, GL_CLAMP_TO_BORDER, GL_LINEAR, GL_LINEAR)
		, normal(renderWidth, renderHeight, GL_RGB, GL_RGB16, GL_CLAMP_TO_BORDER, GL_NEAREST, GL_NEAREST)
		, position(renderWidth, renderHeight, GL_RGB, GL_RGB32F, GL_REPEAT, GL_LINEAR, GL_LINEAR)
		, depth(renderWidth, renderHeight, GL_DEPTH_COMPONENT, GL_DEPTH_COMPONENT24, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST)
	{
		this->AttachTexture(albedo, GL_COLOR_ATTACHMENT0);
		this->AttachTexture(normal, GL_COLOR_ATTACHMENT1);
		this->AttachTexture(position, GL_COLOR_ATTACHMENT2);
		this->AttachTexture(depth, GL_DEPTH_ATTACHMENT);

		// Assign the correct draw buffers for this FrameBuffer
		const GLenum drawBuffers[3] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2 };
		glNamedFramebufferDrawBuffers(this->frameBufferHandle, 3, drawBuffers);
	}

	virtual ~DebugGBuffer() {}

	inline Texture& GetAlbedoTexture() { return albedo; }
	inline Texture& GetNormalTexture() { return normal; }
	inline Texture& GetPositionTexture() { return position; }
	inline Texture& GetDepthTexture() { return depth; }

private:

	Texture albedo;
	Texture normal;
	Texture position;
	Texture depth;
};
