#include "RobotomyRequestForm.hpp"
#include <fstream>

//######## parametrized Constructor ######## //

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45)
{
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy)
{
    this->target = copy.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
    this->target = copy.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    this->target = "default";
}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << "Bzzzzzzzz" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << this->target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->target << " robotomization failed because of a bad luck" << std::endl;
}

//######## getters and setters ######## //


std::string RobotomyRequestForm::getTarget() const
{
    return (this->target);
}

void RobotomyRequestForm::setTarget(std::string &target)
{
    this->target = target;
}



//######## exceptions ######## //

