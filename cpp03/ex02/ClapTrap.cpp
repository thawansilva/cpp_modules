/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:00:03 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/16 19:37:50 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Unnamed"), hitPoint(10),
	energyPoint(10), attackDamage(0)
{
	std::cout << "Default ClapTrap "<< name << " created" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): name(name), hitPoint(10),
	energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap "<< name << " created" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap "<< name << " destroyed" << std::endl;
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
		name = other.name;
		hitPoint = other.hitPoint;
		energyPoint = other.energyPoint;
		attackDamage = other.attackDamage;
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (energyPoint <= 0 || hitPoint <= 0)
		return ;
	energyPoint--;
	std::cout << "ClapTrap " ;
	std::cout << name << " attacks ";
	std::cout << target << ", causing ";
	std::cout << attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	hitPoint = std::max(0, hitPoint - (int)amount);
	std::cout << name << " took ";
	std::cout << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoint <= 0 || hitPoint <= 0)
		return ;
	hitPoint += amount;
	energyPoint--;
	std::cout << name << " was repaired by ";
	std::cout << amount << " hit points" << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return name;
}

int			ClapTrap::getHit(void) const
{
	return hitPoint;
}

int			ClapTrap::getEnergy(void) const
{
	return energyPoint;
}

int			ClapTrap::getAttackDamage(void) const
{
	return attackDamage;
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
