#pragma once

#include <string>
#include <glad/glad.h>

#define MIN_COMPONENT_COUNT 3

class Texture
{
public:
	Texture(const std::string& filename, GLint magFilter = GL_LINEAR, GLint wrapMode = GL_REPEAT, bool srgb = true);
	Texture(int width, int height, GLenum format, GLenum internalFormat, GLint wrapMode,
		GLint magFilter, GLint minFilter, unsigned char* pixels = 0);
	~Texture();

	void Bind() const;
	void Bind(int textureTarget) const;

	inline GLuint GetHandle() const { return textureHandle; }

private:
	GLuint textureHandle;
	
	GLuint internalFormat;

	int width;
	int height;
};

