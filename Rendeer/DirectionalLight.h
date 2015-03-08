#pragma once

#include "ILight.h"

#include <glm/fwd.hpp>

#include "Transform.h"

class PerspectiveCamera;

class DirectionalLight: public ILight
{
public:
	DirectionalLight(const glm::quat& directionRotation, glm::vec3 color, float intensity)
		: ILight(new Shader("shaders/postprocess.vsh", "shaders/Lights/DirectionalLight.fsh"),
		         Transform(glm::vec3(0, 0, 0), directionRotation, 1.0f),
				 color, intensity) {}

	virtual ~DirectionalLight() {}

	void SetUniforms(const DeferredRenderer& renderer, const PerspectiveCamera& camera);
};
