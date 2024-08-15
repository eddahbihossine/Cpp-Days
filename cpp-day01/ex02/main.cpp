#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *ptr = &str;
    std::string &ref = str;
    std::cout << "address of str : " << &str << std::endl;
    std::cout << "address of ptr : " << ptr << std::endl;
    std::cout << "address of ref : " << &ref << std::endl;
    std::cout << "------------------"<< std::endl;
    std::cout << "str : " << str << std::endl;
    std::cout << "ptr : " << *ptr << std::endl;
    std::cout << "ref : " << ref << std::endl;

    return (0);
}