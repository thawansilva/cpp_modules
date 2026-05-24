/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:58:01 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/17 15:58:02 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void separator(std::string title)
{
    std::cout << "\n========== "
              << title
              << " ==========\n";
}

int main()
{
    separator("TEST 1 - Bureaucrat válido");

    try
    {
        Bureaucrat bob("Bob", 42);
        std::cout << bob << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 2 - Bureaucrat grade muito alto");

    try
    {
        Bureaucrat boss("Boss", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 3 - Bureaucrat grade muito baixo");

    try
    {
        Bureaucrat intern("Intern", 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 4 - Increment grade");

    try
    {
        Bureaucrat bob("Bob", 2);

        std::cout << bob << std::endl;

        bob.incrementGrade();

        std::cout << bob << std::endl;

        bob.incrementGrade(); // deve lançar exceção
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 5 - Decrement grade");

    try
    {
        Bureaucrat bob("Bob", 149);

        std::cout << bob << std::endl;

        bob.decrementGrade();

        std::cout << bob << std::endl;

        bob.decrementGrade(); // deve lançar exceção
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 6 - Form válido");

    try
    {
        Form tax("Tax Form", 50, 25);

        std::cout << tax << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 7 - Form grade inválido");

    try
    {
        Form invalid("Invalid Form", 0, 25);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 8 - Assinar form com sucesso");

    try
    {
        Bureaucrat bob("Bob", 1);
        Form form("Top Secret", 10, 5);

        std::cout << form << std::endl;

        bob.signForm(form);

        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 9 - Assinar form falhando");

    try
    {
        Bureaucrat low("Low", 150);
        Form form("Secret", 50, 25);

        std::cout << form << std::endl;

        low.signForm(form);

        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 10 - beSigned direto");

    try
    {
        Bureaucrat bob("Bob", 10);
        Form form("42 Evaluation", 20, 20);

        form.beSigned(bob);

        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 11 - beSigned falhando");

    try
    {
        Bureaucrat bob("Bob", 100);
        Form form("VIP Access", 50, 50);

        form.beSigned(bob);

        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("TEST 12 - Canonical Form");

    try
    {
        Form original("Original", 42, 42);
        Form copy(original);

        std::cout << original << std::endl;
        std::cout << copy << std::endl;

        Form assigned("Assigned", 1, 1);

        assigned = original;

        std::cout << assigned << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    separator("END");

    return 0;
}
