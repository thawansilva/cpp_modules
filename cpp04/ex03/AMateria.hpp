/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 11:19:58 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/22 13:27:49 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include <string>

class ICharacter;

class AMateria
{
public:
	AMateria();
	virtual ~AMateria ();
	AMateria(std::string const& type);
	AMateria(AMateria const& other);
	AMateria&	operator=(const AMateria& other);

	// Member Functions
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target) const;

	// Getters & Setters
	std::string const&	getType(void) const;
	void				setType(const std::string& type);

protected:
	std::string		type;
};
