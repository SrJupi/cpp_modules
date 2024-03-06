#ifndef ICE_HPP
# define ICE_HPP

#include <string>
#include <AMateria.hpp>

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& ref);
	~Ice();

	Ice&	operator=(const Ice& ref);
	void        makeSound() const;

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
