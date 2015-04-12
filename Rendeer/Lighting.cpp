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

	glm::vec3 lightDirectionEuler = glm::eulerAngles(this->transform.GetOrientation());

	shader->SetUniform("u_light_direction", lightDirectionEuler);
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

	shader->SetUniform("u_light_position", this->transform.GetPosition());
	shader->SetUniform("u_light_color", this->color);
	shader->SetUniform("u_light_intensity", this->intensity);

	//shader->SetUniform("u_projection_matrix", camera.GetProjectionMatrix()); // TODO
	//shader->SetUniform("u_inverse_projection_matrix", glm::inverse((camera.GetProjectionMatrix()))); // TODO
}
