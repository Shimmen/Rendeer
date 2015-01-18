#include "Texture.h"

#include <iostream>
#include <cassert>
#include <SDL.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Texture::Texture(const std::string& filename)
{
	glGenTextures(1, &textureHandle);
	glBindTexture(GL_TEXTURE_2D, textureHandle);

	int componentCount = 0;
	unsigned char *pixels =
		stbi_load(filename.c_str(), &width, &height, &componentCount, MIN_COMPONENT_COUNT);

	// If image was loaded properly
	if (pixels != NULL && componentCount != 0)
	{
		internalFormat = (componentCount == 3) ? GL_RGB : GL_RGBA;

		// Inject these depencencies!
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0,
			internalFormat, GL_UNSIGNED_BYTE, pixels);

		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(pixels);
	}
	else
	{
		std::cerr << "Error: could not load texture with name: " << filename << std::endl;
	}

	glBindTexture(GL_TEXTURE_2D, 0);
}


Texture::~Texture()
{
	glDeleteTextures(1, &textureHandle);
}

void Texture::Bind()
{
	// Bind this texture as GL_TEXTURE0
	Bind(0);
}

void Texture::Bind(int textureTarget)
{
	// 32 is the default maximum active textures
	assert(textureTarget >= 0 && textureTarget < 32);

	glActiveTexture(GL_TEXTURE0 + textureTarget);
	glBindTexture(GL_TEXTURE_2D, textureHandle);
}