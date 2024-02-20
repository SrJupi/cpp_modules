#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "AAnimal Default Constructor" << std::endl;
}


AAnimal::AAnimal(const AAnimal& ref) : type(ref.type)
{
	std::cout << "AAnimal Copy Constructor" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& ref)
{
	if (this != &ref)
		this->type = ref.type;
	std::cout << "AAnimal Copy Assignment Constructor" << std::endl;
	return (*this);
}

std::string AAnimal::getType() const
{
	return type;
}
