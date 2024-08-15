#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        std::vector<int> v;
        v.push_back(9);
        sp.addNumbers(v.begin(), v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // try
    // {
    Span sp = Span(100000);
    std::vector<int> v;
    
    // for (int i = 0; i <= 10000; i++)
    // {
    //     v.push_back(i);
    // }
    
    sp.addNumbers(v.begin(), v.end());


    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // return 0;

}


