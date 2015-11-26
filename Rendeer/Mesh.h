#pragma once

#include <string>
#include <vector>

#include <glm/glm.hpp>
#include <glad/glad.h>

#include "Model.h"

class Mesh
{
public:

	Mesh(const std::string& filePath, bool genSmoothNormals = true);
	Mesh(const Model& model);
	~Mesh();

	void Render();

private:

	enum class MeshBuffers
	{
		POSITION_BUFFER = 0,
		NORMAL_BUFFER,
		TANGENT_BUFFER,
		TEXCOORD_BUFFER,
		INDEX_BUFFER,

		MESH_BUFFER_COUNT
	};

private:

	Mesh(Mesh& other) = delete;
	Mesh& operator=(Mesh& other) = delete;

private:

	GLuint vertexArray;
	size_t indexCount;

	GLuint CreateMesh(const Model& model);

};
