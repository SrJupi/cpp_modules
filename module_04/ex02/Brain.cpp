#include <iostream>
#include <cstdlib>

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor" << std::endl;
}

Brain::Brain(const Brain& ref)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = ref.ideas[i];
	std::cout << "Brain Copy Constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor" << std::endl;
}

Brain&	Brain::operator=(const Brain& ref)
{
    if (this != &ref)
    {    
        for (int i = 0; i < 100; i++)
            this->ideas[i] = ref.ideas[i];
    }
	std::cout << "Brain Copy Assignment Constructor" << std::endl;
    return (*this);
}
