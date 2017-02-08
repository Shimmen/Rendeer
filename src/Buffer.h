#pragma once

#include <stdint.h>
#include <vector>
#include <memory>
#include <map>

#include <glad/glad.h>

#include "GLResource.h"

class Buffer: public GLResource
{
public:

	Buffer();
	~Buffer();

public:

	const Buffer& Bind(GLenum target) const;
	const Buffer& BindAsUniformBuffer(GLuint binding) const;
	
	template <typename T>
	void SetData(const std::vector<T>& data, GLenum dataUsage) const
	{
		this->SetData(&data[0], data.size() * sizeof(T), dataUsage);
	}

	template <typename T>
	void UpdateData(const std::vector<T>& data, size_t offset = 0) const
	{
		this->UpdateData(&data[0], data.size() * sizeof(T), offset);
	}

	void SetData(const void *data, size_t dataSize, GLenum dataUsage) const;
	void UpdateData(const void *data, size_t dataSize, size_t offset = 0) const;

	std::vector<uint8_t> GetData(size_t size, size_t offset = 0) const;

private:

	// The target that this buffer handle was last bound to. It is defined as mutable since it isn't a property
	// of the buffer but more a management variable like currentlyBound. That one is a class variable so it doesn't
	// need to be declared as mutable, but this makes sense to store as a member.
	mutable GLenum lastBoundTargetForInstance{ 0 };

	// Maps a buffer bind target to a buffer handle. If currentlyBound[lastBoundTarget] != bufferHandle
	// we know that this buffer isn't bound (where we think it is) and should warn about that.
	static std::map<GLenum, GLuint> currentlyBound;

};
