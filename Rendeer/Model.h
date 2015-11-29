#pragma once

#include <string>
#include <vector>

#include <glm/glm.hpp>

class Model
{
public:

	Model(const std::string& fileName, bool genSmoothNormals = true);
	Model();
	~Model();

	bool HasPositions() const;
	bool HasNormals() const;
	bool HasTangents() const;
	bool HasTextureCoordinates() const;
	bool HasIndices() const;

public:

	// There is no good reason to restrict access to these.

	std::vector<glm::vec3> positions;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec3> tangents;
	std::vector<glm::vec2> textureCoordinates;
	std::vector<unsigned int> indices;

};
