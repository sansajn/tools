#include "json_config.hpp"
#include <sstream>
#include <boost/property_tree/json_parser.hpp>
#include "string_algo.hpp"

using std::string;
using std::stringstream;
namespace pt = boost::property_tree;

json_config::json_config(string const & fname)
{
	read(fname);
}

std::string json_config::get(std::string const & key)
{
	return _data.get<std::string>(key);
}

void json_config::read(string const & fname)
{
	stringstream ss{read_file(fname)};
	pt::read_json(ss, _data);
}

void json_config::save(std::string const & fname)
{
	pt::write_json(fname, _data);
}
