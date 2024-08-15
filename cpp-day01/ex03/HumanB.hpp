#include "Weapon.hpp"

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>

class HumanB
{
    private:
        std::string name;
        Weapon *weapon;
    public:
        HumanB(std::string _name);
        ~HumanB();
        void attack();
        void setWeapon(Weapon &weapon);
};

#endif // HUMANB_HPP
