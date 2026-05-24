/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:39:52 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/03 18:39:53 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): name(name), weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
