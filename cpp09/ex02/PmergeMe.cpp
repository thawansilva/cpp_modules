/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thaperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:50:37 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/16 19:23:29 by thaperei         ###   ########.fr       */
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
	if (size == 0)
		return (seq);
	seq.push_back(1);
	if (size == 1)
		return (seq);
	seq.push_back(3);
	while (seq.back() < size)
	{
		int nextNum = seq[seq.size() - 1] + 2 * seq[seq.size() - 2];
		seq.push_back(nextNum);
	}
	return (seq);
};

template < typename Container >
static	Container	createInsertionList(Container &jacobsthal_seq, const Container &pend)
{
	Container	insertion;
	std::size_t			pend_size = pend.size();

	insertion.push_back(jacobsthal_seq.front());
	while (insertion.size() < pend.size())
	{
		jacobsthal_seq.erase(jacobsthal_seq.begin());

		if (!jacobsthal_seq.empty())
		{
			int	last = insertion.back();
			int	jacob = jacobsthal_seq.front();

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
			int	missing = pend.size() - 1;
			while (insertion.size() < pend_size && missing > insertion.back())
				insertion.push_back(missing--);
		}
	}
	insertion.erase(insertion.end() - 1);
	return (insertion);
}

template < typename Container >
static void	MergeInsert(Container &target)
{
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
	main.insert(main.begin(), pend.front());
	pend.erase(pend.begin());

	Container	jacobsthal_seq = generateJacobsthal<Container>(pend.size());

	Container	insertion = createInsertionList(jacobsthal_seq, pend);
	// Insert elements to main
	typename Container::iterator insert_pos;
	for (typename Container::iterator it = insertion.begin(); it != insertion.end(); ++it)
	{
		int	value;

		value = pend[*it];
		insert_pos = std::upper_bound(main.begin(), main.end(), value);
		main.insert(insert_pos, value);
	}
	if (straggler != -1)
	{
		insert_pos = std::upper_bound(main.begin(), main.end(), straggler);
		main.insert(insert_pos, straggler);
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
