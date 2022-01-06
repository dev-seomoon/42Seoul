/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:08:17 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/19 04:24:40 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		init_values(t_ray *ray, t_player *player, t_info *info)
{
	ray->camera_x = (2 * ray->x) / (double)info->width - 1;
	ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->mapx = (int)player->posx;
	ray->mapy = (int)player->posy;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

static void		set_step_sidedist(t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->posx - ray->mapx) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->mapx + 1.0 - player->posx) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->posy - ray->mapy) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->mapy + 1.0 - player->posy) * ray->delta_dist_y;
	}
}

static void		do_raycasting(t_info *info, t_ray *ray)
{
	t_player	*player;

	player = info->player;
	init_values(ray, player, info);
	set_step_sidedist(ray, player);
	hit(ray, info);
	get_line_height(ray, player, info);
	get_draw_start_end(ray, info);
	texturize(ray, info);
	ray->x++;
}

int				raycasting(t_info *info)
{
	t_ray		*ray;

	if (!(ray = malloc(sizeof(t_ray))))
		return (ERROR);
	ft_bzero(ray, sizeof(t_ray));
	if (!(ray->z_buffer = malloc(sizeof(double) * info->width)))
		return (ERROR);
	ft_bzero(ray->z_buffer, sizeof(double) * info->width);
	while (ray->x < info->width)
		do_raycasting(info, ray);
	if (!draw_sprite(ray, info))
		return (ERROR);
	if (info->save_option == 1)
	{
		info->save_option = 0;
		create_bitmap(info->img, "cub3D.bmp");
		exit_game(info);
	}
	mlx_put_image_to_window(info->mlx, info->win,
		info->img->img_ptr, 0, 0);
	free(ray->z_buffer);
	free(ray);
	return (SUCCES);
}
