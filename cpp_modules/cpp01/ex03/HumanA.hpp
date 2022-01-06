/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:08:13 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/11 17:17:07 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA {
    private:
        std::string name;
        Weapon &weapon;
        
    public:
        HumanA(std::string name, Weapon &weapon);
        void    attack(void);
};

#endif