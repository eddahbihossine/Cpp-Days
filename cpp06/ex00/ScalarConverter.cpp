#include "ScalarConverter.hpp"
#include <sstream>
#define INT 0
#define FLOAT 1
#define CHAR 2
#define DOUBLE 3

ScalarConverter::ScalarConverter()
{
    std::cout << "constructor called"<< std ::endl;
}
void ScalarConverter::convert(std::string oo)
{ 
    
        for (size_t i = 0; i < 4; i++)
        {
            switch (i)
            {
                case CHAR:
                   { 
                    std::cout << "char: ";
                    int p = atoi(oo.c_str());
                    if(oo.length()  == 1)
                    {
                        if ((p <= 32 || p > 127 )&& (oo.find_first_not_of("0123456789")== std::string::npos))
                            std::cout << "Non displayable" << std::endl;
                        else
                            std::cout << "'" << oo[0] << "'" << std::endl;

                    }               
                    else if(oo.length() > 1)
                        {
                            int o = atoi(oo.c_str());
                            if (o <= 32 || o > 127)
                                std::cout << "Non displayable" << std::endl;
                            else
                                std::cout << "'" << static_cast<char>(o) << "'" << std::endl;

                        }
                    }
               
                break;
                case INT:
                   { int o;
                    std::cout << "int: " ;
                    o = atoi(oo.c_str());
                    if (o == 0 && oo[0] != '0')
                        std::cout << "impossible" << std::endl;
                    else
                        std::cout << o << std::endl;
                    break;}
                case FLOAT:
                   { std::cout << "float: ";
                    float f = strtof(oo.c_str(), NULL);
                    if (f == 0 && oo[0] != '0')
                        std::cout << "impossible" << std::endl;
                    else
                        {
                            if(f - static_cast<float>(f) == 0)
                            std:: cout << f << ".0f" << std::endl;
                         else
                            std::cout << f << "f" << std::endl;
                        }
                        }
                break;
                case DOUBLE :
                {
                    std::cout << "Double : ";
                    double d = strtod(oo.c_str(),NULL);
                    if (d == 0 && oo[0] != '0')
                        std::cout << "impossible" << std::endl;
                    else
                        {
                            if(d - static_cast<double>(d) == 0)
                            std:: cout << d << ".0" << std::endl;
                        else
                            std::cout << d  << std::endl;
                        }
                    }

                break;


            default:
                break;
            }
        }

}








ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &src)
    {
        *this = src;
    }
    return *this;
}



ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor called " << std::endl;
}

// Path: ex00/ScalarConverter.hpp




