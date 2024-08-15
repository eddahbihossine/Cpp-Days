#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{
    if (type.empty() )
        std::cout << "Weapon constructor called with empty string" << std::endl;
    else
    std::cout << "Weapon constructor called" << std::endl;
}

Weapon::~Weapon()
{
    std::cout << "Weapon destructor called" << std::endl;
}

std::string const &Weapon::getType() const
{
    return (this->type);
}

void Weapon::setType(std::string ptype)
{
  type = ptype;
}