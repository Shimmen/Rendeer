#include "GBuffer.h"

#include "Shader.h"
#include "Logger.h"

GBuffer::GBuffer(int renderWidth, int renderHeight)
	: frameBuffer{}
	, albedo{ renderWidth, renderHeight, GL_RGB, GL_RGB8, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST }
	, normal{ renderWidth, renderHeight, GL_RGB, GL_RGB16, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST }
	, material{ renderWidth, renderHeight, GL_RGBA, GL_RGBA16F, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST }
	, depth{renderWidth, renderHeight, GL_DEPTH_COMPONENT, GL_DEPTH_COMPONENT16, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST}
{
	frameBuffer.Attach(&albedo, GL_COLOR_ATTACHMENT0);
	frameBuffer.Attach(&normal, GL_COLOR_ATTACHMENT1);
	frameBuffer.Attach(&material, GL_COLOR_ATTACHMENT2);
	frameBuffer.Attach(&depth, GL_DEPTH_ATTACHMENT);

	GLenum reason = 0;
	if (!frameBuffer.IsComplete(&reason))
	{
		Logger::Log("Error: GBuffer framebuffer is incomplete! Reason: %#X", reason);
	}
}

void GBuffer::BindAsRenderTarget() const
{
	frameBuffer.BindAsDrawFrameBuffer();
}

void GBuffer::BindAsUniform(const Shader& lightShader) const
{
	lightShader.Bind();

	// Bind at the highest texture units so it won't collide with other stuff
	int numTextureUnits = Texture2D::GetMaxNumberOfCombinedTextureUnits();
	int currentUnit = numTextureUnits - 1;

	albedo.Bind(currentUnit);
	lightShader.SetUniform("u_albedo", currentUnit--);

	normal.Bind(currentUnit);
	lightShader.SetUniform("u_normals", currentUnit--);

	material.Bind(currentUnit);
	lightShader.SetUniform("u_material", currentUnit--);

	depth.Bind(currentUnit);
	lightShader.SetUniform("u_depth", currentUnit--);
}

const FrameBuffer& GBuffer::GetInternalFrameBuffer() const
{
	return frameBuffer;
}
