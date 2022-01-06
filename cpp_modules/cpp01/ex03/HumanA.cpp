/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:07:55 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/11 17:17:20 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): 
    name(name), weapon(weapon)
{
}

void    HumanA::attack(void)
{
    std::cout << this->name << " attacks with his ";
    std::cout << this->weapon.getType() << std::endl;
}