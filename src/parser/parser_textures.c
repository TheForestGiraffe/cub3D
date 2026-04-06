/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:39:30 by tcunha            #+#    #+#             */
/*   Updated: 2026/04/06 13:24:34 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "parser_internal.h"
#include "utils.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	find_color(char *line)
{
	int		rgb[3];
	int		i;

	skip_spaces(&line);
	i = 0;
	while (i < 3)
	{
		if (!ft_isdigit(*line))
			return (print_error("@find_color", "Its not a digit"), -1);
		rgb[i] = ft_atoi(line);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (print_error("@find_color", "Out of bounds"), -1);
		while (ft_isdigit(*line))
			line++;
		if (i++ < 2 && *line++ != ',')
			return (print_error("@find_color", "Missing comma in RGB"), -1);
	}
	skip_spaces(&line);
	if (*line != '\n' && *line != ' ' && *line != '\t' && *line != '\0')
		return (print_error("@find_color", "Unexpected chars"), -1);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

static int	add_texture(char **texture, char *line, int *status,
			t_element element)
{
	*texture = ft_strtrim(line, " \n\r\t");
	if (!*texture)
		return (print_error("@parser_textures", "add_texture"), 1);
	set_flag(status, element);
	return (0);
}

static int	add_color(int *color, char *line, int *status, t_element element)
{
	*color = find_color(line);
	if (*color == -1)
		return (1);
	set_flag(status, element);
	return (0);
}

static int	parser_textures_lines(t_map *map, char *line, int *status)
{
	if (!*line || *line == '\n')
		return (0);
	skip_spaces(&line);
	if (!ft_strncmp(line, "SO ", 3) && !has_flag(*status, e_south))
		return (add_texture(&map->tex_south, line + 2, status, e_south));
	else if (!ft_strncmp(line, "NO ", 3) && !has_flag(*status, e_north))
		return (add_texture(&map->tex_north, line + 2, status, e_north));
	else if (!ft_strncmp(line, "EA ", 3) && !has_flag(*status, e_east))
		return (add_texture(&map->tex_east, line + 2, status, e_east));
	else if (!ft_strncmp(line, "WE ", 3) && !has_flag(*status, e_west))
		return (add_texture(&map->tex_west, line + 2, status, e_west));
	else if (!ft_strncmp(line, "F ", 2) && !has_flag(*status, e_floor))
		return (add_color(&map->floor_color, line + 1, status, e_floor));
	else if (!ft_strncmp(line, "C ", 2) && !has_flag(*status, e_ceiling))
		return (add_color(&map->ceiling_color, line + 1, status, e_ceiling));
	else
		return (print_error("@parser_textures_lines", "Unexpected chars"), 1);
}

int	parser_textures(t_map *map, int fd)
{
	char	*line;
	int		status;

	status = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (parser_textures_lines(map, line, &status))
			return (free(line), 1);
		if (is_finished(status))
		{
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!is_finished(status))
		return (print_error("@parser_textures", "parser_textures"), 1);
	return (0);
}
