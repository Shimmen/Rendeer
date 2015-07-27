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

	void Bind(GLenum target) const;
	
	void SetData(const void *data, size_t dataSize, GLenum dataUsage) const;
	void UpdateData(const void *data, size_t dataSize, size_t offset = 0) const;

	std::vector<char> GetData(size_t size, size_t offset = 0) const;

	GLuint GetBufferHandle() const;

private:
	GLuint bufferHandle;
	mutable GLenum lastBoundTarget;

	static GLuint currentlyBoundBufferHandle;
	static std::map<GLuint, int> referenceCountForBufferHandle;
};