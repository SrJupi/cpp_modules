#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
    private:
    std::string name;
    public:
    void announce (void);
    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);
    void setName (std::string name);
};

void randomChump (std::string name);
Zombie *newZombie (std::string name);

#endif