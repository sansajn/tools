#include "json_config.hpp"
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <boost/property_tree/json_parser.hpp>

using std::string;
using std::ifstream;
using std::stringstream;
using std::ostringstream;
namespace pt = boost::property_tree;

static string read_file(string const & fname);

json_config::json_config(string const & fname)
{
	read(fname);
}

void json_config::read(string const & fname)
{
	stringstream ss{read_file(fname)};
	pt::read_json(ss, _data);
}

string read_file(string const & fname)
{
	ifstream in{fname};
	if (!in.is_open())
		throw std::runtime_error{string{"unable to open '"} + fname + "' file"};

	ostringstream ss;
	ss << in.rdbuf();

	return ss.str();
}
