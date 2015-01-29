#include "Material.h"

#include <GL/glew.h>

#include "Texture.h"
#include "Shader.h"

Material::Material()
{

}

Material::~Material()
{
	// pointer member Textures are not owned
	// by the Material. So don't delete them here.
}

void Material::UpdateUniforms(const Shader& shader)
{
	/*

	// If the shader has a diffuse texture
	// we will need to bind SOMETHING to it
	if (shader.HasDiffuseTexture())
	{
		// Tell the shader that the diffuse texture
		// will be bound at texture unit 0
		glUniform1i(shader.GetDiffuseTexture().GetHandle(), 0);

		// If this material has a diffuse texture,
		// bind it at the apropriate texture unit,
		// which is 0 for diffuse textures.
		if (diffuseTexture != NULL)
		{
			diffuseTexture->Bind(0);
		}
		// If this material doesn't specify a diffuse
		// texture, bind the default diffuse texture
		else
		{
			// Get default diffuse texture.
			// Should probably be defined as globals
			// or more safe alternative in Texture.h
			Texture *defaultDiffuse = 0;
			defaultDiffuse->Bind(0);
		}
	}

	// Repeat the above method for all members
	// that should be set to uniforms in the shader.
	// Things like other textures (normalMap etc.),
	// and other uniform stuff

	*/
}