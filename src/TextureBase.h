#pragma once

#include <glad/glad.h>

#include "GLResource.h"

class TextureBase: public GLResource
{
public:

	GLuint GetTextureHandle() const;

protected:

	void Bind(GLenum textureTarget, GLuint textureBinding) const;

	// This class is not pure virtual and can therefore be constructed.
	// This, however, should not be possible so the CTOR/DTOR are protected.

	TextureBase();
	virtual ~TextureBase();

public:

	static int GetMaxNumberOfCombinedTextureUnits();

private:

	static int maxNumberOfCombinedTextureUnits;

};
