/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:58:09 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/17 18:29:33 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string &name);
	Bureaucrat(const std::string &name, unsigned int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);

	// Member function
	void			incrementGrade(void);
	void			decrementGrade(void);
	void			signForm(AForm &form);
	virtual void	executeForm(AForm const &form) const;

	// Getters & Setters
	std::string		getName(void) const;
	unsigned int	getGrade(void) const;
	void			setGrade(unsigned int value);

	// Exception
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char	*what() const throw()
			{
				return ("The grade is too high");
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char	*what() const throw()
			{
				return ("The grade is too low");
			}
	};

private:
	const std::string	_name;
	unsigned int		_grade;
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& src);
