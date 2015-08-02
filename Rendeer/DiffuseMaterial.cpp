#include "DiffuseMaterial.h"

#include "Texture.h"
#include "Transform.h"
#include "DeferredRenderer.h"
#include "PerspectiveCamera.h"

DiffuseMaterial::DiffuseMaterial()
	: IMaterial(new Shader("Materials/Diffuse.vsh", "Materials/Diffuse.fsh"))
{
}

void DiffuseMaterial::UpdateUniforms(const DeferredRenderer& renderer,
                                     const Transform& transform,
                                     const PerspectiveCamera& camera)
{
	shader->Bind();

	diffuseTexture->Bind(0);
	shader->SetUniform("u_diffuse", 0);

	normalMap != nullptr ? normalMap->Bind(1) : renderer.defaultNormalMap.Bind(1);
	shader->SetUniform("u_normal_map", 1);

	shader->SetUniform("u_specular_intensity", specularIntensity);
	shader->SetUniform("u_shininess", shininess);

	shader->SetUniform("u_model_view_matrix", camera.GetViewMatrix() * transform.GetModelMatrix());
	shader->SetUniform("u_projection_matrix", camera.GetProjectionMatrix());
}
