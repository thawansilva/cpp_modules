/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thaperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:50:37 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/16 21:23:14 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <sys/time.h>
#include <utility>

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

PmergeMe::PmergeMe(const PmergeMe& src) { *this = src; }

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

static bool comparePairs(const std::pair<int,int> &left, const std::pair<int,int> &right)
{
	return left.second < right.second;
};

template < typename Container >
static Container generateJacobsthal(int size)
{
	Container	seq;

	seq.push_back(0);
	seq.push_back(1);

	int	nextNumber = *(seq.rbegin() + 1) * 2 + seq.back();
	while (nextNumber < size)
	{
		seq.push_back(nextNumber);
		nextNumber = *(seq.rbegin() + 1) * 2 + seq.back();
	}
	seq.erase(seq.begin() + 1);
	return (seq);
};

template < typename Container >
static	Container	createInsertionList(Container &jacobsthal, const Container &pend)
{
	Container		insertion;
	std::size_t		pend_size = pend.size();

	insertion.push_back(jacobsthal.front());
	while (insertion.size() < pend.size())
	{
		jacobsthal.erase(jacobsthal.begin());

		if (!jacobsthal.empty())
		{
			int	last = insertion.back();
			int	jacob = jacobsthal.front();

			if (static_cast<std::size_t>(jacob) > pend_size)
				jacob = pend.size();
			insertion.push_back(jacob--);
			while (jacob > last && insertion.size() < pend_size)
			{
				if (std::find(insertion.begin(), insertion.end(), jacob) == insertion.end())
					insertion.push_back(jacob);
				jacob--;
			}
		}
		else
		{
			int	missing = pend_size - 1;
			while (insertion.size() < pend_size)
				insertion.push_back(missing--);
		}
	}
	return (insertion);
}

template < typename Container >
static void	MergeInsert(Container &target)
{
	if (target.size() <= 3)
	{
		std::sort(target.begin(), target.end());
		return ;
	}
	int	straggler = -1;

	if (target.size() % 2 != 0)
	{
		straggler = target.back();
		target.pop_back();
	}

	// Create pairs
	std::vector< std::pair<int, int> >	pair_vectors;
	for (std::size_t i = 0; i < target.size(); i += 2)
	{
		if (target[i] > target[i + 1])
			pair_vectors.push_back(std::make_pair(target[i + 1], target[i]));
		else 
			pair_vectors.push_back(std::make_pair(target[i], target[i + 1]));
	}
	// Sort pairs
	std::sort(pair_vectors.begin(), pair_vectors.end(), comparePairs);

	// Create main and pend
	Container	main;
	Container	pend;
	for (std::vector< std::pair<int, int> >::iterator it = pair_vectors.begin(); it != pair_vectors.end(); ++it)
	{
		main.push_back(it->second);
		pend.push_back(it->first);
	}

	if (straggler != -1)
		pend.push_back(straggler);
	
	Container	jacobsthal = generateJacobsthal<Container>(pend.size());

	Container	insertion = createInsertionList(jacobsthal, pend);
	// Insert elements to main
	typename Container::iterator insert_pos;
	for (typename Container::iterator it = insertion.begin(); it != insertion.end(); ++it)
	{
		int	value;

		value = pend[*it];
		insert_pos = std::upper_bound(main.begin(), main.end(), value);
		main.insert(insert_pos, value);
	}
	target = main;
}

void	PmergeMe::sort()
{
	std::cout << "Before: " << *this << std::endl;

	timeval start, end;

	gettimeofday(&start, NULL);
	MergeInsert< std::vector<int> >(_vec);
	gettimeofday(&end, NULL);

	long elapsed_vec = (end.tv_sec - start.tv_sec) * 1000000L +
		(end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	MergeInsert< std::deque<int> >(_deq);
	gettimeofday(&end, NULL);

	long elapsed_deq = (end.tv_sec - start.tv_sec) * 1000000L +
		(end.tv_usec - start.tv_usec);

	std::cout << "After: " << *this << std::endl;
	std::cout << "Time to process a range of " << _size
		<< " elements with std::vector: " << elapsed_vec << " microseconds" << std::endl;
	std::cout << "Time to process a range of " << _size
		<< " elements with std::deque: " << elapsed_deq << " microseconds" << std::endl;
}

const std::size_t	&PmergeMe::getSize() const { return (_size); }

const std::vector<int>	&PmergeMe::getVector() const { return (_vec); }

const std::deque<int>	&PmergeMe::getDeque() const { return (_deq); }

std::ostream &operator<<(std::ostream &out, PmergeMe &src)
{
	for (std::vector<int>::const_iterator it = src.getVector().begin(); it != src.getVector().end(); ++it)
		out << *it << " ";
	return (out);
}
