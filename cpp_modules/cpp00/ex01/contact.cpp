/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:03:06 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/05 20:38:12 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void    Contact::display_contact_summary(int index)
{
    std::string col[3] = {this->first_name, this->last_name, this->nickname};
    std::cout << "|" << std::setw(10) << std::right << index;
    for (int i = 0; i < 3; i++) {
        std::cout << "|";
        if (col[i].length() > 10)
            std::cout << col[i].substr(0, 9) << ".";
        else
            std::cout << std::setw(10) << std::right << col[i];
    }
    std::cout << "|\n";
}

void    Contact::display_contact(int index)
{
    std::cout << "Contact " << index << "\n";
    std::cout << "first name: " << this->first_name << "\n";
    std::cout << "last name: " << this->last_name << "\n";
    std::cout << "nickname: " << this->nickname << "\n";
    std::cout << "phone number: " << this->phone_number << "\n";
    std::cout << "darkest secret: " << this->darkest_secret << "\n";
}

std::string    Contact::get_first_name(void)
{
    return (this->first_name);
}

std::string    Contact::get_last_name(void)
{
    return (this->last_name);
}

std::string    Contact::get_nickname(void)
{
    return (this->nickname);
}

std::string    Contact::get_phone_number(void)
{
    return (this->phone_number);
}

std::string    Contact::get_darkest_secret(void)
{
    return (this->darkest_secret);
}

void    Contact::set_first_name(std::string str)
{
    this->first_name = str;
    return ;
}

void    Contact::set_last_name(std::string str)
{
    this->last_name = str;
    return ;
}

void    Contact::set_nickname(std::string str)
{
    this->nickname = str;
    return ;
}

void    Contact::set_phone_number(std::string str)
{
    this->phone_number = str;
    return ;
}

void    Contact::set_darkest_secret(std::string str)
{
    this->darkest_secret = str;
    return ;
}