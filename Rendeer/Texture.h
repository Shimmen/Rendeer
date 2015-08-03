#pragma once

#include <string>
#include <glad/glad.h>

class Bitmap;

class Texture
{
public:

	Texture(const std::string& filename, bool srgb, GLint magFilter = GL_LINEAR, GLint wrapMode = GL_REPEAT);
	Texture(const Bitmap& image, bool srgb, GLint magFilter = GL_LINEAR, GLint wrapMode = GL_REPEAT);

	Texture(int width, int height, GLenum format, GLenum internalFormat, GLint wrapMode, GLint magFilter, GLint minFilter);

	~Texture();
	
	void Bind(int textureTarget) const;

	inline GLuint GetHandle() const { return textureHandle; }
	inline int GetWidth() const { return width; }
	inline int GetHeight() const { return height; }

private:

	GLint CalculateExternalFormat(int componentCount) const;
	GLint CalculateInternalFormat(GLint externalFormat, bool srgb) const;

	void GenerateMipmaps(GLint minFilter) const;
	void SetMaxAnisotropy() const;

private:

	GLuint textureHandle;

	int width;
	int height;

};

