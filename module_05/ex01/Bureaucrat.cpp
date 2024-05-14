#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Default Bureaucrat"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string n, int g) : name(n)
{
	checkGrade(g);
	grade = g;
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
	checkGrade(grade - 1);
	grade--;
}

void Bureaucrat::decrementGrade(void)
{
    checkGrade(grade + 1);
    grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

void Bureaucrat::checkGrade(int g)
{
	if (g < HIGHEST)
		throw Bureaucrat::GradeTooHighException();
	if (g > LOWEST)
		throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(Form &ref) {
	try {
		ref.beSigned(*this);
		std::cout << getName() << " signed " << ref.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << getName() << " could't sign " << ref.getName() << " because " << e.what() << std::endl;
	}
}


std::ostream &operator<<(std::ostream &os, Bureaucrat const &ref)
{
    os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
    return os;
}
