#include "BitcoinExchange.hpp"
int main(int ac , char **av)
{
    (void)ac;
    (void)av;
    try
    {
        BitcoinExchange exchange(av[1]);
        exchange.readData(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;   
}