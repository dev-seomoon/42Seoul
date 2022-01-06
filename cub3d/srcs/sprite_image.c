/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:33:06 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/19 15:39:55 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				stock_sprite(char *path, t_info *info)
{
	if (!(info->sprite->img_ptr =
		mlx_xpm_file_to_image(info->mlx, path,
		&info->sprite->width,
		&info->sprite->height)))
		return (ERROR);
	info->sprite->data =
		mlx_get_data_addr(info->sprite->img_ptr,
		&info->sprite->bpp,
		&info->sprite->size_l,
		&info->sprite->endian);
	free(path);
	return (SUCCES);
}

void			put_pixel_on_sprite_image(t_draw_sprite *s, t_info *info)
{
	int			index;

	s->d = s->y * info->sprite->size_l - info->height
		* (info->sprite->size_l / 2) + s->sprite_height
		* info->sprite->size_l / 2;
	s->tex_y = ((s->d * info->sprite->height) / s->sprite_height)
		/ info->sprite->size_l;
	index = s->tex_y * info->sprite->size_l + s->tex_x * info->sprite->bpp / 8;
	s->total_color = info->sprite->data[index]
		+ info->sprite->data[index + 1]
		+ info->sprite->data[index + 2];
}
