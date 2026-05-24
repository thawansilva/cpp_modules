/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:19:31 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/22 13:45:27 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Default Ice constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria("ice")
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = other;
}

Ice&		Ice::operator=(const Ice& other)
{
	(void) other;
	std::cout << "Ice copy assignment called" << std::endl;
	return *this;
}

AMateria*	Ice::clone() const
{
	return (new Ice(*this));
}

void		Ice::use(ICharacter& character) const
{
	std::cout << "* shoots an ice bolt at " << character.getName() << " *" << std::endl;
}
