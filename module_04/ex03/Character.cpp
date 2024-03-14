#include <iostream>

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : name("Default Character")
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character::Character(std::string nName) : name(nName)
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
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (inventory[idx])
	{
		delete inventory[idx]; // do not delete
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || inventory[idx] == NULL)
		return ;
	inventory[idx]->use(target);
}
