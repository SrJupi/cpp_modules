#include "Bureaucrat.hpp"


int main(void) 
{
	try 
	{
        Bureaucrat bureaucrat("bob", 2);
        std::cout << bureaucrat << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) 
	{
        std::cerr << "TooHighException" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) 
	{
        std::cerr << "TooLowException" << std::endl;
    }

    try 
	{
        Bureaucrat bureaucrat1("bob", 1);
        bureaucrat1.incrementGrade();
        std::cout << bureaucrat1 << std::endl;
    }
    catch (std::exception &e) 
	{
        std::cerr << e.what() << std::endl;
    }

    Bureaucrat bureaucrat2("bob", 150);
    try 
	{
        bureaucrat2.decrementGrade();
        std::cout << bureaucrat2 << std::endl;
    }
    catch (std::exception &e) 
	{
        std::cerr << e.what() << std::endl;
    }
    std::cout << bureaucrat2 << std::endl;

}
