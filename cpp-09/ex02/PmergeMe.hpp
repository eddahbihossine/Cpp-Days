#ifndef PMERGE_ME_S
#define PMERGE_ME_S

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <exception>
#include <deque>

class PmergeMe {

    private:
        std::vector<int> numList;
        std::deque<int> numQueue;
        std::vector<std::pair<int, int> > res;
        int strugler;
    public:
        PmergeMe(int argc, char *argv[]);
        PmergeMe();
        PmergeMe(const PmergeMe &p);
        PmergeMe &operator=(const PmergeMe &p);
        bool isDigit(const std::string &str);
        bool check_sorted( const std::vector<int>& o);
        std::vector<int> generateJacobsthalSequence(int n) ;
        std::deque<int> generateJacobsthalSequenceD(int n) ;
        std::vector<std::pair<int, int> > pmerge( const std::vector<int>& numbers);
        std::deque<std::pair<int, int> > pmergew(const std::deque<int>& numbers);
        std::vector<int> get_numList();
        std::deque<int> get_numQueue();
        void print_list1(const std::deque<int>& o);
        void print_list2(const std::vector<int>& o);


        void set_strugler();
        int get_strugler();
        void sort_using_vector();
        void sort_using_deque();
        
        class NotANumber : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class BadParameters : public std::exception
        {
            public:
                const char *what() const throw();
        };
        class Sorted : public std::exception
        {
            public:
                const char *what() const throw();
        };
        
        ~PmergeMe();
};
#endif