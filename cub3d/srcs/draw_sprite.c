/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:02:58 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/19 15:35:02 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			calc_sprite(t_draw_sprite *s, t_info *info)
{
	s->inv_det = 1.0 / (info->player->plane_x * info->player->dir_y
		- info->player->dir_x * info->player->plane_y);
	s->transform_x = s->inv_det * (info->player->dir_y * s->sprite_x
		- info->player->dir_x * s->sprite_y);
	s->transform_y = s->inv_det * (-info->player->plane_y * s->sprite_x
		+ info->player->plane_x * s->sprite_y);
	s->sprite_screen_x = (int)((info->width / 2) * (1 + s->transform_x
		/ s->transform_y));
	s->sprite_height = abs((int)(info->height / s->transform_y));
	s->draw_start_y = -s->sprite_height / 2 + info->height / 2;
	if (s->draw_start_y < 0)
		s->draw_start_y = 0;
	s->draw_end_y = s->sprite_height / 2 + info->height / 2;
	if (s->draw_end_y >= info->height)
		s->draw_end_y = info->height - 1;
	s->sprite_width = abs((int)(info->height / s->transform_y));
	s->draw_start_x = -s->sprite_width / 2 + s->sprite_screen_x;
	if (s->draw_start_x < 0)
		s->draw_start_x = 0;
	s->draw_end_x = s->sprite_width / 2 + s->sprite_screen_x;
	if (s->draw_end_x >= info->width)
		s->draw_end_x = info->width - 1;
	s->stripe = s->draw_start_x;
}

static void			is_black(t_draw_sprite *s, t_info *info)
{
	int				img_index;
	int				sprite_index;

	img_index = s->y * info->img->size_l
		+ s->stripe * info->img->bpp / 8;
	sprite_index = s->tex_y * info->sprite->size_l
		+ s->tex_x * info->sprite->bpp / 8;
	info->img->data[img_index] = info->sprite->data[sprite_index];
	info->img->data[img_index + 1] = info->sprite->data[sprite_index + 1];
	info->img->data[img_index + 2] = info->sprite->data[sprite_index + 2];
}

int					get_sprite_tex_x(t_info *info, t_draw_sprite *s)
{
	int				tex_x;

	tex_x = (int)(info->sprite->size_l * (s->stripe
				- (-s->sprite_width / 2 + s->sprite_screen_x))
				* info->sprite->width / s->sprite_width)
				/ info->sprite->size_l;
	return (tex_x);
}

static void			make_sprite(t_draw_sprite *s, t_info *info, t_ray *ray)
{
	s->sprite_x = s->sprites[s->i].x - (info->player->posx - 0.5);
	s->sprite_y = s->sprites[s->i].y - (info->player->posy - 0.5);
	calc_sprite(s, info);
	while (s->stripe < s->draw_end_x)
	{
		s->tex_x = get_sprite_tex_x(info, s);
		if (s->transform_y > 0
				&& s->transform_y < ray->z_buffer[s->stripe]
				&& s->stripe > 0 && s->stripe < info->width)
		{
			s->y = s->draw_start_y;
			while (s->y < s->draw_end_y)
			{
				put_pixel_on_sprite_image(s, info);
				if (s->total_color != 0)
					is_black(s, info);
				s->y++;
			}
		}
		s->stripe++;
	}
}

int					draw_sprite(t_ray *ray, t_info *info)
{
	t_draw_sprite	*s;

	if (!(s = malloc(sizeof(t_draw_sprite))))
		return (ERROR);
	ft_bzero(s, sizeof(t_draw_sprite));
	s->i = 0;
	s->sprites = list_to_tab(info);
	sort_sprite(info, s->sprites,
		ft_lstsize((t_list *)info->sprites_on_screen));
	while (s->i < ft_lstsize((t_list *)info->sprites_on_screen))
	{
		make_sprite(s, info, ray);
		s->i++;
	}
	free(s->sprites);
	free(s);
	return (SUCCES);
}
