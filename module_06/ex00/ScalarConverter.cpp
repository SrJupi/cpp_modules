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

void ScalarConverter::convertChar(std::string &str)
{
	char	c;
	int		i;
	float	f;
	double	d;

	c = str[0];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

bool ScalarConverter::checkPseudo(std::string &str)
{
	float	f;
	double	d;

	std::string pseudosF[] = {"-inff", "+inff", "nanf"};
	std::string pseudosD[] = {"-inf", "+inf", "nan"};
	for (int i = 0; i < 3; i++)
	{
		if (str == pseudosF[i])
		{
			str.erase(str.size() - 1);
			f = std::atof(str.c_str());
			d = static_cast<double>(f);
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
			return (true);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (str == pseudosD[i])
		{
			d = std::atof(str.c_str());
			f = static_cast<float>(d);
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
			return (true);
		}
	}
	return (false);
}

bool ScalarConverter::checkFloat(std::string &str)
{
	size_t i = 0;
	if ((str[i] == '+' || str[i] == '-'))
		i++;
	size_t final = str.length();
	if (str[final - 1] == 'f')
		final--;
	for (; i < final; i++) {
        if (!std::isdigit(str[i]) && str[i] != '.') {
            return false;
        }
    }
    return true;}

void ScalarConverter::convertFloat(std::string &str)
{
	float f;
	double d;
	char c;
	int i;
	size_t dot = str.find(".");
	if (str[str.size() - 1] == 'f') {
		str.erase(str.size() - 1);
		f = std::atof(str.c_str());
		d = static_cast<double>(f);
		c = static_cast<char>(f);
		i = static_cast<int>(f);
	}
	else {
		d = std::atof(str.c_str());
		f = static_cast<float>(d);
		c = static_cast<char>(d);
		i = static_cast<int>(d);
	}
	if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(str.size() - dot - 1  == 0 ? 1 : str.size() - dot - 1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

bool ScalarConverter::checkInt(std::string &str)
{
	size_t i = 0;
	if ((str[i] == '+' || str[i] == '-') && str.size() > 1)
		i++;
	for (; i < str.length(); i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

void ScalarConverter::convertInt(std::string &str)
{
	int	i = std::atoi(str.c_str());
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);
	if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	if (str.length() == 1 && (str[0] < '0' || str[0] > '9'))
	{
		return (convertChar(str));
	}
	size_t dot = str.find(".");
	if (dot == std::string::npos)
	{
		if (checkPseudo(str))
			return ;
		if (checkInt(str))
			return convertInt(str);
		std::cout << "String not convertible" << std::endl;
		return ;
	}
	dot = str.find(".", dot + 1);
	if (dot == std::string::npos){
		if (checkFloat(str))
			return convertFloat(str);
	}
	std::cout << "String not convertible" << std::endl;
	return ;
}
