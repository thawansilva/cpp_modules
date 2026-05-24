/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 17:53:55 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/17 17:53:56 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void separator(std::string title)
{
    std::cout << "\n========== "
              << title
              << " ==========\n";
}

int main()
{
    separator("TEST 1 - Valid Bureaucrat");

    try
    {
        Bureaucrat bob("Bob", 42);

        std::cout << bob << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 2 - Grade Too High");

    try
    {
        Bureaucrat boss("Boss", 0);

        std::cout << boss << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 3 - Grade Too Low");

    try
    {
        Bureaucrat intern("Intern", 151);

        std::cout << intern << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 4 - Increment Grade");

    try
    {
        Bureaucrat bob("Bob", 2);

        std::cout << bob << std::endl;

        bob.incrementGrade();

        std::cout << bob << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 5 - Increment Overflow");

    try
    {
        Bureaucrat ceo("CEO", 1);

        std::cout << ceo << std::endl;

        ceo.incrementGrade(); // deve lançar exception
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 6 - Decrement Grade");

    try
    {
        Bureaucrat bob("Bob", 149);

        std::cout << bob << std::endl;

        bob.decrementGrade();

        std::cout << bob << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 7 - Decrement Overflow");

    try
    {
        Bureaucrat intern("Intern", 150);

        std::cout << intern << std::endl;

        intern.decrementGrade(); // deve lançar exception
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 8 - Multiple Operations");

    try
    {
        Bureaucrat worker("Worker", 75);

        std::cout << worker << std::endl;

        worker.incrementGrade();
        worker.incrementGrade();
        worker.decrementGrade();

        std::cout << worker << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 9 - Copy Constructor");

    try
    {
        Bureaucrat original("Original", 10);

        Bureaucrat copy(original);

        std::cout << original << std::endl;
        std::cout << copy << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 10 - Assignment Operator");

    try
    {
        Bureaucrat a("A", 50);
        Bureaucrat b("B", 10);

        std::cout << "Before assignment:" << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;

        b = a;

        std::cout << "After assignment:" << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("END");

    return 0;
}
