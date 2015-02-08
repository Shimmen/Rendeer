#include "ScreenAlignedQuad.h"

ScreenAlignedQuad::ScreenAlignedQuad()
{
	// Should probably be a singleton in the future,
	// so this sits quite nicely here in that case.
	float vertices[8] = {
		-1.0f, -1.0f,
		1.0f, -1.0f,
		-1.0f, 1.0f,
		1.0f, 1.0f
	};

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8, (void *)vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

ScreenAlignedQuad::~ScreenAlignedQuad()
{
	glDeleteBuffers(1, &vertexBuffer);
}

void ScreenAlignedQuad::Render()
{
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 8);
}