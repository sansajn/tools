// test directory iteratora
#include <iostream>
#include "directory_iterator.hpp"

char const * path_to_list = "/tmp";

using std::cout;

int main(int argc, char * argv[])
{
	{  // pure iterator interface
		directory_iterator it{path_to_list}, end_it;
		for (; it != end_it; ++it)
			cout << (*it)->d_name << "\n";
	}

	// c++11 for loop
	for (auto entry : directory_iterator{path_to_list})
		cout << entry->d_name << "\n";

	return 0;
}
