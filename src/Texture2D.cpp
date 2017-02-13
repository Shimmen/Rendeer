#include "Texture2D.h"

// Implementation defined in Bitmap class
//#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include <glm/gtc/type_ptr.hpp>

#include "Logger.h"
#include "FrameBuffer.h"

Texture2D::Texture2D()
	: Texture2D{ "textures/default.png", true }
{
	// Could also not load anything to start up quicker, but this will make it visually clearer what's happening
}

Texture2D::Texture2D(const std::string& filename, bool srgb, GLint magFilter, GLint wrapMode)
	: TextureBase{}
{
	Bind();

	Load(filename, srgb);

	// Assume trilinear for all loaded images
	SetMinFilter(GL_LINEAR_MIPMAP_LINEAR);
	SetMagFilter(magFilter);
	SetWrapS(wrapMode);
	SetWrapT(wrapMode);
	SetAnisotropy(GetMaxAnisotropy());
}

Texture2D::Texture2D(int width, int height, int numComponents, const unsigned char *data)
	: TextureBase()
	, width(width)
	,height(height)
{
	Bind();

	GLenum sourceFormat = CalculateSourceFormat(numComponents);
	GLint internalFormat = CalculateInternalFormat(sourceFormat, false, false);

	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, sourceFormat, GL_UNSIGNED_BYTE, data);

	// Default to linear (can of course be changed later)
	SetMinFilter(GL_LINEAR);
	SetMagFilter(GL_LINEAR);
}

Texture2D::Texture2D(int width, int height, GLenum format, GLenum internalFormat, GLint wrapMode, GLint magFilter, GLint minFilter, GLenum type, const GLvoid *data)
	: TextureBase()
	, width{ width }
	, height{ height }
{
	Bind();

	SetMinFilter(minFilter);
	SetMagFilter(magFilter);
	SetWrapS(wrapMode);
	SetWrapT(wrapMode);
	SetAnisotropy(GetMaxAnisotropy());

	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, type, data);
	GenerateMipmaps();
}

int Texture2D::Bind(GLuint textureBinding) const
{
	TextureBase::Bind(GL_TEXTURE_2D, textureBinding);
	return static_cast<int>(textureBinding);
}

void Texture2D::SetMinFilter(GLint minFilter)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
}

void Texture2D::SetMagFilter(GLint magFilter)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
}

void Texture2D::SetFilter(GLint filter)
{
	SetMinFilter(filter);
	SetMagFilter(filter);
}

void Texture2D::SetWrapS(GLint wrapS)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
}

void Texture2D::SetWrapT(GLint wrapT)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);
}

void Texture2D::SetWrap(GLint wrap)
{
	SetWrapS(wrap);
	SetWrapT(wrap);
}

void Texture2D::SetBorderColor(float r, float g, float b, float a)
{
	GLfloat color[4] = { r, g, b, a };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
}

void Texture2D::GenerateMipmaps()
{
	glGenerateMipmap(GL_TEXTURE_2D);
}

void Texture2D::SetMipmapBase(int base)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, base);
}

float Texture2D::GetMaxAnisotropy() const
{
	GLfloat maxAnisotropy;
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAnisotropy);
	return maxAnisotropy;
}

void Texture2D::SetAnisotropy(float level)
{
	static GLfloat maxAnisotropy = GetMaxAnisotropy();
	float anisotropy = fminf(1.0f, fmaxf(level, maxAnisotropy));
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, anisotropy);
}

void Texture2D::Make(int width, int height, GLenum format, GLenum internalFormat)
{
	Bind();

	this->width = width;
	this->height = height;

	// These *probably shouldn't* matter since there is no input data, but I really don't know...
	GLenum inputType = GL_UNSIGNED_BYTE;
	const GLvoid *inputData = nullptr;
	
	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, inputType, inputData);

	// Default to linear (must be set to something)
	SetMinFilter(GL_LINEAR);
	SetMagFilter(GL_LINEAR);
}

bool Texture2D::Load(const std::string& filename, bool srgb, GLint magFilter, GLint wrapMode, bool generateMipmaps)
{
	FILE *file = fopen(filename.c_str(), "rb");
	if (file == nullptr)
	{
		Logger::Log("Error: can't read file with name '%s'", filename.c_str());
		return false;
	}

	// Flip images to make complient with OpenGL texture handling
	stbi_set_flip_vertically_on_load(true);

	bool hdr = stbi_is_hdr_from_file(file);
	fseek(file, 0, SEEK_SET); // TODO: File a bug! Shouldn't need to rewind, right?
	void *pixels;
	int numComponents;

	if (hdr)
	{
		pixels = stbi_loadf_from_file(file, &width, &height, &numComponents, 0);
	}
	else
	{
		pixels = stbi_load_from_file(file, &width, &height, &numComponents, 0);
	}

	if (pixels == nullptr)
	{
		Logger::Log("Error: stbi could not load image with name '%s': %s", filename.c_str(), stbi_failure_reason());
		return false;
	}

	// Assume trilinear for all loaded images
	SetMinFilter(GL_LINEAR_MIPMAP_LINEAR);
	SetMagFilter(magFilter);
	SetWrapS(wrapMode);
	SetWrapT(wrapMode);

	GLenum sourceFormat = CalculateSourceFormat(numComponents);
	GLint internalFormat = CalculateInternalFormat(sourceFormat, srgb, hdr);
	GLenum sourceType = (hdr) ? GL_FLOAT : GL_UNSIGNED_BYTE;

	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, sourceFormat, sourceType, pixels);

	stbi_image_free(pixels);
	fclose(file);

	if (generateMipmaps)
	{
		GenerateMipmaps();
	}

	return true;
}

std::shared_ptr<FrameBuffer> Texture2D::AsFrameBuffer() const
{
	if (textureAsTarget == nullptr)
	{
		textureAsTarget = std::make_shared<FrameBuffer>();
		textureAsTarget->Attach(this, GL_COLOR_ATTACHMENT0);
	}
	GLenum status{};
	assert(textureAsTarget->IsComplete(&status));
	return textureAsTarget;
}

GLenum Texture2D::CalculateSourceFormat(int numComponents) const
{
	assert(numComponents >= 1 && numComponents <= 4);
	if (numComponents == 1) return GL_RED;
	if (numComponents == 2) return GL_RG;
	if (numComponents == 3) return GL_RGB;
	if (numComponents == 4) return GL_RGBA;
	return 0;
}

GLint Texture2D::CalculateInternalFormat(GLint externalFormat, bool srgb, bool hdr) const
{
	assert(externalFormat == GL_RED || externalFormat == GL_RG ||
	       externalFormat == GL_RGB || externalFormat == GL_RGBA);

	if (srgb && hdr)
	{
		Logger::Log("Error: Texture2D specified to be both SRGB and HDR, which isn't possible! Ignoring sRGB flag.");
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

	// This should never happen...
	return -1;
}
