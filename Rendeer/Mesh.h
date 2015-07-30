#pragma once

#include <string>
#include <vector>

#include <glm/glm.hpp>
#include <glad/glad.h>

#include "Model.h"

class Mesh
{
public:

	Mesh(const Model& model);
	// Should just serve a shortcut through the Model class
	//Mesh(const std::string& fileName, bool genSmoothNormals);

	~Mesh();

	void Render();

private:

	enum MeshBuffers
	{
		POSITION_BUFFER = 0,
		NORMAL_BUFFER,
		TANGENT_BUFFER,
		TEXCOORD_BUFFER,
		INDEX_BUFFER,

		MESH_BUFFER_COUNT
	};

private:

	GLuint vertexArray;
	size_t indexCount;

	GLuint CreateMesh(const Model& model);

};
