#include "DiffuseMaterial.h"

#include "Texture2D.h"
#include "Transform.h"
#include "DeferredRenderer.h"
#include "Camera.h"

DiffuseMaterial::DiffuseMaterial()
	: IMaterial{ new Shader{"Materials/Diffuse.vsh", "Materials/Diffuse.fsh"} }
{
}

void DiffuseMaterial::UpdateUniforms(const DeferredRenderer& renderer,
                                     const Transform& transform,
                                     const Camera& camera)
{
	shader->Bind();

	diffuseTexture->Bind(0);
	shader->SetUniform("u_diffuse", 0);

	normalMap != nullptr ? normalMap->Bind(1) : renderer.defaultNormalMap.Bind(1);
	shader->SetUniform("u_normal_map", 1);

	shader->SetUniform("u_specular_intensity", specularIntensity);
	shader->SetUniform("u_shininess", shininess);

	glm::mat4 modelViewMatrix = camera.GetViewMatrix() * transform.GetModelMatrix();
	glm::mat3 normalMatrix = glm::mat3(glm::transpose(glm::inverse(modelViewMatrix)));
	shader->SetUniform("u_model_view_matrix", modelViewMatrix);
	shader->SetUniform("u_normal_matrix", normalMatrix);
	shader->SetUniform("u_projection_matrix", camera.GetProjectionMatrix());
}
