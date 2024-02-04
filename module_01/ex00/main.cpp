#include <iostream>
#include <string>
#include "Zombie.hpp"

int main()
{
    Zombie a("Constructor Zombie");
    a.announce();
    
    
    Zombie *z = newZombie("New Zombie");
    z->setName("Change Name New Zombie");
    z->announce();
    delete z;
    randomChump("Random Chump");
    return 0;
}
