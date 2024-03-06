#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type) {
	this->type = type;
}


AMateria::AMateria(const AMateria& ref) {
	this->type = ref.type;
}

AMateria::~AMateria() {}

AMateria&	AMateria::operator=(const AMateria& ref)
{
	(void)ref;
	return (*this);
}

std::string const &	AMateria::getType() const {
	return this->type;
}
