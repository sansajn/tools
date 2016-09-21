#include <string>
#include <iostream>
#include "config/keyval_config.hpp"

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
		keyval_config conf{fname};
		python_home = conf.get("python_home");
		format = conf.get("format");
		bitrate = conf.get("bitrate");
		freq = conf.get<int>("freq");
	}
};

int main(int argc, char * argv[])
{
	keyval_config conf{"sample.conf"};

	cout
		<< conf.get("python_home") << "\n"
		<< conf.get("format") << "\n"
		<< conf.get("bitrate") << "\n"
		<< conf.get("freq") << "\n";

	string python_home = conf.get<string>("python_home");
	string format = conf.get<string>("format");
	string bitrate = conf.get<string>("bitrate");
	int freq = conf.get<int>("freq");

	cout
		<< python_home << "\n"
		<< format << "\n"
		<< bitrate << "\n"
		<< freq << "\n";

	app_conf conf2;
	conf2.read("sample.conf");
	cout
		<< conf2.python_home << "\n"
		<< conf2.format << "\n"
		<< conf2.bitrate << "\n"
		<< conf2.freq << "\n";

	return 0;
}
