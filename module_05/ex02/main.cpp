#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main( void )
{
    Bureaucrat junior("Junior bureaucrat", 150);
    Bureaucrat bureaucrat("Vice president",10);
    ShrubberyCreationForm form("BCN");

    junior.signAForm(form);
    bureaucrat.signAForm(form);
    junior.executeForm(form);
    bureaucrat.executeForm(form);

    PresidentialPardonForm pardon("Ford Perfect");
    bureaucrat.signAForm(pardon);
    bureaucrat.executeForm(pardon);
    Bureaucrat president("El presidente", 1);
    president.executeForm(pardon);

    RobotomyRequestForm robot("Bender");
    bureaucrat.executeForm(robot);
    bureaucrat.signAForm(robot);
    bureaucrat.executeForm(robot);

    return 0;
}