#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "AForm.hpp"

class Intern
{
    // public attributes
    public :
    
    //canonical form
    Intern(){}; /* default constructor */
    Intern(const Intern &p); /*copy constructor*/
    Intern operator=(const Intern &o); /*copy assignement operator*/
    ~Intern(){}; /* destructor */
    /* member function */
    AForm *makeForm(std::string name ,std::string target)
    {
         std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for(int i =0; i < 3; i++)
    {
        switch (i)
        {
            case 0:
                if(name == formNames[i])
                {
                    std::cout << "Intern creates " << name << std::endl;
                    return (new ShrubberyCreationForm(target));
                }

                break;
            case 1:
                if(name == formNames[i])
                {
                    std::cout << "Intern creates " << name << std::endl;
                    return (new RobotomyRequestForm(target));
                }
                break;

            case 2:
                if(name == formNames[i])
                {
                    std::cout << "Intern creates " << name << std::endl;
                    return (new PresidentialPardonForm(target));
                }
                break;
        
        default:
            break;
        }
    }
    return 0;
    }
};


#endif