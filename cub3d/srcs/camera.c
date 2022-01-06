/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:54:31 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/19 04:42:25 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_camera_position(
		t_info *info, double dirx, double planex, double planey)
{
	info->player->dir_x = dirx;
	info->player->plane_x = planex;
	info->player->plane_y = planey;
}

void		turn_left(t_player *player)
{
	double	rs;
	double	dir_x;
	double	plane_x;

	rs = player->rotate_speed;
	dir_x = player->dir_x;
	plane_x = player->plane_x;
	player->dir_x = dir_x * cos(-rs) - player->dir_y * sin(-rs);
	player->dir_y = dir_x * sin(-rs) + player->dir_y * cos(-rs);
	player->plane_x = plane_x * cos(-rs) - player->plane_y * sin(-rs);
	player->plane_y = plane_x * sin(-rs) + player->plane_y * cos(-rs);
}

void		turn_right(t_player *player)
{
	double	rs;
	double	dir_x;
	double	plane_x;

	rs = player->rotate_speed;
	dir_x = player->dir_x;
	plane_x = player->plane_x;
	player->dir_x = dir_x * cos(rs) - player->dir_y * sin(rs);
	player->dir_y = dir_x * sin(rs) + player->dir_y * cos(rs);
	player->plane_x = plane_x * cos(rs) - player->plane_y * sin(rs);
	player->plane_y = plane_x * sin(rs) + player->plane_y * cos(rs);
}
