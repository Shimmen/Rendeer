#include "TextureCube.h"

#include <cassert>

#include "Bitmap.h"

TextureCube::TextureCube(const Bitmap& images)
{
	// TODO: Don't assert this! This is just for convenience for now
	assert(images.IsHdr());
	assert(images.GetPixelComponentCount() == 3);

	glBindTexture(GL_TEXTURE_CUBE_MAP, GetTextureHandle());

	// Set texture parameters
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	int faceWidth = images.GetWidth();
	int imageHeight = images.GetHeight();
	int faceHeight = imageHeight / 6;
	size_t faceSize = images.GetDataSize() / 6;
	const unsigned char *sourceData = (unsigned char *)images.GetData().data();

	// Add the images to the texture cube
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB16F, faceWidth, faceHeight, 0, GL_RGB, GL_FLOAT, sourceData + faceSize * 0);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB16F, faceWidth, faceHeight, 0, GL_RGB, GL_FLOAT, sourceData + faceSize * 1);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB16F, faceWidth, faceHeight, 0, GL_RGB, GL_FLOAT, sourceData + faceSize * 2);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB16F, faceWidth, faceHeight, 0, GL_RGB, GL_FLOAT, sourceData + faceSize * 3);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB16F, faceWidth, faceHeight, 0, GL_RGB, GL_FLOAT, sourceData + faceSize * 4);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB16F, faceWidth, faceHeight, 0, GL_RGB, GL_FLOAT, sourceData + faceSize * 5);
}

TextureCube::TextureCube(const Bitmap& left, const Bitmap& right, const Bitmap& down, const Bitmap& up,
	const Bitmap& front, const Bitmap& back)
	: TextureBase()
{
	// Assert all Bitmaps are in the RGB format
	assert(left.GetPixelComponentCount()  == 3 &&
		   right.GetPixelComponentCount() == 3 &&
		   down.GetPixelComponentCount()  == 3 &&
		   up.GetPixelComponentCount()    == 3 &&
		   front.GetPixelComponentCount() == 3 &&
		   back.GetPixelComponentCount()  == 3);

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
	//glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB, down.GetWidth(), down.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, &down.GetData()[0]);
	//glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB, up.GetWidth(), up.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, &up.GetData()[0]); // FIXME: why is everything reversed? See shader as well.
    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB, up.GetWidth(), up.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, &up.GetData()[0]);
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB, down.GetWidth(), down.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, &down.GetData()[0]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB, front.GetWidth(), front.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, &front.GetData()[0]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB, back.GetWidth(), back.GetHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, &back.GetData()[0]);

}

TextureCube::~TextureCube()
{
}

void TextureCube::Bind(GLuint textureTarget) const
{
	TextureBase::Bind(GL_TEXTURE_CUBE_MAP, textureTarget);
}
