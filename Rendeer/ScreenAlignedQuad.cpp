#include "ScreenAlignedQuad.h"

#include "Buffer.h"

ScreenAlignedQuad::ScreenAlignedQuad()
{
	static const GLfloat vertices[12] = {
		-1.0f, -1.0f,  // bottom left
		-1.0f, 1.0f,   // top left
		1.0f, -1.0f,   // bottom right

		-1.0f, 1.0f,   // top left
		1.0f, 1.0f,    // top right
		1.0f, -1.0f,   // bottom right
	};

	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	Buffer vertexBuffer;
	vertexBuffer.Bind(GL_ARRAY_BUFFER);
	vertexBuffer.SetData(&vertices[0], sizeof(vertices), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
}

ScreenAlignedQuad::~ScreenAlignedQuad()
{
	glDeleteVertexArrays(1, &vertexArray);
}

void ScreenAlignedQuad::Render()
{
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_TRIANGLES, 0, 12);
}
