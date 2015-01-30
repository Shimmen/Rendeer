#pragma once

class Shader;
class Texture;

struct Material
{
	// Not needed since Material doesn't own its pointer members
	// ~Material();

	// No real need to restrict access to these:
	Texture *diffuseTexture;
	//Texture *normalMap;
	//Texture *specularMap;

	//float specularPower:
};

