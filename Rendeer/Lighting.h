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
		, intensity(intensity)
	{
	}

	virtual ~ILight()
	{
		delete shader;
	}

	// this->shader should already be set when function is called
	virtual void SetUniforms(const DeferredRenderer& renderer, PerspectiveCamera& camera) = 0;

	Shader* GetShader() const { return shader; }
	Transform* GetTransform() { return &transform; }

protected:

	Shader *shader;
	Transform transform;

	glm::vec3 color;
	float intensity;

};

class DirectionalLight : public ILight
{
public:

	DirectionalLight(const glm::quat& directionRotation, glm::vec3 color, float intensity)
		: ILight(new Shader("postprocess.vsh", "Lights/DirectionalLight.fsh")
		, Transform(glm::vec3(0, 0, 0), glm::normalize(directionRotation), 1.0f), color, intensity)
	{
	}

	virtual ~DirectionalLight() {}

	void SetUniforms(const DeferredRenderer& renderer, PerspectiveCamera& camera);

};

class PointLight : public ILight
{
public:

	PointLight(const glm::vec3 position, glm::vec3 color, float intensity)
		: ILight(new Shader("postprocess.vsh", "Lights/PointLight.fsh")
		, Transform(position, glm::quat(0, 0, 0, 1), 1.0f), color, intensity)
	{
	}

	virtual ~PointLight() {}

	void SetUniforms(const DeferredRenderer& renderer, PerspectiveCamera& camera);

};

class SpotLight : public ILight
{
public:

	SpotLight(const glm::vec3 position, const glm::quat orientation, glm::vec3 color, float intensity, float outerConeAngle, float innerConeAngle)
		: ILight(new Shader("postprocess.vsh", "Lights/SpotLight.fsh")
		, Transform(position, orientation, 1.0f), color, intensity)
		, outerConeAngle(outerConeAngle), innerConeAngle(innerConeAngle)
	{
		assert(outerConeAngle >= innerConeAngle);
		assert(outerConeAngle >= 0);
		assert(innerConeAngle >= 0);
	}

	virtual ~SpotLight() {}

	void SetUniforms(const DeferredRenderer& renderer, PerspectiveCamera& camera);

private:

	float outerConeAngle;
	float innerConeAngle;

};
