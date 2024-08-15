#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <exception>
#include <vector>

class Span{

    private:
    unsigned int n;
    std::vector<int> v;
    public :
    //constructor
        Span();
    //destructor
        ~Span();
    //parameterized constructor
        Span(unsigned int n);
    //copy constructor
        Span(const Span &src);
    //assignment operator
        Span &operator=(const Span &src);
    //add number
        void addNumber(int n);
    //shortest span
        int shortestSpan();
    //longest span
        int longestSpan();
    //exception class
        class FullException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class NoSpanException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
    void print();
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

};

#endif