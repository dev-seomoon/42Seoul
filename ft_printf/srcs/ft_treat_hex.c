/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:45:35 by seomoon           #+#    #+#             */
/*   Updated: 2020/11/24 21:21:43 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				get_hex_len(unsigned long n)
{
	int			len;

	n = (unsigned long)n;
	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char			*convert_demical_to_hex(unsigned long n, char letter)
{
	int			i;
	int			len;
	char		*hex;

	n = (unsigned long)n;
	len = get_hex_len(n);
	hex = (char *)malloc(sizeof(char) * (len + 1));
	if (!hex)
		return (NULL);
	hex[len--] = '\0';
	i = len;
	if (n == 0)
		hex[i] = '0';
	while (n > 0 && i >= 0)
	{
		if (n % 16 < 10)
			hex[i] = n % 16 + '0';
		else
			hex[i] = (n % 16) - 10 + letter;
		i--;
		n = n / 16;
	}
	return (hex);
}

int				ft_treat_hex(unsigned int n, t_flags flags, char letter)
{
	int			ch_count;
	char		*hex;

	n = (unsigned int)(n + (4294967295 + 1));
	if (n == 0 && flags.dot == 0)
		return (ft_treat_width(flags, 0, 0));
	hex = convert_demical_to_hex(n, letter);
	if (flags.dot >= 0)
		hex = ft_treat_precision_hex(hex, flags.dot);
	if (flags.minus == 1)
	{
		ch_count = ft_putstr(hex);
		ch_count += ft_treat_width(flags, ft_strlen(hex), 0);
	}
	else
	{
		if (flags.dot >= 0)
			ch_count = ft_treat_width(flags, ft_strlen(hex), 0);
		else
			ch_count = ft_treat_width(flags, ft_strlen(hex), flags.zero);
		ch_count += ft_putstr(hex);
	}
	free(hex);
	return (ch_count);
}
