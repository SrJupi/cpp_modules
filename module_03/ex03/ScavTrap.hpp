#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
protected:
	const static int baseHP = 100;
	const static int baseEP = 50;
	const static int baseAttack = 20;
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
