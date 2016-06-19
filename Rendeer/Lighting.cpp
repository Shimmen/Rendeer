#include "Lighting.h"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

#include "Shader.h"
#include "Uniform.h"
#include "DeferredRenderer.h"
#include "Camera.h"

ILight::ILight(Shader *shader, const Transform& transform, glm::vec3 color, float intensity)
	: shader{ shader }
	, transform{ transform }
	, color{ color }
	, intensity{ intensity }
{
	this->colorUniform = shader->GetUniformWithName("u_light_color");
	this->intensityUniform = shader->GetUniformWithName("u_light_intensity");
}

void ILight::SetUniforms(const DeferredRenderer& renderer, Camera& camera) const
{
	shader->Bind();

	colorUniform->Set(this->color);
	intensityUniform->Set(this->intensity);
}

DirectionalLight::DirectionalLight(const glm::quat& directionRotation, glm::vec3 color, float intensity, bool usingDynamicCameraPositioning)
	: ILight{
	new Shader{ "Generic/ScreenSpaceQuad.vsh", "Lighting/DirectionalLight.fsh" }
	, Transform{ glm::vec3{ 0, 0, 0 }, glm::normalize(directionRotation) }
	, color, intensity }
	, usingDynamicCameraPositioning{ usingDynamicCameraPositioning }
{
	castsShadows = true;

	this->directionUniform = shader->GetUniformWithName("u_light_direction");
	this->inverseProjectionUniform = shader->GetUniformWithName("u_inverse_projection_matrix");
}

void DirectionalLight::SetUniforms(const DeferredRenderer& renderer, Camera& camera) const
{
	ILight::SetUniforms(renderer, camera);

	auto lightForward = this->transform.GetForward();

	glm::quat conjugateCameraOrientation = glm::conjugate(camera.GetTransform().GetOrientation());
	auto viewSpaceLightForward = glm::rotate(conjugateCameraOrientation, lightForward);
	
	directionUniform->Set(viewSpaceLightForward);

	inverseProjectionUniform->Set(glm::inverse((camera.GetProjectionMatrix())));
}

Camera DirectionalLight::GetLightCamera(const Camera& mainCamera, int shadowMapSize) const
{
	const float cameraNear = 0.0f;
	const float cameraFar = 100.0f;
	const float cameraScale = 10.0f;

	glm::quat worldLightOrientation = this->GetTransform().GetOrientation();
	glm::vec3 worldLightPosition = this->GetTransform().GetPosition();

	if (usingDynamicCameraPositioning)
	{
		// Place the directional light camera at the main camera position and offset it by the looking direction
		// and the light camera near plane, so that the near plane essantially lies at the main camera.
		worldLightPosition = mainCamera.GetTransform().GetPosition() + mainCamera.GetTransform().GetForward() * -cameraNear;

		// Rotate position into light space
		glm::vec4 lightSpaceLightPosition = glm::rotate(glm::conjugate(worldLightOrientation), glm::vec4(worldLightPosition, 1.0f));

		// Quantize position to a light space shadow map texel size
		float lightSpaceTexelSize = (cameraScale * 2.0f) / float(shadowMapSize);
		lightSpaceLightPosition.x = lightSpaceTexelSize * floorf(lightSpaceLightPosition.x / lightSpaceTexelSize);
		lightSpaceLightPosition.y = lightSpaceTexelSize * floorf(lightSpaceLightPosition.y / lightSpaceTexelSize);

		// Rotate back into world space
		worldLightPosition = glm::vec3(glm::rotate(worldLightOrientation, lightSpaceLightPosition));
	}

	return Camera(worldLightPosition, worldLightOrientation,
	              1.0f, cameraNear, cameraFar, cameraScale, CameraComponent::CameraType::ORTHOGRAPHIC);
}

PointLight::PointLight(const glm::vec3 position, glm::vec3 color, float intensity)
	: ILight{
	new Shader{ "Generic/ScreenSpaceQuad.vsh", "Lighting/PointLight.fsh" }
	, Transform{ position, glm::quat{ 0, 0, 0, 1 } }
	, color, intensity }
{
	castsShadows = false;

	this->positionUniform = shader->GetUniformWithName("u_light_position");
	this->inverseProjectionUniform = shader->GetUniformWithName("u_inverse_projection_matrix");
}

void PointLight::SetUniforms(const DeferredRenderer& renderer, Camera& camera) const
{
	ILight::SetUniforms(renderer, camera);

	auto viewSpaceLightPosition = glm::vec3(camera.GetViewMatrix() * glm::vec4(this->transform.GetPosition(), 1.0f));
	positionUniform->Set(viewSpaceLightPosition);

	inverseProjectionUniform->Set(glm::inverse((camera.GetProjectionMatrix())));
}

Camera PointLight::GetLightCamera(const Camera& mainCamera, int shadowMapSize) const
{
	// TODO: This doesn't make sense since it's omnidirectional
	return Camera(this->GetTransform().GetPosition(),
	              this->GetTransform().GetOrientation(),
	              1.0f, 1.0f, 100.0f, glm::radians(90.0f), CameraComponent::CameraType::PERSPECTIVE);
}

SpotLight::SpotLight(const glm::vec3 position, const glm::quat orientation, glm::vec3 color, float intensity, float outerConeAngle, float innerConeAngle)
	: ILight{
	new Shader{ "Generic/ScreenSpaceQuad.vsh", "Lighting/SpotLight.fsh" }
	, Transform{ position, orientation }
	, color, intensity }
	, outerConeAngle{ outerConeAngle }
	, innerConeAngle{ innerConeAngle }
{
	assert(outerConeAngle >= innerConeAngle);
	assert(outerConeAngle >= 0);
	assert(innerConeAngle >= 0);

	castsShadows = true;

	this->positionUniform = shader->GetUniformWithName("u_light_position");
	this->directionUniform = shader->GetUniformWithName("u_light_direction");
	this->outerConeAngleUniform = shader->GetUniformWithName("u_light_outer_cone_angle_cos");
	this->innerConeAngleUniform = shader->GetUniformWithName("u_light_inner_cone_angle_cos");
	this->inverseProjectionUniform = shader->GetUniformWithName("u_inverse_projection_matrix");
}

void SpotLight::SetUniforms(const DeferredRenderer& renderer, Camera& camera) const
{
	ILight::SetUniforms(renderer, camera);

	auto viewSpaceLightPosition = glm::vec3(camera.GetViewMatrix() * glm::vec4(this->transform.GetPosition(), 1.0f));

	auto lightForward = this->transform.GetForward();

	glm::quat conjugateCameraOrientation = glm::conjugate(camera.GetTransform().GetOrientation());
	auto viewSpaceLightForward = glm::rotate(conjugateCameraOrientation, lightForward);

	positionUniform->Set(viewSpaceLightPosition);
	directionUniform->Set(viewSpaceLightForward);
	outerConeAngleUniform->Set(cosf(this->outerConeAngle / 2.0f));
	innerConeAngleUniform->Set(cosf(this->innerConeAngle / 2.0f));

	inverseProjectionUniform->Set(glm::inverse((camera.GetProjectionMatrix())));
}

Camera SpotLight::GetLightCamera(const Camera& mainCamera, int shadowMapSize) const
{
	return Camera(this->GetTransform().GetPosition(),
	              this->GetTransform().GetOrientation(),
	              1.0f, 1.0f, 100.0f, outerConeAngle, CameraComponent::CameraType::PERSPECTIVE);
}
