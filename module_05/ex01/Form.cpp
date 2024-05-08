#include "Form.hpp"

Form::Form(): name("No Form"), isSigned(false), signGrade(0), execGrade(0)
{
}


Form::Form(const Form &ref) : 
	name(ref.getName()),
	isSigned(ref.getSigned()),
	signGrade(ref.getSignGrade()),
	execGrade(ref.getExecGrade())
{
}

Form::Form(std::string n, int sG, int eG) : 
	name(n),
	isSigned(false),
	signGrade(sG),
	execGrade(eG)
{
    checkGrade(signGrade);
    checkGrade(execGrade);
}

Form::~Form()
{
}

Form &Form::operator=(const Form &ref)
{
	if (this != &ref)
	{
		this->isSigned = ref.getSigned();
	}
	return (*this);
}

std::string Form::getName(void) const
{
	return (name);
}

bool Form::getSigned(void) const
{
	return (isSigned);
}

int Form::getSignGrade(void) const
{
	return (signGrade);
}

int Form::getExecGrade(void) const
{
	return (execGrade);
}

void Form::beSigned(const Bureaucrat &ref)
{
    if (ref.getGrade() > signGrade)
        throw Form::GradeTooLowException();
    isSigned = true;
}
void Form::checkGrade(int g)
{
	if (g < HIGHEST)
		throw Form::GradeTooHighException();
	if (g > LOWEST)
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &os, Form const &ref)
{
    std::string status;
	if (ref.getSigned())
		status = "Ready to Go";
	else
		status = "Pending signature";
	
	os << "Form: " << ref.getName() << "\nSigned: " << status <<
	"\nSign Grade: " << ref.getSignGrade() << "\nExecution Grade: " << ref.getExecGrade();
    return os;
}
