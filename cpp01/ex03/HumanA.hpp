/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:40:02 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/03 18:40:03 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
public:
	HumanA(std::string, Weapon& weapon);
	~HumanA();

	void	attack() const;

private:
	std::string	name;
	Weapon		&weapon;
};
#endif
