/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seomoon <seomoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:47:40 by seomoon           #+#    #+#             */
/*   Updated: 2021/02/19 17:07:09 by seomoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			config_resolution(char *line, int i, t_info *info)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (ft_isspace(line[i]))
		i++;
	while (ft_isdigit(line[i]))
		x = (x * 10) + (line[i++] - '0');
	while (ft_isspace(line[i]))
		i++;
	while (ft_isdigit(line[i]))
		y = (y * 10) + (line[i++] - '0');
	while (ft_isspace(line[i]))
		i++;
	if (line[i] != '\0')
		exit_error("Invalid resolution");
	if (x == 0 || y == 0)
		exit_error("Invalid resolution");
	info->width = (x > 2560) ? 2560 : x;
	info->height = (y > 1440) ? 1440 : y;
	info->identifier->resolution++;
	return (SUCCES);
}

static int	check_file(char *file_name)
{
	int		fd;
	int		len;

	len = ft_strlen(file_name) - 1;
	if (!(file_name[len--] == 'm' && file_name[len--] == 'p'
				&& file_name[len--] == 'x' && file_name[len] == '.'))
		return (ERROR);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (ERROR);
	}
	return (SUCCES);
}

int			config_path(int index, char *line, int i, t_info *info)
{
	char	*path;
	int		end;

	if (!line[i])
		exit_error("Path doesn't exist");
	if (!ft_isspace(line[i]))
		exit_error("Unknown identifier");
	while (ft_isspace(line[i]))
		i++;
	end = 0;
	while (ft_isprint(line[i + end]) && !ft_isspace(line[i + end]))
		end++;
	path = ft_substr(line, i, end);
	while (ft_isspace(line[i + end]) && line[i + end] != '\0')
		end++;
	if (line[i + end] != '\0')
		exit_error("Invalid path");
	if (!path || !check_file(path))
		exit_error("Invalid path");
	info->identifier->path[index]++;
	if (index == 4)
		return (stock_sprite(path, info));
	return (set_texture(info, path, index));
}
