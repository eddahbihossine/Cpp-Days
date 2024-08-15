#include "Easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    try
    {
        std::cout << *easyfind(v, 2) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }

    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    try
    {
        std::cout << *easyfind(l, 2) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }
    return 0;
}