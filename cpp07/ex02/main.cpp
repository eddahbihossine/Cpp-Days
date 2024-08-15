#include <iostream>
/*class template */
template <typename T>
class Array
{
    public:
        Array() : _array(NULL), _size(0) {}
        Array(unsigned int n) : _array(new T[n]), _size(n) {}
        ~Array() { delete[] _array; }
        T &operator[](unsigned int i) { return _array[i]; }
        unsigned int size() const { return _size; }
    private:
        T *_array;
        unsigned int _size;
};
/* template that iterate on the string */

template <typename T>

void iter(Array<T> &array, size_t length, void (*f)(T const &))
{
    for (size_t i = 0; i < length; i++)
    {
        f(array[i]);
    }
}

void l(int const &a)
{
    int o  = a +32;
    std::cout << o << std::endl;
}

int main()
{
    Array<int> array(5);
    for (unsigned int i = 0; i < array.size(); i++)
    {
        array[i] = i;
    }
    iter(array, 5, l);
    return 0;
}