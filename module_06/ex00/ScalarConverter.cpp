#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &ref)
{
	*this = ref;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref)
{
	*this = ref;
	return (*this);
}

void ScalarConverter::convert(std::string str)
{
    std::cout << str << std::endl;
}
