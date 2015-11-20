#pragma once

#include <glm/fwd.hpp>

#include <memory>

#include "Shader.h"
#include "Texture2D.h"
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
	}

	virtual void SetUniforms(const DeferredRenderer& renderer, Camera& camera) const = 0;
	virtual Camera GetLightCamera(const Camera& mainCamera, int shadowMapSize) const = 0;

	const Shader& GetShader() const { return *shader; }
	
	Transform& GetTransform() { return transform; }
	const Transform& GetTransform() const { return transform; }

	bool CastsShadows() const { return castsShadows; }
	
protected:

	const std::shared_ptr<Shader> shader;
	Transform transform;

	bool castsShadows{false};

	glm::vec3 color;
	float intensity;

};

class DirectionalLight : public ILight
{
public:

	DirectionalLight(const glm::quat& directionRotation, glm::vec3 color, float intensity, bool usingDynamicCameraPositioning = false)
		: ILight(new Shader("Generic/ScreenSpaceQuad.vsh", "Lighting/DirectionalLight.fsh")
		, Transform(glm::vec3(0, 0, 0), glm::normalize(directionRotation)), color, intensity)
		, usingDynamicCameraPositioning(usingDynamicCameraPositioning)
	{
		castsShadows = true;
	}

	virtual ~DirectionalLight() {}

	void SetUniforms(const DeferredRenderer& renderer, Camera& camera) const;
	Camera GetLightCamera(const Camera& mainCamera, int shadowMapSize) const;

private:

	bool usingDynamicCameraPositioning;

};

class PointLight : public ILight
{
public:

	PointLight(const glm::vec3 position, glm::vec3 color, float intensity)
		: ILight(new Shader("Generic/ScreenSpaceQuad.vsh", "Lighting/PointLight.fsh")
		, Transform(position, glm::quat(0, 0, 0, 1)), color, intensity)
	{
		castsShadows = false;
	}

	virtual ~PointLight() {}

	void SetUniforms(const DeferredRenderer& renderer, Camera& camera) const;
	Camera GetLightCamera(const Camera& mainCamera, int shadowMapSize) const;

};

class SpotLight : public ILight
{
public:

	SpotLight(const glm::vec3 position, const glm::quat orientation, glm::vec3 color, float intensity, float outerConeAngle, float innerConeAngle)
		: ILight(new Shader("Generic/ScreenSpaceQuad.vsh", "Lighting/SpotLight.fsh")
		, Transform(position, orientation), color, intensity)
		, outerConeAngle(outerConeAngle), innerConeAngle(innerConeAngle)
	{
		assert(outerConeAngle >= innerConeAngle);
		assert(outerConeAngle >= 0);
		assert(innerConeAngle >= 0);

		castsShadows = true;
	}

	virtual ~SpotLight() {}

	void SetUniforms(const DeferredRenderer& renderer, Camera& camera) const;
	Camera GetLightCamera(const Camera& mainCamera, int shadowMapSize) const;

private:

	float outerConeAngle;
	float innerConeAngle;

};
