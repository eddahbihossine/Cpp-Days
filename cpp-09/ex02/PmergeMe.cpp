#include "PmergeMe.hpp"
// set up functions
bool PmergeMe::isDigit(const std::string &str) {
    size_t start = (str[0] == '-' && str[1]) ? 1 : 0;
    for (size_t i = start; i < str.length(); ++i) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}
void PmergeMe::set_strugler() 
{
    std::vector<int>::iterator it = this->numList.begin();
    if (this->numList.size() % 2 != 0) 
    {
        strugler = *it;
    }
	else
		strugler = 0;


}

// void PmergeMe::set_struggler2() 
// {
//     if (!this->numDeque.empty()) 
//     {
//         if (this->numDeque.size() % 2 != 0) 
//         {
//             this->struggler = this->numDeque.front();
//             this->numDeque.pop_front();
//         } 
//         else 
//         {
//             this->struggler = 0;
//         }
//     }
// }


int PmergeMe::get_strugler()
{
	return this->strugler;
}

PmergeMe::PmergeMe(int argc, char *argv[]) {
    if (argc <= 1)
        throw BadParameters();

    for (int i = 1; i < argc; i++) {
        std::string str = argv[i];
        if (!isDigit(str))
            throw NotANumber();

        int num = std::stoi(str);
        numList.push_back(num);
        numQueue.push_back(num);
    }

    if (this->check_sorted(numList))
        throw Sorted();
}

//destructor
PmergeMe::~PmergeMe() 
{
    numList.clear();
    numQueue.clear();
    res.clear();
    strugler = 0;

}
//copy constructor
PmergeMe::PmergeMe(const PmergeMe &p) 
{
    numList = p.numList;
    numQueue = p.numQueue;
    res = p.res;
    strugler = p.strugler;
}
//assignment operator
PmergeMe &PmergeMe::operator=(const PmergeMe &p) 
{
    if (this != &p) {
        numList = p.numList;
        numQueue = p.numQueue;
        res = p.res;
        strugler = p.strugler;
    }
    return *this;
}

std::vector<int> PmergeMe::get_numList() 
{
    return numList;
}

std::deque<int> PmergeMe::get_numQueue() 
{
    return numQueue;
}

const char *PmergeMe::NotANumber::what() const throw() 
{
    return "Not a number";
}

const char *PmergeMe::BadParameters::what() const throw() 
{
    return "Bad parameters";
}

const char *PmergeMe::Sorted::what() const throw() 
{
    return "Already sorted";
}

/*----------------------- vector -----------------*/


std::vector<int> PmergeMe::generateJacobsthalSequence(int n) {
    std::vector<int> jacob_numbers;
    int a = 0;
    int b = 1;
    int c;
    for (int i = 0; i <= n; i++) {
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
    if (n >= 2) {
     
        jacob_numbers.erase(jacob_numbers.begin());
        jacob_numbers.erase(jacob_numbers.begin());
    }
    if (b >= n)
        jacob_numbers.pop_back();
    jacob_numbers.push_back(n);
    return jacob_numbers;
}

std::deque<int> PmergeMe::generateJacobsthalSequenceD(int n) {
    std::deque<int> jacob_numbers;
    int a = 0;
    int b = 1;
    int c;
    for (int i = 0; i <= n; i++) {
        if (i == 0)
            jacob_numbers.push_back(a);
        else if (i == 1)
            jacob_numbers.push_back(b);
        else {
            c = a;
            a = b;
            b = (2 *c)+b; // Fixing the calculation of Jacobsthal sequence
            jacob_numbers.push_back(b);
        }
        if (b >= n)
            break;
    }
    if (n >= 2) {
        // Removing the first two elements
        jacob_numbers.pop_front();
        jacob_numbers.pop_front();
    }
    if (b >= n)
        jacob_numbers.pop_back();
    jacob_numbers.push_back(n);
    return jacob_numbers;
}



std::vector<std::pair<int, int> > PmergeMe::pmerge(const std::vector<int>& numbers) 
{
    std::vector<std::pair<int, int> > res;
    std::vector<int>::const_iterator it = numbers.begin();
        while (it != numbers.end()) {
            std::vector<int>::const_iterator next = it;
            ++next;
            if (next != numbers.end()) {
                if (*it > *next)
                    res.push_back(std::make_pair(*next, *it));
                else
                    res.push_back(std::make_pair(*it, *next));
                ++next;
            } 
            else 
                res.push_back(std::make_pair(*it, *it)); 
    
            it = next;
        }
        return res;
}


void PmergeMe::sort_using_vector() 
{
        std::cout << "Before sorting using vector: ";
        this->print_list2(this->get_numList());
        this->set_strugler();
        numList.erase(std::remove(numList.begin(), numList.end(), strugler), numList.end());
	    std::vector<std::pair<int, int> > pairs = this->pmerge(this->get_numList());
        std::vector<int> lkbar;
        std::vector<int> sghar;
		for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) 
		{
			lkbar.push_back(it->second);
			sghar.push_back(it->first);
		}
		if(sghar.front() > lkbar.front())
		{
			lkbar[0] = sghar[0];
			std::vector<int>::iterator it = sghar.begin();
			sghar.erase(it);
		}
        std::sort(lkbar.begin(), lkbar.end());
        std::vector<int> jacob_numbers = this->generateJacobsthalSequence(sghar.size());
        std::vector<int> index;
        for (std::vector<int>::iterator it = jacob_numbers.begin(); it != jacob_numbers.end(); it++) {
            int current = *it;
            index.push_back(current);
            for (int i = current - 1; i > 1; i--) 
			{
                if (std::find(index.begin(), index.end(), i) == index.end()) {
                    index.push_back(i);
                }
            }
        }
		lkbar.insert(std::lower_bound(lkbar.begin(), lkbar.end(), sghar[0]), sghar[0]);
        for (std::vector<int>::iterator it = index.begin(); it != index.end(); it++) 
		{
            if ((size_t)*it < sghar.size()) {
                int sgharIndex = *it;
                int sgharElement = sghar[sgharIndex];
                std::vector<int>::iterator insertPos = std::lower_bound(lkbar.begin(), lkbar.end(), sgharElement);
                lkbar.insert(insertPos, sgharElement);
            }
        }
        if (this->get_strugler() != 0)
            lkbar.insert(std::lower_bound(lkbar.begin(), lkbar.end(), strugler), strugler);
        std::cout << "After sorting using vector: ";
		this->print_list2(lkbar);
}


