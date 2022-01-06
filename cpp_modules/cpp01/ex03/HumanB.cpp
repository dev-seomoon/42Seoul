/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:12:10 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/11 17:22:23 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name)
{
}

void    HumanB::attack(void)
{
    std::cout << this->name << " attacks with his ";
    std::cout << this->getWeapon()->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

Weapon  *HumanB::getWeapon(void)
{
    return (this->weapon);
}