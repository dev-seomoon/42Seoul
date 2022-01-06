/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_unint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:44:52 by seomoon           #+#    #+#             */
/*   Updated: 2020/11/29 16:10:58 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				get_len_u(unsigned int n)
{
	int			len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa_u(unsigned int n)
{
	int			len;
	char		*nbr;

	len = get_len_u(n);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	nbr[len] = '\0';
	len--;
	if (n == 0)
		nbr[len] = '0';
	while (n > 0)
	{
		nbr[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (nbr);
}

int				ft_treat_unint(unsigned int n, t_flags flags)
{
	int			ch_count;
	char		*str_num;

	n = (unsigned int)(n + (4294967295 + 1));
	if (flags.dot == 0 && n == 0)
		return (ft_treat_width(flags, 0, 0));
	else if (flags.dot >= 0)
	{
		str_num = ft_treat_precision_u(n, flags.dot);
		return (ft_put_int(str_num, flags, 0));
	}
	str_num = ft_itoa_u(n);
	if (flags.minus == 1)
		ch_count = ft_put_int(str_num, flags, 0);
	else
		ch_count = ft_put_int(str_num, flags, flags.zero);
	free(str_num);
	return (ch_count);
}
