#include <iostream>
#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	int numAnimals = 2;
	AAnimal *animalArray[2];

	//AAnimal animal;

	for (int i = 0; i < numAnimals; i++)
	{ 
		if (i < numAnimals / 2)
			animalArray[i] = new Cat();
		else
			animalArray[i] = new Dog();
	}
	for (int i = 0; i < numAnimals; i++)
	{
		animalArray[i]->makeSound();
		delete animalArray[i];
	}
	return 0;
}
