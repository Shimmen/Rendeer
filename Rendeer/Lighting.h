#pragma once

#include <glm/fwd.hpp>

#include "Shader.h"
#include "Texture.h"
#include "Transform.h"
#include "FrameBuffer.h"

class DeferredRenderer;
class Camera;

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

	virtual void SetUniforms(const DeferredRenderer& renderer, Camera& camera) const = 0;
	virtual Camera GetLightCamera() const = 0;

	const Shader& GetShader() const { return *shader; }
	
	Transform& GetTransform() { return transform; }
	const Transform& GetTransform() const { return transform; }

	bool CastsShadows() const { return castsShadows; }
	
protected:

	const Shader *shader;
	Transform transform;

	bool castsShadows{false};

	glm::vec3 color;
	float intensity;

};

class DirectionalLight : public ILight
{
public:

	DirectionalLight(const glm::quat& directionRotation, glm::vec3 color, float intensity)
		: ILight(new Shader("postprocess.vsh", "Lighting/DirectionalLight.fsh")
		, Transform(glm::vec3(0, 0, 0), glm::normalize(directionRotation), 1.0f), color, intensity)
	{
		castsShadows = true;
	}

	virtual ~DirectionalLight() {}

	void SetUniforms(const DeferredRenderer& renderer, Camera& camera) const;
	Camera GetLightCamera() const;

};

class PointLight : public ILight
{
public:

	PointLight(const glm::vec3 position, glm::vec3 color, float intensity)
		: ILight(new Shader("postprocess.vsh", "Lighting/PointLight.fsh")
		, Transform(position, glm::quat(0, 0, 0, 1), 1.0f), color, intensity)
	{
		castsShadows = false;
	}

	virtual ~PointLight() {}

	void SetUniforms(const DeferredRenderer& renderer, Camera& camera) const;
	Camera GetLightCamera() const;

};

class SpotLight : public ILight
{
public:

	SpotLight(const glm::vec3 position, const glm::quat orientation, glm::vec3 color, float intensity, float outerConeAngle, float innerConeAngle)
		: ILight(new Shader("postprocess.vsh", "Lighting/SpotLight.fsh")
		, Transform(position, orientation, 1.0f), color, intensity)
		, outerConeAngle(outerConeAngle), innerConeAngle(innerConeAngle)
	{
		assert(outerConeAngle >= innerConeAngle);
		assert(outerConeAngle >= 0);
		assert(innerConeAngle >= 0);

		castsShadows = true;
	}

	virtual ~SpotLight() {}

	void SetUniforms(const DeferredRenderer& renderer, Camera& camera) const;
	Camera GetLightCamera() const;

private:

	float outerConeAngle;
	float innerConeAngle;

};
