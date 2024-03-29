#ifndef CAT_HPP
# define CAT_HPP

#include <string>
#include <AAnimal.hpp>
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain	*brain;
	
public:
	Cat();
	Cat(const Cat& ref);
	~Cat();

	Cat&	operator=(const Cat& ref);
	void        makeSound() const;
	void	printBrain() const;

};

#endif
