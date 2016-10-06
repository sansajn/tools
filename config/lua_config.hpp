#pragma once
#include <string>
#include "script_engine.hpp"

class lua_config
{
public:
//	lua_config() {}
	lua_config(std::string const & fname);

	void read(std::string const & fname);

	std::string get(std::string const & key);

	template <typename R>
	R get(std::string const & key)
	{
		return _lse.global_variable<R>(key.c_str());
	}

private:
	lua::script_engine _lse;
};
