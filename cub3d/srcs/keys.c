/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:20:53 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/16 17:11:14 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_update(t_info *info)
{
	if (info->keys->key_w == 1)
		move_forward(info->map, info->player);
	else if (info->keys->key_s == 1)
		move_backward(info->map, info->player);
	else if (info->keys->key_a == 1)
		move_left(info->map, info->player);
	else if (info->keys->key_d == 1)
		move_right(info->map, info->player);
	else if (info->keys->key_left == 1)
		turn_left(info->player);
	else if (info->keys->key_right == 1)
		turn_right(info->player);
	return (SUCCES);
}

int		key_release(int key, t_info *info)
{
	if (key == KEY_W)
		info->keys->key_w = 0;
	else if (key == KEY_S)
		info->keys->key_s = 0;
	else if (key == KEY_A)
		info->keys->key_a = 0;
	else if (key == KEY_D)
		info->keys->key_d = 0;
	else if (key == KEY_LEFT)
		info->keys->key_left = 0;
	else if (key == KEY_RIGHT)
		info->keys->key_right = 0;
	return (SUCCES);
}

int		key_press(int key, t_info *info)
{
	if (key == KEY_ESC)
		exit_game(info);
	else if (key == KEY_W)
		info->keys->key_w = 1;
	else if (key == KEY_S)
		info->keys->key_s = 1;
	else if (key == KEY_A)
		info->keys->key_a = 1;
	else if (key == KEY_D)
		info->keys->key_d = 1;
	else if (key == KEY_LEFT)
		info->keys->key_left = 1;
	else if (key == KEY_RIGHT)
		info->keys->key_right = 1;
	return (SUCCES);
}
