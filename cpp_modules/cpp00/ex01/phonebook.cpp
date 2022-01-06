/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:37:51 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/06 12:12:55 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip> // i/o formatting

PhoneBook::PhoneBook(void)
{
    this->index = 0;
    this->current = 0;
    this->count = 0;
    return ;
}

void    PhoneBook::add_contact(void)
{
    std::string     input;
    Contact         *contact;

    this->current = this->count % 8;
    contact = &this->contacts[this->current];

    std::cout << "first name : ";
    std::cin >> input;
    contact->set_first_name(input);

    std::cout << "last name : ";
    std::cin >> input;
    contact->set_last_name(input);

    std::cout << "nickname : ";
    std::cin >> input;
    contact->set_nickname(input);

    std::cout << "phone number : ";
    std::cin >> input;
    contact->set_phone_number(input);

    std::cout << "darkest secret : ";
    std::cin >> input;
    contact->set_darkest_secret(input);
    
    this->count++;
    if (this->index < 8)
        this->index++;
    std::cout << "A Contact added. \n";
    
    return;
}

bool    isInteger(std::string str)
{
    int length;

    length = str.length();
    for (int i = 0; i < length; i++) {
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

void    PhoneBook::search_contact(void)
{
    int             index;
    bool            isIndexValid;
    std::string     input;

    if (this->index == 0)
    {
        std::cout << "No Contact. \n";
        return ;
    }
    for (int i = 0; i < this->index; i++) {
        this->contacts[i].display_contact_summary(i);
    }
    std::cout << "Enter index to display a contact informations. \n";
    isIndexValid = false;
    while (!isIndexValid)
    {
        std::cout << "Index: ";
        std::cin >> input;
        if (!isInteger(input)) {
            std::cout << "Invalid index. \n";
            continue ;
        }
        else
            index = std::stoi(input);
        if (index >= 0 && index < this->index)
            isIndexValid = true;
        else
            std::cout << "Invalid index. \n";
    }
    this->contacts[index].display_contact(index);
}