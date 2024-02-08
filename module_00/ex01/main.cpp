#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include "Contact.hpp"
#include "Phonebook.hpp"

int main(void)
{
    Phonebook pb;
    bool isOn = true;
    std::string input;

    std::cout << "Welcome to your phonebook!\n";
    while (isOn)
    {
        if (std::cin.eof())
        {
            std::cin.clear();
            std::clearerr(stdin);
        }
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "Current contacts: " << pb.getSize() << "!\n";
        std::cout << "What do you want to do? ADD, SEARCH or EXIT.\n>>> ";
        if (!std::getline(std::cin, input))
			input = "EOF";
        if (input == "EXIT")
            isOn = false;
        else if (input == "SEARCH")
            isOn = pb.searchContact();
        else if (input == "ADD")
            isOn = pb.addContact();
        else
            std::cout << input << " command not found!\n";
    }
    return 0;
}
