/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:16:07 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/09 12:26:11 by seomoon          ###   ########.fr       */
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

Zombie*     newZombie(std::string name);
void        randomChump(std::string name);

#endif