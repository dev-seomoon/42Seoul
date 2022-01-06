/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:52:02 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/19 17:06:23 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_color_format(char *line, int i)
{
	if (!ft_isdigit(line[i]))
		return (ERROR);
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]) || line[i] == ',')
		i++;
	if (!ft_isdigit(line[i]))
		return (ERROR);
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]) || line[i] == ',')
		i++;
	if (!ft_isdigit(line[i]))
		return (ERROR);
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] != '\0')
		return (ERROR);
	return (SUCCES);
}

static int	get_color(char *line, int i)
{
	int		rgb[3];
	int		color;

	rgb[0] = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]) || line[i] == ',')
		i++;
	rgb[1] = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]) || line[i] == ',')
		i++;
	rgb[2] = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (ft_isspace(line[i]))
		i++;
	if (rgb[0] < 0 || rgb[1] < 0 || rgb[2] < 0
			|| rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255)
		exit_error("Invalid color value");
	color = rgb[0];
	color = (color << 8) + rgb[1];
	color = (color << 8) + rgb[2];
	return (color);
}

int			config_color(char *line, int i, char location, t_info *info)
{
	int		color;

	while (ft_isspace(line[i]))
		i++;
	if (!check_color_format(line, i))
		exit_error("Invalid color format");
	color = get_color(line, i);
	if (location == 'F')
	{
		info->color_floor = color;
		info->identifier->color_floor++;
	}
	else if (location == 'C')
	{
		info->color_ceiling = color;
		info->identifier->color_ceiling++;
	}
	return (SUCCES);
}
