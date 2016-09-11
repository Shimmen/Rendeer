#include "Mesh.h"

#include <iostream>
#include <vector>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Buffer.h"
#include "GeneralUtil.h"

Mesh::Mesh(const std::string& filePath, bool genSmoothNormals)
	: Mesh{ Model{filePath, genSmoothNormals} }
{
}

Mesh::Mesh(const Model& model)
	: vertexArray{}
	, indexCount{ model.indices.size() }
{
	vertexArray.Bind();

	auto buffers = Buffer::GenerateBuffers(nonstd::as_integer(MeshBuffers::MESH_BUFFER_COUNT));

	// TODO: Use stride and offset!
	int stride = 0;
	INT64 offset = 0;

	// Positions
	buffers[nonstd::as_integer(MeshBuffers::POSITION_BUFFER)].Bind(GL_ARRAY_BUFFER).SetData(model.positions, GL_STATIC_DRAW);
	vertexArray.AddVertexAttribute(0, 3, GL_FLOAT, stride, (void *)offset);

	// Normals
	buffers[nonstd::as_integer(MeshBuffers::NORMAL_BUFFER)].Bind(GL_ARRAY_BUFFER).SetData(model.normals, GL_STATIC_DRAW);
	vertexArray.AddVertexAttribute(1, 3, GL_FLOAT, stride, (void *)offset);

	// Tangents
	buffers[nonstd::as_integer(MeshBuffers::TANGENT_BUFFER)].Bind(GL_ARRAY_BUFFER).SetData(model.tangents, GL_STATIC_DRAW);
	vertexArray.AddVertexAttribute(2, 3, GL_FLOAT, stride, (void *)offset);

	// Texture coordinates
	buffers[nonstd::as_integer(MeshBuffers::TEXCOORD_BUFFER)].Bind(GL_ARRAY_BUFFER).SetData(model.textureCoordinates, GL_STATIC_DRAW);
	vertexArray.AddVertexAttribute(3, 2, GL_FLOAT, stride, (void *)offset);

	// Indices
	buffers[nonstd::as_integer(MeshBuffers::INDEX_BUFFER)].Bind(GL_ELEMENT_ARRAY_BUFFER).SetData(model.indices, GL_STATIC_DRAW);

	// Unbind this so the buffers can be deleted. The vertex array is a container type
	// so everything applied when it's bound will persist.
	vertexArray.Unbind();
}

Mesh::~Mesh()
{
}

void Mesh::Render() const
{
	vertexArray.Bind();
	vertexArray.RenderWithElementArrayBuffer(GL_TRIANGLES, this->indexCount, GL_UNSIGNED_INT);
	vertexArray.Unbind();
}
