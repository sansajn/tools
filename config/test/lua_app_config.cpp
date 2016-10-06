#include <string>
#include <iostream>
#include "config/lua_config.hpp"

using std::string;
using std::cout;

struct app_conf
{
	string python_home;
	string format;
	string bitrate;
	int freq;
	bool verbose;

	void read(string const & fname)
	{
		lua_config conf{fname};
		python_home = conf.get("python_home");
		format = conf.get("format");
		bitrate = conf.get("bitrate");
		freq = conf.get<int>("freq");
		verbose = conf.get<bool>("verbose");
	}
};

int main(int argc, char * argv[])
{
	app_conf conf;
	conf.read("config.lua");

	cout
		<< conf.python_home << "\n"
		<< conf.format << "\n"
		<< conf.bitrate << "\n"
		<< conf.freq << "\n"
		<< conf.verbose << "\n";

	return 0;
}
