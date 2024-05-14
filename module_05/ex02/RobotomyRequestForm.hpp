#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <ctime>
#include <cstdlib>


class RobotomyRequestForm : public AForm
{
private:
	RobotomyRequestForm();
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& ref);
	const std::string target;

public:
	RobotomyRequestForm(std::string target);

	RobotomyRequestForm(const RobotomyRequestForm& ref);
	~RobotomyRequestForm();

	void doExecute(void);
};

#endif