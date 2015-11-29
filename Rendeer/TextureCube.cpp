#include "TextureCube.h"

#include <cassert>

#include "Bitmap.h"

TextureCube::TextureCube(const Bitmap& left,
                         const Bitmap& right,
                         const Bitmap& down,
                         const Bitmap& up,
                         const Bitmap& front,
                         const Bitmap& back)
	: TextureBase()
{
	// Assert all Bitmaps are in the RGB format
	assert(left.GetPixelSize()  == 3 &&
		   right.GetPixelSize() == 3 &&
		   down.GetPixelSize()  == 3 &&
		   up.GetPixelSize()    == 3 &&
		   front.GetPixelSize() == 3 &&
		   back.GetPixelSize()  == 3);

	glBindTexture(GL_TEXTURE_CUBE_MAP, GetTextureHandle());

	// Set texture parameters
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	// Add the images to the texture cube
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB, left.GetWidth(), left.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, &left.GetData()[0]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB, right.GetWidth(), right.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, &right.GetData()[0]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB, down.GetWidth(), down.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, &down.GetData()[0]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB, up.GetWidth(), up.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, &up.GetData()[0]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB, front.GetWidth(), front.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, &front.GetData()[0]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB, back.GetWidth(), back.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, &back.GetData()[0]);

}

void TextureCube::Bind(int textureTarget) const
{
	TextureBase::Bind(GL_TEXTURE_CUBE_MAP, textureTarget);
}
