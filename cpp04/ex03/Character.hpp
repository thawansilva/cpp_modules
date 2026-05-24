/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:20:11 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/22 12:44:27 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"
#define INVENTORY_SIZE 4
#define FLOOR_SIZE 10

class Character : public ICharacter
{
public:
	AMateria*	floor[FLOOR_SIZE];

	Character();
	Character(const std::string& name);
	virtual ~Character();
	Character(const Character& other);
	Character& operator=(const Character& other);

	// Enheritaged functions
	std::string const&	getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target) const;


	// Getters & Setters
	void	setName(const std::string& name);

private:
	AMateria*	_inventory[INVENTORY_SIZE];
	std::string	_name;
	//Member Functions
	void				dropOnFloor(AMateria* materia);
};

std::ostream&	operator<<(std::ostream& out, const Character& src);
