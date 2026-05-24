/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:59:56 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/22 15:51:39 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void separator(std::string title)
{
	std::cout << "\n========== " << title << " ==========\n";
}

int main()
{
	separator("SUBJECT TEST");
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	separator("INVENTORY LIMIT TEST");
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure")); // should NOT be added (full)

	separator("INVALID USE TEST");
	me->use(-1, *bob);
	me->use(10, *bob);

	separator("UNEQUIP TEST");
	for (int i = 0; i < 4; i++)
	{
		me->unequip(i);
	}

	separator("RE-EQUIP AFTER UNEQUIP");
	for (int i = 0; i < 4; i++)
	{
		tmp = src->createMateria("ice");
		me->equip(tmp);
	}

	separator("DEEP COPY TEST (COPY CONSTRUCTOR)");
	Character original("original");
	original.equip(src->createMateria("ice"));
	original.equip(src->createMateria("cure"));

	Character copy(original);

	original.use(0, *bob);
	copy.use(0, *bob);

	separator("MODIFY ORIGINAL AFTER COPY");
	original.unequip(0);
	original.use(0, *bob); // might do nothing
	copy.use(0, *bob);     // MUST still work if deep copy

	separator("ASSIGNMENT OPERATOR TEST");
	Character assign("assign");
	assign = original;

	assign.use(0, *bob);

	separator("MATERIA SOURCE FULL TEST");
	MateriaSource ms;
	ms.learnMateria(new Ice());
	ms.learnMateria(new Cure());
	ms.learnMateria(new Ice());
	ms.learnMateria(new Cure());
	ms.learnMateria(new Ice()); // should NOT be learned

	separator("UNKNOWN MATERIA TEST");
	AMateria* unknown = src->createMateria("fire");
	if (!unknown)
		std::cout << "Unknown materia not created (OK)" << std::endl;

	separator("CLEANUP");

	delete bob;
	delete me;
	delete src;

	return 0;
}
