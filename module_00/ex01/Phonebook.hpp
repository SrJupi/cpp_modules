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

    public:
    Phonebook(void);
    void addContact();
    int getSize(void);
    void searchContact(void);
};

#endif