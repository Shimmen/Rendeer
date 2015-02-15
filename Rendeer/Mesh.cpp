#include "Mesh.h"

#include <iostream>
#include <vector>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

Mesh::Mesh(Vertex *vertices, unsigned int vertexCount,
	int *indices, unsigned int indexCount) : indexCount(indexCount)
{
	vertexArray = CreateMesh(vertices, vertexCount, indices, indexCount);
}

Mesh::Mesh(const std::string& fileName, bool genSmoothNormals)
{
	unsigned int importerFlags = aiProcess_Triangulate | aiProcess_CalcTangentSpace | aiProcess_FlipUVs /* | aiProcess_ConvertToLeftHanded */;
	if (genSmoothNormals)
	{
		importerFlags |= aiProcess_GenSmoothNormals;
	}

	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile(fileName, importerFlags);

	if (scene == nullptr)
	{
		std::cerr << "Error: could not load Mesh with file name: " << fileName << std::endl;
	}

	// Get the first mesh (we sort of assume there is only one)
	const aiMesh* model = scene->mMeshes[0];
	
	std::vector<glm::vec3> positions;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec3> tangents;
	std::vector<glm::vec2> texCoords;
	std::vector<unsigned int> indices;
	
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
		texCoords.push_back(glm::vec2(texCoord.x, texCoord.y)); // no cubemaps in the Mesh class! (so no z-axis)
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
	 
	//vertexArray = CreateMesh();
}

// This is sort of the real constructor. Maybe fix so this is a REAL constructor?
GLuint Mesh::CreateMesh(Vertex *vertices, unsigned int vertexCount,
	int *indices, unsigned int indexCount)
{
	std::vector<glm::vec3> positions = std::vector<glm::vec3>();
	std::vector<glm::vec2> texCoords = std::vector<glm::vec2>();

	for (unsigned int i = 0; i < vertexCount; ++i)
	{
		Vertex vertex = vertices[i];
		positions.push_back(*vertex.GetPosition());
		texCoords.push_back(*vertex.GetTexCoord());
	}

	GLuint vertexArray;
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(MESH_BUFFER_COUNT, buffers);

	int stride = sizeof(glm::vec3) + sizeof(glm::vec2);

	///////////////////////
	///////////////////////

	glBindBuffer(GL_ARRAY_BUFFER, buffers[POSITION_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions[0]) * positions.size(), &positions[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); // stride and offset is 0 for now

	///////////////////////

	glBindBuffer(GL_ARRAY_BUFFER, buffers[TEXCOORD_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords[0]) * texCoords.size(), &texCoords[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0); // stride and offset is 0 for now
	

	///////////////////////

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[INDEX_BUFFER]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indexCount, indices, GL_STATIC_DRAW);

	///////////////////////
	///////////////////////

	glBindVertexArray(0);
	return vertexArray;
}

Mesh::~Mesh()
{
	glDeleteBuffers(MESH_BUFFER_COUNT, buffers);
	glDeleteVertexArrays(1, &vertexArray);
}

void Mesh::Render()
{
	glBindVertexArray(vertexArray);
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
}