#include <iostream>
/* template that iterate on the string */
template <typename T>

void iter(T *array, size_t length, void (*f)(T const &))
{
    for (size_t i = 0; i < length; i++)
    {
        f(array[i]);
    }
} 

void f(int const &a)
{
    int o  = a + 32;
    std::cout << o << std::endl;
}




int main()
{
    int array[] = {1, 2, 3, 4, 5};
    iter(array, 5, f);
    return 0;

}