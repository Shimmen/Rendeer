#pragma once

#include <glad/glad.h>

#include <cassert>

class ITexture
{
protected:

	// This class is not pure virtual and can therefore be constructed.
	// This, however, should not be possible so the CTOR/DTOR are protected.

	ITexture()
	{
		glGenTextures(1, &this->textureHandle);
	}

	virtual ~ITexture()
	{
		glDeleteTextures(1, &this->textureHandle);
	}

	inline void BindTexture(GLenum textureBinding, int textureTarget) const
	{
		assert(textureTarget >= 0 && textureTarget < GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS);
		glActiveTexture(GL_TEXTURE0 + textureTarget);
		glBindTexture(textureBinding, this->textureHandle);
	}

public:

	inline GLuint GetHandle() const
	{
		return textureHandle;
	}

protected:

	GLuint textureHandle;

};
