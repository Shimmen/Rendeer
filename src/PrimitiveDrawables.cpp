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

	vertexArray.Bind();
	
	Buffer vertexBuffer;
	vertexBuffer.Bind(GL_ARRAY_BUFFER);
	vertexBuffer.SetData(&vertices[0], sizeof(vertices), GL_STATIC_DRAW);
	vertexArray.AddVertexAttribute(0, 2, GL_FLOAT, 0, 0);
	
	vertexArray.Unbind();
}

ScreenAlignedQuad::~ScreenAlignedQuad()
{
}

void ScreenAlignedQuad::Render()
{
	vertexArray.Bind();
	vertexArray.RenderWithArrayBuffer(GL_TRIANGLES, 6);
	vertexArray.Unbind();
}

SkyboxCube::SkyboxCube()
{
	static const GLfloat skyboxVertices[] = {
		-10.0f, -10.0f, +10.0f,
		-10.0f, +10.0f, +10.0f,
		+10.0f, +10.0f, +10.0f,
		+10.0f, -10.0f, +10.0f,

		-10.0f, -10.0f, -10.0f,
		-10.0f, +10.0f, -10.0f,
		+10.0f, +10.0f, -10.0f,
		+10.0f, -10.0f, -10.0f,
	};

	static const GLubyte skyboxIndices[] = {

		// As seen from inside the cube

		// Front
		0, 1, 2,
		0, 2, 3,

		// Right
		3, 2, 6,
		3, 6, 7,

		// Left
		4, 5, 1,
		4, 1, 0,

		// Back
		7, 6, 5,
		7, 5, 4,

		// Top
		1, 5, 6,
		1, 6, 2,

		// Bottom
		4, 0, 3,
		4, 3, 7
	};

	vertexArray.Bind();

	Buffer vertexBuffer;
	vertexBuffer.Bind(GL_ARRAY_BUFFER);
	vertexBuffer.SetData(&skyboxVertices[0], sizeof(skyboxVertices), GL_STATIC_DRAW);
	vertexArray.AddVertexAttribute(0, 3, GL_FLOAT, 0, 0);

	Buffer indexBuffer;
	indexBuffer.Bind(GL_ELEMENT_ARRAY_BUFFER);
	indexBuffer.SetData(&skyboxIndices[0], sizeof(skyboxIndices), GL_STATIC_DRAW);

	vertexArray.Unbind();
}

SkyboxCube::~SkyboxCube()
{
}

void SkyboxCube::Render()
{
	// 6 quads * 6 indices/quad
	static const int indexCount = 6 * 6;

	vertexArray.Bind();
	vertexArray.RenderWithElementArrayBuffer(GL_TRIANGLES, indexCount, GL_UNSIGNED_BYTE);
	vertexArray.Unbind();
}
