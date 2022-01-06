/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:16:28 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/09 12:24:02 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*     zombieHorde( int N, std::string name )
{
    Zombie  *zombieHorde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        zombieHorde[i].setName(name);
    }
    return (zombieHorde);
}