#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &weapon) :name(_name), weapon(weapon) 
{
    std::cout << "HumanA constructor called" << std::endl;
    name = _name;
    std::cout << "HumanA weapon: " << this->weapon.getType() << std::endl;
}
HumanA::~HumanA()
{
    std::cout << "HumanA dies" << std::endl;
}
void HumanA::attack()
{
    std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}

