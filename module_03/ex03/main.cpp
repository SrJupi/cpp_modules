#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
	std::cout << ">> Create a DiamondTrap object with default and string constructor" << std::endl << std::endl;
	DiamondTrap diamondtrap1;
	DiamondTrap diamondtrap2("DiamondTrap2");

	std::cout << std::endl << ">> Test attack, takeDamage, and beRepaired functionalities" << std::endl << std::endl;
	diamondtrap1.attack("Target1");
	diamondtrap2.attack("Target2");

	diamondtrap1.takeDamage(5);
	diamondtrap2.takeDamage(3);

	diamondtrap1.beRepaired(2);
	diamondtrap2.beRepaired(4);

	std::cout << std::endl << ">> Test guard the gate functionality" << std::endl << std::endl;
	diamondtrap1.guardGate();
	diamondtrap2.guardGate();

	std::cout << std::endl << ">> Test high five functionality" << std::endl << std::endl;
	diamondtrap1.highFivesGuys();
	diamondtrap2.highFivesGuys();

	std::cout << std::endl << ">> Test who am I functionality" << std::endl << std::endl;
	diamondtrap1.whoAmI();
	diamondtrap2.whoAmI();

	std::cout << std::endl << ">> Test copy constructor and copy assignment operator" << std::endl << std::endl;
	DiamondTrap diamondtrap3;
	diamondtrap3 = diamondtrap1;
	DiamondTrap diamondtrap4(diamondtrap2);

	diamondtrap3.attack("Target3");
	diamondtrap4.attack("Target4");

	std::cout << "\n>> The Life and Death of diamondtrap4\n\n";
	diamondtrap4.printInfo();
	std::cout << std::endl;
	diamondtrap4.takeDamage(100);
	std::cout << std::endl;
	diamondtrap4.takeDamage(10);
	std::cout << std::endl;
	diamondtrap4.beRepaired(20);
	std::cout << std::endl;
	diamondtrap4.attack("Enemy");
	std::cout << std::endl;
	diamondtrap4.printInfo();
	std::cout << std::endl;
	return 0;
}
