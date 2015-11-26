#pragma once

#include <glad/glad.h>

class VertexArray
{
public:

	VertexArray();
	~VertexArray();

	void Bind() const;
	void Unbind() const;

	// There are more ways to render a vertexArray ... add them as they are needed.
	void RenderWithElementArrayBuffer(GLenum polygonType, size_t indexCount, GLenum indexType = GL_UNSIGNED_INT) const;

	// This will also enable the relevant vertex attribute array
	void AddVertexAttribute(int index, int valueCount, GLenum valueType, int stride = 0, void *offset = nullptr);

private:

	GLuint vertexArrayHandle;

public:

	static int GetMaxNumberOfVertexAttributes();

private:

	static int maxNumberOfVertexAttributes;

};

