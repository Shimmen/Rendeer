#pragma once

class Shader;
class Texture;

class Material
{
public:
	Material();
	~Material();

	void UpdateUniforms(const Shader& shader);


	// No real need to restrict access to these:
	Texture *diffuseTexture;
	//Texture *normalMap;
	//Texture *specularMap;

	//float specularPower:
};

