/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:56:05 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/21 20:24:51 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShruberyCreationDefault", 145, 137), _target("Default target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src): AForm("ShruberyCreationForm", 145, 137), _target(src.getTarget())
{
	*this = src;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src)
		return (*this);
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();

	std::ofstream	outfile(getTarget().append("_shrubbery").c_str());
	if (outfile.is_open())
	{
		for (int i = 0; i < 5; i++)
		{
			outfile <<
				"         v" << std::endl <<
				"        >X<" << std::endl <<
				"         A" << std::endl <<
				"        d$b" << std::endl <<
				"      .d\\$$b." << std::endl <<
				"    .d$i$$\\$$b." << std::endl <<
				"       d$$@b" << std::endl <<
				"      d\\$$$ib" << std::endl <<
				"    .d$$$\\$$$b" << std::endl <<
				"  .d$$@$$$$\\$$ib." << std::endl <<
				"      d$$i$$b" << std::endl <<
				"     d\\$$$$@$b" << std::endl <<
				"  .d$@$$\\$$$$$@b." << std::endl <<
				".d$$$$i$$$\\$$$$$$b." << std::endl <<
				"        ###" << std::endl <<
				"        ###" << std::endl <<
				"        ###" << std::endl <<
				std::endl;
		}
		outfile.close();
	}
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

std::ostream&	operator<<(std::ostream& out, const ShrubberyCreationForm& src)
{
	out << src.getName() << " Shrubbery  is ";
	out << (src.isSigned() ? "signed" : "not signed");
	out << "\nSign grade: " << src.getSignGrade();
	out << "\nExecute grade: " << src.getExecuteGrade() << std::endl;
	return (out);
}
