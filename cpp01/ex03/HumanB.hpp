/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:39:22 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/03 18:52:03 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
public:
	HumanB(std::string name);
	~HumanB();

	void	attack() const;
	void	setWeapon(Weapon &weapon);

private:
	std::string	name;
	Weapon		*weapon;
};
#endif
