#pragma once

#include "Component.h"
#include "Material.h"
#include "Mesh.h"

class Renderable : public Component
{
public:

	Renderable(std::shared_ptr<Mesh> mesh, std::shared_ptr<Material> material)
		: Component{}
		, material{ material }
		, mesh{ mesh }
	{
	}

	const std::shared_ptr<Material> GetMaterial() const { return material; }
	const std::shared_ptr<Mesh> GetMesh() const { return mesh; }

private:

	virtual void Init() {};

private:

	std::shared_ptr<Material> material;
	std::shared_ptr<Mesh> mesh;

};
