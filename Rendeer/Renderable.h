#pragma once

#include "Component.h"

class Renderable : public Component
{
public:

	Renderable(Mesh& mesh, IMaterial& material)
		: material{ material }
		, mesh{ mesh }
	{
	}

	IMaterial& GetMaterial() { return material; }
	Mesh& GetMesh() { return mesh; }

private:

	virtual void Init() {};

private:

	IMaterial& material;
	Mesh& mesh;

};
