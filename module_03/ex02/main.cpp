#include <iostream>
#include "FragTrap.hpp"

int main()
{
	std::cout << ">> Create a FragTrap object with default and string constructor" << std::endl << std::endl;
	FragTrap fragtrap1;
	FragTrap fragtrap2("FragTrap2");

	std::cout << std::endl << ">> Test attack, takeDamage, and beRepaired functionalities" << std::endl << std::endl;
	fragtrap1.attack("Target1");
	fragtrap2.attack("Target2");

	fragtrap1.takeDamage(5);
	fragtrap2.takeDamage(3);

	fragtrap1.beRepaired(2);
	fragtrap2.beRepaired(4);

	std::cout << std::endl << ">> Test high five functionality" << std::endl << std::endl;
	fragtrap1.highFivesGuys();
	fragtrap2.highFivesGuys();

	std::cout << std::endl << ">> Test copy constructor and copy assignment operator" << std::endl << std::endl;
	FragTrap fragtrap3;
	fragtrap3 = fragtrap1;
	FragTrap fragtrap4(fragtrap2);

	fragtrap3.attack("Target3");
	fragtrap4.attack("Target4");

	std::cout << "\n>> The Life and Death of fragtrap4\n\n";
	fragtrap4.printInfo();
	std::cout << std::endl;
	fragtrap4.takeDamage(100);
	std::cout << std::endl;
	fragtrap4.takeDamage(10);
	std::cout << std::endl;
	fragtrap4.beRepaired(20);
	std::cout << std::endl;
	fragtrap4.attack("Enemy");
	std::cout << std::endl;
	fragtrap4.printInfo();

	return 0;
}
