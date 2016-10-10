#pragma once
#include <boost/property_tree/ptree.hpp>

class json_config
{
public:
	json_config() {}
	json_config(std::string const & fname);

	void read(std::string const & fname);
	void save(std::string const & fname);

	std::string get(std::string const & key);

	template <typename R>
	R get(std::string const & key)
	{
		return _data.get<R>(key);
	}

	template <typename R>
	R get(std::string const & key, R const & defval)
	{
		return _data.get<R>(key, defval);
	}

	template <typename T>
	void put(std::string const & key, T const & val)
	{
		_data.put<T>(key, val);
	}

private:
	boost::property_tree::ptree _data;
};
