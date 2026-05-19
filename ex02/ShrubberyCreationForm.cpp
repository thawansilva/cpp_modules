/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:56:05 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/19 19:22:25 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): _name("Default"), _signGrade(145), _executeGrade(137), _isSigned(false)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name): _name(name), _signGrade(145), _executeGrade(137), _isSigned(false)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
{
	*this = src;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src)
		return (*this);
	return *this;
}

std::ostream&	operator<<(std::ostream& out, const ShrubberyCreationForm& src)
{
	(void)out;
	(void)src;
	return (out);
}
