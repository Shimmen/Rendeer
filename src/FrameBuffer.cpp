#include "FrameBuffer.h"

#include "Texture2D.h"

FrameBuffer::FrameBuffer()
{
	glGenFramebuffers(1, &frameBufferHandle);
}

FrameBuffer::~FrameBuffer()
{
	glDeleteFramebuffers(1, &frameBufferHandle);
}

void FrameBuffer::AttachTexture(const Texture2D& texture, GLenum attatchment) const
{
	if (attachedTexturesCount == 0)
	{
		attachedTextureWidth = texture.GetWidth();
		attachedTextureHeight = texture.GetHeight();
	}
	else
	{
		assert(texture.GetWidth() == attachedTextureWidth);
		assert(texture.GetHeight() == attachedTextureHeight);
	}

	GLint lastBoundFramebuffer;
	glGetIntegerv(GL_FRAMEBUFFER_BINDING, &lastBoundFramebuffer);

	glBindFramebuffer(GL_FRAMEBUFFER, frameBufferHandle);
	glFramebufferTexture2D(GL_FRAMEBUFFER, attatchment, GL_TEXTURE_2D, texture.GetTextureHandle(), 0);

	glBindFramebuffer(GL_FRAMEBUFFER, static_cast<GLuint>(lastBoundFramebuffer));

	attachedTexturesCount++;
}

void FrameBuffer::SetDrawBuffers(const std::vector<GLenum> drawBuffers) const
{
	BindAsDrawFrameBuffer();
	glDrawBuffers((GLsizei)drawBuffers.size(), &drawBuffers[0]);
	// Previous call, make sure to keep track of the currently bound framebuffer!
	//glNamedFramebufferDrawBuffers(frameBufferHandle, (GLsizei)drawBuffers.size(), &drawBuffers[0]);
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

void FrameBuffer::BindAsDrawFrameBuffer() const
{
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, frameBufferHandle);
	glViewport(0, 0, attachedTextureWidth, attachedTextureHeight);
}

void FrameBuffer::BindAsReadFrameBuffer() const
{
	glBindFramebuffer(GL_READ_FRAMEBUFFER, frameBufferHandle);
	glViewport(0, 0, attachedTextureWidth, attachedTextureHeight);
}
