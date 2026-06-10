/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thaperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:21:44 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/09 18:34:06 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange btc;
		btc.readInput(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cerr <<  e.what() << std::endl;
	}
	return (0);
}
