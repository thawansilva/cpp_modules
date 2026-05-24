/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 11:41:08 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/07 11:41:58 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>

class Zombie
{
public:
	Zombie();
	~Zombie();

	void	announce(void) const;
	void	setName(std::string name);

private:
	std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);
#endif
