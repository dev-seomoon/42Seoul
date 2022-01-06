/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:45:23 by seomoon           #+#    #+#             */
/*   Updated: 2020/12/07 20:27:11 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_treat_pointer(unsigned long pointer, t_flags flags)
{
	int			char_count;
	int			len;
	char		*addr;

	pointer = (unsigned long)pointer;
	char_count = 0;
	if (pointer == 0 && flags.dot == 0)
	{
		if (flags.minus == 0)
			char_count += ft_treat_width(flags, 2, 0);
		char_count += ft_putchar('0') + ft_putchar('x');
		if (flags.minus == 1)
			char_count += ft_treat_width(flags, char_count, 0);
		return (char_count);
	}
	addr = convert_demical_to_hex(pointer, 'a');
	len = ft_strlen(addr);
	if (flags.minus == 0)
		char_count += ft_treat_width(flags, len + 2, 0);
	char_count += ft_putchar('0') + ft_putchar('x');
	char_count += ft_putstr(addr);
	if (flags.minus == 1)
		char_count += ft_treat_width(flags, len + 2, 0);
	return (char_count);
}
