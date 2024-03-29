#include <iostream>
#include <iomanip>

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("DefaultFrag")
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap Default Constructor - " << name << std::endl;
}

FragTrap::FragTrap(const std::string &newName) : ClapTrap(newName)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap String Constructor - " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref)
{
	std::cout << "FragTrap Copy Constructor - " << name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor - " << name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &ref)
{
	ClapTrap::operator=(ref);
	std::cout << "FragTrap Copy Assignment Constructor - " << name << std::endl;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	if (!hitPoints || !energyPoints)
	{
		std::cout << "Cannot high five the guys... Am I dead? Am I without energy? Is it worth to live without energy?" << std::endl;
		return;
	}
	energyPoints--;
	std::cout << name << " ヘ( ^o^)ノ＼(^_^ )" << std::endl;
}
