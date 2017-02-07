#include "VertexArray.h"

#include <cassert>

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
	glBindVertexArray(handle);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}

void VertexArray::RenderWithElementArrayBuffer(GLenum polygonType, size_t indexCount, GLenum indexType, const GLvoid *offset) const
{
	glDrawElements(polygonType, static_cast<GLsizei>(indexCount), indexType, offset);
}

void VertexArray::RenderWithArrayBuffer(GLenum polygonType, int vertexCount, int vertexIndexOffset) const
{
	glDrawArrays(polygonType, vertexIndexOffset, vertexCount);
}

void VertexArray::AddVertexAttribute(int index, int valueCount, GLenum valueType, int stride, void *offset, GLboolean normalize)
{
	assert(index < VertexArray::GetMaxNumberOfVertexAttributes());

	GLuint idx = static_cast<GLuint>(index);

	glEnableVertexAttribArray(idx);
	glVertexAttribPointer(idx, valueCount, valueType, normalize, stride, offset);
}

int VertexArray::GetMaxNumberOfVertexAttributes()
{
	if (VertexArray::maxNumberOfVertexAttributes == -1)
	{
		GLint64 count;
		glGetInteger64v(GL_MAX_VERTEX_ATTRIBS, &count);
		VertexArray::maxNumberOfVertexAttributes = static_cast<int>(count);
	}

	return VertexArray::maxNumberOfVertexAttributes;
}

/* static */ int VertexArray::maxNumberOfVertexAttributes{ -1 };

