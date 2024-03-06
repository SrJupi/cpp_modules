#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("DefaultClap"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap Default Constructor - " << name << std::endl;
}

ClapTrap::ClapTrap(const std::string &newName) : name(newName), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap String Constructor - " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ref) : name(ref.name + "_copyConstructed"), hitPoints(ref.hitPoints), energyPoints(ref.energyPoints), attackDamage(ref.attackDamage)
{
	std::cout << "ClapTrap Copy Constructor - " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor - " << name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &ref)
{
	if (this != &ref)
	{
		this->name = ref.name + "_assignmentCopy";
		this->hitPoints = ref.hitPoints;
		this->energyPoints = ref.energyPoints;
		this->attackDamage = ref.attackDamage;
	}
	std::cout << "ClapTrap Copy Assignment Constructor - " << name << std::endl;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	doRealAttack(target, "ClapTrap");
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (!hitPoints)
	{
		std::cout << "Stop! Stop! He's Already Dead!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " was hit... It loses " << amount << " of hit points!" << std::endl;
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (!hitPoints || !energyPoints)
	{
		std::cout << "Cannot be repaired... Am I dead? Am I without energy? Is it worth to live without energy?" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " fells replenished! It got " << amount << " of hit points!" << std::endl;
	hitPoints += amount;
	energyPoints--;
}

void ClapTrap::printInfo(void)
{
	std::cout << "Hello!\nI am " << name << "." << std::endl;
	std::cout << "My stats:\nHitpoints: " << hitPoints << "\nEnergypoints: " << energyPoints << "\nAttack damage: " << attackDamage << std::endl;
}

void ClapTrap::doRealAttack(const std::string &target, const std::string &trapName)
{
	if (!hitPoints || !energyPoints)
	{
		std::cout << "Cannot attack... Am I dead? Am I without energy? Is it worth to live without energy?" << std::endl;
		return;
	}
	energyPoints--;
	std::cout << trapName << " " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}
