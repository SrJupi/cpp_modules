#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal& ref);
	virtual ~Animal();

	Animal&	operator=(const Animal& ref);

	virtual void        makeSound() const;
	std::string getType() const;
};

#endif
