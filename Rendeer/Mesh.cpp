#include "Mesh.h"


Mesh::Mesh(Vertex *vertices, int *indices, unsigned int numIndices)
{
	vertexArray = CreateMesh(vertices, indices, numIndices);
}

Mesh::Mesh(const std::string& fileName)
{
	// TODO: Implement with assimp.
}

// This is sort of the real contructor. Maybe fix so this is a REAL contstructor?
GLuint Mesh::CreateMesh(Vertex *vertices, int *indices, unsigned int indexCount)
{
	this->indexCount = indexCount;

	GLuint vertexArray;
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(MESH_BUFFER_COUNT, buffers);

	glBindBuffer(GL_ARRAY_BUFFER, buffers[POSITION_BUFFER]);
	// TODO: THERE IS A NUMBER THREE RIGHT THERE!!!
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * 3, vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);




	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[INDEX_BUFFER]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indexCount, indices, GL_STATIC_DRAW);

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