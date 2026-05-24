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

AbstractAnimal::AbstractAnimal() : type("Undefined")
{
	std::cout << "Default Animal was created" << std::endl;
}

AbstractAnimal::AbstractAnimal(const AbstractAnimal& other)
{
	*this = other;
	std::cout << "Animal copy constructor was called" << std::endl;
}

AbstractAnimal::~AbstractAnimal()
{
	std::cout << "Animal of type " << type << " died" << std::endl;
}

AbstractAnimal&	AbstractAnimal::operator=(const AbstractAnimal& other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

std::string	AbstractAnimal::getType(void) const
{
	return this->type;
}
