#pragma once
#include <vector>
#include <cstdlib>

class search_traversal_range  // full search style traverse for ranges
{
public:
	search_traversal_range(std::vector<int> & data, size_t from = 0)
		: _data{data}, _from{from}, _idx{from}
	{}

	struct iterator
	{
		iterator(search_traversal_range const * r) : _r{r} {}

		int const & operator*() const
		{
			return _r->current();
		}

		iterator & operator++()
		{
			if (!_r->next())
				_r = nullptr;
			return *this;
		}

		bool operator==(iterator rhs) const
		{
			return _r == rhs._r;
		}

		bool operator!=(iterator rhs) const {return !(*this == rhs);}

	private:
		search_traversal_range const * _r;

		friend class search_traversal_range;
	};

	using const_iterator = iterator;
	using value_type = int;

	iterator begin() const {return iterator{this};}
	iterator end() const {return iterator{nullptr};}

private:
	bool next() const;
	int const & current() const;

	std::vector<int> & _data;
	size_t _from;
	mutable size_t _idx;
};
