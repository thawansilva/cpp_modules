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
#include <fstream.h>

ShrubberyCreationForm::ShrubberyCreationForm(): Form("Default", 145, 137, false)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name): Form(name, 145, 137, false)
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

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->isSigned() && executor.getExecuteGrade() < this->getExecuteGrade())
	{
		std::fstream	outfile(this->getName().append("_shrubbery").c_str());
		if (file.is_open())
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
		return ;
	}
	throw Form::ExecuteException(executor.getName() + " can't execute it");
}

std::ostream&	operator<<(std::ostream& out, const ShrubberyCreationForm& src)
{
	out << src.getName() << " Shrubbery  is ";
	out << (src.isSigned() ? "signed" : "not signed");
	out << "\nSign grade: " << src.getSignGrade();
	out << "\nExecute grade: " << src.getExecuteGrade() << std::endl;
	return (out);
}
