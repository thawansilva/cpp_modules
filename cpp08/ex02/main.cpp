/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:54:29 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/03 19:59:43 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include "Span.hpp"
#include <iostream>

int main()
{
	try
	{
		std::cout << "=== Teste básico ===" << std::endl;

		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: "
			<< sp.shortestSpan() << std::endl;

		std::cout << "Longest span: "
			<< sp.longestSpan() << std::endl;

		std::cout << "\n=== Teste overflow ===" << std::endl;

		try
		{
			sp.addNumber(42);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		std::cout << "\n=== Teste com poucos elementos ===" << std::endl;

		Span small(2);
		small.addNumber(1);

		try
		{
			std::cout << small.shortestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "Erro esperado: "
				<< e.what() << std::endl;
		}

		std::cout << "\n=== Teste grande ===" << std::endl;

		Span big(10000);

		for (int i = 0; i < 10000; i++)
			big.addNumber(i);

		std::cout << "Shortest span: "
			<< big.shortestSpan() << std::endl;

		std::cout << "Longest span: "
			<< big.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Erro: " << e.what() << std::endl;
	}
	return 0;
}
