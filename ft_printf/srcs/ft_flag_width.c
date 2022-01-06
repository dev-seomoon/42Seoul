/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:28:11 by seomoon           #+#    #+#             */
/*   Updated: 2020/11/24 21:07:06 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_treat_width(t_flags flags, int strlen, int zero)
{
	int			char_count;
	int			print_width;

	char_count = 0;
	print_width = flags.width - strlen;
	while (print_width > 0)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		print_width--;
		char_count++;
	}
	return (char_count);
}
