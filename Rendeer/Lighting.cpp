#include "Lighting.h"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

#include "Shader.h"
#include "DeferredRenderer.h"
#include "PerspectiveCamera.h"

void DirectionalLight::SetUniforms(const DeferredRenderer& renderer, const PerspectiveCamera& camera)
{
	shader->Bind();
	
	shader->SetUniform("u_light_direction",  glm::eulerAngles(this->transform.GetRotation()));
	shader->SetUniform("u_light_color", this->color);
	shader->SetUniform("u_light_intensity", this->intensity);
}

void PointLight::SetUniforms(const DeferredRenderer& renderer, const PerspectiveCamera& camera)
{
	shader->Bind();

	// Transform the light from world space to view space
	glm::vec4 lightViewSpacePos = camera.GetViewMatrix() * glm::vec4(this->transform.GetPosition(), 1.0f);

	shader->SetUniform("u_light_view_space_position", glm::vec3(lightViewSpacePos));
	shader->SetUniform("u_light_color", this->color);
	shader->SetUniform("u_light_intensity", this->intensity);
}
