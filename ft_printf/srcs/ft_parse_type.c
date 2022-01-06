/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:30:32 by seomoon           #+#    #+#             */
/*   Updated: 2020/11/23 22:30:52 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_treat_type(char c, t_flags flags, va_list args)
{
	int			char_count;

	char_count = 0;
	if (c == 'c')
		char_count += ft_treat_char(va_arg(args, int), flags);
	else if (c == 's')
		char_count += ft_treat_string(va_arg(args, char *), flags);
	else if (c == 'd' || c == 'i')
		char_count += ft_treat_int(va_arg(args, int), flags);
	else if (c == 'p')
		char_count += ft_treat_pointer(va_arg(args, unsigned long), flags);
	else if (c == 'u')
		char_count += ft_treat_unint(va_arg(args, int), flags);
	else if (c == 'x')
		char_count += ft_treat_hex(va_arg(args, int), flags, 'a');
	else if (c == 'X')
		char_count += ft_treat_hex(va_arg(args, int), flags, 'A');
	else if (c == '%')
		char_count += ft_treat_percent(flags);
	return (char_count);
}
