#include "Texture.h"

#include <cassert>

#include <glm/gtc/type_ptr.hpp>

#include "Bitmap.h"

Texture::Texture(const std::string& filename, bool srgb, GLint magFilter, GLint wrapMode)
	: Texture(Bitmap(filename), srgb, magFilter, wrapMode)
{
}

Texture::Texture(const Bitmap& image, bool srgb, GLint magFilter, GLint wrapMode)
{
	if (image.GetData().size() <= 0)
	{
		// TODO: Do proper error handling
		exit(EXIT_FAILURE);
	}

	this->width = image.GetWidth();
	this->height = image.GetHeight();

	GLint externalFormat = CalculateExternalFormat(image.GetComponentsPerPixel());
	GLint internalFormat = CalculateInternalFormat(externalFormat, srgb);

	glGenTextures(1, &textureHandle);
	glBindTexture(GL_TEXTURE_2D, textureHandle);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);

	const unsigned char *imageData = &image.GetData()[0];
	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, externalFormat, GL_UNSIGNED_BYTE, imageData);

	GenerateMipmaps(GL_LINEAR_MIPMAP_LINEAR);
	SetMaxAnisotropy();
}

Texture::Texture(int width, int height, GLenum format, GLenum internalFormat, GLint wrapMode, GLint magFilter, GLint minFilter)
{
	this->width = width;
	this->height = height;

	glGenTextures(1, &textureHandle);
	glBindTexture(GL_TEXTURE_2D, textureHandle);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);

	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, nullptr);

	GenerateMipmaps(minFilter);
	SetMaxAnisotropy();
}

Texture::~Texture()
{
	glDeleteTextures(1, &textureHandle);
}

void Texture::Bind(int textureTarget) const
{
	// 32 is the maximum active textures possible/allowed
	assert(textureTarget >= 0 && textureTarget < 32);

	glActiveTexture(GL_TEXTURE0 + textureTarget);
	glBindTexture(GL_TEXTURE_2D, textureHandle);
}

void Texture::SetBorderColor(const glm::vec4& color)
{
	Bind(31);
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(color));
}

GLint Texture::CalculateExternalFormat(int componentCount) const
{
	assert(componentCount > 0 && componentCount <= 4);
	if (componentCount == 1) return GL_RED;
	if (componentCount == 2) return GL_RG;
	if (componentCount == 3) return GL_RGB;
	if (componentCount == 4) return GL_RGBA;
	else return 0;
}

GLint Texture::CalculateInternalFormat(GLint externalFormat, bool srgb) const
{
	assert(externalFormat == GL_RED || externalFormat == GL_RG ||
	       externalFormat == GL_RGB || externalFormat == GL_RGBA);

	if (srgb)
	{
		// For sRGB color space in OpenGL no format under 3 components exists.
		if (externalFormat == GL_RGBA) return GL_SRGB8_ALPHA8;
		else                           return GL_SRGB8;
	}
	else
	{
		if (externalFormat == GL_RED)  return GL_R8;
		if (externalFormat == GL_RG)   return GL_RG8;
		if (externalFormat == GL_RGB)  return GL_RGB8;
		if (externalFormat == GL_RGBA) return GL_RGBA8;
		else return 0;
	}
}

void Texture::GenerateMipmaps(GLint minFilter) const
{
	// If minFilter is mipmap compatible, generate mipmaps
	if (minFilter == GL_LINEAR_MIPMAP_LINEAR  || minFilter == GL_LINEAR_MIPMAP_NEAREST ||
		minFilter == GL_NEAREST_MIPMAP_LINEAR || minFilter == GL_NEAREST_MIPMAP_NEAREST)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}
}

void Texture::SetMaxAnisotropy() const
{
	GLfloat maxAnisotropy;
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAnisotropy);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAnisotropy);
}
