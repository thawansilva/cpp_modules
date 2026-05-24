/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:32:43 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/17 20:54:26 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once

class Animal
{
public:
	Animal();
	Animal(const std::string& type);
	virtual ~Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);

	// Member Functions
	virtual void	makeSound(void) const;
	// Getters
	std::string	getType(void) const;

protected:
	std::string	type;
};
