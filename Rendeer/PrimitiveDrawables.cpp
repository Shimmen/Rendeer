#include "PrimitiveDrawables.h"

#include "Buffer.h"

ScreenAlignedQuad::ScreenAlignedQuad()
{
	static const GLfloat vertices[] = {
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
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

SkyboxCube::SkyboxCube()
{
	static const GLfloat skyboxVertices[] = {

		// Directions relative to outside looking at the box
		
		// Front
		-10.0f, -10.0f, -10.0f,
		-10.0f, 10.0f, -10.0f,
		10.0f, 10.0f, -10.0f,

		-10.0f, -10.0f, -10.0f,
		10.0f, 10.0f, -10.0f,
		10.0f, -10.0f, -10.0f,

		// Right
		10.0f, -10.0f, -10.0f,
		10.0f, 10.0f, -10.0f,
		10.0f, 10.0f, 10.0f,

		10.0f, -10.0f, -10.0f,
		10.0f, 10.0f, 10.0f,
		10.0f, -10.0f, 10.0f,

		// Back
		10.0f, -10.0f, 10.0f,
		10.0f, 10.0f, 10.0f,
		-10.0f, 10.0f, 10.0f,

		10.0f, -10.0f, 10.0f,
		-10.0f, 10.0f, 10.0f,
		-10.0f, -10.0f, 10.0f,

		// Left
		-10.0f, -10.0f, 10.0f,
		-10.0f, 10.0f, 10.0f,
		-10.0f, 10.0f, -10.0f,

		-10.0f, -10.0f, 10.0f,
		-10.0f, 10.0f, -10.0f,
		-10.0f, -10.0f, -10.0f,

		// Bottom
		-10.0f, -10.0f, 10.0f,
		-10.0f, -10.0f, -10.0f,
		10.0f, -10.0f, -10.0f,
		
		-10.0f, -10.0f, 10.0f,
		10.0f, -10.0f, -10.0f,
		10.0f, -10.0f, 10.0f,

		// Top
		-10.0f, 10.0f, -10.0f,
		-10.0f, 10.0f, 10.0f,
		10.0f, 10.0f, 10.0f,

		-10.0f, 10.0f, -10.0f,
		10.0f, 10.0f, 10.0f,
		10.0f, 10.0f, -10.0f

	};

	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	Buffer vertexBuffer;
	vertexBuffer.Bind(GL_ARRAY_BUFFER);
	vertexBuffer.SetData(&skyboxVertices[0], sizeof(skyboxVertices), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
}

SkyboxCube::~SkyboxCube()
{
	glDeleteVertexArrays(1, &vertexArray);
}

void SkyboxCube::Render()
{
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_TRIANGLES, 0, 6 * 6); // 6 quads * 6 vertices/quad
}
