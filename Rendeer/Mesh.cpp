#include "Mesh.h"

#include <iostream>
#include <vector>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Buffer.h"

Mesh::Mesh(const std::string& filePath, bool genSmoothNormals)
	: Mesh{ Model{filePath, genSmoothNormals} }
{
}

Mesh::Mesh(const Model& model)
{
	this->indexCount = model.indices.size();
	this->vertexArray = CreateMesh(model);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &vertexArray);
}

void Mesh::Render()
{
	glBindVertexArray(vertexArray);
	glDrawElements(GL_TRIANGLES, (GLsizei)indexCount, GL_UNSIGNED_INT, 0);
}

GLuint Mesh::CreateMesh(const Model& model)
{
	GLuint vertexArray;
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	auto buffers = Buffer::GenerateBuffers(MESH_BUFFER_COUNT);

	// TODO: Use stride and offset!
	int stride = 0;
	INT64 offset = 0;

	// Positions
	buffers[POSITION_BUFFER].Bind(GL_ARRAY_BUFFER).SetData(model.positions, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void *)offset);

	// Normals
	buffers[NORMAL_BUFFER].Bind(GL_ARRAY_BUFFER).SetData(model.normals, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void *)offset);

	// Tangents
	buffers[TANGENT_BUFFER].Bind(GL_ARRAY_BUFFER).SetData(model.tangents, GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, stride, (void *)offset);

	// Texture coordinates
	buffers[TEXCOORD_BUFFER].Bind(GL_ARRAY_BUFFER).SetData(model.texCoords, GL_STATIC_DRAW);
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, stride, (void *)offset);

	// Indices
	buffers[INDEX_BUFFER].Bind(GL_ELEMENT_ARRAY_BUFFER).SetData(model.indices, GL_STATIC_DRAW);

	// Unbind this so the buffers can be deleted. The vertex array is a container type
	// so everything applied when it's bound will persist.
	glBindVertexArray(0);

	return vertexArray;
}

