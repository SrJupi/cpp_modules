#include <iostream>

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->name = "DefaultDiamond";
	this->ClapTrap::name = name + "_clap_name";
	this->hitPoints = FragTrap::baseHP;
	this->energyPoints = ScavTrap::baseEP;
	this->attackDamage = FragTrap::baseAttack;
	std::cout << "DiamondTrap Default Constructor - " << name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &newName)
{
	this->name = newName;
	this->ClapTrap::name = name + "_clap_name";
	this->hitPoints = FragTrap::baseHP;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::baseAttack;
	std::cout << "DiamondTrap String Constructor - " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref) : ScavTrap(ref), FragTrap(ref)
{
	this->name = ref.name;
	ClapTrap::name = ref.name + "_clap_name";
	std::cout << "DiamondTrap Copy Constructor - " << this->name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor - " << name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &ref)
{
	if (this != &ref)
	{
		this->name = ref.name;
		ClapTrap::name = ref.ClapTrap::name;
		this->hitPoints = ref.hitPoints;
		this->energyPoints = ref.energyPoints;
		this->attackDamage = ref.attackDamage;
	}
	std::cout << "DiamondTrap Copy Assignment Constructor - " << name << std::endl;
	return *this;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << this->name << "!\n";
	std::cout << "My claptrap name is " << this->ClapTrap::name << "!\n";
}

void DiamondTrap::attack(const std::string &target)
{
	this->ScavTrap::attack(target);
}
