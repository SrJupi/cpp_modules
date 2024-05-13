#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): target("no target")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string t): target(t), AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref): AForm(ref), target(ref.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	(void)ref;
	return (*this);
}

void PresidentialPardonForm::doExecute(void)
{
	std::cout << "Breaking news: "
	<< target
	<< " receives a formal pardon, signifying absolution from their past actions and a fresh start endorsed by Zaphod Beeblebrox!"
	<< std::endl;
}
