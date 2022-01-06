/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:18:30 by seomoon           #+#    #+#             */
/*   Updated: 2020/12/08 23:35:39 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_treat_save(char *save, va_list args)
{
	int			i;
	int			char_count;
	t_flags		flags;

	i = -1;
	char_count = 0;
	while (save[++i] != '\0')
	{
		flags = ft_init_flags();
		if (save[i] == '%' && save[i + 1] != '\0')
			while (save[i] != '\0')
			{
				i = ft_flag_parse(save, ++i, &flags, args);
				if (ft_istype(save[i]))
				{
					char_count += ft_treat_type(save[i], flags, args);
					break ;
				}
				else
					char_count += ft_putchar(save[i]);
			}
		else if (save[i] != '%')
			char_count += ft_putchar(save[i]);
	}
	return (char_count);
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	int			char_count;
	char		*save;

	char_count = 0;
	save = ft_strdup(format);
	va_start(args, format);
	char_count = ft_treat_save(save, args);
	va_end(args);
	free(save);
	return (char_count);
}
