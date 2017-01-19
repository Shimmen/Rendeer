#include "Buffer.h"

#include <assert.h>

/*static*/ std::map<GLenum, GLuint> Buffer::currentlyBound{};

Buffer::Buffer()
{
	glGenBuffers(1, &handle);
}

Buffer::Buffer(GLuint bufferHandle)
	: GLResource(bufferHandle)
{
}

Buffer::~Buffer()
{
	// Make sure that all cached data on this buffer handle is invalidated, since a new buffer might be created
	// with the same handle as this one which wouldn't be compatible with the current caching/optimizing.
	for (auto& pair : currentlyBound)
	{
		if (pair.second == handle)
		{
			pair.second = 0;
		}

	}

	glDeleteBuffers(1, &handle);
}

/*static*/
std::vector<std::shared_ptr<Buffer>> Buffer::GenerateBuffers(GLuint count)
{
	GLuint bufferHandles[count];
	glGenBuffers(count, bufferHandles);

	std::vector<std::shared_ptr<Buffer>> buffers;
	buffers.reserve(count);

	for (GLuint handle : bufferHandles)
	{
		// Use shared_ptr ctor instead of make_shared so the buffer ctor taking in a handle can be kept private easily
		buffers.emplace_back(new Buffer{handle});
	}

	return buffers;
}

const Buffer& Buffer::Bind(GLenum target) const
{
	if (currentlyBound[target] != handle)
	{
		glBindBuffer(target, handle);
		lastBoundTargetForInstance = target;
		currentlyBound[target] = handle;
	}

	return *this;
}

const Buffer& Buffer::BindAsUniformBuffer(GLuint binding) const
{
	Bind(GL_UNIFORM_BUFFER);
	glBindBufferBase(GL_UNIFORM_BUFFER, binding, handle);

	return *this;
}

void Buffer::SetData(const void *data, size_t dataSize, GLenum dataUsage) const
{
	assert(dataUsage == GL_STATIC_DRAW || dataUsage == GL_DYNAMIC_DRAW);
	assert(dataSize > 0);

	assert(currentlyBound[lastBoundTargetForInstance] == handle);
	glBufferData(lastBoundTargetForInstance, dataSize, data, dataUsage);
}

void Buffer::UpdateData(const void *data, size_t dataSize, size_t offset) const
{
	assert(dataSize > 0);

	assert(currentlyBound[lastBoundTargetForInstance] == handle);
	glBufferSubData(lastBoundTargetForInstance, offset, dataSize, data);
}

std::vector<uint8_t> Buffer::GetData(size_t size, size_t offset) const
{
	std::vector<uint8_t> data;
	data.reserve(size);

	assert(currentlyBound[lastBoundTargetForInstance] == handle);
	glGetBufferSubData(lastBoundTargetForInstance, offset, size, &data[0]);

	return data;
}
