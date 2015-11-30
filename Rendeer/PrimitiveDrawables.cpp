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

	vertexArray.Bind();

	Buffer vertexBuffer;
	vertexBuffer.Bind(GL_ARRAY_BUFFER);
	vertexBuffer.SetData(&skyboxVertices[0], sizeof(skyboxVertices), GL_STATIC_DRAW);
	vertexArray.AddVertexAttribute(0, 3, GL_FLOAT, 0, 0);

	vertexArray.Unbind();
}

SkyboxCube::~SkyboxCube()
{
}

void SkyboxCube::Render()
{
	// 6 quads * 6 vertices/quad
	static const int vertexCount = 6 * 6;

	vertexArray.Bind();
	vertexArray.RenderWithArrayBuffer(GL_TRIANGLES, vertexCount);
	vertexArray.Unbind();
}
