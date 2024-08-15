
#include "Bureaucrat.hpp"

//######## Default Constructor ######## //
Bureaucrat::Bureaucrat() : name("default")
{
    this->grade = 150;
}


//######## getters and setters ######## //

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

//######## exceptions ######## //

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}


Bureaucrat::Bureaucrat(Bureaucrat const &copy) : name(copy.name)
{
    this->grade = copy.grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy)
{
    this->grade = copy.grade;
    return (*this);
}
/* destructor */

Bureaucrat::~Bureaucrat()
{
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (out);
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade = grade;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade--;
}

void Bureaucrat::incrementGrade()
{
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade++;
}