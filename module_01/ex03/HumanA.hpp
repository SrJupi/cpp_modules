#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "HumanB.hpp"
#include <string>

class HumanA: public HumanB
{
    public:
    HumanA(std::string name, Weapon& w);
    ~HumanA(void);
};

#endif