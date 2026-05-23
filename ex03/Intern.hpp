/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:26:50 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/23 17:49:13 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <iostream>

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);

	//Member Functions
	AForm	*makeForm(const std::string &name, const std::string &target);
};

std::ostream&	operator<<(std::ostream& out, const Intern& src);
