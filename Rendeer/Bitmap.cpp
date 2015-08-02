#include "Bitmap.h"

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Bitmap::Bitmap(const std::string& filePath)
{
	pixel_component_t *tempStbiData = stbi_load(filePath.c_str(), &this->width, &this->height, &this->componentsPerPixel, 0);

	if (tempStbiData != nullptr)
	{
		// TODO: Mirror image on the y-axis, since stbi loads the image so the first pixel
		// is the top left one. OpenGL expects the lower left pixel to be the first.

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
