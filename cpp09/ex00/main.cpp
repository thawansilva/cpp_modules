/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thaperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:21:44 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/06 18:32:33 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc <database>" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange btc;
	}
	catch(std::exception &e)
	{
		std::cerr <<  e.what() << std::endl;
	}
	return (0);
}
