#include "HumanB.hpp"

HumanB::HumanB(std::string _name) : name(_name)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    if(this->weapon == NULL)
        std::cout << this->name << " attacks with his bare hands" << std::endl;
    else if(this->weapon != NULL)
        std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
