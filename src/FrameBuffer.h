#pragma once

#include <vector>

#include <glad2/glad.h>

class Texture2D;

class FrameBuffer
{
public:

	FrameBuffer();
	virtual ~FrameBuffer();

	void AttachTexture(const Texture2D& texture, GLenum attatchment) const;
	void SetDrawBuffers(const std::vector<GLenum> drawBuffers) const;

	bool IsComplete(GLenum *statusIfNotComplete = nullptr) const;

	void BindAsDrawFrameBuffer() const;
	void BindAsReadFrameBuffer() const;

protected:

	GLuint frameBufferHandle;

	mutable int attachedTexturesCount{0};
	mutable int attachedTextureWidth{0};
	mutable int attachedTextureHeight{0};

private:

	FrameBuffer(FrameBuffer& other) = delete;
	FrameBuffer& operator=(FrameBuffer& other) = delete;

};
