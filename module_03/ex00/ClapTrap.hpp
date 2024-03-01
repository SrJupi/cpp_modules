#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
private:
	std::string name;
	int         hitPoints;
	int         energyPoints;
	int         attackDamage;

public:
	ClapTrap();
	ClapTrap(const std::string& newName);
	ClapTrap(const ClapTrap& ref);
	~ClapTrap();

	ClapTrap&	operator=(const ClapTrap& ref);

	void        attack(const std::string &target);
	void        takeDamage(unsigned int amount);
	void        beRepaired(unsigned int amount);
	void        printInfo(void);
};

#endif
