#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &ref)
{
	*this = ref;
}

RPN::~RPN()
{
}

void RPN::doOperations(char op, std::stack<float> &result)
{
	float	num2;
	float	num1;

	if (op != '+' && op != '-' && op != '*' && op != '/')
		throw OperatorError();
	if (result.size() < 2)
		throw NotEnoughNumbersError();
	num2 = result.top();
	result.pop();
	num1 = result.top();
	result.pop();
	switch (op)
	{
	case '+':
		result.push(num1 + num2);
		break ;
	case '-':
		result.push(num1 - num2);
		break ;
	case '*':
		result.push(num1 * num2);
		break ;
	case '/':
		if (!num2)
			throw ZeroDivisionError();
		result.push(num1 / num2);
		break ;
	}
}

void RPN::doSomeRPN(std::string rpnString)
{
	std::stack<float> result;
	for (std::string::iterator it = rpnString.begin(); it != rpnString.end(); it++)
	{
		if (isspace(*it))
			continue ;
		if (isdigit(*it))
		{
			result.push(*it - '0');
			continue ;
		}
		try
		{
			doOperations(*it, result);
		}
		catch (OperatorError &e)
		{
			std::cerr << e.what() << ": " << *it << std::endl;
			return ;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			return ;
		}
	}
	if (result.size() > 1)
		throw TooManyNumbersError();
	if (result.size() < 1)
		throw NotEnoughNumbersError();
	std::cout << result.top() << std::endl;
}

RPN &RPN::operator=(const RPN &ref)
{
	if (this != &ref)
		*this = ref;
	return (*this);
}

const char *RPN::NotEnoughNumbersError::what() const throw()
{
	return ("Insufficent amount of numbers to perform an operation");
}

const char *RPN::OperatorError::what() const throw()
{
	return ("Character not identified");
}

const char *RPN::TooManyNumbersError::what() const throw()
{
	return ("Too many numbers found in stack, result is not finished");
}

const char *RPN::ZeroDivisionError::what() const throw()
{
	return ("You should not divide by zero");
}
