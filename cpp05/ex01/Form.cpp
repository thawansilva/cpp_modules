/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:58:22 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/17 17:43:12 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default Form"), _signGrade(150), _executeGrade(150),
	_isSigned(false)
{}

Form::Form(const std::string &name, unsigned int signGrade, unsigned int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade), _isSigned(false)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{}

Form::Form(const Form &src): _name(src.getName() + "_copy"),
	_signGrade(src.getSignGrade()), _executeGrade(src.getExecuteGrade()),
	_isSigned(false)
{
	*this = src;
}

Form&	Form::operator=(const Form& src)
{
	if (this != &src)
		this->_isSigned = src.isSigned();
	return (*this);
}

bool			Form::isSigned(void) const
{
	return (_isSigned);
}

void			Form::beSigned(const Bureaucrat &signer)
{
	if (signer.getGrade() > getSignGrade())
		throw Form::GradeTooLowException();
	else if (!isSigned())
	{
		_isSigned = true;
		std::cout << getName() << " Form was signed by ";
		std::cout << signer.getName() << std::endl;
	}
	else
		std::cout << getName() << "Form is already signed" << std::endl;
}

std::string		Form::getName(void) const
{
	return (_name);
}

unsigned int	Form::getSignGrade(void) const
{
	return (_signGrade);
}

unsigned int	Form::getExecuteGrade(void) const
{
	return (_executeGrade);
}

std::ostream&	operator<<(std::ostream& out, const Form& src)
{
	out << src.getName() << " is ";
	out << (src.isSigned() ? "signed" : "not signed");
	out << "\nSign grade: " << src.getSignGrade();
	out << "\nExecute grade: " << src.getExecuteGrade() << std::endl;
	return (out);
}
