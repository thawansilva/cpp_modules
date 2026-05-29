/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:55:09 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/29 18:11:33 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return *this;
}

static void	print_int(double &num)
{
	std::cout << "int: ";
	if (std::isnan(num) || std::isinf(num))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << static_cast<int>(num) << std::endl;
}

static void	print_char(double &num)
{
	std::cout << "char: ";
	if (std::isnan(num) || num < 0.0 || std::isinf(num))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}

	if (num > 31 && num < 127)
	{
		std::cout << '\'' << static_cast<char>(num) << '\'' << std::endl;
		return ;
	}
	std::cout << "Non displayable" << std::endl;
}

static void	print_float(double &num)
{
	std::cout << "float: ";
	if (std::isnan(num))
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (std::isinf(num))
	{
		if (num > 0)
			std::cout << "+inf";
		else
			std::cout << "-inf";
	}
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(num);
	std::cout << "f" << std::endl;
}

static void	print_double(const double &num)
{
	std::cout << "double: ";
	if (std::isinf(num))
	{
		if (num > 0)
			std::cout << "+inf";
		else
			std::cout << "-inf";
	}
	else
		std::cout << std::fixed << std::setprecision(1) << num;
	std::cout << std::endl;
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
		if ((*end != '\0' && *end != 'f') || (*end != '\0' && *(end + 1) != '\0'))
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			std::cout << "double: impossible" << std::endl;
			return ;
		}
	}
	print_char(num);
	print_int(num);
	print_float(num);
	print_double(num);
}
