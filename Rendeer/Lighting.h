#pragma once

#include <glm/fwd.hpp>

#include <memory>

#include "Shader.h"
#include "Texture2D.h"
#include "Transform.h"
#include "FrameBuffer.h"

class DeferredRenderer;
class Uniform;
class Camera;

class ILight
{
public:

	ILight(Shader *shader, const Transform& transform, glm::vec3 color, float intensity);
	virtual ~ILight() {}

	virtual void SetUniforms(const DeferredRenderer& renderer, Camera& camera) const;
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

	const Uniform *colorUniform;
	const Uniform *intensityUniform;

};

class DirectionalLight : public ILight
{
public:

	DirectionalLight(const glm::quat& directionRotation, glm::vec3 color, float intensity, bool usingDynamicCameraPositioning = false);
	virtual ~DirectionalLight() {}

	void SetUniforms(const DeferredRenderer& renderer, Camera& camera) const;
	Camera GetLightCamera(const Camera& mainCamera, int shadowMapSize) const;

private:

	bool usingDynamicCameraPositioning;

	const Uniform *directionUniform;
	const Uniform *inverseProjectionUniform;

};

class PointLight : public ILight
{
public:

	PointLight(const glm::vec3 position, glm::vec3 color, float intensity);
	virtual ~PointLight() {}

	void SetUniforms(const DeferredRenderer& renderer, Camera& camera) const;
	Camera GetLightCamera(const Camera& mainCamera, int shadowMapSize) const;

private:

	const Uniform *positionUniform;
	const Uniform *inverseProjectionUniform;

};

class SpotLight : public ILight
{
public:

	SpotLight(const glm::vec3 position, const glm::quat orientation, glm::vec3 color, float intensity, float outerConeAngle, float innerConeAngle);
	virtual ~SpotLight() {}

	void SetUniforms(const DeferredRenderer& renderer, Camera& camera) const;
	Camera GetLightCamera(const Camera& mainCamera, int shadowMapSize) const;

private:

	float outerConeAngle;
	float innerConeAngle;

	const Uniform *positionUniform;
	const Uniform *directionUniform;
	const Uniform *outerConeAngleUniform;
	const Uniform *innerConeAngleUniform;
	const Uniform *inverseProjectionUniform;

};
