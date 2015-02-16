#include "Model.h"

#include <iostream>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

Model::Model(const std::string& fileName)
{
	unsigned int importerFlags = 0;
	importerFlags |= aiProcess_Triangulate;
	importerFlags |= aiProcess_CalcTangentSpace;
	importerFlags |= aiProcess_FlipUVs;
	importerFlags |= aiProcess_GenSmoothNormals;

	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile(fileName, importerFlags);

	if (scene == nullptr)
	{
		std::cerr << "Error: could not load Model with file name: " << fileName << std::endl;
	}

	// Get the first mesh (we sort of assume there is only one)
	const aiMesh* model = scene->mMeshes[0];

	const aiVector3D zeroVector(0, 0, 0);
	for (unsigned int i = 0; i < model->mNumVertices; i++)
	{
		// We can assume all of these exist (since assimp was asked to create them if they didn't)
		const aiVector3D position = model->mVertices[i];
		const aiVector3D normal = model->mNormals[i];
		const aiVector3D tangent = model->mTangents[i];

		// (there can be more than one tex-coord per vertex, but we want the first one (0))
		const aiVector3D texCoord = model->HasTextureCoords(0) ? model->mTextureCoords[0][i]
			: zeroVector;

		positions.push_back(glm::vec3(position.x, position.y, position.z));
		normals.push_back(glm::vec3(normal.x, normal.y, normal.z));
		tangents.push_back(glm::vec3(tangent.x, tangent.y, tangent.z));
		texCoords.push_back(glm::vec2(texCoord.x, texCoord.y)); // no cubemaps in the Model class! (so no z-axis)
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