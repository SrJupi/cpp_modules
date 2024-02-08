#include <string>
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void) {};

Zombie::Zombie(std::string name)
{
    this->name = name;
}
Zombie::~Zombie(void)
{
    std::cout << this->name + " is dead!\n";
}

void Zombie::announce(void)
{
    std::cout << this->name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name; 
}