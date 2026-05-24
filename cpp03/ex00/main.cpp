/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:59:56 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/15 16:05:58 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void separator(std::string title)
{
	std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
    separator("CLAPTRAP BASICO");

    ClapTrap a("Alpha");
    ClapTrap b("Beta");

    a.attack("Beta");
    b.takeDamage(0);
    b.beRepaired(5);

    separator("ENERGIA ACABANDO");

    for (int i = 0; i < 12; i++)
        a.attack("dummy");

    separator("DANO EXCESSIVO");

    b.takeDamage(1000);
    b.attack("ghost");
    b.beRepaired(5);

	separator("RESULT");
	std::cout << a << std::endl;
	std::cout << b << std::endl;
    separator("FIM DOS TESTES");

}
