/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thaperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:49:15 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/10 21:27:38 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
	std::vector<int>	_vec;
	std::deque<int>		_deq;
	std::size_t			_num;

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& src);
	PmergeMe& operator=(const PmergeMe& src);

	//Member Functions
	void	VectorFJA(const std::string str);
	void	DequeFJA(const std::string str);
	int		GenerateJacobsthal(int n);
};
