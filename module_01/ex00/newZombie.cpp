#include "Zombie.hpp"

Zombie *newZombie (std::string name)
{
    Zombie *z;
    z = new Zombie();
    z->setName(name);
    z->announce();
    return (z);
}