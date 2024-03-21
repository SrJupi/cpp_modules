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
	j->makeSound(); //will output the dog sound!
	meta->makeSound();

	std::cout << "\nCreating WrongAnimals... why? Don't know..." << std::endl;
	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* wrongi = new WrongCat();
	std::cout << wrongmeta->getType() << " " << std::endl;
	std::cout << wrongi->getType() << " " << std::endl;
	wrongi->makeSound(); //will output the wronganimal sound!
	wrongmeta->makeSound();

	delete wrongmeta;
	delete wrongi;
	return 0;
}
