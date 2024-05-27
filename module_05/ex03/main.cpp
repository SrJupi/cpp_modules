#include "Intern.hpp"

int main( void )
{
    Intern intern;
    AForm *form;

    form = intern.makeForm("HOLA!!!", "Lucas");
    std::cout << form << std::endl;

    form = intern.makeForm("shrubbery creation", "Lucas");
    std::cout << *form << std::endl;
    delete form;

    form = intern.makeForm("robotomy request", "Lucas");
    std::cout << *form << std::endl;
    delete form;
    
    form = intern.makeForm("presidential pardon", "Lucas");
    std::cout << *form << std::endl;
    delete form;

    return 0;
}
