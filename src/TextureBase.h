#pragma once

#include <glad/glad.h>

class TextureBase
{
public:

    void Bind(GLenum textureBinding, GLuint textureTarget) const;
	GLuint GetTextureHandle() const;

protected:

	// This class is not pure virtual and can therefore be constructed.
	// This, however, should not be possible so the CTOR/DTOR are protected.

	TextureBase();
	virtual ~TextureBase();

private:

	GLuint textureHandle;

public:

	static int GetMaxNumberOfCombinedTextureUnits();

private:

	static int maxNumberOfCombinedTextureUnits;

};
