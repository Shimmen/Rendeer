#include "DirectionalLight.h"

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
