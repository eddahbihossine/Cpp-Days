
#include "Harl.hpp"
void Harl::debug()
{
	std::cout << "[ DEBUG ]" << "\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}
void Harl::info()
{
	std::cout << "[ INFO ]" << "\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enoughbacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}
void Harl::warning()
{
	std::cout << "[ WARNING ]" << "\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}
void Harl::error()
{
	std::cout << "[ ERROR ]" << "\n";
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}