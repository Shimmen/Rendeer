#include "ModelLoader.h"

#include <memory>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Entity.h"
#include "Renderable.h"
#include "GeneralUtil.h"
#include "DiffuseMaterial.h"

#define RENDEER_ASSIMP_IMPORT_FLAGS_FAST    aiProcessPreset_TargetRealtime_Fast | aiProcess_TransformUVCoords
#define RENDEER_ASSIMP_IMPORT_FLAGS_QUALITY aiProcessPreset_TargetRealtime_Quality | aiProcess_TransformUVCoords

/*static*/ std::shared_ptr<Entity> ModelLoader::Load(const std::string & filename)
{
	static Assimp::Importer importer{};
	auto entity = std::make_shared<Entity>();

	const aiScene* scene = importer.ReadFile(filename, RENDEER_ASSIMP_IMPORT_FLAGS_QUALITY);
	if (!scene)
	{
		const Logger& logger = Logger::GetDefaultLogger();
		logger.Log("Error: could not load model with filename: " + filename);
		logger.Log("       Reason: " + std::string(importer.GetErrorString()));
		return entity;
	}

	// Only meshes (and their materials) are loaded, so if there are no meshes this function doesn't need to do anything
	if (!scene->HasMeshes())
	{
		return entity;
	}

	AssembleEntity(entity, scene, scene->mRootNode, filename);
	return entity;
}

/*static*/ void ModelLoader::AssembleEntity(std::shared_ptr<Entity> entity, const aiScene *scene, const aiNode *node, const std::string& filename)
{
	// Set transform
	{
		aiVector3D pos, scl;
		aiQuaternion rot;
		node->mTransformation.Decompose(scl, rot, pos);
		entity->GetTransform()
			.SetPosition(pos.x, pos.y, pos.z)
			.SetScale(scl.x, scl.y, scl.z)
			.SetOrientation(glm::quat{rot.w, rot.x, rot.y, rot.z});
	}

	// Set meshes & materials
	unsigned int numMeshes = node->mNumMeshes;
	for (int i = 0; i < numMeshes; ++i)
	{
		int meshIndex = node->mMeshes[i];

		auto mesh = scene->mMeshes[meshIndex];
		auto myMesh = ConvertAssimpMesh(mesh);

		auto material = scene->mMaterials[mesh->mMaterialIndex];
		auto myMaterial = ConvertAssimpMaterial(material, nonstd::directory_name(filename));

		auto renderable = std::make_shared<Renderable>(myMesh, myMaterial);

		if (numMeshes == 1)
		{
			entity->AddComponent(renderable);
		}
		else
		{
			// TODO: Currently we don't support multiple components of the same type in one entity (for when we need to look one up),
			// so we will have to put the renderables in separate child entities for now at least.
			entity->NewChild()->AddComponent(renderable);
		}
	}

	// Assemble child entities
	for (int i = 0; i < node->mNumChildren; ++i)
	{
		std::shared_ptr<Entity> child = entity->NewChild();
		AssembleEntity(child, scene, node->mChildren[i], filename);
	}
}

/*static*/ std::shared_ptr<Mesh> ModelLoader::ConvertAssimpMesh(const aiMesh *mesh)
{
	// TODO: Assert less, allow more plausible configurations
	assert(mesh->HasPositions() && mesh->HasNormals() && mesh->HasTangentsAndBitangents() && mesh->HasFaces() && mesh->HasTextureCoords(0));
	assert(mesh->GetNumUVChannels() == 1); // Let's hope most/all meshes only have one texture coordinate channel!
	assert((mesh->mPrimitiveTypes & ~aiPrimitiveType_TRIANGLE) == 0); // Only triangles!

	std::vector<unsigned int> indices{};
	indices.reserve(mesh->mNumFaces * 3);
	for (int i = 0; i < mesh->mNumFaces; ++i)
	{
		auto& face = mesh->mFaces[i];
		assert(face.mNumIndices == 3); // (Should already be asserted by checking mPrimitiveTypes!)
		indices.emplace_back(face.mIndices[0]);
		indices.emplace_back(face.mIndices[1]);
		indices.emplace_back(face.mIndices[2]);
	}

	unsigned int numVertices = mesh->mNumVertices;

	// Convert 3D texture coordinates to 2D texture coordinates (will take less space in vram but take longer to load)
	std::vector<aiVector2D> texCoords{};
	texCoords.reserve(numVertices);
	for (int i = 0; i < numVertices; ++i)
	{
		auto& vec3 = mesh->mTextureCoords[0][i];
		texCoords.emplace_back(vec3.x, vec3.y);
	}

	auto myMesh = std::make_shared<Mesh>(
		&mesh->mVertices[0].x,
		&mesh->mNormals[0].x,
		&mesh->mTangents[0].x,
		&texCoords[0].x,
		numVertices,
		&indices[0],
		indices.size()
	);

	return myMesh;
}

/*static*/ std::shared_ptr<Material> ModelLoader::ConvertAssimpMaterial(const aiMaterial *material, const std::string& relativePath)
{
#define PATH(name) (relativePath + "/" + std::string(name.C_Str()))

	auto myMaterial = std::make_shared<DiffuseMaterial>();

	// Check for each property that the DiffuseMaterial supports and set them if availables, else do some default.
	// At later stages when many materials are available we can use the info to figure out what material to use.

	aiString tempPath{};

	if (material->GetTexture(aiTextureType_DIFFUSE, 0, &tempPath) == AI_SUCCESS)
	{
		myMaterial->diffuseTexture = std::make_shared<Texture2D>(PATH(tempPath), true);
	}

	if (material->GetTexture(aiTextureType_NORMALS, 0, &tempPath) == AI_SUCCESS)
	{
		myMaterial->normalMap = std::make_shared<Texture2D>(PATH(tempPath), false);
	}

	// TODO: Read these values from the material!
	myMaterial->specularIntensity = 1.0f;
	myMaterial->shininess = 20.0f;

	return myMaterial;

#undef PATH//(name)
}
