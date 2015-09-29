#pragma once

#include "ITexture.h"

#include "glm/fwd.hpp"

#include <string>
#include <glad/glad.h>

class Bitmap;

class Texture2D: public ITexture
{
public:

	Texture2D(const std::string& filename, bool srgb, GLint magFilter = GL_LINEAR, GLint wrapMode = GL_REPEAT);
	Texture2D(const Bitmap& image, bool srgb, GLint magFilter = GL_LINEAR, GLint wrapMode = GL_REPEAT);

	Texture2D(int width, int height, GLenum format, GLenum internalFormat, GLint wrapMode, GLint magFilter, GLint minFilter);
	
	void Bind(int textureTarget) const;

	void SetBorderColor(const glm::vec4& color);

	inline int GetWidth() const { return width; }
	inline int GetHeight() const { return height; }

private:

	GLint CalculateExternalFormat(int componentCount) const;
	GLint CalculateInternalFormat(GLint externalFormat, bool srgb) const;

	void GenerateMipmaps(GLint minFilter) const;
	void SetMaxAnisotropy() const;

private:

	int width;
	int height;

};

