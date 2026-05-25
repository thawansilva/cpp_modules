/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:58:01 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/25 14:58:59 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

#include <iostream>

static void separator(std::string title)
{
	std::cout << "\n";
	std::cout << "========================================\n";
	std::cout << title << std::endl;
	std::cout << "========================================\n";
}

int main()
{
	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);

	separator("VALID FORM CREATION");

	AForm* shrubbery =
		someRandomIntern.makeForm("ShrubberyCreation", "home");

	AForm* robotomy =
		someRandomIntern.makeForm("RobotomyRequest", "Bender");

	AForm* pardon =
		someRandomIntern.makeForm("PresidentialPardon", "Arthur Dent");

	if (shrubbery)
		std::cout << *shrubbery << std::endl;

	if (robotomy)
		std::cout << *robotomy << std::endl;

	if (pardon)
		std::cout << *pardon << std::endl;

	separator("SIGN AND EXECUTE");

	try
	{
		if (shrubbery)
		{
			boss.signForm(*shrubbery);
			boss.executeForm(*shrubbery);
		}

		std::cout << std::endl;
		if (robotomy)
		{
			boss.signForm(*robotomy);
			boss.executeForm(*robotomy);
		}
		std::cout << std::endl;

		if (pardon)
		{
			boss.signForm(*pardon);
			boss.executeForm(*pardon);
		}
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	separator("INVALID FORM NAME");

	AForm* invalid =
		someRandomIntern.makeForm("coffee machine form", "marvin");

	if (!invalid)
		std::cout << "Invalid form correctly returned NULL" << std::endl;

	separator("LOW GRADE TEST");

	try
	{
		Bureaucrat low("LowGuy", 150);

		AForm* test =
			someRandomIntern.makeForm("RobotomyRequest", "target");

		if (test)
		{
			low.signForm(*test);
			low.executeForm(*test);
		}

		delete test;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	separator("EXECUTE UNSIGNED FORM");

	try
	{
		AForm* unsignedForm =
			someRandomIntern.makeForm("ShrubberyCreation", "garden");

		if (unsignedForm)
			boss.executeForm(*unsignedForm);

		delete unsignedForm;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	separator("MEMORY CLEANUP");

	delete shrubbery;
	delete robotomy;
	delete pardon;

	return 0;
}
