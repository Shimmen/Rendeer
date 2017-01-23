#include "Mesh.h"

#include <glad/glad.h>

#include "Buffer.h"
#include "GeneralUtil.h"

Mesh::Mesh(
	const float *positions,
	const float *normals,
	const float *tangents,
	const float *texCoords,
	unsigned int numVertices,
	const unsigned int *indices,
	unsigned int numIndices)
	: vertexArray{}
	, indexCount{numIndices}
{
	vertexArray.Bind();

	int numBuffers = nonstd::as_integer(MeshBuffers::MESH_BUFFER_COUNT);
	auto buffers = Buffer::GenerateBuffers(numBuffers);

	buffers[nonstd::as_integer(MeshBuffers::POSITION_BUFFER)]->Bind(GL_ARRAY_BUFFER).SetData(positions, numVertices * 3 * sizeof(float), GL_STATIC_DRAW);
	vertexArray.AddVertexAttribute(0, 3, GL_FLOAT);

	// Normals
	buffers[nonstd::as_integer(MeshBuffers::NORMAL_BUFFER)]->Bind(GL_ARRAY_BUFFER).SetData(normals, numVertices * 3 * sizeof(float), GL_STATIC_DRAW);
	vertexArray.AddVertexAttribute(1, 3, GL_FLOAT);

	// Tangents
	buffers[nonstd::as_integer(MeshBuffers::TANGENT_BUFFER)]->Bind(GL_ARRAY_BUFFER).SetData(tangents, numVertices * 3 * sizeof(float), GL_STATIC_DRAW);
	vertexArray.AddVertexAttribute(2, 3, GL_FLOAT);

	// Texture coordinates
	buffers[nonstd::as_integer(MeshBuffers::TEXCOORD_BUFFER)]->Bind(GL_ARRAY_BUFFER).SetData(texCoords, numVertices * 2 * sizeof(float), GL_STATIC_DRAW);
	vertexArray.AddVertexAttribute(3, 2, GL_FLOAT);

	// Indices
	buffers[nonstd::as_integer(MeshBuffers::INDEX_BUFFER)]->Bind(GL_ELEMENT_ARRAY_BUFFER).SetData(indices, numIndices * sizeof(unsigned int), GL_STATIC_DRAW);

	// Unbind this so the buffers can be deleted. The vertex array is a container type
	// so everything applied when it's bound will persist.
	vertexArray.Unbind();}

Mesh::~Mesh()
{
}

void Mesh::Render() const
{
	vertexArray.Bind();
	vertexArray.RenderWithElementArrayBuffer(GL_TRIANGLES, this->indexCount, GL_UNSIGNED_INT);
	vertexArray.Unbind();
}
