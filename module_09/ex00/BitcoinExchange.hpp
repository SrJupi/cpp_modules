#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include <exception>
#include <cstdlib>
#include <string>
#include <iomanip>


class BitcoinExchange
{
private:
    static std::string dbPath;
    std::map<std::tm, double> dbMap;
    std::tm createDate(std::string dateString);
    void    createDatabase();
    void    findInMap(std::tm tmDate, float value);
    float   checkDouble(std::string floatStr);
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& ref);
    ~BitcoinExchange();

    void convertInput(std::string inputPath);

    void printDatabase();

    BitcoinExchange&	operator=(const BitcoinExchange& ref);


    class DateError : public std::exception {
    public:
        const char* what() const throw();
    };

    class OpenError : public std::exception {
    public:
        const char* what() const throw();
    };

    class NegativeNumberError : public std::exception {
    public:
        const char* what() const throw();
    };

    class TooBigNumberError : public std::exception {
    public:
        const char* what() const throw();
    };

    class DateNotFound : public std::exception {
    public:
        const char* what() const throw();
    };
};

bool operator<(const std::tm& first, const std::tm& second);
bool operator==(const std::tm& first, const std::tm& second);

std::ostream & operator<<(std::ostream & os, std::tm const & ref);

#endif
