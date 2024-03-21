#include <iostream>
#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void subjectTest(void)
{
	std::cout << "Subject tests:" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	std::cout << std::endl << std::endl;
}

void arrayTest(void)
{
	std::cout << "Array tests:" << std::endl;
	int numAnimals = 2;
	AAnimal *animalArray[2];

	for (int i = 0; i < numAnimals; i++)
	{ 
		if (i < numAnimals / 2)
			animalArray[i] = new Cat();
		else
			animalArray[i] = new Dog();
	}
	for (int i = 0; i < numAnimals; i++)
		delete animalArray[i];
	std::cout << std::endl << std::endl;
}

void copyTest(void)
{
	std::cout << "Copy tests:" << std::endl;
	Cat cat;
	Cat copy = cat;

	std::cout << "Cat brain: ";
	cat.printBrain();
	std::cout << "Copy brain: ";
	copy.printBrain();
}

int main() {
	subjectTest();
	arrayTest();
	copyTest();
	return 0;
}
