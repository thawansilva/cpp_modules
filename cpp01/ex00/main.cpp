/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 11:44:18 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/07 11:44:20 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	randomChump("STACK");
	Zombie* thawan = newZombie("HEAP");
	thawan->announce();
	delete thawan;
	return 0;
}
