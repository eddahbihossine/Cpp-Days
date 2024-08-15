#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>
class Fixed 
{
	private:
		int					_fixedPointValue;
		const static int    _fractionalBits = 8;
	public:
		// constructors
		Fixed();
		~Fixed();
		Fixed(const int value);
		Fixed(const float value);
		//operators
		Fixed &operator++(void);
		Fixed operator++(int );
		Fixed &operator--(void);
		Fixed operator--(int );
		int operator<(const Fixed &fixed) const ;
		int operator>(const Fixed &fixed)	const ;
		int operator<=(const Fixed &fixed) const ;
		int operator>=(const Fixed &fixed) const ;
		int operator==(const Fixed &fixed)	const ;
		int operator!=(const Fixed &fixed)	const ;
		static const Fixed &max( const Fixed &left, const Fixed &right);
		static const Fixed &min(const Fixed &left,const Fixed &right)  ;
		static const Fixed &maxt(Fixed &left, Fixed &right) ;
		static const Fixed &mint(Fixed &left, Fixed &right) ;
		Fixed(const Fixed &fixed);
		float toFloat(void) const;
		int toInt(void) const;
		Fixed& operator=(const Fixed &fixed);
		Fixed &operator+(const Fixed &fixed);
		Fixed &operator-(const Fixed &fixed);
		Fixed &operator*(const Fixed &fixed);
		Fixed &operator/(const Fixed &fixed);
		// getter and setter
		int getRawBits(void) const;
		void setRawBits(int const raw);
};



#endif