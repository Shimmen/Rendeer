#pragma once

#include "TextureBase.h"

#include "glm/fwd.hpp"

#include <string>
#include <glad/glad.h>

class Texture2D: public TextureBase
{
public:

	Texture2D();
	Texture2D(const std::string& filename, bool srgb, GLint magFilter = GL_LINEAR, GLint wrapMode = GL_REPEAT);
	Texture2D(int width, int height, int numComponents, const unsigned char *data = nullptr);

	Texture2D(int width, int height, GLenum format, GLenum internalFormat, GLint wrapMode, GLint magFilter, GLint minFilter, GLenum type = GL_UNSIGNED_BYTE, const GLvoid *data = nullptr);

	bool Load(const std::string& filename, bool srgb, GLint magFilter = GL_LINEAR, GLint wrapMode = GL_REPEAT, bool generateMipmaps = true);
	
	int Bind(GLuint textureBinding = 0) const;

	void SetMinFilter(GLint minFilter);
	void SetMagFilter(GLint magFilter);
	void SetWrapS(GLint wrapS);
	void SetWrapT(GLint wrapT);
	void SetBorderColor(float r, float g, float b, float a);

	void GenerateMipmaps();
	void SetMipmapBase(int base);

	float GetMaxAnisotropy() const;
	void SetAnisotropy(float level);

	inline int GetWidth() const { return width; }
	inline int GetHeight() const { return height; }
	inline int GetSize() const { assert(width == height); return width; }

private:

	GLenum CalculateSourceFormat(int numComponents) const;
	GLint CalculateInternalFormat(GLint externalFormat, bool srgb, bool hdr) const;

private:

	int width;
	int height;

};
