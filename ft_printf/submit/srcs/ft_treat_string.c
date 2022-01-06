/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:45:05 by seomoon           #+#    #+#             */
/*   Updated: 2020/11/24 21:49:45 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_treat_string(char *str, t_flags flags)
{
	int			len;
	int			char_count;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags.dot >= 0 && flags.dot < len)
		len = flags.dot;
	if (flags.minus == 1)
		ft_putstr_len(str, len);
	char_count = ft_treat_width(flags, len, 0);
	if (flags.minus == 0)
		ft_putstr_len(str, len);
	return (char_count + len);
}
