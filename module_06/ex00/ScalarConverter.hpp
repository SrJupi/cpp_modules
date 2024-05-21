#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& ref);
    ~ScalarConverter();

    ScalarConverter&	operator=(const ScalarConverter& ref);

public:
    static void convert(std::string str);
};

#endif
