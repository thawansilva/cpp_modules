/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:26:53 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/23 17:49:57 by thaperei         ###   ########.fr       */
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
	if (this != &src)
		*this = src;
	return *this;
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	AForm	*form;

	if (name.compare("ShrubberyCreationForm") == 0)
		form = new ShrubberyCreationForm(target);
	else if (name.compare("RobotomyRequestForm") == 0)
		form = new RobotomyRequestForm(target);
	else if (name.compare("PresidentialPardonForm") == 0)
		form = new PresidentialPardonForm(target);
	else
	{
		std::cout << "Intern could not create a form called " << name << std::endl;
		return NULL;
	}
	return form;
}

std::ostream&	operator<<(std::ostream& out, const Intern& src)
{
	(void)src;
	out << "I don't know, I just work here.";
	return (out);
}
