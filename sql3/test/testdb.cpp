// std
#include <string>
#include <vector>
#include <iostream>
#include "sql3/session.hpp"

char const * DB_NAME = "test.db";

using std::string;

void error_with_exit(const std::string & msg, int code);

void create_test_db()
{
	dbw::session sql{DB_NAME};
	if (!sql.good())
		error_with_exit("Can't establish a database connection!", 1);

	sql << "CREATE TABLE test(one INTEGER, two NUMERIC, tree TEXT)";
	sql << "INSERT INTO test(one, two, tree) VALUES(1, 2.02, 'hello@')";
	sql << "INSERT INTO test(one, two, tree) VALUES(2, 3.03, 'gmail.com')";

	int one = 5;
	double two = 10.01;
	string tree = "hello world";
	sql << "INSERT INTO test(one,two,tree) VALUES(" << one << "," << two << "," << "'" << tree << "'" << ")";
}


int main(int argc, char * argv[])
{
	create_test_db();

	dbw::session sql(DB_NAME);
	if (!sql.good())
		error_with_exit("Can't establish a database connection!", 1);

	std::vector<int> one;
	std::vector<double> two;
	std::string tree;

	sql << "select one, two, tree from test where one=" << 1, one, two, tree;
	std::cout << one[0] << ", " << two[0] << "; "
		<< one[1] << ", " << two[1] << "\n"
		<< "and " << tree << "\n";

	return 0;
}

void error_with_exit(const std::string & msg, int code)
{
	std::cerr << "error: " << msg << "\n";
	exit(code);
}
