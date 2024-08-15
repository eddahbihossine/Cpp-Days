/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:03:35 by heddahbi          #+#    #+#             */
/*   Updated: 2023/11/01 13:03:36 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Zombie.hpp"

int main()
{
    Zombie *zombie =NULL;
    zombie = newZombie("Zombie1");
    randomChump("Zombie2");
    delete zombie;

}