#include "Texture2D.h"

#include <glm/gtc/type_ptr.hpp>

#include "Bitmap.h"
#include "Logger.h"

Texture2D::Texture2D(const std::string& filename, bool srgb, GLint magFilter, GLint wrapMode)
	: Texture2D(Bitmap{filename}, srgb, magFilter, wrapMode)
{
}

Texture2D::Texture2D(const Bitmap& image, bool srgb, GLint magFilter, GLint wrapMode)
	: TextureBase()
	, width{ image.GetWidth() }
	, height{ image.GetHeight() }
{
	Bind(0);

	// Assume trilinear for all loaded images (can always be changed later)
	SetMinFilter(GL_LINEAR_MIPMAP_LINEAR);
	SetMagFilter(magFilter);
	SetWrapS(wrapMode);
	SetWrapT(wrapMode);

	GLenum sourceFormat = CalculateSourceFormat(image);
	GLenum sourceType = CalculateSourceType(image);
	GLint internalFormat = CalculateInternalFormat(sourceFormat, srgb, image.IsHdr());
	const void *sourceData = &image.GetData()[0];

	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, sourceFormat, sourceType, sourceData);

	GenerateMipmapsIfCompatible(GL_LINEAR_MIPMAP_LINEAR);
	SetMaxAnisotropy();
}

Texture2D::Texture2D(int width, int height, GLenum format, GLenum internalFormat, GLint wrapMode, GLint magFilter, GLint minFilter)
	: TextureBase()
	, width{ width }
	, height{ height }
{
	Bind(0);

	SetMinFilter(minFilter);
	SetMagFilter(magFilter);
	SetWrapS(wrapMode);
	SetWrapT(wrapMode);

	// Since the texture is created empty these work fine.
	static const void *NO_DATA = nullptr;
	static const GLenum NO_TYPE = GL_UNSIGNED_BYTE;

	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, NO_TYPE, NO_DATA);

	GenerateMipmapsIfCompatible(minFilter);
	SetMaxAnisotropy();
}

void Texture2D::Bind(GLuint textureTarget) const
{
	TextureBase::Bind(GL_TEXTURE_2D, textureTarget);
}

void Texture2D::SetMinFilter(GLint minFilter)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
}

void Texture2D::SetMagFilter(GLint magFilter)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
}

void Texture2D::SetWrapS(GLint wrapS)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
}

void Texture2D::SetWrapT(GLint wrapT)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);
}

void Texture2D::SetBorderColor(const glm::vec4& color)
{
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(color));
}

GLenum Texture2D::CalculateSourceFormat(const Bitmap& bitmap) const
{
	int pixelComponentCount = bitmap.GetPixelComponentCount();
	assert(pixelComponentCount > 0 && pixelComponentCount <= 4);
	if (pixelComponentCount == 1) return GL_RED;
	if (pixelComponentCount == 2) return GL_RG;
	if (pixelComponentCount == 3) return GL_RGB;
	if (pixelComponentCount == 4) return GL_RGBA;
	else
	{
		Logger::GetDefaultLogger().Log("Error: couldn't find an source format for the pixel component count " + pixelComponentCount);
		return 0;
	}
}

GLenum Texture2D::CalculateSourceType(const Bitmap & bitmap) const
{
	return bitmap.IsHdr() ? GL_FLOAT : GL_UNSIGNED_BYTE;
}

GLint Texture2D::CalculateInternalFormat(GLint externalFormat, bool srgb, bool hdr) const
{
	assert(externalFormat == GL_RED || externalFormat == GL_RG ||
	       externalFormat == GL_RGB || externalFormat == GL_RGBA);

	if (srgb && hdr)
	{
		Logger::GetDefaultLogger().Log("Error: Texture2D specified to be both SRGB and HDR, which isn't possible! Ignoring sRGB flag.");
		srgb = false;
	}

	if (srgb)
	{
		// For sRGB color space in OpenGL no format under 3 components exists.
		if (externalFormat == GL_RGBA) return GL_SRGB8_ALPHA8;
		else                           return GL_SRGB8;
	}
	else
	{
		if (hdr)
		{
			// Use only 16-bit floating point, since the RGBE format only has 8-bits of precision.
			if (externalFormat == GL_RED)  return GL_R16F;
			if (externalFormat == GL_RG)   return GL_RG16F;
			if (externalFormat == GL_RGB)  return GL_RGB16F;
			if (externalFormat == GL_RGBA) return GL_RGBA16F;
		}
		else
		{
			if (externalFormat == GL_RED)  return GL_R8;
			if (externalFormat == GL_RG)   return GL_RG8;
			if (externalFormat == GL_RGB)  return GL_RGB8;
			if (externalFormat == GL_RGBA) return GL_RGBA8;
		}
	}
}

void Texture2D::GenerateMipmapsIfCompatible(GLint minFilter) const
{
	// If minFilter is mipmap compatible, generate mipmaps
	if (minFilter == GL_LINEAR_MIPMAP_LINEAR  || minFilter == GL_LINEAR_MIPMAP_NEAREST ||
		minFilter == GL_NEAREST_MIPMAP_LINEAR || minFilter == GL_NEAREST_MIPMAP_NEAREST)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}
}

void Texture2D::SetMaxAnisotropy() const
{
	GLfloat maxAnisotropy;
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAnisotropy);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAnisotropy);
}
