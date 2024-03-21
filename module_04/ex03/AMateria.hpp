#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
protected:
	std::string type;
	bool		equipped;

public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& ref);
	virtual ~AMateria();

	AMateria&	operator=(const AMateria& ref);

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) = 0;
	void setEquipped(bool status);
	bool getEquipped();
};

#endif
