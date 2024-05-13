#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): target("no target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t): target(t), AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref): AForm(ref), target(ref.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
	(void)ref;
	return (*this);
}

void ShrubberyCreationForm::doExecute(void)
{
	//plant trees on target
}
