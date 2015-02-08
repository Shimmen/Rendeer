#pragma once

#include <GL/glew.h>

/*
A simple mesh that is a suitable mesh for rendering to textures etc.

Should always be used with the vertex shader screen_aligned_quad.vsh

Should maybe be merged with the Mesh class, but to be more performant we use a triangle strip
which currently isn't supported by the Mesh class. It should at least have a common interface with Mesh
so (at least) the Render() call is the same!
*/

// TODO: Clean up plenty!
// TODO: Make singleton? Probably so.

class ScreenAlignedQuad
{
public:
	ScreenAlignedQuad();
	~ScreenAlignedQuad();
	
	void Render();

private:
	GLuint vertexBuffer;
};
