#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
    private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
    std::string truncate(std::string og);
    public:
    void updateContact (std::string newInfo[5]);
    void printContact (void);
    void printShortInfo (int i);
};

#endif
