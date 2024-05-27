#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int execGrade;
	Form();
	void checkGrade(int g);

public:
	Form(const Form& ref);
	Form(std::string name, int signGrade, int execGrade);
	~Form();

	Form&	operator=(const Form& ref);

	std::string getName(void) const;
	bool getSigned(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;

	void beSigned(const Bureaucrat& ref);

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream & operator<<(std::ostream & os, Form const & ref);

#endif
