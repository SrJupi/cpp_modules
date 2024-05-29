#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include <exception>

class BitcoinExchange
{
private:
    static std::string databasePath;
    std::map<std::tm, float> database;
    std::tm createDate(std::string dateString);
    void    createDatabase();
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& ref);
    ~BitcoinExchange();

    void printDatabase();

    BitcoinExchange&	operator=(const BitcoinExchange& ref);


    class DateError : public std::exception {
    public:
        const char* what() const throw();
    };
};

bool operator<(const std::tm& first, const std::tm& second);
std::ostream & operator<<(std::ostream & os, std::tm const & ref);

#endif
