#include <iostream>
#include <sstream>
#include <string>
#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *horde;
    std::stringstream out;
    
    horde = new Zombie[N];
    while (N--)
    {
        out << N;
        horde[N].setName(name + " " + out.str());
        out.str(std::string());
    }
    return (horde);
}