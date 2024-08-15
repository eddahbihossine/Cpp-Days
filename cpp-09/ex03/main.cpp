
#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <exception>

int main(int argc, char *argv[]) {
    try {

        PmergeMe pmergeMe(argc, argv);
        size_t size = pmergeMe.get_numQueue().size();
        clock_t start_deque = clock();
        pmergeMe.sort_using_deque();

        clock_t end_deque = clock();
        double duration_deque = (double)(end_deque - start_deque) / CLOCKS_PER_SEC * 1000000;
        std::cout << "Time to process a range of " << size <<" elements with std::deque : " << duration_deque << " microseconds" << std::endl;
        std::cout << "----------------" << std::endl;

        clock_t start_vector = clock();
        pmergeMe.sort_using_vector();
        clock_t end_vector = clock();
        double duration_vector = (double)(end_vector - start_vector) / CLOCKS_PER_SEC * 1000000; 
        std::cout << "Time to process a range of " << size <<" elements with std::vector : " << duration_vector << " microseconds" << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
