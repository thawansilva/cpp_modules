#pragma once
#include <iostream>

class Span
{
public:
	Span();
	Span(unsigned int N);
	~Span();
	Span(const Span& other);
	Span& operator=(const Span& other);

	//Member Functions
	void shortestSpan() const;
	void longestSpan() const;
	void addNumber(int num) const;
	// Getters & Setters

	class FullSpanException: public std::exception
	{};
};

//std::ostream&	operator<<(std::ostream& out, const Span& src);
