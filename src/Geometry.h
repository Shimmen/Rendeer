#pragma once

#include <vector>
#include <memory>

class Geometry
{
public:

	static std::unique_ptr<Geometry> Sphere(int sectors, int rings, float radius,
											bool genNormals = true, bool genTangents = true, bool genTexCoords = true);

	bool HasTangents() const { return !tangents.empty(); }
	bool HasNormals() const { return !normals.empty(); }
	bool HasTexCoords() const { return !texCoords.empty(); }

	const std::vector<unsigned int>& GetIndices() const { return indices; }
	const std::vector<float>& GetPositions() const { return positions; }
	const std::vector<float>& GetNormals() const { return normals; }
	const std::vector<float>& GetTangents() const { return tangents; }
	const std::vector<float>& GetTexCoords() const { return texCoords; }

private:

	// Required
	std::vector<unsigned int> indices;
	std::vector<float> positions;

	// Optional
	std::vector<float> tangents;
	std::vector<float> normals;
	std::vector<float> texCoords;

};
