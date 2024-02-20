#include "HumanB.hpp"
#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>


HumanA::HumanA(std::string name, Weapon& w) : HumanB(name)
{
    this->setWeapon(w);
    std::cout << "Creating human A - " << name << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << "My humanity A is dying!\n";
}
