#include "Phonebook.hpp"

std::string getInput(std::string prompt)
{
	std::string input;
	bool valid = false;

	while (!valid)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "\nEOF detected, closing the program." << std::endl;
			exit(0);
		}
		else if(!input.empty())
			valid = true;
		else
		{
			std::cout << input << std::endl;
			std::cout << "Empty input is not allowed, try again." << std::endl;
		}
	}
	return input;
}

void addOperation(Phonebook &phonebook)
{
	std::cout << "FILL THE FOLLOWING INFORMATIONS:" << std::endl;

	Contact contact;
	contact.setFirstName(getInput("First name: "));
	contact.setLastName(getInput("Last name: "));
	contact.setNickname(getInput("Nickname: "));
	contact.setPhoneNumber(getInput("Phone number: "));
	contact.setDarkestSecret(getInput("Darkest secret: "));
	phonebook.addContact(contact);
	std::cout << "\nContact added sucessfully!" << std::endl;
}

void searchOperation(Phonebook phonebook)
{
	phonebook.showContacts();

	int index;
	std::cout << "Enter the index of the contact: ";
	std::cin >> index;
	while (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Not a number, try again: ";
		std::cin >> index;
	}
	std::cin.ignore(10000, '\n');
	phonebook.displayContact(index);
}

int main(void)
{
	Phonebook phonebook;
	std::string command;

	std::cout << "WELCOME TO PHONEBOOK!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT\n" << std::endl;
	do {
		std::cout << "Enter the command: ";
		command = getInput("");
		if (command == "ADD")
			addOperation(phonebook);
		else if (command == "SEARCH")
		{
			if (phonebook.isEmpty())
				std::cout << "Empty phonebook" << std::endl;
			else
				searchOperation(phonebook);
		}
	} while (command != "EXIT");
	std::cout << "Ending the program, bye bye!" << std::endl;
	return 0;
}
