#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
	std::cout << "Materia Source Default Constructor" << std::endl;
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
	std::cout << "Materia Source Copy Constructor" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	std::cout << "Materia Source Destructor" << std::endl;
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

/**
 * @brief Learns a new type of materia.
 *
 * This method allows the materia source to learn a new type of materia.
 * If the materia source already knows the type of materia provided,
 * the method does nothing.
 * If there is an empty slot in the inventory, the materia is stored there.
 * Otherwise, the method does nothing.
 *
 * @param m A pointer to the materia to be learned.
 *          If nullptr, this method does nothing.
 *          The ownership of the materia is not transferred.
 *
 * @note The method assumes that the materia source's inventory has a fixed size of 4 slots.
 *       If all inventory slots are filled when attempting to learn a new materia type,
 *       the new materia type will not be learned.
 *       This method does not handle memory deallocation or ownership transfer.
 *       It simply adds a reference to the materia in the materia source's inventory.
 */
void MateriaSource::learnMateria(AMateria* m){
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == m)
			return ;
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			return ;
		}
	}
}

/**
 * @brief Creates a new instance of a materia of the specified type.
 *
 * This method creates a new instance of a materia of the specified type,
 * if the materia source has learned that type of materia.
 * If the specified type is not found in the inventory, null is returned.
 *
 * @param type A constant reference to a string specifying the type of materia to create.
 *             Must be a valid string representing a known type of materia.
 *
 * @return A pointer to the newly created materia instance, or null if the specified type
 *         is not found in the inventory or if the inventory slot is empty.
 *         The ownership of the created materia is transferred to the caller.
 */
AMateria* MateriaSource::createMateria(std::string const & type){

	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] && inventory[i]->getType() == type)
			return (inventory[i]->clone());
	}
	return 0;  
}
