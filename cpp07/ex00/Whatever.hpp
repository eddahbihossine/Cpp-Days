#ifndef WHAT_EVER_HPP
#define WHAT_EVER_HPP
#include  <iostream>

//template to swap two values

template <typename T>void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}


//template to compare two values

template <typename T>
T min(T a, T b)
{
    return (a < b) ? a : b;
}

//template to compare two values

template <typename T>

T max(T a, T b)
{
    return (a > b) ? a : b;
}
#endif