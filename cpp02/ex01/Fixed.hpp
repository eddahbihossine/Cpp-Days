#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
#include <iomanip>
class Fixed
{
	private:
		int					_fixedPointValue;
		const static int    _fractionalBits = 8;
	public:
		//constructors
		Fixed();
        ~Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &fixed);
		//member functions
		float toFloat(void) const;
		int toInt(void) const;
		//operators
		Fixed& operator=(const Fixed &fixed);
		// getter and setter	
		int getRawBits(void) const;
		void setRawBits(int const raw);
};
#endif  