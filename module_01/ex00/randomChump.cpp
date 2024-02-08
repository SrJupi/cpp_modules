#include "Zombie.hpp"

void randomChump (std::string name)
{
    Zombie z(name);
    z.setName(name);
    z.announce();
}