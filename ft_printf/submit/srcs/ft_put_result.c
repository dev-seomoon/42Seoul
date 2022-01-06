/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:31:26 by seomoon           #+#    #+#             */
/*   Updated: 2020/12/07 20:06:09 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int		ft_putstr(char *str)
{
	int	char_count;

	char_count = 0;
	while (str[char_count])
	{
		ft_putchar(str[char_count]);
		char_count++;
	}
	free(str);
	return (char_count);
}

int		ft_putstr_len(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len && str[i])
		ft_putchar(str[i++]);
	return (i);
}

int		ft_put_int(char *str_num, t_flags flags, int zero)
{
	int	ch_count;
	int	len;

	len = ft_strlen(str_num);
	if (flags.minus == 1)
		ft_putstr(str_num);
	ch_count = ft_treat_width(flags, len, zero);
	if (flags.minus == 0)
		ft_putstr(str_num);
	return (ch_count + len);
}
