#include <string>
#include <iostream>
#include "config/json_config.hpp"

using std::cout;
using std::string;

struct app_conf
{
	string python_home;
	string format;
	string bitrate;
	int freq;

	void read(string const & fname)
	{
		json_config conf{fname};
		python_home = conf.get("python_home");
		format = conf.get("format");
		bitrate = conf.get("bitrate");
		freq = conf.get<int>("freq");
	}
};

int main(int argc, char * argv[])
{
	app_conf conf;
	conf.read("json.conf");

	cout
		<< conf.python_home << "\n"
		<< conf.format << "\n"
		<< conf.bitrate << "\n"
		<< conf.freq << "\n";

	return 0;
}
