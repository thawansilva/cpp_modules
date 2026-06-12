/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thaperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:50:37 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/10 20:50:37 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}


PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	*this = src;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& src)
{
	(void) src;
	return *this;
}

void	PmergeMe::VectorFJA(const std::string str)
{
	(void) str;
}

void	PmergeMe::DequeFJA(const std::string str)
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
