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

	inline
	std::string trim_whitespace(const std::string& string)
	{
		if (string.length() <= 0)
		{
			return "";
		}

		size_t first = string.find_first_not_of(' ');
		size_t last = string.find_last_not_of(' ');
		return string.substr(first, (last - first + 1));
	}
}
