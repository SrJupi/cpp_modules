#include <iostream>
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure Default Constructor" << std::endl;
}


Cure::Cure(const Cure& ref) : AMateria("cure")
{
	(void)ref;
	std::cout << "Cure Copy Constructor" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure Destructor" << std::endl;
}

Cure&	Cure::operator=(const Cure& ref)
{
	(void)ref;
	std::cout << "Cure Copy Assignment Constructor" << std::endl;
	return (*this);
}

void    Cure::makeSound() const
{
	std::cout << "Cure noises..." << std::endl;
}

AMateria *Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter &target)
{
	std::cout << " * Healed " << target.getName() << " * " << std::endl;
}
