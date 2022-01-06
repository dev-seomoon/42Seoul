/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:16:05 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/06 12:10:58 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>

class   Contact {

    private:

        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

    public:

        void    set_first_name(std::string str);
        void    set_last_name(std::string str);
        void    set_nickname(std::string str);
        void    set_phone_number(std::string str);
        void    set_darkest_secret(std::string str);
        void    display_contact_summary(int index);
        void    display_contact(int index);

        std::string get_first_name();
        std::string get_last_name();
        std::string get_nickname();
        std::string get_phone_number();
        std::string get_darkest_secret();
};

class   PhoneBook {

    private:

        int     index;
        int     count;
        int     current;
        Contact contacts[8];

    public:
    
        PhoneBook(); //생성자

        void    add_contact(void);
        void    search_contact(void);
        int     get_index(void);
        void    increase_index(void);
};

#endif