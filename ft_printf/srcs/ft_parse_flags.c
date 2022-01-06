/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:47:29 by seomoon           #+#    #+#             */
/*   Updated: 2020/11/24 21:12:41 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_init_flags(void)
{
	t_flags	flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int			ft_istype(int c)
{
	if ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'))
		return (1);
	else
		return (0);
}

int			ft_isflag(int c)
{
	if ((c == '-') || (c == '0') || (c == '.') || (c == '*'))
		return (1);
	else
		return (0);
}

int			ft_flag_parse(const char *save, int i, t_flags *flags, va_list args)
{
	while (save[i] != '\0')
	{
		if (!ft_isdigit(save[i]) && !ft_istype(save[i]) && !ft_isflag(save[i]))
			break ;
		else if (save[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		else if (save[i] == '.')
			i = ft_flag_dot(save, i, flags, args);
		else if (save[i] == '-')
			*flags = ft_flag_minus(*flags);
		else if (save[i] == '*')
			*flags = ft_flag_width(args, *flags);
		else if (ft_isdigit(save[i]))
			*flags = ft_flag_digit(save[i], *flags);
		if (ft_istype(save[i]))
		{
			flags->type = save[i];
			break ;
		}
		i++;
	}
	return (i);
}
