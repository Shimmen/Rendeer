#pragma once

#include <string>
#include <vector>

#include <glm/glm.hpp>

class Model
{
public:
	Model(const std::string& fileName);
	Model() {} // for manually inserting values

	std::vector<glm::vec3> positions;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec3> tangents;
	std::vector<glm::vec2> texCoords;
	std::vector<unsigned int> indices;
};
