/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:30:16 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/09 12:45:02 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int     main(void)
{
    std::string     str = "HI THIS IS BRAIN";
    std::string     *stringPTR = &str;
    std::string     &stringREF = str;
    
    // display address
    std::cout << &str << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    // display string
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
    return (0);
}