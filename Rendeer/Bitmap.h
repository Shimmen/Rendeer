#pragma once

#include <string>
#include <vector>

class Bitmap
{
public:

	Bitmap();
	Bitmap(const std::string& filePath);
	Bitmap(int width, int height, int pixelSize, const std::vector<void *>& data);
	~Bitmap();

	int GetWidth() const;
	int GetHeight() const;
	int GetPixelSize() const;
	bool IsHdr() const;

	size_t GetDataSize() const;
	const std::vector<void *>& GetData() const;
	void SetData(const std::vector<void *>& data);

private:

	int width{ 0 };
	int height{ 0 };
	int pixelSize{ 0 };
	bool isHdr{ false };

	std::vector<void *> pixelData{};

};