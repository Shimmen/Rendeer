#pragma once

#include <glad/glad.h>

/*

A simple mesh that is a suitable mesh for rendering to textures etc.
Should always be used with the vertex shader screen_aligned_quad.vsh

*/

class ScreenAlignedQuad
{
public:

	ScreenAlignedQuad();
	~ScreenAlignedQuad();
	
	void Render();

private:

	GLuint vertexArray;
	GLuint vertexBuffer;

};

class SkyboxCube
{
public:

	SkyboxCube();
	~SkyboxCube();

	void Render();

private:

	GLuint vertexArray;
	GLuint vertexBuffer;

};
