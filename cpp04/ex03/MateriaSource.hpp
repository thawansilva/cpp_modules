/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:19:10 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/21 15:34:28 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#define AMOUNT_ELEMENTS 4

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource&	operator=(const MateriaSource& other);

	// Enheritaged Functions
	void			learnMateria(AMateria*);
	AMateria*		createMateria(const std::string& type);

private:
	AMateria*		_templates[AMOUNT_ELEMENTS];
};
