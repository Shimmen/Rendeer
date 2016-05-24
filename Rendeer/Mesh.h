#pragma once

#include <string>
#include <vector>

#include <glm/glm.hpp>
#include <glad/glad.h>

#include "Model.h"
#include "VertexArray.h"

class Mesh
{
public:

	Mesh(const Model& model);
	Mesh(const std::string& filePath, bool genSmoothNormals = true);
	~Mesh();

	void Render() const;

private:

	// Non-copyable
	Mesh(Mesh& other) = delete;
	Mesh& operator=(Mesh& other) = delete;

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

	VertexArray vertexArray;
	size_t indexCount;

};
