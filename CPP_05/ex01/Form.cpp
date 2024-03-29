#include "Form.hpp"

Form::Form(std::string _name, bool _isSigned, int _sign, int _exec): name(_name), signGrade(_sign), execGrade(_exec) {
	_isSigned = false;
}

Form::Form(const Form& copy): name(copy.name), signGrade(copy.signGrade), execGrade(copy.execGrade) {
	*this = copy;
}

Form& Form::operator=(const Form& copy) {
	this->isSigned = copy.isSigned;
	return *this;
}

std::string const & Form::getName() const {
	return this->name;
}

bool Form::getSigned() const {
	return this->isSigned;
}

int Form::getSignGrade() const {
	return this->signGrade;
}

int Form::getExecGrade() const {
	return this->execGrade;
}

void Form::setSigned(bool is) {
	this->isSigned = is;
}

void Form::beSigned(Bureaucrat& b) {
	if (b.getGrade() > this->signGrade)
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
	return "The grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "The grade is too low.";
}

std::ostream& operator<<(std::ostream& out, const Form& src) {
	out << src.getName() << ", Sign Grade is " << src.getSignGrade() << ", Execute Grade is " << src.getExecGrade();
	if (src.getSigned())
		out << ", is signed" << std::endl;
	else
		out << ", is not signed" << std::endl;
	return out;
}
