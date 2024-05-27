#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	PresidentialPardonForm();
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& ref);
	const std::string target;

public:
	PresidentialPardonForm(std::string target);

	PresidentialPardonForm(const PresidentialPardonForm& ref);
	~PresidentialPardonForm();

	void doExecute(void);
};

#endif
