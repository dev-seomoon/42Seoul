/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:59:23 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/04 18:34:51 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    bool            run;
    std::string     cmd;
    PhoneBook       phonebook;

    run = true;
    while (run)
    {
        std::cin >> cmd;
        // == op -> .compare()와 비슷하게 동작 (연산자 오버로딩)
        if (cmd == "ADD")
            phonebook.add_contact();
        else if (cmd == "SEARCH")
            phonebook.search_contact();
        else if (cmd == "EXIT")
            run = false;
    }
    return (0);
}