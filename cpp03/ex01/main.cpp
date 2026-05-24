/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:59:56 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/15 16:12:01 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
void separator(std::string title)
{
    std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    separator("SCAVTRAP TEST");

    ScavTrap s("Guardian");
    s.attack("enemy");
    s.takeDamage(30);
    s.beRepaired(10);
    s.guardGate();

    separator("RESULT");
	std::cout << s << std::endl;
    separator("FIM DOS TESTES");
    return 0;
}
