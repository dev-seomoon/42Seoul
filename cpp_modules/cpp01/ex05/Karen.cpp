/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:08:07 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/12 15:14:26 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void)
{
    funcs[DEBUG] = &Karen::debug;
    funcs[INFO] = &Karen::info;
    funcs[WARNING] = &Karen::warning;
    funcs[ERROR] = &Karen::error;

    levels[DEBUG] = "DEBUG";
    levels[INFO] = "INFO";
    levels[WARNING] = "WARNING";
    levels[ERROR] = "ERROR";
}

void    Karen::debug(void)
{
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void    Karen::info(void)
{
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void    Karen::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void    Karen::error(void)
{
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void    Karen::complain(std::string level)
{
    for (int i = 0; i < NUM_OF_LEVELS; i++) {
        if (levels[i] == level) {
            (this->*funcs[i])();
            break;
        }
    }
}