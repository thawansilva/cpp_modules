#pragma once
#include <iostream>

template <typename T>
class Array
{
	T				*_arr;
	unsigned int	_size;

public:
	Array();
	Array(unsigned int n);
	~Array();
	Array(const Array& src);
	Array& operator=(const Array& src);
	T &operator[](unsigned int idx) const;

	//Member Functions
	unsigned int	size() const;

	// Setter
	void			setSize(unsigned int n);
	void			setArray(unsigned int n);
};

#include "Array.tpp"
