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
int main(int ac , char **av)
{
	Harl harl;
	if (ac == 2)
		harl.complain(av[1]);
	else
		std::cout << "Wrong number of arguments" << std::endl;
	return 0;
	
}