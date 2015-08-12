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

Camera DirectionalLight::GetLightCamera() const
{
	// TODO: Omptimize the near & far & size parameters
	return Camera(glm::vec3(), this->GetTransform().GetOrientation(),
	              1.0f, -10.0f, 10.0f, 10.0f, Camera::ORTHOGRAPHIC);
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

Camera PointLight::GetLightCamera() const
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

Camera SpotLight::GetLightCamera() const
{
	return Camera(this->GetTransform().GetPosition(),
	                         this->GetTransform().GetOrientation(),
	                         1.0f, 1.0f, 100.0f, outerConeAngle, Camera::PERSPECTIVE);
}
