/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:59:42 by thaperei          #+#    #+#             */
/*   Updated: 2026/02/28 10:59:44 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	count = 0;
	oldestIndex = 0;
}

bool Phonebook::isEmpty(void)
{
	return (count == 0);
}

bool Phonebook::isFull(void)
{
	return (count == PHONEBOOK_SIZE);
}

void Phonebook::addContact(Contact &newContact)
{
	if (isFull()) {
		contacts[oldestIndex] = newContact;
		if (oldestIndex == PHONEBOOK_SIZE - 1)
			oldestIndex = -1;
		oldestIndex++;
		return ;
	}
	contacts[count] = newContact;
	count++;
}

void Phonebook::displayContact(int index)
{
	if (index < 0 || index >= count) {
		std::cout << "Invalid index or inexistent contact" << std::endl;
		return ;
	}
	Contact contact = contacts[index];
	contact.showInfo();
}

void Phonebook::showContacts(void)
{
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "first Name";
	std::cout << "|" << std::setw(10) << "last Name";
	std::cout << "|" << std::setw(10) << "nickname" << "|" << std::endl;
	std::cout << "|" << std::setfill('-') << std::setw(11);
	std::cout << "|" << std::setfill('-') << std::setw(11);
	std::cout << "|" << std::setfill('-') << std::setw(11);
	std::cout << "|" << std::setw(11) << "|" << std::endl;
	std::cout << std::setfill(' ');

	int i = -1;
	while (++i < count)
	{
		Contact contact = contacts[i];
		std::cout << "|" << std::setw(10) << i << "|";
		contact.showRowInfo();
		std::cout << "|" << std::setfill('-') << std::setw(11);
		std::cout << "|" << std::setfill('-') << std::setw(11);
		std::cout << "|" << std::setfill('-') << std::setw(11);
		std::cout << "|" << std::setw(11) << "|" << std::endl;
		std::cout << std::setfill(' ');
	}
}
