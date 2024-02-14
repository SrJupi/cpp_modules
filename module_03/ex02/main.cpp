#include <iostream>
#include "FragTrap.hpp"

int main() {
    // Create a FragTrap object with default constructor
    FragTrap fragtrap1;
    // Create a FragTrap object with string constructor
    FragTrap fragtrap2("FragTrap2");

    // Test attack, takeDamage, and beRepaired functionalities
    fragtrap1.attack("Target1");
    fragtrap2.attack("Target2");

    fragtrap1.takeDamage(5);
    fragtrap2.takeDamage(3);

    fragtrap1.beRepaired(2);
    fragtrap2.beRepaired(4);

    // Test copy constructor and copy assignment operator
    FragTrap fragtrap3 = fragtrap1; // This invokes the copy constructor
    fragtrap3.printInfo();
    FragTrap fragtrap4 = fragtrap2; // This also invokes the copy constructor

    fragtrap3.attack("Target3");
    fragtrap4.attack("Target4");

    // Test copy assignment operator
    fragtrap3 = fragtrap1; // This should invoke the copy assignment operator
    fragtrap4 = fragtrap2; // This should also invoke the copy assignment operator

    std::cout << "\nThe Life and Death of fragtrap4\n\n";
    fragtrap4.printInfo();
    std::cout << std::endl;
    fragtrap4.highFivesGuys();
    std::cout << std::endl;
    fragtrap4.takeDamage(100);
    std::cout << std::endl;
    fragtrap4.takeDamage(10);
    std::cout << std::endl;
    fragtrap4.takeDamage(10);
    std::cout << std::endl;
    fragtrap4.beRepaired(20);
    std::cout << std::endl;
    fragtrap4.attack("Enemy");
    std::cout << std::endl;
    fragtrap4.highFivesGuys();
    std::cout << std::endl;
    fragtrap4.printInfo();

    return 0;
}
