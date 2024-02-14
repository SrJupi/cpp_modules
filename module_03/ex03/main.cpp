#include <iostream>
#include "DiamondTrap.hpp"

int main() {
    // Create a DiamondTrap object with default constructor
    DiamondTrap diamondtrap1;

    // Create a DiamondTrap object with string constructor
    DiamondTrap diamondtrap2("DiamondTrap2");
    // Test attack, takeDamage, and beRepaired functionalities
    diamondtrap2.printInfo();
    diamondtrap1.attack("Target1");
    diamondtrap2.attack("Target2");

    diamondtrap1.takeDamage(5);
    diamondtrap2.takeDamage(3);

    diamondtrap1.beRepaired(2);
    diamondtrap2.beRepaired(4);

    // Test copy constructor and copy assignment operator
    DiamondTrap diamondtrap3 = diamondtrap1; // This invokes the copy constructor
    diamondtrap3.printInfo();
    DiamondTrap diamondtrap4 = diamondtrap2; // This also invokes the copy constructor

    diamondtrap3.attack("Target3");
    diamondtrap4.attack("Target4");

    // Test copy assignment operator
    diamondtrap3 = diamondtrap1; // This should invoke the copy assignment operator
    diamondtrap4 = diamondtrap2; // This should also invoke the copy assignment operator

    std::cout << "\nThe Life and Death of diamondtrap4\n\n";
    diamondtrap4.printInfo();
    std::cout << std::endl;
    diamondtrap4.highFivesGuys();
    std::cout << std::endl;
    diamondtrap4.takeDamage(100);
    std::cout << std::endl;
    diamondtrap4.takeDamage(10);
    std::cout << std::endl;
    diamondtrap4.takeDamage(10);
    std::cout << std::endl;
    diamondtrap4.beRepaired(20);
    std::cout << std::endl;
    diamondtrap4.attack("Enemy");
    std::cout << std::endl;
    diamondtrap4.highFivesGuys();
    std::cout << std::endl;
    diamondtrap4.printInfo();

    return 0;
}
