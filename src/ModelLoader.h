#pragma once

#include <string>
#include <memory>

#include <assimp/scene.h>

class Mesh;
class Entity;
class Material;

class ModelLoader
{
public:

	static std::shared_ptr<Entity> Load(const std::string& filename);

private:

	static void AssembleEntity(std::shared_ptr<Entity> entity, const aiScene *scene, const aiNode *node, const std::string& filename);

	static std::shared_ptr<Mesh> ConvertAssimpMesh(const aiMesh *mesh);
	static std::shared_ptr<Material> ConvertAssimpMaterial(const aiMaterial *material, const std::string& relativePath);

	ModelLoader() = delete;
	ModelLoader(ModelLoader&) = delete;
	ModelLoader(ModelLoader&&) = delete;

};

