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

	shader->SetUniform("u_light_direction", this->transform.GetForward());
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

void SpotLight::SetUniforms(const DeferredRenderer& renderer, PerspectiveCamera& camera)
{
	shader->Bind();

	shader->SetUniform("u_albedo", 10);
	shader->SetUniform("u_normals", 11);
	//shader->SetUniform("u_depth", 12); // TODO
	shader->SetUniform("u_position", 13); // TODO

	shader->SetUniform("u_light_position", this->transform.GetPosition());
    shader->SetUniform("u_light_direction", this->transform.GetForward());
	shader->SetUniform("u_light_cone_angle", this->coneAngle);
	shader->SetUniform("u_light_color", this->color);
	shader->SetUniform("u_light_intensity", this->intensity);

	//shader->SetUniform("u_projection_matrix", camera.GetProjectionMatrix()); // TODO
	//shader->SetUniform("u_inverse_projection_matrix", glm::inverse((camera.GetProjectionMatrix()))); // TODO
}
