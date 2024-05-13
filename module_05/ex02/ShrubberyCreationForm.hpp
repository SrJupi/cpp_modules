#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	ShrubberyCreationForm();
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& ref);
	const std::string target;

public:
	ShrubberyCreationForm(std::string target);

	ShrubberyCreationForm(const ShrubberyCreationForm& ref);
	~ShrubberyCreationForm();

	void doExecute(void);
};

#endif