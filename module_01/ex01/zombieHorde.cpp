#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *horde;
    
    horde = new Zombie[N];
    while (N--)
        horde[N].setName(name);
    return (horde);
}