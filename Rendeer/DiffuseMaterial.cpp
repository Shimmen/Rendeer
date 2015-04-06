#include "DiffuseMaterial.h"

#include "Texture.h"
#include "Transform.h"
#include "PerspectiveCamera.h"

void DiffuseMaterial::UpdateUniforms(const DeferredRenderer& renderer,
	const Transform& transform, const PerspectiveCamera& camera)
{
	shader->Bind();

	diffuseTexture->Bind(0);
	shader->SetUniform("u_diffuse", 0);

	glm::mat4 modelMatrix = transform.GetModelMatrix();
	glm::mat4 viewProjectionMatrix = camera.GetProjectionMatrix() * camera.GetViewMatrix();
	
	shader->SetUniform("u_model_matrix", modelMatrix);
	shader->SetUniform("u_view_projection_matrix", viewProjectionMatrix);
}