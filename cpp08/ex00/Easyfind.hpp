#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <exception>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::exception();
    }
    return it;
}

#endif // EASY_FIND_HPP