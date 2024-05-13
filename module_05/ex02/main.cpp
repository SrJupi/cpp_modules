#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main( void )
{
    Bureaucrat bureaucrat("ash",10);
    AForm AForm("AFormName", 10, 10);

    std::cout << bureaucrat << std::endl;
    std::cout << AForm << std::endl;
    bureaucrat.signAForm(AForm);
    std::cout << AForm << std::endl;

    bureaucrat.decrementGrade();

    AForm AForm2("OtherAForm", 10, 10);
    std::cout << std::endl << bureaucrat << std::endl;
    std::cout << AForm2 << std::endl;

    try {
        bureaucrat.signAForm(AForm2);
    } catch (AForm::GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << AForm2 << std::endl;

    return 0;
}