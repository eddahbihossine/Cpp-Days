#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(std::string const target);
        ShrubberyCreationForm(ShrubberyCreationForm const &copy);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const &executor) const;
        std::string getTarget() const;
};