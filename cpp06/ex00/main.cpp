#include "ScalarConverter.hpp"
int main(int ac ,char **av)
{
	if(ac != 2)
		return 12;
	ScalarConverter::convert(av[1]);
	std::cout << "\n";
	return 0;
}