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
		_value = other._value;
	}
	return *this;
}

int		Span::getValue(void) const
{
	return _value;
}

void	Span::setValue(int value)
{
	_value = value;
}

//std::ostream&	operator<<(std::ostream& out, const Span& src)
//{
//	return (out);
//}
