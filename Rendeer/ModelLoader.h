#pragma once

#include <string>

class Entity;

class ModelLoader
{
public:

	static Entity Load(const std::string& filename);

private:

	ModelLoader() = delete;
	ModelLoader(const ModelLoader&) = delete;
	~ModelLoader() = delete;

};

