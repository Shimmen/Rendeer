#include "Mesh.h"

#include <iostream>
#include <vector>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

Mesh::Mesh(const Model& model)
{
	indexCount = (unsigned int)model.indices.size();
	vertexArray = CreateMesh(model);
}

GLuint Mesh::CreateMesh(const Model& model)
{
	GLuint vertexArray;
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(MESH_BUFFER_COUNT, buffers);

	int stride = 0; //sizeof(glm::vec3) + sizeof(glm::vec2) + sizeof(glm::vec3);

	///////////////////////
	///////////////////////

	glBindBuffer(GL_ARRAY_BUFFER, buffers[POSITION_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * model.positions.size(), &model.positions[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, 0); // stride and offset is 0 for now

	///////////////////////

	glBindBuffer(GL_ARRAY_BUFFER, buffers[TEXCOORD_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * model.texCoords.size(), &model.texCoords[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, 0); // stride and offset is 0 for now

	///////////////////////

	glBindBuffer(GL_ARRAY_BUFFER, buffers[NORMAL_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * model.normals.size(), &model.normals[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, stride, 0); // stride and offset is 0 for now

	///////////////////////

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[INDEX_BUFFER]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indexCount, &model.indices[0], GL_STATIC_DRAW);

	///////////////////////
	///////////////////////

	// Unbind this just as a security precaution
	// (so nothing regarding the vertex array get changed)
	glBindVertexArray(0);

	return vertexArray;
}

Mesh::~Mesh()
{
	glDeleteBuffers(MESH_BUFFER_COUNT, buffers);
	glDeleteVertexArrays(1, &vertexArray);
}

void Mesh::Render()
{
	glBindVertexArray(vertexArray);
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}