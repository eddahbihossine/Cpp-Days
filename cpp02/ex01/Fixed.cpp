#include "Fixed.hpp"
// int constructor
Fixed ::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << this->_fractionalBits;
}

// default constructor
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointValue = 0;
}
// destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
// convert to float
float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (1 << this->_fractionalBits));
}
// getter
int Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}
// setter
void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

// copy constructor
Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

// assignement operator
Fixed& Fixed::operator=(const Fixed &fixed)
{
	if (this != &fixed)
		this->_fixedPointValue = fixed.getRawBits();
	return (*this);
}

// float constructor
 Fixed:: Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}
// convert to int   
int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}