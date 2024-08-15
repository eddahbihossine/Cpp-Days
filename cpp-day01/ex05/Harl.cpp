#include "Harl.hpp"
void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}
void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enoughbacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning()
{
	std::cout << " I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::complain(std::string level) 
{
	std::string p[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*ptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
		switch(before_main(level, p))
		{
			case 0:
				(this->*ptr[0])();
				break;
			case 1:
				(this->*ptr[1])();
				break;
			case 2:
				(this->*ptr[2])();
				break;
			case 3:
				(this->*ptr[3])();
				break;
			default:
				std::cout << "Wrong argument" << std::endl;
			break;
	}
	
}