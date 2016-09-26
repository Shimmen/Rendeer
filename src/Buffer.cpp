#include "Buffer.h"

#include <assert.h>

#define INCREMENT_REFERENCE_COUNT(bufferHandle) (referenceCountForBufferHandle[bufferHandle]++);
#define DECREMENT_REFERENCE_COUNT(bufferHandle) (referenceCountForBufferHandle[bufferHandle]--);

/*static*/ GLuint Buffer::currentlyBoundBufferHandle = UINT32_MAX;
/*static*/ std::map<GLuint, int> Buffer::referenceCountForBufferHandle;

Buffer::Buffer()
{
	glGenBuffers(1, &bufferHandle);
	INCREMENT_REFERENCE_COUNT(bufferHandle);
}

Buffer::Buffer(GLuint bufferHandle)
	: bufferHandle(bufferHandle)
	, lastBoundTarget(GL_NONE)
{
	INCREMENT_REFERENCE_COUNT(bufferHandle);
}
/*
Buffer::Buffer(Buffer& other)
	: bufferHandle(other.bufferHandle)
	, lastBoundTarget(other.lastBoundTarget)
{
	INCREMENT_REFERENCE_COUNT(bufferHandle);
}
*/
/*static*/ std::vector<Buffer> Buffer::GenerateBuffers(GLuint count)
{
	std::vector<GLuint> bufferHandles(count);
	glGenBuffers(count, &bufferHandles[0]);

	std::vector<Buffer> buffers;
	for (GLuint handle : bufferHandles)
	{
		buffers.push_back(Buffer(handle));
	}

	return buffers;
}

Buffer::~Buffer()
{
	DECREMENT_REFERENCE_COUNT(bufferHandle);
	if (referenceCountForBufferHandle[bufferHandle] <= 0)
	{
		glDeleteBuffers(1, &bufferHandle);
	}
}

const Buffer& Buffer::Bind(GLenum target) const
{
	assert(target == GL_ARRAY_BUFFER ||
		   target == GL_ATOMIC_COUNTER_BUFFER ||
		   target == GL_COPY_READ_BUFFER ||
		   target == GL_COPY_WRITE_BUFFER ||
		   target == GL_DISPATCH_INDIRECT_BUFFER ||
		   target == GL_DRAW_INDIRECT_BUFFER ||
		   target == GL_ELEMENT_ARRAY_BUFFER ||
		   target == GL_PIXEL_PACK_BUFFER ||
		   target == GL_PIXEL_UNPACK_BUFFER ||
		   target == GL_QUERY_BUFFER ||
		   target == GL_SHADER_STORAGE_BUFFER ||
		   target == GL_TEXTURE_BUFFER ||
		   target == GL_TRANSFORM_FEEDBACK_BUFFER ||
		   target == GL_UNIFORM_BUFFER);

	glBindBuffer(target, bufferHandle);

	lastBoundTarget = target;
	currentlyBoundBufferHandle = this->bufferHandle;

	return *this;
}

const Buffer& Buffer::BindAsUniformBuffer(GLuint binding) const
{
	Bind(GL_UNIFORM_BUFFER);
	glBindBufferBase(GL_UNIFORM_BUFFER, binding, GetBufferHandle());

	return *this;
}

void Buffer::SetData(const void *data, size_t dataSize, GLenum dataUsage) const
{
	assert(currentlyBoundBufferHandle == this->bufferHandle);
	assert(dataUsage == GL_STATIC_DRAW || dataUsage == GL_DYNAMIC_DRAW);
	glBufferData(lastBoundTarget, dataSize, data, dataUsage);
}

void Buffer::UpdateData(const void *data, size_t dataSize, size_t offset) const
{
	assert(currentlyBoundBufferHandle == this->bufferHandle);
	glBufferSubData(lastBoundTarget, offset, dataSize, data);
}

std::vector<char> Buffer::GetData(size_t size, size_t offset) const
{
	assert(currentlyBoundBufferHandle == this->bufferHandle);

	std::vector<char> data;
	data.reserve(size);

	glGetBufferSubData(lastBoundTarget, offset, size, &data[0]);

	return data;
}

GLuint Buffer::GetBufferHandle() const
{
	return bufferHandle;
}
