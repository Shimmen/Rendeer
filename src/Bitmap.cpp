#include "Bitmap.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

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
	if (!nonstd::file_is_readable(filePath))
	{
		Logger::Log("Error: can't read file with name '%s'", filePath.c_str());
	}

	stbi_set_flip_vertically_on_load(true);
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
		Logger::Log("Error: stbi could not load image with name '%s': %s", filePath.c_str(), stbi_failure_reason());
	}
	else
	{
		size_t dataSize = GetDataSize();
		this->pixelData.reserve(dataSize);
		std::memcpy(this->pixelData.data(), stbiOwnedData, dataSize);
		stbi_image_free(stbiOwnedData);
	}
}

Bitmap::Bitmap(int width, int height, int pixelComponentCount, const std::vector<void *>& data)
	: width{ width } 
	, height{ height }
	, pixelComponentCount{ pixelComponentCount }
	, isHdr{ false }
	, pixelSize{ pixelComponentCount }
	, pixelData{ static_cast<unsigned int>(width * height * pixelSize) }
{
	// It could also be smaller, but this could possible avoid some bugs where you miss a row, or similar.
	assert(data.size() == pixelData.size());
	memcpy(&pixelData[0], &data[0], pixelData.size());
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

int Bitmap::GetPixelSize() const
{
	return pixelSize;
}

size_t Bitmap::GetDataSize() const
{
	return static_cast<size_t >(GetWidth() * GetHeight() * GetPixelSize());
}

const std::vector<void *>& Bitmap::GetData() const
{
	return pixelData;
}
