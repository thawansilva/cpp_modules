/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:55:35 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/19 19:21:53 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class RobotomyRequestForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &name);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& src);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

	//Member Functions
	virtual			execute(Bureaucrat const &executor) const;
};

std::ostream&	operator<<(std::ostream& out, const RobotomyRequestForm& src);
