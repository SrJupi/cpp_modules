#include <iostream>
#include <string>
#include <iomanip>
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
        std::cout << "Current contacts: " << pb.getSize() << "!\n";
        std::cout << "What do you want to do? ADD, SEARCH or EXIT.\n>>> ";
        if (!std::getline(std::cin, input))
        {
            std::cout << "\nEOF found...\nExiting..\n";
            isOn = false;
        }
        else if (input == "EXIT")
            isOn = false;
        else if (input == "SEARCH")
            isOn = pb.searchContact();
        else if (input == "ADD")
            isOn = pb.addContact();
        else
            std::cout << "Cannot understand: " << input << "!\n";
    }
    return 0;
}

