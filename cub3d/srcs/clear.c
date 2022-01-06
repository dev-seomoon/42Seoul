/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:28:10 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/18 17:29:31 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clear_textures(t_info *info)
{
	int		i;

	i = 0;
	if (info->textures)
	{
		while (i < TEXTURES)
		{
			if (info->textures[i])
				free(info->textures[i]);
			i++;
		}
		free(info->textures);
	}
}

static void	clear_map(t_info *info)
{
	int		i;

	i = 0;
	if (info->map)
	{
		if (info->map->map)
		{
			while (i < info->map->height)
			{
				if (info->map->map[i])
					free(info->map->map[i]);
				i++;
			}
			free(info->map->map);
		}
		free(info->map);
	}
}

void		clear_structs(t_info *info)
{
	clear_textures(info);
	clear_map(info);
	if (info->sprite)
		free(info->sprite);
	if (info->keys)
		free(info->keys);
	if (info->player)
		free(info->player);
	if (info->identifier)
		free(info->identifier);
	if (info->img)
		free(info->img);
	if (info->sprites_on_screen)
		free(info->sprites_on_screen);
	free(info);
}
