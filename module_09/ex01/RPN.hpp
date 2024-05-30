#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
private:
    RPN();
    RPN(const RPN& ref);
    RPN&	operator=(const RPN& ref);
    ~RPN();
    static void doOperations(char op, std::stack<float> &result);

public:
    static void doSomeRPN(std::string rpnString);
    class OperatorError : public std::exception {
    public:
        const char* what() const throw();
    };
    class NotEnoughNumbersError : public std::exception {
    public:
        const char* what() const throw();
    };
    class TooManyNumbersError : public std::exception {
    public:
        const char* what() const throw();
    };
    class ZeroDivisionError : public std::exception {
    public:
        const char* what() const throw();
    };

};

#endif
