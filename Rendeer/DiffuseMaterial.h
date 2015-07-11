#pragma once

#include "IMaterial.h"

class DiffuseMaterial : public IMaterial
{
public:
	DiffuseMaterial()
		: IMaterial(new Shader("Materials/Diffuse.vsh",
							   "Materials/Diffuse.fsh")) {}

	virtual void UpdateUniforms(const DeferredRenderer& renderer,
		const Transform& transform, const PerspectiveCamera& camera);

	// No real need to restrict access to these:
	Texture *diffuseTexture;
	//Texture *normalMap;
	//Texture *specularMap;

	//float specularPower:
};
