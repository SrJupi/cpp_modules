#include <iostream>
#include <iomanip>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	name = "DefaultScav";
	hitPoints = ScavTrap::baseHP;
	energyPoints = ScavTrap::baseEP;
	attackDamage = ScavTrap::baseAttack;
	std::cout << "ScavTrap Default Constructor - " 
		<< name << std::endl;
}

ScavTrap::ScavTrap(const std::string &newName) : ClapTrap(newName)
{
	hitPoints = ScavTrap::baseHP;
	energyPoints = ScavTrap::baseEP;
	attackDamage = ScavTrap::baseAttack;
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
	if (this != &ref)
	{
		this->name = ref.name;
		this->hitPoints = ref.hitPoints;
		this->energyPoints = ref.energyPoints;
		this->attackDamage = ref.attackDamage;
	}
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
	std::cout << "\n\n"
			  << name << " hold the door\nhold the door\nhold door\nholdoor\nhodor\nhodor\nhodor" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	doRealAttack(target, "ScavTrap");
}
