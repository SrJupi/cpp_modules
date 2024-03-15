#include <iostream>
#include <sstream>

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : name("Default Character"), is_matryoshka(0)
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character::Character(std::string nName) : name(nName), is_matryoshka(0)
{
	std::cout << "Character constructor " << nName << std::endl;
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character::Character(const Character& ref) : name(ref.getName())
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = ref.inventory[i]->clone();
	}
}

Character::~Character()
{
	if (matryoshka != NULL)
		delete matryoshka;
	for (int i = 0; i < 4; i++)
	{
		delete inventory[i];
	}
	std::cout << "Character destructor " << getName() << std::endl;
}

Character&	Character::operator=(const Character& ref)
{
	if (this != &ref)
	{
		name = ref.getName();
		for (int i = 0; i < 4; i++)
		{
			inventory[i] = ref.inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	if (!m || m->getEquipped())
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == m)
		{
			std::cout << "Instance already equipped" << std::endl;
			return ;
		}
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			m->setEquipped();
			return ;
		}
	}
	std::cout << getName() << " inventory is full..." << std::endl;
	if (is_matryoshka)
	{
		if (matryoshka == NULL)
		{
			std::stringstream	out;
			out << is_matryoshka;
			matryoshka = new Character(name.substr(0, name.rfind(" ")) + " " + out.str());
			matryoshka->is_matryoshka = is_matryoshka + 1;
		}
		matryoshka->equip(m);
	}
}

void Character::unequip(int idx)
{
	if (is_matryoshka)
		return ;
	if (inventory[idx])
	{
		if (matryoshka == NULL)
		{
			std::stringstream	out;
			out << is_matryoshka;
			matryoshka = new Character(name.substr(0, name.rfind(" ")) + " " + out.str());
			matryoshka->is_matryoshka = is_matryoshka + 1;
		}
		matryoshka->equip(inventory[idx]);
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (is_matryoshka)
		return ;
	if (idx < 0 || idx >= 4 || inventory[idx] == NULL)
		return ;
	inventory[idx]->use(target);
}
