#include "BitcoinExchange.hpp"

std::string BitcoinExchange::databasePath = "input.txt";

std::tm BitcoinExchange::createDate(std::string dateString)
{
    std::tm date = {};
    std::istringstream iss(dateString);
    int year, month, day;
    char delim1, delim2;
    iss >> year >> delim1 >> month >> delim2 >> day;
    if (delim1 != '-' || delim2 != '-'
        || day < 1 || day > 31
        || month < 1 || month > 12
        || year < 2000 || year > 2050)
        throw DateError();
    switch (month){
        case 4: case 6: case 9: case 11:
            if (day > 30)
                throw DateError();
            else
                break;
        case 2:
            if (year % 4 == 0) {
                if (year % 100 == 0 && year % 400 != 0) {
                    if (day > 28)
                        throw DateError();
                }
                else {
                    if (day > 29)
                        throw DateError();
                }
            }
            else if (day > 28)
                throw DateError();
    }
    date.tm_year = year;
    date.tm_mon = month;
    date.tm_mday = day;
    return date;
}

void BitcoinExchange::createDatabase()
{
    std::ifstream file(databasePath, std::ifstream::in);
    std::string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string date;
            char comma;
            float value;
            iss >> date >> comma >> value;
            try {
                database[createDate(date)] = value;
            }
            catch (DateError &e) {
                std::cout << e.what() << " " << date <<std::endl;
            }
        }
    }
}

BitcoinExchange::BitcoinExchange()
{
    std::cout << databasePath << std::endl;
    createDatabase();
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref)
{
    *this=ref;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::printDatabase()
{
    for (std::map<std::tm, float>::iterator it = database.begin(); it != database.end(); it++){
        std::cout << it->first << " -> " << it->second << std::endl;
    }
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& ref)
{
    if (this != &ref)
        *this=ref;
    return (*this);
}

bool operator<(const std::tm &first, const std::tm &second)
{
    if (first.tm_year != second.tm_year)
        return first.tm_year < second.tm_year;
    if (first.tm_mon != second.tm_mon)
        return first.tm_mon < second.tm_mon;
    return first.tm_mday < second.tm_mday;
}

std::ostream &operator<<(std::ostream &os, std::tm const &ref)
{
    os << ref.tm_year << "/" << ref.tm_mon << "/" << ref.tm_mday;
    return os;
}

const char *BitcoinExchange::DateError::what() const throw()
{
	return ("bad input");
}
