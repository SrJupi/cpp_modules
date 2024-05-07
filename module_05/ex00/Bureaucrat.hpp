#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

# define HIGHEST 1
# define LOWEST 150

class Bureaucrat
{
private:
	const std::string name;
	int grade;
	void checkGrade(int g);

public:
	Bureaucrat();
	Bureaucrat(std::string n, int g);
	Bureaucrat(const Bureaucrat& ref);
	~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat& ref);

	const std::string	getName(void) const;
	int getGrade(void) const;
	void	incrementGrade(void);
	void	decrementGrade(void);

	class GradeTooHighException : public std::exception {
	public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream & operator<<(std::ostream & os, Bureaucrat const & ref);

#endif
