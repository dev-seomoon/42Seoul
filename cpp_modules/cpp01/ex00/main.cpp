/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:33:32 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/09 12:08:01 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int     main(void)
{
    Zombie  *one;
    Zombie  *two;

    one = newZombie("Robert");
    two = newZombie("Emma");
    one->announce();
    two->announce();
    randomChump("Jennifer");
    delete one;
    delete two;
    return (0);
}