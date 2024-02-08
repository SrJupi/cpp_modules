#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string _name): name(_name), weapon(NULL) 
{
    std::cout << "Creating human b - " << _name << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "My humanity B is dying!\n";
}

void HumanB::setWeapon(Weapon& w)
{
    this->weapon = &w;
}
    
void HumanB::attack(void)
{
    if (weapon)
        std::cout << this->name << " attacks with their " << (*weapon).getType() << std::endl;
}
