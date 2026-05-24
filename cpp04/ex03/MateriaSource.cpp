/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:19:14 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/22 13:33:37 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < AMOUNT_ELEMENTS; ++i)
		_templates[i] = NULL;
	std::cout << "Default MateriaSource constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{

	for (int i = 0; i < AMOUNT_ELEMENTS; ++i)
		delete _templates[i];
	std::cout << "MateriaSource Destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	*this = other;
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource copy assignment called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < AMOUNT_ELEMENTS; ++i)
		{
			delete _templates[i];
			_templates[i] = NULL;
		}
		for (int i = 0; i < AMOUNT_ELEMENTS; ++i)
		{
			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return ;
	for (int i = 0; i < AMOUNT_ELEMENTS; ++i)
	{
		if (_templates[i] == NULL)
		{
			_templates[i] = materia;
			return ;
		}
	}
	delete materia;
	std::cout << "Templates Inventory are full" << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < AMOUNT_ELEMENTS; ++i)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return (_templates[i]->clone());
	}
	return (0);
}
