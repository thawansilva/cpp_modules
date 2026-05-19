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

RobotomyRequestForm::RobotomyRequestForm(): _name("Default"), _signGrade(72), _executeGrade(45), _isSigned(false)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name): _name(name), _signGrade(72), _executeGrade(45), _isSigned(false)
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

std::ostream&	operator<<(std::ostream& out, const RobotomyRequestForm& src)
{
	(void)out;
	(void)src;
	return (out);
}
