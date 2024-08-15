#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"
class Form;

class Bureaucrat
{
    private:
        std::string const name;
        int grade;
    public:
        Bureaucrat();  
        Bureaucrat(std::string const name, int grade);
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        std::string getName() const;
        Bureaucrat(Bureaucrat const &copy);
        Bureaucrat &operator=(Bureaucrat const &copy);
        void SignForm(Form &f);
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        ~Bureaucrat();
};
std::ostream &operator<<(std::ostream &out, Bureaucrat const &b); 

#endif