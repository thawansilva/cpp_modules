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

#define ZOO_SIZE 4

#pragma once

class AbstractAnimal
{
public:
	AbstractAnimal();
	AbstractAnimal(const AbstractAnimal& other);
	virtual ~AbstractAnimal();
	AbstractAnimal& operator=(const AbstractAnimal& other);

	// Member Functions
	virtual void	makeSound(void) const = 0;
	// Getters
	std::string	getType(void) const;

protected:
	std::string	type;
};
