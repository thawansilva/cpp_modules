/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thaperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:47:11 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/10 20:35:19 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <stack>
#include <cctype>
#include <cstdlib>

RPN::RPN()
{}

RPN::~RPN()
{}

RPN::RPN(const RPN& src) { *this = src; }

RPN&	RPN::operator=(const RPN& src)
{
	(void)src;
	return *this;
}

static bool	isOperator(const std::string &str)
{
	return (str == "+" || str == "-" || str == "*" || str == "/");
}

static int doOperation(const std::string &op, int firstValue, int secondValue)
{
	if (op == "+")
		return secondValue + firstValue;
	else if (op == "-")
		return secondValue - firstValue;
	else if (op == "*")
		return secondValue * firstValue;
	if (firstValue == 0)
		throw std::runtime_error("Error: Cannot divide by zero");
	return secondValue / firstValue;
}

void	RPN::calculate(std::string opStr)
{
	std::stringstream	ss(opStr);
	std::stack<int> stack;

	for (std::string token; std::getline(ss, token, ' ');)
	{
		int result;
		if (token.length() == 1 && std::isdigit(token[0]))
			stack.push(std::atoi(token.c_str()));
		else if (isOperator(token) && stack.size() >= 2)
		{
			int	firstValue = stack.top();
			stack.pop();
			int	secondValue = stack.top();
			stack.pop();
			result = doOperation(token, firstValue, secondValue);
			stack.push(result);
		}
		else if (std::isspace(token[0]))
			continue;
		else
			throw std::runtime_error("Error: Wrong format");
	}
	std::cout << stack.top() << std::endl;
}
