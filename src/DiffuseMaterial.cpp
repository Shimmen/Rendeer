#include "DiffuseMaterial.h"

#include "Transform.h"
#include "DeferredRenderer.h"

DiffuseMaterial::DiffuseMaterial()
: Material{ std::make_shared<Shader>("Materials/Diffuse.vsh", "Materials/Diffuse.fsh") }
{
}

void DiffuseMaterial::UpdateUniforms(const DeferredRenderer& renderer,
                                     const Transform& transform,
                                     const CameraComponent& camera) const
{
	shader->Bind();



	diffuseTexture != nullptr ? diffuseTexture->Bind(0) : renderer.defaultDiffuse.Bind(0);
	shader->SetUniform("u_diffuse", 0);

	normalMap != nullptr ? normalMap->Bind(1) : renderer.defaultNormalMap.Bind(1);
	shader->SetUniform("u_normal_map", 1);

	shader->SetUniform("u_specular_intensity", specularIntensity);
	shader->SetUniform("u_shininess", shininess);

	glm::mat4 modelViewMatrix = camera.GetViewMatrix() * transform.GetWorldMatrix();
	glm::mat3 normalMatrix = glm::mat3(glm::transpose(glm::inverse(modelViewMatrix)));
	shader->SetUniform("u_model_view_matrix", modelViewMatrix);
	shader->SetUniform("u_normal_matrix", normalMatrix);
	shader->SetUniform("u_projection_matrix", camera.GetProjectionMatrix());
}
