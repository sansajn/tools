#define CATCH_CONFIG_MAIN

#include <vector>
#include <algorithm>
#include <iterator>
#include <catch.hpp>
#include "../filter.hpp"

using std::vector;
using std::copy;
using std::back_inserter;

TEST_CASE("filter out odd values with lambda expression", "[filtered]")
{
	vector<int> data = vector<int>{{1, 2, 3, 4, 5, 6}};
	auto only_even = filtered(data, [](int n){return (n%2) == 0;});

	vector<int> expected = vector<int>{{2, 4, 6}};

	vector<int> real;
	copy(only_even.begin(), only_even.end(), back_inserter(real));

	REQUIRE(real == expected);
}
