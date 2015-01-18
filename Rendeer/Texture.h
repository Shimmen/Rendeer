#pragma once

#include <string>
#include <GL/glew.h>

#define MIN_COMPONENT_COUNT 3

class Texture
{
public:
	Texture(const std::string& filename);
	~Texture();

	void Bind();
	void Bind(int textureTarget);

	inline GLuint GetHandle() { return textureHandle; }

private:
	GLuint textureHandle;
	
	GLuint internalFormat;

	int width;
	int height;
};

