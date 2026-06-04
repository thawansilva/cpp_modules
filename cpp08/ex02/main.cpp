/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thaperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 20:43:53 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/04 20:34:11 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

static void separator(const std::string& title)
{
	std::cout << "\n===== " << title << " =====\n";
}

int main()
{
	separator("SUBJECT TEST");

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	separator("COPY CONSTRUCTOR");

	MutantStack<int> copy(mstack);

	for (MutantStack<int>::iterator i = copy.begin(); i != copy.end(); ++i)
		std::cout << *i << std::endl;

	separator("ASSIGNMENT OPERATOR");

	MutantStack<int> assigned;

	assigned = mstack;

	for (MutantStack<int>::iterator i = assigned.begin(); i != assigned.end(); ++i)
		std::cout << *i << std::endl;

	separator("MODIFY THROUGH ITERATOR");

	for (MutantStack<int>::iterator i = mstack.begin(); i != mstack.end(); ++i)
		*i += 100;

	for (MutantStack<int>::iterator i = mstack.begin(); i != mstack.end(); ++i)
		std::cout << *i << std::endl;

	separator("COMPARE WITH LIST");

	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	separator("EMPTY STACK");

	MutantStack<int> empty;

	std::cout << "size = " << empty.size() << std::endl;

	std::cout << "begin == end ? " << (empty.begin() == empty.end()) << std::endl;

	return 0;
}
