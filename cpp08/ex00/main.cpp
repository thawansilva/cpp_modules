/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:54:29 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/04 19:45:21 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

static void separator(const std::string& title)
{
	std::cout << "\n===== " << title << " =====\n";
}

int main()
{
	separator("VECTOR");

	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	std::cout << "Searching 20..." << std::endl;
	if (easyfind(vec, 20))
		std::cout << "Found!" << std::endl;

	std::cout << "Searching 99..." << std::endl;
	if (easyfind(vec, 99))
		std::cout << "Found!" << std::endl;

	separator("LIST");

	std::list<int> lst;
	lst.push_back(-10);
	lst.push_back(-20);
	lst.push_back(-30);

	if (easyfind(vec, -20))
		std::cout << "Found!" << std::endl;

	separator("DEQUE");

	std::deque<int> dq;
	dq.push_back(1);
	dq.push_back(1);
	dq.push_back(1);
	dq.push_back(42);

	if (easyfind(dq, 42))
		std::cout << "Found 42" << std::endl;

	separator("EMPTY CONTAINER");

	std::vector<int> empty;

	if (easyfind(empty, 5))
		std::cout << "Found!" << std::endl;
	return 0;
}
