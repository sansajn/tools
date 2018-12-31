#pragma once
#include <iostream>

/*! \code
auto data = vector<int>{{1,2,3,4,5}};
cout << "r=" << printable(data) << "\n";
\endcode */
template <typename Range>
struct range_printer
{
	range_printer(Range const & r) : _r{r} {}

	friend std::ostream & operator<<(std::ostream & out, range_printer const & rhs)
	{
		out << "[";
		size_t i = 0;
		for (auto const & v : rhs._r)
		{
			if (i++ > 0)
				out << ", ";

			out << v;
		}
		out << "]";

		return out;
	}

private:
	Range const & _r;
};

template <typename Range>
inline range_printer<Range> printable(Range const & r)
{
	return range_printer<Range>{r};
}
