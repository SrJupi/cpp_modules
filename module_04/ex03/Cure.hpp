#ifndef CURE_HPP
# define CURE_HPP

#include <string>
#include <AMateria.hpp>

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& ref);
	~Cure();

	Cure&	operator=(const Cure& ref);
	void        makeSound() const;

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
