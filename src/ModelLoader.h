#pragma once

#include <string>

class Entity;

class ModelLoader
{
public:

	//
	// NOTE:
	//
	// The idea here is to load a tree of entities with meshes and accompanying materials from a 3D model file. This will in the future
	// be called by the Scene loader. E.g., the scene descriptor refers to a teapot.obj, calls this which loads the teapot entity and also
	// the lid and other separate meshes into a little tree. If mesh count > 1, load an empty root entity and the meshes as children entities.
	//
	static Entity Load(const std::string& filename);

private:

	ModelLoader() = delete;
	ModelLoader(const ModelLoader&) = delete;
	~ModelLoader() = delete;

};

