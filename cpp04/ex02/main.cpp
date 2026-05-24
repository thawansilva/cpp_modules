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
	separator("CONSTRUCTION & DESTRUCTION");
	const AbstractAnimal* j = new Dog();
	const AbstractAnimal* i = new Cat();

	delete j;
	delete i;

	separator("ARRAY OF ANIMALS");
	AbstractAnimal* animals[ZOO_SIZE];

	for (int i = 0; i < ZOO_SIZE; i++)
	{
		if (i < ZOO_SIZE / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < ZOO_SIZE; i++)
		animals[i]->makeSound();
	for (int i = 0; i < ZOO_SIZE; i++)
		delete animals[i];

	separator("DEEP COPY");
	Dog original;
	original.getBrain().setIdea(0, "I want food");

	Dog copy = original;
	copy.getBrain().setIdea(0, "I want sleep");
	std::cout << "Original: " << original.getBrain().getIdea(0) << std::endl;
	std::cout << "Copy: " << copy.getBrain().getIdea(0) << std::endl;

	separator("ASSIGNMENT OPERATOR");
	Dog d1;
	d1.getBrain().setIdea(0, "Bone");

	Dog d2;
	d2 = d1;

	d2.getBrain().setIdea(0, "Ball");

	std::cout << d1.getBrain().getIdea(0) << std::endl;
	std::cout << d2.getBrain().getIdea(0) << std::endl;

	separator("COPY STRESS TEST");
	Dog dogs[10];
	for (int i = 0; i < 10; i++)
	{
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
}
