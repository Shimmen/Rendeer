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

	shader->SetUniform("u_model_matrix", transform.GetModelMatrix());
	shader->SetUniform("u_view_matrix", camera.GetViewMatrix());
	shader->SetUniform("u_projection_matrix", camera.GetProjectionMatrix());
}
