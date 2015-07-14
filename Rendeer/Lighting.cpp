#include "Lighting.h"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

#include "Shader.h"
#include "DeferredRenderer.h"
#include "PerspectiveCamera.h"

void DirectionalLight::SetUniforms(const DeferredRenderer& renderer, PerspectiveCamera& camera)
{
	shader->Bind();

	shader->SetUniform("u_albedo", 10);
	shader->SetUniform("u_normals", 11);
	//shader->SetUniform("u_depth", 12); // TODO
	shader->SetUniform("u_position", 13); // TODO

	auto lightForward = this->transform.GetForward();
	auto viewSpaceLightForward = camera.GetTransform().GetInverse().RotateVector(lightForward);

	shader->SetUniform("u_light_direction", viewSpaceLightForward);
	shader->SetUniform("u_light_color", this->color);
	shader->SetUniform("u_light_intensity", this->intensity);
}

void PointLight::SetUniforms(const DeferredRenderer& renderer, PerspectiveCamera& camera)
{
	shader->Bind();

	shader->SetUniform("u_albedo", 10);
	shader->SetUniform("u_normals", 11);
	//shader->SetUniform("u_depth", 12); // TODO
	shader->SetUniform("u_position", 13); // TODO

	auto viewSpaceLightPosition = glm::vec3(camera.GetViewMatrix() * glm::vec4(this->transform.GetPosition(), 1.0f));

	shader->SetUniform("u_light_position", viewSpaceLightPosition);
	shader->SetUniform("u_light_color", this->color);
	shader->SetUniform("u_light_intensity", this->intensity);

	//shader->SetUniform("u_projection_matrix", camera.GetProjectionMatrix()); // TODO
	//shader->SetUniform("u_inverse_projection_matrix", glm::inverse((camera.GetProjectionMatrix()))); // TODO
}

void SpotLight::SetUniforms(const DeferredRenderer& renderer, PerspectiveCamera& camera)
{
	shader->Bind();

	shader->SetUniform("u_albedo", 10);
	shader->SetUniform("u_normals", 11);
	//shader->SetUniform("u_depth", 12); // TODO
	shader->SetUniform("u_position", 13); // TODO

	auto viewSpaceLightPosition = glm::vec3(camera.GetViewMatrix() * glm::vec4(this->transform.GetPosition(), 1.0f));

	auto lightForward = this->transform.GetForward();
	auto viewSpaceLightForward = camera.GetTransform().GetInverse().RotateVector(lightForward);

	shader->SetUniform("u_light_position", viewSpaceLightPosition);
	shader->SetUniform("u_light_direction", viewSpaceLightForward);
	shader->SetUniform("u_light_outer_cone_angle", this->outerConeAngle);
	shader->SetUniform("u_light_inner_cone_angle", this->innerConeAngle);
	shader->SetUniform("u_light_color", this->color);
	shader->SetUniform("u_light_intensity", this->intensity);

	//shader->SetUniform("u_projection_matrix", camera.GetProjectionMatrix()); // TODO
	//shader->SetUniform("u_inverse_projection_matrix", glm::inverse((camera.GetProjectionMatrix()))); // TODO
}
