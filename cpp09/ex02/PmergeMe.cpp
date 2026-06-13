/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thaperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:50:37 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/13 15:10:47 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv)
{
	_size = 0;
	while (argv[_size])
	{
		int	value = std::atoi(argv[_size]);
		if (value < 0)
			throw std::runtime_error("Error: Negative number");
		if (std::find(_vec.begin(), _vec.end(), value) != _vec.end())
			throw std::runtime_error("Error: Duplicated number");
		_vec.push_back(value);
		_deq.push_back(value);
		_size++;
	}
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	*this = src;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& src)
{
	if (this != &src)
	{
		_vec = src.getVector();
		_deq = src.getDeque();
		_size = src.getSize();
	}
	return *this;
}

void	PmergeMe::VectorFJA(const std::string &str)
{
	(void) str;
}

void	PmergeMe::DequeFJA(const std::string &str)
{
	(void)str;
}

int	PmergeMe::GenerateJacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (GenerateJacobsthal(n - 1) + 2 * GenerateJacobsthal(n - 2));
}

const std::size_t	&PmergeMe::getSize() const
{
	return (_size);
}

const std::vector<int>	&PmergeMe::getVector() const
{
	return (_vec);
}

const std::deque<int>	&PmergeMe::getDeque() const
{
	return (_deq);
}

std::ostream &operator<<(std::ostream &out, PmergeMe &src)
{
	for (std::vector<int>::const_iterator it = src.getVector().begin(); it != src.getVector().end(); ++it)
		out << *it << " ";
	return (out);
}
