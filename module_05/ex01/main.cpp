#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{
    Bureaucrat bureaucrat("ash",10);
    Form form("formName", 10, 10);

    std::cout << bureaucrat << std::endl;
    std::cout << form << std::endl;
    bureaucrat.signForm(form);
    std::cout << form << std::endl;

    bureaucrat.decrementGrade();

    Form form2("OtherForm", 10, 10);
    std::cout << std::endl << bureaucrat << std::endl;
    std::cout << form2 << std::endl;

    try {
        bureaucrat.signForm(form2);
    } catch (Form::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << form2 << std::endl;

    return 0;
}