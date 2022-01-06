/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:23:34 by seomoon           #+#    #+#             */
/*   Updated: 2020/07/13 23:31:15 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr_s;

	ptr_s = (char *)s;
	while (1)
	{
		if (*ptr_s == c)
			return (ptr_s);
		if (*ptr_s == '\0')
			break ;
		ptr_s++;
	}
	return (NULL);
}
