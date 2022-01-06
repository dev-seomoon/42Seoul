/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:15:12 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/19 04:26:42 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		check_wall_direction(
		t_ray *ray, t_info *info, t_line *line, double wall_x)
{
	t_image		*texture;

	if (ray->side == 1)
	{
		if (ray->step_y == -1)
			texture = info->textures[0];
		else
			texture = info->textures[1];
	}
	else
	{
		if (ray->step_x == -1)
			texture = info->textures[2];
		else
			texture = info->textures[3];
	}
	line->tex_x = (int)(wall_x * (double)texture->width);
	if ((ray->side == 0 && ray->step_x > 0) ||
			(ray->side == 1 && ray->step_y < 0))
		line->tex_x = texture->width - line->tex_x - 1;
	line->y0 = ray->draw_end;
	line->y1 = ray->draw_start;
	vertical_line_texture(line, info, texture, ray);
}

void			texturize(t_ray *ray, t_info *info)
{
	t_line		*line;
	double		wall_x;

	if (!(line = malloc(sizeof(t_line))))
		exit_error("Fail to allocate map");
	ft_bzero(line, sizeof(t_line));
	line->x = ray->x;
	if (ray->side == 0)
		wall_x = info->player->posy + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = info->player->posx + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	if (info->map->map[ray->mapy][ray->mapx] == '1')
		check_wall_direction(ray, info, line, wall_x);
	line->y0 = 0;
	line->y1 = ray->draw_start;
	vertical_line_color(line, info, info->color_ceiling);
	line->y0 = info->height;
	line->y1 = ray->draw_end;
	vertical_line_color(line, info, info->color_floor);
	free(line);
}

int				set_texture(t_info *info, char *path, int i)
{
	if (!(info->textures[i]->img_ptr =
		mlx_xpm_file_to_image(info->mlx, path,
		&info->textures[i]->width,
		&info->textures[i]->height)))
		return (ERROR);
	info->textures[i]->data =
		mlx_get_data_addr(info->textures[i]->img_ptr,
		&info->textures[i]->bpp,
		&info->textures[i]->size_l,
		&info->textures[i]->endian);
	free(path);
	return (SUCCES);
}
