#pragma once

#include <string>
#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
public:
	Vertex(const glm::vec3& position) :
		position(position) {}

	inline glm::vec3* GetPosition() { return &position;	}

private:
	glm::vec3 position;
};


#define MESH_BUFFER_COUNT 2
enum MeshBuffers
{
	POSITION_BUFFER,
	// more buffers
	// like texture coords
	// and normals and tangents

	INDEX_BUFFER
};

class Mesh
{
public:
	Mesh(Vertex *vertices, int *indices, unsigned int numIndices);
	Mesh(const std::string& fileName);
		
	void Render();

	~Mesh();

private:
	GLuint vertexArray;
	GLuint buffers[MESH_BUFFER_COUNT];

	unsigned int indexCount;

	GLuint CreateMesh(Vertex *vertices, int *indices, unsigned int numIndices);
};

