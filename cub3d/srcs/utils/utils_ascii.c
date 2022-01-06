/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:43:50 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/19 15:44:14 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (SUCCES);
	return (ERROR);
}

int			ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (c);
	else
		return (ERROR);
}

int			ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (SUCCES);
	return (ERROR);
}
