#include "FrameBuffer.h"

#include "Texture.h"

FrameBuffer::FrameBuffer(bool attachDefaultDepthStencilRenderBuffer)
{
	glGenFramebuffers(1, &frameBufferHandle);
}

FrameBuffer::~FrameBuffer()
{
	glDeleteFramebuffers(1, &frameBufferHandle);
}

void FrameBuffer::AttachTexture(const Texture& texture, GLenum attatchment) const
{
	glBindFramebuffer(GL_FRAMEBUFFER, frameBufferHandle);

	// TODO: Will the last variable, the 0 that is the mipmap level ever be used?
	glFramebufferTexture2D(GL_FRAMEBUFFER, attatchment, GL_TEXTURE_2D, texture.GetHandle(), 0);
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