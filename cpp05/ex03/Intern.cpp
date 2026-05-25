/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:26:53 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/25 14:57:40 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

Intern::Intern(const Intern& src)
{
	*this = src;
}

Intern&	Intern::operator=(const Intern& src)
{
	(void)src;
	return *this;
}

static AForm *makeShrubberyForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *makeRobotomyForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *makePresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	const std::string forms[] = { 
		"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"
	};
	AForm* (*formsMethods[])(const std::string &name) = {
		&makeShrubberyForm, &makeRobotomyForm, &makePresidentialPardonForm
	};
	int size = sizeof(forms) / sizeof(forms[0]);

	for (int i = 0; i < size; ++i)
	{
		if (name == forms[i])
		{
			std::cout << "Intern creates " << name << " Form" << std::endl;
			return formsMethods[i](target);
		}
	}
	std::cout << "Intern could not create a form called " << name << std::endl;
	return NULL;
}

std::ostream&	operator<<(std::ostream& out, const Intern& src)
{
	(void)src;
	out << "I don't know, I just work here.";
	return (out);
}
