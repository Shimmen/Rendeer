#pragma once

#include <glad/glad.h>

#include "VertexArray.h"

class ScreenAlignedQuad
{
public:
	
	static void Render();

private:

	ScreenAlignedQuad();
	~ScreenAlignedQuad() {}

	VertexArray vertexArray;

};

class SkyboxCube
{
public:

	static void Render();

private:

	SkyboxCube();
	~SkyboxCube() {}

	VertexArray vertexArray;

};