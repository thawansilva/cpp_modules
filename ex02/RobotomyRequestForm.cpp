/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:55:26 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/19 19:06:55 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): _name("Default"), _signGrade(72),
	_executeGrade(45), _isSigned(false)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name): _name(name),
	_signGrade(72), _executeGrade(45), _isSigned(false)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
{
	*this = src;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	if (this != &src)
		return (*this);
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->isSigned() && executor.getExecuteGrade() < this->getExecuteGrade())
	{
		std::cout << "Make some drilling noise..." << std::endl;
		std::cout << this->getName() << " has been robotomized successfully 50% of the time" << std::endl;
		return ;
	}
	throw AForm::ExecuteException("Robotomy failed.");
}

std::ostream&	operator<<(std::ostream& out, const RobotomyRequestForm& src)
{
	out << src.getName() << " Robotomy  is ";
	out << (src.isSigned() ? "signed" : "not signed");
	out << "\nSign grade: " << src.getSignGrade();
	out << "\nExecute grade: " << src.getExecuteGrade() << std::endl;
	return (out);
}
