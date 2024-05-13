#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): target("no target")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string t): target(t), AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref): AForm(ref), target(ref.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
	(void)ref;
	return (*this);
}

void RobotomyRequestForm::doExecute(void)
{
	//do robotomy
}
