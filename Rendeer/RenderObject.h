#pragma once

#include <string>

#include "Transform.h"
#include "Material.h"
#include "Mesh.h"

class Shader;

class RenderObject
{
public:
	//RenderObject(const std::string& fileName);
	RenderObject(const Mesh& mesh);

	void Render(const Shader& shader);

	inline Mesh* GetMesh() { return &mesh; }

private:
	Transform transform;
	Mesh mesh;
	Material material;
};
