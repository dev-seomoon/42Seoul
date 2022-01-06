/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 15:13:14 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/19 15:34:53 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			next_sprite(t_sprites *actual, t_sprites *new, t_ray *ray)
{
	while (1)
	{
		if (actual->x == ray->mapx && actual->y == ray->mapy)
		{
			free(new);
			break ;
		}
		if ((actual->x != ray->mapx || actual->y != ray->mapy)
			&& !actual->next)
		{
			actual->next = new;
			break ;
		}
		if (actual->next)
			actual = actual->next;
		else
		{
			free(new);
			break ;
		}
	}
}

void				is_sprite(t_ray *ray, t_info *info)
{
	t_sprites		*new;
	t_sprites		*actual;
	t_sprites		save;

	if (!(new = malloc(sizeof(t_sprites))))
		return ;
	new->next = NULL;
	new->x = ray->mapx;
	new->y = ray->mapy;
	actual = info->sprites_on_screen;
	save = *actual;
	if (actual->x == -1 && actual->y == -1)
	{
		actual->x = ray->mapx;
		actual->y = ray->mapy;
	}
	else
		next_sprite(actual, new, ray);
	actual = &save;
}

double				get_sprite_distance(
		t_player *player, t_sprite *sprites, int i)
{
	double			distance;

	distance = (player->posx - sprites[i].x) * (player->posx - sprites[i].x)
		+ (player->posy - sprites[i].y) * (player->posy - sprites[i].y);
	return (distance);
}

void				sort_sprite(
		t_info *info, t_sprite *sprites, int nbr_sprites)
{
	int				i;
	double			dist_a;
	double			dist_b;
	t_sprite		tmp;

	i = 0;
	while (i < nbr_sprites && i + 1 != nbr_sprites)
	{
		dist_a = get_sprite_distance(info->player, sprites, i);
		dist_b = get_sprite_distance(info->player, sprites, i + 1);
		if (dist_a < dist_b)
		{
			tmp = sprites[i];
			sprites[i] = sprites[i + 1];
			sprites[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

t_sprite			*list_to_tab(t_info *info)
{
	t_sprite		*result;
	t_sprites		*save;
	int				count;
	int				list_size;

	save = info->sprites_on_screen;
	list_size = ft_lstsize((t_list *)info->sprites_on_screen);
	if (!(result = malloc(sizeof(t_sprite) * list_size)))
		return (ERROR);
	ft_bzero(result, sizeof(t_sprite) * list_size);
	count = 0;
	while (1)
	{
		if (info->sprites_on_screen)
		{
			result[count].x = info->sprites_on_screen->x;
			result[count++].y = info->sprites_on_screen->y;
		}
		if (info->sprites_on_screen->next)
			info->sprites_on_screen = info->sprites_on_screen->next;
		else
			break ;
	}
	info->sprites_on_screen = save;
	return (result);
}
