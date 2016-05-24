#pragma once

#include "Component.h"

class Renderable : public Component
{
public:

	Renderable(Mesh& mesh, IMaterial& material)
		: Component{}
		, material{ material }
		, mesh{ mesh }
	{
	}

	const IMaterial& GetMaterial() const { return material; }
	const Mesh& GetMesh() const { return mesh; }

private:

	virtual void Init() {};

private:

	IMaterial& material;
	Mesh& mesh;

};
