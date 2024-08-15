#include "Bureaucrat.hpp"

class unclear_params : public std::exception
{
    public:
        const char *what() const throw()
        {
            return ("Usage: ./a.out <grade>");
        }
};

void    err(int o)
{
    if(o != 2)
        throw unclear_params();
}

int main(int ac , char **av)
{
    
    
    try
    {
        err(ac);
        Bureaucrat b("bureaucrat", std::atoi(av[1]));
        std::cout << b<< std::endl;
        b.incrementGrade(); 
        std::cout << b<< std::endl;
        b.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}