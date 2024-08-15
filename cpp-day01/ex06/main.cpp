#include "Harl.hpp"
int before_main(std:: string str, std::string p[4])
{
	int i = 0;
	while (i < 4)
	{
		switch(str.compare(p[i]))
		{
			case 0:
				return i;
		}
		i++;
	}
	return -1;
}
void Harl::complain(std::string level) 
{

	std::string p[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*ptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
		switch(before_main(level, p))
		{
			case 0:
				(this->*ptr[0])();
			case 1:
				(this->*ptr[1])();
			
			case 2:
				(this->*ptr[2])();
			case 3:
			{
				(this->*ptr[3])();
				break;
			}
			default:
				std::cout << "Probably complaining about insignificant problems"<< std::endl;
			break;
		}
	
}

int main(int ac , char **av)
{
	Harl harl;
	if (ac == 2)
		harl.complain(av[1]);
	else
		std::cout << "Wrong number of arguments" << std::endl;
	return 0;
	
}