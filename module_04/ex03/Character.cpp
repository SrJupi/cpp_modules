#include <iostream>
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
			if (inventory[i])
				delete inventory[i];
			inventory[i] = ref.inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return name;
}

/**
 * @brief Equips a materia to the character's inventory.
 *
 * This method equips a materia to the character's inventory if the given materia
 * is not already equipped and if there is an available slot in the inventory.
 * If the given materia is null or is already equipped, this method does nothing.
 *
 * @param m A pointer to the materia to be equipped.
 *          If null, this method does nothing.
 *          The ownership of the materia is shared.
 *          Must not be already equipped.
 *
 * @note The method assumes that the character's inventory has a fixed size of 4 slots.
 *       If all inventory slots are filled when attempting to equip a new materia,
 *       the new materia will not be equipped.
 *       This method does not handle memory deallocation or ownership transfer.
 *       It simply adds a reference to the materia in the character's inventory
 *       and marks it as equipped.
 */
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
			m->setEquipped(true);
			std::cout << name << " equipped with " << m->getType() << std::endl;
			return ;
		}
	}
}
/**
 * @brief Unequips an item from the character's inventory slot.
 *
 * This method removes an item from the character's inventory slot at the given index.
 * If the slot is empty or the index is out of range, this method does nothing.
 * It's important to note that this method does not handle memory deallocation
 * or ownership transfer. It simply removes the reference to the item from the inventory.
 *
 * @param idx The index of the inventory slot to unequip.
 *            Must be in the range [0, 3].
 */
void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && inventory[idx])
	{
		inventory[idx]->setEquipped(false);
		inventory[idx] = NULL;
	}
}

/**
 * @brief Uses the materia in the specified inventory slot on a target character.
 *
 * This method allows the character to use the materia located in the specified
 * inventory slot on a target character. If the specified index is out of range
 * or the inventory slot is empty, this method does nothing.
 *
 * @param idx The index of the inventory slot containing the materia to use.
 *            Must be in the range [0, 3].
 *            If out of range or the slot is empty, this method does nothing.
 *
 * @param target A reference to the target character on which the materia will be used.
 *               The actual effect of using the materia depends on the type of materia
 *               and the specific implementation of the use method for that type.
 *               Must be a valid reference to a character.
 *               The ownership of the target character is not transferred.
 */
void Character::use(int idx, ICharacter &target)
{
	if (is_matryoshka)
		return ;
	if (idx < 0 || idx >= 4 || inventory[idx] == NULL)
		return ;
	inventory[idx]->use(target);
}
