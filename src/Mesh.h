#pragma once

#include "VertexArray.h"

//
// Essentially defines a vertex array that is drawn using indexed vertices with tex-coords, normals, and tangents.
//
class Mesh
{
public:

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

	VertexArray vertexArray;
	size_t indexCount;

};
