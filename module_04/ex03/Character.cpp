#include <iostream>

#include "Character.hpp"

Character::Character() : name("Default Character")
{
    for (int i = 0; i < 4; i++)
    {
        inventory[i] = NULL;
    }
}

Character::Character(std::string nName) : name(nName)
{
    for (int i = 0; i < 4; i++)
    {
        inventory[i] = NULL;
    }
}

Character::Character(const Character& ref)
{
    *this=ref;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        delete inventory[i];
    }
}

Character&	Character::operator=(const Character& ref)
{
    *this=ref;
    return (*this);
}

std::string const &Character::getName() const
{
    return name;
}

virtual void Character::equip(AMateria *m)
{
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
        delete inventory[idx];
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4 || inventory[idx] == NULL)
        return ;
    inventory[idx]->use(target);
}
