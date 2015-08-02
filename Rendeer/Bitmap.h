#pragma once

#include <string>
#include <vector>

class Bitmap
{
public:

	typedef unsigned char pixel_component_t;

public:

	Bitmap(const std::string& filePath);

	int GetWidth() const;
	int GetHeight() const;

	int GetPixelCount() const;
	int GetComponentsPerPixel() const;

	const std::vector<pixel_component_t>& GetData() const;

private:

	int width{0};
	int height{0};

	int componentsPerPixel{0};
	std::vector<pixel_component_t> pixelData{};

	bool isHdr{false};

};