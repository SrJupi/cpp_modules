#include <iostream>
#include "ScavTrap.hpp"

int main()
{
	std::cout << ">> Create a ScavTrap object with default and string constructor" << std::endl << std::endl;
	ScavTrap scavtrap1;
	ScavTrap scavtrap2("ScavTrap2");

	std::cout << std::endl << ">> Test attack, takeDamage, and beRepaired functionalities" << std::endl << std::endl;
	scavtrap1.attack("Target1");
	scavtrap2.attack("Target2");

	scavtrap1.takeDamage(5);
	scavtrap2.takeDamage(3);

	scavtrap1.beRepaired(2);
	scavtrap2.beRepaired(4);

	std::cout << std::endl << ">> Test guard the gate functionality" << std::endl << std::endl;
	scavtrap1.guardGate();
	scavtrap2.guardGate();

	std::cout << std::endl << ">> Test copy constructor and copy assignment operator" << std::endl << std::endl;
	ScavTrap scavtrap3;
	scavtrap3 = scavtrap1;
	ScavTrap scavtrap4(scavtrap2);

	scavtrap3.attack("Target3");
	scavtrap4.attack("Target4");

	std::cout << "\n>> The Life and Death of scavtrap4\n\n";
	scavtrap4.printInfo();
	std::cout << std::endl;
	scavtrap4.takeDamage(100);
	std::cout << std::endl;
	scavtrap4.takeDamage(10);
	std::cout << std::endl;
	scavtrap4.beRepaired(20);
	std::cout << std::endl;
	scavtrap4.attack("Enemy");
	std::cout << std::endl;
	scavtrap4.printInfo();

	return 0;
}
