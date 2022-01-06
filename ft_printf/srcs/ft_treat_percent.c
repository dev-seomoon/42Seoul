/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:01:05 by seomoon           #+#    #+#             */
/*   Updated: 2020/11/29 21:10:37 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_treat_percent(t_flags flags)
{
	int			char_count;

	if (flags.minus == 0)
		char_count = ft_treat_width(flags, 1, flags.zero);
	ft_putchar('%');
	if (flags.minus == 1)
		char_count = ft_treat_width(flags, 1, 0);
	return (char_count + 1);
}
