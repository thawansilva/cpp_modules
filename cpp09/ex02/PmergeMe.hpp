/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thaperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:49:15 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/13 13:51:00 by thaperei         ###   ########.fr       */
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
	std::size_t			_size;

	PmergeMe();

public:
	explicit PmergeMe(char **argv);
	~PmergeMe();
	PmergeMe(const PmergeMe& src);
	PmergeMe& operator=(const PmergeMe& src);

	//Member Functions
	void	VectorFJA(const std::string &str);
	void	DequeFJA(const std::string &str);
	int		GenerateJacobsthal(int n);

	// Getter
	const std::size_t		&getSize() const;
	const std::vector<int>	&getVector() const;
	const std::deque<int>	&getDeque() const;

};

std::ostream &operator<<(std::ostream &out, PmergeMe &src);
