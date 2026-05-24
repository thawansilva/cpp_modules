/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:55:26 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/23 18:12:04 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("Default Target")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): AForm("RobotomyRequestForm Copy", 72, 45), _target(src.getTarget())
{
	*this = src;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	if (this != &src)
		return (*this);
	return *this;
}

static int i = 0;

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	if (i++ % 2)
	{
		std::cout << "BRRRRRRRRRRRRRRR... "<< getTarget() << " has been robotomized" << std::endl;
	}
	else
		std::cout << "Robotomy failed" << std::endl;
	return ;
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (_target);
}

std::ostream&	operator<<(std::ostream& out, const RobotomyRequestForm& src)
{
	out << src.getName() << " Robotomy  is ";
	out << (src.isSigned() ? "signed" : "not signed");
	out << "\nSign grade: " << src.getSignGrade();
	out << "\nExecute grade: " << src.getExecuteGrade() << std::endl;
	return (out);
}
