#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <exception>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack &src) : std::stack<T>(src) {}
        MutantStack &operator=(const MutantStack &src) { std::stack<T>::operator=(src); return *this; }
        virtual ~MutantStack() {}

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin() { return std::stack<T>::c.begin(); }
        iterator end() { return std::stack<T>::c.end(); }
};
#endif // MUTANTSTACK_HPP