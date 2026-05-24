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

#include "ScalarConverter.hpp"

void	print_int(double &num)
{
	if (std::isnan(num))
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}

	int int_num = static_cast<int>(num);
	std::cout << "int: " << int_num << std::endl;
}

void	print_double(double &num)
{
	double double_num = static_cast<double>(num);
	if (std::isnan(num))
	{
		std::cout << "double: nan" << std::endl;
		return ;
	}

	std::cout << "double: " << double_num << std::endl;
}

void	print_char(double &num)
{
	if (std::isnan(num))
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}

	char ch = static_cast<char>(num);
	if ((ch >= 0 && ch <= 31) || ch == 127)
	{
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: " << ch << std::endl;
}

void	print_float(double &num)
{
	int float_num = static_cast<float>(num);

	if (std::isnan(num))
	{
		std::cout << "float: nanf" << std::endl;
		return ;
	}
	std::cout << "float: " << float_num << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	char *end;
	double num;

	if (str.length() == 1 && !std::isdigit(str.at(0)))
		num = static_cast<double>(str.at(0));
	else
	{
		try
		{
			num = std::strtod(str.c_str(), &end);
		}
		catch(std::exception &e) {
			std::cout <<  e.what() << std::endl;
			return ;
		}
		if (*end != '\0')
		{
			
		}
	}
	print_char(num);
	print_int(num);
	print_float(num);
	print_double(num);
}
