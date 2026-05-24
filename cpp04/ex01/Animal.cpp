/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:35:55 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/17 20:45:04 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Undefined")
{
	std::cout << "Default Animal was created" << std::endl;
}

Animal::Animal(const std::string& type) : type(type)
{
	std::cout << "Animal of type " << type << " was created" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal died" << std::endl;
}

Animal::Animal(const Animal& other)
{
	*this = other;
	std::cout << "Animal copy constructor was called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

std::string	Animal::getType(void) const
{
	return this->type;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal made a sound" << std::endl;
}
