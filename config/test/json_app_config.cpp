#define BOOST_TEST_MODULE json_config
#include <string>
#include <iostream>
#include <boost/test/included/unit_test.hpp>
#include "config/json_config.hpp"

using std::cout;
using std::string;

struct app_conf
{
	string python_home;
	string format;
	int freq;
	bool verbose;

	app_conf()
	{
		python_home = "python27";
		format = "opus";
		freq = 48000;
		verbose = false;
	}

	void read(string const & fname)
	{
		json_config conf{fname};
		python_home = conf.get("python_home");
		format = conf.get("format");
		freq = conf.get<int>("freq");
		verbose = conf.get<bool>("verbose");
	}

	void save(string const & fname)
	{
		json_config conf;
		conf.put("python_home", python_home);
		conf.put("format", format);
		conf.put("freq", freq);
		conf.put("verbose", verbose);
		conf.save(fname);
	}
};

BOOST_AUTO_TEST_CASE(save_read)
{
	char const * json_path = "generated_json_conf.json";

	app_conf expected;
	expected.format = "vorbis";
	expected.verbose = true;
	expected.save(json_path);

	app_conf conf;
	conf.read(json_path);

	BOOST_CHECK_EQUAL(expected.python_home, conf.python_home);
	BOOST_CHECK_EQUAL(expected.format, conf.format);
	BOOST_CHECK_EQUAL(expected.freq, conf.freq);
	BOOST_CHECK_EQUAL(expected.verbose, conf.verbose);
}
