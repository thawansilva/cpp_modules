#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Brain was created" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain was destroyed" << std::endl;
}

Brain::Brain(const Brain& other)
{
	*this = other;
	std::cout << "Brain copy constructor was called" << std::endl;
}

Brain&	Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < IDEAS_SIZE; ++i)
			ideas[i] = other.ideas[i];
	}
	std::cout << "Brain assignment operator was called" << std::endl;
	return *this;
}

const std::string*	Brain::getIdeas(void) const
{
	return ideas;
}

std::string	Brain::getIdea(const unsigned int idx) const
{
	if (idx > IDEAS_SIZE)
		return "";
	return ideas[idx];
}
void				Brain::setIdea(const unsigned int idx,
		const std::string& idea)
{
	if (idx > IDEAS_SIZE)
	{
		std::cout << "Limit of ideas reached" << std::endl;
		return ;
	}
	ideas[idx] = idea;
}
