#include "PresidentialPardonForm.hpp"

//default constructor
PresidentialPardonForm ::PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm",25,5)
{
	this->target = target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
 // inform the target that he has been pardonned
	try
	{
		std::cout << executor.getName() << "  has been  pardonned  by Zaphod Beeblbrox" << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return ;
	
}
//default destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called"<< std::endl;

}


PresidentialPardonForm PresidentialPardonForm::operator=(const PresidentialPardonForm &o)
{
	// i don't want to copy anything for the moment 
	this->target = o.target;
	return(*this);
}