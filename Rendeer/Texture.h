#pragma once

#include <string>
#include <GL/glew.h>

#define MIN_COMPONENT_COUNT 3

class Texture
{
public:
	Texture(const std::string& filename, GLint magFilter = GL_LINEAR, GLint wrapMode = GL_REPEAT);
	Texture(int width, int height, GLenum format, GLint wrapMode,
		GLint magFilter, GLint minFilter, unsigned char* pixels = 0);
	~Texture();

	void Bind();
	void Bind(int textureTarget);

	inline GLuint GetHandle() const { return textureHandle; }

private:
	GLuint textureHandle;
	
	GLuint internalFormat;

	int width;
	int height;
};
