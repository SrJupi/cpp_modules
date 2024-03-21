#include <iostream>
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int subjectTest(void)
{
	std::cout << "Subject example:" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	std::cout << std::endl;
	return 0;
}

int	unequipTest(void)
{
	std::cout << "Unequip example:" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("Lukita");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp); // can unequipe because AMateria is still referenced by tmp
	me->equip(src->createMateria("cure")); //unequip this will always cause leaks because there are no reference to it
	Character other("Other");
	me->use(0, other);
	me->use(1, other);
	me->unequip(0);
	//me->unequip(1); // uncomment for leaks!
	delete tmp; //comment for leaks!
	delete me;
	delete src;
	return 0;
}

void	copyTest()
{
	std::cout << "\nCopy example:" << std::endl;
	Character a("Original");
	Character b("Copy");

	a.equip(new Ice());
	a.equip(new Ice());
	a.equip(new Ice());
	a.equip(new Ice());
	for (int i = 0; i < 4; i++)
	{
		a.use(i, b);
	}
	b.equip(new Cure());
	b.equip(new Cure());
	b.equip(new Cure());
	b.equip(new Cure());
	for (int i = 0; i < 4; i++)
	{
		b.use(i, a);
	}
	b = a;
	for (int i = 0; i < 4; i++)
	{
		b.use(i, a);
	}
}

int main()
{
	subjectTest();
	unequipTest();
	copyTest();
	return 0;
}
