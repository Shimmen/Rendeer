#include "GBuffer.h"

#include "Shader.h"

GBuffer::GBuffer(int renderWidth, int renderHeight)
	: frameBuffer{}
	, albedo{ renderWidth, renderHeight, GL_RGB, GL_RGB8, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST }
	, normal{ renderWidth, renderHeight, GL_RGB, GL_RGB16, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST }
	, material{ renderWidth, renderHeight, GL_RGBA, GL_RGBA16F, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST }
	, depth{renderWidth, renderHeight, GL_DEPTH_COMPONENT, GL_DEPTH_COMPONENT16, GL_CLAMP_TO_EDGE, GL_NEAREST, GL_NEAREST}
{
	frameBuffer.AttachTexture(albedo, GL_COLOR_ATTACHMENT0);
	frameBuffer.AttachTexture(normal, GL_COLOR_ATTACHMENT1);
	frameBuffer.AttachTexture(material, GL_COLOR_ATTACHMENT2);
	frameBuffer.AttachTexture(depth, GL_DEPTH_ATTACHMENT);
	frameBuffer.SetDrawBuffers(std::vector<GLenum>{GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2});

	GLenum reason = 0;
	if (!frameBuffer.IsComplete(&reason))
	{
		std::cout << "Error: G Buffer framebuffer is incomplete!\nReason: " << reason << std::endl;
	}
}

GBuffer::~GBuffer()
{
}

void GBuffer::BindAsRenderTarget() const
{
	frameBuffer.BindAsDrawFrameBuffer();
}

void GBuffer::BindAsUniform(const Shader& lightShader) const
{
	lightShader.Bind();

	albedo.Bind(10);
	lightShader.SetUniform("u_albedo", 10);

	normal.Bind(11);
	lightShader.SetUniform("u_normals", 11);

	material.Bind(12);
	lightShader.SetUniform("u_material", 12);
	
	depth.Bind(13);
	lightShader.SetUniform("u_depth", 13);
}
