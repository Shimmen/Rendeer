#pragma once

#include <string>

#include <assimp/scene.h>

class Mesh;
class Entity;
class Material;

class ModelLoader
{
public:

	//
	// NOTE:
	//
	// The idea here is to load a tree of entities with meshes and accompanying materials from a 3D model file. This will in the future
	// be called by the Scene loader. E.g., the scene descriptor refers to a teapot.obj, calls this which loads the teapot entity and also
	// the lid and other separate meshes into a little tree. If mesh count > 1, load an empty root entity and the meshes as children entities.
	//
	static std::shared_ptr<Entity> Load(const std::string& filename);

private:

	static void AssembleEntity(std::shared_ptr<Entity> entity, const aiScene *scene, const aiNode *node, const std::string& filename);

	static std::shared_ptr<Mesh> ConvertAssimpMesh(const aiMesh *mesh);
	static std::shared_ptr<Material> ConvertAssimpMaterial(const aiMaterial *material, const std::string& relativePath);

	ModelLoader() = delete;
	ModelLoader(ModelLoader&) = delete;
	ModelLoader(ModelLoader&&) = delete;

};

