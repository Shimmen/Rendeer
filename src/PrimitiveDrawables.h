#pragma once

#include <glad/glad.h>

#include "VertexArray.h"

class ScreenAlignedQuad
{
public:

	ScreenAlignedQuad();
	~ScreenAlignedQuad();
	
	void Render() const;

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

	void Render() const;

private:

	SkyboxCube(SkyboxCube& other) = delete;
	SkyboxCube& operator=(SkyboxCube& other) = delete;

private:

	VertexArray vertexArray;

};
