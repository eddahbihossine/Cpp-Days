#include "AForm.hpp"
#include "Bureaucrat.hpp"
class Bureaucrat;

//######## Default Constructor ######## //

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::AForm(std::string const name, int const gradeToSign, int const gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &copy) : name(copy.name), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{
    this->isSigned = copy.isSigned;
}

AForm &AForm::operator=(AForm const &copy)
{
    this->isSigned = copy.isSigned;
    return (*this);
}

std::string AForm::getName() const
{
    return (this->name);
}

//######## getters and setters ######## //

bool AForm::getIsSigned() const
{
    return (this->isSigned);
}

int AForm::getGradeToSign() const
{
    return (this->gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (this->gradeToExecute);
}


//######## exceptions ######## //

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}
const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    else
        this->isSigned = true;
}
/*ostream operator*/

std::ostream &operator<<(std::ostream &out, AForm const &f)
{
    out << f.getName() << ", AForm grade to sign " << f.getGradeToSign() << ", AForm grade to execute " << f.getGradeToExecute() << ", is signed " << f.getIsSigned() << std::endl;
    return (out);
}

/* destructor */

AForm::~AForm()
{
}


void AForm::action() const
{
    std::cout << "AForm " << this->name << " is being executed" << std::endl;

}
void AForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->gradeToExecute)
        throw AForm::GradeTooLowException();
    else if(executor.getGrade() < this->getGradeToExecute())
        throw AForm::GradeTooHighException();
    else if (!this->isSigned)
        throw AForm::FormNotSignedException();
    else
        this->action();
}