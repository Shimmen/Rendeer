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

	shader->SetUniform("u_specular_intensity", specularIntensity);
	shader->SetUniform("u_shininess", shininess);

	shader->SetUniform("u_model_view_matrix", camera.GetViewMatrix() * transform.GetModelMatrix());
	shader->SetUniform("u_projection_matrix", camera.GetProjectionMatrix());
}
