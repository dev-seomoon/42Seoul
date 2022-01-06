/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:16:23 by seomoon           #+#    #+#             */
/*   Updated: 2020/07/13 22:59:16 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		begin;
	int		end;

	if (!s1 || !set)
		return (NULL);
	begin = 0;
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	end = ft_strlen(s1 + begin);
	if (end)
		while (s1[begin + end - 1] && ft_strchr(set, s1[begin + end - 1]))
			end--;
	str = (char *)malloc(sizeof(char) * (end + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)(s1 + begin), end + 1);
	return (str);
}
