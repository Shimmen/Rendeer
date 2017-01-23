#pragma once

#include <string>
#include <vector>

#include <glm/glm.hpp>
#include <glad/glad.h>

#include "Model.h"
#include "VertexArray.h"

//
// Essentially defines a vertex array that is drawn using indexed vertices with tex-coords, normals, and tangents.
//
class Mesh
{
public:

	Mesh(const Model& model);
	Mesh(const std::string& filePath, bool genSmoothNormals = true);

	// The positions, normals, and tangents are assumed to be encoded as three floats.
	// Texture coordinates are assumed to be encoded as two floats.
	Mesh(
		const float *positions,
		const float *normals,
		const float *tangents,
		const float *texCoords,
		unsigned int numVertices,
		const unsigned int *indices,
		unsigned int numIndices
	);

	~Mesh();

	void Render() const;

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
