/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 23:58:36 by seomoon           #+#    #+#             */
/*   Updated: 2020/07/25 23:27:41 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	i;
	unsigned int	j;

	dst_len = ft_strlen((const char *)dst);
	src_len = ft_strlen(src);
	i = dst_len;
	j = 0;
	if (dstsize == 0)
		return (src_len);
	if (dstsize < dst_len)
		return (dstsize + src_len);
	while (i < dstsize - 1 && src[j] != '\0')
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst_len + src_len);
}
