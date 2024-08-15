/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:03:48 by heddahbi          #+#    #+#             */
/*   Updated: 2023/11/01 13:03:49 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>
class Zombie 
{
    private:
    std::string _name;
    public:
    Zombie(){
        
    }
    Zombie(std::string name);
    ~Zombie();
    void announce();
};

    Zombie *newZombie(std::string name);
    void randomChump(std::string name);

#endif