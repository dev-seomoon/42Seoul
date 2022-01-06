/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:13:45 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/09 12:28:14 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int     main(void)
{
    Zombie  *horde = zombieHorde(5, "zombie");

    for (int i = 0; i < 5; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return (0);
}