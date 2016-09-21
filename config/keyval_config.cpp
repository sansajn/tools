#include "keyval_config.hpp"
#include <vector>
#include <fstream>
#include <stdexcept>
#include <utility>

using std::vector;
using std::string;
using std::ifstream;
using std::pair;
using std::make_pair;
using std::runtime_error;
using std::logic_error;

static vector<string> read_lines(string const & fname);
static pair<string, string> parse_keyval(string const & line);

keyval_config::keyval_config(std::string const & fname)
{
	read(fname);
}

void keyval_config::read(std::string const & fname)
{
	vector<string> lines = read_lines(fname);
	for (string const & line : lines)
	{
		if (line.empty())
			continue;

		// line comment
		if (line.size() > 1 && line[0] == '/' && line[1] == '/')
			continue;

		pair<string, string> keyval = parse_keyval(line);

		_data[keyval.first] = keyval.second;
	}
}

std::string const & keyval_config::get(std::string const & key)
{
	auto it = _data.find(key);
	if (it != _data.end())
		return it->second;
	else
		throw logic_error{"key not found"};
}

vector<string> read_lines(string const & fname)
{
	ifstream fin{fname};
	if (!fin.is_open())
		throw runtime_error{"unable to open '" + fname + "' for reading"};

	vector<string> lines;

	while (fin)
	{
		string line;
		getline(fin, line);
		lines.emplace_back(line);
	}

	fin.close();

	return lines;
}

pair<string, string> parse_keyval(string const & line)
{
	string::size_type delimpos = line.find('=');
	if (delimpos == string::npos || delimpos == 0)
		throw logic_error{"not a key=value pair"};

	string key = line.substr(0, delimpos);

	string value;
	if (delimpos < line.size()-1)
		value = string{line.begin()+static_cast<string::difference_type>(delimpos)+1, line.end()};

	// TODO: strip key and value

	return make_pair(key, value);
}
