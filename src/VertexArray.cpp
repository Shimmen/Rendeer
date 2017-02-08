#include "VertexArray.h"

#include <cassert>

/*static*/ GLuint VertexArray::currentlyBound = 0;

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &handle);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &handle);
}

void VertexArray::Bind() const
{
	if (currentlyBound != handle)
	{
		glBindVertexArray(handle);
		assert(glIsVertexArray(handle));
		currentlyBound = handle;
	}
}

void VertexArray::Unbind() const
{
	if (currentlyBound != 0)
	{
		glBindVertexArray(0);
		currentlyBound = 0;
	}
}

void VertexArray::RenderWithElementArrayBuffer(GLenum polygonType, size_t indexCount, GLenum indexType, const GLvoid *offset) const
{
	glDrawElements(polygonType, static_cast<GLsizei>(indexCount), indexType, offset);
}

void VertexArray::RenderWithArrayBuffer(GLenum polygonType, int vertexCount, int vertexIndexOffset) const
{
	glDrawArrays(polygonType, vertexIndexOffset, vertexCount);
}

void VertexArray::AddVertexAttribute(unsigned int index, int valueCount, GLenum valueType, int stride, void *offset, GLboolean normalize)
{
	assert(index < VertexArray::GetMaxNumberOfVertexAttributes());
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, valueCount, valueType, normalize, stride, offset);
}

int VertexArray::GetMaxNumberOfVertexAttributes()
{
	static int maxCount = -1;
	if (maxCount == -1)
	{
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &maxCount);
	}
	return maxCount;
}
