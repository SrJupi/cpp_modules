#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& ref);
	~ScalarConverter();

	ScalarConverter&	operator=(const ScalarConverter& ref);

	static void convertChar(std::string &str);
	static bool checkPseudo(std::string &str);
	static bool	checkFloat(std::string &str);
	static void convertFloat(std::string &str);
	static bool	checkInt(std::string &str);
	static void	convertInt(std::string &str);

public:
	static void convert(std::string str);
};

#endif
