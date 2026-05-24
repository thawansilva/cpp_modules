/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 07:53:51 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/07 12:32:27 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::debug( void )
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << "I’ve been coming for years, whereas you started working here just last month." << std::endl << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	int			i;
	std::string	levels[NUM_LEVELS] = {"DEBUG", "INFO", "WARNING",
		"ERROR"};
	method_t		functions[NUM_LEVELS] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	for (i = 0; i < NUM_LEVELS; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return ;
		}
	}
}
