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

	glm::mat4 modelViewMatrix = camera.GetViewMatrix() * transform.GetModelMatrix();
	glm::mat4 projectionMatrix = camera.GetProjectionMatrix();
	
	shader->SetUniform("u_model_view_matrix", modelViewMatrix);
	shader->SetUniform("u_projection_matrix", projectionMatrix);
}