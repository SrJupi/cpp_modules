#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : equipped(false)
{
}

AMateria::AMateria(std::string const &type) : equipped(false)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &ref)
{
	this->type = ref.type;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(const AMateria &ref)
{
	(void)ref;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::setEquipped()
{
	equipped = true;
}

bool AMateria::getEquipped()
{
	return equipped;
}
