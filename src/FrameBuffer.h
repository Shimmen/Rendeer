#pragma once

#include <vector>
#include <map>

#include <glad/glad.h>

#include "GLResource.h"

class Texture2D;

class FrameBuffer: public GLResource
{
public:

	FrameBuffer();
	virtual ~FrameBuffer();

	void Attach(const Texture2D *texture, GLenum attachment);
	const Texture2D *GetAttached(GLenum attachment) const;

	bool IsComplete(GLenum *statusIfNotComplete = nullptr) const;

	void BindAsDrawFrameBuffer(bool setViewport = true, bool setDrawBuffers = true) const;
	void BindAsReadFrameBuffer() const;

protected:

	std::vector<GLenum> drawBuffers;
	std::map<GLenum, const Texture2D *> attachments;

};
