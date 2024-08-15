
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() 
{
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name){
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}



FragTrap::FragTrap(const FragTrap& copy) 
{
    *this = copy;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy) {
    if (this != &copy) 
    {
        _name = copy._name;
        _hitPoints = copy._hitPoints;
        _energyPoints = copy._energyPoints;
        _attackDamage = copy._attackDamage;
    }
    return *this;
}

void FragTrap::highFivesGuys() 
{
    std::cout << "FragTrap " << _name << " is asking for high fives!" << std::endl;
}

