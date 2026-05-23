/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:55:35 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/21 19:53:10 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	const std::string	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &name);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& src);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

	void		execute(Bureaucrat const &executor) const;
	std::string	getTarget() const;
};

std::ostream&	operator<<(std::ostream& out, const RobotomyRequestForm& src);
