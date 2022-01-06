/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:11:55 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/11 17:22:04 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB {
    private:
        std::string name;
        Weapon *weapon;

    public:
        HumanB(std::string name);
        void    attack(void);
        void    setWeapon(Weapon &weapon);
        Weapon  *getWeapon(void);
};

#endif