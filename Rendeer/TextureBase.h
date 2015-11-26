#pragma once

#include <glad/glad.h>

#include <cassert>

class TextureBase
{
public:

	GLuint GetTextureHandle() const;

protected:

	// This class is not pure virtual and can therefore be constructed.
	// This, however, should not be possible so the CTOR/DTOR are protected.

	TextureBase();
	virtual ~TextureBase();

	void Bind(GLenum textureBinding, int textureTarget) const;

private:

	GLuint textureHandle;

public:

	static int GetMaxNumberOfCombinedTextureUnits();

private:

	static int maxNumberOfCombinedTextureUnits;

};
