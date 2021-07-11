#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default Constructor called" << std::endl;
	fixedValue = 0;
}

Fixed::Fixed(int const intVal)
{
	std::cout << "Int Constructor called" << std::endl;

}

Fixed::Fixed(float const floatVal)
{
	std::cout << "Float Constructor called" << std::endl;

}

Fixed::Fixed(Fixed& copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Assignation Operator called" << std::endl;
	this->fixedValue = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function callled" << std::endl;
	return (this->fixedValue);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedValue = raw;
}

float Fixed::toFloat(void) const
{

}

int Fixed::toInt(void) const
{

}
