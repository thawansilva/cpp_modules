/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:59:56 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/17 20:54:22 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

void separator(std::string title)
{
	std::cout << "\n========== " << title << " ==========\n";
}

int main() {
	separator("ARRAY OF ANIMALS");
	Animal*	animals[ZOO_SIZE];
	for (int i = 0; i < ZOO_SIZE; ++i)
	{
		if (i < ZOO_SIZE / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < ZOO_SIZE; ++i)
		animals[i]->makeSound();
	for (int i = 0; i < ZOO_SIZE; ++i)
		delete animals[i];

	separator("DEEP COPY");
	Dog original;
	Dog copy = original;

	original.getBrain().setIdea(0, "Original idea");
	copy.getBrain().setIdea(0, "Copy idea");

	std::cout << "Original: " << original.getBrain().getIdea(0) << std::endl;
	std::cout << "Copy: " << copy.getBrain().getIdea(0) << std::endl;

	separator("ASSIGNMENT OPERATOR");
	Dog a;
	Dog b;

	a.getBrain().setIdea(0, "A idea");
	b = a;

	b.getBrain().setIdea(0, "B idea");

	std::cout << "A: " << a.getBrain().getIdea(0) << std::endl;
	std::cout << "B: " << b.getBrain().getIdea(0) << std::endl;

	separator("COPY STRESS TEST");
	Dog dogs[10];

	for (int i = 0; i < 10; i++) {
		std::ostringstream oss;
		oss << i;
		dogs[i].getBrain().setIdea(0, "Idea " + oss.str());
	}

	Dog copyDogs[10];

	for (int i = 0; i < 10; i++) {
		copyDogs[i] = dogs[i];
	}

	copyDogs[0].getBrain().setIdea(0, "Changed");

	std::cout << dogs[0].getBrain().getIdea(0) << std::endl;
	std::cout << copyDogs[0].getBrain().getIdea(0) << std::endl;

	separator("BRAIN TEST");
	Brain b1;
	b1.setIdea(0, "Hello");

	Brain b2;
	b2 = b1;

	b2.setIdea(0, "World");

	std::cout << "b1: " << b1.getIdea(0) << std::endl;
	std::cout << "b2: " << b2.getIdea(0) << std::endl;
	separator("FINISH TESTS");
}
