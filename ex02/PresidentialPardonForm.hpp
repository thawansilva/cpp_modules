/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:55:57 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/19 19:21:24 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class PresidentialPardonForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &name);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& src);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

	virtual			execute(Bureaucrat const &executor) const;
};

std::ostream&	operator<<(std::ostream& out, const PresidentialPardonForm& src);
