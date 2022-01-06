/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:20:19 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/09 12:26:17 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void): name("Anonymous")
{
}

Zombie::Zombie(std::string name): name(name)
{
    std::cout << "Zombie <" << Zombie::getName() << "> is Born. \n";
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie <" << Zombie::getName() << "> is Died. \n";
}

void    Zombie::announce(void)
{
    std::cout << "<" << Zombie::getName() << "> BraiiiiiiinnnzzzZ...\n";
}

void    Zombie::setName(std::string name)
{
    this->name = name;
}

std::string     Zombie::getName(void)
{
    return (this->name);
}