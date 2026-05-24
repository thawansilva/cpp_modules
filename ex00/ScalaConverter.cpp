/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalaConverter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:55:09 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/24 16:01:46 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalaConverter.hpp"

void convert(std::string &str) const
{
	char *end;
	double num;

	if (str.length() == 1 && !std::isdigit(str.at(0)))
		num = static_cast<double>(str.at(0));
	else
	{
		// obter string
	}
	std::cout << ""  << std::endl;
}

void	print_int()
{}

void	print_double()
{}

void	print_char()
{}

void	print_float()
{}
