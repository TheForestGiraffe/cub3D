/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcunha <tcunha@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:39:30 by tcunha            #+#    #+#             */
/*   Updated: 2026/03/21 12:01:24 by tcunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "parser.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	validate_paths(t_map *map)
{
	int	fd;
	int	i;

	i = 0;
	while (i < e_floor)
	{
		fd = open(map->textures[i], O_RDONLY);
		if (fd == -1)
			return (print_error("@parser_textures", "validate_paths"), 1);
		close(fd);
		i++;
	}
	return (0);
}

static int	add_color(t_map *map, char *line, int *status, t_element element)
{
	int		rgb[3];
	int		i;

	skip_spaces(&line);
	i = 0;
	while (i < 3)
	{
		if (!ft_isdigit(*line))
			return (print_error("@parser_textures", "get_color"), 1);
		rgb[i] = ft_atoi(line);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (print_error("@parser_textures", "get_color"), 1);
		while (ft_isdigit(*line))
			line++;
		if (i++ < 2 && *line++ != ',')
			return (print_error("@parser_textures", "get_color"), 1);
	}
	skip_spaces(&line);
	if (*line != '\n' && *line != ' ' && *line != '\t' && *line != '\0')
		return (print_error("@parser_textures", "get_color"), 1);
	set_flag(status, element);
	map->color[element - e_floor] = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (0);
}

static int	add_texture(t_map *map, char *line, int *status, t_element element)
{
	map->textures[element] = ft_strtrim(line, " \n\r\t");
	if (!map->textures[element])
		return (print_error("@parser_textures", "add_texture"), 1);
	set_flag(status, element);
	return (0);
}

static int	parser_textures_lines(t_map *map, char *line, int *status)
{
	if (!*line || *line == '\n')
		return (0);
	skip_spaces(&line);
	if (!ft_strncmp(line, "SO ", 3) && !has_flag(*status, e_south))
		return (add_texture(map, line + 2, status, e_south));
	else if (!ft_strncmp(line, "NO ", 3) && !has_flag(*status, e_north))
		return (add_texture(map, line + 2, status, e_north));
	else if (!ft_strncmp(line, "EA ", 3) && !has_flag(*status, e_east))
		return (add_texture(map, line + 2, status, e_east));
	else if (!ft_strncmp(line, "WE ", 3) && !has_flag(*status, e_west))
		return (add_texture(map, line + 2, status, e_west));
	else if (!ft_strncmp(line, "F ", 2) && !has_flag(*status, e_floor))
		return (add_color(map, line + 1, status, e_floor));
	else if (!ft_strncmp(line, "C ", 2) && !has_flag(*status, e_ceiling))
		return (add_color(map, line + 1, status, e_ceiling));
	else
		return (print_error("@parser_textures", "parser_textures_lines"), 1);
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
	if (validate_paths(map))
		return (1);
	return (0);
}
