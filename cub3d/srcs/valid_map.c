/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 02:44:35 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/22 03:41:48 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		is_empty(int y, int x, char **map)
{
	if (map[y][x] != '1' && map[y][x] != '9' && map[y][x] != '\0')
		return (SUCCES);
	return (ERROR);
}

static int		is_map_closed(int y, char **map, t_info *info)
{
	int			x;

	x = 0;
	while (map[y][x] != '\0')
	{
		if (map[y][x] == '9' && is_empty(y, x + 1, map))
			return (ERROR);
		if ((x == 0 || y == 0 || y == info->map->height - 1 ||
					(map[y][x + 1] == '\0' || map[y][x + 1] == '9'))
				&& is_empty(y, x, map))
			return (ERROR);
		if ((y + 1 < info->map->height - 1)
				&& (map[y + 1][x] == '9' || map[y + 1][x] == '\0')
				&& is_empty(y, x, map))
			return (ERROR);
		if ((y - 1 > 0) && (map[y - 1][x] == '9') && is_empty(y, x, map))
			return (ERROR);
		if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != '2'
				&& map[y][x] != '9')
			return (ERROR);
		x++;
	}
	return (SUCCES);
}

int				check_map_validation(t_info *info, char **map)
{
	int			y;

	if (!*map || !**map)
		return (ERROR);
	y = 0;
	while (y < info->map->height)
	{
		if (ft_strlen(map[y]) < 1)
			return (ERROR);
		if (!is_map_closed(y, map, info))
			return (ERROR);
		y++;
	}
	return (SUCCES);
}
