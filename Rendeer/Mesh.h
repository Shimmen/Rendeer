#pragma once

#include <string>
#include <vector>

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
public:
	Vertex(const glm::vec3& position,
		   const glm::vec2& texCoord) :
		position(position),
		texCoord(texCoord) {}

	inline glm::vec3* GetPosition() { return &position;	}
	inline glm::vec2* GetTexCoord() { return &texCoord; }

private:
	glm::vec3 position;
	glm::vec2 texCoord;
};


#define MESH_BUFFER_COUNT 3
enum MeshBuffers
{
	POSITION_BUFFER,
	TEXCOORD_BUFFER,

	INDEX_BUFFER
};

class Mesh
{
public:
	Mesh(Vertex *vertices, unsigned int vertexCount, int *indices, unsigned int indexCount);
	Mesh(const std::string& fileName, bool genSmoothNormals);
		
	void Render();

	~Mesh();

private:
	GLuint vertexArray;
	GLuint buffers[MESH_BUFFER_COUNT];

	unsigned int indexCount;

	GLuint CreateMesh(Vertex *vertices, unsigned int vertexCount,
		int *indices, unsigned int numIndices);
};

