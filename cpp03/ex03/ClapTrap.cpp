/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:00:03 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/16 21:01:29 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Unnamed"), _hitPoint(10),
	_energyPoint(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap "<< _name << " created" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): _name(name), _hitPoint(10),
	_energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap "<< _name << " created" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap "<< _name << " destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoint = other._hitPoint;
		_energyPoint = other._energyPoint;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoint <= 0 || _hitPoint <= 0)
		return ;
	_energyPoint--;
	std::cout << "ClapTrap " ;
	std::cout << _name << " attacks ";
	std::cout << target << ", causing ";
	std::cout << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoint = std::max(0, _hitPoint - (int)amount);
	std::cout << _name << " took ";
	std::cout << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoint <= 0 || _hitPoint <= 0)
		return ;
	_hitPoint += amount;
	_energyPoint--;
	std::cout << _name << " was repaired by ";
	std::cout << amount << " hit points" << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return _name;
}

int			ClapTrap::getHit(void) const
{
	return _hitPoint;
}

int			ClapTrap::getEnergy(void) const
{
	return _energyPoint;
}

int			ClapTrap::getAttackDamage(void) const
{
	return _attackDamage;
}

std::ostream&	operator<<(std::ostream &out, const ClapTrap& src)
{
	out << src.getName();
	out << " has:\n";
	out << src.getHit() << " of health\n";
	out << src.getEnergy() << " of energy\n";
	out << src.getAttackDamage() << " of damage";
	return (out);
}
