/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:00:02 by thaperei          #+#    #+#             */
/*   Updated: 2026/02/28 11:00:03 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP 

#include "Contact.hpp"
#include <ostream>
#include <cstdlib>
#define PHONEBOOK_SIZE 8

class Phonebook
{
	private:
		Contact contacts[PHONEBOOK_SIZE];
		int count;
		int oldestIndex;

	public:
		Phonebook(void);

		bool isFull(void);
		bool isEmpty(void);
		void showContacts(void);
		void displayContact(int index);
		void addContact(Contact &newContact);
};
#endif
