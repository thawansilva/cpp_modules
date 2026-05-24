/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:19:51 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/22 13:35:16 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("undefined")
{
	std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type) : type(type)
{
	std::cout << "AMateria constructor of type " << type << " called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	*this = other;
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	(void)other;
	return (*this);
}

void	AMateria::use(ICharacter& target) const
{
	std::cout << "* " << type << " Materia used by " << target.getName() << " *" << std::endl;
}

const std::string&	AMateria::getType(void) const
{
	return this->type;
}

void		AMateria::setType(const std::string& type)
{
	this->type = type;
}
