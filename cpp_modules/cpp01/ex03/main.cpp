/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:53:45 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/11 17:22:29 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int     main(void)
{

    /*
    Weapon  club = Weapon("crude spiked club");

    HumanA  bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();

   */
   Weapon   club = Weapon("crude spiked club");
   
   HumanB   jim("Jim");
   jim.setWeapon(club);
   jim.attack();
   club.setType("some other type of club");
   jim.attack();

    return (0);
}