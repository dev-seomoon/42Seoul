/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:00:44 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/21 22:57:48 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_player(t_info *info)
{
	if (!(info->player = malloc(sizeof(t_player))))
		return (ERROR);
	ft_bzero(info->player, sizeof(t_player));
	info->player->posx = -20.0;
	info->player->posy = -20.0;
	info->player->dir_x = 1.0;
	info->player->dir_y = 0.0;
	info->player->plane_x = -20.0;
	info->player->plane_y = -20.0;
	info->player->move_speed = 0.075;
	info->player->rotate_speed = 0.05;
	info->player->set_player = 0;
	return (SUCCES);
}

int		init_keys(t_info *info)
{
	if (!(info->keys = malloc(sizeof(t_keys))))
		return (ERROR);
	ft_bzero(info->keys, sizeof(t_keys));
	info->keys->key_w = 0;
	info->keys->key_s = 0;
	info->keys->key_a = 0;
	info->keys->key_d = 0;
	return (SUCCES);
}

int		init_map(t_info *info, char *map_name)
{
	if (!(info->map = malloc(sizeof(t_map))))
		return (ERROR);
	ft_bzero(info->map, sizeof(t_map));
	info->map->map_name = map_name;
	info->map->height = 0;
	info->map->width = 0;
	return (SUCCES);
}

int		init_textures(t_info *info)
{
	int	i;

	i = 0;
	if (!(info->textures = malloc(sizeof(t_image *) * TEXTURES - 1)))
		return (ERROR);
	while (i < TEXTURES)
	{
		if (!(info->textures[i] = malloc(sizeof(t_image))))
			return (ERROR);
		ft_bzero(info->textures[i], sizeof(t_image));
		i++;
	}
	return (SUCCES);
}

int		init_sprite(t_info *info)
{
	if (!(info->sprite = malloc(sizeof(t_image))))
		return (ERROR);
	ft_bzero(info->sprite, sizeof(t_image));
	if (!(info->sprites_on_screen = malloc(sizeof(t_list))))
		return (ERROR);
	ft_bzero(info->sprites_on_screen, sizeof(t_list));
	info->sprites_on_screen->x = -1;
	info->sprites_on_screen->y = -1;
	return (SUCCES);
}
