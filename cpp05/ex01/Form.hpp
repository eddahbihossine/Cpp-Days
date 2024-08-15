#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form  
{
    private :
        std::string const name;
        bool isSigned;
        int const gradeToSign;
        int const gradeToExecute;
    public :
    Form();
    Form(std::string const name, int const gradeToSign, int const gradeToExecute);
    Form(Form const &copy);
    Form &operator=(Form const &copy);
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
    ~Form();
};

std::ostream &operator<<(std::ostream &out, Form const &f);
#endif