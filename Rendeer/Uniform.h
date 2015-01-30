#pragma once

#include <string>

#include <GL/glew.h>

class Uniform
{
public:
	Uniform(std::string name, GLuint handle)
		: name(name)
		, handle(handle)
	{
	}

	inline std::string GetName() { return name; }
	inline GLuint GetHandle() { return handle; }

private:
	const std::string name;
	const GLuint handle;
};