#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string _name, int _grade): name(_name) {
	grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): name(copy.getName()) {
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
	this->grade = copy.getGrade();
	return *this;
}

std::string const & Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incGrade() {
	if (--this->grade < 1) {
		this->grade++;
		throw GradeTooHighException();
	}
}

void Bureaucrat::decGrade() {
	if (++this->grade > 150) {
		this->grade--;
		throw GradeTooLowException();
	}
}

void Bureaucrat::signForm(Form& f) {
	try
	{
		f.beSigned(*this);
		std::cout << this->name << " signed " << f.getName() << std::endl;
		f.setSigned(true);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " cannot sign " << f.getName() << " because sign grade is too low." << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form) {
	try
	{
		form.execute(*this);
		std::cout << this->name << " execute " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " cannot execute " << form.getName() << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "1 is the maximum grade. Can't increase it any more.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "150 is the minimum grade. Can't decrease it any more.";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& src) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return out;
}
