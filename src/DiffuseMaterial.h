#pragma once

#include "Material.h"
#include "Texture2D.h"

class DiffuseMaterial : public Material
{
public:

	DiffuseMaterial();

	void UpdateUniforms(const DeferredRenderer& renderer,
	                    const Transform& transform,
	                    const CameraComponent& camera) const override;

	// No real need to restrict access to these

	std::shared_ptr<Texture2D> diffuseTexture;
	std::shared_ptr<Texture2D> normalMap;

	float specularIntensity{1.0f};
	float shininess{0.0f};

};
