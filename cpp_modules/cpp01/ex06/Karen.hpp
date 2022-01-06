/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:16:47 by seomoon           #+#    #+#             */
/*   Updated: 2021/08/12 15:22:33 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>

# define DEBUG 0
# define INFO 1
# define WARNING 2
# define ERROR 3
# define NUM_OF_LEVELS 4

class   Karen {
private:
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);

public:
    Karen(void);
    typedef void    (Karen::*func_ptr)(void);
    func_ptr    funcs[NUM_OF_LEVELS];
    std::string levels[NUM_OF_LEVELS];

    void    complain(std::string level);
};

#endif