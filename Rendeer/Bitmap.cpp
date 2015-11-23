#include "Bitmap.h"

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Bitmap::Bitmap(const std::string& filePath)
{
	// Flip images to make complient with OpenGL texture handling
	stbi_set_flip_vertically_on_load(true);
	pixel_component_t *tempStbiData = stbi_load(filePath.c_str(), &this->width, &this->height, &this->componentsPerPixel, 0);

	if (tempStbiData != nullptr)
	{
		// Copy data from stbi's memory into owned memory
		int dataSize = GetWidth() * GetHeight() * GetComponentsPerPixel();
		this->pixelData.resize(dataSize);
		memcpy_s(&this->pixelData[0], dataSize, tempStbiData, dataSize);

		// Check if file is HDR
		this->isHdr = (stbi_is_hdr_from_memory(tempStbiData, dataSize) != 0);

		stbi_image_free(tempStbiData);
	}
	else
	{
		std::cerr << "Error: could not load texture with name: " << filePath << "." << std::endl;
	}
}

Bitmap::Bitmap(int width, int height, int componentsPerPixel, const std::vector<pixel_component_t>& data)
	: width{ width }
	, height{ height }
	, componentsPerPixel{ componentsPerPixel }
	, pixelData(width * height * componentsPerPixel)
	, isHdr{false}
{
	SetData(data);
}

int Bitmap::GetWidth() const
{
	return width;
}

int Bitmap::GetHeight() const
{
	return height;
}

int Bitmap::GetComponentsPerPixel() const
{
	return componentsPerPixel;
}

const std::vector<Bitmap::pixel_component_t>& Bitmap::GetData() const
{
	return pixelData;
}

void Bitmap::SetData(const std::vector<pixel_component_t>& data)
{
	// It could also be smaller, but this could possible avoid some bugs where you miss a row, or similar.
	assert(data.size() == pixelData.size());
	memcpy_s(&pixelData[0], pixelData.size(), &data[0], pixelData.size());
}
