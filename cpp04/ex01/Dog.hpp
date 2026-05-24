/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:37:30 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/17 20:45:40 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

#pragma once

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	// Member functions
	void	makeSound(void) const;
	// Getters & Setters
	Brain&	getBrain(void) const;
private:
	Brain* _brain;
};
