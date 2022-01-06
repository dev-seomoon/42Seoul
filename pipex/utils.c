/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:23:48 by seomoon           #+#    #+#             */
/*   Updated: 2021/06/08 15:27:13 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int			ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

int			is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

int			push_str(char **split_strs, const char *str, char sep, int i)
{
	int		j;
	int		len;

	len = 0;
	while (!is_sep(str[len], sep) && str[len])
		len++;
	split_strs[i] = (char *)malloc((len + 1) * sizeof(char));
	if (split_strs[i] == 0)
		return (0);
	j = 0;
	while (!is_sep(*str, sep) && *str)
	{
		split_strs[i][j] = *str;
		j++;
		str++;
	}
	split_strs[i][j] = '\0';
	return (j);
}

int			count_words(const char *str, char sep)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!is_sep(str[i], sep) &&
				(is_sep(str[i + 1], sep) || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char		**ft_split(const char *str, char sep)
{
	char	**split_strs;
	int		i;
	int		j;
	int		size;

	size = count_words(str, sep);
	split_strs = (char **)malloc((size + 1) * sizeof(char *));
	if (split_strs == 0)
		return (0);
	i = 0;
	while (*str)
	{
		if (is_sep(*str, sep))
			str++;
		else
		{
			j = push_str(split_strs, str, sep, i);
			str += j;
			i++;
		}
	}
	split_strs[i] = NULL;
	return (split_strs);
}

