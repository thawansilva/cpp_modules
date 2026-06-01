#include "Span.hpp"

Span::Span(): _size(0) {}

Span::Span(const unsigned int N): _size(N) {}

Span::~Span() {}

Span::Span(const Span& src): _vec(src.getVector()), _size(src.getSize()) {}

Span&	Span::operator=(const Span& src)
{
	if (this != &src)
	{
		_size = src.getSize();
		_vec = src.getVector();
	}
	return *this;
}

void	Span::addNumber(const int num)
{
	if (_vec.size() >= _size)
		throw std::runtime_error("Error: Vector is full");
	_vec.push_back(num);
}

std::size_t	Span::shortestSpan(void) const
{
	std::size_t	shortest = -1;
	if (_vec.size() <= 1)
		throw std::runtime_error("Error: Too few elements to find shortest span");

	std::vector<int> sorted(_vec);
	std::sort(sorted.begin(), sorted.end());

	for (std::vector<int>::const_iterator curr = sorted.begin(); curr != sorted.end(); ++curr)
	{
		if (curr == sorted.begin()) continue;
		std::size_t new_diff = static_cast<std::size_t>(*curr - *(curr - 1));
		if (new_diff < shortest)
			shortest = new_diff;
	}
	return shortest;
}

std::size_t	Span::longestSpan(void) const
{
	if (_vec.size() <= 1)
		throw std::runtime_error("Error: Too few elements to find longest span");

	std::vector<int> sorted(_vec);
	std::sort(sorted.begin(), sorted.end());
	return (static_cast<std::size_t>(*(--sorted.end()) - *sorted.begin()));
}

std::size_t	Span::getSize(void) const { return (_size); }

std::vector<int>	Span::getVector(void) const { return _vec; }

std::ostream&	operator<<(std::ostream& out, const Span& src)
{
	std::vector<int> vec = src.getVector();
	out << "{ ";
	for (auto i : vec)
	{
		if (i == (*(vec.end() - 1)))
		{
			out << i;
			break ;
		}
		out << i << ", ";
	}
	out << " }";
	return (out);
}
