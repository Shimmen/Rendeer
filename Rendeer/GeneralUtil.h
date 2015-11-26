#pragma once

namespace nonstd
{
	template <typename Enumeration>
	auto as_integer(const Enumeration value) -> typename std::underlying_type<Enumeration>::type
	{
		return static_cast<typename std::underlying_type<Enumeration>::type>(value);
	}
}
