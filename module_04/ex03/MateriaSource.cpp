#include <iostream>

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& ref)
{
	for (int i = 0; i < 4; i++)
	{
		if (ref.inventory[i])
			inventory[i] = ref.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& ref)
{
	if (this != &ref)
	{
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
				delete inventory[i];
			if (ref.inventory[i])
				inventory[i] = ref.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m){
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			break ;
		}
	}
}
AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i]->getType() == type)
			return (inventory[i].clone());
	}
	return 0;  
}
