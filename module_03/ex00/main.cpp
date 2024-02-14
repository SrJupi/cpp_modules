#include <iostream>
#include "ClapTrap.hpp"

int main() {
    // Create a ClapTrap object with default constructor
    ClapTrap claptrap1;
    // Create a ClapTrap object with string constructor
    ClapTrap claptrap2("ClapTrap2");

    // Test attack, takeDamage, and beRepaired functionalities
    claptrap1.attack("Target1");
    claptrap2.attack("Target2");

    claptrap1.takeDamage(5);
    claptrap2.takeDamage(3);

    claptrap1.beRepaired(2);
    claptrap2.beRepaired(4);

    // Test copy constructor and copy assignment operator
    ClapTrap claptrap3 = claptrap1; // This invokes the copy constructor
    ClapTrap claptrap4 = claptrap2; // This also invokes the copy constructor

    claptrap3.attack("Target3");
    claptrap4.attack("Target4");

    // Test copy assignment operator
    claptrap3 = claptrap1; // This should invoke the copy assignment operator
    claptrap4 = claptrap2; // This should also invoke the copy assignment operator

    return 0;
}
