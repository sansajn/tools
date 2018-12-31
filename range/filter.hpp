#pragma once

/*! \code
vector<int> data = vector<int>{{1, 2, 3, 4, 5, 6}};
auto only_even = filtered(data, [](int n){return (n%2) == 0;});
\endcode */
template <typename Range, typename Pred>
class filter
{
public:
	filter(Range const & r, Pred const & cond = Pred{})
		: _r{r}, _cond{cond}, _it{_r.begin()}
	{
		satisfy_condition();
	}

	struct iterator : public std::iterator<std::input_iterator_tag, typename Range::value_type>
	{
		iterator(filter const * f) : _f{f} {}

		typename std::iterator_traits<iterator>::value_type const & operator*() const
		{
			return _f->current();
		}

		iterator & operator++()
		{
			if (!_f->next())
				_f = nullptr;
			return *this;
		}

		bool operator==(iterator rhs) const
		{
			return _f == rhs._f;
		}

		bool operator!=(iterator rhs) const {return !(*this == rhs);}

	private:
		filter const * _f;

		friend class filter;
	};

	using const_iterator = iterator;

	iterator begin() const {return iterator{this};}
	iterator end() const {return iterator{nullptr};}

private:
	bool next() const
	{
		++_it;
		satisfy_condition();
		return _it != _r.end();
	}

	void satisfy_condition() const
	{
		while (_it != _r.end() && !_cond(*_it))
			++_it;
	}

	typename Range::value_type const & current() const
	{
		return *_it;
	}

	Range const & _r;
	Pred const & _cond;
	mutable typename Range::const_iterator _it;
};

template <typename Range, typename Pred>
filter<Range, Pred> filtered(Range const & r, Pred const & p)
{
	return filter<Range, Pred>{r, p};
}
