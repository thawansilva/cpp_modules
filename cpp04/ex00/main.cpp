/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:59:56 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/25 18:38:46 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

void separator(std::string title)
{
	std::cout << "\n========== " << title << " ==========\n";
}


int main() {
	separator("BASIC INSTANTIATION");
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << animal->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	
	separator("POLYMORPHISM");
	const Animal* zoo[4];
	
	zoo[0] = new Dog();
	zoo[1] = new Cat();
	zoo[2] = new Dog();
	zoo[3] = new Cat();
	
	for (int i = 0; i < 4; i++) {
		std::cout << zoo[i]->getType() << ": ";
		zoo[i]->makeSound();
	}
	
	separator("DESTRUCTORS");
	delete animal;
	delete dog;
	delete cat;
	
	for (int i = 0; i < 4; i++) {
		delete zoo[i];
	}
	
	separator("COPY AND ATTRIBUTION");
	Dog originalDog;
	Dog copiedDog(originalDog); // construtor de cópia
	
	Dog assignedDog;
	assignedDog = originalDog; // operador =
	
	std::cout << "Original: ";
	originalDog.makeSound();
	std::cout << "Copy: ";
	copiedDog.makeSound();
	std::cout << "Assigned: ";
	assignedDog.makeSound();
	
	separator("CONST CORRECTNESS");
	const Dog constDog;
	constDog.makeSound(); // só funciona se método for const
	
	separator("FINISH TEST");

	return 0;
}
