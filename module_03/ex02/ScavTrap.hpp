#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap();
    ScavTrap(const std::string& newName);
    ScavTrap(const ScavTrap& ref);
    ~ScavTrap();

    ScavTrap& operator=(const ScavTrap& ref);

    void guardGate(void);
};

#endif
