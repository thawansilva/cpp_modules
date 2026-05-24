/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:35:55 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/17 20:44:58 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_brain = new Brain();
	std::cout << "Dog was created" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog died" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog& other) : AbstractAnimal(other), _brain(NULL)
{
	*this = other;
	std::cout << "Dog copy constructor was called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		type = other.type;
		delete _brain;
		_brain = new Brain();
		*_brain = *other._brain;
	}
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Au au" << std::endl;
}

Brain&	Dog::getBrain(void) const
{
	return *_brain;
}
