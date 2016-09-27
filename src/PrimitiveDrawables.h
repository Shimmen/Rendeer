#pragma once

#include <glad2/glad.h>

#include "VertexArray.h"

class ScreenAlignedQuad
{
public:

	ScreenAlignedQuad();
	~ScreenAlignedQuad();
	
	void Render();

private:

	ScreenAlignedQuad(ScreenAlignedQuad& other) = delete;
	ScreenAlignedQuad& operator=(ScreenAlignedQuad& other) = delete;

private:

	VertexArray vertexArray;

};

class SkyboxCube
{
public:

	SkyboxCube();
	~SkyboxCube();

	void Render();

private:

	SkyboxCube(SkyboxCube& other) = delete;
	SkyboxCube& operator=(SkyboxCube& other) = delete;

private:

	VertexArray vertexArray;

};
