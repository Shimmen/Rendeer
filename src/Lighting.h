#pragma once

#include <glm/fwd.hpp>

#include <memory>

#include "Camera.h"
#include "Shader.h"
#include "Texture2D.h"
#include "Transform.h"
#include "FrameBuffer.h"

class Renderer;
class Uniform;

class LightComponent: public Component
{
public:

	LightComponent(Shader *shader, glm::vec3 color, float intensity);
	virtual ~LightComponent() {}

	virtual void SetUniforms(const Renderer& renderer, const CameraComponent& camera) const;
	virtual CameraEntity GetLightCamera(const CameraComponent& mainCamera, int shadowMapSize) const = 0;

	const Shader& GetShader() const { return *shader; }

	bool CastsShadows() const { return castsShadows; }

protected:

	virtual void Init() {};

	const std::shared_ptr<Shader> shader;

	bool castsShadows{false};

public:

	glm::vec3 color;
	float intensity;

private:

	const Uniform *colorUniform;
	const Uniform *intensityUniform;

};

class DirectionalLight : public LightComponent
{
public:

	DirectionalLight(glm::vec3 color, float intensity, bool usingDynamicCameraPositioning = false);
	virtual ~DirectionalLight() {}

	void SetUniforms(const Renderer& renderer, const CameraComponent& camera) const;
	CameraEntity GetLightCamera(const CameraComponent& mainCamera, int shadowMapSize) const;

public:

	bool usingDynamicCameraPositioning;

private:

	const Uniform *directionUniform;
	const Uniform *inverseProjectionUniform;

};

class PointLight : public LightComponent
{
public:

	PointLight(glm::vec3 color, float intensity);
	virtual ~PointLight() {}

	void SetUniforms(const Renderer& renderer, const CameraComponent& camera) const;
	CameraEntity GetLightCamera(const CameraComponent& mainCamera, int shadowMapSize) const;

private:

	const Uniform *positionUniform;
	const Uniform *inverseProjectionUniform;

};

class SpotLight : public LightComponent
{
public:

	SpotLight(glm::vec3 color, float intensity, float outerConeAngle, float innerConeAngle);
	virtual ~SpotLight() {}

	void SetUniforms(const Renderer& renderer, const CameraComponent& camera) const;
	CameraEntity GetLightCamera(const CameraComponent& mainCamera, int shadowMapSize) const;

public:

	float outerConeAngle;
	float innerConeAngle;

private:

	const Uniform *positionUniform;
	const Uniform *directionUniform;
	const Uniform *outerConeAngleUniform;
	const Uniform *innerConeAngleUniform;
	const Uniform *inverseProjectionUniform;

};
