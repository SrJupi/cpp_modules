#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *horde;
    int i;
    
    horde = new Zombie[N];
    while (N--)
        horde[N].setName(name + " " + std::to_string(N));
    return (horde);
}