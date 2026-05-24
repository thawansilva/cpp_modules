/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:00:10 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/16 20:58:44 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	~ClapTrap();
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	// Member functions
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	// Getters
	std::string	getName(void) const;
	int			getHit(void) const;
	int			getEnergy(void) const;
	int			getAttackDamage(void) const;

protected:
	std::string	_name;
	int			_hitPoint;
	int			_energyPoint;
	int			_attackDamage;
};

std::ostream&	operator<<(std::ostream &out, const ClapTrap& src);
