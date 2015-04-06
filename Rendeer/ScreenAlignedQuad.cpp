#include "ScreenAlignedQuad.h"

ScreenAlignedQuad::ScreenAlignedQuad()
{
	// Should probably be a singleton in the future,
	// so this sits quite nicely here in that case.
	GLfloat vertices[8] = {
		-1.0f, -1.0f,  // bottom left
		1.0f, -1.0f,   // bottom right
		-1.0f, 1.0f,   // top left
		1.0f, 1.0f,    // top right
	};

	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * 8, (void *)vertices, GL_STATIC_DRAW);
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
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 8);
	glBindVertexArray(0);
}