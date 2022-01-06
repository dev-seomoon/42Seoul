#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(char *s)
{
	char *copy;
	int i;
	int len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char *ft_substr(char *s, int start, int len)
{
	int i;
	char *sub;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *str;
	int len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int check_nl(char *backup)
{
	int i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int backup_to_line(char **backup, char **line, int i)
{
	char *tmp;

	*line = ft_substr(*backup, 0, i);
	tmp = ft_strdup(*backup + (i + 1));
	free(*backup);
	*backup = tmp;
	return (1);
}

int rest_to_line(char **backup, char **line)
{
	int i;

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

int get_next_line(char **line)
{
	char buff[2];
	static char *save;
	int bytes;
	int i;

	while ((bytes = read(0, buff, 1)) > 0)
	{
		buff[bytes] = '\0';
		save = ft_strjoin(save, buff);
		i = check_nl(save);
		if (i >= 0)
			return (backup_to_line(&save, line, i));
	}
	if (bytes < 0)
		return (-1);
	return (rest_to_line(&save, line));
}
