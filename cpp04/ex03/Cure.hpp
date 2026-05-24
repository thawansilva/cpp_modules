/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:20:25 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/21 11:20:29 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	~Cure();
	Cure(const Cure& other);
	Cure& operator=(const Cure& other);

	//Member Functions
	AMateria*	clone() const;
	void		use(ICharacter&) const;
	// Getters & Setters
};
