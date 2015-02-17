#pragma once

#include <string>
#include <vector>

#include <glm/glm.hpp>
#include <GL/glew.h>

#include "Model.h"

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


enum MeshBuffers
{
	POSITION_BUFFER = 0,
	TEXCOORD_BUFFER,
	NORMAL_BUFFER,
	INDEX_BUFFER,

	MESH_BUFFER_COUNT
};

class Mesh
{
public:
	Mesh(const Model& model);
	// Should just serve a shortcut through the Model class
	//Mesh(const std::string& fileName, bool genSmoothNormals);
		
	void Render();

	~Mesh();

private:
	GLuint vertexArray;
	GLuint buffers[MESH_BUFFER_COUNT];

	unsigned int indexCount;

	GLuint CreateMesh(const Model& model);
	GLuint CreateMesh(Vertex *vertices, unsigned int vertexCount,
		int *indices, unsigned int numIndices);
};

