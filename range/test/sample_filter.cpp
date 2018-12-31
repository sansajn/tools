// filtered range implementation
#include <vector>
#include <iostream>
#include "../filter.hpp"
#include "../printer.hpp"
#include "../search_traversal_range.hpp"

using std::vector;
using std::cout;


struct is_even_number
{
	bool operator()(int n) const {return (n % 2) == 0;}
};


int main(int argc, char * argv[])
{
	auto data = vector<int>{{1,2,3,4,5}};
	search_traversal_range r{data};
	cout << "r=" << printable(r) << "\n";
	
	search_traversal_range r2{data, 2};
	cout << "r2=" << printable(r2) << "\n";

	auto only_even = filter<search_traversal_range, is_even_number>{r};
	cout << "only_even=" << printable(only_even) << "\n";

	auto only_odd = filtered(r, [](int n){return (n%2) == 1;});
	cout << "only_odd=" << printable(only_odd) << "\n";

	cout << std::endl;
	return 0;
}
