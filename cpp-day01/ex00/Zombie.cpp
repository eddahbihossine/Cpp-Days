/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 02:28:07 by macair            #+#    #+#             */
/*   Updated: 2023/10/25 04:37:58 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
}
Zombie::~Zombie()
{
    std::cout << this->_name << " is dead" << std::endl;
}
void Zombie::announce()
{
    std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie *newZombie(std::string name)
{
    Zombie *zombie = new Zombie(name);
    return zombie;
}
void randomChump(std::string name)
{
    Zombie ssss;
    ssss = Zombie(name);
    ssss.announce();
}
