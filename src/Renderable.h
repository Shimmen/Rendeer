#pragma once

#include "Component.h"
#include "IMaterial.h"
#include "Mesh.h"

class Renderable : public Component
{
public:

	Renderable(std::shared_ptr<Mesh> mesh, std::shared_ptr<IMaterial> material)
		: Component{}
		, material{ material }
		, mesh{ mesh }
	{
	}

	const std::shared_ptr<IMaterial> GetMaterial() const { return material; }
	const std::shared_ptr<Mesh> GetMesh() const { return mesh; }

private:

	virtual void Init() {};

private:

	std::shared_ptr<IMaterial> material;
	std::shared_ptr<Mesh> mesh;

};
