/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:06:46 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/22 02:23:59 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player_position(t_info *info, char direction, int x, int y)
{
	if (info->player->set_player++ != 0)
		exit_error("Invalid map format");
	if (direction == 'E')
	{
		info->player->dir_y = 0.0;
		set_camera_position(info, 1.0, 0.0, 0.66);
	}
	else if (direction == 'W')
	{
		info->player->dir_y = 0.0;
		set_camera_position(info, -1.0, 0.0, -0.66);
	}
	else if (direction == 'N')
	{
		info->player->dir_y = -1.0;
		set_camera_position(info, 0.0, 0.66, 0.0);
	}
	else if (direction == 'S')
	{
		info->player->dir_y = 1.0;
		set_camera_position(info, 0.0, -0.66, 0.0);
	}
	info->player->posx = (double)(x - 1) + 0.5;
	info->player->posy = (double)y + 0.5;
}

void	move_forward(t_map *map, t_player *player)
{
	double move_x;
	double move_y;

	move_x = player->posx + player->dir_x * player->move_speed;
	move_y = player->posy + player->dir_y * player->move_speed;
	if (map->map[(int)player->posy][(int)move_x] == '0')
		player->posx = move_x;
	if (map->map[(int)move_y][(int)player->posx] == '0')
		player->posy = move_y;
}

void	move_backward(t_map *map, t_player *player)
{
	double move_x;
	double move_y;

	move_x = player->posx - player->dir_x * player->move_speed;
	move_y = player->posy - player->dir_y * player->move_speed;
	if (map->map[(int)player->posy][(int)move_x] == '0')
		player->posx = move_x;
	if (map->map[(int)move_y][(int)player->posx] == '0')
		player->posy = move_y;
}

void	move_left(t_map *map, t_player *player)
{
	double move_x;
	double move_y;

	move_x = player->posx - player->plane_x * player->move_speed;
	move_y = player->posy - player->plane_y * player->move_speed;
	if (map->map[(int)player->posy][(int)move_x] == '0')
		player->posx = move_x;
	if (map->map[(int)move_y][(int)player->posx] == '0')
		player->posy = move_y;
}

void	move_right(t_map *map, t_player *player)
{
	double move_x;
	double move_y;

	move_x = player->posx + player->plane_x * player->move_speed;
	move_y = player->posy + player->plane_y * player->move_speed;
	if (map->map[(int)player->posy][(int)move_x] == '0')
		player->posx = move_x;
	if (map->map[(int)move_y][(int)player->posx] == '0')
		player->posy = move_y;
}
