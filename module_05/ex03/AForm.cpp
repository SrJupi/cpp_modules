#include "AForm.hpp"

AForm::AForm(): name("No AForm"), isSigned(false), signGrade(0), execGrade(0)
{
}


AForm::AForm(const AForm &ref) : 
	name(ref.getName()),
	isSigned(ref.getSigned()),
	signGrade(ref.getSignGrade()),
	execGrade(ref.getExecGrade())
{
}

AForm::AForm(std::string n, int sG, int eG) : 
	name(n),
	isSigned(false),
	signGrade(sG),
	execGrade(eG)
{
    checkGrade(signGrade);
    checkGrade(execGrade);
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &ref)
{
	if (this != &ref)
	{
		this->isSigned = ref.getSigned();
	}
	return (*this);
}

std::string AForm::getName(void) const
{
	return (name);
}

bool AForm::getSigned(void) const
{
	return (isSigned);
}

int AForm::getSignGrade(void) const
{
	return (signGrade);
}

int AForm::getExecGrade(void) const
{
	return (execGrade);
}

void AForm::beSigned(const Bureaucrat &ref)
{
    if (ref.getGrade() > signGrade)
        throw AForm::GradeTooLowException();
    isSigned = true;
}
void AForm::execute(const Bureaucrat &ref)
{
	if (!isSigned)
		throw AForm::NotSignedException();
	if (ref.getGrade() > this->execGrade)
		throw AForm::GradeTooLowException();
	doExecute();
}
void AForm::checkGrade(int g)
{
	if (g < HIGHEST)
		throw AForm::GradeTooHighException();
	if (g > LOWEST)
		throw AForm::GradeTooLowException();
}


const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &os, AForm const &ref)
{
    std::string status;
	if (ref.getSigned())
		status = "Ready to Go";
	else
		status = "Pending signature";
	
	os << "AForm: " << ref.getName() << "\nSigned: " << status <<
	"\nSign Grade: " << ref.getSignGrade() << "\nExecution Grade: " << ref.getExecGrade();
    return os;
}
