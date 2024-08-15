#include "Fixed.hpp"

Fixed::Fixed() 
{
    this->_fixedPointValue = 0;
}

Fixed::~Fixed()
{
}
Fixed ::Fixed(const int value)
{
    this->_fixedPointValue = value << this->_fractionalBits;
}
Fixed ::Fixed(const float value)
{
    this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
    puts("Float constructor called");
    std::cout << this->_fixedPointValue << std::endl;
}
Fixed::Fixed(const Fixed &fixed)
{
    *this = fixed;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_fixedPointValue / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->_fixedPointValue >> this->_fractionalBits);
}

int Fixed::getRawBits(void) const
{
   
    return (this->_fixedPointValue);
}
void Fixed::setRawBits(int const raw)
{
   
    this->_fixedPointValue = raw;
}


Fixed& Fixed::operator=(const Fixed &fixed)
{
    if (this != &fixed)
        this->_fixedPointValue = fixed.getRawBits();
    return (*this);
}
Fixed &Fixed::operator++(void)
{
    this->_fixedPointValue++;
    return (*this);
}
Fixed Fixed::operator++(int) 
{
    Fixed tmp(*this);
    _fixedPointValue++;
    return (tmp);
}
Fixed &Fixed::operator--(void)
{
    this->_fixedPointValue--;
    return (*this);
}
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    _fixedPointValue--;
    return (tmp);
}


 int Fixed::operator>(const Fixed &fixed) const 
 {
     return (this->_fixedPointValue > fixed._fixedPointValue);
 }

int Fixed::operator<(const Fixed &fixed) const 
{
    return (this->_fixedPointValue < fixed._fixedPointValue);
}

int Fixed::operator>=(const Fixed &fixed) const 
{
    return (this->_fixedPointValue >= fixed._fixedPointValue);
}

int Fixed::operator<=(const Fixed &fixed) const 
{
    return (this->_fixedPointValue <= fixed._fixedPointValue);
}

int Fixed::operator==(const Fixed &fixed) const 
{
    return (this->_fixedPointValue == fixed._fixedPointValue);
}

int Fixed::operator!=(const Fixed &fixed) const 
{
    return (this->_fixedPointValue != fixed._fixedPointValue);
}
 
Fixed &Fixed::operator+(const Fixed &fixed)
{
    this->_fixedPointValue += fixed._fixedPointValue;
    return (*this);
}

Fixed &Fixed::operator-(const Fixed &fixed)
{
    this->_fixedPointValue -= fixed._fixedPointValue;
    return (*this);
}

Fixed &Fixed::operator*(const Fixed &fixed)
{
    this->_fixedPointValue *= fixed._fixedPointValue;
    this->_fixedPointValue /= 256;
    return (*this);
}

Fixed &Fixed::operator/(const Fixed &fixed)
{
    this->_fixedPointValue /= fixed._fixedPointValue;
    this->_fixedPointValue =(this->_fixedPointValue  * 256);
    return (*this);
}
 const Fixed &Fixed::max(const Fixed &left, const Fixed &right)  
{
    if (left > right)
        return (left);
    else
        return (right);
}

const Fixed &Fixed::min(const Fixed &left, const Fixed &right) 
{
    if (left < right)
        return (left);
    else
        return (right);
}
const Fixed &Fixed::maxt(Fixed &left, Fixed &right) 
{
    if (left > right)
        return (left);
    else
        return (right);
}
const Fixed &Fixed::mint(Fixed &left, Fixed &right) 
{
    if (left < right)
        return (left);
    else
        return (right);
}