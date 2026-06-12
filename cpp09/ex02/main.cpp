/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thaperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:21:44 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/10 21:27:20 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./PmergeMe <expression>" << std::endl;
		return (1);
	}
	try
	{
		(void)argv;
		PmergeMe pmergeme;
		
		std::cout << "Before: " << argv[1] << std::endl;
		std::cout << "After: " << std::endl;
		std::cout << "Time to process a range of 3000 elements with std:::vector : " << std::endl;
		std::cout << "Time to process a range of 3000 elements with std:::deque : " << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
