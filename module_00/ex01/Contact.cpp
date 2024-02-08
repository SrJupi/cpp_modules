#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

std::string Contact::truncate(std::string og)
{
    if (og.length() <= 10)
        return og;
    return og.substr(0, 9) + ".";
}

void Contact::updateContact (std::string newInfo[5])
{
    firstName = newInfo[0];
    lastName = newInfo[1];
    nickName = newInfo[2];
    phoneNumber = newInfo[3];
    darkestSecret = newInfo[4];
}

void Contact::printContact (void)
{
    std::cout << std::setw(16) << std::left << "First name:" << firstName << std::endl;
    std::cout << std::setw(16) << std::left << "Last name:" << lastName << std::endl;
    std::cout << std::setw(16) << std::left << "Nickname:" << nickName << std::endl;
    std::cout << std::setw(16) << std::left << "Phone number:" << phoneNumber << std::endl;
    std::cout << std::setw(16) << std::left << "Darkest secret:" << darkestSecret << std::endl;
}

void Contact::printShortInfo (int i)
{
        std::cout << '|' << std::setw(10) << std::right << i << "|";
        std::cout << std::setw(10) << std::right << this->truncate(firstName) << "|";
        std::cout << std::setw(10) << std::right << this->truncate(lastName) << "|";
        std::cout << std::setw(10) << std::right << this->truncate(nickName) << "|" << std::endl;
}