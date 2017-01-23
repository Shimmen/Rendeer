#pragma once

#include <glad/glad.h>

#include "VertexArray.h"

class ScreenAlignedQuad
{
public:
	
	static void Render();

private:

	ScreenAlignedQuad();
	~ScreenAlignedQuad();

	ScreenAlignedQuad(ScreenAlignedQuad& other) = delete;
	ScreenAlignedQuad& operator=(ScreenAlignedQuad& other) = delete;

private:

	VertexArray vertexArray;

};

class SkyboxCube
{
public:

	static void Render();

private:

	SkyboxCube();
	~SkyboxCube();

	SkyboxCube(SkyboxCube& other) = delete;
	SkyboxCube& operator=(SkyboxCube& other) = delete;

private:

	VertexArray vertexArray;

};
