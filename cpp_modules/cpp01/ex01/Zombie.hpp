/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:14:22 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/09 12:26:43 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
    private:
        std::string  name;

    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);
        void        announce(void);
        void        setName(std::string name);
        std::string getName(void);
};

Zombie*     zombieHorde( int N, std::string name );

#endif