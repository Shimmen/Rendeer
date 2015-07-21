#pragma once

#include "FrameBuffer.h"
#include "Texture.h"

class GBuffer : public FrameBuffer
{
public:
	GBuffer(int renderWidth, int renderHeight)
		: FrameBuffer()
		, albedo(renderWidth, renderHeight, GL_RGB, GL_RGB8, GL_CLAMP_TO_EDGE, GL_LINEAR, GL_LINEAR)
		, normal(renderWidth, renderHeight, GL_RGB, GL_RGB16, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST)
		, depth(renderWidth, renderHeight, GL_DEPTH_COMPONENT, GL_DEPTH_COMPONENT16, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST)
	{
		this->AttachTexture(albedo, GL_COLOR_ATTACHMENT0);
		this->AttachTexture(normal, GL_COLOR_ATTACHMENT1);
		this->AttachTexture(depth, GL_DEPTH_ATTACHMENT);

		// Assign the correct draw buffers for this FrameBuffer
		const GLenum drawBuffers[2] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1 };
		glNamedFramebufferDrawBuffers(this->frameBufferHandle, 2, drawBuffers);
	}

	virtual ~GBuffer() {}

	inline const Texture& GetAlbedoTexture() const { return albedo; }
	inline const Texture& GetNormalTexture() const { return normal; }
	inline const Texture& GetDepthTexture() const { return depth; }

	inline void BindForLightShader(Shader& lightShader) const
	{
		// TODO: Use uniform buffer objects!

		GetAlbedoTexture().Bind(10);
		GetNormalTexture().Bind(11);
		GetDepthTexture().Bind(12);

		lightShader.Bind();

		lightShader.SetUniform("u_albedo", 10);
		lightShader.SetUniform("u_normals", 11);
		lightShader.SetUniform("u_depth", 12);
	}

private:
	Texture albedo;
	Texture normal;
	Texture depth;
};
