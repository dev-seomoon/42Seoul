/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 12:37:29 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/22 03:41:20 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		get_map_height(char *str, t_info *info)
{
	int			i;
	int			height;

	i = 0;
	height = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			height++;
		i++;
		if (str[i] == '\0' && (i > 0 && str[i - 1] != '\n'))
			height++;
	}
	info->map->height = height;
}

static char		**malloc_map(char *str, t_info *info)
{
	int			i;
	int			width;
	int			line;
	char		**map;

	if (!(map = malloc(sizeof(char *) * info->map->height)))
		return (NULL);
	i = 0;
	line = 0;
	width = 0;
	while (str[i] != '\0' && line < info->map->height)
	{
		if (str[i] == '\n')
		{
			map[line] = malloc(sizeof(char) * (width + 1));
			line++;
			i++;
			width = 0;
		}
		i++;
		width++;
		if (i > 0 && str[i] == '\0' && str[i - 1] != '\n')
			map[line] = malloc(sizeof(char) * (width + 1));
	}
	return (map);
}

static char		**save_map(char *str, char **map, t_info *info)
{
	int			i;
	int			x;
	int			y;

	y = 0;
	i = 0;
	while (y < info->map->height)
	{
		x = 0;
		while (str[i] && str[i] != '\n')
		{
			map[y][x++] = ft_isspace(str[i]) ? '9' : str[i];
			if (str[i] == 'N' || str[i] == 'S' ||
				str[i] == 'W' || str[i] == 'E')
			{
				set_player_position(info, str[i], x, y);
				map[y][x - 1] = '0';
			}
			i++;
		}
		map[y++][x] = '\0';
		i++;
	}
	return (map);
}

char			**treat_map(char *str, t_info *info)
{
	char		**map;

	get_map_height(str, info);
	map = malloc_map(str, info);
	map = save_map(str, map, info);
	if (!check_map_validation(info, map))
		exit_error("Invalid map format");
	if (info->player->posx == -20.0 || info->player->posy == -20.0
			|| info->player->dir_x == -20.0
			|| info->player->dir_y == -20.0)
		exit_error("Invalid map format");
	free(str);
	return (map);
}
