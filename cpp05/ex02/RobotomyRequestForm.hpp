#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP


#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(std::string const target);
        RobotomyRequestForm(RobotomyRequestForm const &copy);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);
        ~RobotomyRequestForm();
        //getters
        std::string getTarget() const;
        // setters
        void setTarget(std::string &target);
        //member functions
        void execute(Bureaucrat const &executor) const;
};
#endif