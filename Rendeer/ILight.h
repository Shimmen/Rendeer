#pragma once

#include <glm/fwd.hpp>

#include "Shader.h"
#include "Transform.h"

class DeferredRenderer;
class PerspectiveCamera;

class ILight
{
public:
	ILight(Shader *shader, const Transform& transform, glm::vec3 color, float intensity)
		: shader(shader)
		, transform(transform)
		, color(color)
		, intensity(intensity) {}

	virtual ~ILight()
	{
		delete shader;
	}

	// this->shader should already be set when function is called
	virtual void SetUniforms(const DeferredRenderer& renderer, const PerspectiveCamera& camera) = 0;

	Shader* GetShader() const { return shader; }
	Transform* GetTransform() { return &transform; }

protected:
	Shader *shader;
	Transform transform;

	glm::vec3 color;
	float intensity;
};
