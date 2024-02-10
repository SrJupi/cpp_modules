#include "Phonebook.hpp"
#include "Contact.hpp"
#include <string>
#include <iomanip>
#include <iostream>
#include <cstdlib>

Phonebook::Phonebook(void): index(0) {}

void Phonebook::displayFullContact(Contact c)
{
    c.printContact();
}

void Phonebook::printHeader(void)
{
    std::cout << '|' << std::setw(10) << std::right << "INDEX" << "|";
    std::cout << std::setw(10) << std::right << "FIRST NAME" << "|";
    std::cout << std::setw(10) << std::right << "LAST NAME" << "|";
    std::cout << std::setw(10) << std::right << "NICKNAME" << "|" << std::endl;
}

void Phonebook::printEmptyLine(void)
{
    std::cout << '|' << std::setw(11) << std::setfill('-') << "|";
    std::cout << std::setw(11) << "|";
    std::cout << std::setw(11) << "|";
    std::cout << std::setw(11) << "|" << std::endl;
    std::cout << std::setfill(' ');
}

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

bool Phonebook::isNumber(const std::string& str) {
    int i = 0;

    if (str[i] == '-')
     i++;
    while(str[i])
    {
        if (!std::isdigit(str[i])) {
            return false;
        }
        i++;
    }
    return true;
}

int Phonebook::getSearchInput(int n)
{
    int tmp;
    std::string input;
    
    std::cout << "Select the index of the contact that you want more information:\n>>> ";
    if (!std::getline(std::cin, input))
    {
        std::cout << "\nReturning to main...\n";
        return -1;
    }
    if (input.empty() || !isNumber(input))
    {
        std::cout << "Input is not a number!\n";
        return -1;
    }
    tmp = std::atoi(input.c_str());
    if (tmp < 0 || tmp >= n)
    {
        std::cout << "Invalid index!\n";
        return -1;
    }
    return tmp;
}
    
bool Phonebook::addContact(void)
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
        std::cout << "Insert item " << i + 1 << ": ";
        if (!std::getline(std::cin, newInfo[i]))
        {
            std::cout << "\nReturning to main...\n";
            return true;
        }
        if (!newInfo[i].empty())
            i++;
        else
            std::cout << "Field cannot be empty... Try again!\n";   
    }
    contacts[index % 8].updateContact(newInfo);
    index++;
    return true;
}

int Phonebook::getSize(void)
{
    if (index < 8)
        return index;
    else
        return 8;
}

bool Phonebook::searchContact(void)
{
    int n;
    
    n = this->getSize();
    if (!n)
    {
        std::cout << "Your phonebook is empty. Nothing to see here...\n";
        return true;
    }
    this->generateSearchTable(n);
    n = this->getSearchInput(n);
    if (n >= 0)
        contacts[n].printContact();
    return true;
}
