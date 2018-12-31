#include "search_traversal_range.hpp"

bool search_traversal_range::next() const
{
	_idx = (_idx+1) % _data.size();
	return _idx != _from;
}

int const & search_traversal_range::current() const
{
	return _data[_idx];
}
