#pragma once

#include <string>
#include <vector>

class Bitmap
{
public:

	Bitmap();
	Bitmap(const std::string& filePath);
	Bitmap(int width, int height, int pixelComponentCount, const std::vector<void *>& data);
	virtual ~Bitmap() {}

	int GetWidth() const;
	int GetHeight() const;
	int GetPixelComponentCount() const;
	bool IsHdr() const;

	int GetPixelSize() const;
	size_t GetDataSize() const;
	const std::vector<void *>& GetData() const;

private:

	int width{ 0 };
	int height{ 0 };
	int pixelComponentCount{ 0 };
	bool isHdr{ false };

	int pixelSize{ 0 };
	std::vector<void *> pixelData{};

};
