/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 22:59:52 by seomoon           #+#    #+#             */
/*   Updated: 2021/07/06 02:20:29 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

int	print_error(char *message)
{
	write(STDOUT_FILENO, message, ft_strlen(message));
	return (1);
}

void	init_zone(t_zone *z)
{
	zone->width = 0;
	zone->height = 0;
	zone->background = 0;
}

int	is_in_rectangle(float x, float y, t_shape *s)
{
	if ( (x < s->x) || (s->x + s->width < x)
		|| (y < s->y) || (s->y + s->height < y) )
		return (OUT_OF_REC);
	if ( (x - s->x < 1.00000000) || (s->x + s->width - x < 1.00000000) || (y - s->y < 1.00000000) || (s->y + s->height - y < 1.00000000) )
		return (
}

void	draw_shape(char **drawing, t_shape *s, t_zone *z)
{
	int	i;
	int	j;
	int	rv;

	i = 0;
	while (i < z->height)
	{
		j = 0;
		while (j < z->width)
		{
			rv = is_in_rectangle(j, i, s);
			if ((s->type == 'r' && rv == 2) ||
				(s->type == 'R' && rv == 1))
				(*drawing)[(i * z->width) + j] = s->color;
			j++;
		}
		i++;
	}
}

int	parse_operation_file(FILE *f, t_zone *z)
{
	int	rv;
	char	*drawing;
	int	i;
	t_shape	s;

	init_zone(z);
	rv = fscanf(f, "%d %d %c\n", &z->width, &z->height, &z->background);
	if (rv != 3)
		return (0);
	if (!(z->width > 0 && z->width <= 300
			&& z->height > 0 && z->height <= 300))
		return (0);
	drawing = malloc(sizeof(char) * (z->width * z->height));
	if (!drawing)
		return (0);
	i = 0;
	while (i < z->width * z->height)
		drawing[i++] = z->background;
	while ((rv = fscanf(f, "%c %f %f %f %f %c\n", &s.type, &s.x, &s.y, &s.width, &s.height, &s.color)) == 6)
	{
		if (!(s->width > 0.00000000 && s->height > 0.00000000 && (s->type == 'r' || s->type == 'R')))
			return (0);
		draw_shape(drawing, &s, zone);
	}
	if (rv == -1)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_zone	z;
	FILE	*f;

	if (ac != 2)
		return (print_error("Error: argument\n"));
	if (!(f = fopen(av[1], "r")) || !(parse_operation_file()))
		return (print_error("Error: Operation file corrupted\n"));


	
}
