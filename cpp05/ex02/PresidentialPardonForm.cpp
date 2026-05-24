/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:55:43 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/21 20:21:13 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm Default", 25, 5), _target("Default target")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src): AForm("PresidentialPardonForm Copy", 25, 5), _target(src.getTarget())
{
	*this = src;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	if (this != &src)
		return (*this);
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox";
	std::cout << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (_target);
}

std::ostream&	operator<<(std::ostream& out, const PresidentialPardonForm& src)
{
	out << src.getName() << " Presidetial Pardon  is ";
	out << (src.isSigned() ? "signed" : "not signed");
	out << "\nSign grade: " << src.getSignGrade();
	out << "\nExecute grade: " << src.getExecuteGrade() << std::endl;
	return (out);
}
