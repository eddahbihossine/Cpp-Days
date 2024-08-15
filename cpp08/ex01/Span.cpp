#include "Span.hpp"

Span::Span() : n(0) {}

Span::Span(unsigned int n)  {
    if (n == 0)
        throw std::exception();

    else
        this->n = n;
    

}

Span::Span(const Span &src) {
    *this = src;
}

Span &Span::operator=(const Span &src) {
    if (this != &src)
        this->n = src.n;
    return *this;
}


Span::~Span() {}

void Span::addNumber(int number) 
{
    if (v.size() + 1 > n)
        throw Span::FullException();
    v.push_back(number);
}
void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) 
{
    if (v.size() + std::distance(begin, end) > n)
        throw Span::FullException();
    v.insert(v.end(), begin, end);
}
void Span::print() 
{
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) 
    {
        std::cout << *it << std::endl;
    }
}
const char* Span::FullException::what() const throw() {
    return "The container is full";
}

const char* Span::NoSpanException::what() const throw() {
    return "There is no span to find";
}
int Span::shortestSpan() 
{
    if (v.size() < 2)
        throw Span::NoSpanException();
    int min = INT_MAX;
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) 
    {
        for (std::vector<int>::iterator it2 = it + 1; it2 != v.end(); it2++) 
        {
            int diff = *it - *it2;
            if (diff < 0)
                diff *= -1;
            if (diff < min)
                min = diff;
        }
    }
    return min;

}

int Span::longestSpan() 
{
    if (v.size() < 2)
        throw std::exception();
    int min = INT_MAX;
    int max = INT_MIN;
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) 
    {
        if (*it < min)
            min = *it;
        if (*it > max)
            max = *it;
    }
    return max - min;
}