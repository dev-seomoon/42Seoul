/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:06:31 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/19 16:08:58 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		check_save_option(t_info *info, char **argv)
{
	if (ft_strlen(argv[2]) > 0)
	{
		if (ft_strcmp(argv[2], "--save") == 0)
			info->save_option = 1;
		else
			print_error("Invalid option");
	}
}

int				init_identifiers(t_info *info)
{
	info->identifier = malloc(sizeof(t_identifier));
	if (!info->identifier)
		return (ERROR);
	ft_bzero(info->identifier, sizeof(t_identifier));
	return (SUCCES);
}

static t_info	*init_game(char *map_name)
{
	t_info		*info;
	char		*map_string;

	if (!(info = malloc(sizeof(t_info))))
		return (ERROR);
	ft_bzero(info, sizeof(t_info));
	if (!(info->mlx = mlx_init()))
		return (ERROR);
	info->width = 400;
	info->height = 400;
	info->save_option = 0;
	if (!init_textures(info) || !init_sprite(info)
			|| !init_map(info, map_name) || !init_keys(info)
			|| !init_player(info) || !init_identifiers(info))
		return (ERROR);
	if (!(map_string = treat_description(info->map->map_name, info)))
		return (ERROR);
	info->map->map = treat_map(map_string, info);
	if (!(info->win = mlx_new_window(
					info->mlx, info->width, info->height, "Cub3D")))
		return (ERROR);
	if (!(info->img = new_image(info)))
		return (ERROR);
	return (info);
}

int				main(int argc, char **argv)
{
	t_info		*info;

	if (argc < 2)
		return (print_error("Too few arguments"));
	if (!(info = init_game(argv[1])))
		exit_error("Fail to initialize info");
	check_save_option(info, argv);
	mlx_hook(info->win, 2, 1L << 0, key_press, info);
	mlx_hook(info->win, 3, 1L << 1, key_release, info);
	mlx_hook(info->win, 17, 0L, exit_game, info);
	mlx_loop_hook(info->mlx, main_loop, info);
	if (info->save_option != 1)
		mlx_loop(info->mlx);
	else
		raycasting(info);
	exit_game(info);
	return (0);
}
