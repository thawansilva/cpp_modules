/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:59:56 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/15 16:22:53 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void separator(std::string title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
	separator("DIAMONDTRAP TEST");
	DiamondTrap d("Diamond");
	
	d.attack("boss");
	d.takeDamage(40);
	d.beRepaired(20);
	d.whoAmI();
	d.highFivesGuys();
	d.guardGate();
	
	separator("DESTRUICAO EM CASCATA");
	{
		DiamondTrap temp("TempDiamond");
		temp.attack("enemy");
	}
	separator("RESULT");
	std::cout << d << std::endl;
	separator("FIM DOS TESTES");
	return 0;
}
