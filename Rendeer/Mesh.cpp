#include "Mesh.h"

#include <vector>

Mesh::Mesh(Vertex *vertices, unsigned int vertexCount,
	int *indices, unsigned int indexCount) : indexCount(indexCount)
{
	vertexArray = CreateMesh(vertices, vertexCount, indices, indexCount);
}

Mesh::Mesh(const std::string& fileName)
{
	// TODO: Implement with assimp.
}

// This is sort of the real contructor. Maybe fix so this is a REAL contstructor?
GLuint Mesh::CreateMesh(Vertex *vertices, unsigned int vertexCount,
	int *indices, unsigned int indexCount)
{
	std::vector<glm::vec3> positions = std::vector<glm::vec3>();
	std::vector<glm::vec2> texCoords = std::vector<glm::vec2>();

	for (unsigned int i = 0; i < vertexCount; ++i)
	{
		Vertex vertex = vertices[i];
		positions.push_back(*vertex.GetPosition());
		texCoords.push_back(*vertex.GetTexCoord());
	}

	GLuint vertexArray;
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(MESH_BUFFER_COUNT, buffers);

	int stride = sizeof(glm::vec3) + sizeof(glm::vec2);

	///////////////////////
	///////////////////////

	glBindBuffer(GL_ARRAY_BUFFER, buffers[POSITION_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions[0]) * positions.size(), &positions[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // stride and offset is 0 for now

	///////////////////////

	glBindBuffer(GL_ARRAY_BUFFER, buffers[TEXCOORD_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords[0]) * texCoords.size(), &texCoords[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0); // stride and offset is 0 for now
	

	///////////////////////

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[INDEX_BUFFER]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indexCount, indices, GL_STATIC_DRAW);

	///////////////////////
	///////////////////////

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