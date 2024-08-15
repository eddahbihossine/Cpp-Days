#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm  
{
    private :
        std::string const name;
        bool isSigned;
        int const gradeToSign;
        int const gradeToExecute;
    public :
    AForm();
    AForm(std::string const name, int const gradeToSign, int const gradeToExecute);
    AForm(AForm const &copy);
    AForm &operator=(AForm const &copy);
    std::string getName() const;
    //getters
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    //setters
    void beSigned(Bureaucrat &b);
    class GradeTooHighException : public std::exception
    {
        public :
            const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public :
            const char *what() const throw();
    };
    class FormNotSignedException : public std::exception
    {
        public :
            const char *what() const throw();
    };
    virtual void execute(Bureaucrat const &executor) const = 0;
    void action() const;
    virtual ~AForm();
};

std::ostream &operator<<(std::ostream &out, AForm const &f);
#endif