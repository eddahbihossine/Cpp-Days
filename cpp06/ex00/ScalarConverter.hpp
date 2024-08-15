#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP
#include <iostream>
class ScalarConverter{
    
    private:
        ScalarConverter();
    public:
        ScalarConverter(ScalarConverter const & src);
        ScalarConverter & operator=(ScalarConverter const & src);
        static void convert(std::string oo);
        ~ScalarConverter();


};

#endif