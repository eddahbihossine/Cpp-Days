#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointValue = 0;
}
Fixed :: ~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
//getter
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointValue);
}
// setter
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}
Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}
Fixed& Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy Assignement operator called" << std::endl;
    if (this != &fixed)
        this->_fixedPointValue = fixed.getRawBits();
    return (*this);
}


