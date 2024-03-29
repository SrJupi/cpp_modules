#include <iostream>
#include <iomanip>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("DefaultScav")
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap Default Constructor - " << name << std::endl;
}

ScavTrap::ScavTrap(const std::string &newName) : ClapTrap(newName)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap String Constructor - " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(ref)
{
	std::cout << "ScavTrap Copy Constructor - " << name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor - " << name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &ref)
{
	ClapTrap::operator=(ref);
	std::cout << "ScavTrap Copy Assignment Constructor - " << name << std::endl;
	return *this;
}

void ScavTrap::guardGate(void)
{
	if (!hitPoints || !energyPoints)
	{
		std::cout << "Cannot guard the Gate... Am I dead? Am I without energy? Is it worth to live without energy?" << std::endl;
		return;
	}
	energyPoints--;
	std::cout << name << " hold the door\nhold the door\nhold door\nholdoor\nhodor\nhodor\nhodor" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	doRealAttack(target, "ScavTrap");
}
