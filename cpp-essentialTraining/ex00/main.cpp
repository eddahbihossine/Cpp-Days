#include <iostream>
#include <list>
#include <string>
 

int main(int ac , char **av)
{
	if(ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return (0);
	}
	else
	{
		for (int i = 1; i < ac; i++)
		{
			std::string str = av[i];
			for (int j = 0; j < (int)str.size(); j++)
				str[j] = std::toupper(str[j]);
			std::cout << str ;
		}
	}
	std::cout << std::endl;
	return (0);

}

	