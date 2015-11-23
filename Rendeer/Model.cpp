#include "Model.h"

#include <iostream>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Logger.h"

Model::Model(const std::string& fileName, bool genSmoothNormals)
{
	unsigned int importerFlags = 0;
	importerFlags |= aiProcess_Triangulate;
	importerFlags |= aiProcess_CalcTangentSpace;
	//importerFlags |= aiProcess_FlipUVs; // sholdn't be neccesary now when stbi can load images flipped.

	if (genSmoothNormals)
	{
		importerFlags |= aiProcess_GenSmoothNormals;
	}
	else
	{
		importerFlags |= aiProcess_GenNormals;
	}

	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(fileName, importerFlags);
	if (scene == nullptr)
	{
		const Logger& logger = Logger::GetDefaultLogger();
		logger.Log("Error: could not load Model with file name: " + fileName);
		logger.Log("       Reason: " + std::string(importer.GetErrorString()));
	}

	// Get the first mesh (we sort of assume there is only one)
	const aiMesh* model = scene->mMeshes[0];

	const aiVector3D zeroVector(0, 0, 0);
	for (unsigned int i = 0; i < model->mNumVertices; i++)
	{
		// We can assume all of these exist (since assimp was asked to create them if they didn't)
		const aiVector3D position = model->mVertices[i];
		const aiVector3D normal = model->mNormals[i];
		
		// Can only be available if model has texture coordinates!
		const aiVector3D tangent = model->HasTangentsAndBitangents() ? model->mTangents[i] : zeroVector;

		// (there can be more than one tex-coord per vertex, but we want the first one (0))
		const aiVector3D texCoord = model->HasTextureCoords(0) ? model->mTextureCoords[0][i] : zeroVector;

		positions.push_back(glm::vec3(position.x, position.y, position.z));
		normals.push_back(glm::vec3(normal.x, normal.y, normal.z));
		tangents.push_back(glm::vec3(tangent.x, tangent.y, tangent.z));
		texCoords.push_back(glm::vec2(texCoord.x, texCoord.y));
	}

	for (unsigned int i = 0; i < model->mNumFaces; i++)
	{
		const aiFace face = model->mFaces[i];

		// Assimp should have triangulated all faces
		assert(face.mNumIndices == 3);

		indices.push_back(face.mIndices[0]);
		indices.push_back(face.mIndices[1]);
		indices.push_back(face.mIndices[2]);
	}
}
