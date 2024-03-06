#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string type;

public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& ref);
	virtual ~AMateria();

	AMateria&	operator=(const AMateria& ref);

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) = 0;
};

#endif
