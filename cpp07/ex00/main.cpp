
#include "Whatever.hpp"

int main()
{
    int a = 2;
    int b = 3;

    std::cout << "a = " << a << " b = " << b << std::endl;
    swap(a, b);
    std::cout << "a = " << a << " b = " << b << std::endl;

    std::cout << "min(2, 3) = " << min(a, b) << std::endl;
    std::cout << "max(2, 3) = " << max(a, b) << std::endl;

    return 0;
}