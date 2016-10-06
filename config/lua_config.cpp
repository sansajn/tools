#include "lua_config.hpp"
#include "error_output.hpp"

using std::string;

lua_config::lua_config(std::string const & fname)
	: _lse{lua::stderr_output}
{
	read(fname);
}

void lua_config::read(std::string const & fname)
{
	_lse.load_script(fname.c_str());
}

std::string lua_config::get(std::string const & key)
{
	return _lse.global_variable<string>(key.c_str());
}
