#include "TextureBase.h"

#include <cassert>

GLuint TextureBase::GetTextureHandle() const
{
	return this->textureHandle;
}

TextureBase::TextureBase()
{
	glGenTextures(1, &this->textureHandle);
}

TextureBase::~TextureBase()
{
	glDeleteTextures(1, &this->textureHandle);
}

void TextureBase::Bind(GLenum textureBinding, GLuint textureTarget) const
{
	assert(textureTarget >= 0 && textureTarget < GetMaxNumberOfCombinedTextureUnits());
	glActiveTexture(GL_TEXTURE0 + textureTarget);
	glBindTexture(textureBinding, this->textureHandle);
}

int TextureBase::GetMaxNumberOfCombinedTextureUnits()
{
	if (TextureBase::maxNumberOfCombinedTextureUnits == -1)
	{
		GLint count;
        glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &count);
		//glGetInteger64v(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &count); // TODO/BUG: Is this available on Windows now?
		TextureBase::maxNumberOfCombinedTextureUnits = static_cast<int>(count);
	}

	return TextureBase::maxNumberOfCombinedTextureUnits;
}

/* static */ int TextureBase::maxNumberOfCombinedTextureUnits{ -1 };

