#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
    private:
    int index;
    Contact contacts[8];
    void displayFullContact(Contact c);
    void printHeader(void);
    void printEmptyLine(void);
    void generateSearchTable(int n);
    int getSearchInput(int n);
    bool isNumber(const std::string& str);

    public:
    Phonebook(void);
    bool addContact();
    int getSize(void);
    bool searchContact(void);
};

#endif
