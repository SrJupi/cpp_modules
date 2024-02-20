#include <iostream>
#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal Default Constructor" << std::endl;
}


Animal::Animal(const Animal& ref) : type(ref.type)
{
	std::cout << "Animal Copy Constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor" << std::endl;
}

Animal&	Animal::operator=(const Animal& ref)
{
	if (this != &ref)
		this->type = ref.type;
	std::cout << "Animal Copy Assignment Constructor" << std::endl;
	return (*this);
}

void    Animal::makeSound() const
{
	std::cout << "Animal noises..." << std::endl;
}

std::string Animal::getType() const
{
	return type;
}
