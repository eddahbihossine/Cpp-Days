#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int N,std::string name)
{
    Zombie *zombie = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombie[i].setName(name);
    }
    return zombie;
}
void Zombie::setName(std::string name)
{
    this->_name = name;
}
void ::Zombie::announce()
{
    std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie::Zombie()
{
    
}
Zombie::~Zombie()
{
    std::cout << this->_name << " is dead" << std::endl;
}