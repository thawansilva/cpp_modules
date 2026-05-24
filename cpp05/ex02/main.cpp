/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:58:01 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/21 19:17:21 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

static void separator(const std::string& title)
{
    std::cout << "\n====================================\n";
    std::cout << title << std::endl;
    std::cout << "====================================\n";
}

int main()
{
    separator("TEST 1 - Bureaucrat creation");

    try
    {
        Bureaucrat high("High", 1);
        Bureaucrat low("Low", 150);

        std::cout << high << std::endl;
        std::cout << low << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 2 - Invalid grades");

    try
    {
        Bureaucrat tooHigh("TooHigh", 0);
    }
    catch (std::exception& e)
    {
        std::cout << "Expected error: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat tooLow("TooLow", 151);
    }
    catch (std::exception& e)
    {
        std::cout << "Expected error: " << e.what() << std::endl;
    }

    separator("TEST 3 - ShrubberyCreationForm");

    try
    {
        Bureaucrat bob("Bob", 1);

        ShrubberyCreationForm shrub("home");

        std::cout << shrub << std::endl;

        bob.signForm(shrub);
        bob.executeForm(shrub);

        std::cout << "Check generated file: home_shrubbery" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 4 - RobotomyRequestForm");

    try
    {
        Bureaucrat alice("Alice", 1);

        RobotomyRequestForm robot("Bender");

        alice.signForm(robot);

        for (int i = 0; i < 5; i++)
            alice.executeForm(robot);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 5 - PresidentialPardonForm");

    try
    {
        Bureaucrat president("President", 1);

        PresidentialPardonForm pardon("Arthur Dent");

        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 6 - Execute unsigned form");

    try
    {
        Bureaucrat boss("Boss", 1);

        RobotomyRequestForm form("Marvin");

        boss.executeForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << "Expected error: " << e.what() << std::endl;
    }

    separator("TEST 7 - Grade too low to sign");

    try
    {
        Bureaucrat low("Low", 150);

        ShrubberyCreationForm form("garden");

        low.signForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << "Expected error: " << e.what() << std::endl;
    }

    separator("TEST 8 - Grade too low to execute");

    try
    {
        Bureaucrat signer("Signer", 1);
        Bureaucrat executor("Executor", 150);

        PresidentialPardonForm form("Ford Prefect");

        signer.signForm(form);
        executor.executeForm(form);
    }
    catch (std::exception& e)
    {
        std::cout << "Expected error: " << e.what() << std::endl;
    }

    separator("TEST 9 - Copy constructor / assignment");

    try
    {
        ShrubberyCreationForm original("forest");
        ShrubberyCreationForm copy(original);

        ShrubberyCreationForm assigned("tmp");
        assigned = original;

        std::cout << original << std::endl;
        std::cout << copy << std::endl;
        std::cout << assigned << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("ALL TESTS FINISHED");

    return 0;
}
