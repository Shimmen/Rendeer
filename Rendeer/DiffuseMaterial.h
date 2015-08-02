#pragma once

#include "IMaterial.h"

class DiffuseMaterial : public IMaterial
{
public:

	DiffuseMaterial();

	virtual void UpdateUniforms(const DeferredRenderer& renderer,
	                            const Transform& transform,
	                            const PerspectiveCamera& camera);

	// No real need to restrict access to these:

	Texture *diffuseTexture;
	Texture *normalMap;
	//Texture *specularMap;

	float specularIntensity{1.0f};
	float shininess{0.0f};

};
