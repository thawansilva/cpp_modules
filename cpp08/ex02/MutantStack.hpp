#pragma once

#include <stack>

// Implement the begin, cbegin, end, cend
// iterators: regular, const, reverse and const reverse
template < typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack& src);
	MutantStack& operator=(const MutantStack& src);

	//Member Functions
};
