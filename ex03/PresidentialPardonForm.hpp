/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:55:57 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/21 19:54:43 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	const std::string	_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &name);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& src);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

	void		execute(Bureaucrat const &executor) const;
	std::string	getTarget() const;
};

std::ostream&	operator<<(std::ostream& out, const PresidentialPardonForm& src);
