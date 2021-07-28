#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
public:
	class GradeTooHighException: public std::exception
	{
	public:
		GradeTooHighException() {}
		virtual ~GradeTooHighException() throw() {}
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
	public:
		GradeTooLowException() {}
		virtual ~GradeTooLowException() throw() {}
		virtual const char* what() const throw();
	};

private:
	std::string const name;
	bool isSigned;
	int const signGrade;
	int const execGrade;
	Form(): isSigned(false), signGrade(0), execGrade(0) {}

public:
	Form(std::string _name, bool _isSigned, int _sign, int _exec);
	Form(const Form& copy);
	Form& operator=(const Form& copy);
	~Form() {}
	std::string const & getName() const;
	bool getSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;
	void setSigned(bool is);
	void beSigned(Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& out, const Form& src);

#endif
