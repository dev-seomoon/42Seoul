/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:38:07 by seomoon           #+#    #+#             */
/*   Updated: 2020/07/13 22:46:49 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*ptr_s;

	ptr_s = (char *)s;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (*(ptr_s + len) == c)
			return (ptr_s + len);
		len--;
	}
	return (NULL);
}
