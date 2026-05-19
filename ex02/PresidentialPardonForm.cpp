/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:55:43 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/19 19:10:12 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): _name("Default"), _signGrade(25), _executeGrade(5), _isSigned(false)
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name): _name(name), _signGrade(25), _executeGrade(5), _isSigned(false)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{ }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
{
	*this = src;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	if (this != &src)
		return (*this);
	return *this;
}

std::ostream&	operator<<(std::ostream& out, const PresidentialPardonForm& src)
{
	(void)out;
	(void)src;
	return (out);
}
