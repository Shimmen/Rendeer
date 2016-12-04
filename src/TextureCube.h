#pragma once

#include "TextureBase.h"

class Bitmap;

class TextureCube: public TextureBase
{
public:

	TextureCube(const Bitmap& images);
	TextureCube(const Bitmap& left, const Bitmap& right, const Bitmap& down, const Bitmap& up,
		const Bitmap& front, const Bitmap& back);
	~TextureCube();

	void Bind(GLuint textureTarget) const;

private:

	TextureCube(TextureCube&) = delete;
	TextureCube& operator=(TextureCube&) = delete;

};

