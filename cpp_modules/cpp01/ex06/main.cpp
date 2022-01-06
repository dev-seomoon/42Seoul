/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:16:54 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/12 15:30:27 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int     main(int argc, char **args)
{
    Karen   karen;
    if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return (1);
    }
    karen.complain(args[1]);
    return (0);
}