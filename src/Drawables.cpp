#include "Drawables.h"

#include "Buffer.h"
#include "Geometry.h"

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
	vertexArray.AddVertexAttribute(0, 2, GL_FLOAT);
	
	vertexArray.Unbind();
}

/*static*/ void ScreenAlignedQuad::Render()
{
	static const ScreenAlignedQuad defaultQuad{};
	defaultQuad.vertexArray.Bind();
	defaultQuad.vertexArray.RenderWithArrayBuffer(GL_TRIANGLES, 6);
	defaultQuad.vertexArray.Unbind();
}

SkyboxCube::SkyboxCube()
{
	static const GLfloat skyboxVertices[] = {
		-1.0f,  1.0f, -1.0f,
		-1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f, -1.0f,  1.0f,
		-1.0f, -1.0f,  1.0f,

		-1.0f,  1.0f, -1.0f,
		1.0f,  1.0f, -1.0f,
		1.0f,  1.0f,  1.0f,
		1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f,  1.0f,
		-1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f, -1.0f,
		1.0f, -1.0f, -1.0f,
		-1.0f, -1.0f,  1.0f,
		1.0f, -1.0f,  1.0f
	};

	vertexArray.Bind();

	Buffer vertexBuffer;
	vertexBuffer.Bind(GL_ARRAY_BUFFER);
	vertexBuffer.SetData(&skyboxVertices[0], sizeof(skyboxVertices), GL_STATIC_DRAW);
	vertexArray.AddVertexAttribute(0, 3, GL_FLOAT);

	vertexArray.Unbind();
}

/*static*/ void SkyboxCube::Render()
{
	// 6 quads * 6 vertices/quad
	static constexpr int vertexCount = 6 * 6;

	static const SkyboxCube skyboxCube{};
	skyboxCube.vertexArray.Bind();
	skyboxCube.vertexArray.RenderWithArrayBuffer(GL_TRIANGLES, vertexCount, 0);
	skyboxCube.vertexArray.Unbind();
}

Sphere::Sphere()
{
	auto sphere = Geometry::Sphere(12, 12, 1.0f, false, false, false);
	indexCount = sphere->GetIndices().size();

	vertexArray.Bind();

	Buffer vertexBuffer;
	vertexBuffer.Bind(GL_ARRAY_BUFFER).SetData(sphere->GetPositions(), GL_STATIC_DRAW);
	vertexArray.AddVertexAttribute(0, 3, GL_FLOAT);

	Buffer indexBuffer;
	indexBuffer.Bind(GL_ELEMENT_ARRAY_BUFFER).SetData(sphere->GetIndices(), GL_STATIC_DRAW);

	vertexArray.Unbind();
}

/*static*/ void Sphere::Render()
{
	static const Sphere sphere{};
	sphere.vertexArray.Bind();
	sphere.vertexArray.RenderWithElementArrayBuffer(GL_TRIANGLES, sphere.indexCount);
	sphere.vertexArray.Unbind();
}
