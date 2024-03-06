#include <iostream>
#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	this->type = "Ice";
	std::cout << "Ice Default Constructor" << std::endl;
}


Ice::Ice(const Ice& ref) : Ice()
{
	std::cout << "Ice Copy Constructor" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor" << std::endl;
}

Ice&	Ice::operator=(const Ice& ref)
{
	if (this != &ref)
		this->type = ref.type;
	std::cout << "Ice Copy Assignment Constructor" << std::endl;
	return (*this);
}

void    Ice::makeSound() const
{
	std::cout << "Ice noises..." << std::endl;
}

AMateria *Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter &target)
{
	std::cout << "Freeze!" << std::endl;
}
