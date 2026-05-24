/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:37:37 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/17 20:44:48 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat was created" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat died" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other.type)
{
	*this = other;
	std::cout << "Cat copy constructor was called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meeeoooow Meeeoooow" << std::endl;
}
