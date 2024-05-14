#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): target("no target")
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(std::string t): AForm("Robotomy Request Form", 72, 45),  target(t)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref): AForm(ref), target(ref.target)
{
	std::srand(std::time(NULL));
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
	std::cout << "ratta-tat-tat-tat" << std::endl;
	if (std::rand() % 2)
		std::cout << "Robotomy successfull: " << target << " memories were wiped out!" << std::endl;
	else
		std::cout << "Robotomy failed!" << std::endl;
}
