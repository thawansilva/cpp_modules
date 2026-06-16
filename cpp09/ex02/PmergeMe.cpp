/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thaperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:50:37 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/14 19:10:27 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
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

void	PmergeMe::VectorFJA(const std::string &str) { (void) str; }

void	PmergeMe::DequeFJA(const std::string &str) { (void)str; }

static bool comparePairs(const std::pair<int,int> &left, const std::pair<int,int> &right)
{
	return left.second < right.second;
};

template < typename T >
void	binarySearch(int value, typename T::iterator left, typename T::iterator right)
{
	typename T::iterator	mid;
	while (std::distance(left, right) > 1)
	{
		mid = (left - right) / 2;
		if (value > *mid) left = mid;
		else right = mid;
	}
	if (value > *left)
		return (left + 1);
	return (left);
}

static std::vector<int> generateJacobsthal(int size)
{
	std::vector<int>	seq;
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

static	std::vector<int>	createInsertionList(std::vector<int> jacobsthal_seq, std::vector<int> pend)
{
	std::vector<int>	insertion;
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
				jacob = pend.size() - 1;
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

static void	MergeInsert(std::vector<int> &target)
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

	std::vector<int>	main;
	std::vector<int>	pend;
	for (std::vector< std::pair<int, int> >::iterator it = pair_vectors.begin(); it != pair_vectors.end(); ++it)
	{
		main.push_back(it->second);
		pend.push_back(it->first);
	}
	main.insert(main.begin(), pend.front());
	pend.erase(pend.begin());

	if (straggler != -1)
		pend.push_back(straggler);
	std::vector<int>	jacobsthal_seq = generateJacobsthal(pend.size());

	std::vector<int>	insertion = createInsertionList(jacobsthal_seq, pend);

	for (std::vector<int>::iterator it = insertion.begin(); it != insertion.end(); ++it)
		std::cout << *it << std::endl;
}

void	PmergeMe::sort()
{
	MergeInsert(_vec);
	//	MergeInsert(_deq);
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
