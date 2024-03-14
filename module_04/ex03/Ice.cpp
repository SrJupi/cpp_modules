#include <iostream>
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice Default Constructor" << std::endl;
}


Ice::Ice(const Ice& ref) : AMateria("ice")
{
	(void)ref;
	std::cout << "Ice Copy Constructor" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor" << std::endl;
}

Ice&	Ice::operator=(const Ice& ref)
{
	(void)ref;
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
	std::cout << " * Freezed " << target.getName() << " * " <<std::endl;
}
