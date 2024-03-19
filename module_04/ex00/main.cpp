#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main( ) {
	std::cout << "Subject tests" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl << "Test Copy Constuctor" << std::endl;

	Animal k(*j);
	std::cout << k.getType() << " " << std::endl;
	k.makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\nCreating WrongAnimals... why? Don't know..." << std::endl;
	WrongAnimal a;
	std::cout << a.getType() << " " << std::endl;
	a.makeSound();
	WrongCat c;
	std::cout << c.getType() << " " << std::endl;
	c.makeSound();

	return 0;
}
