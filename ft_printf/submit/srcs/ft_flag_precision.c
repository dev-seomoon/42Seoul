/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 22:14:11 by seomoon           #+#    #+#             */
/*   Updated: 2020/11/25 00:07:28 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*add_zeros(char *nbr, int len, int precision)
{
	int			i;
	int			j;
	char		*result;

	result = (char *)malloc(sizeof(char) * precision);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	if (nbr[0] == '-')
		result[i++] = nbr[j++];
	while (i < (precision - len))
		result[i++] = '0';
	while (i < precision)
		result[i++] = nbr[j++];
	result[i] = '\0';
	free(nbr);
	return (result);
}

char			*ft_treat_precision(int n, int precision)
{
	int			len;
	char		*nbr;
	char		*result;

	len = get_len(n);
	if (n < 0)
	{
		len--;
		precision++;
	}
	if (len >= precision)
		result = ft_itoa(n);
	else
	{
		nbr = ft_itoa(n);
		result = add_zeros(nbr, len, precision);
	}
	return (result);
}

char			*ft_treat_precision_u(unsigned int n, int precision)
{
	int			len;
	char		*nbr;
	char		*result;

	len = get_len_u(n);
	if (len >= precision)
		result = ft_itoa_u(n);
	else
	{
		nbr = ft_itoa_u(n);
		result = add_zeros(nbr, len, precision);
	}
	return (result);
}

char			*ft_treat_precision_hex(char *hex, int precision)
{
	int			len;
	char		*new_hex;

	len = ft_strlen(hex);
	if (precision <= len)
		return (hex);
	new_hex = add_zeros(hex, len, precision);
	return (new_hex);
}
