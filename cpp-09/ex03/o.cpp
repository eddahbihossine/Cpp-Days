#include <iostream>
#include <string>
#include <vector>
#include <deque>
std::deque<int> generateJacobsthalSequenceD(int n) 
{
    std::deque<int> jacob_numbers;
    int a = 0;
    int b = 1;
    int c = 0;
    for (int i = 0; i <= n; i++) 
    {
        if (i == 0)
            jacob_numbers.push_back(a);
        else if (i == 1)
            jacob_numbers.push_back(b);
        else 
        {
            c = a;
            a = b;
            b = (2 * c) + b;
            jacob_numbers.push_back(b);
        }
        if (b >= n)
            break;
    }
   if(n >= 2)
    {
        jacob_numbers.pop_front();
        jacob_numbers.pop_front();
    }

    if (b >= n)
        jacob_numbers.pop_back();
    jacob_numbers.push_back(n);
    return jacob_numbers;
}

int main()
{
    std::deque<int> jacob_numbers = generateJacobsthalSequenceD(10);
    for (auto i : jacob_numbers)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
