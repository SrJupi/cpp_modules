#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): target("no target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string t): AForm("Shrubbery Creation Form", 145, 137), target(t)
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
	std::ofstream file((target+"_shrubbery").c_str(), std::ios::out | std::ios::app);
	if (file.is_open()) {
		file
		<< "     #\n"
		<< "    ###\n"
		<< "   #####\n"
		<< "  #######\n"
		<< " #########\n"
		<< "    |@|\n"
		<< "    |@|\n\n";
		file.close();
	} else {
		std::cerr << "Unable to open file: " << target << "_shrubbery" << std::endl;
	}
}
