/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:12:03 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/19 04:25:08 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		get_line_height(t_ray *ray, t_player *player, t_info *info)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->mapx - player->posx +
				(1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->mapy - player->posy +
				(1 - ray->step_y) / 2) / ray->ray_dir_y;
	ray->line_height = (int)(info->height / ray->perp_wall_dist);
	ray->z_buffer[ray->x] = ray->perp_wall_dist;
}

void		get_draw_start_end(t_ray *ray, t_info *info)
{
	ray->draw_start = (-ray->line_height / 2) + (info->height / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height / 2) + (info->height / 2);
	if (ray->draw_end >= info->height)
		ray->draw_end = info->height - 1;
}

void		hit(t_ray *ray, t_info *info)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->mapx += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->mapy += ray->step_y;
			ray->side = 1;
		}
		if (info->map->map[ray->mapy][ray->mapx] == '2')
			is_sprite(ray, info);
		else if (info->map->map[ray->mapy][ray->mapx] > '0')
			ray->hit = 1;
	}
}
