/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_description.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:18:25 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/21 23:37:00 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				check_identifiers(t_identifier *id)
{
	if (id->resolution == 0
			|| id->path[0] == 0 || id->path[1] == 0
			|| id->path[2] == 0 || id->path[3] == 0 || id->path[4] == 0
			|| id->color_floor == 0 || id->color_ceiling == 0)
		return (ERROR);
	if (id->resolution > 1 || id->path[0] > 1 || id->path[1] > 1
			|| id->path[2] > 1 || id->path[3] > 1 || id->path[4] > 1
			|| id->color_floor > 1 || id->color_ceiling > 1)
		return (ERROR);
	return (SUCCES);
}

static int		is_type_identifier(char *line, int i, t_info *info)
{
	if (!line[i] || !line[i + 1])
		return (NEXT);
	if (check_identifiers(info->identifier))
		return (NEXT);
	if (line[i] == 'R' && ft_isspace(line[i + 1]))
		return (config_resolution(line, i + 1, info));
	else if ((line[i] == 'F' || line[i] == 'C') && ft_isspace(line[i + 1]))
		return (config_color(line, i + 1, line[i], info));
	else if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E')
	{
		if (line[i] == 'N' && line[i + 1] == 'O')
			return (config_path(0, line, i + 2, info));
		else if (line[i] == 'S' && line[i + 1] == 'O')
			return (config_path(1, line, i + 2, info));
		else if (line[i] == 'W' && line[i + 1] == 'E')
			return (config_path(2, line, i + 2, info));
		else if (line[i] == 'E' && line[i + 1] == 'A')
			return (config_path(3, line, i + 2, info));
		else if (line[i] == 'S')
			return (config_path(4, line, i + 1, info));
		return (NEXT);
	}
	return (NEXT);
}

static int		is_map_character(
		char *line, char **map_string, int i, t_info *info)
{
	if (!line[i])
		return (SUCCES);
	if (line[i] == '0' || line[i] == '1' || line[i] == '2'
			|| line[i] == 'N' || (line[i] == 'S')
			|| (line[i] == 'W') || (line[i] == 'E'))
	{
		if (!check_identifiers(info->identifier))
			exit_error("Fail to initialize info");
		*map_string = ft_strjoin(*map_string, line);
		if (info->gnl_return != 0)
			*map_string = ft_strjoin(*map_string, "\n");
		return (SUCCES);
	}
	return (ERROR);
}

static int		parse_line(
		char *line, char **map_string, t_info *info)
{
	int			i;
	int			result;

	if (!line)
		return (ERROR);
	if (ft_strlen(line) == 0)
		return (SUCCES);
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (!(result = is_type_identifier(line, i, info)))
		return (ERROR);
	if (result == NEXT)
	{
		if (is_map_character(line, map_string, i, info))
			return (SUCCES);
		else if (line[i] && line[i] != '\n')
			exit_error("Unknown identifier");
	}
	return (SUCCES);
}

char			*treat_description(char *map_name, t_info *info)
{
	int			fd;
	char		*line;
	char		*map_string;

	if ((fd = open(map_name, O_RDONLY)) == -1)
		exit_error("Fail to open description file");
	if (!(map_string = malloc(sizeof(char) * 2)))
		return (ERROR);
	ft_bzero(map_string, sizeof(char));
	while ((info->gnl_return = get_next_line(fd, &line)) != -1)
	{
		if (!parse_line(line, &map_string, info))
			return (ERROR);
		free(line);
		if (info->gnl_return == 0)
			break ;
	}
	if (!check_identifiers(info->identifier))
		exit_error("Uninitialized identifier or double identifier");
	return (map_string);
}
