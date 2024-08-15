#include "Form.hpp"
#include "Bureaucrat.hpp"
class Bureaucrat;

//######## Default Constructor ######## //

Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

Form::Form(std::string const name, int const gradeToSign, int const gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &copy) : name(copy.name), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{
    this->isSigned = copy.isSigned;
}

Form &Form::operator=(Form const &copy)
{
    this->isSigned = copy.isSigned;
    return (*this);
}

std::string Form::getName() const
{
    return (this->name);
}

//######## getters and setters ######## //

bool Form::getIsSigned() const
{
    return (this->isSigned);
}

int Form::getGradeToSign() const
{
    return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (this->gradeToExecute);
}


//######## exceptions ######## //

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    else
        this->isSigned = true;
}
/*ostream operator*/

std::ostream &operator<<(std::ostream &out, Form const &f)
{
    out << f.getName() << ", form grade to sign " << f.getGradeToSign() << ", form grade to execute " << f.getGradeToExecute() << ", is signed " << f.getIsSigned() << std::endl;
    return (out);
}

/* destructor */

Form::~Form()
{
}