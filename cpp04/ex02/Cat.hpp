/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:37:47 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/17 20:45:53 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

#pragma once

class Cat : public AbstractAnimal
{
public:
	Cat();
	~Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	// Member functions
	void	makeSound(void) const;
	// Getters & Setters
	Brain&	getBrain(void) const;
private:
	Brain* _brain;
};
