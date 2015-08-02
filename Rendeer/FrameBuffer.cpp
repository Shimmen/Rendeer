#include "FrameBuffer.h"

#include "glad/glad.h"

#include "Texture.h"

FrameBuffer::FrameBuffer()
{
	glGenFramebuffers(1, &frameBufferHandle);
}

FrameBuffer::~FrameBuffer()
{
	glDeleteFramebuffers(1, &frameBufferHandle);
}

void FrameBuffer::AttachTexture(const Texture& texture, GLenum attatchment) const
{
	GLint lastBoundFramebuffer;
	glGetIntegeri_v(GL_FRAMEBUFFER_BINDING, 0, &lastBoundFramebuffer);

	glBindFramebuffer(GL_FRAMEBUFFER, frameBufferHandle);
	glFramebufferTexture2D(GL_FRAMEBUFFER, attatchment, GL_TEXTURE_2D, texture.GetHandle(), 0);

	glBindFramebuffer(GL_FRAMEBUFFER, lastBoundFramebuffer);
}

void FrameBuffer::SetDrawBuffers(const std::vector<GLenum> drawBuffers) const
{
	glNamedFramebufferDrawBuffers(frameBufferHandle, (GLsizei)drawBuffers.size(), &drawBuffers[0]);
}

bool FrameBuffer::IsComplete(GLenum *statusIfNotComplete) const
{
	glBindFramebuffer(GL_FRAMEBUFFER, frameBufferHandle);
	
	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	if (status != GL_FRAMEBUFFER_COMPLETE)
	{
		if (statusIfNotComplete != nullptr)
		{
			*statusIfNotComplete = status;
		}

		return false;
	}

	return true;
}
