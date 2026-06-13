/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thaperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:21:44 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/13 14:01:05 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc <= 2)
	{
		std::cerr << "Usage: ./PmergeMe <num1> <num2> ..." << std::endl;
		return (1);
	}
	try
	{
		(void)argv;
		PmergeMe FJA(&argv[1]);
		
		std::cout << "Before: " << FJA << std::endl;
		std::cout << "After: " << FJA << std::endl;
		std::cout << "Time to process a range of " << FJA.getSize()
		<< " elements with std::vector : " << std::endl;
		std::cout << "Time to process a range of " << FJA.getSize()
		<< " elements with std::deque : " << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
