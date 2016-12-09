#include <iostream>
#include "fs.hpp"

using std::cout;

int main(int argc, char * argv[])
{
	cout 
		<< "temp: " << fs::standard_directories::temp() << "\n"
		<< "user home: " << fs::standard_directories::user_home() << "\n"
		<< "current working: " << fs::standard_directories::working() << "\n"
		<< "program directory: " << fs::standard_directories::program_directory() << "\n";

	return 0;
}
