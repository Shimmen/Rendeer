#pragma once

#include <fstream>

namespace nonstd
{
	template <typename Enumeration>
	inline
	typename std::underlying_type<Enumeration>::type as_integer(const Enumeration value)
	{
		return static_cast<typename std::underlying_type<Enumeration>::type>(value);
	}

	inline
	bool file_is_readable(const std::string& filePath)
	{
		return std::ifstream(filePath.c_str()).good();
	}
}
