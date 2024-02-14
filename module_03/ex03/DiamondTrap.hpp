#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string name;

public:
    DiamondTrap();
    DiamondTrap(const std::string& newName);
    DiamondTrap(const DiamondTrap& ref);
    ~DiamondTrap();

    DiamondTrap& operator=(const DiamondTrap& ref);

    void        attack(const std::string &target);
    void whoAmI(void);
    void        printInfo(void);

};

#endif
