/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:54:21 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/09 22:45:13 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
}

Weapon::Weapon(std::string type): type(type)
{
}

void    Weapon::setType(std::string type)
{
    this->type = type;
}

const std::string   &Weapon::getType(void)
{
    const std::string &typeREF = this->type;
    return (typeREF);
}
