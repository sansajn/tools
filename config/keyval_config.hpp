#pragma once
#include <map>
#include <string>
#include <sstream>

class keyval_config  //!< key=value configuration reader implementation
{
public:
	keyval_config() {}
	keyval_config(std::string const & fname);

	void read(std::string const & fname);
	std::string const & get(std::string const & key);

	template <typename R>
	R get(std::string const & key)
	{
		std::string const & val = get(key);
		R result;
		std::istringstream iss{val};
		iss >> result;
		return result;
	}

private:
	std::map<std::string, std::string> _data;
};
