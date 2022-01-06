/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:54:32 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/09 22:45:10 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon {
    private:
        std::string type;

    public:
        Weapon(void);
        Weapon(std::string type);
        void    setType(std::string type);
        const std::string   &getType(void);
};

#endif