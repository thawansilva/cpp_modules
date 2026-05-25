/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:58:16 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/25 16:42:21 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	const std::string	_name;
	const unsigned int	_signGrade;
	const unsigned int	_executeGrade;
	bool				_isSigned;

public:
	AForm();
	AForm(const std::string &name, unsigned int signGrade, unsigned int executeGrade);
	virtual ~AForm();
	AForm(const AForm& src);
	AForm& operator=(const AForm& src);

	//Member Functions
	bool				isSigned(void) const;
	void				beSigned(const Bureaucrat &b);
	virtual void		execute(Bureaucrat const &executor) const = 0;

	// Getters & Setters
	std::string			getName(void) const;
	unsigned int		getSignGrade(void) const;
	unsigned int		getExecuteGrade(void) const;

	// Exception
	class NotSignedException : public std::exception
	{
		public:
			virtual const char	*what() const throw()
			{
				return ("The form is not signed.");
			}
	};

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char	*what() const throw()
			{
				return ("Grade is too high for the form");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char	*what() const throw()
			{
				return ("Grade is too low for the form");
			}
	};
};

std::ostream&	operator<<(std::ostream& out, const AForm& src);
