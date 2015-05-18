#include "ScreenAlignedQuad.h"

ScreenAlignedQuad::ScreenAlignedQuad()
{
	// Should probably be a singleton in the future,
	// so this sits quite nicely here in that case.
	GLfloat vertices[12] = {
		-1.0f, -1.0f,  // bottom left
		-1.0f, 1.0f,   // top left
		1.0f, -1.0f,   // bottom right
		
		-1.0f, 1.0f,   // top left
		1.0f, 1.0f,    // top right
		1.0f, -1.0f,   // bottom right
	};

	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * 12, (void *)vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

ScreenAlignedQuad::~ScreenAlignedQuad()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteVertexArrays(1, &vertexArray);
}

void ScreenAlignedQuad::Render()
{
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_TRIANGLES, 0, 12);
	glBindVertexArray(0);
}