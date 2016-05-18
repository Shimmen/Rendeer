#include "Bitmap.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "Logger.h"
#include "GeneralUtil.h"

Bitmap::Bitmap()
	: width{ 0 }
	, height{ 0 }
	, pixelComponentCount{ 0 }
	, isHdr{ false }
	, pixelSize{ 0 }
	, pixelData{ 0 }
{
}

Bitmap::Bitmap(const std::string& filePath)
{
	// Flip images to make complient with OpenGL texture handling
	stbi_set_flip_vertically_on_load(false);

	if (nonstd::file_is_readable(filePath) == false)
	{
		Logger::GetDefaultLogger().Log("Error: can't read file with name: " + filePath + ".");
	}

	// Check if image is HDR or not
	this->isHdr = stbi_is_hdr(filePath.c_str()) != 0;

	void *stbiOwnedData = nullptr;

	if (IsHdr())
	{
		stbiOwnedData = stbi_loadf(filePath.c_str(), &this->width, &this->height, &this->pixelComponentCount, 0);
		this->pixelSize = pixelComponentCount * sizeof(float);
	}
	else
	{
		stbiOwnedData = stbi_load(filePath.c_str(), &this->width, &this->height, &this->pixelComponentCount, 0);
		this->pixelSize = pixelComponentCount * sizeof(unsigned char);
	}

	if (stbiOwnedData == nullptr)
	{
		Logger::GetDefaultLogger().Log("Error: stbi could not load image with name: " + filePath + ".");
		Logger::GetDefaultLogger().Log("       Reason: " + std::string(stbi_failure_reason()));
	}
	else
	{
		// Copy data from stbi's memory into owned memory
		size_t dataSize = GetDataSize();
		this->pixelData.resize(dataSize);
		memcpy_s(&this->pixelData[0], dataSize, stbiOwnedData, dataSize);

		// Tell stbi to free it's own data
		stbi_image_free(stbiOwnedData);
	}
}

Bitmap::Bitmap(int width, int height, int pixelComponentCount, const std::vector<void *>& data)
	: width{ width } 
	, height{ height }
	, pixelComponentCount{ pixelComponentCount }
	, isHdr{ false }
	, pixelSize{ pixelComponentCount }
	, pixelData(width * height * pixelSize)
{
	// It could also be smaller, but this could possible avoid some bugs where you miss a row, or similar.
	assert(data.size() == pixelData.size());
	memcpy_s(&pixelData[0], pixelData.size(), &data[0], pixelData.size());
}

Bitmap::~Bitmap()
{
}

int Bitmap::GetWidth() const
{
	return width;
}

int Bitmap::GetHeight() const
{
	return height;
}

int Bitmap::GetPixelComponentCount() const
{
	return pixelComponentCount;
}

bool Bitmap::IsHdr() const
{
	return isHdr;
}

size_t Bitmap::GetPixelSize() const
{
	return pixelSize;
}

size_t Bitmap::GetDataSize() const
{
	return GetWidth() * GetHeight() * GetPixelSize();
}

const std::vector<void *>& Bitmap::GetData() const
{
	return pixelData;
}
