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

void separator(std::string title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
	separator("FRAGTRAP TEST");

	FragTrap f("Fraggy");
	f.attack("enemy");
	f.takeDamage(50);
	f.beRepaired(25);
	f.highFivesGuys();

	separator("RESULT");
	std::cout << f << std::endl;
	separator("FIM DOS TESTES");
	return 0;
}
