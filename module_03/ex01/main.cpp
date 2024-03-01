#include <iostream>
#include "ScavTrap.hpp"

int main() {
	// Create a ScavTrap object with default constructor
	ScavTrap scavtrap1;
	// Create a ScavTrap object with string constructor
	ScavTrap scavtrap2("ScavTrap2");

	// Test attack, takeDamage, and beRepaired functionalities
	scavtrap1.attack("Target1");
	scavtrap2.attack("Target2");

	scavtrap1.takeDamage(5);
	scavtrap2.takeDamage(3);

	scavtrap1.beRepaired(2);
	scavtrap2.beRepaired(4);

	// Test copy constructor and copy assignment operator
	ScavTrap scavtrap3 = scavtrap1; // This invokes the copy constructor
	scavtrap3.printInfo();
	ScavTrap scavtrap4 = scavtrap2; // This also invokes the copy constructor

	scavtrap3.attack("Target3");
	scavtrap4.attack("Target4");

	// Test copy assignment operator
	scavtrap3 = scavtrap1; // This should invoke the copy assignment operator
	scavtrap4 = scavtrap2; // This should also invoke the copy assignment operator

	std::cout << "\nThe Life and Death of scavtrap4\n\n";
	scavtrap4.printInfo();
	std::cout << std::endl;
	scavtrap4.guardGate();
	std::cout << std::endl;
	scavtrap4.takeDamage(100);
	std::cout << std::endl;
	scavtrap4.takeDamage(10);
	std::cout << std::endl;
	scavtrap4.takeDamage(10);
	std::cout << std::endl;
	scavtrap4.beRepaired(20);
	std::cout << std::endl;
	scavtrap4.attack("Enemy");
	std::cout << std::endl;
	scavtrap4.guardGate();
	std::cout << std::endl;
	scavtrap4.printInfo();

	return 0;
}
