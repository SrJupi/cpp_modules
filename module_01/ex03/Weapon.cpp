#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(void) {};

Weapon::Weapon(std::string _type): type(_type) {};

Weapon::~Weapon(void)
{
    std::cout << "Destroy " << this->type << "!\n";
};
    
std::string Weapon::getType (void)
{
    return this->type;
};

void Weapon::setType (std::string type)
{
    this->type = type;
};
