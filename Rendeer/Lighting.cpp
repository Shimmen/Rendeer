#include "Lighting.h"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

#include "Shader.h"
#include "DeferredRenderer.h"
#include "Camera.h"

void DirectionalLight::SetUniforms(const DeferredRenderer& renderer, Camera& camera) const
{
	shader->Bind();

	auto lightForward = this->transform.GetForward();
	auto viewSpaceLightForward = camera.GetTransform().GetInverse().RotateVector(lightForward);

	shader->SetUniform("u_light_direction", viewSpaceLightForward);
	shader->SetUniform("u_light_color", this->color);
	shader->SetUniform("u_light_intensity", this->intensity);

	shader->SetUniform("u_inverse_projection_matrix", glm::inverse((camera.GetProjectionMatrix())));
}

Camera DirectionalLight::GetLightCamera(const Camera& mainCamera, int shadowMapSize) const
{
	const float cameraNear = -25.0f;
	const float cameraFar = 25.0f;
	const float cameraScale = 25.0f;

	glm::quat worldLightOrientation = this->GetTransform().GetOrientation();

	// Place the directional light camera at the main camera position and offset it by the looking direction
	// and the light camera near plane, so that the near plane essantially lies at the main camera.
	glm::vec3 worldLightPosition = mainCamera.GetTransform().GetPosition() + mainCamera.GetTransform().GetForward() * -cameraNear;

	// Rotate position into light space
	glm::vec4 lightSpaceLightPosition = glm::rotate(glm::conjugate(worldLightOrientation), glm::vec4(worldLightPosition, 1.0f));

	// Quantize position to a light space shadow map texel size
	float lightSpaceTexelSize = (cameraScale * 2.0f) / float(shadowMapSize);
	lightSpaceLightPosition.x = lightSpaceTexelSize * floorf(lightSpaceLightPosition.x / lightSpaceTexelSize);
	lightSpaceLightPosition.y = lightSpaceTexelSize * floorf(lightSpaceLightPosition.y / lightSpaceTexelSize);

	// Rotate back into world space
	worldLightPosition = glm::vec3(glm::rotate(worldLightOrientation, lightSpaceLightPosition));

	return Camera(worldLightPosition, worldLightOrientation,
	              1.0f, cameraNear, cameraFar, cameraScale, Camera::ORTHOGRAPHIC);
}

void PointLight::SetUniforms(const DeferredRenderer& renderer, Camera& camera) const
{
	shader->Bind();

	auto viewSpaceLightPosition = glm::vec3(camera.GetViewMatrix() * glm::vec4(this->transform.GetPosition(), 1.0f));

	shader->SetUniform("u_light_position", viewSpaceLightPosition);
	shader->SetUniform("u_light_color", this->color);
	shader->SetUniform("u_light_intensity", this->intensity);

	shader->SetUniform("u_inverse_projection_matrix", glm::inverse((camera.GetProjectionMatrix())));
}

Camera PointLight::GetLightCamera(const Camera& mainCamera, int shadowMapSize) const
{
	// TODO: This doesn't make sense since it's omnidirectional
	return Camera(this->GetTransform().GetPosition(),
	              this->GetTransform().GetOrientation(),
	              1.0f, 1.0f, 100.0f, glm::radians(90.0f), Camera::PERSPECTIVE);
}

void SpotLight::SetUniforms(const DeferredRenderer& renderer, Camera& camera) const
{
	shader->Bind();

	auto viewSpaceLightPosition = glm::vec3(camera.GetViewMatrix() * glm::vec4(this->transform.GetPosition(), 1.0f));

	auto lightForward = this->transform.GetForward();
	auto viewSpaceLightForward = camera.GetTransform().GetInverse().RotateVector(lightForward);

	shader->SetUniform("u_light_position", viewSpaceLightPosition);
	shader->SetUniform("u_light_direction", viewSpaceLightForward);
	shader->SetUniform("u_light_outer_cone_angle_cos", cosf(this->outerConeAngle / 2.0f));
	shader->SetUniform("u_light_inner_cone_angle_cos", cosf(this->innerConeAngle / 2.0f));
	shader->SetUniform("u_light_color", this->color);
	shader->SetUniform("u_light_intensity", this->intensity);

	shader->SetUniform("u_inverse_projection_matrix", glm::inverse((camera.GetProjectionMatrix())));
}

Camera SpotLight::GetLightCamera(const Camera& mainCamera, int shadowMapSize) const
{
	return Camera(this->GetTransform().GetPosition(),
	              this->GetTransform().GetOrientation(),
	              1.0f, 1.0f, 100.0f, outerConeAngle, Camera::PERSPECTIVE);
}
