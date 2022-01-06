/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:00:34 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/19 04:30:00 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				put_pixel_on_image(int color, int x, int y, t_image *img)
{
	unsigned char	*src;
	int				img_index;

	src = (unsigned char *)&color;
	img_index = y * img->size_l + x * img->bpp / 8;
	img->data[img_index] = src[0];
	img->data[img_index + 1] = src[1];
	img->data[img_index + 2] = src[2];
}

void				vertical_line_color(t_line *line, t_info *info, int color)
{
	int				y;
	int				y_max;

	y = line->y0;
	y_max = line->y1;
	if (line->y0 > line->y1)
	{
		y = line->y1;
		y_max = line->y0;
	}
	if (y >= 0)
	{
		while (y < y_max)
		{
			put_pixel_on_image(color, line->x, y, info->img);
			y++;
		}
	}
}

static void			put_texture_on_image(
		t_line *line, t_image *texture, t_info *info, t_ray *ray)
{
	int				distance;
	int				img_index;
	int				texture_index;

	distance = line->y * texture->size_l - info->height * texture->size_l / 2
		+ ray->line_height * texture->size_l / 2;
	line->tex_y = ((distance * texture->height) / ray->line_height)
		/ texture->size_l;
	img_index = line->y * info->img->size_l + line->x * info->img->bpp / 8;
	texture_index = line->tex_y * texture->size_l
		+ line->tex_x * (texture->bpp / 8);
	info->img->data[img_index] = texture->data[texture_index];
	info->img->data[img_index + 1] = texture->data[texture_index + 1];
	info->img->data[img_index + 2] = texture->data[texture_index + 2];
}

void				vertical_line_texture(
		t_line *line, t_info *info, t_image *texture, t_ray *ray)
{
	int				y_max;

	line->y = line->y0;
	y_max = line->y1;
	if (line->y0 > line->y1)
	{
		line->y = line->y1;
		y_max = line->y0;
	}
	if (line->y >= 0)
	{
		while (line->y < y_max)
		{
			put_texture_on_image(line, texture, info, ray);
			line->y++;
		}
	}
}

t_image				*new_image(t_info *info)
{
	t_image			*img;

	if (!(img = malloc(sizeof(t_image))))
		return (NULL);
	ft_bzero(img, sizeof(t_image));
	if (!(img->img_ptr = mlx_new_image(info->mlx, info->width, info->height)))
		return (NULL);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
				&img->size_l, &img->endian);
	img->width = info->width;
	img->height = info->height;
	return (img);
}
