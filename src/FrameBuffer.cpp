#include "FrameBuffer.h"

#include "GLState.h"
#include "Texture2D.h"

/*static*/ GLuint FrameBuffer::lastBoundDraw = 0;
/*static*/ GLuint FrameBuffer::lastBoundRead = 0;

FrameBuffer::FrameBuffer()
{
	glGenFramebuffers(1, &handle);
}

FrameBuffer::~FrameBuffer()
{
	glDeleteFramebuffers(1, &handle);
}

void FrameBuffer::Attach(const Texture2D *texture, GLenum attachment, GLint mipLevel)
{
	// Check sizes to see if they match. It's not a requirement, but I have a feeling this will save me from some bugs...
	if (attachments.size() != 0)
	{
		const auto first = attachments.begin()->second;
		assert(first->GetWidth() == texture->GetWidth());
		assert(first->GetHeight() == texture->GetHeight());
	}

	BindAsDrawFrameBuffer(false, false);
	glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, attachment, GL_TEXTURE_2D, texture->GetTextureHandle(), mipLevel);

	// Store attachment textures and draw buffers
	attachments[attachment] = texture;
	if (attachment >= GL_COLOR_ATTACHMENT0 && attachment <= GL_COLOR_ATTACHMENT31)
	{
		drawBuffers.emplace_back(attachment);
	}
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

int FrameBuffer::GetNumAttached() const
{
	return attachments.size();
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
	if (handle != lastBoundDraw)
	{
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, handle);
		assert(glIsFramebuffer(handle));
		lastBoundDraw = handle;
	}

	// Always set viewport and draw buffers if requested, even if the correct frame buffer is bound.
	// We assume that GL_DRAW_FRAMEBUFFER is only bound from this function, but glDrawBuffers and
	// glViewport are not *directly* connected to the function of a frame buffer, so they might be
	// manipulated/called outside of our scope.

	if (setViewport)
	{
		const auto first = attachments.begin()->second;
		GL::SetViewport(0, 0, first->GetWidth(), first->GetHeight());
	}

	if (setDrawBuffers && drawBuffers.size() > 0)
	{
		glDrawBuffers(static_cast<GLsizei>(drawBuffers.size()), &drawBuffers[0]);
	}
}

void FrameBuffer::BindAsReadFrameBuffer() const
{
	if (handle != lastBoundRead)
	{
		glBindFramebuffer(GL_READ_FRAMEBUFFER, handle);
		assert(glIsFramebuffer(handle));
		lastBoundRead = handle;
	}
}
