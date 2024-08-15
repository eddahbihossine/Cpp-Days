#ifndef PRESIDENTIAL_FORM_HPP
#define PRESIDENTIAL_FORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private :
        //default constructor
        std::string target;
        PresidentialPardonForm();
    public :

    //member functions
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm operator=(const PresidentialPardonForm &o);
    void execute(Bureaucrat const &executor) const;

    // destructor
    ~PresidentialPardonForm();

};

#endif