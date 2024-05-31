#include "BitcoinExchange.hpp"

std::string BitcoinExchange::dbPath = "data.csv";

std::tm BitcoinExchange::createDate(std::string dateString)
{
	std::tm date = {};
	std::istringstream iss(dateString);
	int year, month, day;
	char delim1, delim2;
	iss >> year >> delim1 >> month >> delim2 >> day;
	if (iss.peek() != EOF || delim1 != '-' || delim2 != '-' || day < 1
		|| day > 31 || month < 1 || month > 12 || year < 0)
		throw DateError();
	switch (month)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		if (day > 30)
			throw DateError();
		break ;
	case 2:
		if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) && day > 29)
			throw DateError();
		else if (day > 28)
			throw DateError();
	}
	date.tm_year = year;
	date.tm_mon = month;
	date.tm_mday = day;
	return (date);
}

void BitcoinExchange::createDatabase()
{
	std::ifstream file(dbPath.c_str(), std::ifstream::in);
	if (file.is_open())
	{
	    std::string line;
        getline(file,line);
		while (getline(file, line))
		{
			std::istringstream iss(line);
			std::string date;
			std::string valueStr;
			if (std::getline(iss, date, ',') && std::getline(iss, valueStr))
			{
				try
				{
					float value = std::atof(valueStr.c_str());
					dbMap[createDate(date)] = value;
				}
				catch (const std::exception &e)
				{
                    std::cout << e.what() << " " << date << std::endl;
				}
			}
			else
			{
				std::cerr << "Error: bad input " << line << std::endl;
			}
		}
	}
    file.close();
}

void BitcoinExchange::findInMap(std::tm tmDate, float value)
{
	float                               exchangeRate;
    std::map<std::tm, float>::iterator  it = dbMap.lower_bound(tmDate);
	if (it->first == tmDate)
		exchangeRate = it->second;
	else if (it == dbMap.begin())
		throw DateNotFound();
	else
	{
		it--;
		exchangeRate = it->second;
	}
	std::cout << tmDate << " => " << value << " = " << value
		* exchangeRate << std::endl;
}

float BitcoinExchange::checkFloat(std::string floatStr)
{
    float   value = std::atof(floatStr.c_str());
    if (value < 0)
        throw NegativeNumberError();
    if (value > 1000)
        throw TooBigNumberError();
    return value;
}

BitcoinExchange::BitcoinExchange()
{
	createDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref)
{
	this->dbMap = ref.dbMap;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::convertInput(std::string inputPath)
{
	std::ifstream file(inputPath.c_str(), std::ifstream::in);
	if (!file.is_open())
		throw OpenError();
	std::string line;
    getline(file,line);
	while (getline(file, line))
	{
		std::istringstream iss(line);
		std::string date;
		std::string valueStr;
		if (std::getline(iss, date, '|') && std::getline(iss, valueStr))
		{
			try
			{
				while (date[date.size() - 1] == ' ')
					date.erase(date.size() - 1);
				findInMap(createDate(date),
                checkFloat(valueStr));
			}
			catch (const std::exception &e)
			{
                std::cerr << line << " => " << e.what() << std::endl;
			}
		}
		else
		{
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
    file.close();
}

void BitcoinExchange::printDatabase()
{
	for (std::map<std::tm,
		float>::iterator it = dbMap.begin(); it != dbMap.end(); it++)
	{
		std::cout << it->first << " -> " << it->second << std::endl;
	}
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref)
{
	if (this != &ref) {
        this->dbMap = ref.dbMap;
    }
	return (*this);
}

/* TM OPERATORS */

bool operator<(const std::tm &first, const std::tm &second)
{
	if (first.tm_year != second.tm_year)
		return (first.tm_year < second.tm_year);
	if (first.tm_mon != second.tm_mon)
		return (first.tm_mon < second.tm_mon);
	return (first.tm_mday < second.tm_mday);
}

bool operator==(const std::tm &first, const std::tm &second)
{
	return (first.tm_year == second.tm_year && first.tm_mon == second.tm_mon
		&& first.tm_mday == second.tm_mday);
}

std::ostream &operator<<(std::ostream &os, std::tm const &ref)
{
	os << ref.tm_year << "-" << ref.tm_mon << "-" << ref.tm_mday;
	return (os);
}

/* EXCEPTIONS */

const char *BitcoinExchange::DateError::what() const throw()
{
	return ("Error: not valid date");
}

const char *BitcoinExchange::OpenError::what() const throw()
{
	return ("Error: cannot open file");
}

const char *BitcoinExchange::NegativeNumberError::what() const throw()
{
	return ("Error: not a positive number");
}

const char *BitcoinExchange::TooBigNumberError::what() const throw()
{
	return ("Error: too large a number");
}

const char *BitcoinExchange::DateNotFound::what() const throw()
{
	return ("Date not found in Database");
}
