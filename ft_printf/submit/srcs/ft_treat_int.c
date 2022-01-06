/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:42:33 by seomoon           #+#    #+#             */
/*   Updated: 2020/12/07 19:40:26 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_treat_int(int n, t_flags flags)
{
	int			ch_count;
	char		*str_num;

	if (flags.dot == 0 && n == 0)
		return (ft_treat_width(flags, 0, 0));
	if (flags.dot >= 0)
	{
		str_num = ft_treat_precision(n, flags.dot);
		return (ft_put_int(str_num, flags, 0));
	}
	if (n < 0 && flags.minus == 0 && flags.zero)
	{
		ch_count = ft_putchar('-');
		str_num = ft_itoa_u(n * -1);
		ch_count += ft_treat_width(flags, ft_strlen(str_num) + 1, 1);
		ch_count += ft_putstr(str_num);
		return (ch_count);
	}
	str_num = ft_itoa(n);
	if (flags.minus == 1)
		ch_count = ft_put_int(str_num, flags, 0);
	else
		ch_count = ft_put_int(str_num, flags, flags.zero);
	return (ch_count);
}
