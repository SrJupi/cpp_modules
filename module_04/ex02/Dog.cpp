#include <iostream>
#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog Default Constructor" << std::endl;
}


Dog::Dog(const Dog& ref) : AAnimal(ref)
{
	this->brain = new Brain(*ref.brain);
	std::cout << "Dog Copy Constructor" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Destructor" << std::endl;
}

Dog&	Dog::operator=(const Dog& ref)
{
	if (this != &ref)
	{
		this->type = ref.type;
		this->brain = new Brain(*ref.brain);
	}
	std::cout << "Dog Copy Assignment Constructor" << std::endl;
	return (*this);
}

void    Dog::makeSound() const
{
	std::cout << "Dog noises..." << std::endl;
}

