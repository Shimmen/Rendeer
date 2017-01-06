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

void FrameBuffer::Attach(const Texture2D *texture, GLenum attachment)
{
	// Check sizes to see if they match. It's not a requirement, but I have a feeling this will save me from some bugs...
	if (attachments.size() != 0)
	{
		const auto first = attachments.begin()->second;
		assert(first->GetWidth() == texture->GetWidth());
		assert(first->GetHeight() == texture->GetHeight());
	}

	BindAsDrawFrameBuffer(false, false);
	glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, attachment, GL_TEXTURE_2D, texture->GetTextureHandle(), 0);

	// Store attachment textures and draw buffers
	attachments[attachment] = texture;
	if (attachment >= GL_COLOR_ATTACHMENT0 && attachment <= GL_COLOR_ATTACHMENT31)
	{
		drawBuffers.emplace_back(attachment);
	}
}

bool FrameBuffer::IsComplete(GLenum *statusIfNotComplete) const
{
	BindAsDrawFrameBuffer(false, false);
	
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

void FrameBuffer::BindAsDrawFrameBuffer(bool setViewport, bool setDrawBuffers) const
{
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, frameBufferHandle);

	if (setViewport)
	{
		const auto first = attachments.begin()->second;
		glViewport(0, 0, first->GetWidth(), first->GetHeight());
	}

	if (setDrawBuffers)
	{
		glDrawBuffers(static_cast<GLsizei>(drawBuffers.size()), &drawBuffers[0]);
	}
}

void FrameBuffer::BindAsReadFrameBuffer() const
{
	glBindFramebuffer(GL_READ_FRAMEBUFFER, frameBufferHandle);
}

const Texture2D *FrameBuffer::GetAttached(GLenum attachment) const
{
	auto result = attachments.find(attachment);
	if (result != attachments.end())
	{
		return result->second;
	}

	return nullptr;
}
