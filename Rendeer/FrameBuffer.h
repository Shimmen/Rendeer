#pragma once

#include <vector>

#include <glad/glad.h>

class Texture;

class FrameBuffer
{
public:

	FrameBuffer();
	virtual ~FrameBuffer();

	void AttachTexture(const Texture& texture, GLenum attatchment) const;
	void SetDrawBuffers(const std::vector<GLenum> drawBuffers) const;

	bool IsComplete(GLenum *statusIfNotComplete = nullptr) const;

	inline void BindAsDrawFrameBuffer() const
	{
		glBindFramebuffer(GL_DRAW_FRAMEBUFFER, frameBufferHandle);
	}

	inline void BindAsReadFrameBuffer() const
	{
		glBindFramebuffer(GL_READ_FRAMEBUFFER, frameBufferHandle);
	}

protected:

	GLuint frameBufferHandle;

};
