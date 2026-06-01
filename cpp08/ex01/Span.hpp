#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	std::vector<int>	_vec;
	std::size_t			_size;

	Span();

public:
	Span(const unsigned int N);
	~Span();
	Span(const Span& src);
	Span& operator=(const Span& src);

	//Member Functions
	std::size_t			shortestSpan(void) const;
	std::size_t			longestSpan(void) const;
	void				addNumber(const int num);

	// Getters & Setters
	std::size_t			getSize(void) const;
	std::vector<int>	getVector(void) const;
};

std::ostream&	operator<<(std::ostream& out, const Span& src);
