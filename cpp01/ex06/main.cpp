/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 07:53:47 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/07 10:46:53 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error - Usage: ./harlFilter <level/message>" << std::endl;
		return (0);
	}
	Harl	harl;
	harl.complain(argv[1]);
	return (0);
}
