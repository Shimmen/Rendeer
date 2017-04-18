#pragma once

#include <glad/glad.h>

class GLResource
{
public:

	GLResource() {}
	GLResource(GLuint handle) : handle(handle) {}
	
	virtual ~GLResource() {}

protected:

	GLuint handle{0};

private:

	// Disallow all copying of GLResources
	GLResource(GLResource& other) = delete;
	GLResource& operator=(GLResource& other) = delete;

};
