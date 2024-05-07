#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default Bureaucrat"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string n, int g) : name(n), grade(g)
{
	checkGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : name(ref.getName()),
	grade(ref.getGrade())
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref)
{
	if (this != &ref)
		this->grade = ref.getGrade();
	return (*this);
}

const std::string Bureaucrat::getName(void) const
{
	return (name);
}

int Bureaucrat::getGrade(void) const
{
	return (grade);
}

void Bureaucrat::incrementGrade(void)
{
	grade--;
	checkGrade();
}

void Bureaucrat::decrementGrade(void)
{
    grade++;
    checkGrade();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

void Bureaucrat::checkGrade(void)
{
	if (grade < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	if (grade > LOWEST)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &ref)
{
    os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
    return os;
}
