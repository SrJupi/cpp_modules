#include <iostream>
#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat Default Constructor" << std::endl;
}


Cat::Cat(const Cat& ref) : AAnimal(ref)
{
	this->brain = new Brain(*ref.brain);
	std::cout << "Cat Copy Constructor" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat Destructor" << std::endl;
}

Cat&	Cat::operator=(const Cat& ref)
{
	if (this != &ref)
	{
		this->type = ref.type;
		this->brain = new Brain(*ref.brain);
	}
	std::cout << "Cat Copy Assignment Constructor" << std::endl;
	return (*this);
}

void    Cat::makeSound() const
{
	std::cout << "Cat noises..." << std::endl;
}