bool PmergeMe::check_sorted(const std::vector<int>& o) 
{
    std::vector<int>::const_iterator it = o.begin();
    while (it != std::prev(o.end())) {
        if (*it > *std::next(it))
            return false;
        it++;
    }
    return true;
}


void PmergeMe::print_list2(const std::vector<int>& o) 
{
	for (std::vector<int>::const_iterator it = o.begin(); it != o.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
}

/*----------------------- deque --------------------------*/


void PmergeMe::print_list1(const std::deque<int>& o) 
{
	for (std::deque<int>::const_iterator it = o.begin(); it != o.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
}






std::deque<std::pair<int, int> > PmergeMe::pmergew(const std::deque<int>& numbers) 
{
    std::deque<std::pair<int, int> > res;
    std::deque<int>::const_iterator it = numbers.begin();
        while (it != numbers.end()) {
            std::deque<int>::const_iterator next = it;
            ++next;
            if (next != numbers.end()) 
            {
                if (*it > *next)
                    res.push_back(std::make_pair(*next, *it));
                else
                    res.push_back(std::make_pair(*it, *next));
                ++next;
            } 
            else
                res.push_back(std::make_pair(*it, *it));     
            it = next;
        }
        return res;
}

void PmergeMe::sort_using_deque() 
{
    std::cout << "Before sorting using deque: ";
    this->print_list1(this->get_numQueue());
    this->set_strugler();
    this->numQueue.erase(std::remove(this->numQueue.begin(), this->numQueue.end(), this->strugler), this->numQueue.end());
    std::deque<std::pair<int, int> > pairs = this->pmergew(this->numQueue);
    std::deque<int> lkbar;
    std::deque<int> sghar;
    for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
        lkbar.push_back(it->second);
        sghar.push_back(it->first);
    }
    if (!sghar.empty() && !lkbar.empty() && sghar.front() > lkbar.front()) {
        lkbar[0] = sghar[0];
        sghar.pop_front();
    }
    std::sort(lkbar.begin(), lkbar.end());
    std::deque<int> jacob_numbers = generateJacobsthalSequenceD(sghar.size());
    std::deque<int> index;
    for (std::deque<int>::iterator it = jacob_numbers.begin(); it != jacob_numbers.end(); it++) {
        int current = *it;
        index.push_back(current);
        for (int i = current - 1; i > 1; i--) {
            if (std::find(index.begin(), index.end(), i) == index.end()) {
                index.push_back(i);
            }
        }
    }
    if (!sghar.empty())
        lkbar.insert(std::lower_bound(lkbar.begin(), lkbar.end(), sghar[0]), sghar[0]);
    for (std::deque<int>::iterator it = index.begin(); it != index.end(); it++) {
        if ((size_t)*it < sghar.size()) {
            int sgharIndex = *it;
            int sgharElement = sghar[sgharIndex];
            std::deque<int>::iterator insertPos = std::lower_bound(lkbar.begin(), lkbar.end(), sgharElement);
            lkbar.insert(insertPos, sgharElement);
        }
    }
    if (this->get_strugler() != 0)
        lkbar.insert(std::lower_bound(lkbar.begin(), lkbar.end(), strugler), strugler);
    std::cout << "After sorting using deque: ";
    this->print_list1(lkbar);
}