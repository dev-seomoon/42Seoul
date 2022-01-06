/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:31:24 by seomoon           #+#    #+#             */
/*   Updated: 2020/07/25 23:22:12 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**clear_strs(char **strs)
{
	unsigned int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if ((*s != c) && ((*(s + 1) == c) || (*(s + 1) == '\0')))
			count++;
		s++;
	}
	return (count);
}

static int	push_str(char **strs, char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	*strs = (char *)malloc(sizeof(char) * (len + 1));
	if (!(strs[0]))
		return (0);
	len = 0;
	while (s[len] && s[len] != c)
	{
		(*strs)[len] = s[len];
		len++;
	}
	(*strs)[len] = '\0';
	return (len);
}

char		**ft_split(char const *s, char c)
{
	char	**strs;
	int		len;
	int		j;

	if (!s)
		return (NULL);
	len = count_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (len + 1));
	if (!strs)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			j = push_str(strs, s, c);
			if (j == 0)
				return (clear_strs(strs));
			s += j;
			strs++;
		}
	}
	*strs = 0;
	return (strs - len);
}
