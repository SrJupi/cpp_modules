#ifndef AForm_HPP
# define AForm_HPP

#include <string>
#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int execGrade;
	void checkGrade(int g);

protected:
	AForm();
	AForm(const AForm& ref);
	AForm(std::string name, int signGrade, int execGrade);
	AForm&	operator=(const AForm& ref);
	virtual void doExecute(void) = 0;


public:
	~AForm();

	std::string getName(void) const;
	bool getSigned(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;

	void beSigned(const Bureaucrat& ref);
	void execute(const Bureaucrat& ref);

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	class NotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream & operator<<(std::ostream & os, AForm const & ref);

#endif