/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:20:03 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/22 15:41:40 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

void	Character::dropOnFloor(AMateria* materia)
{
	if (materia == NULL)
		return ;
	for (int i = 0; i < FLOOR_SIZE; ++i)
	{
		if (floor[i] == NULL)
		{
			floor[i] = materia;
			return;
		}
	}
}

Character::Character() : _name("undefined")
{
	// Init floor
	for (int i = 0; i < FLOOR_SIZE; ++i)
		floor[i] = NULL;
	for (int i = 0; i < INVENTORY_SIZE; ++i)
		_inventory[i] = NULL;
	std::cout << "Default character constructor called" << std::endl;
}

Character::Character(const std::string& name) : _name(name)
{
	// Init floor
	for (int i = 0; i < FLOOR_SIZE; ++i)
		floor[i] = NULL;
	for (int i = 0; i < INVENTORY_SIZE; ++i)
		_inventory[i] = NULL;
	std::cout << "Character constructor " << _name << " called" << std::endl;
}

Character::~Character()
{
	// Clean floor
	for (int i = 0; i < FLOOR_SIZE; i++)
	{
		delete floor[i];
		floor[i] = NULL;
	}
	for (int i = 0; i < INVENTORY_SIZE; ++i)
	{
		delete _inventory[i];
		_inventory[i] = NULL;
	}
	std::cout << "Character Destructor " << _name << " called" << std::endl;
}

Character::Character(const Character &other)
{
	for (int i = 0; i < FLOOR_SIZE; i++)
		floor[i] = NULL;
	for (int i = 0; i < INVENTORY_SIZE; ++i)
		this->_inventory[i] = other._inventory[i]
			? other._inventory[i]->clone() : NULL;
	std::cout << "Character copy constructor called" << std::endl;
}

Character&	Character::operator=(const Character& other)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		// Clean Inventory
		for (int i = 0; i < INVENTORY_SIZE; ++i)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		// Copy Inventory
		for (int i = 0; i < INVENTORY_SIZE; ++i)
			this->_inventory[i] = other._inventory[i]
				? other._inventory[i]->clone() : NULL;
	}
	return *this;
}

std::string const&	Character::getName() const
{
	return (_name);
}

void				Character::setName(const std::string& name)
{
	_name = name;
}

void				Character::equip(AMateria* materia)
{
	if (!materia)
		return ;
	for (int i = 0; i < INVENTORY_SIZE; ++i)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = materia;
			return ;
		}
	}
	delete	materia;
}

void				Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_SIZE || _inventory[idx] == NULL)
	{
		std::cout << "Materia does not exist" << std::endl;
		return ;
	}
	dropOnFloor(_inventory[idx]);
	_inventory[idx] = NULL;
}

void				Character::use(int idx, ICharacter& target) const
{
	if (idx < 0 || idx >= INVENTORY_SIZE || _inventory[idx] == NULL)
	{
		std::cout << "Materia does not exist" << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}

std::ostream&	operator<<(std::ostream& out, const Character& src)
{
	out << "My name is " << src.getName();
	return (out);
}
