#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap();
	ScavTrap(const std::string& newName);
	ScavTrap(const ScavTrap& ref);
	~ScavTrap();

	ScavTrap& operator=(const ScavTrap& ref);

	void        attack(const std::string &target);
	void guardGate(void);
};

#endif
