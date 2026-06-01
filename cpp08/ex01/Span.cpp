#include "Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int N)
{
}

Span::~Span()
{
}

Span::Span(const Span& other)
{
	*this = other;
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
	}
	return *this;
}

void		Span::addNumber(int num) const
{
	// if span is not empty
	// 		throw Exception
	// add element to span
}

int		Span::shortestSpan() const
{
	// if span.size() <= 0
	// 		throw Exception
	// calculate shortest span
	return 1;
}

int		Span::longestSpan() const
{
	// if span.size() <= 0
	// 		throw Exception
	// calculate longest span
	return 1;
}

//int		Span::getValue(oid) const
//{
//	return _value;
//}
//
//void	Span::setValue(int value)
//{
//	_value = value;
//}

//std::ostream&	operator<<(std::ostream& out, const Span& src)
//{
//	return (out);
//}
