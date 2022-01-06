/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 23:34:05 by seomoon           #+#    #+#             */
/*   Updated: 2020/11/15 16:00:53 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_nl(char *backup)
{
	int	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		backup_to_line(char **backup, char **line, int i)
{
	char	*tmp;

	*line = ft_substr(*backup, 0, i);
	tmp = ft_strdup(*backup + (i + 1));
	free(*backup);
	*backup = tmp;
	return (1);
}

int		rest_to_line(char **backup, char **line)
{
	int	i;

	if (*backup == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	else if (ft_strlen(*backup) == 0)
	{
		*line = ft_strdup("");
		free(*backup);
		*backup = 0;
		return (0);
	}
	i = check_nl(*backup);
	if (i >= 0)
		return (backup_to_line(backup, line, i));
	else
	{
		*line = ft_strdup(*backup);
		free(*backup);
		*backup = 0;
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static	char	*backup[OPEN_MAX];
	int				nbyte;
	int				i;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((nbyte = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[nbyte] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buff);
		i = check_nl(backup[fd]);
		if (i >= 0)
			return (backup_to_line(&backup[fd], line, i));
	}
	if (nbyte < 0)
		return (-1);
	return (rest_to_line(&backup[fd], line));
}
