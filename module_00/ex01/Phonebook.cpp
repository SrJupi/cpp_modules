#include "Phonebook.hpp"
#include "Contact.hpp"
#include <string>
#include <iomanip>
#include <iostream>

Phonebook::Phonebook(void): index(0) {};

void Phonebook::displayFullContact(Contact c)
{
    c.printContact();
};

void Phonebook::printHeader(void)
{
    std::cout << '|' << std::setw(10) << std::right << "INDEX" << "|";
    std::cout << std::setw(10) << std::right << "FIRST NAME" << "|";
    std::cout << std::setw(10) << std::right << "LAST NAME" << "|";
    std::cout << std::setw(10) << std::right << "NICKNAME" << "|" << std::endl;
};

void Phonebook::printEmptyLine(void)
{
    std::cout << '|' << std::setw(11) << std::setfill('-') << "|";
    std::cout << std::setw(11) << "|";
    std::cout << std::setw(11) << "|";
    std::cout << std::setw(11) << "|" << std::endl;
    std::cout << std::setfill(' ');
};

void Phonebook::generateSearchTable(int n)
{
    int i;
    
    this->printEmptyLine();
    this->printHeader();
    i = 0;
    while (i < n)
    {
        this->printEmptyLine();
        contacts[i].printShortInfo(i);
        i++;
    }
    this->printEmptyLine();
}

int Phonebook::getSearchInput(int n)
{
    int tmp;
    std::string input;
    
    std::cout << "Select the index of the contact that you want more information:\n>>> ";
    std::getline(std::cin, input);
    try
    {
        tmp = std::stoi(input);
    }
    catch (...)
    {
        std::cout << "Input is not a number!\n";
        return -1;
    }
    if (tmp < 0 || tmp >= n)
    {
        std::cout << "Invalid index!\n";
        return -1;
    }
    return tmp;
}
    
void Phonebook::addContact(void)
{
    std::string newInfo[5];
    int i;

    i = 0;
    std::cout << "Inserting new contact, fill the following fields:\n\
    1. First name;\n\
    2. Last name;\n\
    3. Nickname;\n\
    4. Phone number;\n\
    5. Darkest secret.\n";
    while (i < 5)
    {
        std::cout << "Insert item " << std::to_string(i + 1) << ": ";
        std::getline(std::cin, newInfo[i]);
        if (!newInfo[i].empty())
            i++;
        else
            std::cout << "Field cannot be empty... Try again!\n";   
    }
    contacts[index % 8].updateContact(newInfo);
    index++;
};

int Phonebook::getSize(void)
{
    if (index < 8)
        return index;
    else
        return 8;
};

void Phonebook::searchContact(void)
{
    int n;
    
    n = this->getSize();
    if (!n)
    {
        std::cout << "Your phonebook is empty. Nothing to see here...\n";
        return ;
    }
    this->generateSearchTable(n);
    n = this->getSearchInput(n);
    if (n >= 0)
        contacts[n].printContact();
};