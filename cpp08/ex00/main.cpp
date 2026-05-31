/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:54:29 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/31 17:56:51 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>

int main()
{
	// Array container
	std::cout << "=== ARRAY ===" << std::endl;
	std::array<int, 10> arr = { 0, 1, 2, 3, 4, 5, 6};

	int array_result = easyfind<std::array<int, 10>>(arr, 3);
	if (array_result)
		std::cout << "Number found" << std::endl;
	else
		std::cout << "Number not found" << std::endl;

	// Vector container
	std::cout << "=== VECTOR ===" << std::endl;
	std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6};

	int vec_result = easyfind<std::vector<int>>(vec, 10);
	if (vec_result)
		std::cout << "Number found" << std::endl;
	else
		std::cout << "Number not found" << std::endl;

	// List container
	std::cout << "=== LIST ===" << std::endl;
	std::list<int> list = { 0, 1, 2, 3, 4, 5, 6};

	int list_result = easyfind<std::list<int>>(list, 4);
	if (list_result)
		std::cout << "Number found" << std::endl;
	else
		std::cout << "Number not found" << std::endl;

	// Dequeue container
	std::cout << "=== DEQUEUE ===" << std::endl;
	std::deque<int> d = { 0, 1, 2, 3, 4, 5, 6};

	int deque_result = easyfind<std::deque<int>>(d, -1);
	if (deque_result)
		std::cout << "Number found" << std::endl;
	else
		std::cout << "Number not found" << std::endl;
	return 0;
}
