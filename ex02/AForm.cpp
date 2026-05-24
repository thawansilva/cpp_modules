/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:58:22 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/24 15:03:12 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default AForm"), _signGrade(150), _executeGrade(150),
	_isSigned(false)
{}

AForm::AForm(const std::string &name, unsigned int signGrade, unsigned int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false)
{
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{}

AForm::AForm(const AForm &src): _name(src.getName() + "_copy"),
	_signGrade(src.getSignGrade()), _executeGrade(src.getExecuteGrade()),
	_isSigned(false)
{
	*this = src;
}

AForm&	AForm::operator=(const AForm& src)
{
	if (this != &src)
		this->_isSigned = src.isSigned();
	return (*this);
}

bool			AForm::isSigned(void) const
{
	return (_isSigned);
}

void			AForm::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > getSignGrade())
		throw AForm::GradeTooLowException();
	else if (!isSigned())
	{
		_isSigned = true;
		std::cout << getName() << " AForm successfully signed by ";
		std::cout << signer.getName() << std::endl;
	}
	else
		std::cout << getName() << "AForm is already signed" << std::endl;
}

std::string		AForm::getName(void) const
{
	return (_name);
}

unsigned int	AForm::getSignGrade(void) const
{
	return (_signGrade);
}

unsigned int	AForm::getExecuteGrade(void) const
{
	return (_executeGrade);
}

std::ostream&	operator<<(std::ostream& out, const AForm& src)
{
	out << src.getName() << " is ";
	out << (src.isSigned() ? "signed" : "not signed");
	out << "\nSign grade: " << src.getSignGrade();
	out << "\nExecute grade: " << src.getExecuteGrade() << std::endl;
	return (out);
}
