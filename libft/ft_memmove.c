/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:04:17 by seomoon           #+#    #+#             */
/*   Updated: 2020/07/18 04:46:37 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*p_dst;
	const char	*p_src;

	if (!dst && !src)
		return (NULL);
	p_dst = (char *)dst;
	p_src = (const char *)src;
	if (p_dst > p_src)
		while ((int)(--len) >= 0)
			p_dst[len] = p_src[len];
	else
	{
		i = 0;
		while (i < len)
		{
			p_dst[i] = p_src[i];
			i++;
		}
	}
	return (dst);
}
