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
