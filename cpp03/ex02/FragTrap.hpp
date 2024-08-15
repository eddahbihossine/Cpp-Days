#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public  ClapTrap
{

    public :
        //orthodox form
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& copy);
        ~FragTrap();
        FragTrap& operator=(const FragTrap& copy);
        //member functions
        void highFivesGuys(void);

};


#endif //FRAGTRAP_HPP