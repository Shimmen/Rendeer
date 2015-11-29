#pragma once

#include "TextureBase.h"

#include "glm/fwd.hpp"

#include <string>
#include <glad/glad.h>

class Bitmap;

class Texture2D: public TextureBase
{
public:

	Texture2D(const std::string& filename, bool srgb, GLint magFilter = GL_LINEAR, GLint wrapMode = GL_REPEAT);
	Texture2D(const Bitmap& image, bool srgb, GLint magFilter = GL_LINEAR, GLint wrapMode = GL_REPEAT);

	// Construct empty Texture2D for use as a render target, etc.
	Texture2D(int width, int height, GLenum format, GLenum internalFormat, GLint wrapMode, GLint magFilter, GLint minFilter);
	
	void Bind(int textureTarget) const;

	void SetMinFilter(GLenum minFilter);
	void SetMagFilter(GLenum magFilter);
	void SetWrapS(GLenum wrapS);
	void SetWrapT(GLenum wrapT);
	void SetBorderColor(const glm::vec4& color);

	inline int GetWidth() const { return width; }
	inline int GetHeight() const { return height; }

private:

	GLint CalculateSourceFormat(const Bitmap& bitmap) const;
	GLenum CalculateSourceType(const Bitmap& bitmap) const;
	GLint CalculateInternalFormat(GLint externalFormat, bool srgb, bool hdr) const;

	void GenerateMipmapsIfCompatible(GLint minFilter) const;
	void SetMaxAnisotropy() const;

	Texture2D(Texture2D&) = delete;
	Texture2D& operator=(Texture2D&) = delete;

private:

	int width;
	int height;

};
