#pragma once
#include <boost/property_tree/ptree.hpp>

class json_config
{
public:
	json_config() {}
	json_config(std::string const & fname);

	void read(std::string const & fname);

	std::string get(std::string const & key)
	{
		return _data.get<std::string>(key);
	}

	template <typename R>
	R get(std::string const & key)
	{
		return _data.get<R>(key);
	}

private:
	boost::property_tree::ptree _data;
};
