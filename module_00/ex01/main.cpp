#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"
#include "Phonebook.hpp"

int main()
{
    Phonebook pb;
    bool isOn = true;
    std::string input;
//     Contact c;
//     std::string info[] = {"Lucas", "ABCDEFGHIJK", "Lukita", "123456789", "Gosta de censurar as pessoas"};
//     c.updateContact(info);
//     pb.searchContact();
// //    pb.addContact();

//     return 0;
    
    std::cout << "Welcome to your phonebook!\n";
    while (isOn)
    {
        std::cout << "Current contacts: " << pb.getSize() << "!\n";
        std::cout << "What do you want to do? ADD, SEARCH or EXIT.\n>>> ";
        std::getline(std::cin, input);
        if (input == "EXIT")
            isOn = false;
        else if (input == "SEARCH")
            pb.searchContact();
        else if (input == "ADD")
            pb.addContact();
        else
            std::cout << "Cannot understand: " << input << "!\n";
    }

    return 0;
}

