#include "Intern.hpp"


Intern::Intern()
{
}

Intern::Intern(const Intern& ref)
{
    *this=ref;
}

Intern::~Intern()
{
}

Intern&	Intern::operator=(const Intern& ref)
{
    *this=ref;
    return (*this);
}

AForm *Intern::makeShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePardon(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    for (size_t i = 0; i < formName.size(); i++)
        formName[i] = tolower(formName[i]);
    AForm*	(Intern::*functions[3])(std::string) = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePardon};
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i = 0;
    for (; i < 3 && formName != forms[i]; i++)
        ;
    if (i >= 3) {
        std::cerr << "Form not found: " << formName << "!" << std::endl;
        return NULL;
    }
    return (this->*functions[i])(target);
}
