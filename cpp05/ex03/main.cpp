#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
void leaks()
{
    system("leaks ex03");
} 
int main(int ac , char **av)
{
    std::atexit(leaks);
    if (ac != 2)
    {
        std::cout << "Usage: ./ex02 [filename]" << std::endl;
        return (1);
    }
    try
    {
        Intern hh;
        AForm *hl;

        hl  = hh.makeForm("robotomy request","ll");
        delete hl;

        {
            //shrubbery creation form scope
            Bureaucrat b("hamid",137);
            ShrubberyCreationForm i(av[1]);
            b.SignForm(i);
            b.executeForm(i);
        
        }
        {
            //robotomy request form 
            Bureaucrat b2("mohmad",45);
            RobotomyRequestForm o("mohmad");
            b2.SignForm(o);
            b2.executeForm(o);
        }
        {
            // Presidential Pardon Form
            Bureaucrat b3("samir",22);
            PresidentialPardonForm a("samir");
            b3.SignForm(a);
            b3.executeForm(a);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    return (0);
}