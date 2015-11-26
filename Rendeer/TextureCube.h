#pragma once

#include "ITexture.h"

class Bitmap;

class TextureCube: public ITexture
{
public:

	TextureCube(const Bitmap& left, 
	            const Bitmap& right, 
	            const Bitmap& down, 
	            const Bitmap& up, 
	            const Bitmap& front,
	            const Bitmap& back);

	void Bind(int textureTarget) const;

private:

	TextureCube(TextureCube&) = delete;
	TextureCube& operator=(TextureCube&) = delete;

};

