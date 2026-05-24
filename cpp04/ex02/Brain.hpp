#include "iostream"
#define IDEAS_SIZE 100

#pragma once

class Brain
{
public:
	Brain();
	virtual ~Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);

	//Member Functions

	// Getters & Setters
	const std::string*		getIdeas(void) const;
	std::string		getIdea(const unsigned int idx) const;
	void					setIdea(const unsigned int idx,
			const std::string& idea);

private:
	std::string	ideas[IDEAS_SIZE];
};
