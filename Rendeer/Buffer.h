#pragma once

#include <vector>
#include <map>

#include "glad/glad.h"

class Buffer
{
public:

	Buffer();
	Buffer(GLuint bufferHandle);
	Buffer(Buffer& other);

	static std::vector<Buffer> GenerateBuffers(int count);

	~Buffer();

	const Buffer& Bind(GLenum target) const;
	
	template <typename T>
	void SetData(const std::vector<T>& data, GLenum dataUsage) const
	{
		this->SetData(&data[0], data.size() * sizeof(T), dataUsage);
	}

	template <typename T>
	void UpdateData(const std::vector<T>& data, size_t offset = 0) const
	{
		this->UpdateData(&data[0], data.size() * sizeof(T), offset);
	}

	void SetData(const void *data, size_t dataSize, GLenum dataUsage) const;
	void UpdateData(const void *data, size_t dataSize, size_t offset = 0) const;

	std::vector<char> GetData(size_t size, size_t offset = 0) const;

	GLuint GetBufferHandle() const;

private:

	// Not copy-assignable (for now at least)
	Buffer& operator=(Buffer& other);

private:

	GLuint bufferHandle;
	mutable GLenum lastBoundTarget;

	static GLuint currentlyBoundBufferHandle;
	static std::map<GLuint, int> referenceCountForBufferHandle;

};