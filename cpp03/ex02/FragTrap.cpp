/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:15:58 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/16 19:41:52 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unnamed")
{
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
	std::cout << "Default FragTrap "<< name << " created" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
	std::cout << "FragTrap "<< name << " created" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap "<< name << " destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
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

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Let's high five guys?" << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const FragTrap& src)
{
	out << "FragTrap ";
	out << src.getName();
	out << " has:\n";
	out << src.getHit() << " of health\n";
	out << src.getEnergy() << " of energy\n";
	out << src.getAttackDamage() << " of damage";
	return (out);
}
