/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:03:38 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/22 03:33:21 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			print_error(char *message)
{
	if (message)
	{
		ft_putstr("Error\n");
		ft_putstr(message);
		ft_putstr(". \n");
	}
	return (ERROR);
}

void		exit_error(char *message)
{
	if (message)
	{
		ft_putstr("Error\n");
		ft_putstr(message);
		ft_putstr(". \n");
	}
	exit(EXIT_FAILURE);
}

int			exit_game(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	clear_structs(info);
	exit(EXIT_SUCCESS);
	return (SUCCES);
}

int			main_loop(t_info *info)
{
	if (!(raycasting(info)))
	{
		mlx_destroy_window(info->mlx, info->win);
		exit_error("During raycasting");
	}
	key_update(info);
	return (SUCCES);
}
